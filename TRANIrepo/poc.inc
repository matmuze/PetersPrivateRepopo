					
\begin{figure*}[t!]
\centering
 \includegraphics[height=5cm, width=\linewidth]{figures/infovis.png}
\caption{\label{fig:spaces}Infovis}
\end{figure*}

\section{Use Cases}
%[we just learned about the pipeline - now we want to know how it can be actually used - surprise: we actually have a proof of concept implementation of it]
%Illustrators now can use this pipeline of metamorphers to create continuous representations that depict a desired metamorphosis of a given source representation to an intended target representation by combining the metamorphers on each pipeline stage that create the intended relations between the source and the target representation. %that answer specific questions / relate two different representations to each other
%To actually enable an illustrator to apply our method, we created a proof of concept implementation of our pipeline.
%[then we explain the usecase setting based on the data - give details on the data]
%In order to apply our method to solve relevant problems, we approached an illustrator and, in collaboration, created three different use cases for a data set of HIV. 
%This data set represents an HIV particle contained within blood serum \textbf{(see Figure XXX)}. The three questions that we helped to answer with our demonstration are: 1) what does the three dimensional structure of the virus and its inner compartments actually look like and how do they relate to each other hierarchically? 2) what types of molecules are contained in which compartment of virus, how do they look like, and in which approximate quantity are they present? 3) how large is the volume of each compartment and the molecules contained within in respect to each other?

After the description of the theoretical pipeline, we demonstrate its utility on several use cases.
We show these examples on the structural model of the human immunodeficiency virus which is built-up from thousands of macromolecules. The HIV particle is contained within blood serum \textbf{(see Figure XXX)}. The source visual representation is the direct rendering of the structural data set, which is then continuously transformed into a particular destination visualization space. Each example highlights a different aspect of the structure: 1) what does the three dimensional structure of the virus and its inner compartments actually look like and how do they relate to each other hierarchically? 2) what types of molecules are contained in which compartment of virus, how do they look like, and in which approximate quantity are they present? 3) how large is the volume of each compartment and the molecules contained within in respect to each other?

%[first we motivate why illustrators would want to use the pipeline]



\subsection{Explosion of Molecular Structures}
	%[motivate it - what problem does it solve in presenting the data]
Since molecular structures of the HIV data are very densely packed, it is impossible to inspect the outer and inner structures of the virus at the same time. 
The four structures that we want to show are assembled in an onion-like structure where one compartment is contained in another one. We therefore chose to convey the encapsulation of compartments in form of an exploded view (Figure \ref{fig:expl}), to answer our first question.

%We can achieve the transition of the HIV data to an exploded view in the following way:
%how do we want to relate the source rep to the target rep?
%First, we want to create the relation of the original data to the four compartment structures of the target representation. In the data re-structuring stage, we therefore need to create four subsets from our original data that correspond to these compartments. 

The specific pipeline for creating the continuum between the original visualization and the exploded view starts with restructuring. In order to create the relation of the original data to the four compartment structures of the target representation, we create subsets for all four compartments in the restructuring stage. %create subsets from our original data that correspond to these compartments.
%Thereby we create the relation of the original data to the four compartment structures of the target representation.
To create the compartment subsets, we exploit the fact that each compartment contains molecules of different types, and implemented a \textit{type range} metamorpher. The subsets crated by the type range metamorpher contain all given molecules that match a specified type range. If each molecule type could exist within multiple compartments, we could achieve the creation of the compartment subsets, by spatially grouping the molecules with a \textit{spatial splitting} metamorpher. A spatial splitting metamorpher checks the position of a given list of molecules in respect to a spatial object, like a plane, cube, or sphere, that the user can position freely in the scene. Molecules are then assigned to two new subsets, depending on which side of the object they are situated.
To create the seam at which compartments are split for the explosion, we actually apply a spatial splitting metamorpher to spatially subdivide the three outer of the four subsets that we just created along a plane.
%Since three of the four compartments that we just created are exploded in our desired target representation, we further have to spatially subdivide these compartments along a plane. We therefore implemented the \textit{plane splitting} metamorpher that checks the position of a given list of molecules in respect to a plane that the user can freely position in the scene. Molecules are then assigned to two new subsets, depending on which side of the plane they are situated. %that are added as child nodes to the subset that was subdivided
At the end of the restructuring stage, the root node of the scene hierarchy has four child nodes for the compartment subsets. The nodes of the three compartments that are exploded in the final representation, have two additional child nodes containing the spatial subdivision.

Since the visual representation of individual molecules does not change across the source and the target representation, we do not need to apply any metamorphers in the morphing stage of our pipeline.

In order to relate the original unexploded data to the final exploded representation, we need to call \textit{translation} and \textit{rotation} metamorphers in the layouting stage that create the translation (and slight rotation) of the explosion for each pair of spatially split subsets (Figure \ref{fig:explode}b). An additional translation moves each inner compartment to the right of its previously encapsulating compartment (Figure \ref{fig:explode}c).

We now created the continuum between the original unexploded and the exploded target representation. In order to present the transition in a pleasant way, we follow the remaining steps of our pipeline.

Since both, source and target representation, remain within the same view frustum, and we do not explicitly point the camera on any specific details, we apply no metamorpher in the camera control stage.

Our original data differs from the exploded target representation only in position and topology (the split compartments). To present the transition, we move all compartment subsets as a unit so that they keep their shape during the transition. In the trajectory stage, we therefore apply the \textit{linear interpolation} metamorpher to achieve a linear transition along the continuum between source and target representation.

In the layouting stage, we apply a total of XXX layout metamorphers/operations to create the relation to the exploded representation. If all these operations would be executed at the same time, the transition could be hard to follow [cite Heer paper here]. In the timing stage, we can make the presentation of the transition more pleasant, by applying a \textit{delay} metamorpher. The delay metamorpher adjusts the time curve of each compartment subset so that each subsequent explosion start only after the previous is finished. To suggest the opening motion of each exploding compartment in the final representation, we apply a \textit{[need fitting name]} metamorpher that adjusts the time curve of a few random molecules in such a way, that they do not finish their transition. During the transition, the opening compartments thus leave a trail of molecule "breadcrumbs" behind.

The only thing that is left to do now is to sample the continuum representation that we created. We chose a \textit{dense/continuous sampling} metamorpher to create a ten second animation with twenty four frames per second for the supplemental video. For the Figure \ref{fig:explosion} we applied a \textit{sparse sampling} metamorpher [or we took stills from this video?][or we have one sampling metamorpher that we used for video and figures but with different parametrizations - how to spin/sell this?].
%We parametrized the \textit{sampling} metamorpher to create a ten second video, with twenty four frames per second to create the animation for the supplemental video. 

%refer to figure!
	%[then describe how we create it with our metamorphers]
%[explosion: focus on data \& timing]


\subsection{Schematization of Molecular Structures}
	%[motivate it - what problem does it solve in presenting the data]
	The data consists of 42 types of molecules, that have a total of XXX number of instances, consisting of a total number of YYY atoms.
	
%[then describe how we create it with our metamorphers]	
We can achieve the transition of the HIV data to an exploded view in the following way:
%how do we want to relate the source rep to the target rep?


%how do we present the transition/continuum?

%[schematization: foucs on layouts]
	
	
\subsection{Representation of Quantitative Relations}
	%[motivate it - what problem does it solve in presenting the data]
	%[then describe how we create it with our metamorphers]
%[infovis: focus on morphing, camera, trajectory]
