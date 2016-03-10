\section{Conclusion and Future Work}

In this paper, we presented a novel method for authoring cutaway illustrations of mesoscopic molecular models.
Our system uses clipping objects to selectively remove instances based on their type and location. 
To monitor and fine-tune the process, we introduce the visibility equalizer. 
It keeps the user informed about the number of molecular instances removed by the clipping objects, or occluded in the current viewport. 
Moreover, the visibility equalizer allows the users to directly override the behaviour of the clipping objects in order to fine-tune the visibility of molecular ingredients within the scene.

The visibility equalizer concept demonstrates a scenario where a visualization metaphor, such as the stacked bar chart in our case, can serve as a user interface for performing a specific task, in our case to manipulate 3D data to authorize cutaways. 
The proposed method allows the users to create comprehensive illustrations of static biological models in real-time.
This was confirmed by gathering feedback from domain experts. 
While the concept was applied to a specific domain, we also wish to develop other examples where the (information) visualization acts simultaneously as an interface to steer the view.

There are several follow-up ideas which we would like to focus on in the future, to strengthen data exploration and showcasing with cellVIEW.
Firstly, we would like to explore automatic clipping mechanisms to assist the user with the placement of clipping-objects based on the nature of the scene and shape analysis.
Secondly, we would also like to try our visibility equalizer concept with time-dependent datasets and enhance it to provide the means for authoring animations of clipped datasets.

Our Visibility Equalizer method is built on top of cellVIEW and Unity3D, which are both free to use for non-commercial use, the source code is publicly available, as well as the showcased scenes modelled with cellPACK (https://github.com/illvisation/cellVIEW).

 %, as well as by recreating existing illustrations with our method.
%While being simple to use, the method gives the user a considerable level of artistic freedom.
%The conceptual contribution of this work is demonstration of a scenario where a visualization metaphor, such as the stacked bar chart in our case, can serve as a user interface for performing a specific task, in our case authoring a cutaway design. 
%We expect to see further cases where the (information) visualization acts simultaneously as the user interface.
%During the whole authoring process, our method keeps the user informed about the ratios of the molecular instances removed by the clipping objects, or occluded from the current viewpoint. 

