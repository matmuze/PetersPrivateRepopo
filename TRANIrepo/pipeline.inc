\section{Metamorphosis formalization}

\begin{figure*}[ht!]
\centering
 \includegraphics[width=0.9\linewidth]{figures/pipeline.png}
\caption{\label{fig:overview}The metamorphosis pipeline. Continuum creation: data restructuring, morphing, layouting. Continuum presentation: camera control, trajectory, timing, sampling.}
\end{figure*}

The context of our research lies in the field of explanatory visualizations of large-scale models of biological structures, such as viruses and bacteria, where relationships between various abstracted or transformed visual representations of a model should be conveyed without any need for user interaction.
Such visualizations are employed by scientific illustrators and animators for conveying science to expert and non-expert audiences in an easily accessible and engaging way.

Each illustration which communicates a relationship starts with the two representations of the model. The first, source representation, is typically close to the mental model of the audience. The second, target representation, illustrates different aspects of the presented model, but its relationship to the source representation might not be obvious. In that case, the illustrator needs to manually create the visual transition between the two representations. We present a method for creating a continuum, or metamorphosis, between two arbitrary model representations that illustrates the relationship between these representations.

The continuum is defined as follows: the state of each data element is represented as a point in multidimensional "attribute" space. Each attribute of the data is present as one dimension of this space. The continuum is represented by curves in this multidimensional "attribute" space that connect, i.e., relate, the points of an element's source state to its target state.
Our method creates this continuum by describing the target representation on the basis of the original representation, thus alleviating the illustrator from creating the transition manually.

Figure \ref{fig:ov0} shows a source and a target representation. Both communicate certain aspects of a model, but they are disconnected, their relationship is not immediately clear. Our pipeline consists of two high level steps. In the first step, we \textit{create} the continuum by explicitly defining relations between the data structures, visual, and spatial properties of the source and target representation (Fig. \ref{fig:overview}, left).
%explicitly define the relation between an element's attribute in its source and target state. e between both representation states.
However, this unstructured connection is not yet ready for illustrating the relationship between the representations (Figure \ref{fig:ov1}), no means for making the transition readable have yet been applied. The continuous space that we created can be sampled but we have to define \textit{how} first.
This is the task of the second step of our pipeline - it prepares this continuum for \textit{presentation} to an intended audience (Figure \ref{fig:ov2}) by specifying how the relations that we created in the first step should be presented (Fig. \ref{fig:overview}, right). 
%The presentation of the metamorphosis is handled by the last four stages of our pipeline (Fig. \ref{fig:overview}), i.e., in regard to \textit{how} the transition should be carried out.
With this step, the metamorphosis is finalized so that it illustrates the relationship between the source and the target representations.

The metamorphosis is carried out by applying a sequence of operators in our pipeline (Fig. \ref{fig:overview}), which we refer to as \emph{metamorphers}. The operators can be arbitrarily combined by the illustrators to achieve results which they would otherwise have to create manually.

%Each metamorpher belongs to one of the stages of a pipeline according to the task it is used to solve.

%For the clarity, the operators are grouped into several stages

\subsection{Continuum Creation}
In the first step of the pipeline, the continuum between two model representations is created. The continuum forms the basis for the communication of the relationship between two desired data representations.

When illustrators manually create a transition across data representations in a 3D modeling tool, e.g., by key-framing it, the relation between the representations is not explicitly specified. 
Without such a relation, the transition that they modeled is only valid for the exact combination of the specified data, original representation, target representation, as well as the visual transition.
The problem with this approach is that if one of these four aspects should be changed, e.g, because new findings about the data have been discovered, or a different information should be conveyed, the entire transition has to be manually remodeled from scratch.

To overcome this issue, we explicitly create this continuum in the first step of our pipeline by specifying relationships between all aspects of the underlying source and target representations.
The continuum is created with the sequential execution of the metamorphers in the pipeline.
The metamorphers define how an aspect A, e.g., the position, in the source state relates to aspect B in the target state.
The relationship is explicitly modeled with these metamorphers.
Therefore, if the underlying data is changed, the relationship remains.
The transition does not have to be remodeled,
simply the involved metamorphers have to be re-executed on the new data,
thus saving significant effort for the illustrator.

