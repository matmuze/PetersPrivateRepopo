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
			
		
	
\subsubsection{layouting}
	design decisions:
		necessary for enabling transformation of entities/subsets into a different space.
			transform spatial properties, e.g., from anatomical to abstract or to schematic.	=> transformation within the same visualization space (schematization) vs transformation across visualization spaces (abstraction).			
		prerequisite for creating the spatial extents of the target representation.
		
	description:
		deals with spatial attribute transformation.
		determines the target position for each created subset/entity.
			the spatial re-arrangement can be used to convey different information,
			i.e., move all entities of a subset spatially close to each other to separate them from other entities and convey the group size
			
			can be used to:
				spatially order/group entities (abstract),
				reduce entities (simplify),
				reveal hidden structures / entities (occlusion handling)
				
		a layout manipulates only pos/rot
			(scaling is already part of morphing).
			
		can be used on an "inner" level to position entities with respect to each other => give a shape to subsets (e.g., a histogram bar).
		
		can be used on an "outer" level to position subsets with respect to each other.
		
	attributes created in this stage: target..
		position \& rotation,
		input: a node in the hierarchy (not a leaf),
		output: a target position for each child entity of the node \& optionally additional CPs between original \& target position.
	
	PoC operators:
	
		inner:		
			bar:
				abstract,
			slice:
				abstract,
			sphere:
				abstract
				
		outer:		
			line:
				?,
			circle:
				?,
			explosion:
				occlusion handling,
		schematization layout (inner/outer/both?):
			simplify
			
	determines the target position for each created subset/entity
	
\subsubsection{blending/morphing}
	design decisions:
		prerequisite for creating the visual extents of the target representation.
		essential for enabling transformation of entities/subsets into a different representation form.
			transform visual properties,
			e.g., abstraction (cube, histogram), simplification (kekule, LoD, merging in schematization).
			
	description:
		deals with visual attribute transformation.
		entities or subsets change their individual or collective shape, in order to convey specific information or to change the visualization space.
		
			simplify:
				schematization: the noisy mixture that the molecules in a compartment compose, is blurred to form a uniform color that represents the compartment.
				
			abstract:
				histogram: the molecules that are layouted into a histogram bar are blended/overdrawn with a 2D histogram to better convey the abstract information the bar should represent.
				
			reveal (occlusion handling)
			
	attributes created in this stage: target..
		shape,
		size,
		color,
		style,
		dimensionality.
		
		input: original shape(s).
		
		output: morphed shape(s).
		
	PoC operators:
		unfolding,
		blending into new collective shape
			(schematization background,
			histogram bar),
		morphing
			(simplified shapes (like in GJ video)).
			
	determines the shape of an entity /subset in the target state.
	
\subsection{Transition}
\subsubsection{general}
these components are necessary for defining the transition, i.e., how and when each entity reaches its target position \& form.

\subsubsection{trajectory}
	design decisions:
		necessary to bring order into the transition across the spatial canvas.
			making the transition more readable \& visually engaging.
		also necessary to encode topological information, e.g., data highways.		
		prerequisite for spatial coordination of the transition.
		
	description:
		determines how an entity reaches its target position. can be used to infer additional information (e.g., information highways for certain entity types) - but also to decrease occlusion / increase readability of the transition.
		
	attributes created in this stage:
		control points between original and target position \& appearance.
		control point do not suggest a timing but rather key frames for each entity or subset.
		
		input: set of layouted entities (they possess original and target state).
		
		output: transition path based on additional CPs for each entity/subgroup.
		
	PoC operators:
		linear: from A straight to B,
		curved,
		bundling,
		motion blur.
		
	determines how an entity/subset reaches its target position/form
	
\subsubsection{timing}
	design decisions:
		prerequisite for temporal coordination of the transition,
		necessary to bring order into the transition across the temporal canvas,
			making the transition more readable \& visually engaging,
			steering amount of visual stimuli,
			occlusion handling.
		also necessary to encode chronological information, e.g., sequence of events.
		
	description:
		determines when an entity starts its animation and how fast the target destination should be reached.
		can be used to coordinate the animated transition, e.g., to decrease occlusion and the number of simultaneous visual stimuli in order to increase understandability of the transition. e.g., for creating a staged animation.
			
		input: list of entities/subsets \& offset function.
		
		output: start time \& transition speed (curve) for each entity.
		
	attributes created in this stage:
		time offset,
		speed,
		per entity / subset,
		lifetime,
			e.g., for annotations (blending in and out).
			
	offset function:
		depending on:
			inherent spatial parameters,
				position, distance to other entities, density, ..,
			external spatial parameters
				(cutting plane/object)
				
	determines the order and speed at which an entity/subset reaches its final pos/form.
	
\subsection{Story Telling}
\subsubsection{annotations}
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
				
\subsubsection{guided navigation}
	design decisions:
		essential component for storytelling.		
			steering attention towards specific events/details in the data => in a guided walk/fly through manner.
		necessary if the illustrator chooses a destination for the target rep that is outside the initial view frustum-
		
	attributes modified in this stage:
		camera positions \& lookat vector,
		timing handled by timing stage?
		
