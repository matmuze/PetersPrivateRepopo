\section{Overview}

 \begin{figure}[t]
  \centering 
	\includegraphics[width=\linewidth]{figures/o-histogram.eps}
  \caption{\label{fig:ohist}Visual representation of the visibility equalizers.}
 \end{figure}
  
  
 \begin{figure}[t]
  \centering 
  \subfloat[]{\label{fig:overview1}\includegraphics[width=\linewidth]{figures/o1.eps}}
  
  \subfloat[]{\label{fig:overview0}\includegraphics[width=\linewidth]{figures/o0.eps}}  
  \caption{\label{fig:overview}Overview.}
 \end{figure}
 
 
In this work, we focus on visualization and illustration of 3D models of mesoscale molecular structures, such as cells or viruses.
We utilize \emph{cellView} \cite{cellVIEW_2015} tool for both representation and rendering of our 3D scenes.
These scenes can consist up to billions of individual atoms, each belonging to one of the molecular ingredients.
 
 
 
 
 \begin{comment}
 
  \begin{itemize}
 	\item We use cellView for the scene representation
 	\item In the first step, we want arbitrary culling shapes, so we use distance fields (clipping representation / clipping process)
 	\item implicit representation of the clipp[ing
 	\item extracting visibility
 	\item tree structure of the hisytorams
 	\item what happens when histogram is moved
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	histogram representation
 			\item histogram stacking (this is not important now)
 			\item log scale
 	
 	\item you can select subset of cutobjects which are modified by the histograms
 
 
 
 
 
 
 
 
 
 
 
 
 

\begin{itemize}
	\item We conceptualize the cutaway authoring as two stage process, as mentioned in the intro		\item We use cellView
	\item In the first step, we want arbitrary culling shapes, so we use distance fields
	\item Molecules before and after cutting test are counted in the first step, so that histograms can be shown
	\item In the second step, we need to change the visibility, so we make the culling objects fuzzy - some removed molecules are reintroduced, some non-cutaway molecules are removed. This has to correspond with the histograms, so that this could be set by dragging histograms.
	\item We also introduce decay curve, so that the fuzziness doesn't have to be uniform, but it can change according to the distance from the cutting surface - we can do this since we sue distance fields for cutting.
	\item We also do shading of the cutaway parts so that the cut shapes are easily perceivable.
\end{itemize}




\subsection{Design Principles for Cutaway Illustrations}
[here we write what principles are there, and how is our system fulfilling them]
\cite{Lidal12}

There are several issues with using cutaway views in illustrations.
First one is that it has to be clear from the visual representation of the cut that the given part of the object has been removed artificially for the sake of illustration.
Otherwise the viewers might believe that the hole created by the cut is in fact inherent part of the object.
This is commonly solved by using specific shapes of the cuts which significantly differ from the shapes naturally occurring within the object (e.g., using circular cut on object which only have straight edges).

Another issue is that the information about the part of the object that is being cut away is lost.
In technical illustration, this issue is often circumvented by displaying contours of the cutaway part of the object.
Alternatively, small portions of the cutaway parts can be reintroduced into the scene.
These graphical elements are not occluding the objects of interest, but at the same time they help to convey the overall shape of the cutaway part.

 \end{comment}
