% ---------------------------------------------------------------------
% EG author guidelines plus sample file for EG publication using LaTeX2e input
% D.Fellner, v1.17, Sep 23, 2010


\title[Visibility Equalizer]%
      {Visibility Equalizer}

% for anonymous conference submission please enter your SUBMISSION ID
% instead of the author's name (and leave the affiliation blank) !!
\author[M. Le Muzic et al.]
       {M. Le Muzic\thanks{mathieu@cg.tuwien.ac.at}$^{1}$,
        P. Mindek\thanks{mindek@cg.tuwien.ac.at}$^{1}$,
        J. Sorger\thanks{wochenplan@cg.tuwien.ac.at}$^{1}$,
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

In molecular biology and similar fields, knowledge transfer is commonly carried out through schematic illustrations. Traditionally, illustrations of biological processes on the molecular level have been created by manual hand drawing. Nowadays, complex models of various biochemical structures and micro-organisms exist. These models can be utilized in creating computer-generated biological illustrations through various molecular-visualization algorithms. In this paper, we propose a method for enhancing real-time molecular-visualization algorithms with the capability to display cutaway views. Such an option is beneficial to biological illustrators, since the technique of cutaway display is ubiquitously applied in traditional illustration. In contrast with existing algorithms for creating cutaway views, we take advantage of the specific nature of the biochemical models, which consist of multiple instances of the limited number of different molecular types. By reintroducing some of these instances in the cutaway parts of the rendered illustration, we are able to create comprehensible illustrations of complex models. The main contribution of this paper is an interaction mechanism which allows the illustrators to precisely control the amount of instances of different molecular types in the illustration, while maintaining the desired information value.

\begin{classification} % according to http://www.acm.org/class/1998/
\CCScat{Computer Graphics}{I.3.3}{Picture/Image Generation}{Viewing algorithms}
\end{classification}

\end{abstract}





%-------------------------------------------------------------------------
\section{Introduction}

In the field of molecular biology, micro-biology, and medicine, illustrations are essential for the inter- and intra-disciplinary knowledge transfer.
Over the years, illustrators invented various techniques for capturing specific aspects of the displayed objects and processes.
One of the most common methods utilized in the technical illustration are so-called \emph{cutaway views}.
When a cutaway view is applied, parts of the illustrated object are left out, such as if they were physically cut away.
In this way, internal structures, which are to be communicated by the illustration, can be shown.

There are several issues with using cutaway views in illustrations.
First one is that it has to be clear from the visual representation of the cut that the given part of the object has been removed artificially for the sake of illustration.
Otherwise the viewers might believe that the hole created by the cut is in fact inherent part of the object.
This is commonly solved by using specific shapes of the cuts which significantly differ from the shapes naturally occurring within the object (e.g., using circular cut on object which only have straight edges).

Another issue is that the information about the part of the object that is being cut away is lost.
In technical illustration, this issue is often circumvented by displaying contours of the cutaway part of the object.
Contours are not occluding the objects of interest, but at the same time they help to convey the overall shape of the cutaway part.

In molecular visualization, cutaway views can be applied to reveal structures hidden within large molecular models.
Here, the shape of the cutaway part is usually not crucial to preserve in the visualization.
It is rather the \emph{context} that might be lost when everything in front of the object of interest is cut away.
To preserve the context when applying cutaway views on molecular models, it is possible to exploit the fact that these models consist of individual entities, such as proteins or other molecules.
By removing most of the entities of the same type, which are occluding the object of interest, but leaving few of them on their original positions, we achieve a compromise - the object of interest is revealed, but the illustration is also communicating the fact that the entities of this particular type are present in the model.
An example is shown in Figure \ref{fig:hiv}.
Figure \ref{fig:hiv0} shows an illustration of a HIV virus.
In Figure \ref{fig:hiv1}, a cutaway view is used to reveal internal structures of the virus - capsid containing the DNA.
Some of the glycoproteins (yellow molecules on the surface of the virus) are left in the illustration to communicate their presence on the surface of the virus.
In particular, those glycoproteins which are not occluding the object of interest, were chosen to be kept in the illustration providing the contextual information.

\begin{figure}[t]
 \centering
 \subfloat[]{\label{fig:hiv0}\includegraphics[width=0.495\linewidth]{figures/hiv0.eps}}
 \subfloat[]{\label{fig:hiv1}\includegraphics[width=0.495\linewidth]{figures/hiv1.eps}}
 \caption{\label{fig:hiv}(a) Illustration of a HIV virus. (b) Cutaway view of the HIV virus. Despite the cutaway, some of the glycoproteins are kept in the view as context.}
\end{figure}

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
