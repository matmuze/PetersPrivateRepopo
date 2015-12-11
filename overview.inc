\section{Overview}

\begin{figure}[t]
\centering
%\subfloat[]{\label{fig:his0}\includegraphics[width=0.166\linewidth]{figures/hi0.eps}}
%\subfloat[]{\label{fig:his1}\includegraphics[width=0.166\linewidth]{figures/hi1.eps}}
\subfloat[]{\label{fig:his2}\includegraphics[width=0.25\linewidth]{figures/hi3.eps}}
\subfloat[]{\label{fig:his3}\includegraphics[width=0.25\linewidth]{figures/hi2.eps}}
\subfloat[]{\label{fig:his4}\includegraphics[width=0.25\linewidth]{figures/hi4.eps}}
\subfloat[]{\label{fig:his5}\includegraphics[width=0.25\linewidth]{figures/hi5.eps}}
\caption{\label{fig:his}Interaction with the visibility equalizer. (a) increasing the visibility ratio of the red molecules, reduces the occluding blue molecules. (b) completely decreasing the clipping ratio of the red molecules. (c) partially decreasing the clipping ratio of the blue molecules. (d) combining the steps from a and b to increase the overall visibility of the red molecules.}
\end{figure}

 \begin{figure}[t]
  \centering 
	\includegraphics[width=\linewidth]{figures/o-histogram-merged.eps}
  \caption{\label{fig:ohist}Visual representation of the visibility equalizers. Each molecular ingredient has its own stacked bar showing (a) instances visible from the current viewpoint, (b) occluded instances, (c) instances clipped away by the clipping objects.}
 \end{figure}

\begin{comment}
 \begin{figure}[t]
  \centering 
	\includegraphics[width=\linewidth]{figures/o1.eps}
  \caption{\label{fig:overview-user}User-centric overview of our method.}
 \end{figure}

 \begin{figure}[t]
  \centering 
	\includegraphics[width=\linewidth]{figures/o0.eps}
  \caption{\label{fig:overview-tech}Technical pipeline of our method.}
 \end{figure}

\begin{figure*}[t]
 \centering
 \subfloat[]{\label{fig:o0}\includegraphics[width=0.47\linewidth]{figures/o1.eps}}
 \hfill
 \subfloat[]{\label{fig:o1}\includegraphics[width=0.47\linewidth]{figures/o0.eps}}
 \caption{\label{fig:o}The workflow of our method. The data can be displayed either without any clipping (\emph{S1}), with deterministic clipping defined by the clipping objects (\emph{S2}), or by probabilistic clipping specified through the visibility equalizer (\emph{S3}). %Below the states, the used technologies are shown: the user can either use clipping objects to clip the data, or she can manipulate the visibility equalizer to modify the clipping parameters of the clipping objects.
 }
\end{figure*}

\end{comment}  

\begin{figure}[t]
 \centering
	\includegraphics[width=\linewidth]{figures/o.eps}
 \caption{\label{fig:o}The workflow of our method. The data can be displayed either without any clipping (\emph{S1}), with deterministic clipping defined by the clipping objects (\emph{S2}), or probabilistic clipping specified through the visibility equalizer (\emph{S3}). Lower part (technical overview): each clipping object filters the output of the previous one. The rendered image is used to update the visibility equalizer. Interaction with the bars updates the scene to match the specification in the visibility equalizer.%(b) The technologies used in the workflow. The user can either use clipping objects to clip the data, or he can manipulate the visibility equalizers to modify clipping parameters of the clipping objects.
 }
\end{figure}
  
% \begin{figure}[t]
%  \centering 
%  \subfloat[]{\label{fig:overview1}\includegraphics[width=\linewidth]{figures/o1.eps}}
%  
%  \subfloat[]{\label{fig:overview0}\includegraphics[width=\linewidth]{figures/o0.eps}}  
%  \caption{\label{fig:overview}Overview.}
% \end{figure}


%In this work, we focus on visualization of 3D models of mesoscale molecular structures, such as cells or viruses.
%We utilize \emph{cellView} \cite{muzic15} tool for both representation and rendering of our 3D scenes.
%These scenes can consist up to billions of individual atoms, each belonging to one of the molecular ingredients.

The two main components of our method are the \emph{clipping objects} and the \emph{visibility equalizer}. The visual encoding of the visibility equalizer is illustrated in Figure \ref{fig:ohist}. It contains a series of stacked bars, one for each molecular ingredient. The stacked bars show the relation of three visibility values to each other: \emph{a} - the ratio of visible instances of the given ingredient from the current viewpoint; \emph{b} - the ratio of occluded instances; \emph{c} - the ratio of instances which are removed by the clipping objects. The instances are never partially clipped - they are either removed or preserved in the scene. This means that we can derive the visibility values by counting the visible and clipped-away instances.



%These are the three states that an instance can have. The states are accumulated for all instances of each molecle type. Instances are therefore never partially clipped or partially occluded.

%Partial occlusion is therefore not taken into account. 
%An important property of the clipping objects is that they always clip the scene per molecular instance. This means that the whole molecule is always either shown, or clipped away.

