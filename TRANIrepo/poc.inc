\section{Use Cases}
%[we just learned about the pipeline - now we want to know how it can be actually used - surprise: we actually have a proof of concept implementation of it]
%Illustrators now can use this pipeline of metamorphers to create continuous representations that depict a desired metamorphosis of a given source representation to an intended target representation by combining the metamorphers on each pipeline stage that create the intended relations between the source and the target representation. %that answer specific questions / relate two different representations to each other
%To actually enable an illustrator to apply our method, we created a proof of concept implementation of our pipeline.
%[then we explain the usecase setting based on the data - give details on the data]
%In order to apply our method to solve relevant problems, we approached an illustrator and, in collaboration, created three different use cases for a data set of HIV. 
%This data set represents an HIV particle contained within blood serum \textbf{(see Figure XXX)}. The three questions that we helped to answer with our demonstration are: 1) what does the three dimensional structure of the virus and its inner compartments actually look like and how do they relate to each other hierarchically? 2) what types of molecules are contained in which compartment of virus, how do they look like, and in which approximate quantity are they present? 3) how large is the volume of each compartment and the molecules contained within in respect to each other?

After the description of the theoretical pipeline, we demonstrate its utility on several use cases.
We show these examples on the structural model of the human immunodeficiency virus (HIV) which is built-up from thousands of macromolecules. The HIV particle is either contained within blood serum (Figures \ref{fig:teaser} and \ref{fig:explosion}), or with the blood serum removed (Figure \ref{fig:infovis}). The source visual representation is the direct rendering of the structural data set, which is then continuously transformed into a particular destination visualization space. Each example highlights a different aspect of the structure: 1) what does the three dimensional structure of the virus and its inner compartments actually look like and how do they relate to each other hierarchically? 2) what types of molecules are contained in which compartment of virus, what do they look like, and in which approximate quantity are they present? 3) how large is the collective volume of each molecule type within the HIV particle in respect to each other?

%[first we motivate why illustrators would want to use the pipeline]



\subsection{Explosion of Molecular Structures}
	%[motivate it - what problem does it solve in presenting the data]
Since molecular structures of the HIV data are very densely packed, it is impossible to inspect the outer and inner structures of the virus at the same time. 
The four structures that we want to show are assembled in an onion-like structure where one compartment is contained in another one. We therefore chose to convey the encapsulation of compartments in form of an exploded view (Figure \ref{fig:explosion}), to answer our first question.

%We can achieve the transition of the HIV data to an exploded view in the following way:
%how do we want to relate the source rep to the target rep?
%First, we want to create the relation of the original data to the four compartment structures of the target representation. In the data re-structuring stage, we therefore need to create four subsets from our original data that correspond to these compartments.

The specific pipeline for creating the continuum between the original visualization and the exploded view starts with the data restructuring. In order to create the relation of the original data to the four compartment structures of the target representation, we create subsets for all four compartments in the restructuring stage. %create subsets from our original data that correspond to these compartments.
%Thereby we create the relation of the original data to the four compartment structures of the target representation.
To create the compartment subsets, we exploit the fact that each compartment contains molecules of different types, and implemented a \textit{type range} metamorpher. The subsets crated by the type range metamorpher contain all given molecules that match a specified type range. If each molecule type could exist within multiple compartments, we could achieve the creation of the compartment subsets, by spatially grouping the molecules with a \textit{spatial splitting} metamorpher. A spatial splitting metamorpher checks the position of a given list of molecules in respect to a spatial object, like a plane, cube, or sphere, that the user can position freely in the scene. Molecules are then assigned to two new subsets, depending on which side of the object they are situated.
To create the seam at which compartments are split for the explosion, we actually apply a spatial splitting metamorpher to spatially subdivide the three outer of the four subsets that we just created along a plane.
%Since three of the four compartments that we just created are exploded in our desired target representation, we further have to spatially subdivide these compartments along a plane. We therefore implemented the \textit{plane splitting} metamorpher that checks the position of a given list of molecules in respect to a plane that the user can freely position in the scene. Molecules are then assigned to two new subsets, depending on which side of the plane they are situated. %that are added as child nodes to the subset that was subdivided
At the end of the restructuring stage, the root node of the scene hierarchy has four child nodes for the compartment subsets. The nodes of the three compartments that are exploded in the final representation, have two additional child nodes containing the spatial subdivision.

Since the visual representation of individual molecules does not change across the source and the target representation, we do not need to apply any metamorphers in the morphing stage of our pipeline.

