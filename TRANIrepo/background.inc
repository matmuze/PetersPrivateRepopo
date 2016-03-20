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


		to convey their message, illustrators apply a combination of the three high level tasks of occlusion handling, abstraction, and simplification on their data.
		subsequently, many pipeline stages are concerned with fulfilling these tasks with their respective measures.
these can, in combination, then enable other lower level tasks, such as, comparison,.. \textbf{[check brehmer task taxonomy]}

\subsubsection{molecular/mesoscale data}
	\textbf{todo: }describe cellpack format (outsource to mathieu)
	
	\textbf{[our data format:]}	
	this is the data that our pipeline operates on.
	
	\begin{itemize}
	\item atom: represents the smallest part of our data. represented by a unit sphere. always represented within a molecule alongside with other atoms. has information about its chemical element and its local position within a molecule.
		\item molecule: a single molecule. groups together a bunch of atoms. has inherent spatial attributes (pos/rot/scale) and an attribute vector (type). all molecules in the scene are instances of their respective type. the entities that our pipeline operates on. molecules	can be hierarchically grouped to form subsets within a hierarchical scene graph. %has an original position and a target position and optionally control points in between
		\item subset: is a group of entities/molecules.	grouped according so specified attributes (spatial, by type, ..)
		%\item attributes: spatial (pos, rot, volume/size, shape) for original and target \& optionally intermediate (controlpoints) state
		%\item attributes: hierarchical (children, parent)
		%\item attributes: data (data, type, shape composed of atoms \& their positions, color, also time curve?)
	\end{itemize}

			
data is densely packed. depending on each molecules function, they can have a noisy distribution like in a liquid? or they can build rigid structures such as membranes.
		these attributes have to be taken into account when designing a target representation as well as the transition into it.
		


