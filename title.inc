\hyphenation{cellPack}

% ---------------------------------------------------------------------
% EG author guidelines plus sample file for EG publication using LaTeX2e input
% D.Fellner, v1.17, Sep 23, 2010


\title[Visibility Equalizer]%
      {-------- Visibility Equalizer --------\\ Cutaway Visualization of Mesoscopic Biological Models}

% for anonymous conference submission please enter your SUBMISSION ID
% instead of the author's name (and leave the affiliation blank) !!
\author[Le Muzic, Mindek et al.]
       {M. Le Muzic\thanks{Both first authors contributed equally. ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Contact: \{mathieu | mindek\}@cg.tuwien.ac.at}$^{1}$,
        P. Mindek$^{1}$,
        J. Sorger$^{1,2}$,
        L. Autin$^{3}$,
        and I. Viola$^{1}$        
        \\
% For Computer Graphics Forum: Please use the abbreviation of your first name.
         $^1$TU Wien, Austria \\
         $^2$VRVis Research Company, Austria \\
        $^3$ The Scripps Research Institute, La Jolla, California, USA
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