In order to relate the original unexploded data to the final exploded representation, we apply metamorphers of the layouting stage performing the necessary spatial transformations. In this step, we finalized the creation of the continuum between the original unexploded and the exploded target representation. In order to present the transition in a pleasant way, we follow the remaining steps of our pipeline. 

%In order to relate the original unexploded data to the final exploded representation, we need to call \textit{translation} and \textit{rotation} metamorphers in the layouting stage that create the translation (and slight rotation) of the explosion for each pair of spatially split subsets (Figure \ref{fig:explode}b). An additional translation moves each inner compartment to the right of its previously encapsulating compartment (Figure \ref{fig:explode}c).



Since both, source and target representation, remain within the same view frustum, and we do not explicitly point the camera on any specific details, we apply no metamorpher in the camera control stage.

Our original data differs from the exploded target representation only in position and topology (the split compartments). To present the transition, we move all compartment subsets as a unit so that they keep their shape during the transition. In the trajectory stage, we therefore apply the \textit{linear interpolation} metamorpher to achieve a linear transition along the continuum between source and target representation.

In the layouting stage, we apply a total of XXX layout metamorphers/operations to create the relation to the exploded representation. If all these operations would be executed at the same time, the transition could be hard to follow [cite Heer paper here]. In the timing stage, we can make the presentation of the transition more pleasant, by applying a \textit{delay} metamorpher. The delay metamorpher adjusts the time curve of each compartment subset so that each subsequent explosion starts only after the previous is finished. 

In order to also support understanding for the structures of individual molecules/proteins and to convey the opening motion of each exploding compartment in the final representation, we show representatives of the proteins separated from the compartments in which they are contained.
These representatives are molecules that simply do not complete their transition.
To end the transition for these molecules before they reach their final position, we manipulate their timecurves with a \textit{[need fitting name]} metamorpher. During the transition, the opening compartments thus leaves a motion trail of molecules behind that makes individual molecules discernible.

The only thing that is left to accomplish now, is to sample the continuum representation that we created. We chose a \textit{dense/continuous sampling} metamorpher to create a ten second animation with twenty four frames per second for the supplemental video. For the Figure \ref{fig:explosion} we applied a \textit{sparse sampling} metamorpher [or we took stills from this video?][or we have one sampling metamorpher that we used for video and figures but with different parametrizations - how to spin/sell this?].
%We parametrized the \textit{sampling} metamorpher to create a ten second video, with twenty four frames per second to create the animation for the supplemental video. 


%short justification of why an animation between the S and D was necessary in this case.
%what does the three dimensional structure of the virus and its inner compartments actually look like and how do they relate to each other hierarchically?

With the transition that we just created, we can explain to a viewer, how the four compartments are actually enclosed within each other, as the final representation alone does not convey that one object is enclosed in another, especifally for a viewer who has not seen the dataset before.
Furthermore the transition explains where the isolated molecules originate from. 



\begin{figure*}[ht!]
\centering
\subfloat[]{\label{fig:explosion0}\includegraphics[width=0.25\linewidth]{figures/explosion0.png}}
\subfloat[]{\label{fig:explosion1}\includegraphics[width=0.25\linewidth]{figures/explosion1.png}}
\subfloat[]{\label{fig:explosion2}\includegraphics[width=0.25\linewidth]{figures/explosion2.png}}
\subfloat[]{\label{fig:explosion3}\includegraphics[width=0.25\linewidth]{figures/explosion3.png}}
\caption{\label{fig:explosion} Metamorphosis to an exploded representation of blood serum and HIV compartments. A  trail of molecules is left behind during the transition to indicate their individual size and shape.}
\end{figure*}

\begin{figure*}[ht!]
\centering
\subfloat[]{\label{fig:infovis0}\includegraphics[width=0.25\linewidth]{figures/infovis0-1.png}}
\subfloat[]{\label{fig:infovis1}\includegraphics[width=0.25\linewidth]{figures/infovis1.png}}
\subfloat[]{\label{fig:infovis2}\includegraphics[width=0.25\linewidth]{figures/infovis2.png}}
\subfloat[]{\label{fig:infovis3}\includegraphics[width=0.25\linewidth]{figures/infovis3-1.png}}
\caption{\label{fig:infovis}Metamorphosis of molecules into histogram bars that display the volume that each molecule takes up in the HIV particle. A distance based time offset reveals the layered compartments one by one during the metamorphosis.}
\end{figure*}









\subsection{Schematization of Molecular Structures}%[schematization: foucs on layouts]

