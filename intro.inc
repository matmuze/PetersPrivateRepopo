\section{Introduction}\label{sec:intro}

Molecular biology is an emerging field that is characterized by rapid advances of the current state of knowledge.
New discoveries have to be communicated frequently to a large variety of audiences.
However, due to their complexity and mesoscopic scale, it is hard to directly convey the discoveries of molecular phenomena. 
Therefore illustrations that depict models of these mesoscale structures are the most widely used form of communicating them.

The traditional pipeline for creating scientific illustrations of molecular structures starts with gathering the required knowledge for building models that convey the newly discovered insights.
Illustrators then create sketches, in which the relevant internal and external regions of these structures are uncovered.
To achieve this, occlusion management techniques, such as \emph{cutaways} are applied.
Cutaways remove specific outer parts of the organism model, so that internal structures become visible. 
When biologists come up with new findings that are not depicted in the existing illustration, the conceptual layout of the original illustration might not be valid anymore.
The whole illustration process has to be repeated, in the worst case from the beginning, 
which is cumbersome and time consuming.
%Such a cycle can take months or even years to complete.

\begin{figure}[t]
 \centering
 \subfloat[]{\label{fig:hiv0}\includegraphics[width=0.495\linewidth]{figures/which0.eps}}
 \subfloat[]{\label{fig:hiv1}\includegraphics[width=0.495\linewidth]{figures/which1.eps}}
 \caption{\label{fig:which}Which of the proteins shown in (a) are visible in the illustration shown in (b) and which are not?}
\end{figure}

Considering the rapid evolution of knowledge in the field of biology, it is necessary to adapt the traditional illustration pipeline so that new information can be plugged in easily and resulting illustrations can be updated in a very short time.
Virtual 3D models of cells and other mesoscale molecular structures can be utilized for these purposes.
Biologists have designed tools, such as \emph{cellPACK} \cite{cellpack}, to procedurally generate 3D models that represent the structure of micro-organisms such as viruses, or entire cells at atomic resolution.
Based on a set of input parameters, individual molecules are assembled into these complex organic static structures. 
The parameter set consists of a specification of molecular ingredients, concentrations as well as spatial distribution that define where are the instances distributed in a given compartment. 
The resulting 3D models, in most complex cases, may consist of thousands of ingredients, which in turn, may result in millions of molecule instances and billions of atoms.
The instances are densely packed within the predefined compartments, to replicate the actual molecular crowding phenomenon prevailing in living organisms.
Due to the high density of these scenes, inner structures that are essential for conveying the functioning of the organism, remain hidden.
It is therefore important to develop visualization techniques that would procedurally reproduce the occlusion management methods used in traditional illustration.
Currently, this is achieved by placing clipping objects in the scene, which remove specified parts of the displayed model. 
However, illustrators have to make sure that the essential information, e.g., the ratio of multiple molecular ingredients is represented, and not either hidden in the volume or clipped away (Fig. \ref{fig:which}a). 
To do this, they would need to visually inspect the presence of each single ingredient in the resulting visualization (Fig. \ref{fig:which}b).
%However, in order to know how many instances have already been removed, and which molecular types are still sufficiently represented in the scene, the illustrator has to continuously check and compare the modeled scene against the gathered data and tediously confirm whether the essential information is still represented.
%As a tangible example, let us assume we have to confirm the presented ratio of multiple molecular ingredients (Fig. \ref{fig:which}a) in an illustration. 
%By clipping through the center of a 3D model, many structures can be revealed (Fig. \ref{fig:which}b). 
%However, for dozens of molecular types, it would be tedious to manually check whether all are displayed, or if some have been completely removed or not yet revealed through the clipping.
%However, to find out which of these ingredients have been actually shown by the clipping and which are completely cut or not yet revealed, one would need to manually check the presence of each single ingredient in the resulting visualization.



To alleviate this process, we present our first contribution. We display a stacked bar for each molecular type that encodes the ratio of visible, clipped, and occluded instances of the respective type for the current viewpoint and clipping setting. 
During the process of placing clipping objects in the scene, these bars therefore continuously reveal, which molecular types are underrepresented or overrepresented. 
This enables the illustrator to modify the placement of the clipping objects in such a way that every molecular type is adequately represented in the scene. We call this the coarse-level of the visibility specification process.

\begin{figure}[t]
 \centering
 \subfloat[]{\label{fig:hiv0}\includegraphics[width=0.495\linewidth]{figures/hiv0.eps}}
 \subfloat[]{\label{fig:hiv1}\includegraphics[width=0.495\linewidth]{figures/hiv1.eps}}
 \caption{\label{fig:hiv}(a) Illustration of an HIV particle. Here, outside membrane of the virus particle is visible. (b) Cutaway view of an HIV particle. Despite the cutaway, some of the glycoproteins (yellow molecules) are kept in the view to provide adequate context.}
