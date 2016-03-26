\section{The Pipeline}

\subsection{Overview}
\textit{[the paper story transition/flow is too hard here - restate what our paper is about and why we therefore explain now the pipeline stages - what is the pipeline about? it is for molecular models and allows for transitions to other visualization spaces. state the rationale, why a pipeline and why stages are necessary - currently too much "how i spent my summer" style - it is also important to state, why we did something (not only what we did)]}

In this section, we present the eight stages that our pipeline consists of.
The pipeline operates on the following data format.

\textit{[this should be part of the data structuring stage explanation:]}
\begin{itemize}
\item Instances: instances have a spatial position, orientation, and geometrical representation, and can have an attribute vector. in our case, instances are molecules of different types that are composed of atoms. these atoms are represented by points and are the primitives in our data.		
\item Subsets: subsets are grouped instances, in our case groups of molecules. groups can be formed according to any internal or external attributes of instances, such as type or shape similarity.
\item Entities: both instances and subsets are the entities that our pipeline operates on. this means, a metamorpher accepts either individual instances and/or groups of instances, e.g., in the layout stage, when repositioning a single molecule or a group of molecules.		
\end{itemize}
	
%	\begin{itemize}
	%\item atom: represents the smallest part of our data. represented by a unit sphere. always represented within a molecule alongside with other atoms. has information about its chemical element and its local position within a molecule.
		%\item molecule: a single molecule. groups together a bunch of atoms. has inherent spatial attributes (pos/rot/scale) and an attribute vector (type). all molecules in the scene are instances of their respective type. the entities that our pipeline operates on. molecules	can be hierarchically grouped to form subsets within a hierarchical scene graph. %has an original position and a target position and optionally control points in between
		%\item subset: is a group of entities/molecules.	grouped according so specified attributes (spatial, by type, ..)
		%\item attributes: spatial (pos, rot, volume/size, shape) for original and target \& optionally intermediate (controlpoints) state
		%\item attributes: hierarchical (children, parent)
		%\item attributes: data (data, type, shape composed of atoms \& their positions, color, also time curve?)
	%\end{itemize}

%=> this should be clarified/motivated in the introduction			
%data is densely packed. depending on each molecules function, they can have a noisy distribution like in a liquid? or they can build rigid structures such as membranes.		these attributes have to be taken into account when designing a target representation as well as the transition into it.

%\textbf{todo:} where to describe cellpack format? 

Our pipeline takes a molecular data set in the described format and produces a user specified number of frames that show a transition from the provided original representation to a specified target representation.
	
The eight stages of our pipeline can be grouped into two high level tasks:
the first four stages are responsible for creating a target representation.
The final four stages are used to define the transition from the original representation to the target representation.
Each stage supports certain types of operators.
These operators determine how a stage proceeds with the supplied data.
Operators have to be implemented for each stage in consideration of desired target output.
Here is where design considerations come into play.
To convey their message, illustrators apply a combination of the three high level tasks of occlusion handling, and transformations within or across different visualization spaces.
Subsequently, most pipeline stages supply measures for fulfilling these tasks with their individual means.
These can, in combination, then enable other lower level tasks, such as, comparison,.. \textbf{[check brehmer task taxonomy]}

\textit{[this whole paragraph seems irrelevant to the reader:]}
In order to achieve a desired result, the respective operators have to be selected and parametrized for each stage.
Depending on what kind of transition should be achieved, not all stages are mandatory.
Further, the pipeline can be repeated for more complex stories or multi stage transitions.
In the following we will discuss each stage in terms of its function within the pipeline and in terms of how it operates on the supplied data.
How these stages can be applied in practice, will be demonstrated in the next Section, where we will discuss the creation of three exemplary transitions based on our proof of concept implementation.
	
		



\subsection{Target State}
The visual appearance of the final representation is defined in these stages.


\subsubsection{Data Transformation}

Before they start to visually transform their data, illustrators have to decide, which parts of the data and in which granularity it is handled, e.g., to determine, which parts to explode, or which parts to merge and render in a simplified manner.
%, e.g., which parts should be treated as a unit when transforming them to a different representation.
As such, the components on (most of) the following pipeline stages are operating on individual subsets of the data.
Data Transformation, as the first stage in our pipeline, is therefore concerned with creating these subsets - or more precisely, a hierarchical scene-graph of subsets where the leave nodes are the individual molecules.
%As such, this stage partitions the raw unstructured data into subsets according to specified criteria.
These subsets are the building blocks that the final representation is constructed from.

