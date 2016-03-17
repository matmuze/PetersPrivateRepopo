\section{Proof Of Concept Implementation}
\textbf{todo:} discuss PoC components that we implemented per pipeline stage

\subsubsection{different types of transformations/abstractions}		

	depending on what they want to convey, illustrators choose different kinds of abstractions
	derivation (infographic)
		transformation to another visualization space
		tries to convey information that an anatomic representation cannot
			derive data to convey hidden insights
		sacrifices high level shapes (e.g. of compartments or other structures) for low level information (details on the data such as count of instances)
		insight into hidden relations in the data
		todo: flesh out more
			does not care about
			cares about
		immediate transition = harder to follow
	simplification (schematization)
		transformation within the same visualization space
		resembles the illustrations that we see in biomedical textbooks
			simplify data to create understanding
		tries to preserve anatomical attributes but in a simplified / schematic way
			shape/size of compartments
			maybe individual elements
			todo: what else?
		sacrifices low level detail for high level information
		overview of elements in  the data and possibly their interrelations
		todo: flesh out more
			does not care about
			cares about
		immediate transition = more intuitive to follow