%[motivate it - what problem does it solve in presenting the data]
% 2) what types of molecules are contained in which compartment of virus, how do they look like, and in which approximate quantity are they present?
	
%since the data is XXX, it is impossible to see YYY
Besides the structural composition of a cell, biologists are often also interested in the cell's molecular composition, i.e., what types of molecules are present in the data, in which compartment are they contained, what do the molecules look like?
The HIV data, for instances, contains 42 different molecules but due to their high count (thousands of molecule instances across these 42 types), their mostly random distribution and the dense packing of the data, the detailed information about the number of types and their individual shape is impossible to deduce from the original data.
Illustrators therefore create atlas based views (such as in Figure \ref{fig:schema}d) that show a simplified schematic representation of a cell in order to highlight the shapes of different molecules, as well, as the shape and size of the structures that they collectively compose and are contained in. Low level details of the noisy molecule distribution, i.e., the exact count, position and shape of individual molecules are suppressed for this schematic representation.

We achieve such a transition to an atlas based view with our pipeline in the following way:
Similar to the first step in the exploded view use case, we restructure the data with the type range metamorpher to create the relation to the four subsets that represent the compartments of our schematic target representation. Technically, we need each subset twice. Since the four subsets will be blended in image space to create the uniform compartment color, we need a copy of each subset for the layouting stage. The \textit{copy} metamorpher creates copies of the supplied subsets, resulting in copies A and B for each subset.

%To indicate the shape of compartment structures, we create a uniform background color that represents the colors of the molecules
Since the shapes of compartments in the HIV particle are occluded in the original representation, we create a uniform color that marks each compartment's area in the morphing stage.
We create the relation of our original noisy data representation to the uniform compartment color by applying a \textit{blur} metamorpher. 
The blur metamorpher creates an additional render pass for each subset of copy A. The molecules in the respective subset are blurred with a Gaussian blur kernel into a uniform color. By increasing the contrast of the alpha channel for the blurred image, the sharp edges of each compartment are created. %If we wanted to keep a hint of the noisy color distribution, we could reduce the blur kernel. the compartments would still be separated from each other due to the sharp edges of the constrast in the alpha channel.

To reveal the compartment area colors that we created in the previous step, and to enable the display of enlarged representatives for each molecule type that are an essential for conveying the molecule shapes, we have to reduce the noisy clutter of molecules.
We achieve this reduction in the layouting stage, where we create the relation of our dense and noisy original data to the sparse enlarged rendering of representative molecules and compartment shells in the final representation.
For a given subset of copy B, the \textit{schema} layout metamorpher differentiates between membrane molecule types, i.e., molecules that compose the shell of a compartment, and non-membrane types, i.e., the ones that are floating within a compartment, in order to create the final schematic representation.
Since illustrators know, which molecule types the membranes of compartments are composed of, they can specify the membrane type so that they are treated differently than the molecules within compartments. For membrane molecules, the schema layout metamorpher picks the ones that are closest to the border of the compartment, from the viewing position. The picked membrane molecules remain their original size and rotation. The non-picked membrane molecules are scaled to zero to be invisible in the final representation, in order to reveal the compartments and molecules within. Alternatively, instead of scaling, transparency could be applied to membrane molecules in the morphing stage. For membranes, the schema layout operator thus preserves the membranes shells of compartments while revealing the inner structures of a compartment.

For non-membrane molecules, the illustrator has control over the total count of representatives that 
should be displayed in a compartment. Based on the specified number, the schema layout metamorpher calculates how many representatives of each molecule type of the given subset should be kept. The number of kept representatives depends on the ratio between the total number of molecules of each type within the subset, and the maximum number of allowed representatives.
Each molecule has one guaranteed representative.
Once the number of representatives for each molecule type is calculated, the schema layout metamorpher places them on a grid. In order to avoid cluttering of the representatives and to achieve a more pleasant result image, the grid positions are chosen so that molecules are evenly spaced from each other. Representatives are placed iteratively by type to avoid accidental clustering of the same types.

To make the atomic structures of molecule representatives better visible, the schema layout metamorpher enlarges them.
Since not also the position but also the rotation of molecule instances is randomly distributed, the schema layout metamorpher also rotates each representative molecule back to 90 degree, which is the angle that shows the top down look of a molecule.

To achieve smooth rotations during the transition, the trajectory stage uses a \textit{SLERP} metamorpher for the interpolation between the original and the target orientation.

