					
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


\subsection{Schematization of Molecular Structures}%[schematization: foucs on layouts]

%[motivate it - what problem does it solve in presenting the data]
% 2) what types of molecules are contained in which compartment of virus, how do they look like, and in which approximate quantity are they present?
	
%since the data is XXX, it is impossible to see YYY
Besides the structural composition of a cell, biologists are often also interested in the cell's molecular composition, i.e., what types of molecules are present in the data, in which compartment are they contained, what do the molecules look like?
The HIV data, for instances, contains 42 different molecules but due to their high count (thousands of molecule instances across these 42 types), their mostly random distribution and the dense packing of the data, the detailed information about the number of types and their individual shape is impossible to deduce from the original data.
Illustrators therefore create atlas based views (such as in Figure \ref{fig:schema}d) that show a simplified schematic representation of a cell to highlight the shapes of different molecules, as well, as the shape and size of the structures that they collectively compose and are contained in. Low level details of the noisy molecule distribution, i.e., the exact count, position and shape of individual molecules are suppressed for this schematic representation.

We achieve such a transition to an atlas based view with our pipeline in the following way:
Similar to the first step in the exploded view use case, we restructure the data with the type range metamorpher to create the relation to the four subsets that represent the compartments of our schematic target representation. Technically, we need each subset twice. Since the four subsets will be blended in image space to create the uniform compartment color, we need a copy of each one for the layouting stage. The \textit{copy} metamorpher creates copies of the supplied subsets, resulting in copies A and B for each subset.

In the morphing stage, we now create the relation of our original noisy data representation to the uniform color that marks each compartment's area by applying a \textit{blur} metamorpher. The blur operator creates an additional render pass for each given subset where the respective subset is rendered and blurred individually. By increasing the contrast of the alpha channel for the blurred image, the sharp edges of each compartment are created.

In the layouting stage, we create the relation of our dense and noisy original data to the sparse enlarged rendering of representative molecules and compartment shells in the final representation.
For a given subset, the \textit{schema} layout metamorpher differentiates between membrane molecule types, i.e., molecules that compose the shell of a compartment, and non-membrane types, i.e., the ones that are floating within a compartment, in order to create the final schematic representation.
Since illustrators know, which molecule types the membranes of compartments are composed of, they can specify the membrane type so that they are treated differently than the molecules within compartments. For membrane molecules, the schema layout metamorpher picks the ones that are closest to the border of the compartment, from the viewing position. The picked membrane molecules remain their original size and rotation. The non-picked membrane molecules are scaled to zero to be invisible in the final representation, in order to reveal the compartments and molecules within. Alternatively, instead of scaling, transparency could be applied to membrane molecules in the morphing stage. For membranes, the schema layout operator thus preserves the membranes shells of compartments while revealing the inner structures of a compartment.

For non-membrane molecules, the illustrator has control over the total count of representatives that 
should be displayed in a compartment. Based on the specified number, the schema layout metamorpher calculates how many representatives of each molecule type of the given subset should be kept. The number of kept representatives depends on the ratio between the total number of molecules of each type within the subset, and the maximum number of allowed representatives.
Each molecule has one guaranteed representative.
Once the number of representatives for each molecule type is calculated, the schema layout metamorpher creates a uniform grid for the available space with as many grid points as there are representatives.
For each grid point, the metamorpher then pics 

to specify a percentage of how much of the available space should be covered with molecule representatives. This percentage is used to 

the schema layout metamorpher calculates a count of how many molecules can be rendered on 
counts the instances of each type within the subset,
calculates a number that represents 


To achieve this schematic representation therefore, on the one side, specific molecules have to be chosen as representatives of their type to be displayed at a sufficiently large scale (focus), while suppressing the noisy distribution of a vast amount of other molecules (context). 

molecules that do not have a noisy distribution but form coherent structures, such as cell membranes, have to be preserved.	


	timing: distance
%%	why is the transition to the view necessary as opposed to just having the final image?
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	



% therefore aims to preserve the size and shape of high level compartments within the data, and
%This representation was motivated by illustrative drawing, like the ones that can be found in medical books.
%\paragraph{simplification (schematization)}:		simplify data to create understanding.

%		resembles the illustrations that we see in biomedical textbooks.
	%	tries to preserve anatomical attributes but in a simplified / schematic way.
		%tries to give overview of elements in  the data and possibly their interrelations.
		
		because this type of automatic illustrative schematization has not been presented/solved yet in literature, we present it as our tertiary contribution...

%how do we present the transition/continuum?


%justification: why was this transition necessary / why is the final image alone not enough?
	
	discussion: 
	@discussion of results: transition = more intuitive to follow.
This metamorphosis corresponds with a transformation within the same visualization space.


	
\subsection{Representation of Quantitative Relations}%[infovis: focus on morphing, camera, trajectory]
For the analysis and explanation of molecular data often also the comparison of quantitative aspects is important for its understanding. %, besides structural information,
Such quantification is necessary, for instance, when analyzing different life cycle stages of a cell.
In our example, we want to convey how many different molecule types the HIV particle contains, and how much of the volume within the particle each type occupies.

The direct comparison of such information on the original 3D models of the cells can deceive due to the complexity of the molecular structures.
Illustrators therefore often supply quantitative information in the form of infographics, which are based in a different visualization space than the original biological data. In this space, spatial dimensions are not used to convey spatial dimensions but rather abstract dimensions, such as atom counts[cite tory/möller?].
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
We chose to convey the quantitative information about the number of molecule types in the HIV particle and the volumetric relation between types with a histogram (Figure \ref{fig:infovis}d). The number of histogram bars corresponds to the number of molecule types. The height of each bar corresponds to the volume that the respective molecule type occupies in the HIV particle.
Since we are concentrating on displaying relations within the HIV particle, we remove the blood serum from our original representation before we restructure our data hierarchy to match the intended target representation.

Since each histogram bar has to represent a single molecule type, we use a \textit{group-by-type} metamorpher to create a subset for each type.

The histograms in the final representation are constructed from the individual molecules in our original data. Each molecule is represented as a slice with given base area and a height that represents the molecule's volume. By stacking the molecule slices, we receive a height that is representative of the total volume of all molecules of the respective type.
In the morphing stage, we therefore apply an \textit{object space} metamorpher on each type subset, in order to morph the shape of each molecule to the afore mentioned slice. The morphing is achieved by repositioning the atoms of a molecule into a slice. The slice height depends on the number of atoms that the molecule is composed of.

In order to layout the created slices into the shape of a bar, we use a \textit{bar layout} metamorpher on each type subset. The bar layout simply stacks the molecule slices in a subset on top of each other. The bars are then positioned side-by-side along a line with a \textit{line layout} metamorpher.




trajectory:
for each molecule
in bar subset, we add a control point to the top of the bar, so that the
molecule seems like falling into the bar instead of going straight from
its original position to the designated position within the bar.


timing

camera




shapes and positions of compartments and molecules are sacrificed. 
%high level shapes (e.g. of compartments or other structures) for low level information (details on the data such as count of instances).
		
@discussion: here, large distance between representation forms in visualization space - a continuous transition is therefore especially suitable for conveying the transition..




