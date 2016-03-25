\section{Use Cases}
In this section, we will demonstrate our proof of concept implementation based on three exemplary use cases that we developed with illustrators. We will first describe our data set to motivate the components that all three use cases have in common.
After this, we will motivate and describe these use cases, [actually, we already motivated them in the introduction..]
then we will explain,
as well as each use case's particular components and how their application produces these representations.

%our PoC implementation allows illustrators to generate illustrative representations of their data, as well as coordinating/authoring the transitions to these altered representations. 
%we designed two types of representations and created the components that our pipeline requires to produce them for arbitrary molecular data sets.
%we will first discuss the representations that we designed and then go into detail concerning the components that are involved in creating them.
%The components for each stage can be parametrized and queued based on a simple scripting interface.
%\subsection{Use Case Descriptions}

Our use cases are demonstrated on a data set representing an HIV particle engulfed in blood serum. The data consists of 42 types of molecules, that have a total of XXX number of instances, consisting of a total number of YYY atoms. The data can be partitioned into three closed compartments: the blood serum, the outer shell (membrane?) of the HIV particle, and the nucleus within the particle.

Next, we describe the strategies, that we apply on all data sets in our proof-of-concept implementation.
 
\subsection{Common Components}
\subsubsection{Spatial Grouping}
\subsubsection{Grouping by Type}
\subsubsection{Annotations}
\subsubsection{Linear Interpolation}
\subsubsection{Spatial Time Offset}
\subsubsection{Guided Navigation}
\subsubsection{Continuous Sampling}

the special stages concern mostly visual and spatial transformation, as well as trajectory

\subsection{Explosion of Molecular Structures}
Since molecular structures are very densely packed, it is impossible to inspect the outer and inner structures, e.g., of a virus, at the same time, without applying some sort of occlusion handling technique, such as exploded views [cite some fundamental exploded view paper] [kind of have to repeat the argumentation from the introduction here - i guess here i should be more specific..].

\subsubsection{Applied Metamorphers}
--data transform:
1) [type range grouper] create three high lvl subsets: the blood serum, the membrane, the capsid
2) [plane splitter] spatially partiton each subset with the same plane (each one could also be split with a different plane theoretically)

--annotations:
3) text labels: "serum", "capsid", "membrane"

--blending:
no blending applied here

--layouting:
for each high lvl subset:
4) [translate] upper part up, lower part down
5) [rotate] rotate upper part a bit up, lower part a bit down
6) (for all except the first subset)[translate] the subset to the left (double the amount of the previous subset's BB width)
7) position label on top/below each high lvl subset

--trajectory:
8) [linear interpolation]

--timing:
9) introduce a [delay] for each consecutive layout operation (translate sideways of highlvl subsets \& translate up/down for low lvl subsets)
10) [] let some random molecules not finish the transition
11) [] let labels appear after animation is finished

--navigation:
12) guided navi as subset explosion \& transition use more and more screenspace

--sampling:
13) continuous sampling



\subsection{Schematization of Molecular Structures}
This representation was motivated by illustrative drawing, like the ones that can be found in medical/??? books.

\paragraph{simplification (schematization)}:
		simplify data to create understanding.
		transformation within the same visualization space.
		resembles the illustrations that we see in biomedical textbooks.
		immediate transition = more intuitive to follow.
		tries to preserve anatomical attributes but in a simplified / schematic way.
		tries to give overview of elements in  the data and possibly their interrelations.
		
		preserves:	shape/size of compartments,
			maybe individual elements
			
		sacrifices: low level detail for high level information
	
\subsubsection{Applied Metamorphers}
--data transform:
1) [type range grouper] create three high lvl subsets: the blood serum, the membrane, the capsid
2) [copy] the entire partitioned data set because we will render it in two different representations => results in copy A \& B

--annotations:
do the circular annotations?

--visual transform:
A: blurrin \& increasin contrast of alpha channel for nice charp edges of each subset individually
B: scalin

--layouting (spatial transform):
A: renderin them on top of each other (occlusion management)
B: rotatin

--navigation:
not necessary, because we stay in the same visualization space / spatial extents

--trajectory:
B: linear interpolation between rotations

--timing:
staged per compartment
distance field left to right for each