Operators in this stage therefore define, according to which criteria to create these subsets.
For instance, one operator could create a subset that contains all molecules of the same type, another according to the molecules' spatial positioning.

On a technical level, this means that operators of this stage will receive a list of entities (molecules or subsets) as input -
will then group these entities according to specified criteria - and create a number of subsets, e.g, as many as there are molecule types. Each entity that fits the respective subset criteria is assigned to it as its child. Each child entity stores the id of its designated parent.
The output of an operator will therefore be a list of the newly created subsets with the respective child / parent assignments.
%attributes modified/created in this stage: group id, parent / child assignment.
	
To create a scenegraph, the operators of this stage have to be called hierarchically on the data. A user could, for instance, at first partition the scene spatially and then partition the resulting subsets by molecule type. %give reason?

Multiple time steps, different data sets, or simply multiple copies of the same data can also be represented as high level nodes within such a scenegraph - provided the necessary operators to create or load them are implemented.
			

\subsubsection{Annotations}
This stage allows the illustrator to add various forms of annotations to the scene.
Illustrators can use these annotations for multiple purposes:
simple text labels could assist story telling by describing what is currently happening in the scene.
Icons that point to specific events can be used to steer the viewer's attention.
These elements can also be combined to create frames of reference, such as coordinate axes, scales, and legends, that can improve the viewers' orientation within and their understanding of the presented information.
	
%			story telling (labels and annotations) => inform,
%			steer attention (pointers),
%			supplying frames of reference (legends \& coordinate systems) => orientation.
	%		additionally used in static images / small multiples for supplementing the information that is lost due to the missing animation (continuous transition):	
				%- glyphs that indicate the direction of a motion
				%- target destination of an apparently moving entity	
		%can support understanding of the transition (e.g., arrows) - especially in still images.
		%can support understanding of the data (e.g., labels).	
%	attributes created in this stage:		labels/glyphs/...,			content (text,...),			positions \& time of fadein/fadeout (or are these handled by timing, layouting \&trajectory?)

Operators of this stage should therefore, in the simplest case, accept text input and should be able to create or load icons and other graphical representations.
Annotations can be independently positioned and parametrized, but they can also be logically attached to specific entities, e.g., for creating a relative position or extracting and displaying an entity's attributes.

\textbf{[we could also move this behind layouting]}
	
\subsubsection{Visual Transformation}
%transformation of entities into a different representation form.			
Operators in this stage have access to the visual variables of transparency, color, and shape.
Illustrators use these operators to change the visual mapping of parts or all of their data, in order to achieve a transformation within the same or across visualization spaces, e.g., to support tasks like simplification, abstraction, and occlusion handling.
Operations can be applied on any level of the scenegraph, i.e., on individual molecules or subsets of molecules. 

This allows the transparent rendering of occluding molecules, or the morphing of entities to different shapes, as can be seen in [Figure 2 - graham video]. 


				%general: individual or subsets can change their representation: blend into each other into a new collective shape, change individual shape, blend into texture, change individual or collective render mode

%concrete examples:				simplification: specific molecules could be blended to a 2D texture, that represents the molecule's kekule diagram. unnecessary details can be reduced by blurring the complex noisy distribution of molecules within a compartment to a uniform color.
%occlusion handling: by changing visual properties, such as transparency, of certain parts of the data, other parts can be revealed.
%abstraction/transformation/?: the molecules can be morphed into tetris-like blocks that the layouting stage then combines to form, e.g., a histogram bar, encoding the total volume of the respecitve molecule type. 

From a technical perspective, the operators in this stage can implement specific shaders for creating a desired effect, e.g., by changing the molecule geometry, or doing post processing on the rendered image of a subset in a separate rendering pass.
		
%\textbf{[not so happy with the description of this one :/]}
			
\subsubsection{Spatial Transformation (Layouting)}

%The layouting stage creates a target position and rotation for each child element of a supplied subset.
%the operator type determines how the entities in the supplied supset are laid out in respect to each other.

While the previous stage handled the visual variables of transparency, color, and shape, this stage is concerned with the transformation of the spatial variables of position, rotation, and scale.
As the final stage of this part of the pipeline, it completes the transformation of the data, i.e., the creation of the final target representation.
	
