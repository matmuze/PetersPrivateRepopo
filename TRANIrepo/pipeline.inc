\section{The Pipeline}

\subsection{Overview}
		
	our pipeline takes a supplied molecular data set in the described format and produces a user specified number of baked frames that show a continuous transition from the provided original data to a specified target representation.
	
	Our pipeline consists of eight stages that can be grouped into four high level tasks:
	
	the first three stages can be parametrized to specify the target representation.
	
	the next two stages can be used to add additional labels and narrative elements to the animation, such as coordinate axes, legends, or annotations.
	
	the final three stages are used to define the transition from the original representation to the target representation.
		
	each stage supports certain types of operators.
	operators basically determine how a stage proceeds with the supplied data.
	
	they have to be implemented for each stage in consideration of desired output that the respective stage should produce.
	here is where design considerations come into play.
	
	%these operators and their combinations determine the pipeline output.
	in order to achieve a desired result, the respective operators have to be selected and parametrized for each stage.
	
	%\textbf{todo: explain operators more explicitly} \newline
	%implemented once and can then be re-used on arbitrary data sets to achieve the desired results.
	%can be combined in new ways?
	we give a discussion of our proof of concept operators in the next section.
	
		depending on what kind of transition should be achieved, not all stages are mandatory.
		
		also, the	pipeline can be repeated for more complex stories or multi stage transitions.
	
	in the following we will discuss each stage in terms of its function within the pipeline and in terms of how it operates on the supplied data.
	%mention design decisions?
% connection to the work of the real-world illustrators?
	
		\begin{itemize}
			\item Target Representation Creation: Data Partitioning, Layouting, Morphing \& Blending
			\item Narrative Support: Annotations \& Glyphs, Navigation
			\item Transition Specification: Trajectory, Timing, Sampling
		\end{itemize}

		%independent of staging within one transition. staging therefore doesnt have to be implemented by multiple pipeline iterations.

\subsection{Target State}
the visual appearance of the final representation is defined in these stages.\newline
%the partitioning stage..
%while the layouting stage is responsible for manipulating the spatial variables of position and rotation,
%the morphing stage is concerned with the remaining visual variables, i.e., shape, size, color.\newline
%these states are necessary / responsible for defining the target position \& form of the data, i.e., the spatial and visual transformation

\subsubsection{Partitioning Stage}

as the first stage in our pipeline, the partitioning stage is concerned with preparing the molecular data for further processing in the consecutive stages.

%its task is to structure the data so that the desired knowledge can be extracted from it.

illustrators partition their data to decide, in which granularity/level of detail the data is handled, e.g., which parts should be treated as a unit when transforming them to a different representation. \textbf{[concrete example?]} 

as such this stage partitions the raw unstructured data into subsets according to specified criteria.
these subsets are the building blocks that the final representation is constructed from.

the criteria for structuring them are specified by the respective operators of this stage.

for instance, one operator could group all molecules by type, another according to their spatial positioning.

the operators of this stage can be called hierarchically to create a scenegraph of the data. a user could at first partition the scene spatially and then partition the resulting subsets by molecule type. %give reason?

as such, operators implemented for this stage will receive a list of entities or list of subsets as input.
the operator will then group the elements of the supplied list according to specified criteria, such as the elements' molecule type, position, or spatial proximity to a defined point. 
more precisely this means, that a number of subsets is created, e.g, as many as there are molecule types or defined spatial quadrants, and each entity that fits the respective subset is assigned to it as its child. each child entity also stores the id of its designated parent.
the output of an operator will therefore be a list of the newly created subsets with the respective child / parent assignments.
%attributes modified/created in this stage: group id, parent / child assignment.
	
%partitioning is a prerequisite stage for the following pipeline stages. it determines, on which parts of the data the operators in the following pipeline stages will operate. %, e.g., which parts of the data are handled as a unit in layouting or the morphing of the visual representation.

%this stages takes the raw unstructured data and structures it according to the parametrization of the respective operator.

%		also, typically you have very large datasets and dont want to operate on each individual instance but rather on groups of instances.
%			to make the data manageable \& to extract knowledge it is therefore necessary to structure it.
			
%	description:		organize data into subsets.
		%each subset is then fed into the pipeline - which means, each subset can be modified with different operators in the following pipeline stages.
		%does not modify any spatial positioning.
		
		%operators in this stage	can be repeated hierarchically to create a scenegraph of the data.
		%- each subset is then fed into the pipeline - which means, each subset can be modified with different operators.
		
%		no simplification/abstraction/occlusion handling here since we are not manipulating any properties except for parent/child assignments.
		
%	attributes modified/created in this stage: group id, parent / child assignment.
	
