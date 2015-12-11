\section{Results and Discussion}

\begin{figure}[t]
\centering
\subfloat[]{\label{fig:res:gh0}\includegraphics[width=0.5\linewidth]{figures/res-gh0.eps}}
\subfloat[]{\label{fig:res:gh1}\includegraphics[width=0.5\linewidth]{figures/res-gh1.eps}}

\subfloat[]{\label{fig:res:gh2}\includegraphics[width=0.5\linewidth]{figures/res-gh2.eps}}
\subfloat[]{\label{fig:res:gh3}\includegraphics[width=0.5\linewidth]{figures/res-gh3.eps}}
\caption{\label{fig:res:gh}The cutaway molecules are indicated through the ghosting effect. (a) Part of the scene is removed by a clipping plane. (b) The amount of cutaway molecules has been decreased through the probabilistic clipping, which caused some of the cutaway molecules to be reintroduced into the scene. (c) The blood serum (red molecules) are removed by probabilistic clipping in the entire dataset. (d) A falloff function is used to gradually change the influence of the probabilistic clipping.}
\end{figure}

We applied our method to three different datasets to showcase the capabilities of our method. The first dataset is a model of an HIV particle in blood serum. In Figure \ref{fig:res:gh} we show an example of a single clipping plane used to reduce the concentration of the blood serum molecules, so that the HIV particle is visible. However, to avoid misleading the viewer about the actual concentration of the blood molecules, we apply ghosting effect. It illustrates what the actual concentration is, while the visual clutter caused by the blood serum is significantly reduced. Figure \ref{fig:res:gh} illustrates that this can be done in different ways according to the artistic vision.

\begin{figure}[t]
 \centering
 \includegraphics[width=0.5\linewidth]{figures/mycoplasma.eps}
 \caption{\label{fig:res:myco}Mycoplasma mycoides.}
\end{figure}

The second dataset to which we applied our method is a model of \emph{Mycoplasma mycoides}. Figure \ref{fig:res:myco} show how clipping object have been used to reduce visual clutter to illustrate the positions of the ribosomes (shown in blue) within the cell.

%\begin{figure}[t]
%\centering
%\subfloat[]{\label{fig:res:vsc0}\includegraphics[width=0.245\linewidth]{figures/res-vsc0.eps}}
%\hfill
%\subfloat[]{\label{fig:res:vsc1}\includegraphics[width=0.245\linewidth]{figures/res-vsc1.eps}}
%\hfill
%\subfloat[]{\label{fig:res:vsc2}\includegraphics[width=0.245\linewidth]{figures/res-vsc2.eps}}
%\hfill
%\subfloat[]{\label{fig:res:vsc3}\includegraphics[width=0.245\linewidth]{figures/res-vsc3.eps}}
%\caption{\label{fig:res:gh}View-space clipping.}
%\end{figure}

%\begin{figure*}[t]
%\centering

%\subfloat[]{\label{fig:res:w0}\includegraphics[width=0.25\linewidth]{figures/res-w0.eps}}
%\subfloat[]{\label{fig:res:w1}\includegraphics[width=0.25\linewidth]{figures/res-w1.eps}}
%\subfloat[]{\label{fig:res:w2}\includegraphics[width=0.25\linewidth]{figures/res-w2.eps}}
%\subfloat[]{\label{fig:res:w3}\includegraphics[width=0.25\linewidth]{figures/res-w3.eps}}

%\subfloat[]{\label{fig:res:w4}\includegraphics[width=0.25\linewidth]{figures/res-w4.eps}}
%\subfloat[]{\label{fig:res:w5}\includegraphics[width=0.25\linewidth]{figures/res-w5.eps}}
%\subfloat[]{\label{fig:res:w6}\includegraphics[width=0.25\linewidth]{figures/res-w6.eps}}
%\subfloat[]{\label{fig:res:w7}\includegraphics[width=0.25\linewidth]{figures/res-w7.eps}}
%\caption{\label{fig:res:w}W.}
%\end{figure*}

%\begin{figure}[t]
% \centering
% \includegraphics[width=\linewidth]{figures/results01.eps}
% \caption{\label{fig:results01}An illustration of the HIV virus in the %blood serum utilizing cutaways created with our approach.}
%\end{figure}
