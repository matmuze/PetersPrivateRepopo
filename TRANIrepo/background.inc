\section{Background}
[here we give more detail about the stuff that we couldnt talk about in more detail in the introduction \&\& that is \textbf{background information} essential for understanding/following the rest of the paper.]

\subsection{animated transitions in molecular biology}
for what kind of knowledge transfer are they used (examples)?
why are they essential?

%\subsection{illustration in molecular visualization}
%todo: discuss background of field \& application of illustration
\textbf{(todo: outsource to Graham)}
basically ask him to tell us in his words (justify \& motivate), why animations such as in his award winning video are such a great tool for communication scientific insights. (doesnt matter if its verbose, we can shorten it.)

and also ask him to write a bit about the background of his field. what his tasks as illustrator \& animator are, who are his customers / users, where does he get his data from, what does the data look like, what do his users/customers want to see?

\subsubsection{molecular/mesoscale data}
	\textbf{todo: }describe cellpack format (outsource to mathieu)
	
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
		
		