%this is the tool that illustrators use to spatially re-arrange the data that they partitioned and transformed/blended in the previous stages.

With the spatial re-arrangement of the molecular data, various results can be achieved: occlusion handling, e.g., by exploding the dense data to reveal the inner workings of a cell.
The noisy distribution of different molecules can be re-arranged, to simplify the complex and dense data so that it better fits the viewer's mental model.
Elements could be positioned so that they represent an altogether different visualization space, such as a network that shows interactions between molecules.



	%design decisions:		necessary for enabling transformation of entities/subsets into a different space.
			%transform spatial properties, e.g., from anatomical to abstract or to schematic.	=> transformation within the same visualization space (schematization) vs transformation across visualization spaces (abstraction).			
		%prerequisite for creating the spatial extents of the target representation.
		
%	description:		deals with spatial attribute transformation.		determines the target position for each created subset/entity.
			%the spatial re-arrangement can be used to convey different information,			i.e., move all entities of a subset spatially close to each other to separate them from other entities and convey the group size
			
%			can be used to:				spatially order/group entities (abstract),				reduce entities (simplify),				reveal hidden structures / entities (occlusion handling)
%		a layout manipulates only pos/rot			(scaling is already part of morphing).
%		can be used on an "inner" level to position entities with respect to each other => give a shape to subsets (e.g., a histogram bar).	
%		can be used on an "outer" level to position subsets with respect to each other.
				
The input for a layout operator is always a node in the scene hierarchy, i.e., an entity containing a list of molecules or subsets. %(not a leaf),
For each child of the supplied node, the operator calculates a new position rotation, and scale - depending on what kind of layout the respective operator is implementing.
The output of a layout operator is therefore a new position, rotation, and scale for each child of the supplied node. Each entity has a vector of control points that stores positions and rotations and is initialized with the entity's original position and rotation (in the case of subsets, the bounding box). The new values calculated by the layout operators are added to this vector.
	
Layouts can be stacked upon each other - meaning they are called multiple times for the same node - this creates additional control points that can be used to transition the data into intermediate representations before arriving at the final state. The final representation is determined by the last layout that has been called. 
A user could, for instance, first call an explosion layout, to reveal the inner parts of the dense data set, before rearranging these parts into a simplified form.
	
%Layouts can be called for each level in the scene hierarchy, depending on the intended target representation.Subsets containing the leaves of the hierarchy, i.e., the molecule instances. here the layout works directly on re-positioning the individual molecules, e.g., it could put them into an abstract collective shape like a histogram bar. the next highest level node would then contain a list of children where each is layouted as a bar. the layout operator could then position these subsets (bars) with respect to each other.



	
\subsection{Transition}
These stages are responsible for defining the transition to the target representation, i.e., how each entity reaches its target position and when it reaches it's target form.



\subsubsection{Camera Operators}

Control over camera parameters allows illustrators to steer a viewer's attention towards specific events or details in the scene, in a guided navigation fashion.
An operator could also steer the camera to follow the development of a transition, if it leaves the current view frustum, to assure visibility of the entire data.

Operators in this stage modify the camera position \& look-at vector. As such, they create a list of control points for these two values. For guided navigation, an operator could access the positional control points of user defined entities, for instance.
A timing and trajectory is defined in the respective stages for the interpolation between these control points.			
			

\subsubsection{Trajectory}

This stage describes for each molecule, how it reaches the target position and the control points in-between that have been defined in the spatial transformation/layouting stage.
This is in the simplest case a linear interpolation between a molecule's control points.
However, if applied wisely, illustrators can use this stage for multiple purposes:
Simplification: they can make the transition more readable and visually engaging, by bringing structure into its elements' motion paths, e.g., by creating a well positioned point in space for each molecule type through which it has to "travel" to reach its target position.
This can also serve occlusion handling, e.g., by placing these transit points in a way that the molecules flying through them reveal essential parts of the scene. 
Trajectories can also encode topological information that was not present in the original data, e.g., in the form of meaningful data highways that transport molecules from one cellular compartment to another, or to simulate the flow of blood between two organs.

To achieve this spatially structured transition, operators in this stage can implement techniques such as edge bundling. This means that an operator can introduce new control points into the motion path of a molecule, e.g., to re-direct it so that it does not occlude the existing scene. Operators in this stage also determine, whether to interpolate linearly between control points, or whether to use other strategies, such as cubic splines.

