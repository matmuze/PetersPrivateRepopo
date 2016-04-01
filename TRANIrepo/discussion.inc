
\vspace{-5pt}
\section{Discussion and Future Work}
\label{sec:discuss}
\vspace{-2pt}
%[todo: thoughts on creation of the continuum vs presentation of the continuum]




		
%	compatible data types:		dense hierarchical data with lots of repeating entities  of a few dozen types
		


Our method allows the generation of transitions for arbitrary molecular data sets, which has the advantage that target representations and transitions do not have to be manually modeled and key-framed in a tool like Maya.
Our pipeline implementation offers a simple API for access and parametrization of the implemented metamorphers.
As demonstrated in the supplementary video, the scripted metamorphers can be simply reused for the use with different datasets.
The API can be extended with additional metamorphers that support further transitions and target representations, that can then again be applied to arbitrary molecular data.
Currently illustrators can access our API with a scripting interface, where metamorphers along the pipeline are called on subsets of the data with specific parametrizations.
The scripting does not pose a challenge to illustrators as they are used to high level scripting interfaces of tools such as Maya.
Nevertheless, we plan to implement a visual interface for our API so that also non-experts can plug metamorphers together with a few clicks.

%The ease of use and speed in generating results with our method has the tradeoff of sacrificing the flexibility the time consuming manual modeling these modeling tools supply with manual creation.

%Our pipeline is specifically designed to create continuous representations between two representation states. It is not meant to be used to produce movies, i.e., there is no explicit support for features like .. as they can be found in 3D modeling tools.However, theoretically the data restructuring stage could be exploited in such a way ...


%not supported:
%-interaction
%-full fledged animation
Since we designed our pipeline to produce visualizations for presentation purposes, we did not build it explicitly with interaction in mind.
It is built to produce static images or animation sequences.
%It does not consider interactions on a conceptual level.
However, the environment in which we implemented our method \cite{muzic15} natively supports user interactions as it is based on the Unity3D engine.
The formal pipeline, as well as the implementation could be extended to support user interactions, e.g., to make it applicable for interactive analysis.
Such an extension of our approach could allow user interactions, e.g., on the final representation, to create a partial transition of a selected subset back to the original representation.

At one point during the design of our formal pipeline, we were contemplating to add a stage for annotations to our pipeline, as they can assist story telling by describing what is currently happening in the scene. They can point to specific events in the transition to steer the viewer's attention. They can create frames of reference, such as coordinate axes, scales, and legends, that can improve the viewers' orientation within and their understanding of the presented information.
However, we decided to rather discuss them in this part of our paper, as they are orthogonal to what our pipeline is designed to do and therefore do not match the conceptual scope of our pipeline.
Further, the implementation of simple annotations, e.g., as billboards in the scene, is trivial, so we did not deem them as an essential contribution in the scope of our work.

Even though we described our pipeline only for the application with molecular data, it could be also applied on other data formats. %on a macro/micro/nano scale or across different scales
The molecular data is comparable with point cloud data on a non uniform grid. Point cloud and volume data are therefore supported out of the box if the matching data importer is supplied.
What these data formats have in common is that the geometric topologies of objects can be easily split up, e.g., as is the case when splitting a spherical structure along a plane.
In polygon data, the splitting of the geometric topology is not as trivial.
In order to make our pipeline compatible with polygonal data, the data restructuring stage would have to be extended with metamorphers that support topological changes of the mesh data.

While we only inspected our method from the perspective of molecular mesoscale data, our approach could also be applied to other application domains at different visualization scales, e.g., to explain physical phenomena.
Further, our approach could also be used to transition between different scales of data, such as in the work of Hsu et al. \cite{Correa:TOG:2011}.
Different scales of a data set could be managed in different hierarchy levels by the data re-structuring stage.
Each node of the hierarchy could be rendered with a different level of detail in the morphing stage.

Since our pipeline produces a continuum between two representations, it can be used out of the box to generate animations and narrative sequences (comic strips).
However, another interesting direction for future work would be to explore the possibilities that different sampling metamorphers could provide.
As we discussed in Section 3.2.4, our pipeline supports pre-calculated as well as real-time sampling for the presentation of the created continuum.
Real-time sampling could be explored in regard to possible applications for user interaction.
Concerning the pre-calculated continuum, we could investigate how to actually extract information about the change during a transition to substitute the missing information about motion within static glyphs. 
Further, the possible applications of the mentioned narrative sequence-animation hybrid could be explored.





		