Since inner structures are occluded by the outer structures of the blood serum and HIV particle, we use the timing stage to reveal the structures step-by-step. A \textit{staged timing} metamorpher manipulates the time curve of the molecules of a compartment in such a way, that the transition of each compartment starts with a specified delay.
Additionally, in order to create a peel-away effect that reveals the inner structures and molecule representatives of each compartment from left to right, we use a \textit{distance offset} metamorpher. The distance offset metamorpher calculates the distance of each molecule instance to a plane or other object, that the illustrator can place in the scene. The distance to the plane is then used as a measure for creating an additional distance based delay in each molecules time curve.

Since the original and the target representation occupy the exact same space, we do not need to apply any guidance in the camera control stage.

Since we want to create an animated transition from the continuum that we just set up, we apply the same continuous sampling as in the previous use case.


%To achieve this schematic representation therefore, on the one side, specific molecules have to be chosen as representatives of their type to be displayed at a sufficiently large scale (focus), while suppressing the noisy distribution of a vast amount of other molecules (context). 

%molecules that do not have a noisy distribution but form coherent structures, such as cell membranes, have to be preserved.	


%%	why is the transition to the view necessary as opposed to just having the final image?
%Even though the final image of the schematization of the HIV particle is conceptually similar to the original representation, the transition between both representation reveals and emphasizes relations that are not obvious.
The presentation of the continuum between the original data representation and the schematization emphasizes aspects of the data that may not be self explanatory.
The transition of the scaling more directly shows how small the original molecule representatives were.
The transition of rotations emphasizes the fact that molecules can have different orientations in the original data.
The staging per compartment enables occlusion handling as it reveals inner structures in intermediate states of the transition which would not happen in a side by side comparison and non-staged animation.
The distance offset delay reduces the transformation at any given time to a small vertical stripe of the data, thereby reducing the amount of simultaneous visual stimuli, making the animation more readable, and directing the users attention to the one specific location that is transforming at each point in time.



	


	



% therefore aims to preserve the size and shape of high level compartments within the data, and
%This representation was motivated by illustrative drawing, like the ones that can be found in medical books.
%\paragraph{simplification (schematization)}:		simplify data to create understanding.

%		resembles the illustrations that we see in biomedical textbooks.
	%	tries to preserve anatomical attributes but in a simplified / schematic way.
		%tries to give overview of elements in  the data and possibly their interrelations.
		


%how do we present the transition/continuum?


%justification: why was this transition necessary / why is the final image alone not enough?
	

	
\subsection{Representation of Quantitative Relations}%[infovis: focus on morphing, camera, trajectory]
For the analysis and explanation of molecular data often also the comparison of quantitative aspects is important for its understanding. %, besides structural information,
In our example, we convey how many different molecule types the HIV particle contains, and how much of the volume within the particle each type occupies.
Such quantification is necessary, for instance, when analyzing different life cycle stages of a cell.

The direct comparison of such information on the original 3D models of the cells can deceive due to the complexity of the molecular structures.
Illustrators therefore often supply quantitative information in the form of infographics, which are based in a different visualization space than the original biological data. In this space, spatial dimensions are not used to convey spatial dimensions but rather abstract dimensions, such as aggregations, e.g., of atom counts[cite tory/möller?].
%In order to achieve this sort of representation, the molecular data has to be transformed into a different visualization space.
%A stronger abstraction of the original spatial representation than in the previous two examples takes place.
The relation between the original spatial and the transformed abstract dimensions is even harder to grasp.
Continuous transitions are especially suitable for depicting such complex relations, as was successfuly demonstrated in the award-winning animation of the decomposition of a cell (Figure \ref{spaces}b). In this video, scientific illustrator Graham Johnson used an animated transition to convey the relation between the 3D model of a pancreas cell and an abstract depiction of volumetric relations between the elements of the cell.



%scientists and general audiences can learn a great deal about biology by comparing internal structural differences between cells from different parts of the bodies or different species, or different life cycle stages - but spatial comparisons can deceive
%compare and constrast multiple descriptive parameters of visually complicated 3d structures
%organizing molecules/proteins and averaging their volumes
%graph retains qualities of the native model
%hybrid between cell and infographic
%enables to compare similar looking cells
%information of hybrid easier to absorb than mentally merging quantifiation information from pie chart and original 3d model of cell
%complex interplay  of randomness and specific interactions in these structures that enables life to exist

In this final use case, we demonstrate how we can achieve such a transition to an abstract visualization space with our pipeline.
We chose to convey the quantitative information about the number of molecule types in the HIV particle and the volumetric relation between types by a histogram (Figure \ref{fig:infovis}d). The number of histogram bars corresponds to the number of molecule types. The height of each bar corresponds to the volume that the respective molecule type occupies in the HIV particle.
Since we are concentrating on displaying relations within the HIV particle, we remove the blood serum from our original representation before we restructure our data hierarchy to match the intended target representation.