--sampling:
continuous


\subsection{Representation of Volumetric Relations}
This representation was inspired by \textbf{[cite graham video (he actually mentioned a video where something like this is happening)]}. XXX created this animation to give a better understanding of what kind of proteins are represented in the different compartments of a cell, as well as how their collective mass relates to each other. 

what is important in these representations (preserve vs sacrifice vs put into the foreground)

		\paragraph{derivation (infographic)}:
		transformation to another visualization space.
		tries to convey information that an anatomic representation cannot.
			derive data to convey hidden insights.
		immediate transition = harder to follow.
		sacrifices high level shapes (e.g. of compartments or other structures) for low level information (details on the data such as count of instances).
		insight into hidden relations in the data.
		
			does not care about these aspects in the data (preserve): todo
			
			cares about these aspects in the data (sacrifice): todo
			

\subsubsection{Applied Metamorphers}
--data transform:
1) [type range grouper] create 3 hierarchical compartments by typerange
2) [single type grouper] split all three by type => subsets containing all molecules of same type for each hierarchical compartment

--annotations:
3) [txt-label] for each type subset
10) [representative] molecule for type subset

--blending:
4) [slice-flatterer] create target rep for each molecule with blending: slice with hight representing the molecule volume

--layouting:
5) [bar layout] for each type compartment - the layout puts all molecule slices on top of each other to create histogram bars
6) the [line layout] puts all the bars within a compartment side by side
7) the [translate layout] then moves the new center for the next line layout for the next compartment

8) layout: put label below below each bar
9) layout: put rep below label

--trajectory:
10) [top-down-fall-in-component]: for each molecule in bar subset, we add a control point to the top of the bar, so that the molecule seems like falling into the bar instead of going straight from its original position to the designated position within the bar.

--timing:
11) [distance offset] a plane can be positioned in space. the distance of each molecule/compartment to this plane is measured and used for a the creation of a time offset that specified when each molecule is allowed to start its transition

12) timing: make label \& rep appear when animation is finished

--guided navi:
13) [whole-data-in-view-keeper] update the camera pos \& lookat to keep all molecules in the view frustum.

--sampling:
14) continuous sampling

\subsection{PoC Pipeline}
[contains specifics about our pipeline implementation]
implemented in cellVIEW: give some details about cellVIEW): unity, supports loading \&rendering of cellPACK data, renders molecules as point clouds
\newline

desc was jeder component beisteuert um die beiden reps zu erzielen

\subsection{Metamorphers}
[describes PoC components that we implemented per pipeline stage]\newline
[should we describe beforehand what (which representations) we try to achieve with these implementations?]


\subsubsection{Partitioning}
		spatial subselection by clipping plane/object,
		
		splitting into types,
		
		splitting into type ranges
		
		cloning
		
		---not showcased but implemented:		
		*spatial splitting operations into equal parts (pie splitter),
	
\subsubsection{Annotations}
text labels,
icons (textures),
maybe: data representatives (for each type),
optional addon to each operator: connectors between annotation \& assigned subset

\subsubsection{Blending / Morphing}
		
		blur into collective shape,		
		morph,
		
		---not showcased but implemented:				
		blending to texture
		
		---other not implemented \& not used examples:
		unfolding
		
\subsubsection{Layouting}

bar,
line,
translate,
rotate,
scale,
schematization layout = combi of scale \& rotate but selection of elements where what op is applied is very specific

---not showcased but implemented:	
			slice,
			sphere,
			circle

\subsubsection{Camera / Guided Navi}
[whole-data-in-view-keeper] update the camera pos \& lookat to keep all molecules in the view frustum.

other examples:


\subsubsection{Trajectory}
	
		linear: from A straight to B,
		bundling/transit points
		
		---other not implemented \& not used examples:
		curved
		
\subsubsection{Timing}

offset function: delay timing by distance to plane
 \& staging by type ... anything else?
			
		---other not implemented \& not used examples:
	offset according to: inherent spatial parameters (position, distance to other entities, density)
			
\subsubsection{Sampling}

continuous sampling,

		---other not implemented \& not used examples:
sparse (comic strip / narrative sequence),

post-processing operators:
motion blur,
		