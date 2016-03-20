
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

\title{TRANNI -- TRANsitions aNImated: A Formalization of Animated Transitions in Illustrative Molecular Visualization}

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
\shortauthortitle{TRANNI -- TRANsitions aNImated}
%\shortauthortitle{Firstauthor \MakeLowercase{\textit{et al.}}: Paper Title}

%% Abstract section.
\abstract{
Illustrators in molecular biology use animation as a means to convey
complex phenomena in a way that is engaging as well as intuitively
understandable for a broad range of audiences.
Depending on what kind of information they want to convey, they have to
transform this complex data into more representative forms, for instance,
by simplifying structures to reveal their shape or by encoding inherent
quantities and relations in charts or graphs.
To support the understanding of how the transformed data relates to the
original, they convey this transition in a continuous way, with animated
transitions.
While these animations are popular, they still have to be created manually in
3D modeling software.

We therefore provide illustrators with a more streamlined way for creating
these continuous representations by presenting a formalization of animated
transitions in illustrative molecular visualization. Our method is based
on a seven component pipeline that presents our primary contribution.
Our secondary contribution is a proof-of-concept implementation of this
pipeline. We created multiple operators for each pipeline stage that can
be combined to achieve different types of transitions for arbitrary
molecular data sets.
One of these transitions that we designed in collaborations with
illustrators, is a novel illustrative rendering approach for automatic
schematization of mesoscopic data.
} % end of abstract

%% Keywords that describe your work. Will show as 'Index Terms' in journal
%% please capitalize first letter and insert punctuation after last keyword
\keywords{...todo..}

%% ACM Computing Classification System (CCS). 
%% See <http://www.acm.org/class/1998/> for details.
%% The ``\CCScat'' command takes four arguments.

\CCScatlist{ ..todo..
}
