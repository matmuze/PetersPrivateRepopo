
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
These molecular models are loaded into the scene of a 3D modeling tool to form the basis for the modeling of the intended knowledge transfer. The communication of quantities or relations, for instance, requires an abstract representation of the molecular data, e.g., by bar charts or line graphs. The presentation and comparison of cellular structures, on the other hand, requires a simplification of the highly complex data. In both cases, the original data has to be transformed, i.e., within the same (simplification) or to a different (abstraction) visualization space. Unfortunately, these transformations have to be authored and modeled manually within these tools.
%Considering that new discoveries are frequently made, creating new representations and updating existing ones, is a laborous task. %The explanation of sequential processes %, as well as multimodal information for each molecule.
%communicate quantities (e.g., oxigen transport, insulin) => requires different representations (bar chart)
%=> three examples
%complexity of the data: animators can use scripting, toolkits, loading models (at their disposal) - but simulation of this complex environment / complex messages have to be authored manually (no tools for that)
%now concrete examples instead of abstract discussion
%not only molecules
%In both cases, transformations of the original data are involved. A simplification corresponds to the transformation within the same spatial coordinates. A 
%simplification: have to manually author transformation of presented information \& the additional representations

Viewers have to understand these transformations and the relations between the original and the transformed data, for a successful knowledge transfer.
How hard these transformations are to grasp depends, for instance, on how strongly an illustrative representation differs from the original data, how familiar the audience is with the presented data, and how complex the original data is (the number of objects that need to be related to each other, the amount of occlusion).
It is therefore helpful for the user's understanding, to convey the transition from one representation state to the other. Since animations are capable of displaying transitions in a continuous way, they are especially suitable in supporting the viewer's understanding.

%downsides >> alternatives >> but alt less suitable (interaction/presentation)

%Besides their suitability for presentation purposes,
Still, animations are often critically regarded by the visualization community. Tversky describes the fleetingness of the displayed information and the potential sensory overload and distracting nature of badly designed animations. %Nevertheless, \textbf{[here we have to disarm these arguments somehow for our scenario]}.

%illustrators can not rely on interactivity and has to be engaging

However, alternative ways to convey transitions, such as narrative sequences of small multiples or static images that supplement the missing information of the animation by indicating the transition with glyphs.%that encode the transition with glyphs, might not alleviate all downsides of animation. 
While solving the problem of fleetingness, they have to be well designed, as well, to be understandable. Other approaches, such as coordinated multiple view (CMV) visualizations, might not deliver on the requirements for an engaging presentation scenario, as they rely on user interaction.

Animations are therefore often the weapon of choice for illustrators when they intend to engage broad audiences.

%might not alleviate the downsides of animation
%might not deliver the requirements for the presentation scenario

%no continuous transition - missing information
%not as engaging
%might require interaction
%also have to be well designed (manually) to convey the transition

%However, considering that the work of illustrators is mainly used for presentation purposes

%As the aim of illustrators and animators is primarily presentation, it is often a requirement that their visualizations convey the desired knowledge with limited to no interactivity. 

%presentation => limited to no interactivity => need to convey the relationship => animated transitions


%, they are a favored choice by illustrators when it comes to engage large audiences.
%Since these visualizations are intended for presentation purposes, which allows little to no interactivity, animation is a suitable medium.

%Animated transitions are great for engaging audiences, garnering interest from new audiences.
%Besides being engaging, animated transitions have the advantage of being intuitively understandable if well designed - as they display the transition in a continuous way.


In trying to support their mission, we discovered two problems that we feel are worth solving in the context of scientific visualization:
\begin{enumerate}
	\item Animations are created and authored manually. Considering that new discoveries are made frequently in molecular biology, animations have to be re-modeled or all together re-created when new insights are found which makes the effort of creating them even higher.
	\item While animation in visualization and simple transitions in information visualization have been already addressed in literature cite[heer, tversky], narrative animations in molecular biology, while being well established in this branch of visualization, have not been formally described yet.
\end{enumerate}
	
	We therefore present such a formalism as the main contribution of this paper. We describe a conceptual pipeline based all components that are involved when creating animated transitions. Since this pipeline produces a continuous transition, it also offers the prerequisites for the extraction of other forms of transitions, such as narrative sequences or static images with glyphs. %that supplement the missing information of the animation by indicating the transition with glyphs.
	
	As our secondary contribution, we demonstrate a proof-of-concept implementation of this theoretical pipeline based on two(three?) examples that we created in collaboration with illustrators. Finally, we present one of these results, a novel illustrative rendering approach for automatic schematization of mesoscopic data, as our third contribution.

%as our 4th contribution, we present the additional output that our implementation/pipeline supports besides animated transitions: the extraction of narrative sequences \& the creation of static images that supplement the missing information of the animation by indicating the transition with glyphs and annotations
%put after the conceptual framework: the outcome of the pipeline is a continuum that can also be harvested for narrative sequencves & kinky glyph stuff

%They can use motion to show sequence in complex phenomena 

%, as well as high redundancy (need a better word) of the relatively small number of different molecule types. 
%dont fuck with scales


%2: we demonstrate this theoretical pipeline on several exapmples using a proof of concept implem & %shorten % pick most resonating statements
%move stuff to overview

