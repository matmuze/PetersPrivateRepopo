\section{User Feedback}
%Our visualization technique have the versatility to be useful for both, scientific exploration of large bio-molecular scene, and educational purposes.
%Our technique has potential for assisting scientific exploration of large molecular scenes, but it also has potential for educational purposes.

We evaluated the usefulness of our tool by collecting informal user feedback from two domain experts in biological illustration and molecular biology, respectively.
In both cases, we did a remote walk-through introduction of our software, while collecting first impressions.
Additionally, we gave them an executable version of the software and asked them to write a short summary of their experience after trying the tool by themselves.
We first sent an early version of our tool to a biomedical illustrator with a strong academic background in chemistry. 
%He has 10 years of experience in the field of computer graphics and teaches online animation courses at CgSociety, with a focus on the creation of accurate biomolecular representations.
%He further gave computer graphics courses at his own institute (National research council of Italy), focusing on teaching basic skills in lighting and rendering to computer graphic novices.
His overall feedback was very positive, he enjoyed the responsiveness of the tool, and the novel concept of fuzziness and gradient clipping.
Here is a quote from his written feedback:

%I was really impressed by the quality of the non photo realistic toon rendering that can be achieved.
%It makes  the user able to create rendering of very complex scenes in few seconds that can be exported and tweaked for the final look in a composite software making the preproduction of high quality static rendering very fast
%I've never seen so far software that was able to manage with such a huge number of molecules/atoms without crashing.

\textit{``...in my opinion it can be a very useful toolkit for an illustrator in the biomedical field...It also seems very promising for interactive teaching and also for animation purposes...
One very useful feature of the software is the possibility to ``cut'' planes of interest of a particular space, and keeping the information of all ``layers'' by creating a ``gradient'' of concentration of the ingredients of the displayed molecular recipe. 
A visualization that resembles an ``exploded model'' but for biological assembly and it can be achieved without manually selecting every instance you would like to hide.''}

%which would be cumbersome to achieve with the tools he currently uses.
%Further, he was impressed with the responsiveness of the interactions with the visibility equalizer and the clipping planes.
%As a negative point, he mentioned the lack of exporting capabilities to mainstream animation packages such as Maya or Cinema 4D.

Secondly, we interviewed an expert in the domain of molecular biology and visualization. 
%His research focuses on the development and application of computational technologies to study the structure and function of biological molecules.
%His area of interest ranges from the design of therapeutic agents for AIDS, cancer and heart disease, to the development of novel algorithmic visualization and human interface approaches for molecular biology. 
%In nearly thirty years of experience, he has also contributed to a great number of molecular animations and visualizations that have appeared in popular books, magazines, newspapers and on television.
For this second interview the overall feedback was also quite positive.
He greatly enjoyed how easy and fast it was to perform clipping, and also enjoyed the polished user interface for manipulating the cut object parameters.
He also wished for several additional features to improve the usability of the tool, such as filtering based on biomolecular properties and rendering the ghosts of the clipped instances.
These features have since been implemented in the current version of the software, as seen in Figure \ref{fig:res:gh}.
Here is a quote from the written feedback we collected:

%This work provides a state-of-the-art and powerful interactive environment for visualizing and exploring  3D models of complex cellular environments with molecular detail. 
%Much of the problems in viewing and isolating various components of the model are assisted by the functions of this clipping environment. 
%Below are comments on some of the features and their utility

\textit{``...The aperture cutting feature is especially useful for exploring a feature or object in the context of a crowded molecular environment.
%The ability to shade the model with the aperture cut hightens the impression that the object being viewed is embedded in the volume.
%Without the shading, the object in the aperture appears to be floating above the surrounding environment when the model is interactively manipulated.
The ability to retain a subset of the clipped objects (``fuzzy clipping'') is an interesting feature that could be very useful under certain circumstances.
The feature is useful if one wants to get an impression of reducing the concentration of some of the molecular ingredients, or of what a gradient of certain molecular ingredients would look like.''}

%The approach would become even more useful if the selection of the unclipped objects could be based upon relationships between ingredients, such as retaining only selected molecules that are neighbors of one another.

%to improve how the tool could be employed more efficiently by his peers.
%The first wish was to add the possibility to filter molecules according to their biomolecular properties, such as the molecular weight or concentration.
%He also wished to see the ghosts of clipped instances in order to visually convey the proportions of removed elements in the 3D scene while preserving the current visibility setup.
%Additionally, he highly recommended us to add directional lighting to the scene in order to improve depth perception.

%To summarize, the evaluation showed that our equalizer-based approach for visibility specification was valuable and effective for both, scientific and educational purposes according to the opinion of domain experts.