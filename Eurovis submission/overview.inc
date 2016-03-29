\section{Overview}



  
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

%The instances are never partially clipped - they are either removed or preserved in the scene. 
%This means that we can derive the visibility values by counting the visible and clipped-away instances.
%These are the three states that an instance can have. 
%The states are accumulated for all instances of each molecle type. 
%Instances are therefore never partially clipped or partially occluded.
%Partial occlusion is therefore not taken into account. 
%An important property of the clipping objects is that they always clip the scene per molecular instance. 
%This means that the whole molecule is always either shown, or clipped away.

%The clipping objects are implicitly represented by signed distance functions. The zero level set represents the surface clipping object. 
%Positive distances lie outside of the object and negative distances within the object. 
%Clipping can occur relative to the object, which we refer to as \emph{object-space clipping} but also relative to the viewpoint, which we describe as \emph{view-space clipping}. 
%For the latter, the shape of the clipping object acts as a focus region that is revealed through clipping based on its projection onto the screen.

%culling in respect to the current viewpoint.
%can be either used for clipping parts of the scene inside the manifold, which we refer to as . 
%Alternatively, they can be used to localize clipping of occluders of a specified focus region from the given viewpoint, which we refer to as .

%The clipping objects are defined by the distance functions, where the zero level set represents the clipping manifold. 
%They can be arbitrarily positioned within the 3D scene. 
%Additionally, the clipping objects contain several parameters, which modify the way in which they are clipping the molecules in the scene. 
%In particular, each clipping object has a probability threshold $v_1$. $v_1$ specifies the probability of an instance inside the clipping manifold being clipped away.
%By default, $v_1 = 1$.

%The ratios of the clipped instances are then immediately displayed by the visibility equalizer. 
%The implicit representation of the clipping objects allows us to simply query the signed distance function to quickly evaluate whether a molecule is inside or outside of the clipping manifold.
%The process of placing and manipulating clipping objects corresponds with the coarse visibility specification as introduced in Section \ref{sec:intro}.

%When the bars are dragged, probability thresholds of selected clipping objects are modified - directly influencing the probability that an instance of the respective type is clipped or not. 
%This complements the deterministic clipping introduced in the coarse step.
%Instead of the absolute clipping introduced in the coars step, the probability thresholds modify the probability for instances of a respective molecule to be ignored by the deterministic clipping object, thus remaining visible. %directly influence the amount of clipped and visible instances relative to the clipping object.
%This means the user is able to increase or decrease amounts of clipped away instances as well as the visible instances by dragging the visibility equalizer in a probabilistic manner. 

The two main components of our method are the \emph{clipping objects} and the \emph{visibility equalizer}. 
The workflow of our method is depicted in Figure \ref{fig:o}.
We distinguish between object-space object clipping and view-space object clipping.
Object-space clipping discards elements according to their distance to a geometric shape.
View-space clipping discards elements according to whether or not they occlude certain objects in the current viewport.
The role of the visibility equalizer is two fold, to provide important information about the visibility of molecular species, and to let users override the behaviour of the clipping objects by directly manipulating the equalizer values. 
%It contains a series of stacked bars, one for each molecular species, which can be manipulated by user-interaction. 
Each set of stacked bars show three quantitative information for a given type of ingredient: \emph{a} - the ratio of visible instances to the total number of instances; \emph{b} - the ratio of occluded instances to the total number of instances; \emph{c} - the ratio of dicarded instances to the total number of instances.
The visual encoding of the visibility equalizer is illustrated in Figure \ref{fig:ohist}.
By dragging the light green bar, the proportion of instances affected by the object-space clipping is modified, while dragging the dark green bar modifies the proportion of instances affected by the view-space clipping.

%It is important to mention that with multiple clipping objects, interaction with the light green bar in the visibility equalizer will only affect the clipping probability of the selected clipping object.
%We demonstrated three possible states, denoted as \emph{S1}, \emph{S2}, and \emph{S3}. 

%\textbf{S1: }The scene is displayed without any clipping. 
%The visibility equalizer shows that no molecules are clipped, and provides the described visibility information for each molecular ingredient.

%\textbf{S2: }Clipping objects are added to filter-out elements according to the distance to a clipping object's shape.
%This state corresponds to the coarse visibility tuning.
%Each time the scene is refreshed, visible and clipped instances are counted and the values of the visibility equalizer are updated accordingly. 

%\textbf{S3: }The user overrides the behaviour of a clipping object, by interacting with the visibility equalizer as illustrated in Figure \ref{fig:his}.
%Upon modification of the Visibility Equalizer values, the scene is updated and re-rendered to match with the user specified clipping properties.
%This state corresponds to the fine visibility tuning as illustrated in Figure \ref{fig:his}.

%The lower part of Figure \ref{fig:o} shows the technical overview of our method. 
%At the beginning of the pipeline, multiple clipping objects are placed in the scene to filter the data. 
%In case the user interacts with the stacked bars of the visibility equalizer, the properties of the selected clipping object are modified. 

%During the whole process of the visibility specification, the user is informed about the amounts of the visible and clipped-away instances in the scene through the visual encoding of the visibility equalizer.

\begin{figure}[t]
\centering 
\includegraphics[width=0.6\linewidth]{figures/o-histogram-merged.eps}
\caption{\label{fig:ohist}Illustration of the visibility equalizers. 
Each molecular ingredient has its own stacked bar showing (a) instances visible from the current viewpoint, (b) occluded instances, (c) instances clipped away by the clipping objects.}
\end{figure}

\begin{comment}

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