\end{figure}

To preserve important structures that would be removed through clipping objects, such as cutting planes, traditional illustrations also often reintroduce parts of them in front of the revealed cross sections. 
In Figure \ref{fig:hiv1}, for instance, the glycoproteins (yellow molecules) of the HIV particle which are not occluding the object of interest, in this case the capsid containing the RNA, are left in the illustration to communicate their presence on the surface of the virus (\ref{fig:hiv0}).
In this way, the main components of the virus particle can be illustrated in a single image.
%Simple cutaway however, only achieve cross sections.
%In traditional illustration, fine-level visibility specification is often utilized as well.
%To communicate the biology knowledge well, the illustrations have to sometimes display molecular instances which would be impossible to specify with the simple clipping objects, such as cutting planes.%An example is shown in Figure \ref{fig:hiv}.
%Figure \ref{fig:hiv0} shows an illustration of an HIV particle.
%In Figure \ref{fig:hiv1}, a cutting plane is used to reveal internal structures of the virus - the capsid containing the RNA.
%Some of the glycoproteins (yellow molecules) are left in the illustration to communicate their presence on the surface of the virus particle.
%In particular, those glycoproteins which are not occluding the object of interest, were chosen to be kept in the illustration providing the contextual information.
The process of fine-tuning the visibility is extremely time-consuming, as the illustrator has to manually pick individual molecular instances to be reintroduced or removed from the scene. %in order to preserve important information whily not occlude occluding 
%This might be done to control the under and over representation of some of the molecular types, removing instances occluding important aspects of the model, suggesting shapes, etc.


To significantly speed up this visibility fine-tuning process, we propose a novel method for clipping instances using a fuzzy approach. 
In addition to either, entirely show or remove instances of a given ingredient, we offer the possibility to show only an arbitrary number of them.
The main purpose of this approach is to increase the visibility of hidden structures by removing redundant parts of occluding instances while preserving some of them.
An analogy of this approach can be drawn with ``Screen-Door Transparency'', which is a trivial way to obtain transparency in computer graphics, by placing small holes in a polygon to reveal what is present behind.
Additionally, we propose the novel metaphor of the \emph{visibility equalizer} for controlling efficiently this effect.
%To significantly speed up this visibility fine-tuning process, we propose the novel metaphor of the \emph{visibility equalizer} as our main technical contribution.
To explain its role, we use the metaphor of hi-fi sound reproduction where on a basic level, the \textit{volume control} is used for adjusting the output sound \textit{uniformly} on all frequencies. 
Such a mechanism corresponds to our coarse-level visibility specification through the clipping objects, where all molecular types are uniformly removed from the clipped regions.
However, hi-fi sound systems also allow users to fine-tune the sound through an \emph{equalizer}.
With an equalizer, the volume of each individual frequency band can be adjusted separately to achieve a desired sound reproduction.
In the sense of this of metaphor, the visibility of each molecule type can be regarded as a frequency band---represented as the stacked bars that form our visibility equalizer.
To achieve a similar level of fine-grained control for the visibility of the molecule types, we make these bars interactive---thus allowing the user to interact with the equalizer.
Individual intervals on each bar can be dragged to increase or decrease the visibility of the individual molecular types within the scene, given the specified clipping objects. 
%This interactive element effectively turns the stacked bars into visibility equalizers for the molecular models - and as such presents the main technical contribution of this paper.
When interacting with the visibility equalizer, the artist or biologist can intuitively achieve expressive cutaway designs in a fraction of the time that would be needed for manual visibility adjustments.
%The conceptual contribution of this work is demonstration of a scenario where a visualization metaphor, such as the stacked bar chart in our case, can serve as a user interface for performing a specific task, in our case authoring a cutaway design. We expect to see further cases where (information) visualization is simultaneously the user interface.

%\noindent{Our main contributions are:} %\begin{itemize}  \item a new workflow for illustrator-authored cutaway illustrations from mesoscale 3D structural models  \item a new visual metaphor of visibility equalizers with which allows users to fine tune the cut-away design so that visibility is distributed among the molecular types as desired by the illustrator.\end{itemize}

\begin{comment}

To speed-up the fine tuning process we propose a novel method for clipping instances using a fuzzy approach. 
In addition to either entirely show or remove instances of a given ingredient by the clipping object, we offer the possibility to show only an arbitrary number of these instances.
The main advantage of this approach is that we are able to increase the visibility of hidden structures while preserving potentially important, but redundant occluding molecules.
An analogy of this approach can be drawn here with ``Screen-Door Transparency'', which is a trivial way to obtain transparency in computer graphics, by simply placing holes in the polygon to reveal what is present behind.

\end{comment}



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
Figure \ref{fig:hiv0} shows an illustration of an HIV particle.
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


