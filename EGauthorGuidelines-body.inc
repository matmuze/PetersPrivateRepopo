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
   The ABSTRACT is to be in fully-justified italicized text, 
   between two horizontal lines,
   in one-column format, 
   below the author and affiliation information. 
   Use the word ``Abstract'' as the title, in 9-point Times, boldface type, 
   left-aligned to the text, initially capitalized. 
   The abstract is to be in 9-point, single-spaced type.
   The abstract may be up to 3 inches (7.62 cm) long. \\
   Leave one blank line after the abstract, 
   then add the subject categories according to the ACM Classification Index 
   (see http://www.acm.org/class/1998/).

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

%-------------------------------------------------------------------------

%\bibliographystyle{eg-alpha}
\bibliographystyle{eg-alpha-doi}

\bibliography{ref}

%-------------------------------------------------------------------------


\end{document}