%	according to criteria:			internal (data): type				external:			spatial position,				in respect to other entities,				in respect to external factors(cuttingplanes),			derived properties
			
	
\subsubsection{Blending/Morphing}
%this stage enables the transformation of entities/subsets into a different representation form.			
%is responsible for creating the visual properties of the target representation - the transformation of entities/subsets into a different representation form.

illustrators can use the operators of this stage to change the visual representation of parts or all of their data.
this can serve multiple purposes / the three high level tasks of simplification, abstraction, and occlusion handling.

entities or subsets change their individual or collective appearance, in order to convey specific information by revealing, simplifying or transforming the molecular data.
				general: individual or subsets can change their representation: blend into each other into a new collective shape, change individual shape, blend into texture, change individual or collective render mode

concrete examples:				
simplification: specific molecules could be blended to a 2D texture, that represents the molecule's kekule diagram. unnecessary details can be reduced by blurring the complex noisy distribution of molecules within a compartment to a uniform color.
occlusion handling: by changing visual properties, such as transparency, of certain parts of the data, other parts can be revealed.
abstraction/transformation/?: the molecules can be morphed into tetris-like blocks that the layouting stage then combines to form, e.g., a histogram bar, encoding the total volume of the respecitve molecule type. 


operators thus can work on arbitrary levels of the scene hierarchy that was created in the previous pipeline stage:
on the leafes (the individual molecules): 
on the subsets (the grouped molecules): histogram, giant cubes


depending on their implementation, operators on this stage can operate on the any part of the shader pipeline, i.e., move around individual vertices that are the atoms of a molecule or do post processing on the rendered image in a separate rendering pass.
\textbf{[need some feedback for improvement of the input/output description]}

%take individual molecules or subsets as input
%depending on their implemented task, they can
%apply shading (blend together, render contours, transparent,..)
%blend to a 2D texture
%scale
%moph the shape: to a proxy geometry, based on the atoms

%attributes created in this stage: target..		shape,		size,		color,		style,		dimensionality.		output: morphed shape(s).		
%abstraction (cube, histogram), simplification (kekule, LoD, merging in schematization).
			
			
			
\subsubsection{Layouting}

%The layouting stage creates a target position and rotation for each child element of a supplied subset.
%the operator type determines how the entities in the supplied supset are laid out in respect to each other.
	
this is the tool that illustrators use to spatially re-arrange the data that they partitioned in the previous stage/step.
this spatial re-arrangement of the molecular data can serve various purposes. layouts can be used for occlusion handling, e.g., by exploding the dense data to reveal the inner workings of a cell. they can be used to transform the data into an altogether different visualization space, such as a line graph or a network in order to convey some more abstract points. or they can use them to simplify the complex and dense data in order to steer the viewer's attention towards some specific anatomical details that would otherwise remain hidden.

	%design decisions:		necessary for enabling transformation of entities/subsets into a different space.
			%transform spatial properties, e.g., from anatomical to abstract or to schematic.	=> transformation within the same visualization space (schematization) vs transformation across visualization spaces (abstraction).			
		%prerequisite for creating the spatial extents of the target representation.
		
%	description:		deals with spatial attribute transformation.		determines the target position for each created subset/entity.
			%the spatial re-arrangement can be used to convey different information,			i.e., move all entities of a subset spatially close to each other to separate them from other entities and convey the group size
			
%			can be used to:				spatially order/group entities (abstract),				reduce entities (simplify),				reveal hidden structures / entities (occlusion handling)
%		a layout manipulates only pos/rot			(scaling is already part of morphing).
%		can be used on an "inner" level to position entities with respect to each other => give a shape to subsets (e.g., a histogram bar).	
%		can be used on an "outer" level to position subsets with respect to each other.
				
	as such, the input for a layout operator is always a node in the scene hierarchy. %(not a leaf),
	for each child of the supplied node, the operator then calculates a new position and rotation - depending on what kind of layout the respective operator is implementing.
	the output of a layout operator is therefore a new position and rotation for each child of the supplied node. each entity has a vector of control points that stores positions and rotations and is initialized with the element's original position and rotation. the new values calculated by the layout operators are added to this vector.
	
layouts can be stacked upon each other - meaning they are called multiple times for the same node - this creates additional control points that can be used to transition the data into intermediate representations before arriving at the final state. the final representation is determined by the last layout that has been called. 
a user could, for instance, first call an explosion layout, to reveal the inner parts of the dense data set and then 
	
