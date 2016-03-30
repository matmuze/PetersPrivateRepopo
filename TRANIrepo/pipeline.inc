\section{Metamorphosis formalization}

\begin{figure*}[ht!]
\centering
 \includegraphics[height=5cm, width=\linewidth]{figures/pipeline.png}
\caption{\label{fig:overview}The metamorphosis pipeline. Continuum creation: data restructuring, morphing, layouting. Continuum presentation: camera control, trajectory, timing, sampling.}
\end{figure*}

The context of our research lies in the field of explanatory visualizations of large-scale models of biological structures, such as viruses and bacteria, where relationships between various abstracted or transformed visual representations of a model should be conveyed without any need for user interaction.
Such visualizations are employed by scientific illustrators and animators for conveying scientific topics to expert and non-expert audiences in an easily accessible and engaging way.

Each illustration which communicates a relationship starts with the two representations of the model. The first, source representation, is typically close to the mental model of the audience. The second, target representation, illustrates different aspects of the presented model, but its relationship to the source representation might not be obvious. In that case, the illustrator needs to manually create the visual transition between the two representations. We present a method for creating a continuum, or metamorphosis, between two arbitrary model representations that illustrates the relationship between these representations.

The state of each data element is represented as a point in multidimensional "attribute" space. Each attribute of the data is present as one dimension of this space. The continuum is represented by curves in this multidimensional "attribute" space that connect the points of an element's source state to its target state.

Our method creates this continuum by describing the target representation on the basis of the original representation, thus alleviating the illustrator from creating the transition manually.

Figure \ref{fig:ov0} shows a source and a target representation. Both communicate certain aspects of a model, but they are disconnected, their relationship is not immediately clear. Our pipeline consists two high level steps. In the first step, we create a continuous space between source and target representation. However, this unstructured connection is not yet ready for illustrating the relationship between the representations (Figure \ref{fig:ov1}). Therefore, the second step of the pipeline prepares this continuum for presentation to an intended audience (Figure \ref{fig:ov2}). In this step, the metamorphosis is finalized so that it illustrates the relationship between the source and the target representations.

The metamorphosis is carried out by applying a sequence of operators, which we refer to as \emph{metamorphers}. The operators can be arbitrarily combined by the illustrators to achieve results which they would otherwise have to create manually.

%Each metamorpher belongs to one of the stages of a pipeline according to the task it is used to solve.

%For the clarity, the operators are grouped into several stages

\subsection{Continuum Creation}
In the first step of the pipeline, the continuum between two model representations is created. The continuum forms the basis for the communication of the relationship between two desired data representations.

When illustrators manually create a transition across data representations in a 3D modeling tool, e.g., by key-framing it, the relation between the representations is not explicitly specified. 
Without such a relation, the transition that they modeled is only valid for the exact combination of the specified data, original representation, target representation, as well as the visual transition.
The problem with this approach is that if one of these four aspects should be changed, e.g, because new findings about the data have been discovered, or a different information should be conveyed, the entire transition has to be manually remodeled from scratch.

To overcome this issue, we explicitly create this continuum in the first step of our pipeline by explicitly relating each point in the attribute space of the source and the target representation to each other. 
The continuum can then be reused for different data, by replacing the original representation, i.e., the starting point of the curves in attribute space. 
The continuum can be reused for different target representations by replacing the target points of the curves in attribute space, thus saving a significant effort of the illustrator.

%%In the first step of the pipeline, the continuum between two model representations is created. Such a continuum is essential to communicate the relationship between two desired data representation. Alternatively, the continuum can communicate essential information to the viewers, for instance the way how various biological processes occur.
%When illustrators manually create transitions across data representations, they have to keep this continuum in mind while they create its actual visual encoding. They typically don't build relationships between the representations, but design the transition in such a way that the continuum is communicated. The problem with this approach is that if the underlying data change, or different relationship is to be communicated, the entire transition has to be recreated from scratch.
%To overcome this issue, we split the continuum creation from its presentation to the viewers. In the first step of our pipeline, this continuum is explicitly created by specifying relationships of various aspects of the underlying data representations. The continuum can then be reused for different data, or different form of presentation to the viewers, saving a significant effort of the illustrator.
%%

%In this section, we describe the three stages of the continuum creation, with examples of metamorphers which can be used in these stages.