Since each histogram bar has to represent a single molecule type, we use a \textit{group-by-type} metamorpher to create a subset for each type.

The histograms in the final representation are constructed from the individual molecules in our original data. Each molecule is represented as a slice with given base area and a height that represents the molecule's volume. The volume depends on the number of atoms that the molecule is composed of.
By stacking the molecule slices, we receive a height that is representative of the total volume of all molecules of the respective type.
In the morphing stage, we therefore apply an \textit{object space} metamorpher on each type subset, in order to morph the shape of each molecule to the aforementioned slice, by repositioning the atoms of the molecule. 

In order to layout the morphed molecule slices into the shape of a bar, we use a \textit{bar layout} metamorpher on each type subset. The bar layout simply stacks the molecule slices in a subset on top of each other. The bars are then positioned side-by-side along a line with a \textit{line layout} metamorpher.

Since we position the histogram bars in the final representation below the HIV particle, the molecules on top of the particle would, with a linear trajectory between their origin and destination point, fly through the particle, and exit the particle on the bottom side, before reaching their final position in the histogram.
To present the transition in a manner where molecules do not cross the HIV particle on their way to their destination, we introduce additional control points to the path of the molecules in the trajectory stage of our pipeline. \textbf{[TODO: description of first (sideways) CP]}

Further, we add a control point for each molecule type above its respective histogram bar to create a trajectory that looks like the molecules are filling the bar by pouring into it. We therefore bundle the trajectories of the molecules above each bar with a \textit{trajectory bundling} metamorpher.
We place the control point at the same height for all bars. To calculate the x/y position for a control point, we use the center of the bounding box of the respective molecule type subset.
Each subset in the scene hierarchy has a bounding box.
Bounding boxes are calculated when a subset is created and updated when a layout is applied.

Due to the onion like structure of the HIV particle, inner structures are occluded by outer structures.
Inner structures should therefore not start their transition before the outer structures, as they would never be visible in their original representation. Further, if the inner structures would fly through the outer structures to their target representation, a viewer would not understand, from which part of the virus exactly they would be coming from.
To present the transition in a manner, that reveals each original structure before it starts its transition, we apply the \textit{staged timing} metamorpher to peel HIV particle like an onion, starting with its outer layers.
In contrast to the previous two use cases, here, we stage the timing by molecule type to transition each molecular type individually into its histogram bar representation. The transition of each type starts after a certain delay / when the previous transition is finished.
To create the order of the staging that results in the peeling effect, we use a \textit{distance offset} metamorpher. The distance of each molecule of a specific type to the center of the particle is calculated and averaged. The average distance per type is then used for the ordering of the staging. As the center of the particle we assume the center of the bounding box of the root node of the scene hierarchy.

In contrast to the previous use case, the position of the final representation (the histograms) differs from the position of the original representation (the HIV particle).
A camera position that shows both representations at the same time would use the screen space inefficiently, since only during the transition both representations are visible. The original and the target representation would be shown with unused screen space where the respective other representation would be positioned.
We therefore implemented a simple \textit{guided navigation} metamorpher to use the available screen space efficiently by zooming in as closely as possible to the displayed data, while assuring that entire scene (all molecules) are visible at all times during the transition.
The metamorpher checks if molecule instances are culled from the view. If yes, then the camera is zoomed out until no more instances are culled. If no, the camera zooms in until instances are culled. A constant zooming in and out at the optimal position is avoided by smoothing the camera transition. The camera look-at vector is updated to look at the center of our scene, where our HIV particle is positioned.

Finally, to produce the animated transition to the histogram bars, why apply the same continuous sampling as in the previous two use cases.

The transition conveys two aspects of the data that a simple side-by-side presentation of original and target state would not. One the one side, the relation between the histogram bars and the molecular structures that they represent is established. On the other side, the inner structures of the HIV particle that are not visible in the original representation and not present in the target representation are revealed in the course of the transition.








\subsection{Expert Feedback}
We demonstrated the three usecases to two experts in illustration and animation in order to gather their feedback.
Each use case was presented in form a video of the respective animated transition.
We supplied the experts with questionnaires that contained specific questions for each use case. [mention the questions or list a few examples of the questions?]

\subsubsection{Exploded Views}
...waiting for feedback...
\subsubsection{Schematization}
...waiting for feedback...
\subsubsection{Histograms}
...waiting for feedback...





