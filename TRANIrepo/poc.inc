\section{Proof Of Concept Implementation}

our PoC implementation allows illustrators to generate illustrative representations of their data, as well as coordinating/authoring the transitions to these altered representations. 

we designed two types of representations and created the components that our pipeline requires to produce them for arbitrary molecular data sets.

the components for each stage can be parametrized and queued based on a simple scripting interface.

we will first discuss the representations that we designed and then go into detail concerning the components that are involved in creating them.


\subsection{Supported Representations}

\subsubsection{Explosion of Molecular Structures}


\subsubsection{Schematization of Molecular Structures}
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
	

\subsubsection{Representation of Volumetric Relations}
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
			



\subsection{PoC Pipeline}
[contains specifics about our pipeline implementation]
implemented in cellVIEW: give some details about cellVIEW): unity, supports loading \&rendering of cellPACK data, renders molecules as point clouds
\newline

desc was jeder component beisteuert um die beiden reps zu erzielen

\subsection{PoC components}
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
		