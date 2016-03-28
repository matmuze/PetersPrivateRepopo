\hyphenation{cellPack}

% ---------------------------------------------------------------------
% EG author guidelines plus sample file for EG publication using LaTeX2e input
% D.Fellner, v1.17, Sep 23, 2010


\title[Visibility Equalizers]%
      {Visibility Equalizers for Molecular Visualization}

% for anonymous conference submission please enter your SUBMISSION ID
% instead of the author's name (and leave the affiliation blank) !!
\author[M. Le Muzic et al.]
       {M. Le Muzic\thanks{mathieu@cg.tuwien.ac.at}$^{1}$,
        P. Mindek\thanks{mindek@cg.tuwien.ac.at}$^{1}$,
        J. Sorger\thanks{sorger@cg.tuwien.ac.at}$^{1,2}$,
        L. Autin\thanks{ludovic.autin@gmail.com}$^{3}$,
        and I. Viola\thanks{viola@cg.tuwien.ac.at}$^{1}$        
        \\
% For Computer Graphics Forum: Please use the abbreviation of your first name.
         $^1$TU Wien, Austria \\
         $^2$VRVis Research Company, Austria \\
        $^3$ The Scripps Research Institute, La Jolla, California, USA
%             with different affiliations
       }

% ------------------------------------------------------------------------

% if the Editors-in-Chief have given you the data, you may uncomment
% the following five lines and insert it here
%
% \volume{27}   % the volume in which the issue will be published;
% \issue{1}     % the issue number of the publication
% \pStartPage{1}      % set starting page


%-------------------------------------------------------------------------
\begin{document}

% \teaser{
%  \includegraphics[width=\linewidth]{eg_new}
%  \centering
%   \caption{New EG Logo}
% \label{fig:teaser}
% }

\maketitle

\begin{abstract}
In scientific illustration and visualization, cutaway views are often employed as an effective technique for occlusion management in densely packed scenes.
We propose a novel data-centric method for authoring cutaway illustrations of mesoscopic biological models.
In contrast to the existing cutaway algorithms, we take advantage of the specific nature of the biological models. These models consist of thousands of instances that are distributed across a comparably smaller number of different molecular types.
Our method constitutes a two stage process.
In the first step, culling objects are placed in the scene, creating a cutaway visualization of the model.
During this process, histograms inform the user about the instance visibility distribution of each individual molecular type in the scene.
In the second step, the visibility of each molecular type is fine-tuned through these histograms, which at this point act as interactive visibility equalizers. %The visibility equalizers give illustrators precise control over how much percent of each type of molecule should be visible in front of the cutting object. Thus enabling them to quickly and efficiently create visualizations of biological models that provide insights  which would have taken them to manually recreate.
The technique has been evaluated by domain experts in scientific illustration.




%In molecular biology and similar fields, knowledge transfer is commonly carried out through schematic illustrations.
%Traditionally, illustrations of biological processes on the molecular level have been created by manual hand drawing.
%Nowadays, complex models of various biochemical structures and micro-organisms exist.
%These models can be utilized in creating computer-generated biological illustrations through various molecular-visualization algorithms.
%When using such algorithms, it is beneficial for illustrators to be able to apply techniques common in traditional illustration, such as cutaway views.
%In this paper, we propose a method for enhancing real-time molecular-visualization algorithms with the capability to apply cutaway views.
%In contrast with existing cutaway algorithms, we take advantage of the specific nature of the biochemical models, which consists of multiple instances of a limited number of different molecular types.
%Our approach to cutaway views allows the illustrators to reintroduce some of the removed instances into the scene to communicate the presence of the given molecular type, yet maintaining the visibility of the internal structures of the model.
%This process is enabled through a novel interaction method for controlling the visibility in the instance-based scene. We refer to this method as visibility equaliser.


%In this paper, we propose a method for enhancing real-time molecular-visualization algorithms with the capability to display cutaway views.
%Such an option is beneficial to biological illustrators, since the technique of cutaway display is ubiquitously applied in traditional illustration.
%In contrast with existing algorithms for creating cutaway views, we take advantage of the specific nature of the biochemical models, which consist of multiple instances of the limited number of different molecular types.
%We are able to create comprehensible illustrations of complex models by reintroducing some of these instances in the cutaway parts of the rendered illustration.
%The main contribution of this paper is an interaction mechanism which allows the illustrators to precisely control the amount of instances of different molecular types in the illustration, while maintaining the desired information value.

