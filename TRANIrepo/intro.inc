
%% Uncomment below to include a teaser figure.
  \teaser{
 \centering

\subfloat[]{\label{fig:t0}\includegraphics[width=0.25\linewidth]{figures/t0.png}}
\subfloat[]{\label{fig:t1}\includegraphics[width=0.25\linewidth]{figures/t1.png}}
\subfloat[]{\label{fig:t2}\includegraphics[width=0.25\linewidth]{figures/t2.png}}
\subfloat[]{\label{fig:t3}\includegraphics[width=0.25\linewidth]{figures/t3.png}}
 
  \caption{\label{fig:teaser}Metamorphosis to a schematic representation of an HIV particle in blood serum. Protein types are shown in a reduced quantity that represents their number within a compartment. Each representative is enlarged for better readability of its atomic composition.}
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
\firstsection{Introduction}\label{sec:intro}
\maketitle
The traditional approach for the visual communication of scientific insights is handled by illustrators and animators.
Their goal is to convey complex phenomena in an accessible way, and to attract the interest of broad audiences.
In recent years, we have seen a rapid increase in the communication of topics from molecular biology (e.g., work of Drew Berry, Graham Johnson, David Bolinsky, Ga\"el McGill, Janett Iwasa), such as the splitting of DNA, the transport of oxygen in the the blood stream, or the comparison of molecular structures within a cell. %we dont mention animations yet
Such animations are used in teaching undergraduate level biology worldwide.

%[what does an illustrator want to convey? - concrete examples]
When illustrators want to convey, for instance, the inner and outer structures of a cell, they face the challenge that the structures of their data are very densely packed. The dense data makes it very difficult to convey inner and outer structures at the same time. Therefore they employ means for occlusion handling, such as exploded views, in order to make all important aspects of the data visible.
Illustrators often want to convey the entire variety of different molecules within a cell in form of an atlas-based view. However, a cell contains in reality many thousand instances of the same molecular structures. To achieve such an atlas based view, an illustrator does not want to display every single molecule but would rather draw various structures at sufficiently large scale so that the viewer can understand the structural details.
In these examples, the illustrator represents abstracted spatial information within the same spatial frame of reference. We denote this as a transformation \textit{within} the same visualization space (Fig. 2a).
In other cases, illustrators want to convey quantitative instead of spatial information, e.g., how many different molecules of each type a biological entity contains, or how a functional relationship between these molecules would look like.
In the former case, a bar chart could be used as representation of the quantities. A node-link diagram could be chosen in the latter case to convey the relationships. 
In such cases, the illustrator would abstract the biological structure from a spatial representation to a quantitative or relational one, which we denote as a transformation \textit{across} visualization spaces (Fig. 2b).

\begin{figure}[ht!]
\centering
\subfloat[]{\label{fig:spaces0}\includegraphics[width=\linewidth]{figures/small-spaces0.png}}

\subfloat[]{\label{fig:spaces1}\includegraphics[width=\linewidth]{figures/small-spaces1.png}}
\caption{\label{fig:spaces}(a) Examples of transitions within the same visualization space and (b) across different visualization spaces (video by Graham Johnson).}
\end{figure}
%[general conclusion of what he wants to convey]
%Illustrators have access to different narrative elements that can be combined with each other in order to convey their stories.
%The element of temporal sequence is used to convey changes of data states over time.
%The element of visual transformation creates different representations of the data in order to convey otherwise hidden aspects.

For biological entities, a "canonical" representation, especially for non-experts, is the one closest to their mental model that is formed by images from photography, microscopy, and crystallography.
%A viewer's mental model of a biological entity is formed by images from photography, microscopy,... - 
The mental model is therefore anchored within the same visualization space as the actual biological entity. %To comprehend another (transformed) representation form, a viewer needs guidance on how to relate their mental model to this transformed representation. %the mental model is typically also an abstraction as human vision/perception system tends to abstract what it sees.
If no obvious relation between a mental model and a particular representation exists, the viewer needs guidance on how to relate their mental model to this transformed representation, in order to comprehend the other (transformed) representation form.

In scenarios where interaction is possible or desired, e.g., in an interactive analysis scenario, approaches such as coordinated multiple view (CMV) visualizations can be used for conveying the relations between two representations, e.g., via brushing and linking.

In cases, where interaction is not feasible or very limited, such as in presentation scenarios, this guidance is often realized by depicting a transition from a representation A to a representation B, e.g., in the form of static sequence of small multiples, or an animated transition.
We denote such a transition as a metamorphosis and the individual building blocks of the metamorphosis as metamorphers.



%For a successful knowledge transfer, viewers have to understand the relations between the original and the transformed data.
%How hard these relations are to grasp depends on how strongly an illustrative representation differs from the original data, how familiar the audience is with the presented data, and how complex the original data is (the number of objects that need to be related to each other, the amount of occlusion).
%It is therefore helpful for the user's understanding, to convey the transition, or \emph{metamorphosis}, from one representation state to the other.

%These animations typically are used to display two types of continuous sequences: sequences of temporal events, and transitions to other data representations. In this paper, we deal with the second type of these sequences. 
%Illustrators use transitions to convey, how different representations of the same data, as well as, the same representations of different data, relate to each other.



Animations are a powerful tool for conveying these metamorphoses, since they are capable of displaying such a transition between two representations in a continuous way.
The continuous presentation supports an intuitive understanding of the relationship between representation states. The presentation is both self-explanatory, and enjoyable to audiences \cite{Robertson:TVCG:2008}.
Despite their immense popularity in the visual communication crafts, animations are also regarded critically by the visualization community. Tversky \cite{Tversky:IJHCS:2002} describes the fleetingness of the displayed information and the potential sensory overload and distracting nature of badly designed animations. 

Alternative solutions for conveying transitions alleviate the fleetingness of the displayed information by sacrificing the continuous aspect of the representation. Examples are narrative sequences of small multiples or static images that supplement the missing information of the continuity with glyphs.
While solving the problem of fleetingness, they have to be well designed to be understandable.

%Animations, narrative sequences, and static images are most suited for circumstances where little to no interaction is possible or desired, such as in presentation scenarios.
%Since these visualizations are intended for presentation purposes, which allows little to no interactivity, animation is a suitable medium.
%Animated transitions are great for engaging audiences, garnering interest from new audiences.


Once a transition from one representation to another one is planned, there is little aid in modeling tools to realize it. Animators employ key frame animation and create these keyframes manually
%However, no matter which medium is used for the illustrative depiction of these stories, these transformed representations and the transitions to them have to be modeled manually by the illustrators
which is a laborious and time-consuming task.
%The authors build their visualizations with complex molecular models, e.g., of a cell, consisting of millions of atoms that form tens of thousands of molecules, that are loaded into the scene of a 3D modeling tool. 
Considering that new discoveries are made frequently in molecular biology, these representations and their transitions have to be re-modeled when new insights are found, which makes the effort for maintaining them even higher.	

%	\item While animation in visualization and simple transitions in information visualization have been already addressed in literature cite[heer, tversky], narrative animations in molecular biology, while being well established in this branch of visualization, have not been formally described yet.\end{enumerate}

We therefore set our goal to assist illustrators by eliminating the need to manually author their target representations and the transitions in between.
We supply illustrators with a pipeline for creating continuous target representation as well presenting the transitions to them.

Our main contribution is a formalization of a uniform method for creating continuous target representations for spatial biological data sets, as well as presenting the transitions to these representations - describing the complete metamorphosis of the data representation, so to say.

Data representations are specified in such a way that they form a continuous space.
The first three stages of the pipeline are responsible for creating this continuum. The final four stages of the pipeline are responsible for presenting the continuum.
This continuum can be arbitrarily sampled in order to create a transition between two representations, e.g., densely, in the form of animation, or sparsely, in the form of small multiples.
%The method is described by a pipeline that consists of eight stages that can be grouped by their high-level functionality: target state representation, transition definition, and story helpers.
Each stage supports operators, so called metamorphers, that are responsible for one aspect of the metamorphosis.

Further, we demonstrate an exemplification of this pipeline with an extendable API by showcasing three use cases that we developed and evaluated in collaboration with an illustrator, one of them is 
a novel illustrative rendering approach for automatic schematization of mesoscopic data.
. %One of these results, a novel illustrative rendering approach for automatic schematization of mesoscopic data, is our third and final contribution.