\subsubsection{Data restructuring}
Biological data models are organized in a hierarchy, which corresponds with the semantics of abstraction of the modelled phenomena. This hierarchy often differ in both representations. Therefore, the first step of connecting the representations is to match their semantic hierarchy. In this step of the pipeline, the illustrator defines data subsets within the source model representation, which match the semantics of the target representation, thus restructuring the data. Additionally, some of the data subsets can be duplicated, if the target representation requires it. All the data subsets are then organized in a hierarchy with a tree structure, or a scene graph. All the subsequent pipeline stages can operate on any node of the scene graph, giving the illustrators the flexibility they are used to from the 3D modelling software.

Examples of metamorphers used in this stages are implicitly defined cutaway objects, such as those proposed by Le Muzic at al. \ref{our eurovis paper}, which specify spatial data subsets, or various data clustering algorithms.

\subsubsection{Morphing}
%DESCRIBE THE RELATION

An important aspect that might obfuscate the relationship between different representations of the biological data are the shapes, or visual representations, of the individual data elements. For instance, molecules in the mesoscale biological models can be displayed as space-filling models, stick models, or one of many different representations commonly used in molecular graphics. Alternatively, molecules can be represented by abstract shapes, such as balls or cubes illustrating their volume.

In this stage of the pipeline, the relationships between the shapes of the corresponding data elements are specified. For this purpose, two types of metamorphers can be applied.

\emph{Object-space morphing} metamorphers are used to transition between 3D shapes of the visual representations of the data elements. For instance, in the molecular data, this is achieved by continuously repositioning the individual atoms of a molecule to form the shape of a different molecule. If the atom counts of the two molecules differ, multiple atoms are placed at the same spatial location to match these counts before the object-space morphing is applied.

\emph{Image-space morphing} metamorphers transforms the visual representations of the data elements in the image space, for instance through alpha blending or other image-processing operations. These metamorphers are used when the two representations cannot be adequately matched in the object space.

%For this purpose, we propose two metamorphers.

%\emph{Shapeshift} metamorpher morphs the shape of the elements in the object space. In case of molecules, this is achieved by continuously repositioning the individual atoms of a molecule to form the shape of a different molecule. If the atom counts of the two molecules differ, we place multiple atoms at the same spatial location to match these counts before the shapeshift operator is applied.

%\emph{Crossfade} metamorpher morphs the shape of the elements in the image space. This is simply achieved by cross-fading the visual representations of the two data elements through alpha-blending.

\subsubsection{Layout}
Depending on the intended message, the illustrators often need to reposition data elements within the visualization. This might be done as means for occlusion handling, e.g., by exploding dense data to reveal the internal structures, or to simplify noisy or complex spatial arrangement of the data elements to better fit the viewer's mental model. Elements could be positioned so that they represent an altogether different visualization space, such as a network that shows interactions between molecules.

%To allow the illustrators to create transitions between various spatial arrangements of the data elements, the target state have to be

To allow the illustrators to create transitions between different data representations, the spatial arrangements of the data elements in both representations need to be matched. This is achieved by transforming the positions, rotations, and scaling of the data elements through \emph{layout} metamorphers. For instance, such metamorphers can arrange the data elements into various 3D volumes, such as cubes or spheres in order to illustrate their relative counts, or align them side by side for comparison.

The layout metamorphers operate on the individual nodes of the scene graph down to the individual data elements (e.g., molecules), so that whole data subsets can be transformed at once. Additionally, the layout metamorphers can be arbitrarily stacked to achieve wide range of spatial transformations.

\subsection{Continuum Presentation}
After the continuum between the two data representations is created, it needs to be processed so that the transition is engaging, readable, and valuable, i.e., it conveys the relevant information. There are three high level tasks that are responsible for achieving this goal: occlusion handling, the steering of the viewer's attention, and the reduction of the visual clutter. These tasks are carried out during the second step of our pipeline, consisting of four different stages.

%After the continuum between the two data representations is created, it needs to be processed so that it adequately communicates the intended message. This processing takes place within the second step of the pipeline, consisting of four stages.


%Independent of the intended purpose of a transition, it is essential, how the transition is presented, in order to make it engaging, readable, and valueable (in the sense that it conveys relevant information).
%Three high level tasks are responsible for achieving these goals: occlusion handling, the steering of the viewer's attention, and the reduction of visual stimuli.
%The tasks can be achieved in both, the target representation of the transition, and during the transition itself. In the former case, the continuum creation pipeline stages are responsible, in the latter the continuum presentation stages.
%occlusion handling helps to.... can be handled for instance by
%steering helps to... can be handled for instance by
%stimuli reduction helps to.. can be handled for instance by.. stages

