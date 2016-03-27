					
\begin{figure*}[t!]
\centering
 \includegraphics[height=5cm, width=\linewidth]{figures/infovis.png}
\caption{\label{fig:spaces}Infovis}
\end{figure*}

\section{Use Cases}
%[we just learned about the pipeline - now we want to know how it can be actually used - surprise: we actually have a proof of concept implementation of it]
Real world illustrators now can use this pipeline of metamorphers to create continuous representations that depict a desired metamorphosis of a given source representation to an intended target representation by combining the metamorphers on each pipeline stage that create the intended relations between the source and the target representation. %that answer specific questions / relate two different representations to each other
To actually enable an illustrator to apply our method, we created a proof of concept implementation of our pipeline.
%[then we explain the usecase setting based on the data - give details on the data]
In order to apply our method to solve relevant problems, we approached an illustrator and, in collaboration, created three different use cases for a data set of HIV. 
This data set represents an HIV particle contained within blood serum \textbf{(see Figure XXX)}. The three questions that we helped to answer with our demonstration are: 1) what does the three dimensional structure of the virus and its inner compartments actually look like and how do they relate to each other hierarchically? 2) what types of molecules are contained in which compartment of virus, how do they look like, and in which approximate quantity are they present? 3) how large is the volume of each compartment and the molecules contained within in respect to each other?

%[first we motivate why illustrators would want to use the pipeline]



\subsection{Explosion of Molecular Structures}
	%[motivate it - what problem does it solve in presenting the data]
Since molecular structures of the HIV data are very densely packed, it is impossible to inspect the outer and inner structures of the virus at the same time. 
Since the four structures that we want to show, hierarchically contain each other, much like a Russian matryoshka doll, we chose to transform the virus representation to an exploded view (Figure \ref{fig:expl}), to answer our first question.

We can achieve the transition of the HIV data to an exploded view in the following way:
%how do we want to relate the source rep to the target rep?
First, we want to create the relation of the original data to the four compartment structures of the target representation. In the data re-structuring stage, we therefore need to create four subsets from our original data that correspond to these compartments. Since each compartment contains molecules of differing types, we implemented the \textit{type range} metamorpher that creates subsets that contain all given molecules that match a specified type range. These four subsets are added to the root node of our data that contains all molecules. Since three of the four compartments that we just created are exploded in our desired target representation, we further have to spatially subdivide these compartments along a plane. We therefore implemented the \textit{plane splitting} metamorpher that checks the position of a given list of molecules in respect to a plane that the user can freely position in the scene. Molecules are then assigned to two new subsets, depending on which side of the plane they are situated. %that are added as child nodes to the subset that was subdivided
The scene hierarchy is therefore extended by two additional child nodes containing the spatial subdivision for each subset that we just spatially subdivided.

Since the visual representation of individual molecules does not change across the source and the target representation, we do not need to apply any metamorphers in the morphing stage of our pipeline.

In order to relate the original unexploded data to the final exploded representation, we need to call \textit{translation} and \textit{rotation} metamorphers in the layouting stage that create the translation (and slight rotation) of the explosion for each pair of spatially split subsets (Figure \ref{fig:explode}b). An additional translation moves each inner compartment to the left of its previously encapsulating compartment (Figure \ref{fig:explode}c).

We now created the continuum between the original unexploded and the exploded target representation. In order to present the transition in a pleasant way, we follow the remaining steps of our pipeline.

Since both, source and target representation, remain within the same view frustum, and we do not want to explicitly point the camera on any specific details, we apply no metamorpher in the camera control stage.

Our original data differs from the exploded target representation only in position and topology (the split compartments). To present the transition, we therefore want to move all compartment subsets as a unit - they should keep their shape during the transition. In the trajectory stage, we therefore apply the \textit{linear interpolation} metamorpher to achieve a linear transition along the continuum between source and target representation.

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
%[schematization: foucs on layouts]
	
	
\subsection{Representation of Quantitative Relations}
	%[motivate it - what problem does it solve in presenting the data]
	%[then describe how we create it with our metamorphers]
%[infovis: focus on morphing, camera, trajectory]
