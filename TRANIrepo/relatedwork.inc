\section{Related Work}
Animation and transitions between visual and data representations have been employed in many contexts. 
They serve as powerful tools for the dissemination of complex relations in space, time and abstract dimensions. 
They are frequently used in visual story telling and for the depiction of correspondences between data representations as well as visual representations. 

\subsection{Visual story telling}
Kosara and Mackinlay~\cite{Kosara:Computer:2013} note that for a long time the focus of visualization research was on exploration and analysis but that presentation of findings especially using elements of story telling should be a research focus of equal importance.
They list prominent examples of story telling that include animated transitions for trend analysis and dissemination.

Robertson et al.~\cite{Robertson:TVCG:2008} have looked at trend visualizations in depth. Three methods including animated transitions were analyzed. They found that animated transitions of data was reported to be more enjoyable and exciting to users. They also found that it was significantly faster when used for presentation but less exact and less effective for analyzing data. 
These results encouraged us to use animated transitions to facilitate presentation of complex molecular data. 

Segel and Heer~\cite{Segel:TVCG:2010} analyze story telling with narrative visualization and point out different approaches. They distinguish between author- and reader-driven elements in a narrative and speculate that "exploration of transitions between them presents an exciting area for researchers and practitioners". 
Along these lines Wohlfart and Hauser~\cite{Wohlfart:EuroVis:2007} presented a guided interactive volume visualization approach. Their system enables authoring and editing of visualization stories that give the user partial control over the exploration.

Ma et al.~\cite{Ma:CGA:2012} describe the need of new scientific visualization methods that can be used for scientific story telling. Among other issues they suggest that novel transitions between different coordinate systems are needed to address the overwhelming complexity involved in today's scientific story telling.

\subsection{Transitions between visual representations}
Kosara et al.~\cite{Kosara:VMV:2004} use 3D scatter plot matrices to establish a link between physical layout and the abstract dimensions of the data. Their work is an early attempt to connect information visualization and scientific visualization using points as data primitives.

Guilmaine et al.~\cite{Guilmaine:IWCAVI:2012} compare different animated transitions of tree structures. They find that hierarchical animation is better suited for tracking of changes.
Basch~\cite{Basch:2011:ATA} describes possibilities for animated transitions between volumetric rendering and abstract views like histograms and scatter plots. Heer and Robertson~\cite{Heer:TVCG:2007} show animated transitions between different visual representations of statistical data. These works make use of staging and staggering which are techniques that reduces occlusions and clutter. Our approach is based on these findings and formalizes animated transitions between spatial and abstract attributes.

Huron et al.~\cite{huron:TVCG:2013} present the visual sedimentation metaphor for the animation of data streams. This metaphor allows to transition from discrete visual elements to a continuous representation. 
We employ a similar metaphor for the transition of spatial objects to abstract charts.

Exploded views~\cite{Bruckner:2006:TVCG, Li:SIGGRAPH:2008, Karpenko:2010:TVCG} have been used in different contexts as a technique for illustrating  spatial or hierarchical relations of parts of an object. They are frequently used in animations or interactive systems and reported to be effective in the dissemination of complex layouts.
Our approach is similar to exploded views, since it animates the decomposition of the object into its parts. 
However, the spatial displacement is not only driven by the visibility of the individual parts, but also by additional data attributes. 


\subsection{Alternatives to animated transitions} 
Small multiples~\cite{Tufte:1990:EI}, coordinated multiple views, and static images in conjunction with annotations, traces and glyphs are alternatives that are typically used to visualize transitions, trends, correspondences or sequences~\cite{Robertson:TVCG:2008}.
Tversky et al.~\cite{Tversky:IJHCS:2002} summarize cognitive studies on the benefits of animation. 
Although, they conclude that animation alone has not been convincingly demonstrated to be superior to static illustrations, other findings of their study suggest a direction for research on animations in visualization.
They report that animation together with basic interaction methods like pausing, partial re-playing, zooming and change of perspective might be the key to enhance the effectiveness of animation.
Further, they acknowledge that the alternatives to animation (such as sequences of static illustration) are surprisingly hard to design and are therefore not an easy target for computer automation. 


%\textbf{Molecular Visualziation}: 
%\textbf{infographics:} assisted with glyphs and labels
%\textbf{small multiples: }represent essential snapshots (points) in time, static.
%while tversky argues, small multiples or static images can be as powerful in conveying the transition as animations, it is hard to design them so that they contain all the information that a viewer needs to follow along.
%e.g., in case of badly designed instruction manuals, users often switch to youtube video when they cannot follow the thread.			
%it is not really known, at which intervals / what kind of keyframes in the transition are essential to guarantee the viewer's understanding (true?).
%generally, it could be said, the less images are used in the small multiples - the more rich the information that they encode needs to be
%these go basically from analytical towards engaging \& from interactive towards non-interactive. the suitability of a method depends on the user's task / what he wants to achieve / to present.
	
	
	