
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
The traditional approach for the visual communication of scientific insights is handled by illustrators and animators.
Their goal is to convey complex phenomena in an accessible way, and to attract the interest of broad audiences.
In recent years, we have seen a rapid increase in the communication of topics from molecular biology \textbf{cite[drew berry, gj, david bolinsky, Gaël McGill, janett iwasa]}, such as the splitting of DNA, the transport of oxygen in the the blood stream, or the comparison of molecular structures within a cell. %we dont mention animations yet
Such animations are used in teaching undergraduate level biology worldwide.

%[what does an illustrator want to convey? - concrete examples]
When illustrators want to convey, for instance, the inner and outer structures of a cell, they face the challenge that the structures of their data are very densely packed. The dense data makes it very difficult to convey inner and outer structures at the same time. Therefore they employ means for occlusion handling, such as exploded views, in order to make all important aspects of the data visible.
Illustrators often want to convey the entire variety of different molecules within a cell in form of an atlas-based view [cite some atlas]. However, a cell contains in reality many thousand instances of the same molecular structures. To achieve such an atlas based view, an illustrator does not want to display every single molecule but would rather draw various structures at sufficiently large scale so that the viewer can understand the structural details.
In these examples, the illustrator represents abstracted spatial information within same spatial frame of reference. We denote this as a transformation \textit{within} the same visualization space.
In other cases, illustrators want to convey quantitative instead of spatial information, e.g., how many different molecules of each type a biological entity contains, or how a functional relationship between these molecules would look like.
In the former case, a bar chart could be used as representation of the quantities. A node-link diagram could be chosen in the latter case to convey the relationships. 
In such cases, the illustrator would abstract the biological structure from a spatial representation to a quantitative or relational one, which we denote as a transformation \textit{across} visualization spaces.

%Illustrator abstracts the reality, in the previous examples, within the same visualization space. However, they could decide

%Visual transformation is necessary, because the molecular data data is complex. [explain complex data here or within the following examples?]%in the highly complex data that consists 
%Illustrators employ occlusion handling techniques, such as exploded views, to reveal the inner structures of a dense cellular data set.
%They employ focus \& context techniques, such as the simplification of unimportant details of millions of atoms, in order to enable the presentation and comparison of cellular structures.
%While these two examples correspond to a transformation within the same visualization space, the depiction of abstract quantities or relationships, e.g., by bar charts or line graphs, correspond to the transformation to a different visualization space altogether. 

[general conclusion of what he wants to convey]
Illustrators have access to different narrative elements that can be combined with each other in order to convey their stories.
The element of temporal sequence is used to convey changes of data states over time.
The element of visual transformation creates different representations of the data in order to convey otherwise hidden aspects.

%transformations across visualization spaces. %also across different data spaces? (either temporal or multiple data sets)


%In all cases, the original representation has to be transformed, in one case, within the same visualization space, and in the other to a different visualization space. 


For a successful knowledge transfer, viewers have to understand the relations between the original and the transformed data.
How hard these relations are to grasp depends on how strongly an illustrative representation differs from the original data, how familiar the audience is with the presented data, and how complex the original data is (the number of objects that need to be related to each other, the amount of occlusion).
It is therefore helpful for the user's understanding, to convey the transition, or \emph{metamorphosis}, from one representation state to the other.

%These animations typically are used to display two types of continuous sequences: sequences of temporal events, and transitions to other data representations. In this paper, we deal with the second type of these sequences. 
%Illustrators use transitions to convey, how different representations of the same data, as well as, the same representations of different data, relate to each other. 


Animations are a powerful tool for conveying these metamorphoses, since they are capable of displaying them in a continuous way.
The continuous presentation supports an intuitive understanding of the relationship between representation states. The presentation is self-explanatory and enjoyable to audiences \cite{Robertson:TVCG:2008}.
Still, animations are also critically regarded by the visualization community. Tversky describes the fleetingness of the displayed information and the potential sensory overload and distracting nature of badly designed animations. 

Alternative solutions for conveying transitions alleviate the fleetingness of the displayed information by sacrificing the continuous aspect of the representation. Examples are narrative sequences of small multiples or static images that supplement the missing information of the continuity with glyphs.
While solving the problem of fleetingness, they have to be well designed to be understandable.

These approaches are most suited for circumstances where little to no interaction is possible or desired, such as in presentation scenarios.
In scenarios where interaction is possible or desired, other approaches, such as coordinated multiple view (CMV) visualizations can be used.

%Since these visualizations are intended for presentation purposes, which allows little to no interactivity, animation is a suitable medium.
%Animated transitions are great for engaging audiences, garnering interest from new audiences.

However, no matter which medium is used for the illustrative depiction of these stories, these transformed representations and the transitions to them have to be modeled manually by the illustrators which is a laborious and time-consuming task.
The authors build their visualizations with complex molecular models, e.g., of a cell, consisting of millions of atoms that form tens of thousands of molecules, that are loaded into the scene of a 3D modeling tool. 
Considering that new discoveries are made frequently in molecular biology, these representations and their transitions have to be re-modeled when new insights are found, which makes the effort for maintaining them even higher.	

%	\item While animation in visualization and simple transitions in information visualization have been already addressed in literature cite[heer, tversky], narrative animations in molecular biology, while being well established in this branch of visualization, have not been formally described yet.\end{enumerate}

We therefore want to assist illustrators by presenting our primary contribution: a formal description of a uniform method for creating target representations for spatial biological data sets, as well as the continuous transitions to these representations - describing the complete metamorphosis of the data representation, so to say.

%This metamorphosis is created by an eight stage pipeline.
The output of this method is a continuous space between two representation states.
This space can be arbitrarily sampled to create a transition between these representations, e.g., continuously, in the form of an animation, or sparsely, in the form of small multiples.

The method is described by a pipeline that consists of eight stages that can be grouped by their high-level functionality: target state representation, transition definition, and story helpers.
Each stage supports operators, so called metamorphers, that are responsible for one aspect of the metamorphosis.

As our secondary contribution, we demonstrate a proof-of-concept implementation of this pipeline based on three use cases that we developed in collaboration with illustrators. One of these results, a novel illustrative rendering approach for automatic schematization of mesoscopic data, is our third and final contribution.

