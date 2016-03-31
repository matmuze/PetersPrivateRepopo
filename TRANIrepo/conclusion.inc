\vspace{-7pt}
\section{Conclusion}
\vspace{-2pt}
In this paper, we present a formal method for creating continuous transitions between two representations.
These target representations and transitions have historically been modeled and key-framed manually by illustrators and animators in 3D modeling tools.
Our method is described in the form of a pipeline, that creates and presents a continuum between two representations in seven stages based on a simple scripting interface. Representations and transitions can be created with a few lines of code and executed for arbitrary data sets, which is a huuuge improvement over the previous manual workflow for creating such representations.
Each stage of our pipeline supports a certain type of so called metamorphers, that are responsible for relating the original to the target representation for certain aspects of the continuum.
We implemented our method and showcased its flexibility based on three use cases that highlight certain aspects of a HIV data set, and we discussed further possible applications of the metamorphers that we provide.
%Our implementation offers a simple API that allows to access, parametrize, and combine the supported metamorphers.
Each pipeline stage can be extended with metamorphers to further increase the range of supported target states and transitions.
The metamorphers can then be applied to arbitrary molecular data sets.
In a discussion we describe how our approach can be applied to other data types and other visualization domains.
We gathered feedback from domain experts in illustration and animation that confirmed the benefit of our approach in respect to their habitual workflow.
