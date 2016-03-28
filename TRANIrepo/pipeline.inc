\section{Metamorphosis formalization}

\begin{figure*}[t]
\centering
\subfloat[]{\label{fig:ov0}\includegraphics[width=0.33\linewidth]{figures/ov0.png}}
\subfloat[]{\label{fig:ov1}\includegraphics[width=0.33\linewidth]{figures/ov1.png}}
\subfloat[]{\label{fig:ov2}\includegraphics[width=0.33\linewidth]{figures/ov2.png}}
\caption{\label{fig:ov}The continuum between two representations describes the metamorphosis from one representation state to another: a) source and target representation. b) the continuum creation connects both representations. c) the continuum is restructured for presentation.}
\end{figure*}

The context of our research is an explanatory visualization of large-scale structural models of viruses and bacteri that conveys relationships between various abstracted or transformed visual representations of the models without any need for user interaction. Such visualization techniques can then be easily employed by scientific illustrators and animators for easily accessible and engaging content authoring for popularising and conveying science to non-expert audiences.

Each illustration which communicates a relationship starts with the two representations of the model. The first, source representation, is typically close to the mental model of the audience. The second, target representation illustrates different aspects of the presented model, but its relationship to the source representation might not be obvious. In that case, the illustrator needs to manually create the visual transition between the two representations. We present a method for creating continuum between two arbitrary model representations, or metamorphosis, and using it to illustrate the relationship between these representations. The metamorphosis is created automatically through describing the target representation, thus alleviating the illustrator from creating it manually.

Figure \ref{fig:ov0} shows the source and the target representations. They both communicate certain aspects of the model, but they are disconnected, their relationship is not immediately clear. Our pipeline consists two steps. In the first step, we create a continuous space between these representations. However, this low-level connection is not yet ready for illustrating the relationship between the representations (Figure \ref{fig:ov1}). Therefore, the second step of the pipeline prepares this continuum for the presentation to the intended audience (Figure \ref{fig:ov2}). In this step, the metamorphosis is finalized so that it illustrates the relationship between the source and the target representations.

The metamorphosis is carried out by applying a sequence of operators, which we refer to as \emph{metamorphers}.

%Each metamorpher belongs to one of the stages of a pipeline according to the task it is used to solve.

%For the clarity, the operators are grouped into several stages

\subsection{Continuum Creation}
In the first step of the pipeline, the continuum between two model representations is created. In this section, we describe the three stages of the continuum creation, with examples of metamorphers which can be used in these stages.

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
After the continuum between the two data representations is created, it needs to be processed so that it adequately communicates the intended message. This processing takes place within the second step of the pipeline, consisting of four stages.

\subsubsection{Trajectory}
While the layout stage of the pipeline defines the relationship between data elements in different data representations, the actual transition between them is not yet specified. It is necessary to define the trajectory along which the data elements move in order to transit from the source representation to the target one. This is done in the first stage of the continuum presentation step.

The trajectories are defined as arbitrary sets of control points between the source and target transformations of the data elements. These control points can form various curves along which the data elements move during the metamorphosis. The continuity of the spatial transformations is achieved through linear interpolation of the translations and scaling, and spherical linear interpolation of the rotations.

The metamorphers of the trajectory stage can be used to structure the transition, such as through edge-various bundling methods. For instance, the molecules of the same type can move to their target positions along similar paths in order to minimize the visual clutter created by the transition.

\subsubsection{Timing}
In order to present the transitions specified in the morphing and the layout stages to the viewers, illustrators need to create appropriate temporal arrangement for them. Such arrangement encodes the information about the chronology of the illustrated events. Additionally, illustrators use the speed at which individual transitions occur as means to suggest their importance for the communicated message, as well as to draw viewers attention to different parts of the illustration.

The temporal arrangement is designed through metamorphers of the timing stage. They operate on so called \emph{time curves} associated with each node in the scene graph. These curves are used as transformations of the data elements' positions within their specified trajectories as functions of time.

The metamorphers are used to specify the starting time of each transformation, as well as its speed. As such, they can be used to create various temporal effects, e.g., ease-in or ease-out curves for the movement of the data elements or entire data subsets. The time curves can be also modified to make some of the elements stop in the middle of the specified trajectory, or to reverse their movement.

%Additionally, the speed at which individual transitions occur might be used by the illustrators to suggest importance of the individual events and 

\subsubsection{Camera Control}
To adequately follow the development of continuous transitions, especially those between different visualization spaces, camera steering is a necessary component of a non-interactive explanatory visualization. To assure visibility of all data elements at each timestep, illustrators manually specify camera settings and how they change over time.

In our pipeline, this task is carried out through the metamorphers in the \emph{camera control} stage. These metamorphers access the temporally and spatially arranged data elements and use this information to automatically modify the position and the look-at vector of the camera. An example of camera control metamorpher sets the look-at vector of the camera to point in the centroid of the data elements, while it moves the camera far enough to capture the entire dataset for the given field-of-view.

\subsubsection{Sampling}
To present the created transition to the viewers, it is necessary to select a set of timesteps which are going to tell the story intended by the illustrators. In the simplest case, the transition is sampled densely enough to form a seamless animation, given certain FPS and a desired length of the animation. However, due to various disadvantages of animation, as discussed in Section \ref{sec:intro}, it might be necessary to select only few representative timesteps which show the essential aspects of the transition.

Metamorphers of the \emph{sampling} stage implement various strategies how these timesteps are chosen. While the previous stages of the pipeline can be called multiple times in order to create more complex animations/transitions/stories, the sampling stage is final, as it ties together the information from the previous stages to sample the visual result.

For this purpose, the scene graph information is propagated through the hierarchy down to the individual data elements, to determine their absolute positions and orientations. The trajectory and the timing stages of the pipeline provide the information about the intermediate transformations of the data elements in an arbitrary timestep, which is in turn acquired by the sampling metamorphers.

Since the operators applied in the previous stages of the pipeline are continuous, there are no restrictions on how the sampling is performed. For instance, it is possible to create a hybrid visualization that displays a sparsely sampled narrative sequence of small multiples. Upon request, a continuous animated transition between two consecutive small multiples can be shown to provide additional information on how do they relate to each other.

The sampling stage can also determine if the transition is pre-baked or sampled on the fly in real-time.
This makes it possible to use a continuous pre-baked transition to create, for instance, a single result image that encodes the missing transition information within glyphs. These glyphs can be calculated from the continuous pre-baked information.



\begin{figure*}[ht!]
\centering
 \includegraphics[height=5cm, width=\linewidth]{figures/metamorphers.png}
\caption{\label{fig:spaces}Examples of different metamorphers: a) shape morphing, b) blurring, c) time offset, d) some layout}
\end{figure*}