\subsubsection{Trajectory}
While the layout stage of the pipeline defines the relationship between data elements in different data representations, the actual transition between them is not yet specified. It is necessary to define the trajectory along which the data elements move in order to transit from the source representation to the target one. This is done in the first stage of the continuum presentation step.

The trajectories are defined as arbitrary sets of control points between the source and target transformations of the data elements. These control points can form various curves along which the data elements move during the metamorphosis. The continuity of the spatial transformations is achieved through linear interpolation of the translations and scaling, and spherical linear interpolation of the rotations.

The metamorphers of the trajectory stage can be used to structure the transition, such as through edge-various bundling methods. For instance, the molecules of the same type can move to their target positions along similar paths in order to minimize the visual clutter created by the transition.

\subsubsection{Timing}
In order to present the transitions specified in the morphing and the layout stages to the viewers, illustrators need to create appropriate temporal arrangement for them. Such arrangement encodes the information about the chronology of the illustrated events. Additionally, illustrators use the speed at which individual transitions occur as means to suggest their importance for the communicated message, as well as to draw viewers attention to different parts of the illustration.

The temporal arrangement is designed through metamorphers of the timing stage. They operate on so called \emph{time curves} associated with each node in the scene graph. These curves are used as transformations of the data elements' positions within their specified trajectories as functions of time.

The metamorphers are used to specify the starting time of each transformation, as well as its speed. As such, they can be used to create various temporal effects, e.g., ease-in or ease-out curves for the movement of the data elements or entire data subsets. The time curves can be also modified to make some of the elements stop in the middle of the specified trajectory, or to reverse their movement.

%Additionally, the speed at which individual transitions occur might be used by the illustrators to suggest importance of the individual events and 


\begin{figure*}[t]
\centering
\subfloat[]{\label{fig:mm0}\includegraphics[width=0.22\linewidth]{figures/mm0.png}}
\hfill
\subfloat[]{\label{fig:mm1}\includegraphics[width=0.22\linewidth]{figures/mm1-1.png}}
\hfill
\subfloat[]{\label{fig:mm2}\includegraphics[width=0.22\linewidth]{figures/mm2.png}}
\hfill
\subfloat[]{\label{fig:mm3}\includegraphics[width=0.22\linewidth]{figures/mm3.png}}
\caption{\label{fig:mm}Examples of different metamorphers: a) shape morphing, b) time offset, c) blurring, d) trajectory bundling}
\end{figure*}


\subsubsection{Camera Control}
To adequately follow the development of continuous transitions, especially those between different visualization spaces, camera steering is a necessary component of a non-interactive explanatory visualization. To assure visibility of all data elements at each timestep, illustrators manually specify camera settings and how they change over time.

In our pipeline, this task is carried out through the metamorphers in the \emph{camera control} stage. These metamorphers access the temporally and spatially arranged data elements and use this information to automatically modify the position and the look-at vector of the camera. An example of camera control metamorpher sets the look-at vector of the camera to point in the centroid of the data elements, while it moves the camera far enough to capture the entire dataset for the given field-of-view.



\subsubsection{Sampling}
To present the created transition to the viewers, it is necessary to select a set of timesteps which are going to tell the story intended by the illustrators. In the simplest case, the transition is sampled densely enough to form a seamless animation, given certain FPS and a desired length of the animation. However, due to various disadvantages of animation, as discussed in Section \ref{sec:intro}, it might be necessary to select only few representative timesteps which show the essential aspects of the transition.

Metamorphers of the \emph{sampling} stage implement various strategies how these timesteps are chosen. While the previous stages of the pipeline can be called multiple times in order to create more complex animations/transitions/stories, the sampling stage is final, as it ties together the information from the previous stages to sample the visual result.

For this purpose, the scene graph information is propagated through the hierarchy down to the individual data elements, to determine their absolute positions and orientations. The trajectory and the timing stages of the pipeline provide the information about the intermediate transformations of the data elements in an arbitrary timestep, which is in turn acquired by the sampling metamorphers.

Since the operators applied in the previous stages of the pipeline are continuous, there are no restrictions on how the sampling is performed. For instance, it is possible to create a hybrid visualization that displays a sparsely sampled narrative sequence of small multiples. Upon request, a continuous animated transition between two consecutive small multiples can be shown to provide additional information on how do they relate to each other.

The sampling stage can also determine if the transition is pre-calculated or sampled on the fly in real-time.
A continuous pre-calculated transition could be used not only for display in an animation but also for extracting information about the continuous change or motion of the transition. This extracted information could then be used for encoding the otherwise missing information about the transition in the form of glyphs within a static single result image. %These glyphs can be calculated from the continuous pre-baked information.