As such, this stage, takes a subset from the scene hierarchy as input.
The child elements of this subset are analyzed in terms of their control points (at the very least original and target position) and their relation to the control points of the remaining elements of this subset (or the entire scene).
Depending on the operator type, new control points that fulfill a desired function, such as clutter reduction in the form of more orderly transition paths, are created as the output of the stage.
		%necessary to bring order into the transition across the spatial canvas.	
		%prerequisite for spatial coordination of the transition.		
		%can be used to infer additional information (e.g., information highways for certain entity types) - but also to decrease occlusion / increase readability of the transition.		
%	attributes created in this stage:
	%	control points between original and target position \& appearance.
		%control point do not suggest a timing but rather key frames for each entity or subset.		
%		input: set of layouted entities (they possess original and target state).		
	%	output: transition path based on additional CPs for each entity/subgroup.
		
	
\subsubsection{Timing}

The timing stage is responsible for the temporal coordination of the transition by determining the order and speed at which entities or subsets reach their target position and visual form.
As such, this stage is the illustrators' canvas in the temporal dimension.

While the inherent purpose of this stage is to encode chronological information, i.e., the sequence of events, illustrators can also use it for additional purposes:
they can make the transition more readable \& visually engaging by reducing the number of simultaneous visual stimuli, i.e., by starting the transition of indicisual molecules / subsets with a time offset to each other, thus creating staged transitions/animations [cite heer?]. %i.e., by timing when and how fast individual molecules or subsets should approach their target destinations, as well as their target representations,
Timing can also be used for occlusion handling, i.e., by first starting the transition of elements that occlude important structures or that are closer to the viewing position, while other elements remain in their positions until they are revealed.
Further, timing can also be used for controlling visual stimuli. The transition can be timed in a way that the attention is steered to a currently important structure or event by animating what should be in focus while keeping the remaining scene still.

As such, operators of this stage, depending on the intent that they implement, create a time curve for each entity. This time curve determines the start time and speed of the spatial and visual transition. Optionally, also an end time can be created, i.e., to determine, when an element should cease to exist but also, when the transition should stop, i.e., whether an element should reach its final destination as well as how close it should get. This can be used to create a target representation that looks like it stopped in mid-motion.
	
\subsubsection{Sampling}

This final stage determines the sampling strategy, i.e., at which rate the transition is sampled. %in which resolution the pipeline outputs the transition.
The operator, that the illustrator chooses, therefore determines, whether the transition will be continuous or if sparser sampling will be applied, e.g., to extract a narrative sequence like in a comic strip.
The lowest rate would therefore just output the final image of the target representation.

While the previous stages of the pipeline can be called multiple times in order to create more complex animations/transitions/stories, the sampling stage is final, as it ties together the information from the previous stages to sample the visual result.

%interpolates between the controlpoints/keyframes
%produces a smooth \&continuous transition / animation 

Before the sampling starts, the scene hierarchy is flattened again - which means that all information from higher level nodes is projected into the leaves, i.e., the individual molecules. The transformation matrices of higher level nodes are multiplied recursively with all their lower level children for each controlpoint - so that each molecule knows about its global position for each control point.

The sampling stage then uses the output of the timing stage to determine at which rate/speed to interpolate between control points for each molecule.
And it uses the output of the trajectory stage to determine how to interpolate between the supplied control points, e.g., linear, cubic,..

The sampling stage can also determine if the transition is pre-baked or sampled on the fly in real-time.
This makes it possible to use a continuous pre-baked transition to create, for instance, a single result image that encodes the missing transition information within glyphs. These glyphs can be calculated from the continuous pre-baked information.

The continuously sampled information could also be exploited to create a hybrid visualization that displays a discretely sampled narrative sequence of small multiples. Upon clicking one of these small multiples, it could show the continuous transition to the next discrete element in the narrative sequence.
%This missing information can be extracted from the continuously sampled pre-baked transition and 

%to use this information in a postprocessing step to create glyphs that reintroduce the information that was missing through the sparse sampling
%this stage also allows/supports operators that can, for instance, first do a smooth continuous sampling and then extract transition / motion path information from these samples and encode the information in a postprocessing step into supporting glyphs that reintroduce the information that was missing through the sparse sampling
 
















