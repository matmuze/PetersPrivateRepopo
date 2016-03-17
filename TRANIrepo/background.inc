\section{Overview}
[here we give more detail about the stuff that we couldnt talk about more in the introduction.]

\subsection{animated transitions}
upsides / downsides of animation

\subsection{illustration in molecular visualization}
todo: discuss background of field \& application of illustration (maybe outsource to Graham?)

\subsubsection{molecular/mesoscale data}
	\textbf{todo: }describe cellpack format (outsource)
	
	our data format:
	\begin{itemize}
		\item entity: represents the smallest part of the data. a single molecule. has inherent spatial attributes and optionally also an attribute vector. can be hierarchically grouped to subsets to build a sort of scene graph. has an original position and a target position and optionally control points in between
		\item subset: is a group of entities.	grouped according so specified attributes (spatial, by type, ..)
		\item attributes: spatial (pos, rot, volume/size, shape) for original and target \& optionally intermediate (controlpoints) state
		\item attributes: hierarchical (children, parent)
		\item attributes: data (data, type, shape composed of atoms \& their positions, color, also time curve?)
	\end{itemize}

			
	\textbf{things that should be preserved:} depending on the usecase / representation - not all properties are essential for each representation form.
	\begin{itemize}
		\item instance level: position of instances
		\item type level: shape of types, relative size of types, color of types (?), number relation between types
		\item compartment level: shape/pos/size/color of compartments / structures
		\item global level: volumetric dimensions of the data
		\item todo: what else?
	\end{itemize}
		
		

		

\subsection{our pipeline}
	
		the pipeline contains three high level stages:
		\begin{itemize}
			\item one for the creation of the target representation.
			\item one for the specification of the transition.
			\item and an optional one that supports story telling.
		\end{itemize}
			each stage is composed of multiple lower level stages that define each high level stage.
			
			our PoC implementation allows illustrators to generate illustrative representations by simplifying or transforming their data, as well as coordinating/authoring the transitions to these altered representations - based on a simple scripting interface.