\begin{classification} % according to http://www.acm.org/class/1998/
\CCScat{Computer Graphics}{I.3.3}{Picture/Image Generation}{Viewing algorithms}
\end{classification}

\end{abstract}




%-------------------------------------------------------------------------
\section{Introduction}

Biology is an emerging field where the state of the current knowledge changes extremely quickly.
New discoveries have to be communicated to a large variety of audiences.
Since these discoveries often happen on the microscopic level and they are not directly observable in sufficient detail, illustration is the only way how to communicate them.

Traditional pipeline of the scientific illustrators starts with the collection of data and knowledge gathering.
Afterwards, they make sketches, in which specific regions of the illustrated objects are uncovered.
For this, occlusion management techniques are necessary.
Oftentimes, \emph{cutaway views} are employed, where specific parts of the scene are removed form the illustration, so that internal structures become visible.
When new knowledge is discovered, the conceptual layout of the illustration might break down and the whole process has to start from the beginning.
Therefore, the duration of this process counts in months or even years.

With the rapid changes to the knowledge in the field of biology, it is necessary to adapt the traditional illustration pipeline so that the new data can be easily plugged in and the resulting illustrations can be updated accordingly in a very short time period.
Virtual models of cells and other mesoscale molecular structures can be utilized for this purposes.
These models can be created with tools such as \emph{cellPack} \cite{cellpack} and the knowledge from the field of integrative structural biology.
The models consist of multiple instances of several molecular types.
The instances are densely packed within predefined compartments according to the biology knowledge.

The mesoscale biological models represent the geometry of microorganisms, cells, or even viruses at atomic resolution.
However, simply displaying such models does not guarantee an adequate view of internal structures, which are often necessary to communicate through an illustration.
This is due to the high density of the molecular instances present in the models.
To solve this problem, visualization techniques need to be developed which reproduce the occlusion management methods used in traditional illustration.

Currently, occlusion management in virtual models is carried out by placing culling objects in the scene, which remove specified parts of the displayed model.
During this process, the illustrator does not have a good overview of what instances have been already removed, and which molecular types are still sufficiently represented in the scene.
The illustrator has to continuously check the modelled scene against the gathered data and tediously confirm whether all the necessary molecular types are still present.

To alleviate this process, we present our first contribution.
During the process of placing the culling objects in the the scene, we display \emph {visibility histograms} of the molecular types, which immediately reveal which of them are underrepresented or overrepresented.
By looking at the visibility histograms, which are continuously updated, the illustrator is able to modify the placement of the culling objects in such a way that every molecular type is adequately represented in the scene.
This is the coarse-level of the visibility specification process.

In illustration, fine-level visibility specification is often utilized as well.
To communicate the biology knowledge well, the illustrations have to sometimes display molecular instances which would be impossible to specify with the simple culling objects, such as cutting planes.
An example is shown in Figure \ref{fig:hiv}.
Figure \ref{fig:hiv0} shows an illustration of a HIV virus.
In Figure \ref{fig:hiv1}, a cutting plane is used to reveal internal structures of the virus - the capsid containing the RNA.
Some of the glycoproteins (yellow molecules) are left in the illustration to communicate their presence on the surface of the virus particle.
In particular, those glycoproteins which are not occluding the object of interest, were chosen to be kept in the illustration providing the contextual information.
In this way, the main components of the virus particle can be illustrated in a single image.

The process of fine-tuning the visibility is extremely time-consuming, as the illustrator has to pick individual molecular instances to be reintroduced or removed from the scene.
This might be done to control the under and overrepresentation of some of the molecular types, removing instances occluding important aspects of the model, suggesting shapes, etc.

To significantly speed up the fine-level visibility specification, we propose our second contribution - \emph{visibility equalizers}.
To explain how the visibility equalizers are used to speed up the process of fine-tuning the visibility in molecular models, we use the metaphor of hi-fi sound reproduction.
In the hi-fi sound systems, volume control is the basic tool for adjusting the output sound uniformly on all frequencies.
This corresponds with the coarse-level visibility specification through culling objects in the molecular scenes, where all molecular types are uniformly removed from the culled regions.
However, hi-fi sound system allow users to fine-tune the sound through \emph{equalizers}.
With equalizers, the volume of each individual frequency band can be adjusted separately to achieve desired sound during the reproduction.
To achieve similar level of control for the visibility in the molecular models, we make the visibility histograms interactive.
Individual bins of the histograms can be dragged to increase or decrease visibility of the individual molecular types within the scene, given the specified culling objects.
The interactive element effectively turns the visibility histograms into visibility equalizers for the molecular models.





