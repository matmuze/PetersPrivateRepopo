% ---------------------------------------------------------------------
% EG author guidelines plus sample file for EG publication using LaTeX2e input
% D.Fellner, v1.17, Sep 23, 2010


\title[Context-Preserving Cutaways in Molecular Visualization]%
      {Context-Preserving Cutaways in Molecular Visualization}

% for anonymous conference submission please enter your SUBMISSION ID
% instead of the author's name (and leave the affiliation blank) !!
\author[M. Le Muzic et al.]
       {M. Le Muzic\thanks{mathieu@cg.tuwien.ac.at}$^{1}$,
        P. Mindek\thanks{mindek@cg.tuwien.ac.at}$^{1}$,
        and I. Viola\thanks{viola@cg.tuwien.ac.at}$^{1}$        
        \\
% For Computer Graphics Forum: Please use the abbreviation of your first name.
         $^1$TU Wien, Austria
%        $^2$ Another Department to illustrate the use in papers from authors
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

In the field of molecular biology, knowledge transfer is commonly carried out through schematic illustrations. Traditionally, illustrations of biological processes on the molecular level have been created by manual hand drawing. Nowadays, complex models of various biochemical structures and micro-organisms exist. These models can be utilized in creating computer-generated biological illustrations through various molecular-visualization algorithms. In this paper, we propose a method for enhancing real-time molecular-visualization algorithms with the capability to display cutaway views. Such an option is beneficial to biological illustrators, since the technique of cutaway display is ubiquitously applied in traditional illustration. In contrast with existing algorithms for creating cutaway views, we take advantage of the specific nature of the biochemical models, which consist of multiple instances of the same molecular type. By reintroducing some of these instances in the parts of the rendered illustration which has been cut away to reveal internal structures, we are able to preserve the context of the objects of interest.

\begin{classification} % according to http://www.acm.org/class/1998/
\CCScat{Computer Graphics}{I.3.3}{Picture/Image Generation}{Viewing algorithms}
\end{classification}

\end{abstract}





%-------------------------------------------------------------------------
\section{Introduction}

\section{Related Work}
\cite{Viola05}
\cite{Burns07}
\cite{Burns08}
\cite{Li07}
\cite{Lidal12}
\cite{cellVIEW_2015}

%-------------------------------------------------------------------------

%\bibliographystyle{eg-alpha}
\bibliographystyle{eg-alpha-doi}

\bibliography{ref}

%-------------------------------------------------------------------------


\end{document}
