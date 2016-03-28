\section{Discussion and Future Work}

\subsection{Expert Feedback}
We demonstrated the three transitions that we discussed in Section \ref{sec:usecase} to two experts in illustration and animation in order to gather their feedback.
Each use case was presented in form a video of the respective animated transition.
We supplied the experts with questionnaires that contained specific questions for each use case. [mention the questions or list a few examples of the questions?]

\subsubsection{Exploded Views}
...waiting for feedback...
\subsubsection{Schematization}
...waiting for feedback...
\subsubsection{Histograms}
...waiting for feedback...





\subsection{Reflections on the Pipeline}

high level tasks:


		
	compatible data types:
		dense hierarchical data with lots of repeating entities  of a few dozen types
		

%not supported:
%-interaction
%-full fledged animation
Since we designed our pipeline to produce visualizations for presentation purposes, we did not build it explicitly with interaction in mind.
It is built to produce static images.
%It does not consider interactions on a conceptual level.
The environment in which we implemented our method, however (cellVIEW), natively supports user interactions as it is based on the Unity3D engine.
The formal pipeline, as well as the implementation could be extended to support user interactions.
Our plan for future work is actually to allow user interactions on the final representation that then creates a partial transition of a selected subset back to the original representation.

Our pipeline is not feature explicit support for 
such as they are featured in full fledged 3D modeling environments that support 
as our focus lies on supporting illustrators 



annotations..


general applicability:
	compatible data formats:
		point cloud,
		volume,
		polygonal?











future work:
authoring tool
extraction of motion for glyphs



\subsection{Discussion of Results}

\subsubsection{shematization}
	discussion: 
	@discussion of results: transition = more intuitive to follow.
This metamorphosis corresponds with a transformation within the same visualization space.

		because this type of automatic illustrative schematization has not been presented/solved yet in literature, we present it as our tertiary contribution...

\subsubsection{infovis}

shapes and positions of compartments and molecules are sacrificed. 
%high level shapes (e.g. of compartments or other structures) for low level information (details on the data such as count of instances).		
@discussion: here, large distance between representation forms in visualization space - a continuous transition is therefore especially suitable for conveying the transition..




	

		
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

		