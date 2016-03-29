\subsection{Discussion of Results}



	
\subsection{occlusion}
Independent of the intended purpose of a transition, it is essential, how the transition is presented, in order to make it engaging, readable, and valuable (in the sense that it conveys relevant information).
Three high level tasks are responsible for achieving these goals: occlusion handling, the steering of the viewer's attention, and the reduction of visual stimuli.
The tasks can be achieved in both, the target representation of the transition, and during the transition itself. In the former case, the continuum creation pipeline stages are responsible, in the latter the continuum presentation stages.
occlusion handling helps to.... can be handled for instance by thsese stages.. by doin this or that or 
steering helps to... can be handled for instance by...
stimuli reduction helps to.. can be handled for instance by.. stages

	is of course a central factor that could hinder a user's understanding of a transition.


		grouping (prerequesite / support / not directly responsible): choose groups so that they dont interfere with each other (depending on how you plan to transform the data)
			TODO: come up with examples that describe which kind of grouping would be beneficial for which kind of target state
				e.g., group the data first into layers parallel to the viewing plane that basically peel the data
		layouts
				bar: within the bar occlusion does not matter, as long as the bar represents entities of the exact same type
				general: the placement of entities/subests should be chosen so that they dont occlude each other from the viewing angle. 
			maybe we should not distinguish between inner and outer layout since this kind of restricts us to having two layouts instead of n.

then again, we could argue that there can be n-outer layouts, and one inner layout
		morphing:
			same as inner layout: within the shape occlusion is not an issue
			
		trajectory:
			the trajectories offer two of techniques for avoiding occlusion.
			
				edge bundling:
				setting control points so that paths don't occlude each other
				todo: anything else?
				
		timing:
			coordination of timing and speed of elements, e.g., staging
			
			




\subsubsection{shematization}
	discussion: 
	@discussion of results: transition = more intuitive to follow.
This metamorphosis corresponds with a transformation within the same visualization space.

		because this type of automatic illustrative schematization has not been presented/solved yet in literature, we present it as our tertiary contribution...

\subsubsection{infovis}

shapes and positions of compartments and molecules are sacrificed. 
%high level shapes (e.g. of compartments or other structures) for low level information (details on the data such as count of instances).		
@discussion: here, large distance between representation forms in visualization space - a continuous transition is therefore especially suitable for conveying the transition..




%\subsubsection{animation}tversky:	congruence principle:		the structure and content of an external representation should match the structure and content of the desired mental representation.	apprehension principle:		the structure and content of the external representation should be readily and accurately perceived and comprehended.
		
		\subsubsection{things that should be preserved:} depending on the usecase / representation - not all properties are essential for each representation form.
	\begin{itemize}
		\item instance level: position of instances
		\item type level: shape of types, relative size of types, color of types (?), number relation between types
		\item compartment level: shape/pos/size/color of compartments / structures
		\item global level: volumetric dimensions of the data
		\item todo: what else?
	\end{itemize}
		
		
		
		
		
		
		
		
		
		

%\textbf{[this is the old usecase section]}
%In this section, we will demonstrate our proof of concept implementation based on three exemplary use cases that we developed with illustrators. We will first describe our data and then motivate these use cases, [actually, we already motivated them in the introduction..]

%After this, we will motivate the components that all three use cases have in common.
%And finally, we will describe each use case's particular components and how their application produces the desired representations.
%our PoC implementation allows illustrators to generate illustrative representations of their data, as well as coordinating/authoring the transitions to these altered representations. 
%we designed two types of representations and created the components that our pipeline requires to produce them for arbitrary molecular data sets.
%we will first discuss the representations that we designed and then go into detail concerning the components that are involved in creating them.
%The components for each stage can be parametrized and queued based on a simple scripting interface.
%\subsection{Use Case Descriptions}

%Our use cases are demonstrated on a data set representing an HIV particle engulfed in blood serum. The data consists of 42 types of molecules, that have a total of XXX number of instances, consisting of a total number of YYY atoms. The data can be partitioned into three closed compartments: the blood serum, the outer shell (membrane?) of the HIV particle, and the nucleus within the particle. They were supplied to us in the cellPACK format [cite cellpack].

%\subsection{Explosion of Molecular Structures}
%Since molecular structures are very densely packed, it is impossible to inspect the outer and inner structures, e.g., of a virus, at the same time, without applying some sort of occlusion handling technique, such as exploded views [cite some fundamental exploded view paper] [kind of have to repeat the argumentation from the introduction here - i guess here i should be more specific..].
%[why is it necessry (problem statement)][what does it preserve(focus)][what does it sacrifice]

		
		
	%	\subsection{Representation of Quantitative Relations}
%For the explanation of the molecular data, often also the relation of quantitative aspects is important for its understanding, e.g, how many different molecules of each type does the HIV particle contain, or how much of the volume within the particle does each type occupy? 
%Scientific illustrator Graha Johnson, for example, conveyed the quantities in an award-winning video demonstration of the decomposition of an XXX cell.
%In order to achieve this sort of representation, the molecular data has to be transformed into a different visualization space. A stronger abstraction than in the previous two examples takes place.
%To convey these quantitative information about aggregated volumetric and count information, shapes and positions of compartments and molecules are sacrificed. Since this transformation is across visualization spaces, the target representation is harder to relate to the original representation.
%high level shapes (e.g. of compartments or other structures) for low level information (details on the data such as count of instances).
		
