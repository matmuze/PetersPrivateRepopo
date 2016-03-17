
%% Uncomment below to include a teaser figure.
  \teaser{
 \centering
 \includegraphics[height=6cm]{figures/teaser.png}
  \caption{tease me, then please me}
  }

%% Uncomment below to disable the manuscript note
%\renewcommand{\manuscriptnotetxt}{}

%% Copyright space is enabled by default as required by guidelines.
%% It is disabled by the 'review' option or via the following command:
% \nocopyrightspace

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%% START OF THE PAPER %%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\begin{document}

%% The ``\maketitle'' command must be the first command after the
%% ``\begin{document}'' command. It prepares and prints the title block.

%% the only exception to this rule is the \firstsection command
\firstsection{Introduction}
\maketitle
The traditional approach for the visual communication of scientific insights is handled by illustrators and animators. %(mesoscale - do not mention yet).
Their goal is two-fold: on the one side, they want to attract the interest of broad audiences, on the other side, the want to communicate complex phenomena in an accessible way.
In recent years, we have seen an increase in the communication of complex topics from molecular biology \textbf{cite[drew berry, gj, david bolinsky, Gaël McGill, janett iwasa]}. These authors employed animations to explain phenomena, such as the splitting of DNA, the transport of oxygen in the the blood stream, or the comparison of molecular structures within a cell.
The authors build their visualizations with molecular models, e.g., of a cell, that can consist of millions of atoms that form tens of thousands of molecules. %This data is characterized by high complexity, high density, and therefore also high occlusion.
These molecular models are loaded into the scene of a 3D modeling tool to form the basis of the modeling of the intended knowledge transfer. The communication of quantities or relations, for instance, requires a transformation of the original data to more abstract representations, such as bar charts or line graphs. The presentation and comparison of cellular structures, on the other hand, requires a transformation of the highly complex data to a simplified representation. Unfortunately, these transformations have to be authored and modeled manually within these tools.
%Considering that new discoveries are frequently made, creating new representations and updating existing ones, is a laborous task. %The explanation of sequential processes %, as well as multimodal information for each molecule.
%communicate quantities (e.g., oxigen transport, insulin) => requires different representations (bar chart)
%=> three examples
%complexity of the data: animators can use scripting, toolkits, loading models (at their disposal) - but simulation of this complex environment / complex messages have to be authored manually (no tools for that)
%now concrete examples instead of abstract discussion
%not only molecules
%In both cases, transformations of the original data are involved. A simplification corresponds to the transformation within the same spatial coordinates. A 
%simplification: have to manually author transformation of presented information \& the additional representations

Further, viewers have to grasp these transitions and the relations between the original and the transformed data, for a successful knowledge transfer.
How hard these transitions are to grasp depends, for instance, on how strongly an illustrative representation differs from the original data, how familiar the audience is with the presented data, and how complex the original data is (the number of objects that need to be tracked or related to each other, the amount of occlusion).
Since these visualizations are intended for presentation purposes, which allows little to no interactivity, animation is a suitable medium.

%As the aim of illustrators and animators is primarily presentation, it is often a requirement that their visualizations convey the desired knowledge with limited to no interactivity. 

%presentation => limited to no interactivity => need to convey the relationship => animated transitions

%Illustrators and animators in mesoscale visualization are communication experts, as they try to engage broad audiences for a certain topic. With their animations, they want to convey knowledge about complex phenomena such as biological processes on the molecular level. As such, the illustrations and animations they create are mainly designed for presentation purposes - be it to an audience of laymen in a museum or to peers in a presentation. 
%The molecular data that they present typically consists of millions of atoms that form tens of thousands of molecules of a couple of dozen different types. These molecules form the outer and inner structures of a cell.
%The data is characterized by high complexity, high density, and therefore also high occlusion.
%As such, depending on what information an illustrator wants to convey, special considerations have to be taken into account when visualizing this data.
%An illustrator might want to show hidden structures by simplifying the data in a way that it preserves structures. In another scenario a stronger abstraction might be necessary to convey hidden relations within the data. \textbf{[probably more concrete detail should be given: talk about transition within the same space and across spaces here or later...]}
		
%It can be hard for an audience to grasp, which part of an abstracted representation corresponds to which part of the original representation. % -- this link can be lost in the transition.
%This depends on various factors, i.e., how strongly this illustrative representation differs from the original data, how familiar the audience is with the presented data, and how complex the original data is (the number of objects that need to be tracked  or related to each other, the amount of occlusion).
%The depiction of the transition is therefore necessary to preserve and convey this relation. Illustrators use various means for communicating the correspondences between representations. One, that has gained a lot of popularity recently, are animated transitions. 

%Animated transitions are great for engaging audiences, garnering interest from new audiences.
Besides being engaging, animated transitions have the advantage of being intuitively understandable if well designed - as they display the transition in a continuous way.
Besides their suitability for presentation purposes, animations are often critically regarded by the visualization community. Tversky describes the fleetingness of the displayed information and the potential sensory overload and distracting nature of badly designed animations. %Nevertheless, \textbf{[here we have to disarm these arguments somehow for our scenario]}.
Alternative ways to convey transitions exist but are often not always as suitable for presentation purposes, as we will discuss in Section 2.

We discovered two problems that we feel are worth solving:
\begin{enumerate}
	\item Animations are created and authored manually. Considering that new discoveries are made frequently in molecular biology, animations have to be re-modeled or all together re-created when new insights are found which makes the effort of creating them even higher.
	\item While animation in visualization and animated transitions within the same visualization space have been already addressed in literature cite[heer, tversky], these transitions, while being well established in this branch of visualization, have not been given a formal treatment yet.
\end{enumerate}
	
	We therefore present such a formalism in the form of a conceptual pipeline that describes all the components involved in animated transitions as the main contribution of this paper.	Since the pipeline produces a continuous transition, it also offers the prerequisites for the extraction of other forms of transitions, such as narrative sequences or static images that supplement the missing information of the animation by indicating the transition with glyphs.
	
	As our secondary contribution, we demonstrate a proof-of-concept implementation of this theoretical pipeline based on two(three?) examples that we created in collaboration with illustrators. Finally, we present one of these results, a novel illustrative rendering approach for automatic schematization of mesoscopic data, as our third contribution.

%as our 4th contribution, we present the additional output that our implementation/pipeline supports besides animated transitions: the extraction of narrative sequences \& the creation of static images that supplement the missing information of the animation by indicating the transition with glyphs and annotations
%put after the conceptual framework: the outcome of the pipeline is a continuum that can also be harvested for narrative sequencves & kinky glyph stuff

%They can use motion to show sequence in complex phenomena 

%, as well as high redundancy (need a better word) of the relatively small number of different molecule types. 
%dont fuck with scales


%2: we demonstrate this theoretical pipeline on several exapmples using a proof of concept implem & %shorten % pick most resonating statements
%move stuff to overview