%The continuum can then be reused for different data, or different form of presentation to the viewers, saving a significant effort of the illustrator.

%explicitly relating each point in the attribute space of the source and the target representation to each other. 
%The continuum can then be reused for different data, by replacing the original representation, i.e., the starting point of the curves in attribute space. 
%The continuum can be reused for different target representations by replacing the target points of the curves in attribute space, thus saving a significant effort of the illustrator.

%%In the first step of the pipeline, the continuum between two model representations is created. Such a continuum is essential to communicate the relationship between two desired data representation. Alternatively, the continuum can communicate essential information to the viewers, for instance the way how various biological processes occur.
%When illustrators manually create transitions across data representations, they have to keep this continuum in mind while they create its actual visual encoding. They typically don't build relationships between the representations, but design the transition in such a way that the continuum is communicated. The problem with this approach is that if the underlying data change, or different relationship is to be communicated, the entire transition has to be recreated from scratch.
%To overcome this issue, we split the continuum creation from its presentation to the viewers. In the first step of our pipeline, this continuum is explicitly created by specifying relationships of various aspects of the underlying data representations. The continuum can then be reused for different data, or different form of presentation to the viewers, saving a significant effort of the illustrator.
%%

%In this section, we describe the three stages of the continuum creation, with examples of metamorphers which can be used in these stages.

\subsubsection{Data restructuring}
%Biological data models are organized in a hierarchy, which corresponds with the semantics of abstraction of the modelled phenomena.
Biological data models often have a semantic hierarchy, such as the compartments that build up a cell.
The hierarchy in a target representation does not necessarily have to be the same, e.g., due to abstraction of certain details.
Therefore, the first step of connecting two representations, is to match their semantic hierarchy.
%Therefore, as the first step of connecting two representations, the metamorphers in this stage match their semantic hierarchy.
The metamorphers in this stage, relate the original data structure with the data structure of the target representation by defining data subsets within the source model representation that match the semantics of the target representation, thus restructuring the data.
%The illustrator defines data subsets within the source model representation, which match the semantics of the target representation, thus restructuring the data.
Optionally, data subsets can be duplicated, if the target representation requires it.
All data subsets are organized in a hierarchical tree structure, or a scene graph.
The subsequent pipeline stages can operate on any node of the scene graph, giving illustrators the flexibility they are used to from 3D modeling software.

Examples of metamorphers used in this stage are explicitly defined cutaway objects, such as those proposed by Le Muzic at al. \cite{LeMuzic:EV:2016}, which specify spatial data subsets, or data clustering algorithms, e.g., that group proteins by their type.

\subsubsection{Morphing}
%DESCRIBE THE RELATION
An important aspect of relating two representations of the same biological data to each other, is understanding how the shapes of individual elements in those two representations relate to each other.
%The understandability of the relationship between two different representations of the same biological entities strongly depends on the similarity of their visual representation.
%Depending on the visual appearance of biological entities in two different representations forms
%An important aspect that might obfuscate the relationship between different representations of the biological data are the shapes, or visual representations, of the individual data elements. 
For instance, molecules in mesoscale biological models can be displayed as space-filling models, stick models, or one of many other representations commonly used in molecular graphics. Alternatively, molecules can be represented in a different spatial frame of reference, as abstract shapes, such as cuboids, to illustrate quantitative information, such as their volume.

Metamorphers in this stage of the pipeline therefore specify the relationships between the shapes of the corresponding data elements. Depending on the target representation, two types of metamorphers can be applied to establish this relationship:

\emph{Object-space morphing} metamorphers define how to transition between 3D shapes of the visual representations of the data elements. For instance, in molecular data, this can be achieved by continuously repositioning the individual atoms of a molecule to form the shape of the target representation, such as a different molecule, or an abstract shape (Fig. \ref{fig:mm0}). %If the atom counts of the two molecules differ, multiple atoms are placed at the same spatial location to match these counts before the object-space morphing is applied.

\emph{Image-space morphing} metamorphers define how to transform the visual representation of data elements in image space, for instance, through alpha blending or other image-processing operations (Fig. \ref{fig:mm2}). These metamorphers are used when the two representations cannot be adequately matched in the object space.