%@discussion: here, large distance between representation forms in visualization space - a continuous transition is therefore especially suitable for conveying the transition..
		

		


%\subsection{Common Components}
%The following metamorphers are involved in all three usecases.
%\subsubsection{Grouping by Type Range}
%In all use cases, we want to partition the data into the afore mentioned three high level subsets of the blood serum, HIV membrane, and HIV capsid. This is necessary to be able to operate on each subset individually, e.g., when exploding these compartments separately [mention here already how we use it in each usecase?]. 
%We therefore need subsets that contain entities of a specified type range.
%The metamorpher therefore creates as many subsets as there are ranges specified, and parses a given list of entities. Entities of a type matching a defined range, are then assigned as children to the respective subset.

%\subsubsection{Text Labels}\subsubsection{Icons / Textures}\subsubsection{Translate?}\subsubsection{Rotate?}\subsubsection{Linear Interpolation}\subsubsection{Staging}\subsubsection{Spatial Time Offset}\subsubsection{Guided Navigation}\subsubsection{Continuous Sampling}
%\subsection{Specific Components}[will be placed in the respective usecase]

%\subsubsection{Grouping by Type - use case C}We need to visually or spatially transform all molecules of the same type in a uniform fashion, e.g., to spatially transform them into a collective shape. [refer to all usecases here?]The output of this metamorpher is therefore a list of subsets that contain entities of the same type.The metamorpher parses a given list of entities and creates a new subset for each new type-ID that it finds. Entities of the matching type are then assigned as children to this subset.

%\subsubsection{Cloning}\subsubsection{Spatial Grouping}\subsubsection{Blurring}\subsubsection{Morphing}\subsubsection{Bar Layout}\subsubsection{Line Layout}\subsubsection{Schematic (Scale \& Rotate)}\subsubsection{Transit Points / Bundling}\subsubsection{SLERP}



%\subsection{Explosion of Molecular Structures}


%\subsubsection{Applied Metamorphers}--data transform:1) [type range grouper] create three high lvl subsets: the blood serum, the membrane, the capsid2) [plane splitter] spatially partiton each subset with the same plane (each one could also be split with a different plane theoretically)--annotations:3) text labels: "serum", "capsid", "membrane"--blending:no blending applied here
%--layouting:for each high lvl subset:4) [translate] upper part up, lower part down5) [rotate] rotate upper part a bit up, lower part a bit down6) (for all except the first subset)[translate] the subset to the left (double the amount of the previous subset's BB width)7) position label on top/below each high lvl subset
%--trajectory:8) [linear interpolation]--timing:9) introduce a [delay] for each consecutive layout operation (translate sideways of highlvl subsets \& translate up/down for low lvl subsets)10) [] let some random molecules not finish the transition11) [] let labels appear after animation is finished--navigation:12) guided navi as subset explosion \& transition use more and more screenspace--sampling:13) continuous sampling






	
%\subsubsection{Applied Metamorphers}--data transform:1) [type range grouper] create three high lvl subsets: the blood serum, the membrane, the capsid2) [copy] the entire partitioned data set because we will render it in two different representations => results in copy A \& B
%--annotations:do the circular annotations?
%--visual transform:A: blurrin \& increasin contrast of alpha channel for nice charp edges of each subset individuallyB: scalin
%--layouting (spatial transform):A: renderin them on top of each other (occlusion management)B: rotatin
%--navigation:not necessary, because we stay in the same visualization space / spatial extents
%--trajectory:B: linear interpolation between rotations
%--timing:staged per compartmentdistance field left to right for each
%--sampling:continuous


%\subsection{Representation of Volumetric Relations}
%\subsubsection{Applied Metamorphers}--data transform:1) [type range grouper] create 3 hierarchical compartments by typerange2) [single type grouper] split all three by type => subsets containing all molecules of same type for each hierarchical compartment
%--annotations:3) [txt-label] for each type subset10) [representative] molecule for type subset
%--blending:4) [slice-flatterer] create target rep for each molecule with blending: slice with hight representing the molecule volume
%--layouting:5) [bar layout] for each type compartment - the layout puts all molecule slices on top of each other to create histogram bars6) the [line layout] puts all the bars within a compartment side by side7) the [translate layout] then moves the new center for the next line layout for the next compartment
%8) layout: put label below below each bar9) layout: put rep below label
%--trajectory:10) [top-down-fall-in-component]: for each molecule in bar subset, we add a control point to the top of the bar, so that the molecule seems like falling into the bar instead of going straight from its original position to the designated position within the bar.
%--timing:11) [distance offset] a plane can be positioned in space. the distance of each molecule/compartment to this plane is measured and used for a the creation of a time offset that specified when each molecule is allowed to start its transition
%12) timing: make label \& rep appear when animation is finished
%--guided navi:13) [whole-data-in-view-keeper] update the camera pos \& lookat to keep all molecules in the view frustum.
%--sampling:14) continuous sampling




		