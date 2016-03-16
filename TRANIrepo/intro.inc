
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
In recent years, we have seen an increase in the communication of complex topics from molecular biology \textbf{cite[drew berry, gj, david bolinsky, Gaël McGill, janett iwasa]}. These animations explain phenomena, such as the splitting of DNA, the transport of oxygen in the the blood stream, or the comparison of molecular structures within a cell.
The authors build their visualizations with molecular models, e.g., of a cell, that can consist of millions of atoms that form tens of thousands of molecules of a couple of dozen different types. This data is characterized by high complexity, high density, and therefore also high occlusion. These molecular models are loaded into the scene of a 3D modeling tool to form the basis of the intended knowledge transfer. However, the knowledge that the authors want to convey, has to be authored and modeled manually within these tools. The communication of quantities or relations, for instance, requires additional representations, such as a bar chart or a line graph. The presentation and comparison of cellular structures, on the other hand, requires a simplification of the highly complex data. %The explanation of sequential processes %, as well as multimodal information for each molecule.
%communicate quantities (e.g., oxigen transport, insulin) => requires different representations (bar chart)
%=> three examples
%complexity of the data: animators can use scripting, toolkits, loading models (at their disposal) - but simulation of this complex environment / complex messages have to be authored manually (no tools for that)
%now concrete examples instead of abstract discussion
%not only molecules
simplification: have to manually author transformation of presented information \& the additional representations
viewers have to grasp these transformations and the relations between original and abstracted data
since presentation is goal, the representations should convey this knowledge / the transformation with little to no interactivity
this is why animation is a favored tool for conveying these transitions.

%As the aim of illustrators and animators is primarily presentation, it is often a requirement that their visualizations convey the desired knowledge with limited to no interactivity. 

%presentation => limited to no interactivity => need to convey the relationship => animated transitions

%Illustrators and animators in mesoscale visualization are communication experts, as they try to engage broad audiences for a certain topic. With their animations, they want to convey knowledge about complex phenomena such as biological processes on the molecular level. As such, the illustrations and animations they create are mainly designed for presentation purposes - be it to an audience of laymen in a museum or to peers in a presentation. 
%The molecular data that they present typically consists of millions of atoms that form tens of thousands of molecules of a couple of dozen different types. These molecules form the outer and inner structures of a cell.
%The data is characterized by high complexity, high density, and therefore also high occlusion.
%As such, depending on what information an illustrator wants to convey, special considerations have to be taken into account when visualizing this data.
%An illustrator might want to show hidden structures by simplifying the data in a way that it preserves structures. In another scenario a stronger abstraction might be necessary to convey hidden relations within the data. \textbf{[probably more concrete detail should be given: talk about transition within the same space and across spaces here or later...]}

raw text:
different types of conveying transformations/abstractions:
	A) derivation (infographic): transformation to another visualization space.	tries to convey information that an anatomic representation cannot. derive data to convey hidden insights
		sacrifices high level shapes (e.g. of compartments or other structures) for low level information (details on the data such as count of instances)
		insight into hidden relations in the data
		todo: flesh out more
			does not care about
			cares about
		immediate transition = harder to follow
	simplification (schematization)
		transformation within the same visualization space
		tries to preserve anatomical attributes but in a simplified / schematic way
			resembles the illustrations that we see in biomedical textbooks
				simplify data to create understanding
			shape/size of compartments
			maybe individual elements
			sacrifices low level detail for high level information
			todo: what else?
		overview of elements in  the data and possibly their interrelations
		todo: flesh out more
			does not care about
			cares about
		immediate transition = more intuitive to follow
		
		
%It can be hard for an audience to grasp, which part of an abstracted representation corresponds to which part of the original representation. % -- this link can be lost in the transition.
This depends on various factors, i.e., how strongly this illustrative representation differs from the original data, how familiar the audience is with the presented data, and how complex the original data is (the number of objects that need to be tracked  or related to each other, the amount of occlusion).
The depiction of the transition is therefore necessary to preserve and convey this relation. Illustrators use various means for communicating the correspondences between representations. One, that has gained a lot of popularity recently, are animated transitions. 

Animated transitions are great for engaging audiences, garnering interest from new audiences. They are intuitively understandable if well designed - as they display the transition in a continuous way. Besides their popularity with general audiences, animations are often critically regarded by the visualization community... Tversky describes the fleetingness of the displayed information and the potential sensory overload and distracting nature of badly designed animations. \textbf{[here we have to disarm these arguments somehow for our scenario]}. Nevertheless, their success with biologist audiences, as well as \textbf{[....]}, speaks for them.
Alternative ways to convey transitions \textbf{[exist but are often not suitable for what illustrators want to achieve]}, we will discuss them in Section 2.

in this context, we discovered two problems that we feel are worth solving:
	1) these animations are created manually in modeling tools such as maya which is a laborious task on its own.
		considering that molecular biology is a very thriving/growing field where new discoveries are made frequently these animations have to be re-modeled when new insights are found		which makes the effort of creating them even higher.
	2) while animation in general and animated transitions within the same visualization space have been already discussed, and are not very present in today's world of scientific visualization, this form of representation is well established in this branch of visualization, but has not been given a formal treatment yet.
	
	we therefore present such a formalism in the form of a conceptual pipeline that describes all the components involved in such transitions [1st contribution]
	
	further, we present an implementation of this pipeline  [2nd contribution] with a discussion of our proof-of-concept components for each stage. 
	the pipeline allows illustrators to generate illustrative representations by simplifying or transforming their data, as well as coordinating/authoring the transitions to these altered representations - based on a simple scripting interface.
	
		the pipeline contains three high level stages:
			1) one for the creation of the target representation.
			2) one for the specification of the transition.
			3) and an optional one that supports story telling.
			each composed of  multiple lower level stages that define each high level stage
			
	 to showcase our pipeline/implementation, we created different proof-of-concept representations for a mesoscopic data set - in collaboration with illustrators.
	 we demonstrate two results that can be achieved with simple scripting of commands that are fed into the pipeline.
	one of these results is our third contribution: a novel illustrative rendering approach for automatic schematization of mesoscopic data.

as our 4th contribution, we present the additional output that our implementation/pipeline supports besides animated transitions: the extraction of narrative sequences \& the creation of static images that supplement the missing information of the animation by indicating the transition with glyphs and annotations
%put after the conceptual framework: the outcome of the pipeline is a continuum that can also be harvested for narrative sequencves & kinky glyph stuff

%They can use motion to show sequence in complex phenomena 

%, as well as high redundancy (need a better word) of the relatively small number of different molecule types. 
%dont fuck with scales


%2: we demonstrate this theoretical pipeline on several exapmples using a proof of concept implem & %shorten % pick most resonating statements
%move stuff to overview

