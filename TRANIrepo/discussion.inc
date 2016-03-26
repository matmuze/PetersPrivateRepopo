\section{Discussion}


\subsection{Discussion of Results}

\subsection{Expert Feedback}


	
\subsection{General Applicability of Our Approach}
	compatible data formats:
		point cloud,
		volume,
		polygonal?
		
	compatible data types:
		dense hierarchical data with lots of repeating entities  of a few dozen types
		
\subsection{general discussion}
\subsubsection{additional outcomes}
	side products of our pipeline - free of charge / easily achievable with minimal additional effort:
	sequence: comic strips,
	static image with glyph
	
\subsubsection{animation}
tversky:
	congruence principle:
		the structure and content of an external representation should match the structure and content of the desired mental representation.
		
	apprehension principle:
		the structure and content of the external representation should be readily and accurately perceived and comprehended.
		
		\subsubsection{things that should be preserved:} depending on the usecase / representation - not all properties are essential for each representation form.
	\begin{itemize}
		\item instance level: position of instances
		\item type level: shape of types, relative size of types, color of types (?), number relation between types
		\item compartment level: shape/pos/size/color of compartments / structures
		\item global level: volumetric dimensions of the data
		\item todo: what else?
	\end{itemize}
		
\subsection{occlusion}

	is of course a central factor that could hinder a user's understanding of a transition.
	can be dealt with at various stages of the pipeline.
		grouping: choose groups so that they dont interfere with each other (depending on how you plan to transform the data)
			TODO: come up with examples that describe which kind of grouping would be beneficial for which kind of target state
				e.g., group the data first into layers parallel to the viewing plane that basically peel the data
		layouts
			inner
				bar: within the bar occlusion does not matter, as long as the bar represents entities of the exact same type
				todo: other inner layouts \& general
			outer
				general: the placement of entities/subests should be chosen so that they dont occlude each other from the viewing angle. 
			maybe we should not distinguish between inner and outer layout since this kind of restricts us to having two layouts instead of n.

then again, we could argue that there can be n-outer layouts, and one inner layout
		morphing:
			same as inner layout: within the shape occlusion is not an issue
			
		trajectory:
			the trajectories offer two of techniques for avoiding occlusion.
			
				edge bundling:
				setting control points so that paths don't occlude each other
				todo: anything else?
				
		timing:
			coordination of timing and speed of elements, e.g., staging

		