

\section{Discussion and Future Work}



high level tasks: occlusion handling, steering of attention, stimuli reduction

occlusion handling
steering of visual stimuli

		
	compatible data types:
		dense hierarchical data with lots of repeating entities  of a few dozen types
		

%not supported:
%-interaction
%-full fledged animation
Since we designed our pipeline to produce visualizations for presentation purposes, we did not build it explicitly with interaction in mind.
It is built to produce static images.
%It does not consider interactions on a conceptual level.
The environment in which we implemented our method, however (cellVIEW), natively supports user interactions as it is based on the Unity3D engine.
The formal pipeline, as well as the implementation could be extended to support user interactions.
Our plan for future work is actually to allow user interactions on the final representation, e.g., to create a partial transition of a selected subset back to the original representation.

Our pipeline is specifically designed to create continuous representations between two representation states. It is not meant to be used to produce movies, i.e., there is no explicit support for features like .. as they can be found in 3D modeling tools.
However, theoretically the data restructuring stage could be exploited in such a way 

At one point during the design of our formal pipeline, we were contemplating to add a stage for annotations to our pipeline, as they can assist story telling by describing what is currently happening in the scene. They can point to specific events in the transition to steer the viewer's attention. They can create frames of reference, such as coordinate axes, scales, and legends, that can improve the viewers' orientation within and their understanding of the presented information.
However, we decided to rather discuss them in this part of our paper, as they are orthogonal to what our pipeline is designed to do and therefore do not match the conceptual scope of our pipeline.
Further, the implementation of simple annotations, e.g., as billboards in the scene, is trivial, so we did not deem them as an essential contribution in the scope of our work.

Even though we described our pipeline only for the application with molecular data, it could be also applied on other data formats and other application domains, e.g., to explain physical phenomena. %on a macro/micro/nano scale or across different scales
The molecular data is comparable with point cloud data on a non uniform grid. Point cloud and volume data are therefore supported out of the box if the matching data importer is supplied.
What these data formats have in common is that the geometric topologies of objects can be easily split up, e.g., as is the case when splitting a spherical structure along a plane.
In polygon data, the splitting of the geometric topology is not as trivial.
In order to make our pipeline compatible with polygonal data, the data restructuring stage would have to be extended with metamorphers that support topological changes of the mesh data.


transitions across different scales (meso - nano)





	side products of our pipeline - free of charge / easily achievable with minimal additional effort:
	sequence: comic strips,
	static image with glyph







future work:
authoring tool
extraction of motion for glyphs
implementation of comic strip / animation hybrid






	


	
\subsection{occlusion}

	is of course a central factor that could hinder a user's understanding of a transition.
	can be dealt with at various stages of the pipeline.
		grouping: choose groups so that they dont interfere with each other (depending on how you plan to transform the data)
			TODO: come up with examples that describe which kind of grouping would be beneficial for which kind of target state
				e.g., group the data first into layers parallel to the viewing plane that basically peel the data
		layouts
			inner
				bar: within the bar occlusion does not matter, as long as the bar represents entities of the exact same type
				todo: other inner layouts \& general
			outer
				general: the placement of entities/subests should be chosen so that they dont occlude each other from the viewing angle. 
			maybe we should not distinguish between inner and outer layout since this kind of restricts us to having two layouts instead of n.

then again, we could argue that there can be n-outer layouts, and one inner layout
		morphing:
			same as inner layout: within the shape occlusion is not an issue
			
		trajectory:
			the trajectories offer two of techniques for avoiding occlusion.
			
				edge bundling:
				setting control points so that paths don't occlude each other
				todo: anything else?
				
		timing:
			coordination of timing and speed of elements, e.g., staging

		