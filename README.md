# Radical <-> Unreal Live Link Remap Plugin

This plugin contains retargeting assets for converting animation output from RADiCAL Studio to an Unreal Engine editor session. It will receive data from a local RADiCAL Studio session, either on the same computer or over the local network.

## Initial Setup Instructions

To install, download the latest release for your engine version on the right side bar and unzip to your project or engine Marketplace folder, then enable the plugin in your project.

After starting the Live Link stream from Radical Studio, open the UE4 editor and go to Window -> Live Link. Go to Source -> Message Bus Source -> select the `RadLiveLink` source. There will be a random alphanumeric string appended to the name, to differentiate between multiple Live Link sources on the network (e.g. other instances of Radical Studio). You can now close this window.

## Live Link Preview

The Live Link data can be previewed inside the Skeleton, Skeletal Mesh, Blueprint or Animation Blueprint windows for a given skeletal asset. On the right side, go to Preview Scene Settings, under Animation, change the Preview Controller to Live Link Preview Controller. Then, change the Live Link Subject Name to `RadicalPose`.

For Retarget Asset, select the corresponding blueprint Remap Asset file for that skeleton. For example, for the Radical skeleton, choose the `RadToRadRemap` asset. For the Epic skeleton, choose the `BP_RadToEpicRemapAsset`. Assuming the target character uses an Epic skeleton, it should look as follows:
![Live Link Preview Setup](GALLERY_IMAGES/LiveLinkPreviewController.png)

## Live Link Source in AnimBP

To apply the incoming animation data to the characters in the scene, go to the AnimBP for the character and create a Live Link Pose node. Select the a) Live Link Subject Name and b) the Retarget Asset, like so:
![Live Link Pose node setup](GALLERY_IMAGES/LiveLinkPose.png)

Because of the difference between the RADiCAL skeleton (which defaults to a T pose) and the Unreal skeleton (which defaults to an A pose) we have to apply some rotations at the shoulder. Refer to the `AnimBP_EpicGames_Mannequin` AnimGraph and copy these transform nodes to your character:
![Transform Bone nodes](GALLERY_IMAGES/TransformBones.png)

## Rotation conversions

To account for some of the differences between the Radical Studio coordinate frame and Unreal, we have flipped the incoming LiveLink data's rotation and position axes. If you want to delve into the source C++, you can inspect the conversions at the `RadicalLiveLinkRemapAssetBase` class and its child classes. We expect that other skeletons will require different rotation adjustments, including swapping axes. We exposed three overridable methods to implement the root bone position, root bone rotation, and non-root bone rotation conversions. Please note that the AI output in Radical Studio uses the hip bone as a root, so position data should be mapped to the hips (or pelvis) in the target skeleton.
