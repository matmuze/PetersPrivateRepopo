
%% If you are submitting a paper to a conference for review with a double
%% blind reviewing process, please replace the value ``0'' below with your
%% OnlineID. Otherwise, you may safely leave it at ``0''.
\onlineid{0}

%% declare the category of your paper, only shown in review mode
\vgtccategory{Technique}

%% allow for this line if you want the electronic option to work properly
\vgtcinsertpkg

%% In preprint mode you may define your own headline.
%\preprinttext{To appear in an IEEE VGTC sponsored conference.}

%% Paper title.

\title{
--- Metamorphers ---\\A Formalization of Transitions in Illustrative Molecular Visualization
}
%% This is how authors are specified in the journal style
%% indicate IEEE Member or Student Member in form indicated below
\author{A, B, and C}
\authorfooter{
%% insert punctuation at end of each item
\item
 Author A is with Institute X. E-mail: a@x.com.
\item
 Author B is with Institute Y. E-mail: b@Y.com.
}

%other entries to be set up for journal
\shortauthortitle{Metamorphers}
%\shortauthortitle{Firstauthor \MakeLowercase{\textit{et al.}}: Paper Title}

%% Abstract section.
\abstract{
Illustrators in molecular biology often use animated transitions as a means to communicate complex phenomena.
While these animations are popular, they still have to be created manually in 3D modeling software. 
We therefore provide illustrators with a streamlined way for creating such transitions between various representations of molecular data.
We propose a formalization of the process of specifying transitions to arbitrary representations in the form of a conceptual pipeline.
Data representations are specified in such a way that they form a continuous space.
The first three stages of the pipeline are responsible for creating this continuum. The final four stages of the pipeline are responsible for presenting the continuum.
This continuum can be arbitrarily sampled in order to create a transition between two representations, e.g., densely, in the form of animation, or sparsely, in the form of small multiples.
We demonstrate our concept on exemplary use cases by creating multiple operators, so called metamorphers, for each pipeline stage. These metamorphers can be combined to achieve different types of transitions for arbitrary molecular data sets. We present three transitions that we designed in collaboration with illustrators, based on the data set of HIV: the explosion of inner and outer cellular compartments, a novel illustrative rendering approach for automatic schematization of mesoscopic data, and a transition to an infographic view, conveying quantitative relationships.
In a qualitative discussion of our results, we received positive feedback from domain experts in illustration.
} % end of abstract

%% Keywords that describe your work. Will show as 'Index Terms' in journal
%% please capitalize first letter and insert punctuation after last keyword
\keywords{Molecular Visualization, Illustrative Rendering, Animation.}

%% ACM Computing Classification System (CCS). 
%% See <http://www.acm.org/class/1998/> for details.
%% The ``\CCScat'' command takes four arguments.

\CCScatlist{ ..todo..
}