The clipping objects are implicitly represented by signed distance functions. The zero level set represents the surface clipping object. Positive distances lie outside of the object and negative distances within the object. Clipping can occur relative to the object, which we refer to as \emph{object-space clipping} but also relative to the viewpoint, which we describe as \emph{view-space clipping}. For the latter, the shape of the clipping object acts as a focus region that is revealed through clipping based on its projection onto the screen.

%culling in respect to the current viewpoint.
%can be either used for clipping parts of the scene inside the manifold, which we refer to as . Alternatively, they can be used to localize clipping of occluders of a specified focus region from the given viewpoint, which we refer to as .

%The clipping objects are defined by the distance functions, where the zero level set represents the clipping manifold. They can be arbitrarily positioned within the 3D scene. Additionally, the clipping objects contain several parameters, which modify the way in which they are clipping the molecules in the scene. In particular, each clipping object has a probability threshold $v_1$. $v_1$ specifies the probability of an instance inside the clipping manifold being clipped away. By default, $v_1 = 1$.

Figure \ref{fig:o} depicts the workflow of our method as a state-machine. There are three possible states, denoted as \emph{S1}, \emph{S2}, and \emph{S3}. In the state \emph{S1}, the scene is displayed without any clipping. The visibility equalizer shows that no molecules are clipped, and provides the described visibility information for each molecular ingredient.
Clipping objects can be used to transition to state \emph{S2}, where parts of the model are removed in a deterministic way. Here, the distance function of the clipping objects determines whether an instance is clipped or not. %The implicit representation of the clipping objects allows us to simply query the signed distance function to quickly evaluate whether a molecule is inside or outside of the clipping manifold.
The ratios of the clipped instances are displayed by the visibility equalizer. The process of placing and manipulating clipping objects corresponds with the coarse visibility specification as introduced in Section \ref{sec:intro}.

At any point, the user can interact with the visibility equalizer to adjust the amount of the visible instances in the scene. By dragging the dark green bars, the visibility relative to occluders can be increased or decreased. Dragging the light green bars, modifies the visibility relative to clipping object. When the bars are dragged, probability thresholds of selected clipping objects are modified - directly influencing the probability that an instance of the respective type is clipped or not. This complements the deterministic clipping introduced in the coarse step.
%Instead of the absolute clipping introduced in the coars step, the probability thresholds modify the probability for instances of a respective molecule to be ignored by the deterministic clipping object, thus remaining visible. %directly influence the amount of clipped and visible instances relative to the clipping object.
%This means the user is able to increase or decrease amounts of clipped away instances as well as the visible instances by dragging the visibility equalizer in a probabilistic manner. 
This situation is represented by the state \emph{S3} and corresponds to the visibility fine-tuning step. The possible interactions with the visibility equalizer are illustrated in Figure \ref{fig:his}.

The lower part of Figure \ref{fig:o} shows the technical overview of our method. At the beginning of the pipeline, multiple clipping objects are placed into the 3D scene, filtering the data. Each clipping object filters the output of the previous one. In the rendering stage, the visible and clipped-away instances are counted in respect to the current viewpoint and the visibility equalizer is updated each frame. In case the user interacts with the stacked bars of the visibility equalizer, the probability thresholds of the selected subset of the clipping object are modified. Then the 3D scene is updated to match with the specification in the visibility equalizer. %During the whole process of the visibility specification, the user is informed about the amounts of the visible and clipped-away instances in the scene through the visual encoding of the visibility equalizer.






\begin{comment}

The visual representation of the visibility equalizers is illustrated in Figure \ref{fig:ohist}. The equalizers are represented by three stacked histograms, where each histogram bin represents single molecular ingredients. Each bin is a stack of three values, denoted as \emph{a}, \emph{b}, and \emph{c}. The part \emph{a} shows the number of visible instances of the given ingredient. The part \emph{b} shows the number of instances not removed by clipping, but not visible due to occlusion. The part \emph{c} represents the number of instances which has been clipped away.

Figure \ref{fig:overview-user} illustrates how our method is utilized by users. The method can show the data in one of three states, denoted as \emph{S1}, \emph{S2}, and \emph{S3}. In the state \emph{S1}, the data are shown without any clipping applied. The visibility equalizers are already shown, displaying the proportion of visible and occluded instances of the individual ingredients, however the user does not interact with them yet. In this state, the user can specify the viewing direction, which might modify the values displayed by the visibility equalizers.

In the state \emph{S2}, parts of the scene are removed. The user can switch from the state \emph{S1} to the state \emph{S2} by placing and manipulating cutting objects. These are represented as distance functions, of which zero level-sets are used as the clipping criteria. The visibility equalizers now also show the portion of the molecular instnaces, which has been clipped away. So far, the clipping has been done in a deterministic manner.

At this point, the user can use the information displayed by the visibility equalizers to steer the iterative process of the placement and the manipulation of the clipping objects (path $1$). However, at this point there is also the possibility of the direct interaction with the visibility equalizers. The values in the individual bins of the displayed histograms can be dragged in order to increase or decrease the number of clipped instances of certain ingredients, switching to the state \emph{S3}. This is carried out in a probabilistic manner. If the number of clipped-away instances is decreased, the probability that an instance passing a clipping test will be removed continuously decreases from $100\%$ to $0\%$. On the other hand, if the the number of clipped-away instances is increased, the probability of instances which do not pass the clipping test being removed from the scene continuously increases from $0\%$ to $100\%$.

\end{comment}




















 
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
