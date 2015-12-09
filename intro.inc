\section{Introduction}

Biology is an emerging field where the state of the current knowledge changes extremely quickly.
New discoveries have to be communicated to a large variety of audiences.
Since these discoveries often happen on the molecular level and they are not directly observable in sufficient detail, illustration is the only way how to communicate them.

Traditional pipeline of the scientific illustration starts with the collection of data and knowledge gathering.
Afterwards, illustrators make sketches, in which specific regions of the illustrated objects are uncovered.
For this, occlusion management techniques are necessary.
Oftentimes, \emph{cutaway views} are employed, where specific parts of the scene are removed form the organism model in the illustration, so that internal structures become visible.
When new knowledge is discovered, the conceptual layout of the illustration might break down and the whole process has to start from the beginning.
Therefore, the duration of this process counts in months or even years.

With the rapid changes to the knowledge in the field of biology, it is necessary to adapt the traditional illustration pipeline so that the new data can be easily plugged in and the resulting illustrations can be updated accordingly in a very short time period.
Virtual 3D models of cells and other mesoscale molecular structures can be utilized for this purposes.
Such models can be created with tools that procedurally assemble individual molecules into large complexes and into entire systems such as bacterial organisms.
An example of such a tool is \emph{cellPack} \cite{cellpack}. Its core functionality is a packing algorithm, which take individual molecular ingredients, as well as shapes of compartments where the instances of these ingredients are populated, as the input.
%and the knowledge from the field of integrative structural biology.
%The models consist of multiple instances of several molecular types.
The output is a 3D model consisting of multiple instances of several molecular ingredients.
The instances are densely packed within the predefined compartments.
The shape of the compartments is designed by the domain experts in biology.
%according to the biology knowledge.

The mesoscale biological models represent the structure of microorganisms, cells, or even viruses at atomic resolution.
However, simply displaying such models does not guarantee an adequate view of internal structures.
These structures are often the key for the function of the organism, and should be therefore shown in an illustration.
%These are therefore shown in the illustration.
%which are often necessary to communicate through an illustration.
%This is due to
The internal structures are occluded because of the high density of the molecular instances present in the models.
To solve this problem, visualization techniques need to be developed which reproduce the occlusion management methods used in traditional illustration.

Currently, occlusion management in mesoscale virtual models is carried out by placing clipping objects in the scene, which remove specified parts of the displayed model.
During this process, the illustrator does not have a good overview of what instances have been already removed, and which molecular types are still sufficiently represented in the scene.
The illustrator has to continuously check the modelled scene against the gathered data and tediously confirm whether all the necessary molecular types are still present.

To alleviate this process, we present our first contribution.
During the process of placing the clipping objects in the the scene, we display \emph {visibility histograms} of the molecular types, which immediately reveal which of them are underrepresented or overrepresented.
By looking at the visibility histograms, which are continuously updated, the illustrator is able to modify the placement of the clipping objects in such a way that every molecular type is adequately represented in the scene.
This is the coarse-level of the visibility specification process.

In traditional illustration, fine-level visibility specification is often utilized as well.
To communicate the biology knowledge well, the illustrations have to sometimes display molecular instances which would be impossible to specify with the simple clipping objects, such as cutting planes.
An example is shown in Figure \ref{fig:hiv}.
Figure \ref{fig:hiv0} shows an illustration of a HIV virus.
In Figure \ref{fig:hiv1}, a cutting plane is used to reveal internal structures of the virus - the capsid containing the RNA.
Some of the glycoproteins (yellow molecules) are left in the illustration to communicate their presence on the surface of the virus particle.
In particular, those glycoproteins which are not occluding the object of interest, were chosen to be kept in the illustration providing the contextual information.
In this way, the main components of the virus particle can be illustrated in a single image.

The process of fine-tuning the visibility is extremely time-consuming, as the illustrator has to pick individual molecular instances to be reintroduced or removed from the scene.
This might be done to control the under and overrepresentation of some of the molecular types, removing instances occluding important aspects of the model, suggesting shapes, etc.

To significantly speed up the fine-level visibility specification in our approach utilizing 3D virtual models, we propose our second contribution - \emph{visibility equalizers}.
To explain how the visibility equalizers are used to speed up the process of fine-tuning the visibility in molecular models, we use the metaphor of hi-fi sound reproduction.
In the hi-fi sound systems, volume control is the basic tool for adjusting the output sound uniformly on all frequencies.
This corresponds with the coarse-level visibility specification through clipping objects in the molecular scenes, where all molecular types are uniformly removed from the clipped regions.
However, hi-fi sound system allows users to fine-tune the sound through \emph{equalizers}.
With equalizers, the volume of each individual frequency band can be adjusted separately to achieve desired sound during the reproduction.
To achieve similar level of control for the visibility in the molecular models, we make the visibility histograms interactive.
Individual bins of the histograms can be dragged to increase or decrease visibility of the individual molecular types within the scene, given the specified clipping objects.
The interactive element effectively turns the visibility histograms into visibility equalizers for the molecular models.

Our main contributions are:
\begin{itemize}
  \item a new workflow for illustrator-authored cutaway illustrations from mesoscale 3D structural models
  \item a new visual metaphor of visibility equalizers with which allows users to fine tune the cut-away design so that visibility is distributed among the molecular types as desired by the illustrator.
\end{itemize}





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