%For this purpose, we propose two metamorphers.

%\emph{Shapeshift} metamorpher morphs the shape of the elements in the object space. In case of molecules, this is achieved by continuously repositioning the individual atoms of a molecule to form the shape of a different molecule. If the atom counts of the two molecules differ, we place multiple atoms at the same spatial location to match these counts before the shapeshift operator is applied.

%\emph{Crossfade} metamorpher morphs the shape of the elements in the image space. This is simply achieved by cross-fading the visual representations of the two data elements through alpha-blending.

\subsubsection{Layout}
Depending on what illustrators intend to convey in a target representation, they often need to reposition data elements within the visualization.
This might be done as means for occlusion handling, e.g., by exploding dense data to reveal the internal structures, or to simplify a noisy or complex spatial arrangement of the data elements to better fit the viewer's mental model. Elements could be positioned so that they represent an altogether different visualization space, such as a network that shows interactions between molecules.

%To allow the illustrators to create transitions between various spatial arrangements of the data elements, the target state have to be

Metamorphers in this stage of the pipeline therefore define how the spatial arrangements of data elements in both representations are related to each other, in order to allow illustrators to create spatial transitions between both layouts.
Metamorphers define this relation with a sequence of transformations of the positions, rotations, and scales of the data elements.
Layout metamorphers operate on the individual nodes of the scene graph down to the individual data elements (e.g., molecules), so that whole data subsets can be transformed at once.
Additionally, layout metamorphers can be arbitrarily stacked to achieve a wide range of spatial transformations.
Such metamorphers can arrange data elements into various 3D volumes, such as cubes or spheres in order to illustrate their relative counts, or align them side by side for comparison.



\subsection{Continuum Presentation}
After the continuum between the two data representations is created, the "how?" of its presentation needs to be answered. The transition should be presented in a way that is engaging, readable, and valuable, i.e., so that it conveys the relevant information for the current scenario.
%After the continuum between the two data representations is created, it needs to be presented in an engaging, readable, and valuable way, i.e., so that it conveys the relevant information for the current scenario.
There are three high level tasks that are essential in achieving this goal: occlusion handling, the steering of the viewer's attention, and the reduction of visual clutter. These tasks can be achieved during the second step of our pipeline, consisting of four different stages.

%After the continuum between the two data representations is created, it needs to be processed so that it adequately communicates the intended message. This processing takes place within the second step of the pipeline, consisting of four stages.


%Independent of the intended purpose of a transition, it is essential, how the transition is presented, in order to make it engaging, readable, and valueable (in the sense that it conveys relevant information).
%Three high level tasks are responsible for achieving these goals: occlusion handling, the steering of the viewer's attention, and the reduction of visual stimuli.
%The tasks can be achieved in both, the target representation of the transition, and during the transition itself. In the former case, the continuum creation pipeline stages are responsible, in the latter the continuum presentation stages.
%occlusion handling helps to.... can be handled for instance by
%steering helps to... can be handled for instance by
%stimuli reduction helps to.. can be handled for instance by.. stages

\subsubsection{Trajectory}
While the layout stage of the pipeline defines the "what" of the spatial relationship between data elements in different data representations, the actual "how", i.e., the trajectories between each source/target pair of spatial attributes is not yet specified. It is necessary to define the trajectory along which the data elements move in order to transit from the source representation to the target one. This is achieved in the first stage of the continuum presentation step.

Trajectory metamorphers define the "how" of the spatial relation based on arbitrary sets of control points between the source and target transformations of the data elements. These control points define the paths along which the data elements move, rotate, and scale during the metamorphosis. 
%The continuity of the spatial transformations is achieved through linear interpolation of the translations and scaling, and spherical linear interpolation of the rotations.

The metamorphers of the trajectory stage can be used to structure the transition, such as through various edge-bundling methods. For instance, the molecules of the same type can move to their target positions along similar paths in order to minimize the visual clutter created by the transition (Fig. \ref{fig:mm3}).

\subsubsection{Timing}
In order to coordinate the transitions specified in the morphing and the layout stages, illustrators need to create an appropriate temporal arrangement for them. Such an arrangement can, on the one side, encode information about the chronology of the illustrated events. On the other side, illustrators use the speed and sequence at which individual transitions occur as means to suggest the transition's importance for the communicated message, as well as to draw a viewer's attention to different parts of the illustration.

