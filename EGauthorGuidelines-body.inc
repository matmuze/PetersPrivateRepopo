% ---------------------------------------------------------------------
% EG author guidelines plus sample file for EG publication using LaTeX2e input
% D.Fellner, v1.17, Sep 23, 2010


\title[Visibility Equalizer]%
      {Visibility Equalizer}

% for anonymous conference submission please enter your SUBMISSION ID
% instead of the author's name (and leave the affiliation blank) !!
\author[M. Le Muzic et al.]
       {M. Le Muzic\thanks{mathieu@cg.tuwien.ac.at}$^{1}$,
        P. Mindek\thanks{mindek@cg.tuwien.ac.at}$^{1}$,
        J. Sorger\thanks{jsorger@cg.tuwien.ac.at}$^{1}$,
        L. Autin\thanks{ludovic.autin@gmail.com}$^{2}$,
        and I. Viola\thanks{viola@cg.tuwien.ac.at}$^{1}$        
        \\
% For Computer Graphics Forum: Please use the abbreviation of your first name.
         $^1$TU Wien, Austria
        $^2$ The Scripps Research Institute, La Jolla, California, USA
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

\section{Related Work}
\cite{Viola05}
\cite{Burns07}
\cite{Burns08}
\cite{Li07}
\cite{Lidal12}
\cite{cellVIEW_2015}

\section{Overview}

\begin{figure*}[t]
 \centering
 \subfloat[]{\label{fig:his0}\includegraphics[width=0.166\linewidth]{figures/h0.eps}}
 \subfloat[]{\label{fig:his1}\includegraphics[width=0.166\linewidth]{figures/h1.eps}}
 \subfloat[]{\label{fig:his2}\includegraphics[width=0.166\linewidth]{figures/h2.eps}}
 \subfloat[]{\label{fig:his3}\includegraphics[width=0.166\linewidth]{figures/h3.eps}}
 \subfloat[]{\label{fig:his4}\includegraphics[width=0.166\linewidth]{figures/h4.eps}}
 \subfloat[]{\label{fig:his5}\includegraphics[width=0.166\linewidth]{figures/h5.eps}}
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

\section{Fuzzy Cutaways}

\section{Equalizing Visibility}

\section{Evaluation}

\section{Results and Discussion}

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