\begin{comment}

In the field of molecular biology, micro-biology, and medicine, illustrations are essential for the inter- and intra-disciplinary knowledge transfer.
Over the years, illustrators have developed various techniques for capturing specific aspects of the displayed objects and processes.
One of the most common methods utilized in the technical illustration are so-called \emph{cutaway views}.
When a cutaway view is applied, parts of the illustrated object are left out, such as if they were physically cut away.
In this way, internal structures, which are to be communicated by the illustration, can be shown.

Creating hand-drawn illustrations of complex polymolecular structures, or even entire microorganisms, is an extremely tedious task. Such structures can contain hundreds of thousands of molecules.
Therefore, to communicate the intended message, it is often necessary to adequately simplify the structure in question.
The illustration then consists of appropriate abstractions, while certain amount of information is lost.

A different approach is to utilize computational models of the structures which are to be illustrated, and utilizing software packages for visualization of these models.
Such models, typically generated through simulation and statistical modelling, consists of large numbers of instances of several molecular types.
The different molecular types contained within the model represent the chemical composition of the modelled object, while the distributions of the instances of the individual types represent the concentrations of the respective chemical compounds.
High number of molecular instances, as well as their large densities, often make task of visualizing such models non-trivial.
The advantage of this approach is the possibility to generate illustrations exhibiting high degree of accuracy, which would require extremely high effort.

When utilizing the molecular models for the illustrative purposes, algorithmic equivalents of the traditional illustrative techniques are often employed.
For instance, software packages for computer-aided illustration often offer an option to manipulate and apply culling objects for creating cutaway views of the illustrated models or scenes.
The culling objects work in such a way that the part of the rendered scene enclosed by the surface of the cutting object is removed, thus making previously occluded structures visible.

%Cutaways views are essential in illustration of processes on the microscopic scale. These processes are often demonstrated on polymolecular models, where large number of molecular instances form complex nested structures. Such structures would be impossible to visualize when the model is displayed as a whole, thus creating a need for the cutaway views.

Simple culling objects are not always sufficient for the illustrative purposes. Sometimes, it is necessary to reintroduce parts of the scene that has been culled away in order to increase the informative value of the illustration. An example is shown in Figure \ref{fig:hiv}.
Figure \ref{fig:hiv0} shows an illustration of a HIV virus.
In Figure \ref{fig:hiv1}, a cutaway view is used to reveal internal structures of the virus - the capsid containing the RNA.
Some of the glycoproteins (yellow molecules) are left in the illustration to communicate their presence on the surface of the virus particle.
In particular, those glycoproteins which are not occluding the object of interest, were chosen to be kept in the illustration providing the contextual information. In this way, the main components of the virus particle can be illustrated in a single image.

In general, illustrators choose such placements of the culling objects that only unimportant parts of the scene are removed and no essential information is lost.
Specifically in molecular visualization, it is often desired that the culling objects are positioned so that all molecular types are represented in the generated scene.
However, the placement of the culling objects also needs to correspond with the geometrical structure of the model, so that it is obvious what are the artificial cuts introduced in the illustration, and what is their purpose.
Given the high complexity inherent to most of the molecular models, meeting both of these requirements at the same time is a difficult task.
With each additional culling object that the illustrator introduces into the scene, it gets progressively more difficult to keep overview of which molecular types are still represented in the scene in sufficient amounts.

To alleviate this problem, we propose \emph{Visibility Equalizer}.
It is a visualization element which displays a histograms of the individual molecule types present in the scene.
These histograms show the total numbers of molecules of each type in the model, numbers of molecules cut away by the clipping objects, and numbers of molecules of each type which are actually visible from the current viewpoint.
By showing these histograms, the illustrator is informed about the information value of the illustration at any given time during the creative process.

We focus on real-time visualization tools that can be used for illustration of molecular data.
In these scenarios, the user does not have direct control over the presented content, in contrast to a scenario where the content is created by manually placing individual molecules into the scene.
Therefore, Visibility Equalizer provides essential information about the scene while multiple culling objects are placed and dynamically manipulated.