Metamorphers in the timing stage define the "how" of this temporal arrangement.
%The temporal arrangement is designed through metamorphers of the timing stage.
They operate on so called \emph{time curves} that are associated with each node in the scene graph. These curves are used as transformations of the data elements' positions within their specified trajectories as functions of time.

Timing metamorphers are used to specify the starting time of each transformation, as well as its speed (Fig. \ref{fig:mm1}). As such, they can be used to create various temporal effects, such as staging \cite{Heer:TVCG:2007} to reduce the visual clutter during the transition, and ease-in or ease-out curves for the movement of the data elements or entire data subsets. Time curves can also be modified to make some of the elements stop in the middle of the specified trajectory, or to reverse their movement.

%Additionally, the speed at which individual transitions occur might be used by the illustrators to suggest importance of the individual events and 


\begin{figure*}[t]
\centering
\subfloat[]{\label{fig:mm0}\includegraphics[width=0.17\linewidth]{figures/mm0.png}}
\hfill
\subfloat[]{\label{fig:mm2}\includegraphics[width=0.17\linewidth]{figures/mm2.png}}
\hfill
\subfloat[]{\label{fig:mm3}\includegraphics[width=0.17\linewidth]{figures/mm3.png}}
\hfill
\subfloat[]{\label{fig:mm1}\includegraphics[width=0.17\linewidth]{figures/mm1-1.png}}
\caption{\label{fig:mm}Examples of different metamorphers: a) object space morphing, b) image space morphing, c) trajectory bundling, d) distance based time offset}
\end{figure*}


\subsubsection{Camera Control}
To adequately follow the development of continuous transitions, e.g., when trajectories or target representations lie outside the original view frustum, and to guide the viewer's attention towards important details of a representation, camera steering is a necessary component of a non-interactive explanatory visualization. %To assure the visibility of all important data elements at each time step, illustrators specify camera settings and how they change over time.

Camera control metamorphers define how camera settings change over time, to assure the visibility of all important data elements at each time step.
%In our pipeline, this task is carried out through the metamorphers in the \emph{camera control} stage.
These metamorphers access the temporally and spatially arranged data elements and use this information to automatically modify the position and the look-at vector of the camera. A camera control metamorpher could, for instance, set the look-at vector of the camera to point in the centroid of the data elements, while it moves the camera far enough to capture the entire data set for the given field-of-view.



\subsubsection{Sampling}
To present the created transition to the viewers, it is necessary to select a set of time steps that are going to tell the story intended by the illustrators. In the simplest case, the transition is sampled densely enough to form a seamless animation, given a certain number of frames per second and a desired length of the animation.
In other situations,
%However, due to various disadvantages of animation, as discussed in Section \ref{sec:intro},
it might be more feasible to present only a few representative time steps which show the essential aspects of the transition, e.g., as a narrative sequence of single images.

Metamorphers of the \emph{sampling} stage implement various strategies of how these time steps are chosen. While the previous stages of the pipeline can be called multiple times in order to create more complex transitions, the sampling stage is final, as it ties together the information from the previous stages to sample the visual result.

To sample the transition information created in the previous stages, the scene graph information is propagated down through the hierarchy to the individual data elements, to determine their absolute positions, orientations, and shapes at each point in time. %The trajectory and the timing stages of the pipeline provide the information about the intermediate transformations of the data elements in an arbitrary time step, which is in turn acquired by the sampling metamorphers.
%Since the operators applied in the previous stages of the pipeline are continuous, t
There are no restrictions on how the sampling is performed. For instance, it is possible to create a hybrid visualization that displays a sparsely sampled narrative sequence of small multiples. Upon request, a continuous animated transition between two consecutive small multiples could be shown to provide additional information on how they relate to each other.

The sampling stage can also determine if the transition is pre-calculated or sampled on the fly in real-time.
A continuous pre-calculated transition could be used not only for display in an animation but also for extracting information about the continuous change or motion of the transition. This extracted information could then be used for encoding the otherwise missing information about the transition in the form of glyphs within a static single result image. %These glyphs can be calculated from the continuous pre-baked information.




