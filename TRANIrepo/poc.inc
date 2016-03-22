\section{Proof Of Concept Implementation}

our PoC implementation allows illustrators to generate illustrative representations of their data, as well as coordinating/authoring the transitions to these altered representations. 

we designed two types of representations and created the components that our pipeline requires to produce them for arbitrary molecular data sets.

the components for each stage can be parametrized and queued based on a simple scripting interface.

we will first discuss the representations that we designed and then go into detail concerning the components that are involved in creating them.

\subsection{Supported Representations}
\subsubsection{Representation of Volumetric Relations}
This representation was inspired by \textbf{[cite graham video (he actually mentioned a video where something like this is happening)]}. XXX created this animation to give a better understanding of what kind of proteins are represented in the different compartments of a cell, as well as how their collective mass relates to each other. 

what is important in these representations (preserve vs sacrifice vs put into the foreground)

\subsubsection{Schematization of Molecular Structures}
This representation was motivated by illustrative drawing, like the ones that can be found in medical/??? books.

\subsection{PoC Pipeline}
[contains specifics about our pipeline implementation]
implemented in cellVIEW: give some details about cellVIEW): unity, supports loading \&rendering of cellPACK data, renders molecules as point clouds
\newline

desc was jeder component beisteuert um die beiden reps zu erzielen

\subsection{PoC components}
[describes PoC components that we implemented per pipeline stage]\newline
[should we describe beforehand what (which representations) we try to achieve with these implementations?]


\subsubsection{Partitioning}



	proof of concept (PoC) operators:
		spatial subselection by clipping plane/object,
		splitting into types,
		spatial splitting operations into equal parts,
		cloning.
	
\subsubsection{Blending / Morphing}
		
	PoC operators:
		unfolding,
		blending into new collective shape
			(schematization background,
			histogram bar),
		morphing
			(simplified shapes (like in GJ video)).
	
\subsubsection{Layouting}

PoC operators:
	
		inner:		
			bar:
				abstract,
			slice:
				abstract,
			sphere:
				abstract
				
		outer:		
			line:
				?,
			circle:
				?,
			explosion:
				occlusion handling,
		schematization layout (inner/outer/both?):
			simplify
			
	
	\subsubsection{Trajectory}
	
	PoC operators:
		linear: from A straight to B,
		curved,
		bundling?,
		motion blur?.
		
\subsubsection{Timing}
PoC: offset function \& staging by type ... anything else?
			
	offset function:
		depending on:
			inherent spatial parameters,
				position, distance to other entities, density, ..,
			external spatial parameters
				(cutting plane/object)
			
\subsubsection{Sampling}

we do continuous sampling


\subsection{different types of transformations/abstractions}		
	depending on what they want to convey, illustrators choose different kinds of abstractions:
	
		\paragraph{derivation (infographic)}:
		transformation to another visualization space.
		tries to convey information that an anatomic representation cannot.
			derive data to convey hidden insights.
		immediate transition = harder to follow.
		sacrifices high level shapes (e.g. of compartments or other structures) for low level information (details on the data such as count of instances).
		insight into hidden relations in the data.
		
			does not care about these aspects in the data (preserve): todo
			
			cares about these aspects in the data (sacrifice): todo
			
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
		
		
		
		
		
		
		
		
		
		
		