layouts are can be called for each level in the scene hierarchy. depending on the intended target representation.
lowest level nodes contain leaves (molecule instances). here the layout works directly on re-positioning the individual molecules, e.g., it could put them into an abstract collective shape like a histogram bar. the next highest level node would then contain a list of children where each is layouted as a bar. the layout operator could then position these subsets (bars) with respect to each other.
	
	
\subsection{Transition}
These stages are responsible for defining the transition to the target representation, i.e., how each entity reaches its target position and when it reaches it's target form.

\subsubsection{Trajectory}

This stage describes for each molecule, how it reaches the target position and the control points in-between that have been defined in the layouting stage.
This is in the simplest case a linear interpolation between a molecule's control points.
However, if applied wisely, illustrators can use this stage for multiple purposes:
simplification: they can make the transition more readable and visually engaging, by bringing structure into its elements' motion paths, e.g., by creating a well positioned point in space for each molecule type through which it has to "travel" to reach its target position.
this structuring can serve occlusion handling, e.g., by placing these transit points in a way that the molecules flying through them reveal essential parts of the scene. 
information generation: they can also encode topological information that was not present in the original data, e.g., in the form of meaningful data highways that transport molecules from one state to another, or even to simulate the flow of blood between two organs.

to achieve this structuring, operators in this stage can implement techniques such as edge bundling. this means that an operator can introduce new controlpoints into the motionpath of a molecule, e.g., to re-direct it so that it does not occlude the existing scene.

as such, this stage, takes a subset from the scene hierarchy as input.
the child elements of this subset are analyzed in terms of their controlpoints (at the very least original and target position) and their relation to the controlpoints (original and target position) of the remaining elements of this subset (or even the entire scene).
depending on the operator type, new controlpoints that fulfill one of the above described functions are created as the output of the stage.
		%necessary to bring order into the transition across the spatial canvas.	
		%prerequisite for spatial coordination of the transition.		
		%can be used to infer additional information (e.g., information highways for certain entity types) - but also to decrease occlusion / increase readability of the transition.		
%	attributes created in this stage:
	%	control points between original and target position \& appearance.
		%control point do not suggest a timing but rather key frames for each entity or subset.		
%		input: set of layouted entities (they possess original and target state).		
	%	output: transition path based on additional CPs for each entity/subgroup.
		
	
\subsubsection{Timing}

		the timing stage is responsible for the temporal coordination of the transition by determining the order and speed at which entities or subsets reach their target position and visual form.
		
		as such, this stage is the illustrators' canvas in the temporal dimension.

		while the inherent purpose of this stage is to encode chronological information, i.e., the sequence of events, illustrators can also use it for additional purposes:
			they can make the transition more readable \& visually engaging by reducing the number of simultaneous visual stimuli, i.e., by starting the transition of indicisual molecules / subsets with a time offset to each other, thus creating staged transitions/animations [cite heer?]. %i.e., by timing when and how fast individual molecules or subsets should approach their target destinations, as well as their target representations,
			timing can also be used for occlusion handling, i.e., by first starting the transition of elements that occlude important structures or that are closer to the viewing position, while other elements remain in their positions until they are revealed.
			
			further, timing can also be used for controlling visual stimuli. the transition can be timed in a way that the attention is steered to a currently important structure or event by animating what should be in focus while keeping the remaining scene still.
			
as such, operators of this stage, depending on the intent that they implement, create a time curve for each entity that determines the start time and speed of the spatial and visual transition. optionally they can also create an end time, i.e., determine, when an element should cease to exist but also, when the transition should stop, i.e., whether an element should reach its final destination as well as how close it should get. this can be used to create a target representation that looks like it stopped in mid-motion.~~~
			
			
				
	
	
	
\subsubsection{Sampling}



\subsection{Story Telling}
\subsubsection{Annotations}
	design decisions:
		necessary for:
			story telling (labels and annotations) => inform,
			steer attention (pointers),
			supplying frames of reference (legends \& coordinate systems) => orientation.
			additionally used in static images / small multiples for supplementing the information that is lost due to the missing animation (continuous transition):
			
				- glyphs that indicate the direction of a motion
				
				- target destination of an apparently moving entity
				
	description:
		can support understanding of the transition (e.g., arrows) - especially in still images.
		can support understanding of the data (e.g., labels).
		
	attributes created in this stage:
		labels/glyphs/...,
			content (text,...),
			positions \& time of fadein/fadeout
(or are these handled by timing, layouting \& trajectory?)
				
\subsubsection{Guided Navigation}
	design decisions:
		essential component for storytelling.		
			steering attention towards specific events/details in the data => in a guided walk/fly through manner.
		necessary if the illustrator chooses a destination for the target rep that is outside the initial view frustum-
		
	attributes modified in this stage:
		camera positions \& lookat vector,
		timing handled by timing stage?
		