\end{comment}

\begin{figure}[t]
 \centering
 \subfloat[]{\label{fig:hiv0}\includegraphics[width=0.495\linewidth]{figures/hiv0.eps}}
 \subfloat[]{\label{fig:hiv1}\includegraphics[width=0.495\linewidth]{figures/hiv1.eps}}
 \caption{\label{fig:hiv}(a) Illustration of a HIV virus. Here, outside membrane of the virus particle is visible. (b) Cutaway view of the HIV virus. Despite the cutaway, some of the glycoproteins (yellow molecules) are kept in the view to provide adequate context.}
\end{figure}

\include{relatedwork}


\section{Overview}

\begin{itemize}
	\item We conceptualize the cutaway authoring as two stage process, as mentioned in the intro		\item We use cellView
	\item In the first step, we want arbitrary culling shapes, so we use distance fields
	\item Molecules before and after cutting test are counted in the first step, so that histograms can be shown
	\item In the second step, we need to change the visibility, so we make the culling objects fuzzy - some removed molecules are reintroduced, some non-cutaway molecules are removed. This has to correspond with the histograms, so that this could be set by dragging histograms.
	\item We also introduce decay curve, so that the fuzziness doesn't have to be uniform, but it can change according to the distance from the cutting surface - we can do this since we sue distance fields for cutting.
	\item We also do shading of the cutaway parts so that the cut shapes are easily perceivable.
\end{itemize}


\begin{figure*}[t]
 \centering
 \subfloat[]{\label{fig:his0}\includegraphics[width=0.166\linewidth]{figures/hi0.eps}}
 \subfloat[]{\label{fig:his1}\includegraphics[width=0.166\linewidth]{figures/hi1.eps}}
 \subfloat[]{\label{fig:his2}\includegraphics[width=0.166\linewidth]{figures/hi2.eps}}
 \subfloat[]{\label{fig:his3}\includegraphics[width=0.166\linewidth]{figures/hi3.eps}}
 \subfloat[]{\label{fig:his4}\includegraphics[width=0.166\linewidth]{figures/hi4.eps}}
 \subfloat[]{\label{fig:his5}\includegraphics[width=0.166\linewidth]{figures/hi5.eps}}
 \caption{\label{fig:his}Visibility Equalizers.}
\end{figure*}

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

\section{Workflow}

Cull objects are defined...

\section{Property-Based Clipping}

%Additionally to defining where instances will be clipped, our system offer the mean to selectively chose the concentration of displayed elements for each protein types.
%These values are controlled by the user via the user interface. 

Our data comprise of a dense set of macromolecules, encapsulated in compartments with several degrees of nesting. 

Molecules are grouped by type and compartment, this information is contained in the scene file generated by cellPACK.

Basic filtering parameters allows to manipulate the visibility of entire set of instances based on their type, independently or not from a geometrical cull object.

Each cull object has its own parameters which are defined for all the ingredients type as shown in the overview figure XX.

When a geometrical shape is associated to the cull object, the filtered visibility will only be applied to the region defined by the geometry, e.g, plane, sphere, cone...

User can modify these filtering parameters via the user interface.

There are two parameters that are not directly related to object-space or view-space cull geometries.

First is the percentage of visible elements of a given type. 
We refer to this value as ingredient clip probability.

Second are the biochemical properties such as mass or quantities.

Additionally, there are more parameters which can influence when an instance is culled and which are depending on an actual geometry cull object, those are defined in section XX.


\subsection{Histograms}

To provide a clear overview of the scene properties, we display histograms for each ingredient type that indicate information about their visibility.

By default we chose to show three ranges in each histogram. The section of the histogram (dark green region) shows the percentage of instances that are currently visible on the screen. 
The entire green section (dark \& light green) represents the percentage of instances that are actually rendered.

In order to fill histograms with the correct value, we perform book-keeping of both clipped and visible instances, which we recompute after each changes in cut objects or camera.

Histograms are sorted per compartment in a tree layout, additional histograms are also displayed for the compartments, averaging all the values of the ingredients contained inside.

Histograms are also interactive.

Upon manipulation of the right end of the second range of the histogram (light green) the system will increase or decrease the clip probability internally, resulting in changes in displayed quantities.

%The dragging of the range is directly influencing the internal value "value1". 
The culled states of the instances will get subsequently updated and counted in order to update the histogram value.

Because of the degree of indirection between the user action and the view, we are also able change the way we display information in the histograms, without affecting the way of interacting with them.

For instance, quantities are relative by default, i.e, they represent a percentage, but they can also be displayed as absolute.

For displaying absolute quantities we support logarithmic scaling to ensure low quantities to be visible in the histograms.

An logarithmic ruler is also provided to help the user understanding the displayed values


\subsection{Instance Discarding}

Prior to the rendering each single instance is evaluated to determine if it shall be rendered.

The cut objects how instances shall be discarded and they are applied sequentially.

Internally the filtering is applied just after the object-space culling as shown in figure XX.

First is applied the filtering based the clip probability.

For each instance, we compare a uniformly distributed random number with the clip probability.

If the random number is higher than the probability, the instance is marked as culled, and will not be rendered. 

The random number is initially set for each individual instance and remain the same, in order to guaranty reproducibility of the scene.

Secondly, instances are filtered according to their biochemical properties, for each cut object and each protein types the user defines ranges values for the both quantities and molecular weight.

Instances whose properties lie outside on these ranges are marked as culled and discarded.

For the book-keeping is the clipped ingredient we count for each ingredient type how many instances where discarded in total, for all active cut object.



\section{Shape-Based Clipping}

\subsection{Object-Space}

The basic parameters of the cull objects define the global number of clipped instances for each ingredient type.

Additionally, they can be associated with geometrical shapes to determine where the clipping should take place.


\subsubsection{Analytical Distance Evaluation}

At the very beginning of the process, for each instance, prior to the filtering, we determine if the instance if located in the region defined by the geometry.

Our system currently supports the following set of primitive shapes (plane, cube, sphere, cylinder and cone)

Although simple, it may still be computationally expensive to evaluate the signed distance of those shapes with a large number of points in space, using a mesh-based representation.

To accelerate the computation we solve the problem analytically using a signed distance field (SDF).

Using such analytical representation reduces the problem of evaluating the distance to solving trivial 3D shapes equations.

It is also possible to apply traditional transform operations to the distance field, such as translation, rotation and scaling.

The effect of the shape-based clipping can also be inverted by inverting the result of the signed distance function, offering more usage flexibility.

Using, for instance, a spherical shape, the clip region would normally be set to the inside of the sphere, while in inverted mode it would correspond to the inside of the sphere. 

\subsubsection{Gradient Clipping}

We provide additional options to gradually remove instances given a geometrical shape.

The purpose is to facilitate the removal of instances, primarily for illustration purposes.

\textbf{TODO PMINDEK:} Talk about gradient clipping here


\subsection{View-Space}

While object-space culling using primitive shapes allows for a great degree of flexibility, it requires cumbersome manual operations for complex set-ups, and is also limited in terms of shapes diversities.

We additionally provide a method to specify a set of ingredient types as focus, and to selectively remove occluding instances.

\subsubsection{Mask-Based Approach}

Due to the potentially large number of instances in our scenes, we use accelerate the computation of occluding instances using an image-based approach on the GPU.

To determine what instances are in front of the focus, we first separately render a mask containing all the focus elements.

Focus ingredients are priorly selected from the histogram view via a dedicated toggle.

There can be only one mask created per cut object.

The mask is rendered using bounding sphere in order to lower to cost of the additional render pass.

The render pass sets the depth buffer in order to let subsequent draw calls to pass only if they are overlapping the focus region.

Subsequently, we draw the bounding sphere of the remaining instances over the mask, fragments that will pass the depth test are therefore guaranteed to belong to an object occluding the focus, with at least one pixel.

From the fragment program we then mark the occluding instance as culled, in a similar way as we would normally cull an instance. 





\subsubsection{Aperture Effect}

Image-based mask culling using depth and stencil test

\section{Depth cues and Enhancements}

\section{Results and Discussion}


\section{Evaluation}

\begin{figure}[t]
 \centering
 \includegraphics[width=\linewidth]{figures/results01.eps}
 \caption{\label{fig:results01}An illustration of the HIV virus in the blood serum utilizing cutaways created with our approach.}
\end{figure}

\section{Conclusions}

%-------------------------------------------------------------------------

%\bibliographystyle{eg-alpha}
\bibliographystyle{eg-alpha-doi}

\bibliography{ref}

%-------------------------------------------------------------------------


\end{document}
