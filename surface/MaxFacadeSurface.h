// GENERATED - DO NOT EDIT.
// Edits here are overwritten. Change the facade entry table and regenerate.
//
// THE 3DS MAX SDK MCP FACADE SURFACE INDEX - names only, for grepping and for #ifdef.
//
// THIS IS AN INDEX, NOT THE CONTRACT. It declares no prototypes and no ABI offsets, and
// including it gets you nothing to call. The callable contract is MaxFacadeApi.h, which
// arrives with the installed plugin so that the header you compile against and the binary
// you call cannot be different versions.
//
// What it is for: answering 'does the facade reach X?' from a checkout, with grep, and
// telling an absence apart from a refusal. Every entry appears twice - once in the X-macro
// list, once as a MAXMCP_FACADE_HAS_<Name> define - so both of these work:
//
//     grep GizmoShapeAppendPolyline surface/MaxFacadeSurface.h
//     #ifdef MAXMCP_FACADE_HAS_GizmoShapeAppendPolyline
//
// and the deliberate ABSENCES are listed at the bottom, with their reasons, because an
// empty grep cannot tell you which of four different things it means.
//
// If what you need is not here, that is a feature request - not a reason to reach for the
// 3ds Max SDK from a cartridge. See LAW.md and docs/FEATURE_REQUESTS.md.

#ifndef MAXMCP_FACADE_SURFACE_H
#define MAXMCP_FACADE_SURFACE_H

#define MAXMCP_FACADE_SURFACE_ABI 188
#define MAXMCP_FACADE_SURFACE_COUNT 5430

// X(Name, "family", "returns", "argument notation")
#define MAXMCP_FACADE_SURFACE(X) \
    X(SceneRoot, "Scene", "node", "") \
    X(NodeChildCount, "Node", "int32", "node Node") \
    X(NodeChild, "Node", "node", "node Node, int32 Index") \
    X(NodeName, "Node", "result", "node Node, mutstr OutName, size Capacity") \
    X(NodeSelected, "Node", "int32", "node Node, ptr:result OutResult") \
    X(NodeFaceCounts, "Node", "result", "node Node, int32 Time, ptr:MaxMcpFaceCounts OutCounts") \
    X(CurrentTime, "Current", "int32", "") \
    X(LightCreate, "Light", "node", "int32 Type, cstr Name") \
    X(LightRead, "Light", "result", "node Node, int32 Time, ptr:MaxMcpLight OutLight") \
    X(LightWrite, "Light", "result", "node Node, int32 Time, cptr:MaxMcpLight Light") \
    X(LightExcludedName, "Light", "result", "node Node, int32 Index, mutstr OutName, size Capacity") \
    X(NodeDelete, "Node", "result", "node Node") \
    X(NodeTransformRead, "Node", "result", "node Node, int32 Time, ptr:MaxMcpTransform OutTransform") \
    X(NodeTransformWrite, "Node", "result", "node Node, int32 Time, cptr:MaxMcpTransform Transform") \
    X(CameraCreate, "Camera", "node", "int32 Type, cstr Name") \
    X(CameraRead, "Camera", "result", "node Node, int32 Time, ptr:MaxMcpCamera OutCamera") \
    X(CameraWrite, "Camera", "result", "node Node, int32 Time, cptr:MaxMcpCamera Camera") \
    X(ShapeCreate, "Shape", "node", "cstr Name") \
    X(ShapeLineCount, "Shape", "int32", "node Node, int32 Time") \
    X(ShapeLineRead, "Shape", "result", "node Node, int32 Time, int32 Index, ptr:MaxMcpShapeLine OutLine") \
    X(ShapePointsRead, "Shape", "result", "node Node, int32 Time, int32 Index, ptr:MaxMcpShapePoint OutPoints, size Capacity, ptr:int32 OutWritten") \
    X(ShapeClear, "Shape", "result", "node Node") \
    X(ShapeLineAppend, "Shape", "int32", "node Node, cptr:MaxMcpShapePoint Points, size Count, int32 Closed") \
    X(HelperCreate, "Helper", "node", "cstr Name") \
    X(HelperRead, "Helper", "result", "node Node, int32 Time, ptr:MaxMcpHelper OutHelper") \
    X(HelperClassName, "Helper", "result", "node Node, mutstr OutName, size Capacity") \
    X(MeshColorCounts, "Mesh", "result", "node Node, int32 Time, ptr:MaxMcpMeshColors OutCounts") \
    X(MeshColorVertsRead, "Mesh", "result", "node Node, int32 Time, ptr:MaxMcpColorVertex OutColors, size Capacity, ptr:int32 OutWritten") \
    X(MeshColorFacesRead, "Mesh", "result", "node Node, int32 Time, ptr:MaxMcpColorFace OutFaces, size Capacity, ptr:int32 OutWritten") \
    X(MeshColorWrite, "Mesh", "result", "node Node, cptr:MaxMcpColorVertex Colors, size ColorCount, cptr:MaxMcpColorFace Faces, size FaceCount") \
    X(NodeMaterial, "Node", "anim", "node Node") \
    X(NodeWireColor, "Node", "result", "node Node, ptr:float OutRgb") \
    X(NodeSetMaterial, "Node", "result", "node Node, anim Material") \
    X(MaterialCreate, "Material", "anim", "cstr Name") \
    X(MaterialRead, "Material", "result", "anim Material, int32 Time, ptr:MaxMcpMaterial OutMaterial") \
    X(MaterialWrite, "Material", "result", "anim Material, int32 Time, cptr:MaxMcpMaterial Material_") \
    X(MaterialName, "Material", "result", "anim Material, mutstr OutName, size Capacity") \
    X(MaterialSetName, "Material", "result", "anim Material, cstr Name") \
    X(MaterialClassName, "Material", "result", "anim Material, mutstr OutName, size Capacity") \
    X(MaterialSubMaterial, "Material", "anim", "anim Material, int32 Index") \
    X(MaterialSetSubMaterial, "Material", "result", "anim Material, int32 Index, anim SubMaterial") \
    X(MaterialSubTexmap, "Material", "anim", "anim Material, int32 Index") \
    X(MaterialSetSubTexmap, "Material", "result", "anim Material, int32 Index, anim Texmap") \
    X(MaterialMapEnabled, "Material", "int32", "anim Material, int32 Index") \
    X(MaterialMapAmount, "Material", "float", "anim Material, int32 Index, int32 Time") \
    X(TexmapCreateBitmap, "Texmap", "anim", "cstr FileName") \
    X(TexmapRead, "Texmap", "result", "anim Texmap, int32 Time, ptr:MaxMcpTexmap OutTexmap") \
    X(TexmapWrite, "Texmap", "result", "anim Texmap, int32 Time, cptr:MaxMcpTexmap Texmap_") \
    X(TexmapName, "Texmap", "result", "anim Texmap, mutstr OutName, size Capacity") \
    X(TexmapSetName, "Texmap", "result", "anim Texmap, cstr Name") \
    X(TexmapClassName, "Texmap", "result", "anim Texmap, mutstr OutName, size Capacity") \
    X(TexmapBitmapName, "Texmap", "result", "anim Texmap, mutstr OutName, size Capacity") \
    X(TexmapSetBitmapName, "Texmap", "result", "anim Texmap, cstr FileName") \
    X(TexmapSubTexmap, "Texmap", "anim", "anim Texmap, int32 Index") \
    X(TexmapSetSubTexmap, "Texmap", "result", "anim Texmap, int32 Index, anim SubTexmap") \
    X(TexmapUVGenRead, "Texmap", "result", "anim Texmap, int32 Time, ptr:MaxMcpUVGen OutUVGen") \
    X(TexmapUVGenWrite, "Texmap", "result", "anim Texmap, int32 Time, cptr:MaxMcpUVGen UVGen") \
    X(SceneEnvironmentMap, "Scene", "anim", "") \
    X(SceneSetEnvironmentMap, "Scene", "result", "anim Texmap") \
    X(NodeTMController, "Node", "anim", "node Node") \
    X(ControllerSubController, "Controller", "anim", "anim Controller, int32 Which") \
    X(NodeVisibilityController, "Node", "anim", "node Node") \
    X(SceneBackgroundController, "Scene", "anim", "") \
    X(SceneAmbientController, "Scene", "anim", "") \
    X(ControllerRead, "Controller", "result", "anim Controller, ptr:MaxMcpController OutController") \
    X(ControllerKeyRead, "Controller", "result", "anim Controller, int32 Index, ptr:MaxMcpKey OutKey") \
    X(ControllerKeyWrite, "Controller", "result", "anim Controller, int32 Index, cptr:MaxMcpKey Key") \
    X(ControllerKeyAppend, "Controller", "int32", "anim Controller, cptr:MaxMcpKey Key") \
    X(ControllerKeyDelete, "Controller", "result", "anim Controller, int32 Index") \
    X(NodeSampleRead, "Node", "result", "node Node, int32 Time, ptr:MaxMcpSample OutSample") \
    X(ControllerClassName, "Controller", "result", "anim Controller, mutstr OutName, size Capacity") \
    X(ControllerTimeRange, "Controller", "result", "anim Controller, ptr:int32 OutStart, ptr:int32 OutEnd") \
    X(ControllerValueFloat, "Controller", "result", "anim Controller, int32 Time, ptr:float OutValue, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(ControllerValuePoint3, "Controller", "result", "anim Controller, int32 Time, ptr:float OutValue, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(SceneAnimRange, "Scene", "result", "ptr:int32 OutStart, ptr:int32 OutEnd") \
    X(CameraValidity, "Camera", "result", "node Node, int32 Time, ptr:int32 OutStart, ptr:int32 OutEnd") \
    X(LightValidity, "Light", "result", "node Node, int32 Time, ptr:int32 OutStart, ptr:int32 OutEnd") \
    X(NodeObjectValidity, "Node", "result", "node Node, int32 Time, ptr:int32 OutStart, ptr:int32 OutEnd") \
    X(MaterialHasMapControls, "Material", "int32", "anim Material") \
    X(CameraTargetDistanceRaw, "Camera", "float", "node Node, int32 Time") \
    X(decomp_affine, "decomp_affine", "result", "cptr:float Matrix, ptr:MaxMcpAffineParts OutParts") \
    X(comp_affine, "comp_affine", "result", "cptr:MaxMcpAffineParts Parts, ptr:float OutMatrix") \
    X(invert_affine, "invert_affine", "result", "cptr:MaxMcpAffineParts Parts, ptr:MaxMcpAffineParts OutParts") \
    X(SpectralDecomp, "Spectral", "result", "cptr:float Matrix, ptr:float OutScale, ptr:float OutQuat") \
    X(QFromAngAxis, "QFrom", "result", "float Angle, cptr:float Axis, ptr:float OutQuat") \
    X(AngAxisFromQ, "Ang", "result", "cptr:float Quat, ptr:float OutAxisAngle") \
    X(QuatInverse, "Quat", "result", "cptr:float Quat, ptr:float OutQuat") \
    X(QuatConjugate, "Quat", "result", "cptr:float Quat, ptr:float OutQuat") \
    X(QuatLogN, "Quat", "result", "cptr:float Quat, ptr:float OutQuat") \
    X(QuatExp, "Quat", "result", "cptr:float Quat, ptr:float OutQuat") \
    X(QuatMultiply, "Quat", "result", "cptr:float A, cptr:float B, ptr:float OutQuat") \
    X(QuatDivide, "Quat", "result", "cptr:float A, cptr:float B, ptr:float OutQuat") \
    X(QuatNormalize, "Quat", "result", "cptr:float Quat, ptr:float OutQuat") \
    X(QuatIsIdentity, "Quat", "int32", "cptr:float Quat") \
    X(QuatMakeClosest, "Quat", "result", "cptr:float Quat, cptr:float To, ptr:float OutQuat") \
    X(AngAxisGetNumRevs, "Ang", "int32", "cptr:float AxisAngle") \
    X(AngAxisSetNumRevs, "Ang", "result", "cptr:float AxisAngle, int32 Revolutions, ptr:float OutAxisAngle") \
    X(Slerp, "Slerp", "result", "cptr:float P, cptr:float Q, float T, ptr:float OutQuat") \
    X(QCompA, "QComp", "result", "cptr:float Previous, cptr:float Quat, cptr:float Next, ptr:float OutQuat") \
    X(Squad, "Squad", "result", "cptr:float P, cptr:float A, cptr:float B, cptr:float Q, float T, ptr:float OutQuat") \
    X(qorthog, "qorthog", "result", "cptr:float P, cptr:float Axis, ptr:float OutQuat") \
    X(squadrev, "squadrev", "result", "float Angle, cptr:float Axis, cptr:float P, cptr:float A, cptr:float B, cptr:float Q, float T, ptr:float OutQuat") \
    X(QangAxis, "Qang", "float", "cptr:float P, cptr:float Q, ptr:float OutAxis") \
    X(TransformQuat, "Transform", "result", "cptr:float Matrix, cptr:float Quat, ptr:float OutQuat") \
    X(QuatToEuler, "Quat", "result", "cptr:float Quat, int32 Type, int32 Flag, ptr:float OutAngles") \
    X(EulerToQuat, "Euler", "result", "cptr:float Angles, int32 Type, ptr:float OutQuat") \
    X(MatrixToEuler, "Matrix", "result", "cptr:float Matrix, int32 Type, int32 Flag, ptr:float OutAngles") \
    X(EulerToMatrix, "Euler", "result", "cptr:float Angles, int32 Type, ptr:float OutMatrix") \
    X(ContinuousQuatToEuler, "Continuous", "result", "cptr:float Quat, int32 Type, ptr:float OutAngles") \
    X(GetEulerQuatAngleRatio, "Get", "float", "cptr:float QuatA, cptr:float QuatB, ptr:float OutEulerA, ptr:float OutEulerB, int32 Type") \
    X(GetEulerMatAngleRatio, "Get", "float", "cptr:float MatrixA, cptr:float MatrixB, ptr:float OutEulerA, ptr:float OutEulerB, int32 Type") \
    X(RotateXMatrix, "Rotate", "result", "float Angle, ptr:float OutMatrix") \
    X(RotateYMatrix, "Rotate", "result", "float Angle, ptr:float OutMatrix") \
    X(RotateZMatrix, "Rotate", "result", "float Angle, ptr:float OutMatrix") \
    X(RotateYPRMatrix, "Rotate", "result", "float Yaw, float Pitch, float Roll, ptr:float OutMatrix") \
    X(RotAngleAxisMatrix, "Rot", "result", "cptr:float Axis, float Angle, ptr:float OutMatrix") \
    X(TransMatrix, "Trans", "result", "cptr:float Translation, ptr:float OutMatrix") \
    X(ScaleMatrix, "Scale", "result", "cptr:float Scale, ptr:float OutMatrix") \
    X(MatrixInverse, "Matrix", "result", "cptr:float Matrix, ptr:float OutMatrix") \
    X(InverseHighPrecision, "Inverse", "result", "cptr:float Matrix, ptr:float OutMatrix") \
    X(PseudoInverse, "Pseudo", "result", "cptr:float Matrix, ptr:float OutMatrix") \
    X(AffineTranspose, "Affine", "result", "cptr:float Matrix, ptr:float OutMatrix") \
    X(MatrixMultiply, "Matrix", "result", "cptr:float A, cptr:float B, ptr:float OutMatrix") \
    X(XFormMat, "XForm", "result", "cptr:float Space, cptr:float Matrix, ptr:float OutMatrix") \
    X(MatrixTransformPoint, "Matrix", "result", "cptr:float Matrix, cptr:float Point, ptr:float OutPoint") \
    X(VectorTransform, "Vector", "result", "cptr:float Matrix, cptr:float Vector, ptr:float OutVector") \
    X(RotateMatrix, "Rotate", "result", "cptr:float Matrix, cptr:float Quat, ptr:float OutMatrix") \
    X(PreRotateMatrix, "Pre", "result", "cptr:float Matrix, cptr:float Quat, ptr:float OutMatrix") \
    X(MatrixHasNegativeParity, "Matrix", "int32", "cptr:float Matrix") \
    X(RGBtoHSV, "RG", "result", "cptr:float Rgb, ptr:float OutHsv") \
    X(HSVtoRGB, "HS", "result", "cptr:float Hsv, ptr:float OutRgb") \
    X(HSVtoRGBInt, "HS", "uint32", "int32 H, int32 S, int32 V") \
    X(GetTicksPerFrame, "Get", "int32", "") \
    X(GetFrameRate, "Get", "int32", "") \
    X(GetSystemUnitScale, "Get", "double", "int32 Type") \
    X(GetRelativeScale, "Get", "double", "int32 FromType, float FromScale, int32 ToType, float ToScale") \
    X(IsValidUnitCharacter, "IsValid", "int32", "int32 Character") \
    X(FormatUniverseValue, "Format", "result", "float Value, mutstr OutText, size Capacity") \
    X(DecodeUniverseValue, "Decode", "float", "cstr Text, ptr:int32 OutValid") \
    X(TimeToString, "Time", "result", "int32 Time, mutstr OutText, size Capacity") \
    X(StringToTime, "String", "result", "cstr Text, ptr:int32 OutTime") \
    X(NodeBaseObject, "Node", "anim", "node Node") \
    X(NodeEvaluatedObject, "Node", "anim", "node Node, int32 Time") \
    X(MeshVertexCount, "Mesh", "int32", "anim Object") \
    X(MeshFaceCount, "Mesh", "int32", "anim Object") \
    X(setNumVerts, "set", "result", "anim Object, int32 Count, int32 Keep, int32 Shrink") \
    X(setNumFaces, "set", "result", "anim Object, int32 Count, int32 Keep, int32 Shrink") \
    X(MeshVertsRead, "Mesh", "result", "anim Object, ptr:float OutVerts, size Capacity, ptr:int32 OutWritten") \
    X(MeshVertsWrite, "Mesh", "result", "anim Object, cptr:float Verts, size Count") \
    X(MeshFacesRead, "Mesh", "result", "anim Object, ptr:MaxMcpFace OutFaces, size Capacity, ptr:int32 OutWritten") \
    X(MeshFacesWrite, "Mesh", "result", "anim Object, cptr:MaxMcpFace Faces, size Count") \
    X(getMatID, "get", "int32", "anim Object, int32 Face") \
    X(setMatID, "set", "result", "anim Object, int32 Face, int32 Material") \
    X(getEdgeVis, "get", "int32", "anim Object, int32 Face, int32 Edge") \
    X(setEdgeVis, "set", "result", "anim Object, int32 Face, int32 Edge, int32 Visible") \
    X(getNumMaps, "get", "int32", "anim Object") \
    X(setNumMaps, "set", "result", "anim Object, int32 Count, int32 Keep") \
    X(mapSupport, "map", "int32", "anim Object, int32 Channel") \
    X(setMapSupport, "set", "result", "anim Object, int32 Channel, int32 Support, int32 Keep") \
    X(getNumMapVerts, "get", "int32", "anim Object, int32 Channel") \
    X(setNumMapVerts, "set", "result", "anim Object, int32 Channel, int32 Count, int32 Keep") \
    X(getNumMapFaces, "get", "int32", "anim Object, int32 Channel") \
    X(setNumMapFaces, "set", "result", "anim Object, int32 Channel, int32 Count, int32 Keep") \
    X(MeshMapVertsRead, "Mesh", "result", "anim Object, int32 Channel, ptr:float OutVerts, size Capacity, ptr:int32 OutWritten") \
    X(MeshMapVertsWrite, "Mesh", "result", "anim Object, int32 Channel, cptr:float Verts, size Count") \
    X(MeshMapFacesRead, "Mesh", "result", "anim Object, int32 Channel, ptr:MaxMcpColorFace OutFaces, size Capacity, ptr:int32 OutWritten") \
    X(MeshMapFacesWrite, "Mesh", "result", "anim Object, int32 Channel, cptr:MaxMcpColorFace Faces, size Count") \
    X(buildNormals, "build", "result", "anim Object") \
    X(checkNormals, "check", "result", "anim Object, int32 Illuminate") \
    X(FlipNormal, "Flip", "result", "anim Object, int32 Face") \
    X(UnifyNormals, "Unify", "result", "anim Object, int32 SelectedOnly") \
    X(AutoSmooth, "Auto", "result", "anim Object, float Angle, int32 UseSelection, int32 PreventIndirectSmoothing") \
    X(FaceNormal, "Face", "result", "anim Object, int32 Face, int32 Normalize, ptr:float OutNormal") \
    X(FaceCenter, "Face", "result", "anim Object, int32 Face, ptr:float OutCenter") \
    X(AngleBetweenFaces, "Angle", "float", "anim Object, int32 FaceA, int32 FaceB") \
    X(DeleteVertSet, "Delete", "result", "anim Object, cptr:uint32 Bits, int32 BitCount") \
    X(DeleteFaceSet, "Delete", "result", "anim Object, cptr:uint32 Bits, int32 BitCount") \
    X(DeleteIsoVerts, "Delete", "result", "anim Object") \
    X(DeleteFlaggedFaces, "Delete", "int32", "anim Object") \
    X(BreakVerts, "Break", "result", "anim Object, cptr:uint32 Bits, int32 BitCount") \
    X(CloneFaces, "Clone", "result", "anim Object, cptr:uint32 Bits, int32 BitCount") \
    X(WeldCollinear, "Weld", "result", "anim Object, cptr:uint32 Bits, int32 BitCount") \
    X(ExtrudeFaces, "Extrude", "result", "anim Object, int32 DoFace") \
    X(DivideEdge, "Divide", "result", "anim Object, int32 Edge, float Proportion, int32 VisibleDiagonal1, int32 FixNeighbours, int32 VisibleDiagonal2") \
    X(DivideFace, "Divide", "result", "anim Object, int32 Face, int32 EdgeA, int32 EdgeB, float ProportionA, float ProportionB, int32 Visible") \
    X(TurnEdge, "Turn", "result", "anim Object, int32 Edge") \
    X(EdgeTessellate, "Edge", "result", "anim Object, float Tension, int32 IgnoreSelection") \
    X(FindOpenEdges, "Find", "result", "anim Object, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(ElementFromFace, "Element", "result", "anim Object, int32 Face, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(SliceMesh, "Slice", "int32", "anim Object, cptr:float PlaneNormal, float Offset, int32 Split, int32 Remove") \
    X(Optimize, "Optimize", "result", "anim Object, float NormalThreshold, float EdgeThreshold, float Bias, float MaxEdge, uint32 Flags") \
    X(ApplyUVWMap, "Apply", "result", "anim Object, int32 Type, float UTile, float VTile, float WTile, int32 UFlip, int32 VFlip, int32 WFlip, int32 Cap, cptr:float Matrix, int32 Channel") \
    X(FreeAll, "Free", "result", "anim Object") \
    X(InvalidateGeomCache, "Invalidate", "result", "anim Object") \
    X(InvalidateTopologyCache, "Invalidate", "result", "anim Object") \
    X(CombineMeshes, "Combine", "result", "anim Object, anim MeshA, anim MeshB") \
    X(DeepCopy, "Deep", "result", "anim Object, anim Source, uint32 Channels") \
    X(getBoundingBox, "get", "result", "anim Object, ptr:float OutMin, ptr:float OutMax") \
    X(PointsWereChanged, "Points", "result", "anim Object") \
    X(EventSubscribe, "Event", "result", "int32 Code") \
    X(EventUnsubscribe, "Event", "result", "int32 Code") \
    X(EventPending, "Event", "int32", "") \
    X(EventsRead, "Events", "result", "ptr:MaxMcpEvent OutEvents, size Capacity, ptr:int32 OutRead") \
    X(EventsDropped, "Events", "uint32", "") \
    X(NodeObjectClassId, "Node", "result", "node Node, int32 Time, ptr:int32 OutSuperClass, ptr:uint32 OutPartA, ptr:uint32 OutPartB") \
    X(AnimClassId, "Anim", "result", "anim Anim, ptr:int32 OutSuperClass, ptr:uint32 OutPartA, ptr:uint32 OutPartB") \
    X(NodeCreateMesh, "Node", "node", "cstr Name") \
    X(NodeSetName, "Node", "result", "node Node, cstr Name") \
    X(NodeSetSelected, "Node", "result", "node Node, int32 Selected") \
    X(NodeParent, "Node", "node", "node Node") \
    X(NodeAttachChild, "Node", "result", "node Parent, node Child, int32 KeepTM") \
    X(NodeSetWireColor, "Node", "result", "node Node, cptr:float Rgb") \
    X(NodeFlagsRead, "Node", "result", "node Node, ptr:MaxMcpNodeFlags OutFlags") \
    X(NodeFlagsWrite, "Node", "result", "node Node, cptr:MaxMcpNodeFlags Flags") \
    X(NodeUserPropBuffer, "Node", "result", "node Node, mutstr OutText, size Capacity") \
    X(NodeSetUserPropBuffer, "Node", "result", "node Node, cstr Text") \
    X(LightSetExcluded, "Light", "result", "node Node, cptr:node Nodes, size Count, int32 Include, int32 AffectIllum, int32 AffectShadow") \
    X(ControllerCreate, "Controller", "anim", "int32 SuperClassId, uint32 PartA, uint32 PartB") \
    X(NodeSetTMController, "Node", "result", "node Node, anim Controller") \
    X(NodeSetVisibilityController, "Node", "result", "node Node, anim Controller") \
    X(ControllerSetSubController, "Controller", "result", "anim Controller, int32 Which, anim Sub") \
    X(SceneAmbient, "Scene", "result", "int32 Time, ptr:float OutRgb") \
    X(SceneSetAmbient, "Scene", "result", "int32 Time, cptr:float Rgb") \
    X(SceneBackground, "Scene", "result", "int32 Time, ptr:float OutRgb") \
    X(SceneSetBackground, "Scene", "result", "int32 Time, cptr:float Rgb") \
    X(SceneSetAnimRange, "Scene", "result", "int32 Start, int32 End") \
    X(SceneSetTime, "Scene", "result", "int32 Time") \
    X(MeshVertSelRead, "Mesh", "result", "anim Object, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(MeshVertSelWrite, "Mesh", "result", "anim Object, cptr:uint32 Bits, int32 BitCount") \
    X(MeshFaceSelRead, "Mesh", "result", "anim Object, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(MeshFaceSelWrite, "Mesh", "result", "anim Object, cptr:uint32 Bits, int32 BitCount") \
    X(MeshEdgeSelRead, "Mesh", "result", "anim Object, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(MeshEdgeSelWrite, "Mesh", "result", "anim Object, cptr:uint32 Bits, int32 BitCount") \
    X(MeshSelLevelRead, "Mesh", "result", "anim Object, ptr:int32 OutLevel") \
    X(MeshSelLevelWrite, "Mesh", "result", "anim Object, int32 Level") \
    X(MaterialCreateByClass, "Material", "anim", "uint32 PartA, uint32 PartB") \
    X(TexmapCreate, "Texmap", "anim", "uint32 PartA, uint32 PartB") \
    X(HoldBegin, "Hold", "result", "") \
    X(HoldAccept, "Hold", "result", "cstr Name") \
    X(HoldCancel, "Hold", "result", "") \
    X(HoldRestore, "Hold", "result", "") \
    X(HoldSuspend, "Hold", "result", "") \
    X(HoldResume, "Hold", "result", "") \
    X(HoldSuperBegin, "Hold", "result", "") \
    X(HoldSuperAccept, "Hold", "result", "cstr Name") \
    X(HoldSuperCancel, "Hold", "result", "") \
    X(HoldStateRead, "Hold", "result", "ptr:MaxMcpHoldState OutState") \
    X(NodeIsGroupHead, "Node", "int32", "node Node") \
    X(NodeIkFlags, "Node", "result", "node Node, ptr:MaxMcpIkNodeFlags OutFlags") \
    X(ControllerJointParams, "Controller", "result", "anim Controller, ptr:MaxMcpIkJoint OutJoint") \
    X(ChamferDataCreate, "Chamfer", "result", "ptr:held OutHeld") \
    X(AdjEdgeListCreate, "Adj", "result", "anim Object, ptr:held OutHeld") \
    X(MeshChamferVertices, "Mesh", "result", "anim Object, cptr:uint32 Bits, int32 BitCount, held Chamfer, held AdjEdges") \
    X(MeshChamferEdges, "Mesh", "result", "anim Object, cptr:uint32 Bits, int32 BitCount, held Chamfer, held AdjEdges") \
    X(MeshChamferMove, "Mesh", "result", "anim Object, held Chamfer, float Amount, held AdjEdges") \
    X(InstanceCreate, "Instance", "result", "int32 SuperClassId, uint32 PartA, uint32 PartB, ptr:held OutHeld") \
    X(NodeCreateWithObject, "Node", "result", "held Instance, cstr Name, ptr:node OutNode") \
    X(HeldDispose, "Held", "result", "held Held") \
    X(HeldCount, "Held", "result", "ptr:int32 OutCount") \
    X(LightExcludeAdd, "Light", "result", "node Node, node Excluded") \
    X(LightExcludedNode, "Light", "result", "node Node, int32 Index, ptr:node OutNode") \
    X(LightExcludeSet, "Light", "result", "node Node, int32 Index, node Excluded") \
    X(LightExcludeRemove, "Light", "result", "node Node, int32 Index") \
    X(SceneSetAmbientController, "Scene", "result", "anim Controller") \
    X(SceneSetBackgroundController, "Scene", "result", "anim Controller") \
    X(NodeIkFlagsWrite, "Node", "result", "node Node, cptr:MaxMcpIkNodeFlags Flags") \
    X(ControllerJointParamsWrite, "Controller", "result", "anim Controller, cptr:MaxMcpIkJoint Joint") \
    X(HoldSuspendedRead, "Hold", "result", "ptr:int32 OutSuspended") \
    X(ShapeSplineCount, "Shape", "result", "node Node, ptr:int32 OutCount") \
    X(ShapeSplinePointsRead, "Shape", "result", "node Node, int32 Index, ptr:MaxMcpShapePoint OutPoints, size Capacity, ptr:int32 OutWritten, ptr:int32 OutClosed") \
    X(ShapeSplineReplace, "Shape", "result", "node Node, int32 Index, cptr:MaxMcpShapePoint Points, size Count, int32 Closed") \
    X(ShapeSplineDelete, "Shape", "result", "node Node, int32 Index") \
    X(ShapeSplineDeleteMany, "Shape", "result", "node Node, cptr:uint32 Indices, uint32 Count") \
    X(EventSubscribedCodes, "Event", "result", "ptr:int32 OutCodes, size Capacity, ptr:int32 OutWritten") \
    X(EventSubscriberCount, "Event", "result", "int32 Code, ptr:int32 OutCount") \
    X(AnimRelease, "Anim", "result", "anim Anim") \
    X(AnimClassName, "Anim", "result", "anim Anim, int32 Localized, mutstr OutName, size Capacity") \
    X(NodeObjectClassName, "Node", "result", "node Node, int32 Time, int32 Localized, mutstr OutName, size Capacity") \
    X(NodeObjectBBox, "Node", "result", "node Node, int32 Time, cptr:float Tm, ptr:float OutMin, ptr:float OutMax") \
    X(MtlBaseValidity, "Mtl", "result", "anim MtlBase, int32 Time, ptr:int32 OutStart, ptr:int32 OutEnd") \
    X(MtlDisplacementValidity, "Mtl", "result", "anim Material, int32 Time, ptr:int32 OutStart, ptr:int32 OutEnd") \
    X(MaterialSetMapEnabled, "Material", "result", "anim Material, int32 Index, int32 OnOff") \
    X(MaterialSetMapAmount, "Material", "result", "anim Material, int32 Index, float Amount, int32 Time") \
    X(MeshVertexNormal, "Mesh", "result", "anim Object, int32 Vertex, ptr:float OutNormal") \
    X(MeshVertexNormalCount, "Mesh", "result", "anim Object, int32 Vertex, ptr:int32 OutCount") \
    X(MeshSetVertexNormal, "Mesh", "result", "anim Object, int32 Vertex, cptr:float Normal") \
    X(MultiMaterialSetCount, "Multi", "result", "anim Material, int32 Count") \
    X(MultiMaterialAdd, "Multi", "result", "anim Material, anim SubMaterial, int32 Index, cstr Name") \
    X(MultiMaterialRemove, "Multi", "result", "anim Material, int32 Index") \
    X(MultiMaterialSetSubAndName, "Multi", "result", "anim Material, int32 Index, anim SubMaterial, cstr Name") \
    X(MultiMaterialSubName, "Multi", "result", "anim Material, int32 Index, mutstr OutName, size Capacity") \
    X(MaterialSubMtlSlotName, "Material", "result", "anim Material, int32 Index, int32 Localized, mutstr OutName, size Capacity") \
    X(MtlBaseSubTexmapSlotName, "Mtl", "result", "anim MtlBase, int32 Index, int32 Localized, mutstr OutName, size Capacity") \
    X(MtlBaseMapSlotType, "Mtl", "result", "anim MtlBase, int32 Index, ptr:int32 OutType") \
    X(CompositeTexmapSetCount, "Composite", "result", "anim Texmap, int32 Count") \
    X(AnimInstanceCreate, "Anim", "anim", "int32 SuperClassId, uint32 PartA, uint32 PartB, ptr:result OutResult") \
    X(NodeCreateForObject, "Node", "node", "anim Object, cstr Name, ptr:result OutResult") \
    X(NameMakeUnique, "Name", "result", "cstr Name, mutstr OutName, size Capacity") \
    X(NodeSetObjectRef, "Node", "result", "node Node, anim Object") \
    X(NodeObjectOrWSMRef, "Node", "anim", "node Node, ptr:result OutResult") \
    X(AnimDeleteThis, "Anim", "result", "anim Anim") \
    X(SuperClassCount, "Super", "int32", "ptr:result OutResult") \
    X(SuperClassAt, "Super", "result", "int32 Index, ptr:int32 OutSuperClass") \
    X(ClassCount, "Class", "int32", "int32 SuperClassId, ptr:result OutResult") \
    X(ClassAt, "Class", "result", "int32 SuperClassId, int32 Index, ptr:uint32 OutPartA, ptr:uint32 OutPartB, ptr:int32 OutIsPublic") \
    X(ClassEntryName, "Class", "result", "int32 SuperClassId, uint32 PartA, uint32 PartB, mutstr OutName, size Capacity") \
    X(ClassEntryNonLocalizedName, "Class", "result", "int32 SuperClassId, uint32 PartA, uint32 PartB, mutstr OutName, size Capacity") \
    X(ClassCategory, "Class", "result", "int32 SuperClassId, uint32 PartA, uint32 PartB, mutstr OutName, size Capacity") \
    X(ClassEntryIsLoaded, "Class", "result", "int32 SuperClassId, uint32 PartA, uint32 PartB, ptr:int32 OutLoaded") \
    X(DefaultControllerRead, "Default", "result", "int32 SuperClassId, ptr:int32 OutSuperClass, ptr:uint32 OutPartA, ptr:uint32 OutPartB") \
    X(DefaultControllerWrite, "Default", "result", "int32 SuperClassId, uint32 PartA, uint32 PartB") \
    X(AnimIsRefMaker, "Anim", "int32", "anim Anim, ptr:result OutResult") \
    X(AnimIsRefTarget, "Anim", "int32", "anim Anim, ptr:result OutResult") \
    X(NodeAsAnim, "Node", "anim", "node Node") \
    X(AnimAsNode, "Anim", "node", "anim Anim") \
    X(AnimSubCount, "Anim", "int32", "anim Anim, ptr:result OutResult") \
    X(AnimSubAnim, "Anim", "result", "anim Anim, int32 Index, ptr:anim OutSub") \
    X(AnimSubAnimName, "Anim", "result", "anim Anim, int32 Index, int32 Localized, mutstr OutName, size Capacity") \
    X(AnimSubNumToRefNum, "Anim", "int32", "anim Anim, int32 SubNum, ptr:result OutResult") \
    X(AnimRefCount, "Anim", "int32", "anim Anim, ptr:result OutResult") \
    X(AnimReference, "Anim", "result", "anim Anim, int32 Index, ptr:anim OutTarget") \
    X(AnimFindRef, "Anim", "int32", "anim Anim, anim Target, ptr:result OutResult") \
    X(AnimDependents, "Anim", "result", "anim Anim, ptr:anim OutDependents, size Capacity, ptr:int32 OutWritten") \
    X(AnimDirectDependents, "Anim", "result", "anim Anim, ptr:anim OutDependents, size Capacity, ptr:int32 OutWritten") \
    X(ControllerSubCount, "Controller", "int32", "anim Controller, ptr:result OutResult") \
    X(ControllerSubControllerAt, "Controller", "result", "anim Controller, int32 Index, ptr:anim OutSub") \
    X(ControllerCreatePointContainer, "Controller", "anim", "") \
    X(ControllerAddSubController, "Controller", "int32", "anim Controller, anim Sub, ptr:result OutResult") \
    X(AnimCanAssignController, "Anim", "int32", "anim Anim, int32 SubNum, ptr:result OutResult") \
    X(AnimAssignController, "Anim", "int32", "anim Anim, int32 SubNum, anim Controller, ptr:result OutResult") \
    X(AnimTestForLoop, "Anim", "int32", "anim Target, anim Maker, ptr:result OutResult") \
    X(AnimCanTransferReference, "Anim", "int32", "anim Anim, int32 Which, ptr:result OutResult") \
    X(AnimReplaceReference, "Anim", "int32", "anim Anim, int32 Which, anim NewTarget, int32 DeleteOld, ptr:result OutResult") \
    X(ControllerSetSubControllerAt, "Controller", "result", "anim Controller, int32 Index, anim Sub") \
    X(ControllerSetSubCount, "Controller", "result", "anim Controller, int32 Count, int32 Keep") \
    X(AnimCanDeleteSubAnim, "Anim", "int32", "anim Anim, int32 Index, ptr:result OutResult") \
    X(AnimDeleteSubAnim, "Anim", "result", "anim Anim, int32 Index") \
    X(AnimDeleteReference, "Anim", "int32", "anim Anim, int32 Which, ptr:result OutResult") \
    X(ControllerDeleteSubControllers, "Controller", "result", "anim Controller, cptr:uint32 Bits, int32 BitCount") \
    X(AnimHasInterface, "Anim", "result", "anim Anim, uint32 PartA, uint32 PartB, ptr:int32 OutHas") \
    X(AnimInterfaceName, "Anim", "result", "anim Anim, uint32 PartA, uint32 PartB, mutstr OutName, size Capacity") \
    X(AnimHasLegacyInterface, "Anim", "result", "anim Anim, uint32 Id, ptr:int32 OutHas") \
    X(ClassInterfaceCount, "Class", "result", "int32 SuperClassId, uint32 PartA, uint32 PartB, ptr:int32 OutCount") \
    X(ClassInterfaceIdAt, "Class", "result", "int32 SuperClassId, uint32 PartA, uint32 PartB, int32 Index, ptr:uint32 OutPartA, ptr:uint32 OutPartB") \
    X(ClassInterfaceNameAt, "Class", "result", "int32 SuperClassId, uint32 PartA, uint32 PartB, int32 Index, mutstr OutName, size Capacity") \
    X(ClassHasInterface, "Class", "result", "int32 SuperClassId, uint32 PartA, uint32 PartB, uint32 IdPartA, uint32 IdPartB, ptr:int32 OutHas") \
    X(AnimLimitEnableRead, "Anim", "result", "anim Anim, ptr:int32 OutEnabled") \
    X(AnimLimitEnableWrite, "Anim", "result", "anim Anim, int32 Enabled") \
    X(AnimLimitedControlRead, "Anim", "result", "anim Anim, ptr:anim OutControl") \
    X(AnimLimitedControlWrite, "Anim", "result", "anim Anim, anim Control") \
    X(AnimEulerOrderRead, "Anim", "result", "anim Anim, ptr:int32 OutOrder") \
    X(AnimEulerOrderWrite, "Anim", "result", "anim Anim, int32 Order") \
    X(AnimRealWorldMapSizeRead, "Anim", "result", "anim Anim, ptr:int32 OutUse") \
    X(AnimRealWorldMapSizeTagRead, "Anim", "result", "anim Anim, ptr:int32 OutUse") \
    X(AnimRealWorldMapSizeWrite, "Anim", "result", "anim Anim, int32 Use") \
    X(AnimAppDataWrite, "Anim", "result", "anim Anim, uint32 KeyPartA, uint32 KeyPartB, int32 KeySuperClassId, uint32 KeySubId, cptr:byte Data, uint32 Length, ptr:int32 OutReplaced") \
    X(AnimAppDataRead, "Anim", "result", "anim Anim, uint32 KeyPartA, uint32 KeyPartB, int32 KeySuperClassId, uint32 KeySubId, ptr:byte OutData, size Capacity, ptr:uint32 OutWritten") \
    X(AnimAppDataDelete, "Anim", "result", "anim Anim, uint32 KeyPartA, uint32 KeyPartB, int32 KeySuperClassId, uint32 KeySubId") \
    X(AnimAppDataClearAll, "Anim", "result", "anim Anim") \
    X(AnimCustAttribContainer, "Anim", "result", "anim Anim, ptr:anim OutContainer") \
    X(AnimCustAttribContainerCreate, "Anim", "result", "anim Anim, ptr:int32 OutCreated") \
    X(AnimCustAttribContainerDelete, "Anim", "result", "anim Anim") \
    X(CustAttribContainerOwner, "Cust", "result", "anim Container, ptr:anim OutOwner") \
    X(AnimCustAttribCount, "Anim", "result", "anim Anim, ptr:int32 OutCount") \
    X(AnimCustAttribAt, "Anim", "result", "anim Anim, int32 Index, ptr:anim OutAttrib") \
    X(CustAttribName, "Cust", "result", "anim Attrib, int32 Localized, mutstr OutName, size Capacity") \
    X(AnimCustAttribAppend, "Anim", "result", "anim Anim, anim Attrib, ptr:int32 OutAppended") \
    X(AnimCustAttribInsert, "Anim", "result", "anim Anim, int32 Index, anim Attrib, ptr:int32 OutInserted") \
    X(AnimCustAttribSet, "Anim", "result", "anim Anim, int32 Index, anim Attrib, ptr:int32 OutSet") \
    X(AnimCustAttribRemove, "Anim", "result", "anim Anim, int32 Index") \
    X(AnimParamBlockCount, "Anim", "int32", "anim Anim, ptr:result OutResult") \
    X(AnimParamBlock, "Anim", "result", "anim Anim, int32 Index, ptr:anim OutBlock") \
    X(AnimParamBlockById, "Anim", "result", "anim Anim, int32 BlockId, ptr:anim OutBlock") \
    X(ParamBlockId, "Param", "int32", "anim Block, ptr:result OutResult") \
    X(ParamBlockVersion, "Param", "uint32", "anim Block, ptr:result OutResult") \
    X(ParamBlockName, "Param", "result", "anim Block, mutstr OutName, size Capacity") \
    X(ParamBlockOwner, "Param", "result", "anim Block, ptr:anim OutOwner") \
    X(ParamBlockValidity, "Param", "result", "anim Block, int32 Time, ptr:int32 OutStart, ptr:int32 OutEnd") \
    X(ParamBlockParamCount, "Param", "int32", "anim Block, ptr:result OutResult") \
    X(ParamBlockParamId, "Param", "int32", "anim Block, int32 Index, ptr:result OutResult") \
    X(ParamBlockParamIndex, "Param", "int32", "anim Block, int32 ParamId, ptr:result OutResult") \
    X(ParamBlockParamType, "Param", "int32", "anim Block, int32 ParamId, ptr:result OutResult") \
    X(ParamBlockParamName, "Param", "result", "anim Block, int32 ParamId, mutstr OutName, size Capacity") \
    X(ParamBlockParamNonLocalizedName, "Param", "result", "anim Block, int32 ParamId, mutstr OutName, size Capacity") \
    X(ParamBlockParamLocalName, "Param", "result", "anim Block, int32 ParamId, int32 TabIndex, int32 Localized, mutstr OutName, size Capacity") \
    X(ParamBlockParamDef, "Param", "result", "anim Block, int32 ParamId, ptr:MaxMcpParamDef OutDef") \
    X(ParamBlockParamControlType, "Param", "int32", "anim Block, int32 ParamId, ptr:result OutResult") \
    X(ParamBlockParamAnimNum, "Param", "int32", "anim Block, int32 ParamId, int32 TabIndex, ptr:result OutResult") \
    X(ParamBlockAnimNumToParamIndex, "Param", "int32", "anim Block, int32 AnimNum, ptr:int32 OutTabIndex, ptr:result OutResult") \
    X(ParamBlockParamRefNum, "Param", "int32", "anim Block, int32 ParamId, int32 TabIndex, ptr:result OutResult") \
    X(ParamBlockParamControllerRefNum, "Param", "int32", "anim Block, int32 ParamId, int32 TabIndex, ptr:result OutResult") \
    X(ParamBlockValueFloat, "Param", "result", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, ptr:float OutValue, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(ParamBlockValueInt, "Param", "result", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, ptr:int32 OutValue, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(ParamBlockValuePoint2, "Param", "result", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, ptr:float OutValue, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(ParamBlockValuePoint3, "Param", "result", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, ptr:float OutValue, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(ParamBlockValuePoint4, "Param", "result", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, ptr:float OutValue, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(ParamBlockValueColor, "Param", "result", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, ptr:float OutValue, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(ParamBlockValueAColor, "Param", "result", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, ptr:float OutValue, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(ParamBlockValueString, "Param", "result", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, mutstr OutValue, size Capacity, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(ParamBlockValueMtl, "Param", "result", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, ptr:anim OutValue, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(ParamBlockValueTexmap, "Param", "result", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, ptr:anim OutValue, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(ParamBlockValueNode, "Param", "result", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, ptr:node OutValue, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(ParamBlockValueRefTarget, "Param", "result", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, ptr:anim OutValue, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(ParamBlockValueBlock, "Param", "result", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, ptr:anim OutValue, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(ParamBlockValueMatrix3, "Param", "result", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, ptr:float OutValue, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(ParamBlockSetFloat, "Param", "int32", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, float Value, ptr:result OutResult") \
    X(ParamBlockSetInt, "Param", "int32", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, int32 Value, ptr:result OutResult") \
    X(ParamBlockSetPoint2, "Param", "int32", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, cptr:float Value, ptr:result OutResult") \
    X(ParamBlockSetPoint3, "Param", "int32", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, cptr:float Value, ptr:result OutResult") \
    X(ParamBlockSetPoint4, "Param", "int32", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, cptr:float Value, ptr:result OutResult") \
    X(ParamBlockSetColor, "Param", "int32", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, cptr:float Value, ptr:result OutResult") \
    X(ParamBlockSetAColor, "Param", "int32", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, cptr:float Value, ptr:result OutResult") \
    X(ParamBlockSetString, "Param", "int32", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, cstr Value, ptr:result OutResult") \
    X(ParamBlockSetMtl, "Param", "int32", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, anim Value, ptr:result OutResult") \
    X(ParamBlockSetTexmap, "Param", "int32", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, anim Value, ptr:result OutResult") \
    X(ParamBlockSetNode, "Param", "int32", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, node Value, ptr:result OutResult") \
    X(ParamBlockSetRefTarget, "Param", "int32", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, anim Value, ptr:result OutResult") \
    X(ParamBlockSetBlock, "Param", "int32", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, anim Value, ptr:result OutResult") \
    X(ParamBlockSetMatrix3, "Param", "int32", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, cptr:float Value, ptr:result OutResult") \
    X(ParamBlockResetValue, "Param", "result", "anim Block, int32 ParamId, int32 TabIndex, int32 UpdateUI, int32 CallSetHandlers") \
    X(ParamBlockController, "Param", "result", "anim Block, int32 ParamId, int32 TabIndex, ptr:anim OutController") \
    X(ParamBlockKeyAtTime, "Param", "int32", "anim Block, int32 ParamId, int32 Time, int32 TabIndex, ptr:result OutResult") \
    X(ParamBlockSetController, "Param", "result", "anim Block, int32 ParamId, int32 TabIndex, anim Controller, int32 PreserveFrame0Value") \
    X(ParamBlockRemoveController, "Param", "result", "anim Block, int32 ParamId, int32 TabIndex") \
    X(ParamBlockTabCount, "Param", "int32", "anim Block, int32 ParamId, ptr:result OutResult") \
    X(ParamBlockTabSetCount, "Param", "result", "anim Block, int32 ParamId, int32 Count") \
    X(ParamBlockTabZeroCount, "Param", "result", "anim Block, int32 ParamId") \
    X(ParamBlockTabResize, "Param", "int32", "anim Block, int32 ParamId, int32 Count, ptr:result OutResult") \
    X(ParamBlockTabShrink, "Param", "result", "anim Block, int32 ParamId") \
    X(ParamBlockTabDelete, "Param", "int32", "anim Block, int32 ParamId, int32 Start, int32 Count, ptr:result OutResult") \
    X(ParamBlockTabInsertFloat, "Param", "int32", "anim Block, int32 ParamId, int32 At, float Value, ptr:result OutResult") \
    X(ParamBlockTabInsertInt, "Param", "int32", "anim Block, int32 ParamId, int32 At, int32 Value, ptr:result OutResult") \
    X(ParamBlockTabInsertPoint2, "Param", "int32", "anim Block, int32 ParamId, int32 At, cptr:float Value, ptr:result OutResult") \
    X(ParamBlockTabInsertPoint3, "Param", "int32", "anim Block, int32 ParamId, int32 At, cptr:float Value, ptr:result OutResult") \
    X(ParamBlockTabInsertPoint4, "Param", "int32", "anim Block, int32 ParamId, int32 At, cptr:float Value, ptr:result OutResult") \
    X(ParamBlockTabInsertColor, "Param", "int32", "anim Block, int32 ParamId, int32 At, cptr:float Value, ptr:result OutResult") \
    X(ParamBlockTabInsertAColor, "Param", "int32", "anim Block, int32 ParamId, int32 At, cptr:float Value, ptr:result OutResult") \
    X(ParamBlockTabInsertString, "Param", "int32", "anim Block, int32 ParamId, int32 At, cstr Value, ptr:result OutResult") \
    X(ParamBlockTabInsertMtl, "Param", "int32", "anim Block, int32 ParamId, int32 At, anim Value, ptr:result OutResult") \
    X(ParamBlockTabInsertTexmap, "Param", "int32", "anim Block, int32 ParamId, int32 At, anim Value, ptr:result OutResult") \
    X(ParamBlockTabInsertNode, "Param", "int32", "anim Block, int32 ParamId, int32 At, node Value, ptr:result OutResult") \
    X(ParamBlockTabInsertRefTarget, "Param", "int32", "anim Block, int32 ParamId, int32 At, anim Value, ptr:result OutResult") \
    X(ParamBlockTabInsertBlock, "Param", "int32", "anim Block, int32 ParamId, int32 At, anim Value, ptr:result OutResult") \
    X(ParamBlockTabInsertMatrix3, "Param", "int32", "anim Block, int32 ParamId, int32 At, cptr:float Value, ptr:result OutResult") \
    X(ParamBlockTabAppendFloat, "Param", "int32", "anim Block, int32 ParamId, float Value, int32 AllocExtra, ptr:result OutResult") \
    X(ParamBlockTabAppendInt, "Param", "int32", "anim Block, int32 ParamId, int32 Value, int32 AllocExtra, ptr:result OutResult") \
    X(ParamBlockTabAppendPoint2, "Param", "int32", "anim Block, int32 ParamId, cptr:float Value, int32 AllocExtra, ptr:result OutResult") \
    X(ParamBlockTabAppendPoint3, "Param", "int32", "anim Block, int32 ParamId, cptr:float Value, int32 AllocExtra, ptr:result OutResult") \
    X(ParamBlockTabAppendPoint4, "Param", "int32", "anim Block, int32 ParamId, cptr:float Value, int32 AllocExtra, ptr:result OutResult") \
    X(ParamBlockTabAppendColor, "Param", "int32", "anim Block, int32 ParamId, cptr:float Value, int32 AllocExtra, ptr:result OutResult") \
    X(ParamBlockTabAppendAColor, "Param", "int32", "anim Block, int32 ParamId, cptr:float Value, int32 AllocExtra, ptr:result OutResult") \
    X(ParamBlockTabAppendString, "Param", "int32", "anim Block, int32 ParamId, cstr Value, int32 AllocExtra, ptr:result OutResult") \
    X(ParamBlockTabAppendMtl, "Param", "int32", "anim Block, int32 ParamId, anim Value, int32 AllocExtra, ptr:result OutResult") \
    X(ParamBlockTabAppendTexmap, "Param", "int32", "anim Block, int32 ParamId, anim Value, int32 AllocExtra, ptr:result OutResult") \
    X(ParamBlockTabAppendNode, "Param", "int32", "anim Block, int32 ParamId, node Value, int32 AllocExtra, ptr:result OutResult") \
    X(ParamBlockTabAppendRefTarget, "Param", "int32", "anim Block, int32 ParamId, anim Value, int32 AllocExtra, ptr:result OutResult") \
    X(ParamBlockTabAppendBlock, "Param", "int32", "anim Block, int32 ParamId, anim Value, int32 AllocExtra, ptr:result OutResult") \
    X(ParamBlockTabAppendMatrix3, "Param", "int32", "anim Block, int32 ParamId, cptr:float Value, int32 AllocExtra, ptr:result OutResult") \
    X(DefaultControllerForParamType, "Default", "result", "int32 SuperClassId, int32 ParamType, ptr:int32 OutSuperClass, ptr:uint32 OutPartA, ptr:uint32 OutPartB") \
    X(NodeDerivedObject, "Node", "anim", "node Node, ptr:result OutResult") \
    X(NodeWSMDerivedObject, "Node", "anim", "node Node, ptr:result OutResult") \
    X(NodeFindBaseObject, "Node", "anim", "node Node, ptr:result OutResult") \
    X(NodeReplaceableObjectRef, "Node", "anim", "node Node, ptr:result OutResult") \
    X(DerivedObjectCreate, "Derived", "anim", "anim Object, ptr:result OutResult") \
    X(WSDerivedObjectCreate, "WS", "anim", "anim Object, ptr:result OutResult") \
    X(NodeCreateWSMDerivedObject, "Node", "result", "node Node") \
    X(DerivedObjectReference, "Derived", "result", "anim DerivedObject, ptr:anim OutObject") \
    X(DerivedObjectSetReference, "Derived", "int32", "anim DerivedObject, anim Object, ptr:result OutResult") \
    X(DerivedObjectModifierCount, "Derived", "int32", "anim DerivedObject, ptr:result OutResult") \
    X(DerivedObjectModifier, "Derived", "result", "anim DerivedObject, int32 Index, ptr:anim OutModifier") \
    X(DerivedObjectAddModifier, "Derived", "result", "anim DerivedObject, anim Modifier, int32 Before") \
    X(DerivedObjectSetModifier, "Derived", "result", "anim DerivedObject, int32 Index, anim Modifier") \
    X(DerivedObjectDeleteModifier, "Derived", "result", "anim DerivedObject, int32 Index") \
    X(NodeCanAddModifier, "Node", "int32", "node Node, anim Modifier, ptr:result OutResult") \
    X(NodeAddModifier, "Node", "int32", "node Node, anim Modifier, int32 BeforeModStackIndex, ptr:result OutResult") \
    X(NodeFindModifierAt, "Node", "result", "node Node, int32 ModStackIndex, ptr:anim OutDerivedObject, ptr:int32 OutIndex, ptr:anim OutModifier") \
    X(NodeFindModifier, "Node", "result", "node Node, anim Modifier, ptr:anim OutDerivedObject, ptr:int32 OutModStackIndex, ptr:int32 OutIndex") \
    X(NodeDeleteModifier, "Node", "int32", "node Node, anim Modifier, ptr:result OutResult") \
    X(NodeDeleteModifierAt, "Node", "int32", "node Node, int32 ModStackIndex, ptr:result OutResult") \
    X(ModifierName, "Modifier", "result", "anim Modifier, int32 Localized, mutstr OutName, size Capacity") \
    X(ModifierSetName, "Modifier", "result", "anim Modifier, cstr Name") \
    X(ModifierEnabled, "Modifier", "int32", "anim Modifier, ptr:result OutResult") \
    X(ModifierSetEnabled, "Modifier", "result", "anim Modifier, int32 Enabled") \
    X(ModifierEnabledInViews, "Modifier", "int32", "anim Modifier, ptr:result OutResult") \
    X(ModifierSetEnabledInViews, "Modifier", "result", "anim Modifier, int32 Enabled") \
    X(ModifierEnabledInRender, "Modifier", "int32", "anim Modifier, ptr:result OutResult") \
    X(ModifierSetEnabledInRender, "Modifier", "result", "anim Modifier, int32 Enabled") \
    X(ModifierValidity, "Modifier", "result", "anim Modifier, int32 Time, ptr:int32 OutStart, ptr:int32 OutEnd") \
    X(ModifierChannelsUsed, "Modifier", "uint32", "anim Modifier, ptr:result OutResult") \
    X(ModifierChannelsChanged, "Modifier", "uint32", "anim Modifier, ptr:result OutResult") \
    X(ModifierInputType, "Modifier", "result", "anim Modifier, ptr:uint32 OutPartA, ptr:uint32 OutPartB") \
    X(WSMObjectCreateMod, "WS", "anim", "anim WsmObject, node SpaceWarpNode, ptr:result OutResult") \
    X(ModContextTransform, "Mod", "result", "anim DerivedObject, int32 Index, ptr:float OutRow") \
    X(ModContextSetTransform, "Mod", "result", "anim DerivedObject, int32 Index, cptr:float Row") \
    X(ModContextBox, "Mod", "result", "anim DerivedObject, int32 Index, ptr:float OutMin, ptr:float OutMax") \
    X(ModContextSetBox, "Mod", "result", "anim DerivedObject, int32 Index, cptr:float Min, cptr:float Max") \
    X(NodeObjectTransform, "Node", "result", "node Node, int32 Time, ptr:float OutRow, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(NodeObjectTransformBeforeWSM, "Node", "result", "node Node, int32 Time, ptr:float OutRow, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(NodeObjectTransformAfterWSM, "Node", "result", "node Node, int32 Time, ptr:float OutRow, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(NodeTransformValidity, "Node", "result", "node Node, int32 Time, ptr:int32 OutStart, ptr:int32 OutEnd") \
    X(NodeHasWSM, "Node", "int32", "node Node, ptr:result OutResult") \
    X(NodeObjectOffset, "Node", "result", "node Node, ptr:MaxMcpObjectOffset OutOffset") \
    X(NodeSetObjectOffset, "Node", "result", "node Node, cptr:MaxMcpObjectOffset Offset") \
    X(NodeCenterPivot, "Node", "result", "node Node, int32 Time, int32 MoveObject") \
    X(NodeAlignPivot, "Node", "result", "node Node, int32 Time, int32 MoveObject") \
    X(NodeWorldAlignPivot, "Node", "result", "node Node, int32 Time, int32 MoveObject") \
    X(NodeAlignPivotToParent, "Node", "result", "node Node, int32 Time") \
    X(NodeAlignPivotToWorld, "Node", "result", "node Node, int32 Time") \
    X(NodeMayResetTransform, "Node", "int32", "node Node, ptr:result OutResult") \
    X(NodeResetTransform, "Node", "result", "node Node, int32 Time, int32 ScaleOnly") \
    X(NodeResetPivot, "Node", "result", "node Node, int32 Time") \
    X(ObjectValidity, "Object", "result", "anim Object, int32 Time, ptr:int32 OutStart, ptr:int32 OutEnd") \
    X(ObjectChannelValidity, "Object", "result", "anim Object, int32 Time, int32 ChannelNumber, ptr:int32 OutStart, ptr:int32 OutEnd") \
    X(ObjectSetChannelValidity, "Object", "result", "anim Object, int32 ChannelNumber, int32 Start, int32 End") \
    X(ObjectUpdateValidity, "Object", "result", "anim Object, int32 ChannelNumber, int32 Start, int32 End") \
    X(ObjectInvalidateChannels, "Object", "result", "anim Object, uint32 ChannelMask") \
    X(NodeInvalidateTM, "Node", "result", "node Node") \
    X(NodeInvalidateTreeTM, "Node", "result", "node Node") \
    X(NodeInvalidateWS, "Node", "result", "node Node") \
    X(NodeInvalidateObjectCache, "Node", "result", "node Node") \
    X(AnimNotifyDependents, "Anim", "int32", "anim Anim, int32 ChangeStart, int32 ChangeEnd, size PartId, uint32 Message, int32 SuperClassFilter, int32 Propagate, int32 NotifyOption, ptr:result OutResult") \
    X(SceneRedrawViews, "Scene", "result", "int32 Time, uint32 Flags") \
    X(SceneSuspendEditing, "Scene", "result", "uint32 WhichPanels, int32 AlwaysSuspend") \
    X(SceneResumeEditing, "Scene", "result", "uint32 WhichPanels, int32 AlwaysSuspend") \
    X(ShapePointsReadObject, "Shape", "result", "node Node, int32 Time, int32 Index, ptr:MaxMcpShapePoint OutPoints, size Capacity, ptr:int32 OutWritten") \
    X(NodeCreatePoly, "Node", "node", "cstr Name") \
    X(EditPolyObjClassId, "Edit", "result", "ptr:int32 OutSuperClassId, ptr:uint32 OutPartA, ptr:uint32 OutPartB") \
    X(PatchObjClassId, "Patch", "result", "ptr:int32 OutSuperClassId, ptr:uint32 OutPartA, ptr:uint32 OutPartB") \
    X(NodeCreatePatch, "Node", "node", "cstr Name") \
    X(NodeCanConvertTo, "Node", "result", "node Node, int32 Time, uint32 PartA, uint32 PartB, ptr:int32 OutCan") \
    X(PolySetNumVerts, "Poly", "result", "anim Object, int32 Count") \
    X(PolySetNumFaces, "Poly", "result", "anim Object, int32 Count") \
    X(PolyNewVert, "Poly", "result", "anim Object, cptr:float Position, ptr:int32 OutVert") \
    X(PolyCreateFace, "Poly", "result", "anim Object, cptr:int32 Verts, size Degree, int32 TriangulationType, ptr:int32 OutFace") \
    X(PolySetMapNum, "Poly", "result", "anim Object, int32 Count") \
    X(PolyVertexCount, "Poly", "result", "anim Object, ptr:int32 OutCount") \
    X(PolyVertsRead, "Poly", "result", "anim Object, ptr:MaxMcpPolyVert OutVerts, size Capacity, ptr:int32 OutWritten") \
    X(PolyEdgeCount, "Poly", "result", "anim Object, ptr:int32 OutCount") \
    X(PolyEdgesRead, "Poly", "result", "anim Object, ptr:MaxMcpPolyEdge OutEdges, size Capacity, ptr:int32 OutWritten") \
    X(PolyFaceCount, "Poly", "result", "anim Object, ptr:int32 OutCount") \
    X(PolyFacesRead, "Poly", "result", "anim Object, ptr:MaxMcpPolyFace OutFaces, size Capacity, ptr:int32 OutWritten") \
    X(PolyFaceVertsRead, "Poly", "result", "anim Object, int32 Face, ptr:int32 OutVerts, size Capacity, ptr:int32 OutWritten") \
    X(PolyFaceEdgesRead, "Poly", "result", "anim Object, int32 Face, ptr:int32 OutEdges, size Capacity, ptr:int32 OutWritten") \
    X(PolyMeshFlags, "Poly", "result", "anim Object, ptr:uint32 OutFlags") \
    X(PolyPartValidity, "Poly", "result", "anim Object, uint32 Channels, ptr:int32 OutStart, ptr:int32 OutEnd") \
    X(PolyMapCount, "Poly", "result", "anim Object, ptr:int32 OutCount") \
    X(PolyMapFlags, "Poly", "result", "anim Object, int32 Channel, ptr:uint32 OutFlags") \
    X(PolyMapVertCount, "Poly", "result", "anim Object, int32 Channel, ptr:int32 OutCount") \
    X(PolyMapFaceCount, "Poly", "result", "anim Object, int32 Channel, ptr:int32 OutCount") \
    X(PolyMapVertsRead, "Poly", "result", "anim Object, int32 Channel, ptr:float OutVerts, size Capacity, ptr:int32 OutWritten") \
    X(PolyMapFacesRead, "Poly", "result", "anim Object, int32 Channel, ptr:MaxMcpPolyMapFace OutFaces, size Capacity, ptr:int32 OutWritten") \
    X(PolyMapFaceVertsRead, "Poly", "result", "anim Object, int32 Channel, int32 Face, ptr:int32 OutVerts, size Capacity, ptr:int32 OutWritten") \
    X(PolyVertsWrite, "Poly", "result", "anim Object, cptr:float Verts, size Count") \
    X(PolyFaceMakePoly, "Poly", "result", "anim Object, int32 Face, cptr:int32 Verts, size Degree, cptr:int32 Visible, cptr:int32 Selected") \
    X(PolyFaceSetSmGroup, "Poly", "result", "anim Object, int32 Face, uint32 SmGroup") \
    X(PolyFaceSetMaterial, "Poly", "result", "anim Object, int32 Face, uint32 Material") \
    X(PolyInvalidateTopoCache, "Poly", "result", "anim Object, int32 ClearCacheFlags") \
    X(PolyInvalidateGeomCache, "Poly", "result", "anim Object") \
    X(PolyFillInMesh, "Poly", "result", "anim Object") \
    X(PolyMeshSetFlag, "Poly", "result", "anim Object, uint32 Flags, int32 Value") \
    X(PolyMeshClearFlag, "Poly", "result", "anim Object, uint32 Flags") \
    X(PolySetPartValidity, "Poly", "result", "anim Object, uint32 Channels, int32 Start, int32 End") \
    X(PolyInitMap, "Poly", "result", "anim Object, int32 Channel") \
    X(PolyMapSetNumVerts, "Poly", "result", "anim Object, int32 Channel, int32 Count") \
    X(PolyMapSetNumFaces, "Poly", "result", "anim Object, int32 Channel, int32 Count") \
    X(PolyMapNewVert, "Poly", "result", "anim Object, int32 Channel, cptr:float Vert, ptr:int32 OutVert") \
    X(PolyMapNewFace, "Poly", "result", "anim Object, int32 Channel, cptr:int32 Verts, size Degree, ptr:int32 OutFace") \
    X(PolyMapVertsWrite, "Poly", "result", "anim Object, int32 Channel, cptr:float Verts, size Count") \
    X(PolyMapFaceMakePoly, "Poly", "result", "anim Object, int32 Channel, int32 Face, cptr:int32 Verts, size Degree") \
    X(PolySetEdgeVis, "Poly", "result", "anim Object, int32 Edge, int32 Visible") \
    X(PolySetEdgeSel, "Poly", "result", "anim Object, int32 Edge, int32 Selected") \
    X(PolySetNumEdges, "Poly", "result", "anim Object, int32 Count") \
    X(PolyAppendNewEdges, "Poly", "result", "anim Object, int32 Count, ptr:int32 OutFirst") \
    X(PolySimpleNewEdge, "Poly", "result", "anim Object, int32 V1, int32 V2, ptr:int32 OutEdge") \
    X(PolyNewEdge, "Poly", "result", "anim Object, int32 V1, int32 V2, int32 LeftFace, int32 FacePos, ptr:int32 OutEdge") \
    X(PolyRegisterEdge, "Poly", "result", "anim Object, int32 V1, int32 V2, int32 LeftFace, int32 FacePos, ptr:int32 OutEdge") \
    X(PolySetFlag, "Poly", "result", "anim Object, int32 Level, int32 Index, uint32 Flags, int32 Value") \
    X(PolyClearFlag, "Poly", "result", "anim Object, int32 Level, int32 Index, uint32 Flags") \
    X(PolyDeleteFlaggedFaces, "Poly", "result", "anim Object, uint32 DeathFlags, uint32 CopyFlags") \
    X(PolyCollapseDeadVerts, "Poly", "result", "anim Object") \
    X(PolyCollapseDeadEdges, "Poly", "result", "anim Object") \
    X(PolyCollapseDeadFaces, "Poly", "result", "anim Object") \
    X(PolyCollapseDeadStructs, "Poly", "result", "anim Object") \
    X(PolyRemoveVertex, "Poly", "result", "anim Object, int32 Vertex, ptr:int32 OutRemoved") \
    X(PolyRemoveVertices, "Poly", "result", "anim Object, cptr:int32 Vertices, size Count, ptr:int32 OutRemoved") \
    X(PolyRemoveEdge, "Poly", "result", "anim Object, int32 Edge") \
    X(PolyRemoveSpur, "Poly", "result", "anim Object, int32 Spur, ptr:int32 OutRemoved") \
    X(PolyFreeVerts, "Poly", "result", "anim Object") \
    X(PolyFreeEdges, "Poly", "result", "anim Object") \
    X(PolyFreeFaces, "Poly", "result", "anim Object") \
    X(PolyClear, "Poly", "result", "anim Object") \
    X(PolyClearAndFree, "Poly", "result", "anim Object") \
    X(PolyMapClear, "Poly", "result", "anim Object, int32 Channel") \
    X(PolyMapClearAndFree, "Poly", "result", "anim Object, int32 Channel") \
    X(PolyClearMap, "Poly", "result", "anim Object, int32 Channel") \
    X(PolyFreeMap, "Poly", "result", "anim Object, int32 Channel") \
    X(PolyFreeMaps, "Poly", "result", "anim Object") \
    X(PolyMapCollapseDeadVerts, "Poly", "result", "anim Object, int32 Channel") \
    X(PolyMapCollapseDeadFaces, "Poly", "result", "anim Object, int32 Channel") \
    X(PolyBorderLoopCount, "Poly", "result", "anim Object, int32 SelLevel, uint32 TargetFlag, ptr:int32 OutCount") \
    X(PolyBorderLoopRead, "Poly", "result", "anim Object, int32 SelLevel, uint32 TargetFlag, int32 Loop, ptr:int32 OutEdges, size Capacity, ptr:int32 OutWritten, ptr:int32 OutTargeted") \
    X(PolyExtrudeFaces, "Poly", "result", "anim Object, uint32 Flag, ptr:int32 OutDone") \
    X(PolySlice, "Poly", "result", "anim Object, cptr:float PlaneNormal, float Offset, float Threshold, int32 Split, int32 Remove, int32 FlaggedFacesOnly, uint32 FaceFlags, int32 TriangulationType, ptr:int32 OutDone") \
    X(PolyMultiDivideEdge, "Poly", "result", "anim Object, int32 Edge, int32 Segments") \
    X(PolySplitTriEdge, "Poly", "result", "anim Object, int32 Edge, float Proportion, float Threshold, int32 NewEdgeVisible, int32 NewEdgeSelected, ptr:int32 OutVert") \
    X(PolyDivideFace, "Poly", "result", "anim Object, int32 Face, cptr:float Barycentric, size Count, ptr:int32 OutVert") \
    X(PolyTessellateByEdges, "Poly", "result", "anim Object, float Bulge") \
    X(PolyTessellateByCenters, "Poly", "result", "anim Object") \
    X(PolyElementFromFace, "Poly", "result", "anim Object, int32 Face, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(PolyBorderFromEdge, "Poly", "result", "anim Object, int32 Edge, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(PolyCloneFaces, "Poly", "result", "anim Object, uint32 CloneFlag, int32 ClearOriginal") \
    X(PolyWeldVerts, "Poly", "result", "anim Object, int32 A, int32 B, ptr:int32 OutWelded") \
    X(PolyWeldEdge, "Poly", "result", "anim Object, int32 Edge, ptr:int32 OutWelded") \
    X(PolyFlipNormal, "Poly", "result", "anim Object, int32 Face") \
    X(PolyAutoSmooth, "Poly", "result", "anim Object, float Threshold, uint32 FaceFlag, ptr:int32 OutDone") \
    X(PolyVDataCount, "Poly", "result", "anim Object, ptr:int32 OutCount") \
    X(PolyVDataSupported, "Poly", "result", "anim Object, int32 Channel, ptr:int32 OutSupported") \
    X(PolySetVDataSupport, "Poly", "result", "anim Object, int32 Channel, int32 Support") \
    X(PolyVDataRead, "Poly", "result", "anim Object, int32 Channel, ptr:float OutValues, size Capacity, ptr:int32 OutWritten") \
    X(PolyVDataWrite, "Poly", "result", "anim Object, int32 Channel, cptr:float Values, size Count") \
    X(PolyFreeVData, "Poly", "result", "anim Object, int32 Channel") \
    X(PolyFreeAllVData, "Poly", "result", "anim Object") \
    X(PolyEDataCount, "Poly", "result", "anim Object, ptr:int32 OutCount") \
    X(PolyEDataSupported, "Poly", "result", "anim Object, int32 Channel, ptr:int32 OutSupported") \
    X(PolySetEDataSupport, "Poly", "result", "anim Object, int32 Channel, int32 Support") \
    X(PolyEDataRead, "Poly", "result", "anim Object, int32 Channel, ptr:float OutValues, size Capacity, ptr:int32 OutWritten") \
    X(PolyEDataWrite, "Poly", "result", "anim Object, int32 Channel, cptr:float Values, size Count") \
    X(PolyFreeEData, "Poly", "result", "anim Object, int32 Channel") \
    X(PolyFreeAllEData, "Poly", "result", "anim Object") \
    X(PatchSetNumVerts, "Patch", "result", "anim Object, int32 Count, int32 Keep, ptr:int32 OutDone") \
    X(PatchSetNumVecs, "Patch", "result", "anim Object, int32 Count, int32 Keep, ptr:int32 OutDone") \
    X(PatchSetNumPatches, "Patch", "result", "anim Object, int32 Count, int32 Keep, ptr:int32 OutDone") \
    X(PatchSetNumEdges, "Patch", "result", "anim Object, int32 Count, int32 Keep, ptr:int32 OutDone") \
    X(PatchMakeQuad, "Patch", "result", "anim Object, int32 Index, cptr:int32 Verts, cptr:int32 Vecs, cptr:int32 Interiors, uint32 SmGroup, ptr:int32 OutMade") \
    X(PatchMakeTri, "Patch", "result", "anim Object, int32 Index, cptr:int32 Verts, cptr:int32 Vecs, cptr:int32 Interiors, uint32 SmGroup, ptr:int32 OutMade") \
    X(PatchBuildLinkages, "Patch", "result", "anim Object, int32 Patch, ptr:int32 OutValid") \
    X(PatchComputeInteriors, "Patch", "result", "anim Object") \
    X(PatchComputeAux, "Patch", "result", "anim Object") \
    X(PatchVertexCount, "Patch", "result", "anim Object, ptr:int32 OutCount") \
    X(PatchVecCount, "Patch", "result", "anim Object, ptr:int32 OutCount") \
    X(PatchCount, "Patch", "result", "anim Object, ptr:int32 OutCount") \
    X(PatchEdgeCount, "Patch", "result", "anim Object, ptr:int32 OutCount") \
    X(PatchVertsRead, "Patch", "result", "anim Object, ptr:MaxMcpPatchVert OutVerts, size Capacity, ptr:int32 OutWritten") \
    X(PatchVecsRead, "Patch", "result", "anim Object, ptr:MaxMcpPatchVec OutVecs, size Capacity, ptr:int32 OutWritten") \
    X(PatchesRead, "Patches", "result", "anim Object, ptr:MaxMcpPatch OutPatches, size Capacity, ptr:int32 OutWritten") \
    X(PatchesWrite, "Patches", "result", "anim Object, cptr:MaxMcpPatch Patches, size Count") \
    X(PatchEdgesRead, "Patch", "result", "anim Object, ptr:MaxMcpPatchEdge OutEdges, size Capacity, ptr:int32 OutWritten") \
    X(PatchVertVectorsRead, "Patch", "result", "anim Object, int32 Vert, ptr:int32 OutVectors, size Capacity, ptr:int32 OutWritten") \
    X(PatchVertPatchesRead, "Patch", "result", "anim Object, int32 Vert, ptr:int32 OutPatches, size Capacity, ptr:int32 OutWritten") \
    X(PatchVertEdgesRead, "Patch", "result", "anim Object, int32 Vert, ptr:int32 OutEdges, size Capacity, ptr:int32 OutWritten") \
    X(PatchVecPatchesRead, "Patch", "result", "anim Object, int32 Vec, ptr:int32 OutPatches, size Capacity, ptr:int32 OutWritten") \
    X(PatchEdgePatchesRead, "Patch", "result", "anim Object, int32 Edge, ptr:int32 OutPatches, size Capacity, ptr:int32 OutWritten") \
    X(PatchVertsWrite, "Patch", "result", "anim Object, cptr:MaxMcpPatchVert Verts, size Count") \
    X(PatchVecsWrite, "Patch", "result", "anim Object, cptr:MaxMcpPatchVec Vecs, size Count") \
    X(PatchSetSmGroup, "Patch", "result", "anim Object, int32 Patch, uint32 SmGroup") \
    X(PatchSetFlags, "Patch", "result", "anim Object, int32 Patch, uint32 Flags") \
    X(PatchMatIdRead, "Patch", "result", "anim Object, int32 Patch, ptr:uint32 OutMaterial") \
    X(PatchMatIdWrite, "Patch", "result", "anim Object, int32 Patch, uint32 Material") \
    X(PatchViewTessRead, "Patch", "result", "anim Object, ptr:MaxMcpTessApprox OutTess") \
    X(PatchViewTessWrite, "Patch", "result", "anim Object, cptr:MaxMcpTessApprox Tess") \
    X(PatchProdTessRead, "Patch", "result", "anim Object, ptr:MaxMcpTessApprox OutTess") \
    X(PatchProdTessWrite, "Patch", "result", "anim Object, cptr:MaxMcpTessApprox Tess") \
    X(PatchDispTessRead, "Patch", "result", "anim Object, ptr:MaxMcpTessApprox OutTess") \
    X(PatchDispTessWrite, "Patch", "result", "anim Object, cptr:MaxMcpTessApprox Tess") \
    X(PatchTessFlagsRead, "Patch", "result", "anim Object, ptr:MaxMcpPatchTessFlags OutFlags") \
    X(PatchTessFlagsWrite, "Patch", "result", "anim Object, cptr:MaxMcpPatchTessFlags Flags") \
    X(PatchSurfaceRead, "Patch", "result", "anim Object, ptr:MaxMcpPatchSurface OutSurface") \
    X(PatchSurfaceWrite, "Patch", "result", "anim Object, cptr:MaxMcpPatchSurface Surface") \
    X(PatchInvalidateGeomCache, "Patch", "result", "anim Object") \
    X(PatchInvalidateMesh, "Patch", "result", "anim Object") \
    X(PatchMapCount, "Patch", "result", "anim Object, ptr:int32 OutCount") \
    X(PatchMapChannelCount, "Patch", "result", "anim Object, ptr:int32 OutCount") \
    X(PatchSetNumMaps, "Patch", "result", "anim Object, int32 Count, int32 Keep") \
    X(PatchMapSupport, "Patch", "result", "anim Object, int32 Channel, ptr:int32 OutSupported") \
    X(PatchSetMapSupport, "Patch", "result", "anim Object, int32 Channel, int32 Init") \
    X(PatchMapVertCount, "Patch", "result", "anim Object, int32 Channel, ptr:int32 OutCount") \
    X(PatchSetNumMapVerts, "Patch", "result", "anim Object, int32 Channel, int32 Count, int32 Keep, ptr:int32 OutDone") \
    X(PatchSetNumMapPatches, "Patch", "result", "anim Object, int32 Channel, int32 Count, int32 Keep, int32 OldCount, ptr:int32 OutDone") \
    X(PatchMapVertsRead, "Patch", "result", "anim Object, int32 Channel, ptr:float OutVerts, size Capacity, ptr:int32 OutWritten") \
    X(PatchMapVertsWrite, "Patch", "result", "anim Object, int32 Channel, cptr:float Verts, size Count") \
    X(PatchMapPatchesRead, "Patch", "result", "anim Object, int32 Channel, ptr:MaxMcpPatchMapFace OutFaces, size Capacity, ptr:int32 OutWritten") \
    X(PatchMapPatchesWrite, "Patch", "result", "anim Object, int32 Channel, cptr:MaxMcpPatchMapFace Faces, size Count") \
    X(PatchDeleteParts, "Patch", "result", "anim Object, cptr:int32 DelVerts, size VertCount, cptr:int32 DelPatches, size PatchCount") \
    X(ShapeKnotCount, "Shape", "result", "node Node, int32 Spline, ptr:int32 OutCount") \
    X(ShapeKnotRead, "Shape", "result", "node Node, int32 Spline, int32 Knot, ptr:MaxMcpKnot OutKnot") \
    X(ShapeSplineClosed, "Shape", "result", "node Node, int32 Spline, ptr:int32 OutClosed") \
    X(ShapeSegCount, "Shape", "result", "node Node, int32 Spline, ptr:int32 OutCount") \
    X(ShapeSegMatId, "Shape", "result", "node Node, int32 Spline, int32 Segment, ptr:uint32 OutMaterial") \
    X(ShapeBezierSplineCount, "Shape", "result", "node Node, int32 Time, ptr:int32 OutCount") \
    X(ShapeBezierKnotCount, "Shape", "result", "node Node, int32 Time, int32 Spline, ptr:int32 OutCount") \
    X(ShapeBezierKnotRead, "Shape", "result", "node Node, int32 Time, int32 Spline, int32 Knot, ptr:MaxMcpKnot OutKnot") \
    X(ShapeBezierSplineClosed, "Shape", "result", "node Node, int32 Time, int32 Spline, ptr:int32 OutClosed") \
    X(ShapeSplineAppend, "Shape", "result", "node Node, int32 InitialType, int32 DragType, ptr:int32 OutIndex") \
    X(ShapeSplineInsert, "Shape", "result", "node Node, int32 Index, int32 InitialType, int32 DragType, ptr:int32 OutInserted") \
    X(ShapeKnotAdd, "Shape", "result", "node Node, int32 Spline, int32 Where, cptr:MaxMcpKnot Knot, ptr:int32 OutAdded") \
    X(ShapeKnotWrite, "Shape", "result", "node Node, int32 Spline, int32 Knot, cptr:MaxMcpKnot NewKnot") \
    X(ShapeKnotFlagsWrite, "Shape", "result", "node Node, int32 Spline, int32 Knot, uint32 Mask, int32 Value") \
    X(ShapeSetKnotType, "Shape", "result", "node Node, int32 Spline, int32 Knot, int32 Type, ptr:int32 OutSet") \
    X(ShapeSetLineType, "Shape", "result", "node Node, int32 Spline, int32 Segment, int32 Type, ptr:int32 OutSet") \
    X(ShapeSplineInitialKnotType, "Shape", "result", "node Node, int32 Spline, int32 Type, ptr:int32 OutSet") \
    X(ShapeSplineDragKnotType, "Shape", "result", "node Node, int32 Spline, int32 Type, ptr:int32 OutSet") \
    X(ShapeSetSplineClosed, "Shape", "result", "node Node, int32 Spline, int32 Closed, ptr:int32 OutSet") \
    X(ShapeSetSegMatId, "Shape", "result", "node Node, int32 Spline, int32 Segment, uint32 Material") \
    X(ShapeComputeBezPoints, "Shape", "result", "node Node, int32 Spline") \
    X(ShapeKnotDelete, "Shape", "result", "node Node, int32 Spline, int32 Knot, ptr:int32 OutDeleted") \
    X(ShapeCurveCount, "Shape", "result", "node Node, int32 Time, ptr:int32 OutCount") \
    X(ShapeCurveClosed, "Shape", "result", "node Node, int32 Time, int32 Curve, ptr:int32 OutClosed") \
    X(ShapeCurveInterp, "Shape", "result", "node Node, int32 Time, int32 Curve, float Param, int32 ParamType, ptr:float OutPoint") \
    X(ShapeCurveTangent, "Shape", "result", "node Node, int32 Time, int32 Curve, float Param, int32 ParamType, ptr:float OutTangent") \
    X(ShapeCurveLength, "Shape", "result", "node Node, int32 Time, int32 Curve, ptr:float OutLength") \
    X(ShapePieceCount, "Shape", "result", "node Node, int32 Time, int32 Curve, ptr:int32 OutCount") \
    X(ShapePieceInterp, "Shape", "result", "node Node, int32 Time, int32 Curve, int32 Piece, float Param, int32 ParamType, ptr:float OutPoint") \
    X(ShapePieceTangent, "Shape", "result", "node Node, int32 Time, int32 Curve, int32 Piece, float Param, int32 ParamType, ptr:float OutTangent") \
    X(ShapePieceMatId, "Shape", "result", "node Node, int32 Time, int32 Curve, int32 Piece, ptr:uint32 OutMaterial") \
    X(ShapeCanMakeBezier, "Shape", "result", "node Node, int32 Time, ptr:int32 OutCan") \
    X(ShapeRenderRead, "Shape", "result", "node Node, int32 Time, ptr:MaxMcpShapeRender OutRender") \
    X(ShapeRenderWrite, "Shape", "result", "node Node, int32 Time, cptr:MaxMcpShapeRender Render") \
    X(CombineMeshesTM, "Combine", "result", "anim Object, anim MeshA, anim MeshB, cptr:float MatrixA, cptr:float MatrixB, int32 WhichInvert") \
    X(MeshSpecifyNormals, "Mesh", "result", "anim Object") \
    X(MeshSpecifiedNormalsPresent, "Mesh", "result", "anim Object, ptr:int32 OutPresent") \
    X(MeshClearSpecifiedNormals, "Mesh", "result", "anim Object") \
    X(NormalSpecFaceCount, "Normal", "result", "anim Object, ptr:int32 OutCount") \
    X(NormalSpecSetFaceCount, "Normal", "result", "anim Object, int32 Count, ptr:int32 OutOk") \
    X(NormalSpecNormalCount, "Normal", "result", "anim Object, ptr:int32 OutCount") \
    X(NormalSpecSetNormalCount, "Normal", "result", "anim Object, int32 Count, ptr:int32 OutOk") \
    X(NormalSpecClear, "Normal", "result", "anim Object") \
    X(NormalSpecClearAndFree, "Normal", "result", "anim Object") \
    X(NormalSpecClearNormals, "Normal", "result", "anim Object") \
    X(NormalSpecNewNormal, "Normal", "int32", "anim Object, cptr:float Normal, int32 Explicit, ptr:result OutResult") \
    X(NormalSpecNormalsRead, "Normal", "result", "anim Object, ptr:float OutNormals, size Capacity, ptr:int32 OutWritten") \
    X(NormalSpecNormalsWrite, "Normal", "result", "anim Object, cptr:float Normals, size Count") \
    X(NormalSpecNormalRead, "Normal", "result", "anim Object, int32 NormalIndex, ptr:float OutNormal") \
    X(NormalSpecNormalWrite, "Normal", "result", "anim Object, int32 NormalIndex, cptr:float Normal") \
    X(NormalSpecExplicitRead, "Normal", "result", "anim Object, int32 NormalIndex, ptr:int32 OutExplicit") \
    X(NormalSpecExplicitWrite, "Normal", "result", "anim Object, int32 NormalIndex, int32 Explicit") \
    X(NormalSpecAllExplicitWrite, "Normal", "result", "anim Object, int32 Explicit") \
    X(NormalSpecAnyExplicit, "Normal", "result", "anim Object, ptr:int32 OutAny") \
    X(NormalSpecMakeExplicit, "Normal", "result", "anim Object, int32 UseSelection, cptr:uint32 SelectionBits, int32 BitCount, int32 Value, ptr:int32 OutChanged") \
    X(NormalSpecFacesRead, "Normal", "result", "anim Object, ptr:MaxMcpNormalFace OutFaces, size Capacity, ptr:int32 OutWritten") \
    X(NormalSpecFacesWrite, "Normal", "result", "anim Object, cptr:MaxMcpNormalFace Faces, size Count") \
    X(NormalSpecFaceNormalRead, "Normal", "result", "anim Object, int32 Face, int32 Corner, ptr:float OutNormal") \
    X(NormalSpecFaceNormalWrite, "Normal", "result", "anim Object, int32 Face, int32 Corner, cptr:float Normal") \
    X(NormalSpecFaceIndexRead, "Normal", "result", "anim Object, int32 Face, int32 Corner, ptr:int32 OutNormalIndex") \
    X(NormalSpecFaceIndexWrite, "Normal", "result", "anim Object, int32 Face, int32 Corner, int32 NormalIndex") \
    X(NormalSpecFaceCornerSpecifiedRead, "Normal", "result", "anim Object, int32 Face, int32 Corner, ptr:int32 OutSpecified") \
    X(NormalSpecFaceCornerSpecifiedWrite, "Normal", "result", "anim Object, int32 Face, int32 Corner, int32 Specified") \
    X(NormalSpecFaceClear, "Normal", "result", "anim Object, int32 Face") \
    X(NormalSpecSelectionRead, "Normal", "result", "anim Object, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(NormalSpecSelectionWrite, "Normal", "result", "anim Object, cptr:uint32 Bits, int32 BitCount") \
    X(NormalSpecFlagRead, "Normal", "result", "anim Object, uint32 Flag, ptr:int32 OutSet") \
    X(NormalSpecFlagWrite, "Normal", "result", "anim Object, uint32 Flags, int32 Value") \
    X(NormalSpecDisplayLengthRead, "Normal", "result", "anim Object, ptr:float OutLength") \
    X(NormalSpecDisplayLengthWrite, "Normal", "result", "anim Object, float Length") \
    X(NormalSpecBuildNormals, "Normal", "result", "anim Object") \
    X(NormalSpecComputeNormals, "Normal", "result", "anim Object") \
    X(NormalSpecCheckNormals, "Normal", "result", "anim Object") \
    X(MeshVDataChannelCount, "Mesh", "result", "anim Object, ptr:int32 OutCount") \
    X(MeshSetVDataChannelCount, "Mesh", "result", "anim Object, int32 Count, int32 Keep") \
    X(MeshVDataSupported, "Mesh", "result", "anim Object, int32 Channel, ptr:int32 OutSupported") \
    X(MeshSetVDataSupport, "Mesh", "result", "anim Object, int32 Channel, int32 Support") \
    X(MeshVDataType, "Mesh", "result", "anim Object, int32 Channel, ptr:int32 OutType") \
    X(VertexDataChannelType, "Vertex", "result", "int32 Channel, ptr:int32 OutType") \
    X(MeshVDataElementCount, "Mesh", "result", "anim Object, int32 Channel, ptr:int32 OutCount") \
    X(MeshSetVDataElementCount, "Mesh", "result", "anim Object, int32 Channel, int32 Count, int32 Keep") \
    X(MeshVDataRead, "Mesh", "result", "anim Object, int32 Channel, ptr:float OutValues, size Capacity, ptr:int32 OutWritten") \
    X(MeshVDataWrite, "Mesh", "result", "anim Object, int32 Channel, cptr:float Values, size Count") \
    X(MeshFreeVData, "Mesh", "result", "anim Object, int32 Channel") \
    X(MeshFreeAllVData, "Mesh", "result", "anim Object") \
    X(MeshVertHideRead, "Mesh", "result", "anim Object, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(MeshVertHideWrite, "Mesh", "result", "anim Object, cptr:uint32 Bits, int32 BitCount") \
    X(ObjectSupportsNamedSubSels, "Object", "result", "anim Object, ptr:int32 OutSupports") \
    X(ObjectNamedSelSetCount, "Object", "result", "anim Object, ptr:int32 OutCount") \
    X(ObjectNamedSelSetName, "Object", "result", "anim Object, int32 Index, mutstr OutName, size Capacity") \
    X(ObjectSetNamedSelSetName, "Object", "result", "anim Object, int32 Index, cstr Name") \
    X(ObjectNewSetFromCurSel, "Object", "result", "anim Object, cstr Name") \
    X(ObjectNewSetByOperator, "Object", "result", "anim Object, cstr Name, cptr:int32 Sets, size SetCount, int32 Op") \
    X(ObjectActivateSubSelSet, "Object", "result", "anim Object, cstr Name") \
    X(ObjectRemoveSubSelSet, "Object", "result", "anim Object, cstr Name") \
    X(SceneNamedSelSetListChanged, "Scene", "result", "") \
    X(ObjectSubObjTypeCount, "Object", "result", "anim Object, ptr:int32 OutCount") \
    X(ObjectSubObjTypeName, "Object", "result", "anim Object, int32 Index, mutstr OutName, size Capacity") \
    X(ObjectSubObjectLevel, "Object", "result", "anim Object, ptr:int32 OutLevel") \
    X(PanelTaskMode, "Panel", "result", "ptr:int32 OutMode") \
    X(PanelSetTaskMode, "Panel", "result", "int32 Mode") \
    X(PanelSubObjectLevel, "Panel", "result", "ptr:int32 OutLevel") \
    X(PanelSubObjectLevelCount, "Panel", "result", "ptr:int32 OutCount") \
    X(PanelSetSubObjectLevel, "Panel", "result", "int32 Level, int32 Force") \
    X(MeshSelectModLevelRead, "Mesh", "result", "anim Anim, ptr:uint32 OutLevel") \
    X(MeshSelectModLevelWrite, "Mesh", "result", "anim Anim, uint32 Level") \
    X(MeshSelectModDataChanged, "Mesh", "result", "anim Anim") \
    X(MeshSelectVertSelRead, "Mesh", "result", "anim Anim, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(MeshSelectFaceSelRead, "Mesh", "result", "anim Anim, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(MeshSelectEdgeSelRead, "Mesh", "result", "anim Anim, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(MeshSelectVertSelWrite, "Mesh", "result", "anim Anim, int32 Time, cptr:uint32 Bits, int32 BitCount") \
    X(MeshSelectFaceSelWrite, "Mesh", "result", "anim Anim, int32 Time, cptr:uint32 Bits, int32 BitCount") \
    X(MeshSelectEdgeSelWrite, "Mesh", "result", "anim Anim, int32 Time, cptr:uint32 Bits, int32 BitCount") \
    X(MeshSelectHasWeights, "Mesh", "result", "anim Anim, ptr:int32 OutHas") \
    X(MeshSelectCanAssignWeights, "Mesh", "result", "anim Anim, ptr:int32 OutCan") \
    X(MeshSelectWeightsRead, "Mesh", "result", "anim Anim, int32 VertexCount, ptr:float OutWeights, size Capacity, ptr:int32 OutWritten") \
    X(MeshSelectWeightsWrite, "Mesh", "result", "anim Anim, int32 Time, cptr:float Weights, size Count") \
    X(MeshSelectNamedSetCount, "Mesh", "result", "anim Anim, int32 Level, ptr:int32 OutCount") \
    X(MeshSelectNamedSetName, "Mesh", "result", "anim Anim, int32 Level, int32 Index, mutstr OutName, size Capacity") \
    X(MeshSelectNamedSetId, "Mesh", "result", "anim Anim, int32 Level, int32 Index, ptr:uint32 OutId") \
    X(MeshSelectNamedSetBitsRead, "Mesh", "result", "anim Anim, int32 Level, int32 Index, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(MeshSelectNamedSetAppend, "Mesh", "result", "anim Anim, int32 Level, cstr Name, uint32 Id, cptr:uint32 Bits, int32 BitCount") \
    X(MeshSelectNamedSetBitsWrite, "Mesh", "result", "anim Anim, int32 Level, int32 Index, cptr:uint32 Bits, int32 BitCount") \
    X(MeshSelectNamedSetRename, "Mesh", "result", "anim Anim, int32 Level, cstr OldName, cstr NewName, ptr:int32 OutRenamed") \
    X(MeshSelectNamedSetDelete, "Mesh", "result", "anim Anim, int32 Level, int32 Index") \
    X(MeshSelectNamedSetsResize, "Mesh", "result", "anim Anim, int32 Level, int32 BitCount") \
    X(SplineSelectModLevelRead, "Spline", "result", "anim Anim, ptr:uint32 OutLevel") \
    X(SplineSelectModLevelWrite, "Spline", "result", "anim Anim, uint32 Level") \
    X(SplineSelectModDataChanged, "Spline", "result", "anim Anim") \
    X(SplineSelectVertSelRead, "Spline", "result", "anim Anim, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(SplineSelectSegmentSelRead, "Spline", "result", "anim Anim, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(SplineSelectSplineSelRead, "Spline", "result", "anim Anim, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(SplineSelectVertSelWrite, "Spline", "result", "anim Anim, int32 Time, cptr:uint32 Bits, int32 BitCount") \
    X(SplineSelectSegmentSelWrite, "Spline", "result", "anim Anim, int32 Time, cptr:uint32 Bits, int32 BitCount") \
    X(SplineSelectSplineSelWrite, "Spline", "result", "anim Anim, int32 Time, cptr:uint32 Bits, int32 BitCount") \
    X(SplineSelectNamedSetCount, "Spline", "result", "anim Anim, int32 Level, ptr:int32 OutCount") \
    X(SplineSelectNamedSetName, "Spline", "result", "anim Anim, int32 Level, int32 Index, mutstr OutName, size Capacity") \
    X(SplineSelectNamedSetId, "Spline", "result", "anim Anim, int32 Level, int32 Index, ptr:uint32 OutId") \
    X(SplineSelectNamedSetBitsRead, "Spline", "result", "anim Anim, int32 Level, int32 Index, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(SplineSelectNamedSetAppend, "Spline", "result", "anim Anim, int32 Level, cstr Name, uint32 Id, cptr:uint32 Bits, int32 BitCount") \
    X(SplineSelectNamedSetBitsWrite, "Spline", "result", "anim Anim, int32 Level, int32 Index, cptr:uint32 Bits, int32 BitCount") \
    X(SplineSelectNamedSetRename, "Spline", "result", "anim Anim, int32 Level, cstr OldName, cstr NewName, ptr:int32 OutRenamed") \
    X(SplineSelectNamedSetDelete, "Spline", "result", "anim Anim, int32 Level, int32 Index") \
    X(SplineSelectNamedSetsResize, "Spline", "result", "anim Anim, int32 Level, int32 BitCount") \
    X(NodeDisposeTemporary, "Node", "result", "node Node") \
    X(NodeInvalidateRect, "Node", "result", "node Node, int32 t, int32 oldRect") \
    X(NodeDetach, "Node", "result", "node Node, int32 t, int32 keepTM") \
    X(NodeNumberOfChildren, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeHide, "Node", "result", "node Node, int32 onOff") \
    X(NodeIsHidden, "Node", "result", "node Node, uint32 hflags, int32 forRenderer, ptr:int32 OutValue") \
    X(NodeIsNodeHidden, "Node", "result", "node Node, int32 forRenderer, ptr:int32 OutValue") \
    X(NodeIsFrozen, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeFreeze, "Node", "result", "node Node, int32 onOff") \
    X(NodeSetShowFrozenWithMtl, "Node", "result", "node Node, int32 onOff") \
    X(NodeShowFrozenWithMtl, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeXRayMtl, "Node", "result", "node Node, int32 onOff") \
    X(NodeHasXRayMtl, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBoxMode, "Node", "result", "node Node, int32 onOff") \
    X(NodeGetBoxMode, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeAllEdges, "Node", "result", "node Node, int32 onOff") \
    X(NodeGetAllEdges, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeVertTicks, "Node", "result", "node Node, int32 onOff") \
    X(NodeGetVertTicks, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBackCull, "Node", "result", "node Node, int32 onOff") \
    X(NodeGetBackCull, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeUnhideObjectAndLayer, "Node", "result", "node Node, int32 dolayer") \
    X(NodeIsObjectHidden, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeUnfreezeObjectAndLayer, "Node", "result", "node Node, int32 dolayer") \
    X(NodeIsObjectFrozen, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeHasObjectXRayMtl, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeIgnoreExtents, "Node", "result", "node Node, int32 onOff") \
    X(NodeGetIgnoreExtents, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetCastShadows, "Node", "result", "node Node, int32 onOff") \
    X(NodeCastShadows, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetRcvShadows, "Node", "result", "node Node, int32 onOff") \
    X(NodeRcvShadows, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetMotBlur, "Node", "result", "node Node, int32 kind") \
    X(NodeMotBlur, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeGetImageBlurMultiplier, "Node", "result", "node Node, int32 t, ptr:float OutValue") \
    X(NodeSetImageBlurMultiplier, "Node", "result", "node Node, int32 t, float m") \
    X(NodeGetMotBlurOnOff, "Node", "result", "node Node, int32 t, ptr:int32 OutValue") \
    X(NodeSetMotBlurOnOff, "Node", "result", "node Node, int32 t, int32 m") \
    X(NodeSetRenderable, "Node", "result", "node Node, int32 onOff") \
    X(NodeRenderable, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetApplyAtmospherics, "Node", "result", "node Node, int32 onOff") \
    X(NodeApplyAtmospherics, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetPrimaryVisibility, "Node", "result", "node Node, int32 onOff") \
    X(NodeGetPrimaryVisibility, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetSecondaryVisibility, "Node", "result", "node Node, int32 onOff") \
    X(NodeGetSecondaryVisibility, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetGenerateCaustics, "Node", "result", "node Node, int32 onOff") \
    X(NodeGenerateCaustics, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetRcvCaustics, "Node", "result", "node Node, int32 onOff") \
    X(NodeRcvCaustics, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetGenerateGlobalIllum, "Node", "result", "node Node, int32 onOff") \
    X(NodeGenerateGlobalIllum, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetRcvGlobalIllum, "Node", "result", "node Node, int32 onOff") \
    X(NodeRcvGlobalIllum, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetCVertMode, "Node", "result", "node Node, int32 onOff") \
    X(NodeGetCVertMode, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetShadeCVerts, "Node", "result", "node Node, int32 onOff") \
    X(NodeGetShadeCVerts, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeGetVertexColorType, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetVertexColorType, "Node", "result", "node Node, int32 nvct") \
    X(NodeGetVertexColorMapChannel, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetVertexColorMapChannel, "Node", "result", "node Node, int32 vcmc") \
    X(NodeGetTrajectoryON, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetTrajectoryON, "Node", "result", "node Node, int32 onOff") \
    X(NodeShowBone, "Node", "result", "node Node, int32 boneVis") \
    X(NodeBoneAsLine, "Node", "result", "node Node, int32 onOff") \
    X(NodeIsBoneShowing, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeIsBoneOnly, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetTargetNodePair, "Node", "result", "node Node, int32 onOff") \
    X(NodeGetTargetNodePair, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeGetWireColor, "Node", "result", "node Node, ptr:uint32 OutValue") \
    X(NodeDependent, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeIsRootNode, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeGetTransformLock, "Node", "result", "node Node, int32 type, int32 axis, ptr:int32 OutValue") \
    X(NodeSetTransformLock, "Node", "result", "node Node, int32 type, int32 axis, int32 onOff") \
    X(NodeIsTarget, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetIsTarget, "Node", "result", "node Node, int32 b") \
    X(NodeSetVisibility, "Node", "result", "node Node, int32 t, float vis") \
    X(NodeGetInheritVisibility, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetInheritVisibility, "Node", "result", "node Node, int32 onOff") \
    X(NodeSetRenderOccluded, "Node", "result", "node Node, int32 onOff") \
    X(NodeGetRenderOccluded, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeNumMtls, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeAlignToParent, "Node", "result", "node Node, int32 t") \
    X(NodeAlignToWorld, "Node", "result", "node Node, int32 t") \
    X(NodeFlagForeground, "Node", "result", "node Node, int32 t, int32 notify") \
    X(NodeIsActiveGrid, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeGetGBufID, "Node", "result", "node Node, ptr:uint32 OutValue") \
    X(NodeSetGBufID, "Node", "result", "node Node, uint32 id") \
    X(NodeGetRenderID, "Node", "result", "node Node, ptr:uint32 OutValue") \
    X(NodeSetRenderID, "Node", "result", "node Node, uint32 id") \
    X(NodeGetHandle, "Node", "result", "node Node, ptr:uint32 OutValue") \
    X(NodeIsGroupMember, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeIsOpenGroupMember, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeIsOpenGroupHead, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetGroupMember, "Node", "result", "node Node, int32 b") \
    X(NodeSetGroupHead, "Node", "result", "node Node, int32 b") \
    X(NodeSetGroupMemberOpen, "Node", "result", "node Node, int32 b") \
    X(NodeSetGroupHeadOpen, "Node", "result", "node Node, int32 b") \
    X(NodeGetPosTaskWeight, "Node", "result", "node Node, ptr:float OutValue") \
    X(NodeGetRotTaskWeight, "Node", "result", "node Node, ptr:float OutValue") \
    X(NodeSetPosTaskWeight, "Node", "result", "node Node, float w") \
    X(NodeSetRotTaskWeight, "Node", "result", "node Node, float w") \
    X(NodeGetTaskAxisState, "Node", "result", "node Node, int32 which, int32 axis, ptr:int32 OutValue") \
    X(NodeSetTaskAxisState, "Node", "result", "node Node, int32 which, int32 axis, int32 onOff") \
    X(NodeGetTaskAxisStateBits, "Node", "result", "node Node, ptr:uint32 OutValue") \
    X(NodeGetXRefFileCount, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeDeleteXRefFile, "Node", "result", "node Node, int32 i, ptr:int32 OutValue") \
    X(NodeBindXRefFile, "Node", "result", "node Node, int32 i, ptr:int32 OutValue") \
    X(NodeDeleteAllXRefs, "Node", "result", "node Node") \
    X(NodeReloadXRef, "Node", "result", "node Node, int32 i, ptr:int32 OutValue") \
    X(NodeFlagXrefChanged, "Node", "result", "node Node, int32 i") \
    X(NodeUpdateChangedXRefs, "Node", "result", "node Node, int32 redraw, ptr:int32 OutValue") \
    X(NodeAttemptToResolveUnresolvedXRefs, "Node", "result", "node Node") \
    X(NodeGetXRefFlags, "Node", "result", "node Node, int32 i, ptr:uint32 OutValue") \
    X(NodeSetXRefFlags, "Node", "result", "node Node, int32 i, uint32 flag, int32 onOff") \
    X(NodeIsSceneXRefNode, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeIsSceneNode, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeSetBoneNodeOnOff, "Node", "result", "node Node, int32 onOff, int32 t") \
    X(NodeSetBoneAutoAlign, "Node", "result", "node Node, int32 onOff") \
    X(NodeSetBoneFreezeLen, "Node", "result", "node Node, int32 onOff") \
    X(NodeSetBoneScaleType, "Node", "result", "node Node, int32 which") \
    X(NodeSetBoneAxis, "Node", "result", "node Node, int32 which") \
    X(NodeSetBoneAxisFlip, "Node", "result", "node Node, int32 onOff") \
    X(NodeGetBoneNodeOnOff, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeGetBoneNodeOnOff_T, "Node", "result", "node Node, int32 t, ptr:int32 OutValue") \
    X(NodeGetBoneAutoAlign, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeGetBoneFreezeLen, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeGetBoneScaleType, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeGetBoneAxis, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeGetBoneAxisFlip, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeRealignBoneToChild, "Node", "result", "node Node, int32 t") \
    X(NodeResetBoneStretch, "Node", "result", "node Node, int32 t") \
    X(NodeWasLoadedByLastMerge, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(ControllerNumKeys, "Controller", "int32", "anim Anim, ptr:result OutResult") \
    X(ControllerKeyTime, "Controller", "int32", "anim Anim, int32 Index, ptr:result OutResult") \
    X(ControllerKeyIndexAtTime, "Controller", "int32", "anim Anim, int32 Time, ptr:result OutResult") \
    X(ControllerIsKeyAtTime, "Controller", "int32", "anim Anim, int32 Time, uint32 Flags, ptr:result OutResult") \
    X(ControllerKeyTimes, "Controller", "result", "anim Anim, int32 RangeStart, int32 RangeEnd, uint32 Flags, ptr:int32 OutTimes, size Capacity, ptr:int32 OutWritten, ptr:int32 OutSkipped") \
    X(ControllerKeySelState, "Controller", "result", "anim Anim, int32 RangeStart, int32 RangeEnd, uint32 Flags, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutSkipped") \
    X(ControllerKeySelected, "Controller", "int32", "anim Anim, int32 Index, ptr:result OutResult") \
    X(ControllerNumSelKeys, "Controller", "int32", "anim Anim, ptr:result OutResult") \
    X(ControllerFlaggedKeyIndex, "Controller", "int32", "anim Anim, ptr:result OutResult") \
    X(ControllerSupportsTimeOperations, "Controller", "int32", "anim Anim, ptr:result OutResult") \
    X(ControllerGetORT, "Controller", "int32", "anim Controller, int32 Which, ptr:result OutResult") \
    X(ControllerORTsEnabled, "Controller", "int32", "anim Controller, ptr:result OutResult") \
    X(AnimLocked, "Anim", "int32", "anim Anim, int32 CheckOverride, ptr:result OutResult") \
    X(AnimLockIsComponent, "Anim", "int32", "anim Anim, ptr:result OutResult") \
    X(AnimLockable, "Anim", "int32", "anim Anim, anim Client, int32 SubNum, ptr:result OutResult") \
    X(AnimSubAnimLocked, "Anim", "int32", "anim Client, int32 SubNum, int32 CheckOverride, ptr:result OutResult") \
    X(AnimSubAnimLockable, "Anim", "int32", "anim Client, int32 SubNum, ptr:result OutResult") \
    X(SceneUnlockOverride, "Scene", "int32", "ptr:result OutResult") \
    X(AnimOverrideUnlocked, "Anim", "int32", "anim Anim, ptr:result OutResult") \
    X(SceneUberUnlockDepth, "Scene", "int32", "ptr:result OutResult") \
    X(SceneAnimateState, "Scene", "int32", "ptr:result OutResult") \
    X(SceneAnimatingAt, "Scene", "int32", "int32 Time, ptr:result OutResult") \
    X(SceneKeyingAt, "Scene", "int32", "int32 Time, ptr:result OutResult") \
    X(SceneKeyModeState, "Scene", "int32", "ptr:result OutResult") \
    X(SceneKeyModeSuspended, "Scene", "int32", "ptr:result OutResult") \
    X(ControllerKeyAdd, "Controller", "result", "anim Anim, int32 Time, uint32 Flags") \
    X(ControllerInsertTime, "Controller", "result", "anim Anim, int32 InsertAt, int32 Amount") \
    X(ControllerKeyCopyFromTime, "Controller", "result", "anim Anim, int32 SourceTime, int32 DestTime, uint32 Flags") \
    X(ControllerKeySelect, "Controller", "result", "anim Anim, int32 Index, int32 Selected") \
    X(ControllerEditTimeRange, "Controller", "result", "anim Anim, int32 RangeStart, int32 RangeEnd, uint32 Flags") \
    X(ControllerReverseTime, "Controller", "result", "anim Anim, int32 RangeStart, int32 RangeEnd, uint32 Flags") \
    X(ControllerScaleTime, "Controller", "result", "anim Anim, int32 RangeStart, int32 RangeEnd, float Scale") \
    X(ControllerSetORT, "Controller", "result", "anim Controller, int32 Ort, int32 Which") \
    X(ControllerEnableORTs, "Controller", "result", "anim Controller, int32 Enable") \
    X(AnimSetLocked, "Anim", "result", "anim Anim, int32 Locked, int32 LockSubAnims, anim Client, int32 SubNum") \
    X(AnimSubAnimSetLocked, "Anim", "result", "anim Client, int32 SubNum, int32 Locked, int32 LockSubAnims, anim Anim") \
    X(SceneSetUnlockOverride, "Scene", "result", "int32 OnOff") \
    X(SceneUberUnlockPush, "Scene", "result", "") \
    X(SceneUberUnlockPop, "Scene", "result", "") \
    X(SceneAnimateOn, "Scene", "result", "") \
    X(SceneAnimateOff, "Scene", "result", "") \
    X(SceneAnimateSuspend, "Scene", "result", "") \
    X(SceneAnimateResume, "Scene", "result", "") \
    X(SceneSetKeyMode, "Scene", "result", "int32 OnOff") \
    X(SceneKeyModeSuspend, "Scene", "result", "") \
    X(SceneKeyModeResume, "Scene", "result", "") \
    X(ControllerKeyDeleteAtTime, "Controller", "result", "anim Anim, int32 Time") \
    X(ControllerKeyDeleteByIndex, "Controller", "result", "anim Anim, int32 Index") \
    X(ControllerKeysDelete, "Controller", "result", "anim Anim, uint32 Flags") \
    X(ControllerDeleteTime, "Controller", "result", "anim Anim, int32 RangeStart, int32 RangeEnd, uint32 Flags") \
    X(ControllerValueQuat, "Controller", "result", "anim Controller, int32 Time, ptr:float OutQuat, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(ControllerValueScale, "Controller", "result", "anim Controller, int32 Time, ptr:float OutScale, ptr:float OutScaleRotation, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(ControllerValuePoint4, "Controller", "result", "anim Controller, int32 Time, int32 Method, ptr:float InOutValue, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(ControllerValueMatrix3, "Controller", "result", "anim Controller, int32 Time, ptr:float InOutMatrix, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(ControllerSetValueFloat, "Controller", "result", "anim Controller, int32 Time, float Value, int32 Commit, int32 Method") \
    X(ControllerSetValuePoint3, "Controller", "result", "anim Controller, int32 Time, cptr:float Value, int32 Commit, int32 Method") \
    X(ControllerSetValuePoint4, "Controller", "result", "anim Controller, int32 Time, cptr:float Value, int32 Commit, int32 Method") \
    X(ControllerSetValueQuat, "Controller", "result", "anim Controller, int32 Time, cptr:float Quat, int32 Commit") \
    X(ControllerSetValueAngAxis, "Controller", "result", "anim Controller, int32 Time, cptr:float AxisAngle, int32 Commit") \
    X(ControllerSetValueScale, "Controller", "result", "anim Controller, int32 Time, cptr:float Scale, cptr:float ScaleRotation, int32 Commit, int32 Method") \
    X(ControllerSetValueXForm, "Controller", "result", "anim Controller, int32 Time, cptr:MaxMcpXFormPacket Packet, int32 Commit") \
    X(ControllerCommitValue, "Controller", "result", "anim Controller, int32 Time") \
    X(ControllerRestoreValue, "Controller", "result", "anim Controller, int32 Time") \
    X(ControllerNumMorphTargets, "Controller", "int32", "anim Controller, ptr:result OutResult") \
    X(ControllerMorphTarget, "Controller", "result", "anim Controller, int32 Index, ptr:anim OutTarget") \
    X(ControllerMorphTargetName, "Controller", "result", "anim Controller, int32 Index, mutstr OutName, size Capacity") \
    X(ControllerMorphTargetTM, "Controller", "result", "anim Controller, int32 Index, ptr:float OutRow") \
    X(ControllerMorphTargetValid, "Controller", "int32", "anim Controller, int32 Time, anim Object, ptr:result OutResult") \
    X(ControllerMorphFlaggedTarget, "Controller", "int32", "anim Controller, ptr:result OutResult") \
    X(ControllerMorphTargetAdd, "Controller", "result", "anim Controller, int32 Time, anim Object, cstr Name, cptr:float Row, int32 ForceCreate, int32 Commit") \
    X(ControllerSetMorphTargetName, "Controller", "result", "anim Controller, int32 Index, cstr Name") \
    X(ControllerMorphTargetDelete, "Controller", "result", "anim Controller, int32 Index") \
    X(SkinBoneCount, "Skin", "result", "anim Modifier, ptr:int32 OutCount") \
    X(SkinBone, "Skin", "result", "anim Modifier, int32 Bone, ptr:node OutBone") \
    X(SkinBoneProperty, "Skin", "result", "anim Modifier, int32 Bone, ptr:uint32 OutFlags") \
    X(SkinBoneFlatCount, "Skin", "result", "anim Modifier, ptr:int32 OutCount") \
    X(SkinBoneFlat, "Skin", "result", "anim Modifier, int32 BoneFlat, ptr:node OutBone") \
    X(SkinBoneName, "Skin", "result", "anim Modifier, int32 BoneFlat, mutstr OutName, size Capacity") \
    X(SkinSelectedBone, "Skin", "result", "anim Modifier, ptr:int32 OutBoneFlat") \
    X(SkinBoneEndPoints, "Skin", "result", "anim Modifier, int32 BoneFlat, ptr:float OutStart, ptr:float OutEnd") \
    X(SkinBoneTm, "Skin", "result", "anim Modifier, int32 BoneFlat, ptr:float OutRow") \
    X(SkinBoneInitTm, "Skin", "result", "anim Modifier, node Bone, int32 ObjectOffset, ptr:float OutRow") \
    X(SkinInitTm, "Skin", "result", "anim Modifier, node SkinNode, int32 ObjectOffset, ptr:float OutRow") \
    X(SkinRefFrame, "Skin", "result", "anim Modifier, ptr:int32 OutTime") \
    X(SkinDQBlending, "Skin", "result", "anim Modifier, ptr:int32 OutBlending") \
    X(SkinSetDQBlending, "Skin", "result", "anim Modifier, int32 Blending") \
    X(SkinBoneStretchTm, "Skin", "result", "anim Modifier, node Bone, ptr:float OutRow") \
    X(SkinSetBoneStretchTm, "Skin", "result", "anim Modifier, node Bone, cptr:float StretchRow, ptr:int32 OutSet") \
    X(SkinVertexSelectionRead, "Skin", "result", "anim Modifier, node SkinNode, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(SkinVertexSelectionWrite, "Skin", "result", "anim Modifier, node SkinNode, cptr:uint32 Bits, int32 BitCount") \
    X(SkinPointCount, "Skin", "result", "anim Modifier, node SkinNode, ptr:int32 OutCount") \
    X(SkinVertexBoneCount, "Skin", "result", "anim Modifier, node SkinNode, int32 Vertex, ptr:int32 OutCount") \
    X(SkinVertexBones, "Skin", "result", "anim Modifier, node SkinNode, int32 Vertex, ptr:int32 OutBones, size Capacity, ptr:int32 OutWritten") \
    X(SkinVertexWeights, "Skin", "result", "anim Modifier, node SkinNode, int32 Vertex, ptr:float OutWeights, size Capacity, ptr:int32 OutWritten") \
    X(SkinVertexSpline, "Skin", "result", "anim Modifier, node SkinNode, int32 Vertex, int32 VertexBone, ptr:MaxMcpSkinSpline OutSpline") \
    X(SkinVertexDQBlendWeight, "Skin", "result", "anim Modifier, node SkinNode, int32 Vertex, ptr:float OutWeight") \
    X(SkinSetVertexDQBlendWeight, "Skin", "result", "anim Modifier, node SkinNode, int32 Vertex, float Weight") \
    X(SkinAddBone, "Skin", "result", "anim Modifier, node Bone, int32 Update, ptr:int32 OutAdded") \
    X(SkinSetSkinTm, "Skin", "result", "anim Modifier, node SkinNode, cptr:float ObjectRow, cptr:float NodeRow, ptr:int32 OutSet") \
    X(SkinSetBoneTm, "Skin", "result", "anim Modifier, node Bone, cptr:float ObjectRow, cptr:float NodeRow, ptr:int32 OutSet") \
    X(SkinSetVertexWeights, "Skin", "result", "anim Modifier, node SkinNode, int32 Vertex, cptr:node Bones, cptr:float Weights, size Count, ptr:int32 OutSet") \
    X(MorphChannelCount, "Morph", "result", "anim Modifier, ptr:int32 OutCount") \
    X(MorphSetChannelCount, "Morph", "result", "anim Modifier, int32 Count") \
    X(MorphChannelActive, "Morph", "result", "anim Modifier, int32 Channel, ptr:int32 OutActive") \
    X(MorphChannelName, "Morph", "result", "anim Modifier, int32 Channel, int32 Localized, mutstr OutName, size Capacity") \
    X(MorphSetChannelName, "Morph", "result", "anim Modifier, int32 Channel, int32 Localized, cstr Name") \
    X(MorphChannelPointCount, "Morph", "result", "anim Modifier, int32 Channel, ptr:int32 OutCount") \
    X(MorphChannelConnection, "Morph", "result", "anim Modifier, int32 Channel, ptr:node OutTarget") \
    X(MorphSetChannelConnection, "Morph", "result", "anim Modifier, int32 Channel, node Target") \
    X(MorphChannelTargetCount, "Morph", "result", "anim Modifier, int32 Channel, ptr:int32 OutCount") \
    X(MorphChannelProgressiveCount, "Morph", "result", "anim Modifier, int32 Channel, ptr:int32 OutCount") \
    X(MorphChannelProgressive, "Morph", "result", "anim Modifier, int32 Channel, ptr:int32 OutProgressive") \
    X(MorphChannelTargetAt, "Morph", "result", "anim Modifier, int32 Channel, int32 Target, ptr:node OutTarget") \
    X(MorphChannelTargetPoint, "Morph", "result", "anim Modifier, int32 Channel, int32 Target, int32 Point, ptr:float OutPoint") \
    X(MorphChannelTargetPercent, "Morph", "result", "anim Modifier, int32 Channel, int32 Target, ptr:double OutPercent") \
    X(MorphSetChannelTargetPercent, "Morph", "result", "anim Modifier, int32 Channel, int32 Target, double Percent, ptr:int32 OutSet") \
    X(MorphChannelInitPercent, "Morph", "result", "anim Modifier, int32 Channel, ptr:double OutPercent") \
    X(MorphChannelPoint, "Morph", "result", "anim Modifier, int32 Channel, int32 Point, ptr:float OutPoint") \
    X(MorphSetChannelPoint, "Morph", "result", "anim Modifier, int32 Channel, int32 Point, cptr:float Value") \
    X(MorphChannelPointDelta, "Morph", "result", "anim Modifier, int32 Channel, int32 Point, ptr:float OutDelta") \
    X(MorphSetChannelPointDelta, "Morph", "result", "anim Modifier, int32 Channel, int32 Point, cptr:float Delta") \
    X(MorphChannelPointWeight, "Morph", "result", "anim Modifier, int32 Channel, int32 Point, ptr:double OutWeight") \
    X(MorphSetChannelPointWeight, "Morph", "result", "anim Modifier, int32 Channel, int32 Point, double Weight") \
    X(MorphChannelBaseDeltas, "Morph", "result", "anim Modifier, int32 Channel, ptr:float OutDeltas, size Capacity, ptr:int32 OutWritten, ptr:int32 OutGot") \
    X(MorphChannelProgressiveDeltas, "Morph", "result", "anim Modifier, int32 Channel, int32 Progressive, ptr:float OutDeltas, size Capacity, ptr:int32 OutWritten, ptr:int32 OutGot") \
    X(MorphChannelWeightController, "Morph", "result", "anim Modifier, int32 Channel, ptr:anim OutController") \
    X(MorphChannelReset, "Morph", "result", "anim Modifier, int32 Channel, int32 Active, int32 Modded, int32 PointCount") \
    X(MorphAddProgressiveTarget, "Morph", "result", "anim Modifier, int32 Channel, node Target, ptr:int32 OutAdded") \
    X(MorphDeleteAllChannels, "Morph", "result", "anim Modifier") \
    X(MorphRebuildCache, "Morph", "result", "anim Modifier, anim Object, ptr:int32 OutBuilt") \
    X(MorphDeleteCache, "Morph", "result", "anim Modifier") \
    X(NodeBoneAttrsRead, "Node", "result", "node Node, ptr:MaxMcpBoneAttrs OutAttrs") \
    X(NodeBoneAttrsWrite, "Node", "result", "node Node, int32 Time, cptr:MaxMcpBoneAttrs Attrs") \
    X(NodeBoneNodeOnOffAt, "Node", "result", "node Node, int32 Time, ptr:int32 OutOnOff") \
    X(NodeBoneDisplayRead, "Node", "result", "node Node, ptr:int32 OutShowing, ptr:int32 OutBoneOnly") \
    X(NodeStretchTm, "Node", "result", "node Node, int32 Time, ptr:float OutRow, ptr:int32 OutValidStart, ptr:int32 OutValidEnd") \
    X(SceneAtmosphericCount, "Scene", "result", "ptr:int32 OutCount") \
    X(SceneAtmospheric, "Scene", "result", "int32 Index, ptr:anim OutAtmospheric") \
    X(SceneAddAtmospheric, "Scene", "result", "anim Atmospheric") \
    X(SceneSetAtmospheric, "Scene", "result", "int32 Index, anim Atmospheric") \
    X(SceneDeleteAtmospheric, "Scene", "result", "int32 Index") \
    X(SceneEffectCount, "Scene", "result", "ptr:int32 OutCount") \
    X(SceneEffect, "Scene", "result", "int32 Index, ptr:anim OutEffect") \
    X(SceneAddEffect, "Scene", "result", "anim Effect") \
    X(SceneSetEffect, "Scene", "result", "int32 Index, anim Effect") \
    X(SceneDeleteEffect, "Scene", "result", "int32 Index") \
    X(SpecialFxGizmoCount, "Special", "result", "anim Fx, ptr:int32 OutCount") \
    X(SpecialFxGizmo, "Special", "result", "anim Fx, int32 Index, ptr:node OutGizmo") \
    X(SpecialFxGizmoAppend, "Special", "result", "anim Fx, node Gizmo") \
    X(SpecialFxGizmoDelete, "Special", "result", "anim Fx, int32 Index") \
    X(SpecialFxGizmoAccepts, "Special", "result", "anim Fx, node Gizmo, ptr:int32 OutAccepts") \
    X(SpecialFxName, "Special", "result", "anim Fx, int32 Localized, mutstr OutName, size Capacity") \
    X(SpecialFxStoredName, "Special", "result", "anim Fx, mutstr OutName, size Capacity") \
    X(SpecialFxSetName, "Special", "result", "anim Fx, cstr Name") \
    X(SpecialFxActive, "Special", "result", "anim Fx, int32 Time, ptr:int32 OutActive") \
    X(SpecialFxDisabled, "Special", "result", "anim Fx, ptr:int32 OutDisabled") \
    X(SpecialFxSetDisabled, "Special", "result", "anim Fx, int32 Disabled") \
    X(SceneUseEnvironmentMap, "Scene", "result", "ptr:int32 OutOnOff") \
    X(SceneSetUseEnvironmentMap, "Scene", "result", "int32 OnOff") \
    X(LayerCreate, "Layer", "anim", "cstr Name") \
    X(LayerCount, "Layer", "result", "ptr:int32 OutCount") \
    X(LayerByIndex, "Layer", "anim", "int32 Index") \
    X(LayerByName, "Layer", "anim", "cstr Name") \
    X(LayerCurrent, "Layer", "anim", "") \
    X(LayerRoot, "Layer", "anim", "") \
    X(LayerSetCurrent, "Layer", "result", "anim Layer") \
    X(LayerSetCurrentFromSelection, "Layer", "result", "") \
    X(LayerPropagateToLayer, "Layer", "result", "ptr:int32 OutPropagate") \
    X(LayerSetPropagateToLayer, "Layer", "result", "int32 Propagate") \
    X(LayerName, "Layer", "result", "anim Layer, mutstr OutName, size Capacity") \
    X(LayerSetName, "Layer", "result", "anim Layer, cstr Name") \
    X(LayerFlagsRead, "Layer", "result", "anim Layer, int32 IncludeParent, ptr:MaxMcpLayerFlags OutFlags") \
    X(LayerFlagsWrite, "Layer", "result", "anim Layer, int32 Propagate, cptr:MaxMcpLayerFlags Flags") \
    X(LayerWireColor, "Layer", "result", "anim Layer, ptr:float OutRgb") \
    X(LayerSetWireColor, "Layer", "result", "anim Layer, int32 Propagate, cptr:float Rgb") \
    X(LayerDisplayRead, "Layer", "result", "anim Layer, ptr:MaxMcpLayerDisplay OutDisplay") \
    X(LayerDisplayWrite, "Layer", "result", "anim Layer, int32 Propagate, cptr:MaxMcpLayerDisplay Display") \
    X(LayerRenderRead, "Layer", "result", "anim Layer, ptr:MaxMcpLayerRender OutRender") \
    X(LayerRenderWrite, "Layer", "result", "anim Layer, cptr:MaxMcpLayerRender Render") \
    X(LayerVisibility, "Layer", "result", "anim Layer, int32 Time, ptr:float OutVisibility") \
    X(LayerSetVisibility, "Layer", "result", "anim Layer, int32 Time, float Visibility") \
    X(LayerMotionBlurRead, "Layer", "result", "anim Layer, int32 Time, ptr:MaxMcpLayerMotionBlur OutBlur") \
    X(LayerMotionBlurWrite, "Layer", "result", "anim Layer, int32 Time, cptr:MaxMcpLayerMotionBlur Blur") \
    X(LayerGIExcluded, "Layer", "result", "anim Layer, ptr:int32 OutExcluded") \
    X(LayerSetGIExcluded, "Layer", "result", "anim Layer, int32 Excluded") \
    X(LayerNeverDegrade, "Layer", "result", "anim Layer, ptr:int32 OutNeverDegrade") \
    X(LayerSetNeverDegrade, "Layer", "result", "anim Layer, int32 NeverDegrade") \
    X(LayerOn, "Layer", "result", "anim Layer, ptr:int32 OutOn") \
    X(LayerSetOn, "Layer", "result", "anim Layer, int32 On") \
    X(LayerLock, "Layer", "result", "anim Layer, ptr:int32 OutLock") \
    X(LayerSetLock, "Layer", "result", "anim Layer, int32 Lock") \
    X(LayerParent, "Layer", "anim", "anim Layer, ptr:result OutResult") \
    X(LayerChildCount, "Layer", "result", "anim Layer, ptr:int32 OutCount") \
    X(LayerChild, "Layer", "anim", "anim Layer, int32 Index") \
    X(LayerSetParent, "Layer", "result", "anim Layer, anim Parent") \
    X(NodeLayer, "Node", "anim", "node Node, ptr:result OutResult") \
    X(LayerAddNode, "Layer", "result", "anim Layer, node Node") \
    X(LayerNodeCount, "Layer", "result", "anim Layer, ptr:int32 OutCount") \
    X(LayerNodes, "Layer", "result", "anim Layer, ptr:node OutNodes, size Capacity, ptr:int32 OutWritten") \
    X(NodeByLayerRead, "Node", "result", "node Node, ptr:MaxMcpNodeByLayer OutByLayer") \
    X(NodeByLayerWrite, "Node", "result", "node Node, cptr:MaxMcpNodeByLayer ByLayer") \
    X(LayerUsed, "Layer", "result", "anim Layer, ptr:int32 OutUsed") \
    X(LayerHasObjects, "Layer", "result", "anim Layer, ptr:int32 OutHasObjects") \
    X(LayerHierarchyHasNodes, "Layer", "result", "anim Layer, ptr:int32 OutHasNodes") \
    X(LayerHasSelectedNodesInHierarchy, "Layer", "result", "anim Layer, ptr:int32 OutHas") \
    X(LayerHasSceneXRefNodesInHierarchy, "Layer", "result", "anim Layer, ptr:int32 OutHas") \
    X(LayerMaxNodeHandle, "Layer", "result", "anim Layer, int32 Recurse, ptr:node OutHandle") \
    X(LayerSelectObjects, "Layer", "result", "anim Layer") \
    X(LayerSelectObjectsFlag, "Layer", "result", "anim Layer, int32 Select") \
    X(LayerCanDelete, "Layer", "result", "anim Layer, ptr:int32 OutCan") \
    X(LayerDelete, "Layer", "result", "anim Layer") \
    X(LayerDeleteHierarchy, "Layer", "result", "anim Layer, int32 ForceDelete, ptr:int32 OutDeleted") \
    X(NodeGetActualINode, "Node", "result", "node Node, ptr:node OutValue") \
    X(NodeGetName, "Node", "result", "node Node, mutstr OutName, size Capacity") \
    X(NodeGetParentNode, "Node", "result", "node Node, ptr:node OutValue") \
    X(NodeGetChildNode, "Node", "result", "node Node, int32 i, ptr:node OutValue") \
    X(NodeGetImageBlurMultController, "Node", "result", "node Node, ptr:anim OutValue") \
    X(NodeGetMotBlurOnOffController, "Node", "result", "node Node, ptr:anim OutValue") \
    X(NodeGetTarget, "Node", "result", "node Node, ptr:node OutValue") \
    X(NodeGetLookatNode, "Node", "result", "node Node, ptr:node OutValue") \
    X(NodeGetObjectRef, "Node", "result", "node Node, ptr:anim OutValue") \
    X(NodeGetObjOrWSMRef, "Node", "result", "node Node, ptr:anim OutValue") \
    X(NodeGetTMController, "Node", "result", "node Node, ptr:anim OutValue") \
    X(NodeGetVisController, "Node", "result", "node Node, ptr:anim OutValue") \
    X(NodeGetMtl, "Node", "result", "node Node, ptr:anim OutValue") \
    X(NodeGetXRefTree, "Node", "result", "node Node, int32 i, ptr:node OutValue") \
    X(NodeGetXRefParent, "Node", "result", "node Node, int32 i, ptr:node OutValue") \
    X(MeshGetMtlIndex, "Mesh", "result", "anim Object, ptr:uint32 OutValue") \
    X(MeshInit, "Mesh", "result", "anim Object") \
    X(MeshSetNumTVerts, "Mesh", "result", "anim Object, int32 ct, int32 keep, ptr:int32 OutValue") \
    X(MeshSetNumTVFaces, "Mesh", "result", "anim Object, int32 ct, int32 keep, int32 oldCt, ptr:int32 OutValue") \
    X(MeshSetNumVertCol, "Mesh", "result", "anim Object, int32 ct, int32 keep, ptr:int32 OutValue") \
    X(MeshSetNumVCFaces, "Mesh", "result", "anim Object, int32 ct, int32 keep, int32 oldCt, ptr:int32 OutValue") \
    X(MeshSetNumMaps, "Mesh", "result", "anim Object, int32 ct, int32 keep") \
    X(MeshGetNumMaps, "Mesh", "result", "anim Object, ptr:int32 OutValue") \
    X(MeshMapSupport, "Mesh", "result", "anim Object, int32 mp, ptr:int32 OutValue") \
    X(MeshSetMapSupport, "Mesh", "result", "anim Object, int32 mp, int32 support") \
    X(MeshSetNumMapVerts, "Mesh", "result", "anim Object, int32 mp, int32 ct, int32 keep") \
    X(MeshGetNumMapVerts, "Mesh", "result", "anim Object, int32 mp, ptr:int32 OutValue") \
    X(MeshSetNumMapFaces, "Mesh", "result", "anim Object, int32 mp, int32 ct, int32 keep, int32 oldCt") \
    X(MeshGetNumMapFaces, "Mesh", "result", "anim Object, int32 mp, ptr:int32 OutValue") \
    X(MeshMakeMapPlanar, "Mesh", "result", "anim Object, int32 mp") \
    X(MeshDeleteIsoMapVerts, "Mesh", "result", "anim Object") \
    X(MeshFreeMapVerts, "Mesh", "result", "anim Object, int32 mp") \
    X(MeshFreeMapFaces, "Mesh", "result", "anim Object, int32 mp") \
    X(MeshSetNumVData, "Mesh", "result", "anim Object, int32 ct, int32 keep") \
    X(MeshGetNumVData, "Mesh", "result", "anim Object, ptr:int32 OutValue") \
    X(MeshGetNumVDataSupported, "Mesh", "result", "anim Object, ptr:int32 OutValue") \
    X(MeshVDataSupport, "Mesh", "result", "anim Object, int32 vd, ptr:int32 OutValue") \
    X(MeshSetSmoothFlags, "Mesh", "result", "anim Object, int32 f") \
    X(MeshGetSmoothFlags, "Mesh", "result", "anim Object, ptr:int32 OutValue") \
    X(MeshBuildNormals, "Mesh", "result", "anim Object") \
    X(MeshBuildRenderNormals, "Mesh", "result", "anim Object") \
    X(MeshCheckNormals, "Mesh", "result", "anim Object, int32 illum") \
    X(MeshGetFaceMtlIndex, "Mesh", "result", "anim Object, int32 i, ptr:uint32 OutValue") \
    X(MeshInvalidateGeomCache, "Mesh", "result", "anim Object") \
    X(MeshInvalidateTopologyCache, "Mesh", "result", "anim Object") \
    X(MeshFreeAll, "Mesh", "result", "anim Object") \
    X(MeshEnableEdgeList, "Mesh", "result", "anim Object, int32 e") \
    X(MeshBuildVisEdgeList, "Mesh", "result", "anim Object") \
    X(MeshInvalidateEdgeList, "Mesh", "result", "anim Object") \
    X(MeshBuildBoundingBox, "Mesh", "result", "anim Object") \
    X(MeshBuildStrips, "Mesh", "result", "anim Object, ptr:int32 OutValue") \
    X(MeshInvalidateStrips, "Mesh", "result", "anim Object") \
    X(MeshBuildStripsAndEdges, "Mesh", "result", "anim Object") \
    X(MeshFlipNormal, "Mesh", "result", "anim Object, int32 i") \
    X(MeshUnifyNormals, "Mesh", "result", "anim Object, int32 selOnly") \
    X(MeshAutoSmooth, "Mesh", "result", "anim Object, float angle, int32 useSel, int32 preventIndirectSmoothing") \
    X(MeshDeleteFlaggedFaces, "Mesh", "result", "anim Object, ptr:int32 OutValue") \
    X(MeshDeleteSelected, "Mesh", "result", "anim Object") \
    X(MeshDoesFaceExist, "Mesh", "result", "anim Object, uint32 v0, uint32 v1, uint32 v2, ptr:int32 OutValue") \
    X(MeshRemoveDegenerateFaces, "Mesh", "result", "anim Object, ptr:int32 OutValue") \
    X(MeshRemoveIllegalFaces, "Mesh", "result", "anim Object, ptr:int32 OutValue") \
    X(MeshDivideEdge, "Mesh", "result", "anim Object, uint32 edge, float prop, int32 visDiag1, int32 fixNeighbors, int32 visDiag2") \
    X(MeshDivideFace, "Mesh", "result", "anim Object, uint32 face, uint32 e1, uint32 e2, float prop1, float prop2, int32 fixNeighbors, int32 split") \
    X(MeshExtrudeFaces, "Mesh", "result", "anim Object, int32 doFace") \
    X(MeshIndentSelFaces, "Mesh", "result", "anim Object, float amount") \
    X(MeshDeleteIsoVerts, "Mesh", "result", "anim Object") \
    X(MeshIsFaceCacheInvalid, "Mesh", "result", "anim Object, int32 faceIndex, ptr:int32 OutValue") \
    X(MeshInvalidateVertexCache, "Mesh", "result", "anim Object, int32 vertex") \
    X(MeshSetStaticMesh, "Mesh", "result", "anim Object, int32 staticMesh") \
    X(MeshReduceDisplayCaches, "Mesh", "result", "anim Object") \
    X(MeshIsAccelDataDirty, "Mesh", "result", "anim Object, ptr:int32 OutValue") \
    X(MeshDirtyAccelData, "Mesh", "result", "anim Object") \
    X(SceneForceCompleteRedraw, "Scene", "result", "int32 doDisabled") \
    X(SceneDisplayActiveCameraViewWithMultiPassEffect, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetActiveViewportTransparencyDisplay, "Scene", "result", "int32 transType, ptr:int32 OutValue") \
    X(SceneDisableSceneRedraw, "Scene", "result", "") \
    X(SceneEnableSceneRedraw, "Scene", "result", "") \
    X(SceneIsSceneRedrawDisabled, "Scene", "result", "ptr:int32 OutValue") \
    X(ScenePopCommandMode, "Scene", "result", "") \
    X(SceneSetStdCommandMode, "Scene", "result", "int32 cid") \
    X(ScenePushStdCommandMode, "Scene", "result", "int32 cid") \
    X(ScenePopPrompt, "Scene", "result", "") \
    X(SceneRemoveTempPrompt, "Scene", "result", "") \
    X(SceneDisableStatusXYZ, "Scene", "result", "") \
    X(SceneEnableStatusXYZ, "Scene", "result", "") \
    X(SceneProgressEnd, "Scene", "result", "") \
    X(SceneGetCancel, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetCancel, "Scene", "result", "int32 sw") \
    X(SceneGetGridSpacing, "Scene", "result", "ptr:float OutValue") \
    X(SceneGetGridMajorLines, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetExtendedDisplayMode, "Scene", "result", "int32 vflags") \
    X(SceneGetExtendedDisplayMode, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetFlyOffTime, "Scene", "result", "int32 msecs") \
    X(SceneGetFlyOffTime, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetCrossHairCur, "Scene", "result", "int32 onOff") \
    X(SceneGetCrossHairCur, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneRealizeParamPanel, "Scene", "result", "") \
    X(SceneSnapPercent, "Scene", "result", "float percentIn, ptr:float OutValue") \
    X(SceneGetSnapState, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneGetSnapMode, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetSnapMode, "Scene", "result", "int32 mode, ptr:int32 OutValue") \
    X(SceneClearPickMode, "Scene", "result", "") \
    X(SceneClearSubObjectNamedSelSets, "Scene", "result", "") \
    X(SceneClearCurNamedSelSet, "Scene", "result", "") \
    X(SceneGetSubObjectLevel, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetSubObjectLevel, "Scene", "result", "int32 level, int32 force") \
    X(SceneGetNumSubObjectLevels, "Scene", "result", "ptr:int32 OutValue") \
    X(ScenePipeSelLevelChanged, "Scene", "result", "") \
    X(SceneSelectionFrozen, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneFreezeSelection, "Scene", "result", "") \
    X(SceneThawSelection, "Scene", "result", "") \
    X(SceneGetSelNode, "Scene", "result", "int32 i, ptr:node OutValue") \
    X(SceneGetSelNodeCount, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneEnableShowEndResult, "Scene", "result", "int32 enabled") \
    X(SceneGetShowEndResult, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetShowEndResult, "Scene", "result", "int32 show") \
    X(SceneGetPreserveStackPosition, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetPreserveStackPosition, "Scene", "result", "int32 preserve") \
    X(SceneGetCrossing, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetToolButtonState, "Scene", "result", "int32 button, int32 state") \
    X(SceneEnableToolButton, "Scene", "result", "int32 button, int32 enable") \
    X(SceneEnableUndo, "Scene", "result", "int32 enable") \
    X(SceneGetCommandPanelTaskMode, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetCommandPanelTaskMode, "Scene", "result", "int32 mode") \
    X(SceneEnableAnimateButton, "Scene", "result", "int32 enable") \
    X(SceneIsAnimateEnabled, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetAnimateButtonState, "Scene", "result", "int32 onOff") \
    X(SceneInProgressiveMode, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneBeginProgressiveMode, "Scene", "result", "") \
    X(SceneEndProgressiveMode, "Scene", "result", "") \
    X(SceneGetAxisConstraints, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetAxisConstraints, "Scene", "result", "int32 c") \
    X(SceneEnableAxisConstraints, "Scene", "result", "int32 c, int32 enabled") \
    X(ScenePushAxisConstraints, "Scene", "result", "int32 c") \
    X(ScenePopAxisConstraints, "Scene", "result", "") \
    X(SceneGetCoordCenter, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetCoordCenter, "Scene", "result", "int32 c") \
    X(SceneEnableCoordCenter, "Scene", "result", "int32 enabled") \
    X(SceneGetRefCoordSys, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRefCoordSys, "Scene", "result", "int32 c") \
    X(SceneEnableRefCoordSys, "Scene", "result", "int32 enabled") \
    X(SceneGetSelectFilter, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetSelectFilter, "Scene", "result", "int32 c") \
    X(SceneGetNumberSelectFilters, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneGetSelectFilterName, "Scene", "result", "int32 index, mutstr OutName, size Capacity") \
    X(SceneGetDisplayFilter, "Scene", "result", "int32 index, ptr:int32 OutValue") \
    X(SceneSetDisplayFilter, "Scene", "result", "int32 index, int32 on") \
    X(SceneGetNumberDisplayFilters, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneGetDisplayFilterName, "Scene", "result", "int32 index, mutstr OutName, size Capacity") \
    X(SceneGetNumAxis, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneLockAxisTripods, "Scene", "result", "int32 onOff") \
    X(SceneAxisTripodLocked, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneGetTime, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneIsCPEdgeOnInView, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneGetRootNode, "Scene", "result", "ptr:node OutValue") \
    X(SceneClearNodeSelection, "Scene", "result", "int32 redraw") \
    X(SceneGetLightConeConstraint, "Scene", "result", "ptr:float OutValue") \
    X(SceneGetActiveGrid, "Scene", "result", "ptr:node OutValue") \
    X(SceneStopCreating, "Scene", "result", "") \
    X(SceneGetDir, "Scene", "result", "int32 which, mutstr OutName, size Capacity") \
    X(SceneGetPlugInEntryCount, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneGetPlugInDesc, "Scene", "result", "int32 i, mutstr OutName, size Capacity") \
    X(SceneGetPlugInDir, "Scene", "result", "int32 i, mutstr OutName, size Capacity") \
    X(SceneGetMtlSlot, "Scene", "result", "int32 slot, ptr:anim OutValue") \
    X(SceneGetMatLibFileName, "Scene", "result", "mutstr OutName, size Capacity") \
    X(SceneFileOpen, "Scene", "result", "") \
    X(SceneFileSave, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneFileSaveAs, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneFileSaveSelected, "Scene", "result", "") \
    X(SceneFileReset, "Scene", "result", "int32 noPrompt") \
    X(SceneFileMerge, "Scene", "result", "") \
    X(SceneFileHold, "Scene", "result", "") \
    X(SceneFileFetch, "Scene", "result", "") \
    X(SceneLoadDefaultMatLib, "Scene", "result", "") \
    X(SceneFileImport, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneFileExport, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetBkgImageAspect, "Scene", "result", "int32 t") \
    X(SceneGetBkgImageAspect, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetBkgImageAnimate, "Scene", "result", "int32 onOff") \
    X(SceneSetBkgFrameRange, "Scene", "result", "int32 start, int32 end, int32 step") \
    X(SceneGetBkgFrameRangeVal, "Scene", "result", "int32 which, ptr:int32 OutValue") \
    X(SceneSetBkgORType, "Scene", "result", "int32 which, int32 type") \
    X(SceneGetBkgORType, "Scene", "result", "int32 which, ptr:int32 OutValue") \
    X(SceneSetBkgStartTime, "Scene", "result", "int32 t") \
    X(SceneGetBkgStartTime, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetBkgSyncFrame, "Scene", "result", "int32 f") \
    X(SceneGetBkgSyncFrame, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneGetBkgFrameNum, "Scene", "result", "int32 t, ptr:int32 OutValue") \
    X(SceneGetRealTimePlayback, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRealTimePlayback, "Scene", "result", "int32 realTime") \
    X(SceneGetPlayActiveOnly, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetPlayActiveOnly, "Scene", "result", "int32 playActive") \
    X(SceneStartAnimPlayback, "Scene", "result", "int32 selOnly") \
    X(SceneEndAnimPlayback, "Scene", "result", "") \
    X(SceneIsAnimPlaying, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneGetPlaybackSpeed, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetPlaybackSpeed, "Scene", "result", "int32 s") \
    X(SceneGetPlaybackLoop, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetPlaybackLoop, "Scene", "result", "int32 loop") \
    X(SceneIncrementValidityToken, "Scene", "result", "") \
    X(SceneCloseCurRenderer, "Scene", "result", "") \
    X(SceneSetUseDraftRenderer, "Scene", "result", "int32 b") \
    X(SceneGetUseDraftRenderer, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneChangeRenderSetting, "Scene", "result", "int32 renderSettingID") \
    X(SceneGetCurrentRenderSetting, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneGetMEditRendererLocked, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetMEditRendererLocked, "Scene", "result", "int32 locked") \
    X(SceneGetMEditRendererLocked_DefaultValue, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetMEditRendererLocked_DefaultValue, "Scene", "result", "int32 locked") \
    X(SceneCheckForRenderAbort, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneAbortRender, "Scene", "result", "") \
    X(SceneGetRendTimeType, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendTimeType, "Scene", "result", "int32 type") \
    X(SceneGetRendStart, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendStart, "Scene", "result", "int32 start") \
    X(SceneGetRendEnd, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendEnd, "Scene", "result", "int32 end") \
    X(SceneGetRendNThFrame, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendNThFrame, "Scene", "result", "int32 n") \
    X(SceneGetRendShowVFB, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendShowVFB, "Scene", "result", "int32 onOff") \
    X(SceneGetRendSaveFile, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendSaveFile, "Scene", "result", "int32 onOff") \
    X(SceneGetRendUseDevice, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendUseDevice, "Scene", "result", "int32 onOff") \
    X(SceneGetRendUseNet, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendUseNet, "Scene", "result", "int32 onOff") \
    X(SceneGetRendWidth, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendWidth, "Scene", "result", "int32 w") \
    X(SceneGetRendHeight, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendHeight, "Scene", "result", "int32 h") \
    X(SceneGetRendPixelAspect, "Scene", "result", "ptr:float OutValue") \
    X(SceneSetRendPixelAspect, "Scene", "result", "float a") \
    X(SceneGetRendImageAspect, "Scene", "result", "ptr:float OutValue") \
    X(SceneGetRendApertureWidth, "Scene", "result", "ptr:float OutValue") \
    X(SceneSetRendApertureWidth, "Scene", "result", "float aw") \
    X(SceneGetRendFieldRender, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendFieldRender, "Scene", "result", "int32 onOff") \
    X(SceneGetRendColorCheck, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendColorCheck, "Scene", "result", "int32 onOff") \
    X(SceneGetRendSuperBlack, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendSuperBlack, "Scene", "result", "int32 onOff") \
    X(SceneGetRendHidden, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendHidden, "Scene", "result", "int32 onOff") \
    X(SceneGetRendForce2Side, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendForce2Side, "Scene", "result", "int32 onOff") \
    X(SceneGetRendAtmosphere, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendAtmosphere, "Scene", "result", "int32 onOff") \
    X(SceneGetRendEffects, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendEffects, "Scene", "result", "int32 onOff") \
    X(SceneGetRendDisplacement, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendDisplacement, "Scene", "result", "int32 onOff") \
    X(SceneGetRendDitherTrue, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendDitherTrue, "Scene", "result", "int32 onOff") \
    X(SceneGetRendDither256, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendDither256, "Scene", "result", "int32 onOff") \
    X(SceneGetRendMultiThread, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendMultiThread, "Scene", "result", "int32 onOff") \
    X(SceneGetRendNThSerial, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendNThSerial, "Scene", "result", "int32 onOff") \
    X(SceneGetRendVidCorrectMethod, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendVidCorrectMethod, "Scene", "result", "int32 m") \
    X(SceneGetRendFieldOrder, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendFieldOrder, "Scene", "result", "int32 fo") \
    X(SceneGetRendNTSC_PAL, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendNTSC_PAL, "Scene", "result", "int32 np") \
    X(SceneGetRendSuperBlackThresh, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendSuperBlackThresh, "Scene", "result", "int32 sb") \
    X(SceneGetRendFileNumberBase, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendFileNumberBase, "Scene", "result", "int32 n") \
    X(SceneGetSkipRenderedFrames, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetSkipRenderedFrames, "Scene", "result", "int32 onOff") \
    X(SceneGetRendSimplifyAreaLights, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetRendSimplifyAreaLights, "Scene", "result", "int32 onOff") \
    X(SceneGetHideByCategoryFlags, "Scene", "result", "ptr:uint32 OutValue") \
    X(SceneSetHideByCategoryFlags, "Scene", "result", "uint32 f") \
    X(SceneGetViewportLayout, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetViewportLayout, "Scene", "result", "int32 layout") \
    X(SceneIsViewportMaxed, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetViewportMax, "Scene", "result", "int32 max") \
    X(SceneViewportZoomExtents, "Scene", "result", "int32 doAll, int32 skipPersp") \
    X(SceneGetINodeByHandle, "Scene", "result", "uint32 handle, ptr:node OutValue") \
    X(SceneGetINodeFromRenderID, "Scene", "result", "uint32 id, ptr:node OutValue") \
    X(SceneExecuteMAXCommand, "Scene", "result", "int32 id") \
    X(SceneGetEnvironmentMap, "Scene", "result", "ptr:anim OutValue") \
    X(SceneGetUseEnvironmentMap, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneGetAmbientController, "Scene", "result", "ptr:anim OutValue") \
    X(SceneGetLightTintController, "Scene", "result", "ptr:anim OutValue") \
    X(SceneSetLightLevel, "Scene", "result", "int32 t, float lev") \
    X(SceneGetLightLevelController, "Scene", "result", "ptr:anim OutValue") \
    X(SceneNumAtmospheric, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneDeleteAtmosphere, "Scene", "result", "int32 i") \
    X(SceneGetBackGroundController, "Scene", "result", "ptr:anim OutValue") \
    X(SceneNumEffects, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneInvalidateOsnapdraw, "Scene", "result", "") \
    X(SceneIsNetworkRenderServer, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneGetScenePointer, "Scene", "result", "ptr:anim OutValue") \
    X(SceneFreeSceneBitmaps, "Scene", "result", "") \
    X(SceneGetKeyStepsSelOnly, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetKeyStepsSelOnly, "Scene", "result", "int32 onOff") \
    X(SceneGetKeyStepsUseTrans, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetKeyStepsUseTrans, "Scene", "result", "int32 onOff") \
    X(SceneGetKeyStepsPos, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetKeyStepsPos, "Scene", "result", "int32 onOff") \
    X(SceneGetKeyStepsRot, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetKeyStepsRot, "Scene", "result", "int32 onOff") \
    X(SceneGetKeyStepsScale, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetKeyStepsScale, "Scene", "result", "int32 onOff") \
    X(SceneGetKeyStepsUseTrackBar, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetKeyStepsUseTrackBar, "Scene", "result", "int32 onOff") \
    X(SceneGetUseTransformGizmo, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetUseTransformGizmo, "Scene", "result", "int32 onOff") \
    X(SceneSetTransformGizmoRestoreAxis, "Scene", "result", "int32 bOnOff") \
    X(SceneGetTransformGizmoRestoreAxis, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneGetConstantAxisRestriction, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetConstantAxisRestriction, "Scene", "result", "int32 onOff") \
    X(SceneDeactivateTransformGizmo, "Scene", "result", "") \
    X(SceneConfigureBitmapPaths, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneGetCommandStackSize, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneAddSFXRollupPage, "Scene", "result", "uint32 vflags") \
    X(SceneDeleteSFXRollupPage, "Scene", "result", "") \
    X(SceneRefreshSFXRollupPage, "Scene", "result", "") \
    X(SceneGetNumProperties, "Scene", "result", "int32 PropertySet, ptr:int32 OutValue") \
    X(SceneGetImportZoomExtents, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetImportZoomExtents, "Scene", "result", "int32 onOff") \
    X(SceneSetIncludeXRefsInHierarchy, "Scene", "result", "int32 onOff") \
    X(SceneGetIncludeXRefsInHierarchy, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneIsXRefAutoUpdateSuspended, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetXRefAutoUpdateSuspended, "Scene", "result", "int32 onOff") \
    X(SceneUpdateMtlEditorBrackets, "Scene", "result", "") \
    X(SceneIsTrialLicense, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneIsNetworkLicense, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneCheckForSave, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneFlushUndoBuffer, "Scene", "result", "") \
    X(SceneDeferredPluginLoadingEnabled, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneEnableDeferredPluginLoading, "Scene", "result", "int32 onOff") \
    X(SceneGetImportCtxNode, "Scene", "result", "ptr:node OutValue") \
    X(SceneSetQuietMode, "Scene", "result", "int32 onOff, ptr:int32 OutValue") \
    X(SceneGetQuietMode, "Scene", "result", "int32 checkServerMode, ptr:int32 OutValue") \
    X(SceneSetAutoGridEnable, "Scene", "result", "int32 sw") \
    X(SceneGetAutoGridEnable, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneGetAutoGridState, "Scene", "result", "ptr:int32 OutValue") \
    X(SceneSetAutoGridState, "Scene", "result", "int32 sw") \
    X(PolyVShrink, "Poly", "result", "anim Object, int32 num") \
    X(PolyFreeVEdge, "Poly", "result", "anim Object") \
    X(PolyVEdgeAlloc, "Poly", "result", "anim Object") \
    X(PolyFreeVFace, "Poly", "result", "anim Object") \
    X(PolyVFaceAlloc, "Poly", "result", "anim Object") \
    X(PolyEAlloc, "Poly", "result", "anim Object, int32 num, int32 keep") \
    X(PolyEShrink, "Poly", "result", "anim Object, int32 num") \
    X(PolyFShrink, "Poly", "result", "anim Object, int32 num") \
    X(PolyMNum, "Poly", "result", "anim Object, ptr:int32 OutValue") \
    X(PolyTriNum, "Poly", "result", "anim Object, ptr:int32 OutValue") \
    X(PolyIsEdgeMapSeam, "Poly", "result", "anim Object, int32 mapChannel, int32 edge, ptr:int32 OutValue") \
    X(PolySetNumVData, "Poly", "result", "anim Object, int32 ct, int32 keep") \
    X(PolyVDNum, "Poly", "result", "anim Object, ptr:int32 OutValue") \
    X(PolyVDNumSupported, "Poly", "result", "anim Object, ptr:int32 OutValue") \
    X(PolyVDataSupport, "Poly", "result", "anim Object, int32 vdChannel, ptr:int32 OutValue") \
    X(PolySetNumEData, "Poly", "result", "anim Object, int32 ct, int32 keep") \
    X(PolyEDNum, "Poly", "result", "anim Object, ptr:int32 OutValue") \
    X(PolyEDNumSupported, "Poly", "result", "anim Object, ptr:int32 OutValue") \
    X(PolyEDataSupport, "Poly", "result", "anim Object, int32 edChannel, ptr:int32 OutValue") \
    X(PolyVClear, "Poly", "result", "anim Object, int32 vv") \
    X(PolyVInit, "Poly", "result", "anim Object, int32 vv") \
    X(PolyVFaceIndex, "Poly", "result", "anim Object, int32 vv, int32 ff, int32 ee, ptr:int32 OutValue") \
    X(PolyVEdgeIndex, "Poly", "result", "anim Object, int32 vv, int32 ee, ptr:int32 OutValue") \
    X(PolyVDeleteEdge, "Poly", "result", "anim Object, int32 vv, int32 ee") \
    X(PolyVDeleteFace, "Poly", "result", "anim Object, int32 vv, int32 ff") \
    X(PolyVReplaceEdge, "Poly", "result", "anim Object, int32 vv, int32 oe, int32 ne") \
    X(PolyVReplaceFace, "Poly", "result", "anim Object, int32 vv, int32 of, int32 nf") \
    X(PolyCopyVert, "Poly", "result", "anim Object, int32 nv, int32 ov") \
    X(PolyMNVDebugPrint, "Poly", "result", "anim Object, int32 vv") \
    X(PolyAppendNewFaces, "Poly", "result", "anim Object, int32 nfnum, ptr:int32 OutValue") \
    X(PolyAppendNewVerts, "Poly", "result", "anim Object, int32 nvnum, ptr:int32 OutValue") \
    X(PolyEliminateCollinearVerts, "Poly", "result", "anim Object") \
    X(PolyEliminateCoincidentVerts, "Poly", "result", "anim Object, float thresh") \
    X(PolyPaintFaceFlag, "Poly", "result", "anim Object, int32 ff, uint32 fl, uint32 fenceflags") \
    X(PolyFillInFaceEdges, "Poly", "result", "anim Object") \
    X(PolyFillInVertEdgesFaces, "Poly", "result", "anim Object") \
    X(PolyOrderVerts, "Poly", "result", "anim Object") \
    X(PolyOrderVert, "Poly", "result", "anim Object, int32 vid") \
    X(PolyTriangulate, "Poly", "result", "anim Object") \
    X(PolyTriangulateFace, "Poly", "result", "anim Object, int32 ff") \
    X(PolyTargetVertsBySelection, "Poly", "result", "anim Object, int32 iSelLevel, ptr:int32 OutValue") \
    X(PolyTargetEdgesBySelection, "Poly", "result", "anim Object, int32 iSelLevel, ptr:int32 OutValue") \
    X(PolyTargetFacesBySelection, "Poly", "result", "anim Object, int32 iSelLevel, ptr:int32 OutValue") \
    X(PolyDetargetVertsBySharpness, "Poly", "result", "anim Object, float sharpval") \
    X(PolyRetriangulateFace, "Poly", "result", "anim Object, int32 ff, int32 triangulationType") \
    X(PolyMakePolyMesh, "Poly", "result", "anim Object, int32 maxdeg, int32 elimCollin") \
    X(PolyMakePolyMeshRanged, "Poly", "result", "anim Object, int32 startFace, int32 endFace") \
    X(PolyMakeConvexPolyMesh, "Poly", "result", "anim Object, int32 maxdeg") \
    X(PolyFindEdgeFromVertToVert, "Poly", "result", "anim Object, int32 vrt1, int32 vrt2, ptr:int32 OutValue") \
    X(PolyCheckNormals, "Poly", "result", "anim Object, int32 illum") \
    X(PolyBuildNormals, "Poly", "result", "anim Object") \
    X(PolyBuildRenderNormals, "Poly", "result", "anim Object") \
    X(PolyFlipElementNormals, "Poly", "result", "anim Object, uint32 flag, ptr:int32 OutValue") \
    X(PolyFlipFaceNormals, "Poly", "result", "anim Object, uint32 faceFlag, ptr:int32 OutValue") \
    X(PolyResmooth, "Poly", "result", "anim Object, int32 smooth, int32 targonly, uint32 targmask") \
    X(PolyCommonSmoothing, "Poly", "result", "anim Object, int32 targonly, ptr:uint32 OutValue") \
    X(PolyGetOldSmGroup, "Poly", "result", "anim Object, int32 targonly, ptr:uint32 OutValue") \
    X(PolyGetAllSmGroups, "Poly", "result", "anim Object, int32 targonly, ptr:uint32 OutValue") \
    X(PolyFindReplacementSmGroup, "Poly", "result", "anim Object, int32 ff, uint32 os, ptr:uint32 OutValue") \
    X(PolyPaintNewSmGroup, "Poly", "result", "anim Object, int32 ff, uint32 os, uint32 ns") \
    X(PolySeparateSmGroups, "Poly", "result", "anim Object, int32 v1, int32 v2, ptr:int32 OutValue") \
    X(PolyFindAvailableSmoothingGroups, "Poly", "result", "anim Object, int32 faceIndex, uint32 excludeSmoothing, ptr:uint32 OutValue") \
    X(PolyFenceMaterials, "Poly", "result", "anim Object") \
    X(PolyFenceSmGroups, "Poly", "result", "anim Object") \
    X(PolyFenceFaceSel, "Poly", "result", "anim Object") \
    X(PolyFenceOneSidedEdges, "Poly", "result", "anim Object") \
    X(PolyFenceNonPlanarEdges, "Poly", "result", "anim Object, float thresh, int32 makevis") \
    X(PolySetMapSeamFlags, "Poly", "result", "anim Object") \
    X(PolyFindOpenRegions, "Poly", "result", "anim Object") \
    X(PolyEliminateDoubledMappingVerts, "Poly", "result", "anim Object") \
    X(PolyEliminateIsoMapVerts, "Poly", "result", "anim Object") \
    X(PolyMNDebugPrintVertexNeighborhood, "Poly", "result", "anim Object, int32 vv, int32 triprint") \
    X(PolySplitEdge, "Poly", "result", "anim Object, int32 ee, float prop, ptr:int32 OutValue") \
    X(PolySplitFlaggedVertices, "Poly", "result", "anim Object, uint32 flag, ptr:int32 OutValue") \
    X(PolySplitFlaggedEdges, "Poly", "result", "anim Object, uint32 flag, ptr:int32 OutValue") \
    X(PolySplitFacesUsingBothSidesOfEdge, "Poly", "result", "anim Object, uint32 edgeFlag, int32 triangulationType, ptr:int32 OutValue") \
    X(PolyMakeConvex, "Poly", "result", "anim Object") \
    X(PolyMakeFaceConvex, "Poly", "result", "anim Object, int32 ff") \
    X(PolyRestrictPolySize, "Poly", "result", "anim Object, int32 maxdeg") \
    X(PolyMakePlanar, "Poly", "result", "anim Object, float planarThresh, int32 track") \
    X(PolyMakeFacePlanar, "Poly", "result", "anim Object, int32 ff, float planarThresh, int32 track") \
    X(PolyWeldBorderEdges, "Poly", "result", "anim Object, int32 e1, int32 e2, ptr:int32 OutValue") \
    X(PolyWeldBorderVerts, "Poly", "result", "anim Object, float thresh, uint32 flag, ptr:int32 OutValue") \
    X(PolyWeldOpposingEdges, "Poly", "result", "anim Object, uint32 edgeFlag, ptr:int32 OutValue") \
    X(PolyPrepForBoolean, "Poly", "result", "anim Object") \
    X(PolyConnectEdges, "Poly", "result", "anim Object, uint32 edgeFlag, int32 segments, int32 triangulationType, ptr:int32 OutValue") \
    X(PolyConnectVertices, "Poly", "result", "anim Object, uint32 vertexFlag, int32 triangulationType, ptr:int32 OutValue") \
    X(PolyCloneVerts, "Poly", "result", "anim Object, uint32 cloneFlag, int32 clear_orig") \
    X(PolyDetachFaces, "Poly", "result", "anim Object, uint32 flag, ptr:int32 OutValue") \
    X(PolyQuadChamfer, "Poly", "result", "anim Object, float amount, int32 segments, float tension, int32 resultType, uint32 flag, ptr:int32 OutValue") \
    X(PolyUpdateDisplayVertexColors, "Poly", "result", "anim Object") \
    X(PolySetDisplayVertexColors, "Poly", "result", "anim Object, int32 chan") \
    X(PolyPrepForPipeline, "Poly", "result", "anim Object") \
    X(PolyAllocRVerts, "Poly", "result", "anim Object") \
    X(PolyFreeRVerts, "Poly", "result", "anim Object") \
    X(PolyReduceDisplayCaches, "Poly", "result", "anim Object") \
    X(PolyInvalidateHardwareMesh, "Poly", "result", "anim Object, uint32 keepFlags") \
    X(PolySetStaticMesh, "Poly", "result", "anim Object, int32 staticMesh") \
    X(PolyClearSpecifiedNormals, "Poly", "result", "anim Object") \
    X(PolySpecifyNormals, "Poly", "result", "anim Object") \
    X(PolyRelax, "Poly", "result", "anim Object, float relaxval, int32 targonly") \
    X(PolySmoothByCreases, "Poly", "result", "anim Object, uint32 creaseFlag") \
    X(PolyNumDeadEdges, "Poly", "result", "anim Object, ptr:int32 OutValue") \
    X(PolyNumDeadVerts, "Poly", "result", "anim Object, ptr:int32 OutValue") \
    X(PolyNumDeadFaces, "Poly", "result", "anim Object, ptr:int32 OutValue") \
    X(PolyIsAccelDataDirty, "Poly", "result", "anim Object, ptr:int32 OutValue") \
    X(PolyDirtyAccelData, "Poly", "result", "anim Object") \
    X(PolyGetFlag, "Poly", "result", "anim Object, uint32 fl, ptr:int32 OutValue") \
    X(PolyClearAllFlags, "Poly", "result", "anim Object") \
    X(PolyCopyFlags, "Poly", "result", "anim Object, uint32 fl") \
    X(PolyFlagMatch, "Poly", "result", "anim Object, uint32 fmask, uint32 fl, ptr:int32 OutValue") \
    X(PolyExportFlags, "Poly", "result", "anim Object, ptr:uint32 OutValue") \
    X(PolyImportFlags, "Poly", "result", "anim Object, uint32 fl") \
    X(ControllerGetTarget, "Controller", "result", "anim Controller, ptr:node OutValue") \
    X(ControllerGetPositionController, "Controller", "result", "anim Controller, ptr:anim OutValue") \
    X(ControllerGetRotationController, "Controller", "result", "anim Controller, ptr:anim OutValue") \
    X(ControllerGetScaleController, "Controller", "result", "anim Controller, ptr:anim OutValue") \
    X(ControllerGetRollController, "Controller", "result", "anim Controller, ptr:anim OutValue") \
    X(ControllerGetInheritanceFlags, "Controller", "result", "anim Controller, ptr:uint32 OutValue") \
    X(ControllerIsColorController, "Controller", "result", "anim Controller, ptr:int32 OutValue") \
    X(ControllerIsLeaf, "Controller", "result", "anim Controller, ptr:int32 OutValue") \
    X(ControllerIsKeyable, "Controller", "result", "anim Controller, ptr:int32 OutValue") \
    X(ControllerIsReplaceable, "Controller", "result", "anim Controller, ptr:int32 OutValue") \
    X(ControllerMirrorIKConstraints, "Controller", "result", "anim Controller, int32 axis, int32 which, int32 pasteMirror") \
    X(ControllerTerminateIK, "Controller", "result", "anim Controller, ptr:int32 OutValue") \
    X(ControllerNodeIKParamsChanged, "Controller", "result", "anim Controller") \
    X(ControllerTMInvalidated, "Controller", "result", "anim Controller") \
    X(ControllerCanCopyIKParams, "Controller", "result", "anim Controller, int32 which, ptr:int32 OutValue") \
    X(ControllerCanApplyEaseMultCurves, "Controller", "result", "anim Controller, ptr:int32 OutValue") \
    X(ControllerPostCloneNode, "Controller", "result", "anim Controller") \
    X(ControllerPreventNodeDeletion, "Controller", "result", "anim Controller, ptr:int32 OutValue") \
    X(ControllerVisibleInViewports, "Controller", "result", "anim Controller, ptr:int32 OutValue") \
    X(ControllerCanInstanceController, "Controller", "result", "anim Controller, ptr:int32 OutValue") \
    X(ControllerClearSelection, "Controller", "result", "anim Controller, int32 selLevel") \
    X(ControllerSelectAll, "Controller", "result", "anim Controller, int32 selLevel") \
    X(ControllerInvertSelection, "Controller", "result", "anim Controller, int32 selLevel") \
    X(MeshSetMtlIndex, "Mesh", "result", "anim Object, uint32 mtlIndex") \
    X(MeshGetNormal, "Mesh", "result", "anim Object, int32 i, ptr:MaxMcpPoint3 OutValue") \
    X(MeshGetFaceNormal, "Mesh", "result", "anim Object, int32 i, ptr:MaxMcpPoint3 OutValue") \
    X(MeshSetFaceMtlIndex, "Mesh", "result", "anim Object, int32 i, uint32 id") \
    X(MeshFaceNormal, "Mesh", "result", "anim Object, uint32 fi, int32 nrmlize, ptr:MaxMcpPoint3 OutValue") \
    X(MeshFaceCenter, "Mesh", "result", "anim Object, uint32 fi, ptr:MaxMcpPoint3 OutValue") \
    X(NodeSetObjOffsetPos, "Node", "result", "node Node, cptr:MaxMcpPoint3 p") \
    X(NodeGetObjOffsetPos, "Node", "result", "node Node, ptr:MaxMcpPoint3 OutValue") \
    X(NodeSetObjOffsetRot, "Node", "result", "node Node, cptr:MaxMcpQuat q") \
    X(NodeGetObjOffsetRot, "Node", "result", "node Node, ptr:MaxMcpQuat OutValue") \
    X(MeshSetNormal, "Mesh", "result", "anim Object, int32 i, cptr:MaxMcpPoint3 xyz") \
    X(MeshSetFaceNormal, "Mesh", "result", "anim Object, int32 i, cptr:MaxMcpPoint3 xyz") \
    X(MeshGetStripNormal, "Mesh", "result", "anim Object, int32 cv, uint32 mID, uint32 smGroup, ptr:MaxMcpPoint3 nor") \
    X(MeshBaryCoords, "Mesh", "result", "anim Object, uint32 face, cptr:MaxMcpPoint3 p, ptr:MaxMcpPoint3 OutValue") \
    X(PolyFaceBBox, "Poly", "result", "anim Object, int32 ff, ptr:MaxMcpBox3 bbox") \
    X(PolyBBox, "Poly", "result", "anim Object, ptr:MaxMcpBox3 bbox, int32 targonly") \
    X(PolyComputeCenter, "Poly", "result", "anim Object, int32 ff, ptr:MaxMcpPoint3 ctr") \
    X(PolyComputeSafeCenter, "Poly", "result", "anim Object, int32 ff, ptr:MaxMcpPoint3 ctr, ptr:int32 OutValue") \
    X(PolyGetVertexNormal, "Poly", "result", "anim Object, int32 vrt, ptr:MaxMcpPoint3 OutValue") \
    X(PolyGetEdgeNormal, "Poly", "result", "anim Object, int32 edgeIndex, ptr:MaxMcpPoint3 OutValue") \
    X(PolyGetFaceNormal, "Poly", "result", "anim Object, int32 fc, int32 nrmlz, ptr:MaxMcpPoint3 OutValue") \
    X(ControllerClearIKParam, "Controller", "result", "anim Controller, cptr:MaxMcpInterval iv, int32 index") \
    X(ControllerRescaleTime, "Controller", "result", "anim Controller, cptr:MaxMcpInterval oseg, cptr:MaxMcpInterval nseg, ptr:int32 OutValue") \
    X(SceneSetStatusXYZ, "Scene", "result", "cptr:MaxMcpAngAxis aa") \
    X(SceneGetAnimRange, "Scene", "result", "ptr:MaxMcpInterval OutValue") \
    X(SceneGetDefaultRendererClassID, "Scene", "result", "int32 renderSettingID, ptr:MaxMcpClassID OutValue") \
    X(SceneSetDefaultRendererClassID, "Scene", "result", "int32 renderSettingID, cptr:MaxMcpClassID classID") \
    X(SceneZoomToBounds, "Scene", "result", "int32 doAll, cptr:MaxMcpBox3 box") \
    X(SceneGetSelectionWorldBox, "Scene", "result", "int32 t, ptr:MaxMcpBox3 box") \
    X(SceneSetViewportBGColor, "Scene", "result", "cptr:MaxMcpPoint3 color") \
    X(SceneGetViewportBGColor, "Scene", "result", "ptr:MaxMcpPoint3 OutValue") \
    X(SceneGetAmbient, "Scene", "result", "int32 t, ptr:MaxMcpInterval valid, ptr:MaxMcpPoint3 OutValue") \
    X(SceneGetLightTint, "Scene", "result", "int32 t, ptr:MaxMcpInterval valid, ptr:MaxMcpPoint3 OutValue") \
    X(SceneSetLightTint, "Scene", "result", "int32 t, cptr:MaxMcpPoint3 col") \
    X(SceneGetLightLevel, "Scene", "result", "int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(SceneGetBackGround, "Scene", "result", "int32 t, ptr:MaxMcpInterval valid, ptr:MaxMcpPoint3 OutValue") \
    X(SceneSetBackGround, "Scene", "result", "int32 t, cptr:MaxMcpPoint3 col") \
    X(Scene7GetPivotMode, "Scene7", "result", "ptr:int32 OutValue") \
    X(Scene7GetAffectChildren, "Scene7", "result", "ptr:int32 OutValue") \
    X(Scene7SetAffectChildren, "Scene7", "result", "int32 bAffectChildren") \
    X(Scene7ShouldContinueRenderOnError, "Scene7", "result", "ptr:int32 OutValue") \
    X(Scene7IncrRenderActive, "Scene7", "result", "") \
    X(Scene7DecrRenderActive, "Scene7", "result", "") \
    X(Scene7XRefRenderEnd, "Scene7", "result", "") \
    X(Scene7OpenRenderDialog, "Scene7", "result", "") \
    X(Scene7CancelRenderDialog, "Scene7", "result", "") \
    X(Scene7CloseRenderDialog, "Scene7", "result", "") \
    X(Scene7CommitRenderDialogParameters, "Scene7", "result", "") \
    X(Scene7UpdateRenderDialogParameters, "Scene7", "result", "") \
    X(Scene7FlushAllTrackViewWindows, "Scene7", "result", "") \
    X(Scene7UnFlushAllTrackViewWindows, "Scene7", "result", "") \
    X(Scene7CloseAllTrackViewWindows, "Scene7", "result", "") \
    X(Scene7SelectedHistoryChanged, "Scene7", "result", "") \
    X(Scene7CmdPanelOpen, "Scene7", "result", "ptr:int32 OutValue") \
    X(Scene7SuspendEditing, "Scene7", "result", "uint32 whichPanels") \
    X(Scene7ResumeEditing, "Scene7", "result", "uint32 whichPanels") \
    X(Scene7SuspendMotionEditing, "Scene7", "result", "") \
    X(Scene7ResumeMotionEditing, "Scene7", "result", "") \
    X(Scene7ReBuildSuperList, "Scene7", "result", "") \
    X(Scene7IsEditing, "Scene7", "result", "ptr:int32 OutValue") \
    X(Scene7ChangeHistory, "Scene7", "result", "int32 upDown") \
    X(Scene7UpdateLockCheckObjectCounts, "Scene7", "result", "") \
    X(Scene7GetMAXIniFile, "Scene7", "result", "ptr:MaxMcpStrOut OutValue") \
    X(Scene7CloseAllSchematicViewWindows, "Scene7", "result", "") \
    X(Scene7FlushAllSchematicViewWindows, "Scene7", "result", "") \
    X(Scene7UnFlushAllSchematicViewWindows, "Scene7", "result", "") \
    X(Scene7EnableDrawing, "Scene7", "result", "int32 onOff") \
    X(Scene7SetSceneDisplayFlag, "Scene7", "result", "uint32 flag, int32 onOff, int32 updateUI") \
    X(Scene7GetActiveMtlSlot, "Scene7", "result", "ptr:int32 OutValue") \
    X(Scene7SetActiveMtlSlot, "Scene7", "result", "int32 i") \
    X(Scene7FlushMtlDlg, "Scene7", "result", "") \
    X(Scene7UnFlushMtlDlg, "Scene7", "result", "") \
    X(Scene7IsMtlDlgShowing, "Scene7", "result", "ptr:int32 OutValue") \
    X(Scene7OpenMtlDlg, "Scene7", "result", "") \
    X(Scene7CloseMtlDlg, "Scene7", "result", "") \
    X(Scene7ResetAllViews, "Scene7", "result", "") \
    X(Scene7GetLockImageAspRatio, "Scene7", "result", "ptr:int32 OutValue") \
    X(Scene7SetLockImageAspRatio, "Scene7", "result", "int32 on") \
    X(Scene7GetImageAspRatio, "Scene7", "result", "ptr:float OutValue") \
    X(Scene7SetImageAspRatio, "Scene7", "result", "float on") \
    X(Scene7GetLockPixelAspRatio, "Scene7", "result", "ptr:int32 OutValue") \
    X(Scene7SetLockPixelAspRatio, "Scene7", "result", "int32 on") \
    X(Scene7GetPixelAspRatio, "Scene7", "result", "ptr:float OutValue") \
    X(Scene7SetPixelAspRatio, "Scene7", "result", "float on") \
    X(Scene7SetViewportGridVisible, "Scene7", "result", "int32 index, int32 state") \
    X(Scene7ViewportInvalidate, "Scene7", "result", "int32 index") \
    X(Scene7ViewportInvalidateBkgImage, "Scene7", "result", "int32 index") \
    X(Scene7InvalidateAllViewportRects, "Scene7", "result", "") \
    X(Scene7RedrawViewportsNow, "Scene7", "result", "int32 t, uint32 vpFlags") \
    X(Scene7RedrawViewportsLater, "Scene7", "result", "int32 t, uint32 vpFlags") \
    X(Scene7SetActiveViewportRenderLevel, "Scene7", "result", "int32 level") \
    X(Scene7GetActiveViewportRenderLevel, "Scene7", "result", "ptr:int32 OutValue") \
    X(Scene7SetActiveViewportShowEdgeFaces, "Scene7", "result", "int32 show") \
    X(Scene7GetActiveViewportShowEdgeFaces, "Scene7", "result", "ptr:int32 OutValue") \
    X(Scene7SetActiveViewportTransparencyLevel, "Scene7", "result", "int32 level") \
    X(Scene7GetActiveViewportTransparencyLevel, "Scene7", "result", "ptr:int32 OutValue") \
    X(Scene7GetDualPlanes, "Scene7", "result", "ptr:int32 OutValue") \
    X(Scene7SetDualPlanes, "Scene7", "result", "int32 b") \
    X(Scene7SetTestOnlyFrozen, "Scene7", "result", "int32 onOff") \
    X(Scene7SetScaleMode, "Scene7", "result", "int32 mode") \
    X(Scene7SetCenterMode, "Scene7", "result", "int32 mode") \
    X(Scene7StartManipulateMode, "Scene7", "result", "") \
    X(Scene7EndManipulateMode, "Scene7", "result", "") \
    X(Scene7XRefSceneSetIgnoreFlag, "Scene7", "result", "int32 index, uint32 f, int32 onOff") \
    X(Scene7UpdateSceneXRefState, "Scene7", "result", "") \
    X(Scene7GetSnapActive, "Scene7", "result", "ptr:int32 OutValue") \
    X(Scene7SetSnapActive, "Scene7", "result", "int32 onOff") \
    X(Scene7GetSnapType, "Scene7", "result", "ptr:int32 OutValue") \
    X(Scene7SetSnapType, "Scene7", "result", "int32 type") \
    X(Scene7ToggleASnap, "Scene7", "result", "") \
    X(Scene7TogglePSnap, "Scene7", "result", "") \
    X(Scene7SetGridSpacing, "Scene7", "result", "float newVal") \
    X(Scene7SetGridMajorLines, "Scene7", "result", "float newVal") \
    X(Scene7GetSnapAngle, "Scene7", "result", "ptr:float OutValue") \
    X(Scene7SetSnapAngle, "Scene7", "result", "float newVal") \
    X(Scene7GetSnapPercent, "Scene7", "result", "ptr:float OutValue") \
    X(Scene7SetSnapPercent, "Scene7", "result", "float newVal") \
    X(Scene7SetExpertMode, "Scene7", "result", "int32 onOff") \
    X(Scene7GetExpertMode, "Scene7", "result", "ptr:int32 OutValue") \
    X(Scene7WriteCUIConfig, "Scene7", "result", "") \
    X(Scene7SaveCUIAs, "Scene7", "result", "") \
    X(Scene7LoadCUI, "Scene7", "result", "") \
    X(Scene7RevertToBackupCUI, "Scene7", "result", "") \
    X(Scene7ResetToFactoryDefaultCUI, "Scene7", "result", "") \
    X(Scene7GetGridIntens, "Scene7", "result", "ptr:float OutValue") \
    X(Scene7SetGridIntens, "Scene7", "result", "float f") \
    X(Scene7GetWhiteOrigin, "Scene7", "result", "ptr:int32 OutValue") \
    X(Scene7SetWhiteOrigin, "Scene7", "result", "int32 b") \
    X(Scene7GetUseGridColor, "Scene7", "result", "ptr:int32 OutValue") \
    X(Scene7SetUseGridColor, "Scene7", "result", "int32 b") \
    X(Scene7UpdateColors, "Scene7", "result", "int32 useGridColor, int32 gridIntensity, int32 whiteOrigin") \
    X(Scene7RepaintTimeSlider, "Scene7", "result", "") \
    X(Scene7StartAnimPlayback2, "Scene7", "result", "int32 selOnly") \
    X(Scene7OpenEnvEffectsDialog, "Scene7", "result", "") \
    X(Scene7CloseEnvEffectsDialog, "Scene7", "result", "") \
    X(AnimClassID, "Anim", "result", "anim Anim, ptr:MaxMcpClassID OutValue") \
    X(AnimTestFlagBit, "Anim", "result", "anim Anim, int32 index, ptr:int32 OutValue") \
    X(AnimSetFlagBit, "Anim", "result", "anim Anim, int32 index, int32 newValue") \
    X(AnimClearFlagBit, "Anim", "result", "anim Anim, int32 index") \
    X(AnimFreeCaches, "Anim", "result", "anim Anim") \
    X(AnimNumSubs, "Anim", "result", "anim Anim, ptr:int32 OutValue") \
    X(AnimBypassTreeView, "Anim", "result", "anim Anim, ptr:int32 OutValue") \
    X(AnimBypassTrackBar, "Anim", "result", "anim Anim, ptr:int32 OutValue") \
    X(AnimBypassPropertyLevel, "Anim", "result", "anim Anim, ptr:int32 OutValue") \
    X(AnimInvisibleProperty, "Anim", "result", "anim Anim, ptr:int32 OutValue") \
    X(AnimGetSubAnimCurveColor, "Anim", "result", "anim Anim, int32 subNum, ptr:uint32 OutValue") \
    X(AnimCanCopyAnim, "Anim", "result", "anim Anim, ptr:int32 OutValue") \
    X(AnimCanMakeUnique, "Anim", "result", "anim Anim, ptr:int32 OutValue") \
    X(AnimHasSubElements, "Anim", "result", "anim Anim, int32 type, ptr:int32 OutValue") \
    X(AnimRenderEnd, "Anim", "result", "anim Anim, int32 t, ptr:int32 OutValue") \
    X(AnimEditTrack, "Anim", "result", "anim Anim") \
    X(AnimNumKeys, "Anim", "result", "anim Anim, ptr:int32 OutValue") \
    X(AnimGetKeyTime, "Anim", "result", "anim Anim, int32 index, ptr:int32 OutValue") \
    X(AnimGetKeyIndex, "Anim", "result", "anim Anim, int32 t, ptr:int32 OutValue") \
    X(AnimCopyKeysFromTime, "Anim", "result", "anim Anim, int32 src, int32 dst, uint32 flags") \
    X(AnimDeleteKeyAtTime, "Anim", "result", "anim Anim, int32 t") \
    X(AnimIsKeyAtTime, "Anim", "result", "anim Anim, int32 t, uint32 flags, ptr:int32 OutValue") \
    X(AnimOpenTreeEntry, "Anim", "result", "anim Anim, int32 type, uint32 tv") \
    X(AnimCloseTreeEntry, "Anim", "result", "anim Anim, int32 type, uint32 tv") \
    X(AnimIsTreeEntryOpen, "Anim", "result", "anim Anim, int32 type, uint32 tv, ptr:int32 OutValue") \
    X(AnimSetSelInTrackView, "Anim", "result", "anim Anim, uint32 tv, int32 sel") \
    X(AnimSetTrackViewSelSet, "Anim", "result", "anim Anim, int32 which, int32 inOut") \
    X(AnimGetTimeRange, "Anim", "result", "anim Anim, uint32 flags, ptr:MaxMcpInterval OutValue") \
    X(AnimEditTimeRange, "Anim", "result", "anim Anim, cptr:MaxMcpInterval range, uint32 flags") \
    X(AnimDeleteTime, "Anim", "result", "anim Anim, cptr:MaxMcpInterval iv, uint32 flags") \
    X(AnimReverseTime, "Anim", "result", "anim Anim, cptr:MaxMcpInterval iv, uint32 flags") \
    X(AnimScaleTime, "Anim", "result", "anim Anim, cptr:MaxMcpInterval iv, float s") \
    X(AnimInsertTime, "Anim", "result", "anim Anim, int32 ins, int32 amount") \
    X(AnimSupportTimeOperations, "Anim", "result", "anim Anim, ptr:int32 OutValue") \
    X(AnimDeleteKeys, "Anim", "result", "anim Anim, uint32 flags") \
    X(AnimDeleteKeyByIndex, "Anim", "result", "anim Anim, int32 index") \
    X(AnimSelectSubCurve, "Anim", "result", "anim Anim, int32 subNum, int32 sel") \
    X(AnimSelectKeyByIndex, "Anim", "result", "anim Anim, int32 i, int32 sel") \
    X(AnimIsKeySelected, "Anim", "result", "anim Anim, int32 i, ptr:int32 OutValue") \
    X(AnimGetFlagKeyIndex, "Anim", "result", "anim Anim, ptr:int32 OutValue") \
    X(AnimNumSelKeys, "Anim", "result", "anim Anim, ptr:int32 OutValue") \
    X(AnimCloneSelectedKeys, "Anim", "result", "anim Anim, int32 offset") \
    X(AnimAddNewKey, "Anim", "result", "anim Anim, int32 t, uint32 flags") \
    X(AnimSelectCurve, "Anim", "result", "anim Anim, int32 sel") \
    X(AnimIsCurveSelected, "Anim", "result", "anim Anim, ptr:int32 OutValue") \
    X(AnimIsSubCurveSelected, "Anim", "result", "anim Anim, int32 subNum, ptr:int32 OutValue") \
    X(AnimSetSelKeyCoords, "Anim", "result", "anim Anim, int32 t, float val, uint32 flags") \
    X(AnimSubAnimSetKeyBufferPresent, "Anim", "result", "anim Anim, int32 subNum, ptr:int32 OutValue") \
    X(AnimSetKeyBufferPresent, "Anim", "result", "anim Anim, ptr:int32 OutValue") \
    X(AnimSubAnimCommitSetKeyBuffer, "Anim", "result", "anim Anim, int32 t, int32 subNum") \
    X(AnimCommitSetKeyBuffer, "Anim", "result", "anim Anim, int32 t") \
    X(AnimSubAnimRevertSetKeyBuffer, "Anim", "result", "anim Anim, int32 subNum") \
    X(AnimRevertSetKeyBuffer, "Anim", "result", "anim Anim") \
    X(AnimIsAnimated, "Anim", "result", "anim Anim, ptr:int32 OutValue") \
    X(AnimCanCopySubTrack, "Anim", "result", "anim Anim, int32 subNum, cptr:MaxMcpInterval iv, uint32 flags, ptr:int32 OutValue") \
    X(AnimGetTrackVSpace, "Anim", "result", "anim Anim, int32 lineHeight, ptr:int32 OutValue") \
    X(AnimTrackParamsType, "Anim", "result", "anim Anim, ptr:int32 OutValue") \
    X(AnimHasNoteTracks, "Anim", "result", "anim Anim, ptr:int32 OutValue") \
    X(AnimNumNoteTracks, "Anim", "result", "anim Anim, ptr:int32 OutValue") \
    X(AnimDeleteAllNoteTracks, "Anim", "result", "anim Anim, ptr:uint32 OutValue") \
    X(AnimFreeAllBitmaps, "Anim", "result", "anim Anim") \
    X(AnimIsSubClassOf, "Anim", "result", "anim Anim, cptr:MaxMcpClassID classID, ptr:int32 OutValue") \
    X(AnimClearAllAppData, "Anim", "result", "anim Anim") \
    X(AnimMouseCycleCompleted, "Anim", "result", "anim Anim, int32 t") \
    X(AnimMouseCycleStarted, "Anim", "result", "anim Anim, int32 t") \
    X(AnimNumParamBlocks, "Anim", "result", "anim Anim, ptr:int32 OutValue") \
    X(AnimSvSetRefIndex, "Anim", "result", "anim Anim, uint32 i") \
    X(AnimAllocCustAttribContainer, "Anim", "result", "anim Anim") \
    X(AnimDeleteCustAttribContainer, "Anim", "result", "anim Anim") \
    X(ObjectIsRenderable, "Object", "result", "anim Anim, ptr:int32 OutValue") \
    X(ObjectUsesWireColor, "Object", "result", "anim Anim, ptr:int32 OutValue") \
    X(ObjectDoOwnSelectHilite, "Object", "result", "anim Anim, ptr:int32 OutValue") \
    X(ObjectNormalAlignVector, "Object", "result", "anim Anim, int32 t, ptr:MaxMcpPoint3 pt, ptr:MaxMcpPoint3 norm, ptr:int32 OutValue") \
    X(ObjectCanCacheObject, "Object", "result", "anim Anim, ptr:int32 OutValue") \
    X(ObjectWSStateInvalidate, "Object", "result", "anim Anim") \
    X(ObjectIsWorldSpaceObject, "Object", "result", "anim Anim, ptr:int32 OutValue") \
    X(ObjectGetWorldSpaceObjectNode, "Object", "result", "anim Anim, ptr:node OutValue") \
    X(ObjectIsParticleSystem, "Object", "result", "anim Anim, ptr:int32 OutValue") \
    X(ObjectTopologyChanged, "Object", "result", "anim Anim") \
    X(ObjectIsDeformable, "Object", "result", "anim Anim, ptr:int32 OutValue") \
    X(ObjectNumPoints, "Object", "result", "anim Anim, ptr:int32 OutValue") \
    X(ObjectGetPoint, "Object", "result", "anim Anim, int32 i, ptr:MaxMcpPoint3 OutValue") \
    X(ObjectSetPoint, "Object", "result", "anim Anim, int32 i, cptr:MaxMcpPoint3 p") \
    X(ObjectIsPointSelected, "Object", "result", "anim Anim, int32 i, ptr:int32 OutValue") \
    X(ObjectPointSelection, "Object", "result", "anim Anim, int32 i, ptr:float OutValue") \
    X(ObjectGetWeight, "Object", "result", "anim Anim, int32 i, ptr:double OutValue") \
    X(ObjectSetWeight, "Object", "result", "anim Anim, int32 i, double w") \
    X(ObjectPointsWereChanged, "Object", "result", "anim Anim") \
    X(ObjectNumMapsUsed, "Object", "result", "anim Anim, ptr:int32 OutValue") \
    X(ObjectConvertToType, "Object", "result", "anim Anim, int32 t, cptr:MaxMcpClassID obtype, ptr:anim OutValue") \
    X(ObjectPreferredCollapseType, "Object", "result", "anim Anim, ptr:MaxMcpClassID OutValue") \
    X(ObjectCollapseObject, "Object", "result", "anim Anim, ptr:anim OutValue") \
    X(ObjectGetSubselState, "Object", "result", "anim Anim, ptr:uint32 OutValue") \
    X(ObjectSetSubSelState, "Object", "result", "anim Anim, uint32 s") \
    X(ObjectObjectValidity, "Object", "result", "anim Anim, int32 t, ptr:MaxMcpInterval OutValue") \
    X(ObjectIsBaseClassOwnedChannel, "Object", "result", "anim Anim, int32 nchan, ptr:int32 OutValue") \
    X(ObjectReduceCaches, "Object", "result", "anim Anim, int32 t") \
    X(ObjectIsConstObject, "Object", "result", "anim Anim, ptr:int32 OutValue") \
    X(ObjectNumPipeBranches, "Object", "result", "anim Anim, int32 selected, ptr:int32 OutValue") \
    X(ObjectGetPipeBranch, "Object", "result", "anim Anim, int32 i, int32 selected, ptr:anim OutValue") \
    X(ObjectNumberOfContainedShapes, "Object", "result", "anim Anim, ptr:int32 OutValue") \
    X(ObjectIsShapeObject, "Object", "result", "anim Anim, ptr:int32 OutValue") \
    X(ObjectCheckObjectIntegrity, "Object", "result", "anim Anim, ptr:int32 OutValue") \
    X(ObjectFindBaseObject, "Object", "result", "anim Anim, ptr:anim OutValue") \
    X(ObjectIsParamSurface, "Object", "result", "anim Anim, ptr:int32 OutValue") \
    X(ObjectNumSurfaces, "Object", "result", "anim Anim, int32 t, ptr:int32 OutValue") \
    X(ObjectGetSurfacePoint, "Object", "result", "anim Anim, int32 t, float u, float v, ptr:MaxMcpInterval iv, ptr:MaxMcpPoint3 OutValue") \
    X(ObjectUseSelectionBrackets, "Object", "result", "anim Anim, ptr:int32 OutValue") \
    X(ObjectIsManipulator, "Object", "result", "anim Anim, ptr:int32 OutValue") \
    X(ObjectReduceDisplayCaches, "Object", "result", "anim Anim") \
    X(ObjectStartStackEval, "Object", "result", "anim Anim") \
    X(ObjectEndStackEval, "Object", "result", "anim Anim") \
    X(PatchPatchObjectInit, "Patch", "result", "anim Object") \
    X(PatchGetObjectDisplayRequirement, "Patch", "result", "anim Object, ptr:uint32 OutValue") \
    X(PatchSetChannelValidity, "Patch", "result", "anim Object, int32 i, cptr:MaxMcpInterval v") \
    X(PatchTopologyChanged, "Patch", "result", "anim Object") \
    X(PatchConvertValidity, "Patch", "result", "anim Object, int32 t, ptr:MaxMcpInterval OutValue") \
    X(PatchSetPoint, "Patch", "result", "anim Object, int32 i, cptr:MaxMcpPoint3 p") \
    X(PatchPointsWereChanged, "Patch", "result", "anim Object") \
    X(PatchDeleteThis, "Patch", "result", "anim Object") \
    X(PatchFreeCaches, "Patch", "result", "anim Object") \
    X(PatchRescaleWorldUnits, "Patch", "result", "anim Object, float f") \
    X(PatchPlugControllersSel, "Patch", "result", "anim Object, int32 t") \
    X(PatchAllocVertContArray, "Patch", "result", "anim Object, int32 count") \
    X(PatchAllocVecContArray, "Patch", "result", "anim Object, int32 count") \
    X(PatchAllocContArrays, "Patch", "result", "anim Object, int32 vertCount, int32 vecCount") \
    X(PatchSetVertAnim, "Patch", "result", "anim Object, int32 t, int32 point, cptr:MaxMcpPoint3 pt") \
    X(PatchSetVecAnim, "Patch", "result", "anim Object, int32 t, int32 point, cptr:MaxMcpPoint3 pt") \
    X(PatchUpdatePatchMesh, "Patch", "result", "anim Object, int32 t") \
    X(PatchPrepareMesh, "Patch", "result", "anim Object, int32 t") \
    X(PatchShowLattice, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchShowVerts, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchSetShowLattice, "Patch", "result", "anim Object, int32 sw") \
    X(PatchSetShowVerts, "Patch", "result", "anim Object, int32 sw") \
    X(PatchSetMeshSteps, "Patch", "result", "anim Object, int32 steps") \
    X(PatchGetMeshSteps, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchSetMeshStepsRender, "Patch", "result", "anim Object, int32 steps") \
    X(PatchGetMeshStepsRender, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchSetRelax, "Patch", "result", "anim Object, int32 v") \
    X(PatchSetRelaxViewports, "Patch", "result", "anim Object, int32 v") \
    X(PatchSetRelaxValue, "Patch", "result", "anim Object, float v") \
    X(PatchSetRelaxIter, "Patch", "result", "anim Object, int32 v") \
    X(PatchSetRelaxBoundary, "Patch", "result", "anim Object, int32 v") \
    X(PatchSetRelaxSaddle, "Patch", "result", "anim Object, int32 v") \
    X(PatchSetShowInterior, "Patch", "result", "anim Object, int32 si") \
    X(PatchGetShowInterior, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchSetUsePatchNormals, "Patch", "result", "anim Object, int32 usePatchNorm") \
    X(PatchGetUsePatchNormals, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchSetAdaptive, "Patch", "result", "anim Object, int32 sw") \
    X(PatchGetAdaptive, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchGetViewTessNormals, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchSetViewTessNormals, "Patch", "result", "anim Object, int32 use") \
    X(PatchGetProdTessNormals, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchSetProdTessNormals, "Patch", "result", "anim Object, int32 use") \
    X(PatchGetViewTessWeld, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchSetViewTessWeld, "Patch", "result", "anim Object, int32 weld") \
    X(PatchGetProdTessWeld, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchSetProdTessWeld, "Patch", "result", "anim Object, int32 weld") \
    X(PatchInvalidateRelaxedMesh, "Patch", "result", "anim Object") \
    X(PatchGetSubobjectLevel, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchGetSubobjectType, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchSetSubobjectLevel, "Patch", "result", "anim Object, int32 level") \
    X(PatchShowEndResultChanged, "Patch", "result", "anim Object, int32 showEndResult") \
    X(PatchClearSelection, "Patch", "result", "anim Object, int32 selLevel") \
    X(PatchSelectAll, "Patch", "result", "anim Object, int32 selLevel") \
    X(PatchInvertSelection, "Patch", "result", "anim Object, int32 selLevel") \
    X(PatchPatchSelChanged, "Patch", "result", "anim Object") \
    X(PatchInvalidateSurfaceUI, "Patch", "result", "anim Object") \
    X(PatchInvalidateOpsUI, "Patch", "result", "anim Object") \
    X(PatchChangeRememberedPatch, "Patch", "result", "anim Object, int32 type") \
    X(PatchChangeSelPatches, "Patch", "result", "anim Object, int32 type") \
    X(PatchSetRememberedPatchType, "Patch", "result", "anim Object, int32 type") \
    X(PatchChangeRememberedVert, "Patch", "result", "anim Object, int32 type") \
    X(PatchChangeSelVerts, "Patch", "result", "anim Object, int32 type") \
    X(PatchSetRememberedVertType, "Patch", "result", "anim Object, int32 type") \
    X(PatchTransformStart, "Patch", "result", "anim Object, int32 t") \
    X(PatchTransformFinish, "Patch", "result", "anim Object, int32 t") \
    X(PatchTransformCancel, "Patch", "result", "anim Object, int32 t") \
    X(PatchSetupNamedSelDropDown, "Patch", "result", "anim Object") \
    X(PatchNSCopy, "Patch", "result", "anim Object") \
    X(PatchNSPaste, "Patch", "result", "anim Object") \
    X(PatchRefreshSelType, "Patch", "result", "anim Object") \
    X(PatchSetNumSelLabel, "Patch", "result", "anim Object") \
    X(PatchSetSelDlgEnables, "Patch", "result", "anim Object") \
    X(PatchSetOpsDlgEnables, "Patch", "result", "anim Object") \
    X(PatchSetSurfDlgEnables, "Patch", "result", "anim Object") \
    X(PatchGetAttachMat, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchSetAttachMat, "Patch", "result", "anim Object, int32 value") \
    X(PatchGetCondenseMat, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchSetCondenseMat, "Patch", "result", "anim Object, int32 sw") \
    X(PatchDoDeleteSelected, "Patch", "result", "anim Object, int32 interactive") \
    X(PatchDoBreak, "Patch", "result", "anim Object, int32 interactive") \
    X(PatchResolveTopoChanges, "Patch", "result", "anim Object") \
    X(PatchCreateContArrays, "Patch", "result", "anim Object") \
    X(PatchSynchContArrays, "Patch", "result", "anim Object") \
    X(PatchGetSelMatIndex, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchSetSelMatIndex, "Patch", "result", "anim Object, int32 index") \
    X(PatchSelectByMat, "Patch", "result", "anim Object, int32 index, int32 clear") \
    X(PatchSelectBySmoothGroup, "Patch", "result", "anim Object, uint32 bits, int32 clear") \
    X(PatchSetSelSmoothBits, "Patch", "result", "anim Object, uint32 bits, uint32 which") \
    X(PatchSetPropagate, "Patch", "result", "anim Object, int32 sw") \
    X(PatchGetPropagate, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchDoPatchAdd, "Patch", "result", "anim Object, int32 type") \
    X(PatchDoSubdivide, "Patch", "result", "anim Object, int32 level") \
    X(PatchDoPatchDetach, "Patch", "result", "anim Object, int32 copy, int32 reorient") \
    X(PatchDoVertWeld, "Patch", "result", "anim Object") \
    X(PatchDoEdgeWeld, "Patch", "result", "anim Object") \
    X(PatchStartCopyTangentMode, "Patch", "result", "anim Object") \
    X(PatchStartPasteTangentMode, "Patch", "result", "anim Object") \
    X(PatchStartPasteTangent, "Patch", "result", "anim Object") \
    X(PatchEndPasteTangent, "Patch", "result", "anim Object") \
    X(PatchDoHide, "Patch", "result", "anim Object, int32 type") \
    X(PatchDoUnHide, "Patch", "result", "anim Object") \
    X(PatchDoPatchHide, "Patch", "result", "anim Object") \
    X(PatchDoVertHide, "Patch", "result", "anim Object") \
    X(PatchDoEdgeHide, "Patch", "result", "anim Object") \
    X(PatchDoAddHook, "Patch", "result", "anim Object, int32 vert1, int32 seg1") \
    X(PatchDoRemoveHook, "Patch", "result", "anim Object") \
    X(PatchDoExtrude, "Patch", "result", "anim Object, int32 t") \
    X(PatchBeginExtrude, "Patch", "result", "anim Object, int32 t") \
    X(PatchEndExtrude, "Patch", "result", "anim Object, int32 t, int32 accept") \
    X(PatchExtrude, "Patch", "result", "anim Object, int32 t, float amount, int32 useLocalNorm") \
    X(PatchDoFlipNormals, "Patch", "result", "anim Object, int32 patchIndex") \
    X(PatchDoUnifyNormals, "Patch", "result", "anim Object") \
    X(PatchDoBevel, "Patch", "result", "anim Object, int32 t") \
    X(PatchBeginBevel, "Patch", "result", "anim Object, int32 t") \
    X(PatchEndBevel, "Patch", "result", "anim Object, int32 t, int32 accept") \
    X(PatchBevel, "Patch", "result", "anim Object, int32 t, float amount, int32 smoothStart, int32 smoothEnd") \
    X(PatchDoPatchSmooth, "Patch", "result", "anim Object, int32 type") \
    X(PatchCreatePatch, "Patch", "result", "anim Object, int32 vertIndx1, int32 vertIndx2, int32 vertIndx3") \
    X(PatchGetSelLevel, "Patch", "result", "anim Object, ptr:uint32 OutValue") \
    X(PatchSetSelLevel, "Patch", "result", "anim Object, uint32 level") \
    X(PatchLocalDataChanged, "Patch", "result", "anim Object") \
    X(PatchSetVertColor, "Patch", "result", "anim Object, cptr:MaxMcpColor clr, int32 mp") \
    X(PatchSetPatchColor, "Patch", "result", "anim Object, cptr:MaxMcpColor clr, int32 mp") \
    X(PatchChangeMappingTypeLinear, "Patch", "result", "anim Object, int32 linear") \
    X(PatchShrinkSelection, "Patch", "result", "anim Object, int32 type") \
    X(PatchGrowSelection, "Patch", "result", "anim Object, int32 type") \
    X(PatchSelectEdgeRing, "Patch", "result", "anim Object") \
    X(PatchSelectEdgeLoop, "Patch", "result", "anim Object") \
    X(PatchSelectOpenEdges, "Patch", "result", "anim Object") \
    X(PatchDoCreateShape, "Patch", "result", "anim Object") \
    X(PatchUseEdgeDists, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchSetUseEdgeDists, "Patch", "result", "anim Object, int32 useSoftSelections") \
    X(PatchUseSoftSelections, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchSetUseSoftSelections, "Patch", "result", "anim Object, int32 useSoftSelections") \
    X(PatchInvalidateVertexWeights, "Patch", "result", "anim Object") \
    X(PatchToggleShadedFaces, "Patch", "result", "anim Object") \
    X(PatchUpdateVertexDists, "Patch", "result", "anim Object") \
    X(PatchUpdateEdgeDists, "Patch", "result", "anim Object") \
    X(PatchUpdateVertexWeights, "Patch", "result", "anim Object") \
    X(SplineSplineShapeInit, "Spline", "result", "node Node") \
    X(SplineTransformStart, "Spline", "result", "node Node, int32 t") \
    X(SplineTransformFinish, "Spline", "result", "node Node, int32 t") \
    X(SplineTransformCancel, "Spline", "result", "node Node, int32 t") \
    X(SplineSetupNamedSelDropDown, "Spline", "result", "node Node") \
    X(SplineNSCopy, "Spline", "result", "node Node") \
    X(SplineNSPaste, "Spline", "result", "node Node") \
    X(SplineSetChannelValidity, "Spline", "result", "node Node, int32 i, cptr:MaxMcpInterval v") \
    X(SplineSetPoint, "Spline", "result", "node Node, int32 i, cptr:MaxMcpPoint3 p") \
    X(SplinePointsWereChanged, "Spline", "result", "node Node") \
    X(SplineDeleteThis, "Spline", "result", "node Node") \
    X(SplineRescaleWorldUnits, "Spline", "result", "node Node, float f") \
    X(SplineCreateContArray, "Spline", "result", "node Node") \
    X(SplineSynchContArray, "Spline", "result", "node Node") \
    X(SplineAllocContArray, "Spline", "result", "node Node, int32 count") \
    X(SplineInsertPointConts, "Spline", "result", "node Node, int32 index, int32 count") \
    X(SplineReversePointConts, "Spline", "result", "node Node, int32 index, int32 count, int32 keepFirst") \
    X(SplineNullPointConts, "Spline", "result", "node Node, int32 index, int32 count") \
    X(SplineNullPolyPointConts, "Spline", "result", "node Node, int32 poly") \
    X(SplinePlugControllersSel, "Spline", "result", "node Node, int32 t") \
    X(SplineSetPointAnim, "Spline", "result", "node Node, int32 t, int32 poly, int32 vert, cptr:MaxMcpPoint3 pt") \
    X(SplineGetSubobjectLevel, "Spline", "result", "node Node, ptr:int32 OutValue") \
    X(SplineSetSubobjectLevel, "Spline", "result", "node Node, int32 level") \
    X(SplineClearSelection, "Spline", "result", "node Node, int32 level") \
    X(SplineSelectAll, "Spline", "result", "node Node, int32 level") \
    X(SplineInvertSelection, "Spline", "result", "node Node, int32 level") \
    X(SplineShowEndResultChanged, "Spline", "result", "node Node, int32 showEndResult") \
    X(SplineBeginOutlineMove, "Spline", "result", "node Node, int32 t") \
    X(SplineBeginFilletMove, "Spline", "result", "node Node, int32 t") \
    X(SplineBeginChamferMove, "Spline", "result", "node Node, int32 t") \
    X(SplineOutlineMove, "Spline", "result", "node Node, int32 t, float amount") \
    X(SplineFilletMove, "Spline", "result", "node Node, int32 t, float amount") \
    X(SplineChamferMove, "Spline", "result", "node Node, int32 t, float amount") \
    X(SplineEndMoveModes, "Spline", "result", "node Node, int32 t, int32 accept") \
    X(SplineEndOutlineMove, "Spline", "result", "node Node, int32 t, int32 accept") \
    X(SplineEndFilletMove, "Spline", "result", "node Node, int32 t, int32 accept") \
    X(SplineEndChamferMove, "Spline", "result", "node Node, int32 t, int32 accept") \
    X(SplineStartOutlineMode, "Spline", "result", "node Node") \
    X(SplineStartFilletMode, "Spline", "result", "node Node") \
    X(SplineStartChamferMode, "Spline", "result", "node Node") \
    X(SplineStartSegBreakMode, "Spline", "result", "node Node") \
    X(SplineStartSegRefineMode, "Spline", "result", "node Node") \
    X(SplineStartCrossInsertMode, "Spline", "result", "node Node") \
    X(SplineStartVertConnectMode, "Spline", "result", "node Node") \
    X(SplineStartVertInsertMode, "Spline", "result", "node Node, int32 controlID") \
    X(SplineEndVertInsert, "Spline", "result", "node Node, int32 acceptUndo") \
    X(SplineStartCreateLineMode, "Spline", "result", "node Node") \
    X(SplineEndCreateLine, "Spline", "result", "node Node") \
    X(SplineStartCrossSectionMode, "Spline", "result", "node Node") \
    X(SplineStartCrossSection, "Spline", "result", "node Node") \
    X(SplineEndCrossSection, "Spline", "result", "node Node, int32 acceptUndo") \
    X(SplineStartBooleanMode, "Spline", "result", "node Node") \
    X(SplineDoBoolean, "Spline", "result", "node Node, int32 poly2") \
    X(SplineStartTrimMode, "Spline", "result", "node Node") \
    X(SplineStartExtendMode, "Spline", "result", "node Node") \
    X(SplineGetAttachMat, "Spline", "result", "node Node, ptr:int32 OutValue") \
    X(SplineSetAttachMat, "Spline", "result", "node Node, int32 value") \
    X(SplineGetCondenseMat, "Spline", "result", "node Node, ptr:int32 OutValue") \
    X(SplineSetCondenseMat, "Spline", "result", "node Node, int32 sw") \
    X(SplineDoVertBreak, "Spline", "result", "node Node") \
    X(SplineDoVertWeld, "Spline", "result", "node Node") \
    X(SplineDoMakeFirst, "Spline", "result", "node Node") \
    X(SplineDoVertDelete, "Spline", "result", "node Node") \
    X(SplineDoSegDelete, "Spline", "result", "node Node") \
    X(SplineDoSegDetach, "Spline", "result", "node Node, int32 sameShape, int32 copy, int32 reorient") \
    X(SplineDoSegDivide, "Spline", "result", "node Node, int32 divisions") \
    X(SplineDoPolyClose, "Spline", "result", "node Node") \
    X(SplineDoPolyDetach, "Spline", "result", "node Node, int32 copy, int32 reorient") \
    X(SplineDoPolyMirror, "Spline", "result", "node Node, int32 type, int32 copy") \
    X(SplineDoPolyDelete, "Spline", "result", "node Node") \
    X(SplineDoPolyReverse, "Spline", "result", "node Node") \
    X(SplineDoPolyExplode, "Spline", "result", "node Node") \
    X(SplineDoExplodeToObjects, "Spline", "result", "node Node") \
    X(SplineSetBoolOperation, "Spline", "result", "node Node, int32 type") \
    X(SplineSetMirrorOperation, "Spline", "result", "node Node, int32 type") \
    X(SplineGetBoolOperation, "Spline", "result", "node Node, ptr:int32 OutValue") \
    X(SplineGetMirrorOperation, "Spline", "result", "node Node, ptr:int32 OutValue") \
    X(SplineSetBooleanButton, "Spline", "result", "node Node") \
    X(SplineSetMirrorButton, "Spline", "result", "node Node") \
    X(SplineChangeSelVerts, "Spline", "result", "node Node, int32 type") \
    X(SplineChangeRememberedVert, "Spline", "result", "node Node, int32 type") \
    X(SplineSetRememberedVertType, "Spline", "result", "node Node, int32 type") \
    X(SplineChangeSelSegs, "Spline", "result", "node Node, int32 type") \
    X(SplineChangeRememberedSeg, "Spline", "result", "node Node, int32 type") \
    X(SplineSetRememberedSegType, "Spline", "result", "node Node, int32 type") \
    X(SplineChangeSelPolys, "Spline", "result", "node Node, int32 type") \
    X(SplineChangeRememberedPoly, "Spline", "result", "node Node, int32 type") \
    X(SplineSetRememberedPolyType, "Spline", "result", "node Node, int32 type") \
    X(SplineDeleteSpline, "Spline", "result", "node Node, int32 poly") \
    X(SplineReverse, "Spline", "result", "node Node, int32 poly, int32 keepFirst") \
    X(SplineDeleteKnot, "Spline", "result", "node Node, int32 poly, int32 index") \
    X(SplineMakeFirst, "Spline", "result", "node Node, int32 poly, int32 index") \
    X(SplineSetOptimize, "Spline", "result", "node Node, int32 sw") \
    X(SplineSetAdaptive, "Spline", "result", "node Node, int32 sw") \
    X(SplineSetSteps, "Spline", "result", "node Node, int32 n") \
    X(SplineRecordTopologyTags, "Spline", "result", "node Node") \
    X(SplineRecordTopology, "Spline", "result", "node Node") \
    X(SplineRefreshSelType, "Spline", "result", "node Node") \
    X(SplineUpdateSelectDisplay, "Spline", "result", "node Node") \
    X(SplineSetSelDlgEnables, "Spline", "result", "node Node") \
    X(SplineSetOpsDlgEnables, "Spline", "result", "node Node") \
    X(SplineSetSurfDlgEnables, "Spline", "result", "node Node") \
    X(SplineSelectionChanged, "Spline", "result", "node Node") \
    X(SplineSetFCLimit, "Spline", "result", "node Node") \
    X(SplineGetSelMatIndex, "Spline", "result", "node Node, ptr:int32 OutValue") \
    X(SplineSetSelMatIndex, "Spline", "result", "node Node, int32 index") \
    X(SplineSelectByMat, "Spline", "result", "node Node, int32 index, int32 clear") \
    X(SplineInvalidateSurfaceUI, "Spline", "result", "node Node") \
    X(SplineStartBindMode, "Spline", "result", "node Node") \
    X(SplineDoBind, "Spline", "result", "node Node, int32 poly1, int32 vert1, int32 poly2, int32 vert2") \
    X(SplineDoUnBind, "Spline", "result", "node Node") \
    X(SplineDoHide, "Spline", "result", "node Node") \
    X(SplineDoUnhide, "Spline", "result", "node Node") \
    X(SplineDoCycleVerts, "Spline", "result", "node Node") \
    X(SplineStartRefineConnectMode, "Spline", "result", "node Node") \
    X(SplineEndRefineConnectMode, "Spline", "result", "node Node") \
    X(SplineDoVertFuse, "Spline", "result", "node Node") \
    X(SplineStartCopyTangentMode, "Spline", "result", "node Node") \
    X(SplineStartPasteTangentMode, "Spline", "result", "node Node") \
    X(SplineStartPasteTangent, "Spline", "result", "node Node") \
    X(SplineEndPasteTangent, "Spline", "result", "node Node") \
    X(SplineGetSelLevel, "Spline", "result", "node Node, ptr:uint32 OutValue") \
    X(SplineSetSelLevel, "Spline", "result", "node Node, uint32 level") \
    X(SplineLocalDataChanged, "Spline", "result", "node Node") \
    X(SplineSelectBySegment, "Spline", "result", "node Node, int32 interactive") \
    X(SplineSelectBySpline, "Spline", "result", "node Node, int32 interactive") \
    X(SplineInvalidateGeomCache, "Spline", "result", "node Node") \
    X(SplineUseEdgeDists, "Spline", "result", "node Node, ptr:int32 OutValue") \
    X(SplineSetUseEdgeDists, "Spline", "result", "node Node, int32 useSoftSelections") \
    X(SplineUseSoftSelections, "Spline", "result", "node Node, ptr:int32 OutValue") \
    X(SplineSetUseSoftSelections, "Spline", "result", "node Node, int32 useSoftSelections") \
    X(SplineInvalidateVertexWeights, "Spline", "result", "node Node") \
    X(SplineUpdateVertexDists, "Spline", "result", "node Node") \
    X(SplineUpdateEdgeDists, "Spline", "result", "node Node") \
    X(SplineUpdateVertexWeights, "Spline", "result", "node Node") \
    X(PatchMeshSetNumVerts, "Patch", "result", "anim Object, int32 ct, int32 keep, ptr:int32 OutValue") \
    X(PatchMeshSetNumVecs, "Patch", "result", "anim Object, int32 ct, int32 keep, ptr:int32 OutValue") \
    X(PatchMeshSetNumPatches, "Patch", "result", "anim Object, int32 ct, int32 keep, ptr:int32 OutValue") \
    X(PatchMeshSetNumEdges, "Patch", "result", "anim Object, int32 ct, int32 keep, ptr:int32 OutValue") \
    X(PatchMeshGetNumMapVerts, "Patch", "result", "anim Object, int32 mp, ptr:int32 OutValue") \
    X(PatchMeshSetPatchMtlIndex, "Patch", "result", "anim Object, int32 i, uint32 id") \
    X(PatchMeshBuildLinkages, "Patch", "result", "anim Object, int32 patch, ptr:int32 OutValue") \
    X(PatchMeshComputeInteriors, "Patch", "result", "anim Object") \
    X(PatchMeshComputeAux, "Patch", "result", "anim Object") \
    X(PatchMeshBuildBoundingBox, "Patch", "result", "anim Object") \
    X(PatchMeshInvalidateGeomCache, "Patch", "result", "anim Object") \
    X(PatchMeshInvalidateMesh, "Patch", "result", "anim Object") \
    X(PatchMeshInvalidateRelaxedMesh, "Patch", "result", "anim Object") \
    X(PatchMeshFreeAll, "Patch", "result", "anim Object") \
    X(PatchMeshApplyConstraints, "Patch", "result", "anim Object, int32 selOnly") \
    X(PatchMeshSetMeshSteps, "Patch", "result", "anim Object, int32 steps") \
    X(PatchMeshGetMeshSteps, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchMeshSetMeshStepsRender, "Patch", "result", "anim Object, int32 steps") \
    X(PatchMeshGetMeshStepsRender, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchMeshSetShowInterior, "Patch", "result", "anim Object, int32 si") \
    X(PatchMeshGetShowInterior, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchMeshSetUsePatchNormals, "Patch", "result", "anim Object, int32 usePatchNorm") \
    X(PatchMeshGetUsePatchNormals, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchMeshSetAdaptive, "Patch", "result", "anim Object, int32 sw") \
    X(PatchMeshGetAdaptive, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchMeshGetViewTessNormals, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchMeshSetViewTessNormals, "Patch", "result", "anim Object, int32 use") \
    X(PatchMeshGetProdTessNormals, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchMeshSetProdTessNormals, "Patch", "result", "anim Object, int32 use") \
    X(PatchMeshGetViewTessWeld, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchMeshSetViewTessWeld, "Patch", "result", "anim Object, int32 weld") \
    X(PatchMeshGetProdTessWeld, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchMeshSetProdTessWeld, "Patch", "result", "anim Object, int32 weld") \
    X(PatchMeshGetEdge, "Patch", "result", "anim Object, int32 v1, int32 v2, ptr:MaxMcpSpan OutValue") \
    X(PatchMeshGetPatches, "Patch", "result", "anim Object, int32 vert, ptr:MaxMcpSpan OutValue") \
    X(PatchMeshGetEdges, "Patch", "result", "anim Object, int32 vert, ptr:MaxMcpSpan OutValue") \
    X(PatchMeshGetVectors, "Patch", "result", "anim Object, int32 vert, ptr:MaxMcpSpan OutValue") \
    X(PatchMeshSetNumMaps, "Patch", "result", "anim Object, int32 ct, int32 keep") \
    X(PatchMeshSetMapSupport, "Patch", "result", "anim Object, int32 chan, int32 init") \
    X(PatchMeshRecordTopologyTags, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchMeshWeld, "Patch", "result", "anim Object, int32 fromVert, int32 toVert, ptr:int32 OutValue") \
    X(PatchMeshSubdivide, "Patch", "result", "anim Object, int32 type, int32 propagate") \
    X(PatchMeshWeldEdges, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchMeshCreateExtrusion, "Patch", "result", "anim Object, int32 type, int32 edgeClone") \
    X(PatchMeshBuildPatchNormals, "Patch", "result", "anim Object") \
    X(PatchMeshInvalidatePatchNormals, "Patch", "result", "anim Object") \
    X(PatchMeshMoveNormal, "Patch", "result", "anim Object, float amount, int32 useLocalNorms, int32 type") \
    X(PatchMeshFlipPatchNormal, "Patch", "result", "anim Object, int32 index") \
    X(PatchMeshUnifyNormals, "Patch", "result", "anim Object, int32 useSel") \
    X(PatchMeshCreateBevel, "Patch", "result", "anim Object") \
    X(PatchMeshBevel, "Patch", "result", "anim Object, float amount, int32 smoothStart, int32 smoothEnd") \
    X(PatchMeshChangePatchInterior, "Patch", "result", "anim Object, int32 index, int32 type") \
    X(PatchMeshChangeVertType, "Patch", "result", "anim Object, int32 index, int32 type") \
    X(PatchMeshShrinkSelection, "Patch", "result", "anim Object, int32 type") \
    X(PatchMeshGrowSelection, "Patch", "result", "anim Object, int32 type") \
    X(PatchMeshPrepareMesh, "Patch", "result", "anim Object") \
    X(PatchMeshPrepareUnrelaxedMesh, "Patch", "result", "anim Object") \
    X(PatchMeshAutoSmooth, "Patch", "result", "anim Object, float angle, int32 useSel, int32 preventIndirectSmoothing") \
    X(PatchMeshChangePatchToLinearMapping, "Patch", "result", "anim Object, int32 index") \
    X(PatchMeshChangePatchToCurvedMapping, "Patch", "result", "anim Object, int32 index") \
    X(PatchMeshArePatchesLinearMapped, "Patch", "result", "anim Object, int32 index, ptr:int32 OutValue") \
    X(PatchMeshArePatchesCurvedMapped, "Patch", "result", "anim Object, int32 index, ptr:int32 OutValue") \
    X(PatchMeshSingleEdgesOnly, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchMeshSetVertexWeightCount, "Patch", "result", "anim Object, int32 i") \
    X(PatchMeshSetVertexWeight, "Patch", "result", "anim Object, int32 i, float w") \
    X(PatchMeshSupportVSelectionWeights, "Patch", "result", "anim Object") \
    X(PatchMeshVertexWeightSelectLevel, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchMeshUseEdgeDists, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchMeshSetUseEdgeDists, "Patch", "result", "anim Object, int32 edgeDist") \
    X(PatchMeshEdgeDist, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchMeshSetEdgeDist, "Patch", "result", "anim Object, int32 edgeDist") \
    X(PatchMeshUseSoftSelections, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchMeshSetUseSoftSelections, "Patch", "result", "anim Object, int32 useSoftSelections") \
    X(PatchMeshAffectBackface, "Patch", "result", "anim Object, ptr:int32 OutValue") \
    X(PatchMeshSetAffectBackface, "Patch", "result", "anim Object, int32 affectBackface") \
    X(PatchMeshFalloff, "Patch", "result", "anim Object, ptr:float OutValue") \
    X(PatchMeshSetFalloff, "Patch", "result", "anim Object, float falloff") \
    X(PatchMeshPinch, "Patch", "result", "anim Object, ptr:float OutValue") \
    X(PatchMeshSetPinch, "Patch", "result", "anim Object, float pinch") \
    X(PatchMeshBubble, "Patch", "result", "anim Object, ptr:float OutValue") \
    X(PatchMeshSetBubble, "Patch", "result", "anim Object, float bubble") \
    X(PatchMeshInvalidateVertexWeights, "Patch", "result", "anim Object") \
    X(PatchMeshUpdateVertexDists, "Patch", "result", "anim Object") \
    X(PatchMeshUpdateEdgeDists, "Patch", "result", "anim Object") \
    X(PatchMeshUpdateVertexWeights, "Patch", "result", "anim Object") \
    X(MeshDeleteVertSet, "Mesh", "result", "anim Object, cptr:MaxMcpSpan set") \
    X(MeshBreakVerts, "Mesh", "result", "anim Object, cptr:MaxMcpSpan set") \
    X(MeshCloneFaces, "Mesh", "result", "anim Object, cptr:MaxMcpSpan fset") \
    X(PolyVertexSelect, "Poly", "result", "anim Object, cptr:MaxMcpSpan vsel") \
    X(PolyEdgeSelect, "Poly", "result", "anim Object, cptr:MaxMcpSpan esel") \
    X(PolyFaceSelect, "Poly", "result", "anim Object, cptr:MaxMcpSpan fsel") \
    X(PolyOptimizeSmoothingGroups, "Poly", "result", "anim Object, cptr:MaxMcpSpan optimizeFaces, ptr:int32 OutValue") \
    X(NodeSetUserPropString, "Node", "result", "node Node, cstr key, cstr string") \
    X(NodeSetUserPropInt, "Node", "result", "node Node, cstr key, int32 val") \
    X(NodeSetUserPropFloat, "Node", "result", "node Node, cstr key, float val") \
    X(NodeSetUserPropBool, "Node", "result", "node Node, cstr key, int32 b") \
    X(NodeUserPropExists, "Node", "result", "node Node, cstr key, ptr:int32 OutValue") \
    X(ScenePushPrompt, "Scene", "result", "cstr s") \
    X(SceneReplacePrompt, "Scene", "result", "cstr s") \
    X(SceneDisplayTempPrompt, "Scene", "result", "cstr s, int32 msec") \
    X(SceneProgressUpdate, "Scene", "result", "int32 pct, int32 showPct, cstr stepName") \
    X(SceneAppendSubObjectNamedSelSet, "Scene", "result", "cstr set") \
    X(SceneSetCurNamedSelSet, "Scene", "result", "cstr setName") \
    X(SceneLoadFromFile, "Scene", "result", "cstr name, int32 refresh, ptr:int32 OutValue") \
    X(SceneSaveToFile, "Scene", "result", "cstr fname, int32 clearNeedSaveFlag, int32 useNewFile, ptr:int32 OutValue") \
    X(SceneGetINodeByName, "Scene", "result", "cstr name, ptr:node OutValue") \
    X(SceneCanImportFile, "Scene", "result", "cstr filename, ptr:int32 OutValue") \
    X(SceneIsMaxFile, "Scene", "result", "cstr filename, ptr:int32 OutValue") \
    X(SceneIsInternetCachedFile, "Scene", "result", "cstr filename, ptr:int32 OutValue") \
    X(SceneCanImportBitmap, "Scene", "result", "cstr filename, ptr:int32 OutValue") \
    X(Scene7BringTrackViewWindowToTop, "Scene7", "result", "cstr tv_name, ptr:int32 OutValue") \
    X(Scene7AppendToCurFilePath, "Scene7", "result", "cstr toAppend, ptr:int32 OutValue") \
    X(Scene7LoadCUIConfig, "Scene7", "result", "cstr fileName") \
    X(SplineDeletePointConts, "Spline", "result", "node Node, cptr:MaxMcpSpan set") \
    X(MeshWeldCollinear, "Mesh", "result", "anim Object, ptr:MaxMcpSpan set") \
    X(MeshFindOpenEdges, "Mesh", "result", "anim Object, ptr:MaxMcpSpan edges") \
    X(PolySelectEdgeLoop, "Poly", "result", "anim Object, ptr:MaxMcpSpan edgeSel") \
    X(PolySelectEdgeRing, "Poly", "result", "anim Object, ptr:MaxMcpSpan edgeSel") \
    X(PolyGetVerticesByFlag, "Poly", "result", "anim Object, ptr:MaxMcpSpan vset, uint32 flags, uint32 fmask, ptr:int32 OutValue") \
    X(PolyGetEdgesByFlag, "Poly", "result", "anim Object, ptr:MaxMcpSpan eset, uint32 flags, uint32 fmask, ptr:int32 OutValue") \
    X(PolyGetFacesByFlag, "Poly", "result", "anim Object, ptr:MaxMcpSpan fset, uint32 flags, uint32 fmask, ptr:int32 OutValue") \
    X(NodeGetUserPropBuffer, "Node", "result", "node Node, ptr:MaxMcpStrOut buf") \
    X(NodeGetUserPropString, "Node", "result", "node Node, cstr key, ptr:MaxMcpStrOut string, ptr:int32 OutValue") \
    X(SceneMakeNameUnique, "Scene", "result", "ptr:MaxMcpStrOut name") \
    X(Scene7GetCurRefCoordSysName, "Scene7", "result", "ptr:MaxMcpStrOut name") \
    X(AnimGetClassName, "Anim", "result", "anim Anim, ptr:MaxMcpStrOut s, int32 localized") \
    X(AnimGetKeySelState, "Anim", "result", "anim Anim, ptr:MaxMcpSpan sel, cptr:MaxMcpInterval range, uint32 flags, ptr:int32 OutValue") \
    X(ObjectInitNodeName, "Object", "result", "anim Anim, ptr:MaxMcpStrOut s") \
    X(PatchActivateSubSelSet, "Patch", "result", "anim Object, ptr:MaxMcpStrOut setName") \
    X(PatchNewSetFromCurSel, "Patch", "result", "anim Object, ptr:MaxMcpStrOut setName") \
    X(PatchRemoveSubSelSet, "Patch", "result", "anim Object, ptr:MaxMcpStrOut setName") \
    X(PatchSetNamedSelSetName, "Patch", "result", "anim Object, int32 i, ptr:MaxMcpStrOut newName") \
    X(SplineInitNodeName, "Spline", "result", "node Node, ptr:MaxMcpStrOut s") \
    X(SplineActivateSubSelSet, "Spline", "result", "node Node, ptr:MaxMcpStrOut setName") \
    X(SplineNewSetFromCurSel, "Spline", "result", "node Node, ptr:MaxMcpStrOut setName") \
    X(SplineRemoveSubSelSet, "Spline", "result", "node Node, ptr:MaxMcpStrOut setName") \
    X(SplineSetNamedSelSetName, "Spline", "result", "node Node, int32 i, ptr:MaxMcpStrOut newName") \
    X(PatchMeshSelectEdgeRing, "Patch", "result", "anim Object, ptr:MaxMcpSpan eSel") \
    X(PatchMeshSelectEdgeLoop, "Patch", "result", "anim Object, ptr:MaxMcpSpan eSel") \
    X(SceneSetActiveViewport, "Scene", "result", "hwnd hwnd, ptr:int32 OutValue") \
    X(SceneGetMAXHWnd, "Scene", "result", "ptr:hwnd OutValue") \
    X(SceneMakeExtendedViewportActive, "Scene", "result", "hwnd hWnd") \
    X(SceneRegisterDlgWnd, "Scene", "result", "hwnd hDlg") \
    X(SceneUnRegisterDlgWnd, "Scene", "result", "hwnd hDlg, ptr:int32 OutValue") \
    X(SceneDeleteRollupPage, "Scene", "result", "hwnd hRollup") \
    X(SceneFileOpenMatLib, "Scene", "result", "hwnd hWnd") \
    X(SceneFileSaveMatLib, "Scene", "result", "hwnd hWnd") \
    X(SceneFileSaveAsMatLib, "Scene", "result", "hwnd hWnd") \
    X(SceneRAMPlayer, "Scene", "result", "hwnd hWndParent, cstr szChanA, cstr szChanB") \
    X(Scene7GetStatusPanelHWnd, "Scene7", "result", "ptr:hwnd OutValue") \
    X(Scene7SetListenerMiniHWnd, "Scene7", "result", "hwnd wnd") \
    X(Scene7GetListenerMiniHWnd, "Scene7", "result", "ptr:hwnd OutValue") \
    X(Scene7GetViewPanelHWnd, "Scene7", "result", "ptr:hwnd OutValue") \
    X(NodeGetVisibility, "Node", "result", "node Node, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(NodeGetLocalVisibility, "Node", "result", "node Node, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(PatchGetVertColor, "Patch", "result", "anim Object, int32 mp, ptr:int32 differs, ptr:MaxMcpColor OutValue") \
    X(PatchGetPatchColor, "Patch", "result", "anim Object, int32 mp, ptr:int32 differs, ptr:MaxMcpColor OutValue") \
    X(MeshBuildTransformedBoundingBox, "Mesh", "result", "anim Object, cptr:MaxMcpMatrix3 transformMat") \
    X(MeshApplyUVWMap, "Mesh", "result", "anim Object, int32 type, float utile, float vtile, float wtile, int32 uflip, int32 vflip, int32 wflip, int32 cap, cptr:MaxMcpMatrix3 tm, int32 channel") \
    X(PolyGetVertexSpace, "Poly", "result", "anim Object, int32 vrt, ptr:MaxMcpMatrix3 tm") \
    X(NodeGetNodeTM, "Node", "result", "node Node, int32 t, ptr:MaxMcpInterval valid, ptr:MaxMcpMatrix3 OutValue") \
    X(NodeSetNodeTM, "Node", "result", "node Node, int32 t, cptr:MaxMcpMatrix3 tm") \
    X(NodeGetObjectTM, "Node", "result", "node Node, int32 time, ptr:MaxMcpInterval valid, ptr:MaxMcpMatrix3 OutValue") \
    X(NodeGetObjTMBeforeWSM, "Node", "result", "node Node, int32 time, ptr:MaxMcpInterval valid, ptr:MaxMcpMatrix3 OutValue") \
    X(NodeGetObjTMAfterWSM, "Node", "result", "node Node, int32 time, ptr:MaxMcpInterval valid, ptr:MaxMcpMatrix3 OutValue") \
    X(NodeGetParentTM, "Node", "result", "node Node, int32 t, ptr:MaxMcpMatrix3 OutValue") \
    X(NodeGetTargetTM, "Node", "result", "node Node, int32 t, ptr:MaxMcpMatrix3 m, ptr:int32 OutValue") \
    X(NodeMove, "Node", "result", "node Node, int32 t, cptr:MaxMcpMatrix3 tmAxis, cptr:MaxMcpPoint3 val, int32 localOrigin, int32 affectKids, int32 pivMode, int32 ignoreLocks") \
    X(NodeRotate, "Node", "result", "node Node, int32 t, cptr:MaxMcpMatrix3 tmAxis, cptr:MaxMcpAngAxis val, int32 localOrigin, int32 affectKids, int32 pivMode, int32 ignoreLocks") \
    X(NodeScale, "Node", "result", "node Node, int32 t, cptr:MaxMcpMatrix3 tmAxis, cptr:MaxMcpPoint3 val, int32 localOrigin, int32 affectKids, int32 pivMode, int32 ignoreLocks") \
    X(NodeGetStretchTM, "Node", "result", "node Node, int32 t, ptr:MaxMcpInterval valid, ptr:MaxMcpMatrix3 OutValue") \
    X(ControllerSubMove, "Controller", "result", "anim Controller, int32 t, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, ptr:MaxMcpPoint3 val, int32 localOrigin") \
    X(ControllerSubRotate, "Controller", "result", "anim Controller, int32 t, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, ptr:MaxMcpQuat val, int32 localOrigin") \
    X(ControllerSubScale, "Controller", "result", "anim Controller, int32 t, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, ptr:MaxMcpPoint3 val, int32 localOrigin") \
    X(SceneNonMouseCreate, "Scene", "result", "cptr:MaxMcpMatrix3 tm, ptr:anim OutValue") \
    X(SceneNonMouseCreateFinish, "Scene", "result", "cptr:MaxMcpMatrix3 tm") \
    X(ObjectApplyUVWMap, "Object", "result", "anim Anim, int32 type, float utile, float vtile, float wtile, int32 uflip, int32 vflip, int32 wflip, int32 cap, cptr:MaxMcpMatrix3 tm, int32 channel") \
    X(ObjectGetContainedShapeMatrix, "Object", "result", "anim Anim, int32 t, int32 index, ptr:MaxMcpMatrix3 mat") \
    X(PatchApplyUVWMap, "Patch", "result", "anim Object, int32 type, float utile, float vtile, float wtile, int32 uflip, int32 vflip, int32 wflip, int32 cap, cptr:MaxMcpMatrix3 tm, int32 channel") \
    X(PatchMove, "Patch", "result", "anim Object, int32 t, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, ptr:MaxMcpPoint3 val, int32 localOrigin") \
    X(PatchRotate, "Patch", "result", "anim Object, int32 t, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, ptr:MaxMcpQuat val, int32 localOrigin") \
    X(PatchScale, "Patch", "result", "anim Object, int32 t, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, ptr:MaxMcpPoint3 val, int32 localOrigin") \
    X(SplineMove, "Spline", "result", "node Node, int32 t, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, ptr:MaxMcpPoint3 val, int32 localOrigin") \
    X(SplineRotate, "Spline", "result", "node Node, int32 t, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, ptr:MaxMcpQuat val, int32 localOrigin") \
    X(SplineScale, "Spline", "result", "node Node, int32 t, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, ptr:MaxMcpPoint3 val, int32 localOrigin") \
    X(PatchMeshApplyUVWMap, "Patch", "result", "anim Object, int32 type, float utile, float vtile, float wtile, int32 uflip, int32 vflip, int32 wflip, int32 cap, cptr:MaxMcpMatrix3 tm, int32 channel") \
    X(PatchMeshTransform, "Patch", "result", "anim Object, ptr:MaxMcpMatrix3 tm") \
    X(EPolyInvalidateSoftSelectionCache, "EPoly", "result", "anim Object") \
    X(EPolyInvalidateDistanceCache, "EPoly", "result", "anim Object") \
    X(EPolyRefreshScreen, "EPoly", "result", "anim Object") \
    X(EPolyEditing, "EPoly", "result", "anim Object, ptr:int32 OutValue") \
    X(EPolyGetEPolySelLevel, "EPoly", "result", "anim Object, ptr:int32 OutValue") \
    X(EPolyGetMNSelLevel, "EPoly", "result", "anim Object, ptr:int32 OutValue") \
    X(EPolySetEPolySelLevel, "EPoly", "result", "anim Object, int32 level") \
    X(EPolyEpGetVerticesByFlag, "EPoly", "result", "anim Object, ptr:MaxMcpSpan vset, uint32 flags, uint32 fmask, ptr:int32 OutValue") \
    X(EPolyEpGetEdgesByFlag, "EPoly", "result", "anim Object, ptr:MaxMcpSpan eset, uint32 flags, uint32 fmask, ptr:int32 OutValue") \
    X(EPolyEpGetFacesByFlag, "EPoly", "result", "anim Object, ptr:MaxMcpSpan fset, uint32 flags, uint32 fmask, ptr:int32 OutValue") \
    X(EPolyEpSetVertexFlags, "EPoly", "result", "anim Object, cptr:MaxMcpSpan vset, uint32 flags, uint32 fmask, int32 undoable") \
    X(EPolyEpSetEdgeFlags, "EPoly", "result", "anim Object, cptr:MaxMcpSpan eset, uint32 flags, uint32 fmask, int32 undoable") \
    X(EPolyEpSetFaceFlags, "EPoly", "result", "anim Object, cptr:MaxMcpSpan fset, uint32 flags, uint32 fmask, int32 undoable") \
    X(EPolyEpActionButtonOp, "EPoly", "result", "anim Object, int32 opcode") \
    X(EPolyEpActionToggleCommandMode, "EPoly", "result", "anim Object, int32 mode") \
    X(EPolyEpActionEnterPickMode, "EPoly", "result", "anim Object, int32 mode") \
    X(EPolyEpActionExitCommandModes, "EPoly", "result", "anim Object") \
    X(EPolyEpActionGetCommandMode, "EPoly", "result", "anim Object, ptr:int32 OutValue") \
    X(EPolyEpActionGetPickMode, "EPoly", "result", "anim Object, ptr:int32 OutValue") \
    X(EPolyMoveSelection, "EPoly", "result", "anim Object, int32 level, int32 t, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, ptr:MaxMcpPoint3 val, int32 localOrigin") \
    X(EPolyRotateSelection, "EPoly", "result", "anim Object, int32 level, int32 t, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, ptr:MaxMcpQuat val, int32 localOrigin") \
    X(EPolyScaleSelection, "EPoly", "result", "anim Object, int32 level, int32 t, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, ptr:MaxMcpPoint3 val, int32 localOrigin") \
    X(EPolyEpResetSlicePlane, "EPoly", "result", "anim Object") \
    X(EPolyEpSetSlicePlane, "EPoly", "result", "anim Object, ptr:MaxMcpPoint3 planeNormal, ptr:MaxMcpPoint3 planeCenter, float planeSize") \
    X(EPolySetVertexColor, "EPoly", "result", "anim Object, cptr:MaxMcpColor clr, int32 mp, uint32 flag, int32 t") \
    X(EPolySetFaceColor, "EPoly", "result", "anim Object, cptr:MaxMcpColor clr, int32 mp, uint32 flag, int32 t") \
    X(EPolySetVertexDataValue, "EPoly", "result", "anim Object, int32 channel, float w, uint32 vertexFlags, int32 t") \
    X(EPolySetEdgeDataValue, "EPoly", "result", "anim Object, int32 channel, float w, uint32 edgeFlags, int32 t") \
    X(EPolyResetVertexData, "EPoly", "result", "anim Object, int32 channel") \
    X(EPolyResetEdgeData, "EPoly", "result", "anim Object, int32 channel") \
    X(EPolyBeginPerDataModify, "EPoly", "result", "anim Object, int32 mnSelLevel, int32 channel") \
    X(EPolyInPerDataModify, "EPoly", "result", "anim Object, ptr:int32 OutValue") \
    X(EPolyEndPerDataModify, "EPoly", "result", "anim Object, int32 success") \
    X(EPolyBeginVertexColorModify, "EPoly", "result", "anim Object, int32 mp, uint32 flag") \
    X(EPolyInVertexColorModify, "EPoly", "result", "anim Object, ptr:int32 OutValue") \
    X(EPolyEndVertexColorModify, "EPoly", "result", "anim Object, int32 success") \
    X(EPolySetMatIndex, "EPoly", "result", "anim Object, int32 index, uint32 flag") \
    X(EPolySetSmoothBits, "EPoly", "result", "anim Object, uint32 bits, uint32 bitmask, uint32 flag") \
    X(EPolySetDisplacementParams, "EPoly", "result", "anim Object") \
    X(EPolyUpdateDisplacementParams, "EPoly", "result", "anim Object") \
    X(EPolyUseDisplacementPreset, "EPoly", "result", "anim Object, int32 presetNumber") \
    X(EPolyEpfnBeginExtrude, "EPoly", "result", "anim Object, int32 msl, uint32 flag, int32 t") \
    X(EPolyEpfnEndExtrude, "EPoly", "result", "anim Object, int32 accept, int32 t") \
    X(EPolyEpfnDragExtrude, "EPoly", "result", "anim Object, float amount, int32 t") \
    X(EPolyEpfnBeginBevel, "EPoly", "result", "anim Object, int32 msl, uint32 flag, int32 doExtrude, int32 t") \
    X(EPolyEpfnEndBevel, "EPoly", "result", "anim Object, int32 accept, int32 t") \
    X(EPolyEpfnDragBevel, "EPoly", "result", "anim Object, float outline, float height, int32 t") \
    X(EPolyEpfnBeginChamfer, "EPoly", "result", "anim Object, int32 msl, int32 t") \
    X(EPolyEpfnEndChamfer, "EPoly", "result", "anim Object, int32 accept, int32 t") \
    X(EPolyEpfnDragChamfer, "EPoly", "result", "anim Object, float amount, int32 t") \
    X(EPolyEpfnHide, "EPoly", "result", "anim Object, int32 msl, uint32 flags, ptr:int32 OutValue") \
    X(EPolyEpfnUnhideAll, "EPoly", "result", "anim Object, int32 msl, ptr:int32 OutValue") \
    X(EPolyEpfnNamedSelectionCopy, "EPoly", "result", "anim Object, cstr setName") \
    X(EPolyEpfnNamedSelectionPaste, "EPoly", "result", "anim Object, int32 useDlgToRename") \
    X(EPolyEpfnCreateVertex, "EPoly", "result", "anim Object, cptr:MaxMcpPoint3 pt, int32 pt_local, int32 select, ptr:int32 OutValue") \
    X(EPolyEpfnCreateEdge, "EPoly", "result", "anim Object, int32 v1, int32 v2, int32 select, ptr:int32 OutValue") \
    X(EPolyEpfnCapHoles, "EPoly", "result", "anim Object, int32 msl, uint32 targetFlags, ptr:int32 OutValue") \
    X(EPolyEpfnDelete, "EPoly", "result", "anim Object, int32 msl, uint32 delFlag, int32 delIsoVerts, ptr:int32 OutValue") \
    X(EPolyEpfnDetachToElement, "EPoly", "result", "anim Object, int32 msl, uint32 flag, int32 keepOriginal, ptr:int32 OutValue") \
    X(EPolyEpfnSplitEdges, "EPoly", "result", "anim Object, uint32 flag, ptr:int32 OutValue") \
    X(EPolyEpfnBreakVerts, "EPoly", "result", "anim Object, uint32 flag, ptr:int32 OutValue") \
    X(EPolyEpfnCollapse, "EPoly", "result", "anim Object, int32 msl, uint32 flag, ptr:int32 OutValue") \
    X(EPolyEpfnExtrudeFaces, "EPoly", "result", "anim Object, float amount, uint32 flag, int32 t") \
    X(EPolyEpfnBevelFaces, "EPoly", "result", "anim Object, float height, float outline, uint32 flag, int32 t") \
    X(EPolyEpfnChamferVertices, "EPoly", "result", "anim Object, float amount, int32 t") \
    X(EPolyEpfnChamferEdges, "EPoly", "result", "anim Object, float amount, int32 t") \
    X(EPolyEpfnInSlicePlaneMode, "EPoly", "result", "anim Object, ptr:int32 OutValue") \
    X(EPolyEpfnWeldVerts, "EPoly", "result", "anim Object, int32 vert1, int32 vert2, cptr:MaxMcpPoint3 destination, ptr:int32 OutValue") \
    X(EPolyEpfnWeldEdges, "EPoly", "result", "anim Object, int32 edge1, int32 edge2, ptr:int32 OutValue") \
    X(EPolyEpfnWeldFlaggedVerts, "EPoly", "result", "anim Object, uint32 flag, ptr:int32 OutValue") \
    X(EPolyEpfnWeldFlaggedEdges, "EPoly", "result", "anim Object, uint32 flag, ptr:int32 OutValue") \
    X(EPolyEpfnMakePlanar, "EPoly", "result", "anim Object, int32 msl, uint32 flag, int32 t, ptr:int32 OutValue") \
    X(EPolyEpfnMoveToPlane, "EPoly", "result", "anim Object, cptr:MaxMcpPoint3 planeNormal, float planeOffset, int32 msl, uint32 flag, int32 t, ptr:int32 OutValue") \
    X(EPolyEpfnDeleteIsoVerts, "EPoly", "result", "anim Object, ptr:int32 OutValue") \
    X(EPolyEpfnForceSubdivision, "EPoly", "result", "anim Object") \
    X(EPolyEpfnSelectVertByColor, "EPoly", "result", "anim Object, int32 add, int32 sub, int32 mp, int32 t") \
    X(EPolyEpfnSetDiagonal, "EPoly", "result", "anim Object, int32 face, int32 corner1, int32 corner2") \
    X(EPolyEpfnRetriangulate, "EPoly", "result", "anim Object, uint32 flag, ptr:int32 OutValue") \
    X(EPolyEpfnFlipNormals, "EPoly", "result", "anim Object, uint32 flag, ptr:int32 OutValue") \
    X(EPolyEpfnSelectByMat, "EPoly", "result", "anim Object, int32 index, int32 clear, int32 t") \
    X(EPolyEpfnSelectBySmoothGroup, "EPoly", "result", "anim Object, uint32 bits, int32 clear, int32 t") \
    X(EPolyEpfnAutoSmooth, "EPoly", "result", "anim Object, int32 t") \
    X(EPolyCollapseDeadStructs, "EPoly", "result", "anim Object") \
    X(EPolyEpfnChamferVerticesOpen, "EPoly", "result", "anim Object, float in_amount, int32 in_open, int32 in_time") \
    X(EPolyEpfnChamferEdgesOpen, "EPoly", "result", "anim Object, float in_amount, int32 in_open, int32 in_time") \
    X(EPolyEpfnSetRingShift, "EPoly", "result", "anim Object, int32 in_newPos, int32 in_moveOnly, int32 in_add") \
    X(EPolyEpfnSetLoopShift, "EPoly", "result", "anim Object, int32 in_newPos, int32 in_moveOnly, int32 in_add") \
    X(EPolyEpfnConvertSelectionToBorder, "EPoly", "result", "anim Object, int32 in_epSelLevelFrom, int32 in_epSelLevelTo, ptr:int32 OutValue") \
    X(EPolyEpfnPaintDeformCommit, "EPoly", "result", "anim Object") \
    X(EPolyEpfnPaintDeformCancel, "EPoly", "result", "anim Object") \
    X(EPolyCloseSmGrpFloater, "EPoly", "result", "anim Object") \
    X(EPolyCloseMatIDFloater, "EPoly", "result", "anim Object") \
    X(EPolyMatIDFloaterHWND, "EPoly", "result", "anim Object, ptr:hwnd OutValue") \
    X(EPolySmGrpFloaterHWND, "EPoly", "result", "anim Object, ptr:hwnd OutValue") \
    X(EPolySmGrpFloater, "EPoly", "result", "anim Object") \
    X(EPolyMatIDFloater, "EPoly", "result", "anim Object") \
    X(EPolyMatIDFloaterVisible, "EPoly", "result", "anim Object, ptr:int32 OutValue") \
    X(EPolySmGrpFloaterVisible, "EPoly", "result", "anim Object, ptr:int32 OutValue") \
    X(UnwrapFnPlanarMap, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnSave, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnLoad, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnReset, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnEdit, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnSetMapChannel, "Unwrap", "result", "anim Mod, int32 channel") \
    X(UnwrapFnGetMapChannel, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnSetProjectionType, "Unwrap", "result", "anim Mod, int32 proj") \
    X(UnwrapFnGetProjectionType, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnSetVC, "Unwrap", "result", "anim Mod, int32 vc") \
    X(UnwrapFnGetVC, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnMove, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnMoveH, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnMoveV, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnRotate, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnScale, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnScaleH, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnScaleV, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnMirrorH, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnMirrorV, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnExpandSelection, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnContractSelection, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnSetFalloffType, "Unwrap", "result", "anim Mod, int32 falloff") \
    X(UnwrapFnGetFalloffType, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnSetFalloffSpace, "Unwrap", "result", "anim Mod, int32 space") \
    X(UnwrapFnGetFalloffSpace, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnSetFalloffDist, "Unwrap", "result", "anim Mod, float dist") \
    X(UnwrapFnGetFalloffDist, "Unwrap", "result", "anim Mod, ptr:float OutValue") \
    X(UnwrapFnBreakSelected, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnWeld, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnWeldSelected, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnUpdatemap, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnDisplaymap, "Unwrap", "result", "anim Mod, int32 update") \
    X(UnwrapFnIsMapDisplayed, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnSetUVSpace, "Unwrap", "result", "anim Mod, int32 space") \
    X(UnwrapFnGetUVSpace, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnOptions, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnLock, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnHide, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnUnhide, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnFreeze, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnThaw, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnFilterSelected, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnPan, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnZoom, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnZoomRegion, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnFit, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnFitSelected, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnSnapToggle, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnGetCurrentMap, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnSetCurrentMap, "Unwrap", "result", "anim Mod, int32 map") \
    X(UnwrapFnNumberMaps, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnSetLineColor, "Unwrap", "result", "anim Mod, cptr:MaxMcpPoint3 color") \
    X(UnwrapFnSetSelColor, "Unwrap", "result", "anim Mod, cptr:MaxMcpPoint3 color") \
    X(UnwrapFnSetRenderWidth, "Unwrap", "result", "anim Mod, int32 dist") \
    X(UnwrapFnGetRenderWidth, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnSetRenderHeight, "Unwrap", "result", "anim Mod, int32 dist") \
    X(UnwrapFnGetRenderHeight, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnSetWeldThreshold, "Unwrap", "result", "anim Mod, float dist") \
    X(UnwrapFnGetWeldThresold, "Unwrap", "result", "anim Mod, ptr:float OutValue") \
    X(UnwrapFnSetUseBitmapRes, "Unwrap", "result", "anim Mod, int32 useBitmapRes") \
    X(UnwrapFnGetUseBitmapRes, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnGetConstantUpdate, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnSetConstantUpdate, "Unwrap", "result", "anim Mod, int32 constantUpdates") \
    X(UnwrapFnGetShowSelectedVertices, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnSetShowSelectedVertices, "Unwrap", "result", "anim Mod, int32 show") \
    X(UnwrapFnGetPixelCenterSnape, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnSetPixelCenterSnape, "Unwrap", "result", "anim Mod, int32 midPixel") \
    X(UnwrapFnGetMatID, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnSetMatID, "Unwrap", "result", "anim Mod, int32 matid") \
    X(UnwrapFnNumberMatIDs, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnIsVertexSelected, "Unwrap", "result", "anim Mod, int32 index, ptr:int32 OutValue") \
    X(UnwrapFnMoveSelectedVertices, "Unwrap", "result", "anim Mod, cptr:MaxMcpPoint3 offset") \
    X(UnwrapFnRotateSelectedVertices, "Unwrap", "result", "anim Mod, float angle") \
    X(UnwrapFnScaleSelectedVertices, "Unwrap", "result", "anim Mod, float scale, int32 dir") \
    X(UnwrapFnNumberVertices, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnMoveX, "Unwrap", "result", "anim Mod, float p") \
    X(UnwrapFnMoveY, "Unwrap", "result", "anim Mod, float p") \
    X(UnwrapFnMoveZ, "Unwrap", "result", "anim Mod, float p") \
    X(UnwrapFnIsPolygonSelected, "Unwrap", "result", "anim Mod, int32 index, ptr:int32 OutValue") \
    X(UnwrapFnNumberPolygons, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnDetachEdgeVerts, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnFlipH, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnFlipV, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnGetLockAspect, "Unwrap", "result", "anim Mod, ptr:int32 OutValue") \
    X(UnwrapFnSetLockAspect, "Unwrap", "result", "anim Mod, int32 a") \
    X(UnwrapFnGetMapScale, "Unwrap", "result", "anim Mod, ptr:float OutValue") \
    X(UnwrapFnSetMapScale, "Unwrap", "result", "anim Mod, float sc") \
    X(UnwrapFnGetSelectionFromFace, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnForceUpdate, "Unwrap", "result", "anim Mod, int32 update") \
    X(UnwrapFnZoomToGizmo, "Unwrap", "result", "anim Mod, int32 all") \
    X(UnwrapFnSetVertexPosition, "Unwrap", "result", "anim Mod, int32 t, int32 index, cptr:MaxMcpPoint3 pos") \
    X(UnwrapFnMarkAsDead, "Unwrap", "result", "anim Mod, int32 index") \
    X(UnwrapFnNumberPointsInFace, "Unwrap", "result", "anim Mod, int32 index, ptr:int32 OutValue") \
    X(UnwrapFnGetVertexIndexFromFace, "Unwrap", "result", "anim Mod, int32 index, int32 vertexIndex, ptr:int32 OutValue") \
    X(UnwrapFnGetHandleIndexFromFace, "Unwrap", "result", "anim Mod, int32 index, int32 vertexIndex, ptr:int32 OutValue") \
    X(UnwrapFnGetInteriorIndexFromFace, "Unwrap", "result", "anim Mod, int32 index, int32 vertexIndex, ptr:int32 OutValue") \
    X(UnwrapFnGetVertexGIndexFromFace, "Unwrap", "result", "anim Mod, int32 index, int32 vertexIndex, ptr:int32 OutValue") \
    X(UnwrapFnGetHandleGIndexFromFace, "Unwrap", "result", "anim Mod, int32 index, int32 vertexIndex, ptr:int32 OutValue") \
    X(UnwrapFnGetInteriorGIndexFromFace, "Unwrap", "result", "anim Mod, int32 index, int32 vertexIndex, ptr:int32 OutValue") \
    X(UnwrapFnAddPoint, "Unwrap", "result", "anim Mod, cptr:MaxMcpPoint3 pos, int32 fIndex, int32 ithV, int32 sel") \
    X(UnwrapFnAddHandle, "Unwrap", "result", "anim Mod, cptr:MaxMcpPoint3 pos, int32 fIndex, int32 ithV, int32 sel") \
    X(UnwrapFnAddInterior, "Unwrap", "result", "anim Mod, cptr:MaxMcpPoint3 pos, int32 fIndex, int32 ithV, int32 sel") \
    X(UnwrapFnSetFaceVertexIndex, "Unwrap", "result", "anim Mod, int32 fIndex, int32 ithV, int32 vIndex") \
    X(UnwrapFnSetFaceHandleIndex, "Unwrap", "result", "anim Mod, int32 fIndex, int32 ithV, int32 vIndex") \
    X(UnwrapFnSetFaceInteriorIndex, "Unwrap", "result", "anim Mod, int32 fIndex, int32 ithV, int32 vIndex") \
    X(UnwrapFnUpdateViews, "Unwrap", "result", "anim Mod") \
    X(UnwrapFnGetFaceSelFromStack, "Unwrap", "result", "anim Mod") \
    X(Unwrap2FnSelectFacesByNormal, "Unwrap2", "result", "anim Mod, cptr:MaxMcpPoint3 Normal, float angleThreshold, int32 update") \
    X(Unwrap2FnSelectClusterByNormal, "Unwrap2", "result", "anim Mod, float angleThreshold, int32 seedIndex, int32 relative, int32 update") \
    X(Unwrap2FnNormalMapNoParams, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnNormalMapDialog, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnUnfoldSelectedPolygons, "Unwrap2", "result", "anim Mod, int32 unfoldMethod, int32 normalize") \
    X(Unwrap2FnUnfoldSelectedPolygonsDialog, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnUnfoldSelectedPolygonsNoParams, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnSetSeedFace, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnShowVertexConnectionList, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnCopy, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnPaste, "Unwrap2", "result", "anim Mod, int32 rotate") \
    X(Unwrap2FnPasteInstance, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnSetDebugLevel, "Unwrap2", "result", "anim Mod, int32 level") \
    X(Unwrap2FnStitchVerts, "Unwrap2", "result", "anim Mod, int32 bAlign, float fBias") \
    X(Unwrap2FnStitchVertsNoParams, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnStitchVertsDialog, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnSelectElement, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnFlattenMapDialog, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnFlattenMapNoParams, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnSetTile, "Unwrap2", "result", "anim Mod, int32 tile") \
    X(Unwrap2FnSetTileLimit, "Unwrap2", "result", "anim Mod, int32 lmit") \
    X(Unwrap2FnSetTileContrast, "Unwrap2", "result", "anim Mod, float contrast") \
    X(Unwrap2FnSetShowMap, "Unwrap2", "result", "anim Mod, int32 smap") \
    X(Unwrap2FnSetLimitSoftSel, "Unwrap2", "result", "anim Mod, int32 limit") \
    X(Unwrap2FnSetLimitSoftSelRange, "Unwrap2", "result", "anim Mod, int32 range") \
    X(Unwrap2FnSetVertexWeight, "Unwrap2", "result", "anim Mod, int32 index, float weight") \
    X(Unwrap2FnModifyWeight, "Unwrap2", "result", "anim Mod, int32 index, int32 modified") \
    X(Unwrap2FnSetGeomElemMode, "Unwrap2", "result", "anim Mod, int32 elem") \
    X(Unwrap2FnSetGeomPlanarMode, "Unwrap2", "result", "anim Mod, int32 planar") \
    X(Unwrap2FnSetGeomPlanarModeThreshold, "Unwrap2", "result", "anim Mod, float threshold") \
    X(Unwrap2FnSetBackFaceCull, "Unwrap2", "result", "anim Mod, int32 backFaceCull") \
    X(Unwrap2FnSetOldSelMethod, "Unwrap2", "result", "anim Mod, int32 oldSelMethod") \
    X(Unwrap2FnSetSelectionMatID, "Unwrap2", "result", "anim Mod, int32 matID") \
    X(Unwrap2FnSelectByMatID, "Unwrap2", "result", "anim Mod, int32 matID") \
    X(Unwrap2FnSelectBySG, "Unwrap2", "result", "anim Mod, int32 sg") \
    X(Unwrap2FnSetTVElementMode, "Unwrap2", "result", "anim Mod, int32 mode") \
    X(Unwrap2FnGeomExpandFaceSel, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnGeomContractFaceSel, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnSetAlwaysEdit, "Unwrap2", "result", "anim Mod, int32 always") \
    X(Unwrap2FnSetShowConnection, "Unwrap2", "result", "anim Mod, int32 show") \
    X(Unwrap2FnSetFilteredSelected, "Unwrap2", "result", "anim Mod, int32 filter") \
    X(Unwrap2FnSetPixelCornerSnap, "Unwrap2", "result", "anim Mod, int32 snap") \
    X(Unwrap2FnSetLock, "Unwrap2", "result", "anim Mod, int32 snap") \
    X(Unwrap2FnPackNoParams, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnPackDialog, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnSetTVSubMode, "Unwrap2", "result", "anim Mod, int32 mode") \
    X(Unwrap2FnSetFillMode, "Unwrap2", "result", "anim Mod, int32 mode") \
    X(Unwrap2FnMoveSelected, "Unwrap2", "result", "anim Mod, cptr:MaxMcpPoint3 offset") \
    X(Unwrap2FnRotateSelected, "Unwrap2", "result", "anim Mod, float angle") \
    X(Unwrap2FnScaleSelected, "Unwrap2", "result", "anim Mod, float scale, int32 dir") \
    X(Unwrap2FnSetDisplayOpenEdges, "Unwrap2", "result", "anim Mod, int32 openEdgeDisplay") \
    X(Unwrap2FnSetOpenEdgeColor, "Unwrap2", "result", "anim Mod, cptr:MaxMcpPoint3 color") \
    X(Unwrap2FnSetUVEdgeMode, "Unwrap2", "result", "anim Mod, int32 uvmode") \
    X(Unwrap2FnSetOpenEdgeMode, "Unwrap2", "result", "anim Mod, int32 uvmode") \
    X(Unwrap2FnUVEdgeSelect, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnOpenEdgeSelect, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnVertToEdgeSelect, "Unwrap2", "result", "anim Mod, int32 bPartialSelect") \
    X(Unwrap2FnVertToFaceSelect, "Unwrap2", "result", "anim Mod, int32 bPartialSelect") \
    X(Unwrap2FnEdgeToVertSelect, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnEdgeToFaceSelect, "Unwrap2", "result", "anim Mod, int32 bPartialSelect") \
    X(Unwrap2FnFaceToVertSelect, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnFaceToEdgeSelect, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnSetDisplayHiddenEdges, "Unwrap2", "result", "anim Mod, int32 hiddenEdgeDisplay") \
    X(Unwrap2FnSetHandleColor, "Unwrap2", "result", "anim Mod, cptr:MaxMcpPoint3 color") \
    X(Unwrap2FnSetFreeFormMode, "Unwrap2", "result", "anim Mod, int32 freeFormMode") \
    X(Unwrap2FnSetFreeFormColor, "Unwrap2", "result", "anim Mod, cptr:MaxMcpPoint3 color") \
    X(Unwrap2FnScaleSelectedXY, "Unwrap2", "result", "anim Mod, float scaleX, float scaleY, cptr:MaxMcpPoint3 axis") \
    X(Unwrap2FnSnapPivot, "Unwrap2", "result", "anim Mod, int32 pos") \
    X(Unwrap2FnSetPivotOffset, "Unwrap2", "result", "anim Mod, cptr:MaxMcpPoint3 color") \
    X(Unwrap2FnSketchNoParams, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnSketchDialog, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnSketchReverse, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnSetHitSize, "Unwrap2", "result", "anim Mod, int32 size, int32 applyUIScaling") \
    X(Unwrap2FnSetResetPivotOnSel, "Unwrap2", "result", "anim Mod, int32 reset") \
    X(Unwrap2FnSetPolyMode, "Unwrap2", "result", "anim Mod, int32 pmode") \
    X(Unwrap2FnPolySelect, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnSetAllowSelectionInsideGizmo, "Unwrap2", "result", "anim Mod, int32 select") \
    X(Unwrap2FnSetAsDefaults, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnLoadDefaults, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnSetSharedColor, "Unwrap2", "result", "anim Mod, cptr:MaxMcpPoint3 color") \
    X(Unwrap2FnSetShowShared, "Unwrap2", "result", "anim Mod, int32 select") \
    X(Unwrap2FnSetSyncSelectionMode, "Unwrap2", "result", "anim Mod, int32 sync") \
    X(Unwrap2FnSyncTVSelection, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnSyncGeomSelection, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnSetBackgroundColor, "Unwrap2", "result", "anim Mod, cptr:MaxMcpPoint3 color") \
    X(Unwrap2FnUpdateMenuBar, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnSetBrightCenterTile, "Unwrap2", "result", "anim Mod, int32 bright") \
    X(Unwrap2FnSetBlendToBack, "Unwrap2", "result", "anim Mod, int32 blend") \
    X(Unwrap2FnSetPaintMode, "Unwrap2", "result", "anim Mod, int32 paint") \
    X(Unwrap2FnSetPaintSize, "Unwrap2", "result", "anim Mod, int32 size, int32 applyUIScaling") \
    X(Unwrap2FnIncPaintSize, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnDecPaintSize, "Unwrap2", "result", "anim Mod") \
    X(Unwrap2FnSetTickSize, "Unwrap2", "result", "anim Mod, int32 size, int32 applyUIScaling") \
    X(Unwrap2FnSetGridSize, "Unwrap2", "result", "anim Mod, float size") \
    X(Unwrap2FnSetSnapToggle, "Unwrap2", "result", "anim Mod, int32 snap") \
    X(Unwrap2FnSetGridVisible, "Unwrap2", "result", "anim Mod, int32 visible") \
    X(Unwrap2FnSetGridColor, "Unwrap2", "result", "anim Mod, cptr:MaxMcpPoint3 color") \
    X(Unwrap2FnSetSnapStrength, "Unwrap2", "result", "anim Mod, float size") \
    X(Unwrap2FnSetAutoMap, "Unwrap2", "result", "anim Mod, int32 autoMap") \
    X(Unwrap2FnSetFlattenAngle, "Unwrap2", "result", "anim Mod, float angle") \
    X(Unwrap2FnSetFlattenSpacing, "Unwrap2", "result", "anim Mod, float spacing") \
    X(Unwrap2FnSetFlattenNormalize, "Unwrap2", "result", "anim Mod, int32 normalize") \
    X(Unwrap2FnSetFlattenRotate, "Unwrap2", "result", "anim Mod, int32 rotate") \
    X(Unwrap2FnSetFlattenFillHoles, "Unwrap2", "result", "anim Mod, int32 fillHoles") \
    X(Unwrap2FnSetPreventFlattening, "Unwrap2", "result", "anim Mod, int32 preventFlattening") \
    X(Unwrap2FnSetEnableSoftSelection, "Unwrap2", "result", "anim Mod, int32 enable") \
    X(Unwrap2FnSetApplyToWholeObject, "Unwrap2", "result", "anim Mod, int32 wholeObject") \
    X(Unwrap2FnSetVertexPosition2, "Unwrap2", "result", "anim Mod, int32 t, int32 index, cptr:MaxMcpPoint3 pos, int32 hold, int32 update") \
    X(Unwrap2FnRelax, "Unwrap2", "result", "anim Mod, int32 iteration, float str, int32 lockEdges, int32 matchArea") \
    X(Unwrap2FnGetCheckerTiling, "Unwrap2", "result", "anim Mod, ptr:float OutValue") \
    X(Unwrap2FnSetCheckerTiling, "Unwrap2", "result", "anim Mod, float tiling") \
    X(ShapeObjGetThickness, "Shape", "result", "node Node, int32 t, ptr:MaxMcpInterval ivalid, ptr:float OutValue") \
    X(ShapeObjGetSides, "Shape", "result", "node Node, int32 t, ptr:MaxMcpInterval ivalid, ptr:int32 OutValue") \
    X(ShapeObjGetAngle, "Shape", "result", "node Node, int32 t, ptr:MaxMcpInterval ivalid, ptr:float OutValue") \
    X(ShapeObjGetViewportThickness, "Shape", "result", "node Node, ptr:float OutValue") \
    X(ShapeObjGetViewportSides, "Shape", "result", "node Node, ptr:int32 OutValue") \
    X(ShapeObjGetViewportAngle, "Shape", "result", "node Node, ptr:float OutValue") \
    X(ShapeObjGetGenUVs, "Shape", "result", "node Node, ptr:int32 OutValue") \
    X(ShapeObjGetDispRenderMesh, "Shape", "result", "node Node, ptr:int32 OutValue") \
    X(ShapeObjGetUseViewport, "Shape", "result", "node Node, ptr:int32 OutValue") \
    X(ShapeObjGetViewportOrRenderer, "Shape", "result", "node Node, ptr:int32 OutValue") \
    X(ShapeObjSetThickness, "Shape", "result", "node Node, int32 t, float thick") \
    X(ShapeObjSetSides, "Shape", "result", "node Node, int32 t, int32 s") \
    X(ShapeObjSetAngle, "Shape", "result", "node Node, int32 t, float a") \
    X(ShapeObjSetViewportThickness, "Shape", "result", "node Node, float thick") \
    X(ShapeObjSetViewportSides, "Shape", "result", "node Node, int32 s") \
    X(ShapeObjSetViewportAngle, "Shape", "result", "node Node, float a") \
    X(ShapeObjSetRenderable, "Shape", "result", "node Node, int32 sw") \
    X(ShapeObjSetGenUVs, "Shape", "result", "node Node, int32 sw") \
    X(ShapeObjSetDispRenderMesh, "Shape", "result", "node Node, int32 sw") \
    X(ShapeObjSetUseViewport, "Shape", "result", "node Node, int32 sw") \
    X(ShapeObjSetViewportOrRenderer, "Shape", "result", "node Node, int32 sw") \
    X(ShapeObjNumberOfVertices, "Shape", "result", "node Node, int32 t, int32 curve, ptr:int32 OutValue") \
    X(ShapeObjNumberOfCurves, "Shape", "result", "node Node, int32 t, ptr:int32 OutValue") \
    X(ShapeObjCurveClosed, "Shape", "result", "node Node, int32 t, int32 curve, ptr:int32 OutValue") \
    X(ShapeObjInterpCurve3D, "Shape", "result", "node Node, int32 t, int32 curve, float param, int32 ptype, ptr:MaxMcpPoint3 OutValue") \
    X(ShapeObjTangentCurve3D, "Shape", "result", "node Node, int32 t, int32 curve, float param, int32 ptype, ptr:MaxMcpPoint3 OutValue") \
    X(ShapeObjNumberOfPieces, "Shape", "result", "node Node, int32 t, int32 curve, ptr:int32 OutValue") \
    X(ShapeObjInterpPiece3D, "Shape", "result", "node Node, int32 t, int32 curve, int32 piece, float param, int32 ptype, ptr:MaxMcpPoint3 OutValue") \
    X(ShapeObjTangentPiece3D, "Shape", "result", "node Node, int32 t, int32 curve, int32 piece, float param, int32 ptype, ptr:MaxMcpPoint3 OutValue") \
    X(ShapeObjGetMatID, "Shape", "result", "node Node, int32 t, int32 curve, int32 piece, ptr:uint32 OutValue") \
    X(ShapeObjCanMakeBezier, "Shape", "result", "node Node, ptr:int32 OutValue") \
    X(ShapeObjGetParameterName, "Shape", "result", "node Node, int32 pbIndex, int32 localized, ptr:MaxMcpStrOut OutValue") \
    X(ShapeObjInvalidateGeomCache, "Shape", "result", "node Node") \
    X(ShapeObjGetUsePhysicalScaleUVs, "Shape", "result", "node Node, ptr:int32 OutValue") \
    X(ShapeObjSetUsePhysicalScaleUVs, "Shape", "result", "node Node, int32 flag") \
    X(ShapeObjGetTwistCorrect, "Shape", "result", "node Node, ptr:int32 OutValue") \
    X(ShapeObjSetTwistCorrect, "Shape", "result", "node Node, int32 flag") \
    X(ShapeObjGetCap, "Shape", "result", "node Node, ptr:int32 OutValue") \
    X(ShapeObjSetCap, "Shape", "result", "node Node, int32 flag") \
    X(ShapeObjGetQuadCap, "Shape", "result", "node Node, ptr:int32 OutValue") \
    X(ShapeObjSetQuadCap, "Shape", "result", "node Node, int32 flag") \
    X(ShapeObjGetCapSegments, "Shape", "result", "node Node, int32 t, ptr:MaxMcpInterval ivalid, ptr:int32 OutValue") \
    X(ShapeObjSetCapSegments, "Shape", "result", "node Node, int32 t, int32 count") \
    X(ShapeObjGetSphereCap, "Shape", "result", "node Node, int32 t, ptr:MaxMcpInterval ivalid, ptr:float OutValue") \
    X(ShapeObjSetSphereCap, "Shape", "result", "node Node, int32 t, float value") \
    X(MXSParticleGetParticleSystem, "MX", "result", "anim Object, ptr:anim OutValue") \
    X(MXSParticleGetParticleSystemNode, "MX", "result", "anim Object, ptr:node OutValue") \
    X(MXSParticleGetTimeStart, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleGetTimeEnd, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetTimeEnd, "MX", "result", "anim Object, int32 time") \
    X(MXSParticleGetActionNode, "MX", "result", "anim Object, ptr:node OutValue") \
    X(MXSParticleGetUseTime, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetUseTime, "MX", "result", "anim Object, int32 use") \
    X(MXSParticleGetUseAge, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetUseAge, "MX", "result", "anim Object, int32 use") \
    X(MXSParticleGetUseLifespan, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetUseLifespan, "MX", "result", "anim Object, int32 use") \
    X(MXSParticleGetUseEventTime, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetUseEventTime, "MX", "result", "anim Object, int32 use") \
    X(MXSParticleGetUsePosition, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetUsePosition, "MX", "result", "anim Object, int32 use") \
    X(MXSParticleGetUseSpeed, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetUseSpeed, "MX", "result", "anim Object, int32 use") \
    X(MXSParticleGetUseAcceleration, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetUseAcceleration, "MX", "result", "anim Object, int32 use") \
    X(MXSParticleGetUseOrientation, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetUseOrientation, "MX", "result", "anim Object, int32 use") \
    X(MXSParticleGetUseSpin, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetUseSpin, "MX", "result", "anim Object, int32 use") \
    X(MXSParticleGetUseScale, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetUseScale, "MX", "result", "anim Object, int32 use") \
    X(MXSParticleGetUseTM, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetUseTM, "MX", "result", "anim Object, int32 use") \
    X(MXSParticleGetUseSelected, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetUseSelected, "MX", "result", "anim Object, int32 use") \
    X(MXSParticleGetUseShape, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetUseShape, "MX", "result", "anim Object, int32 use") \
    X(MXSParticleGetUseMtlIndex, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetUseMtlIndex, "MX", "result", "anim Object, int32 use") \
    X(MXSParticleGetUseMapping, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetUseMapping, "MX", "result", "anim Object, int32 use") \
    X(MXSParticleGetUseInt, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetUseInt, "MX", "result", "anim Object, int32 use") \
    X(MXSParticleGetUseFloat, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetUseFloat, "MX", "result", "anim Object, int32 use") \
    X(MXSParticleGetUseVector, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetUseVector, "MX", "result", "anim Object, int32 use") \
    X(MXSParticleGetUseMatrix, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetUseMatrix, "MX", "result", "anim Object, int32 use") \
    X(MXSParticleGetCurrentParticleIndex, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleGetCurrentParticleBornIndex, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetCurrentParticleIndex, "MX", "result", "anim Object, int32 index") \
    X(MXSParticleSetCurrentParticleBornIndex, "MX", "result", "anim Object, int32 bornIndex") \
    X(MXSParticleSetParticleTimeByIndex, "MX", "result", "anim Object, int32 index, int32 time") \
    X(MXSParticleSetParticleTimeByBornIndex, "MX", "result", "anim Object, int32 id, int32 time") \
    X(MXSParticleGetParticleTime, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetParticleTime, "MX", "result", "anim Object, int32 time") \
    X(MXSParticleSetParticleAgeByIndex, "MX", "result", "anim Object, int32 index, int32 age") \
    X(MXSParticleSetParticleAgeByBornIndex, "MX", "result", "anim Object, int32 id, int32 age") \
    X(MXSParticleGetParticleAge, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetParticleAge, "MX", "result", "anim Object, int32 age") \
    X(MXSParticleSetParticleLifespanByIndex, "MX", "result", "anim Object, int32 index, int32 lifespan") \
    X(MXSParticleSetParticleLifespanByBornIndex, "MX", "result", "anim Object, int32 id, int32 lifespan") \
    X(MXSParticleGetParticleLifespan, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetParticleLifespan, "MX", "result", "anim Object, int32 lifespan") \
    X(MXSParticleSetParticleEventTimeByIndex, "MX", "result", "anim Object, int32 index, int32 time") \
    X(MXSParticleSetParticleEventTimeByBornIndex, "MX", "result", "anim Object, int32 id, int32 time") \
    X(MXSParticleGetParticleEventTime, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetParticleEventTime, "MX", "result", "anim Object, int32 time") \
    X(MXSParticleSetParticlePositionByIndex, "MX", "result", "anim Object, int32 index, cptr:MaxMcpPoint3 pos") \
    X(MXSParticleSetParticlePositionByBornIndex, "MX", "result", "anim Object, int32 id, cptr:MaxMcpPoint3 pos") \
    X(MXSParticleSetParticlePosition, "MX", "result", "anim Object, cptr:MaxMcpPoint3 pos") \
    X(MXSParticleSetParticleSpeedByIndex, "MX", "result", "anim Object, int32 index, cptr:MaxMcpPoint3 speed") \
    X(MXSParticleSetParticleSpeedByBornIndex, "MX", "result", "anim Object, int32 id, cptr:MaxMcpPoint3 speed") \
    X(MXSParticleSetParticleSpeed, "MX", "result", "anim Object, cptr:MaxMcpPoint3 speed") \
    X(MXSParticleSetParticleAccelerationByIndex, "MX", "result", "anim Object, int32 index, cptr:MaxMcpPoint3 accel") \
    X(MXSParticleSetParticleAccelerationByBornIndex, "MX", "result", "anim Object, int32 id, cptr:MaxMcpPoint3 accel") \
    X(MXSParticleSetParticleAcceleration, "MX", "result", "anim Object, cptr:MaxMcpPoint3 speed") \
    X(MXSParticleSetParticleOrientationByIndex, "MX", "result", "anim Object, int32 index, cptr:MaxMcpPoint3 orient") \
    X(MXSParticleSetParticleOrientationByBornIndex, "MX", "result", "anim Object, int32 id, cptr:MaxMcpPoint3 orient") \
    X(MXSParticleSetParticleOrientation, "MX", "result", "anim Object, cptr:MaxMcpPoint3 orient") \
    X(MXSParticleSetParticleSpinByIndex, "MX", "result", "anim Object, int32 index, cptr:MaxMcpAngAxis spin") \
    X(MXSParticleSetParticleSpinByBornIndex, "MX", "result", "anim Object, int32 id, cptr:MaxMcpAngAxis spin") \
    X(MXSParticleSetParticleSpin, "MX", "result", "anim Object, cptr:MaxMcpAngAxis spin") \
    X(MXSParticleSetParticleScaleByIndex, "MX", "result", "anim Object, int32 index, float scale") \
    X(MXSParticleSetParticleScaleByBornIndex, "MX", "result", "anim Object, int32 id, float scale") \
    X(MXSParticleGetParticleScale, "MX", "result", "anim Object, ptr:float OutValue") \
    X(MXSParticleSetParticleScale, "MX", "result", "anim Object, float scale") \
    X(MXSParticleSetParticleScaleXYZByIndex, "MX", "result", "anim Object, int32 index, cptr:MaxMcpPoint3 scale") \
    X(MXSParticleSetParticleScaleXYZByBornIndex, "MX", "result", "anim Object, int32 id, cptr:MaxMcpPoint3 scale") \
    X(MXSParticleSetParticleScaleXYZ, "MX", "result", "anim Object, cptr:MaxMcpPoint3 scale") \
    X(MXSParticleSetParticleTMByIndex, "MX", "result", "anim Object, int32 index, cptr:MaxMcpMatrix3 tm") \
    X(MXSParticleSetParticleTMByBornIndex, "MX", "result", "anim Object, int32 id, cptr:MaxMcpMatrix3 tm") \
    X(MXSParticleSetParticleTM, "MX", "result", "anim Object, cptr:MaxMcpMatrix3 tm") \
    X(MXSParticleSetParticleSelectedByIndex, "MX", "result", "anim Object, int32 index, int32 selected") \
    X(MXSParticleSetParticleSelectedByBornIndex, "MX", "result", "anim Object, int32 id, int32 selected") \
    X(MXSParticleGetParticleSelected, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetParticleSelected, "MX", "result", "anim Object, int32 selected") \
    X(MXSParticleSetParticleMtlIndexByIndex, "MX", "result", "anim Object, int32 index, int32 mtlIndex") \
    X(MXSParticleSetParticleMtlIndexByBornIndex, "MX", "result", "anim Object, int32 id, int32 mtlIndex") \
    X(MXSParticleSetParticleMtlIndex, "MX", "result", "anim Object, int32 mtlIndex") \
    X(MXSParticleSetParticleIntByIndex, "MX", "result", "anim Object, int32 index, int32 value") \
    X(MXSParticleSetParticleIntByBornIndex, "MX", "result", "anim Object, int32 id, int32 value") \
    X(MXSParticleGetParticleInt, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetParticleInt, "MX", "result", "anim Object, int32 value") \
    X(MXSParticleSetParticleFloatByIndex, "MX", "result", "anim Object, int32 index, float value") \
    X(MXSParticleSetParticleFloatByBornIndex, "MX", "result", "anim Object, int32 id, float value") \
    X(MXSParticleGetParticleFloat, "MX", "result", "anim Object, ptr:float OutValue") \
    X(MXSParticleSetParticleFloat, "MX", "result", "anim Object, float value") \
    X(MXSParticleSetParticleVectorByIndex, "MX", "result", "anim Object, int32 index, cptr:MaxMcpPoint3 value") \
    X(MXSParticleSetParticleVectorByBornIndex, "MX", "result", "anim Object, int32 id, cptr:MaxMcpPoint3 value") \
    X(MXSParticleSetParticleVector, "MX", "result", "anim Object, cptr:MaxMcpPoint3 value") \
    X(MXSParticleSetParticleMatrixByIndex, "MX", "result", "anim Object, int32 index, cptr:MaxMcpMatrix3 value") \
    X(MXSParticleSetParticleMatrixByBornIndex, "MX", "result", "anim Object, int32 id, cptr:MaxMcpMatrix3 value") \
    X(MXSParticleSetParticleMatrix, "MX", "result", "anim Object, cptr:MaxMcpMatrix3 value") \
    X(MXSParticleSetParticleTestStatusByIndex, "MX", "result", "anim Object, int32 index, int32 testStatus") \
    X(MXSParticleSetParticleTestStatusByBornIndex, "MX", "result", "anim Object, int32 id, int32 testStatus") \
    X(MXSParticleGetParticleTestStatus, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetParticleTestStatus, "MX", "result", "anim Object, int32 testStatus") \
    X(MXSParticleSetGlobalTestStatus, "MX", "result", "anim Object, int32 testStatus") \
    X(MXSParticleSetParticleTestTimeByIndex, "MX", "result", "anim Object, int32 index, int32 testTime") \
    X(MXSParticleSetParticleTestTimeByBornIndex, "MX", "result", "anim Object, int32 id, int32 testTime") \
    X(MXSParticleGetParticleTestTime, "MX", "result", "anim Object, ptr:int32 OutValue") \
    X(MXSParticleSetParticleTestTime, "MX", "result", "anim Object, int32 testTime") \
    X(MXSParticleSetGlobalTestTime, "MX", "result", "anim Object, int32 testTime") \
    X(BezierShapeInit, "Bezier", "result", "node Node") \
    X(BezierShapeGetVert, "Bezier", "result", "node Node, int32 poly, int32 i, ptr:MaxMcpPoint3 OutValue") \
    X(BezierShapeBuildBoundingBox, "Bezier", "result", "node Node") \
    X(BezierShapeInvalidateGeomCache, "Bezier", "result", "node Node") \
    X(BezierShapeInvalidateCapCache, "Bezier", "result", "node Node") \
    X(BezierShapeSetDispFlag, "Bezier", "result", "node Node, uint32 f") \
    X(BezierShapeGetDispFlag, "Bezier", "result", "node Node, uint32 f, ptr:uint32 OutValue") \
    X(BezierShapeClearDispFlag, "Bezier", "result", "node Node, uint32 f") \
    X(BezierShapeDeleteSpline, "Bezier", "result", "node Node, int32 index, ptr:int32 OutValue") \
    X(BezierShapeNewShape, "Bezier", "result", "node Node") \
    X(BezierShapeGetNumVerts, "Bezier", "result", "node Node, ptr:int32 OutValue") \
    X(BezierShapeGetNumSegs, "Bezier", "result", "node Node, ptr:int32 OutValue") \
    X(BezierShapeUpdateSels, "Bezier", "result", "node Node, int32 save") \
    X(BezierShapeGetClosures, "Bezier", "result", "node Node, ptr:MaxMcpSpan array") \
    X(BezierShapeSetClosures, "Bezier", "result", "node Node, ptr:MaxMcpSpan array") \
    X(BezierShapeReverse, "Bezier", "result", "node Node, int32 poly, int32 keepZero") \
    X(BezierShapeMakeFirst, "Bezier", "result", "node Node, int32 poly, int32 vertex") \
    X(BezierShapeTransform, "Bezier", "result", "node Node, cptr:MaxMcpMatrix3 tm") \
    X(BezierShapeReadyCachedPolyShape, "Bezier", "result", "node Node") \
    X(BezierShapePrepVertBaseIndex, "Bezier", "result", "node Node") \
    X(BezierShapeGetVertIndex, "Bezier", "result", "node Node, int32 poly, int32 vert, ptr:int32 OutValue") \
    X(BezierShapeGetTotalVerts, "Bezier", "result", "node Node, ptr:int32 OutValue") \
    X(BezierShapeSetVert, "Bezier", "result", "node Node, int32 index, cptr:MaxMcpPoint3 xyz") \
    X(BezierShapePrepKnotBaseIndex, "Bezier", "result", "node Node") \
    X(BezierShapeGetKnotIndex, "Bezier", "result", "node Node, int32 poly, int32 knot, ptr:int32 OutValue") \
    X(BezierShapeGetTotalKnots, "Bezier", "result", "node Node, ptr:int32 OutValue") \
    X(BezierShapeDeleteSelVerts, "Bezier", "result", "node Node, int32 poly, ptr:int32 OutValue") \
    X(BezierShapeDeleteSelSegs, "Bezier", "result", "node Node, int32 poly, ptr:int32 OutValue") \
    X(BezierShapeDeleteSelectedVerts, "Bezier", "result", "node Node, ptr:int32 OutValue") \
    X(BezierShapeDeleteSelectedSegs, "Bezier", "result", "node Node, ptr:int32 OutValue") \
    X(BezierShapeDeleteSelectedPolys, "Bezier", "result", "node Node, ptr:int32 OutValue") \
    X(BezierShapeCloneSelectedParts, "Bezier", "result", "node Node, int32 reverse, ptr:int32 OutValue") \
    X(BezierShapeRecordTopologyTags, "Bezier", "result", "node Node, int32 channel, ptr:int32 OutValue") \
    X(BezierShapeInterpCurve3D, "Bezier", "result", "node Node, int32 poly, float param, int32 ptype, ptr:MaxMcpPoint3 OutValue") \
    X(BezierShapeTangentCurve3D, "Bezier", "result", "node Node, int32 poly, float param, int32 ptype, ptr:MaxMcpPoint3 OutValue") \
    X(BezierShapeInterpPiece3D, "Bezier", "result", "node Node, int32 poly, int32 piece, float param, int32 ptype, ptr:MaxMcpPoint3 OutValue") \
    X(BezierShapeTangentPiece3D, "Bezier", "result", "node Node, int32 poly, int32 piece, float param, int32 ptype, ptr:MaxMcpPoint3 OutValue") \
    X(BezierShapeGetMatID, "Bezier", "result", "node Node, int32 poly, int32 piece, ptr:uint32 OutValue") \
    X(BezierShapeLengthOfCurve, "Bezier", "result", "node Node, int32 poly, ptr:float OutValue") \
    X(BezierShapeBindKnot, "Bezier", "result", "node Node, int32 isEnd, int32 segIndex, int32 splineSegID, int32 splinePointID") \
    X(BezierShapeUnbindKnot, "Bezier", "result", "node Node, int32 splineID, int32 isEnd, ptr:int32 OutValue") \
    X(BezierShapeUpdateBindList, "Bezier", "result", "node Node, int32 useGeometricTracking") \
    X(BezierShapeHideSelectedSegs, "Bezier", "result", "node Node, ptr:int32 OutValue") \
    X(BezierShapeHideSelectedVerts, "Bezier", "result", "node Node, ptr:int32 OutValue") \
    X(BezierShapeHideSelectedSplines, "Bezier", "result", "node Node, ptr:int32 OutValue") \
    X(BezierShapeUnhideSegs, "Bezier", "result", "node Node, ptr:int32 OutValue") \
    X(BezierShapeSetVertexWeightCount, "Bezier", "result", "node Node, int32 i") \
    X(BezierShapeSetVertexWeight, "Bezier", "result", "node Node, int32 i, float w") \
    X(BezierShapeSupportVSelectionWeights, "Bezier", "result", "node Node") \
    X(BezierShapeUseEdgeDists, "Bezier", "result", "node Node, ptr:int32 OutValue") \
    X(BezierShapeSetUseEdgeDists, "Bezier", "result", "node Node, int32 edgeDist") \
    X(BezierShapeEdgeDist, "Bezier", "result", "node Node, ptr:int32 OutValue") \
    X(BezierShapeSetEdgeDist, "Bezier", "result", "node Node, int32 edgeDist") \
    X(BezierShapeUseSoftSelections, "Bezier", "result", "node Node, ptr:int32 OutValue") \
    X(BezierShapeSetUseSoftSelections, "Bezier", "result", "node Node, int32 useSoftSelections") \
    X(BezierShapeAffectBackface, "Bezier", "result", "node Node, ptr:int32 OutValue") \
    X(BezierShapeSetAffectBackface, "Bezier", "result", "node Node, int32 affectBackface") \
    X(BezierShapeFalloff, "Bezier", "result", "node Node, ptr:float OutValue") \
    X(BezierShapeSetFalloff, "Bezier", "result", "node Node, float falloff") \
    X(BezierShapePinch, "Bezier", "result", "node Node, ptr:float OutValue") \
    X(BezierShapeSetPinch, "Bezier", "result", "node Node, float pinch") \
    X(BezierShapeBubble, "Bezier", "result", "node Node, ptr:float OutValue") \
    X(BezierShapeSetBubble, "Bezier", "result", "node Node, float bubble") \
    X(BezierShapeInvalidateVertexWeights, "Bezier", "result", "node Node") \
    X(BezierShapeUpdateVertexDists, "Bezier", "result", "node Node") \
    X(BezierShapeUpdateEdgeDists, "Bezier", "result", "node Node") \
    X(BezierShapeUpdateVertexWeights, "Bezier", "result", "node Node") \
    X(ILayerSetName, "ILayer", "result", "anim Layer, cstr name") \
    X(ILayerGetName, "ILayer", "result", "anim Layer, ptr:MaxMcpStrOut OutValue") \
    X(ILayerSetWireColor, "ILayer", "result", "anim Layer, uint32 newcol, int32 propagate") \
    X(ILayerGetWireColor, "ILayer", "result", "anim Layer, ptr:uint32 OutValue") \
    X(ILayerHide, "ILayer", "result", "anim Layer, int32 onOff, int32 propagate") \
    X(ILayerIsHidden, "ILayer", "result", "anim Layer, int32 includeParent, ptr:int32 OutValue") \
    X(ILayerFreeze, "ILayer", "result", "anim Layer, int32 onOff, int32 propagate") \
    X(ILayerIsFrozen, "ILayer", "result", "anim Layer, int32 includeParent, ptr:int32 OutValue") \
    X(ILayerXRayMtl, "ILayer", "result", "anim Layer, int32 onOff, int32 propagate") \
    X(ILayerHasXRayMtl, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerBoxMode, "ILayer", "result", "anim Layer, int32 onOff, int32 propagate") \
    X(ILayerGetBoxMode, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerBackCull, "ILayer", "result", "anim Layer, int32 onOff, int32 propagate") \
    X(ILayerGetBackCull, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerAllEdges, "ILayer", "result", "anim Layer, int32 onOff, int32 propagate") \
    X(ILayerGetAllEdges, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerVertTicks, "ILayer", "result", "anim Layer, int32 onOff, int32 propagate") \
    X(ILayerGetVertTicks, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerTrajectory, "ILayer", "result", "anim Layer, int32 onOff, int32 propagate") \
    X(ILayerGetTrajectory, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerIgnoreExtents, "ILayer", "result", "anim Layer, int32 onOff, int32 propagate") \
    X(ILayerGetIgnoreExtents, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerSetShowFrozenWithMtl, "ILayer", "result", "anim Layer, int32 onOff, int32 propagate") \
    X(ILayerShowFrozenWithMtl, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerSetCVertMode, "ILayer", "result", "anim Layer, int32 onOff, int32 propagate") \
    X(ILayerGetCVertMode, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerSetShadeCVerts, "ILayer", "result", "anim Layer, int32 onOff") \
    X(ILayerGetShadeCVerts, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerSetVisibility, "ILayer", "result", "anim Layer, int32 t, float vis") \
    X(ILayerGetVisibility, "ILayer", "result", "anim Layer, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(ILayerIsHiddenByVisControl, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerSetRenderable, "ILayer", "result", "anim Layer, int32 onOff, int32 propagate") \
    X(ILayerRenderable, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerSetInheritVisibility, "ILayer", "result", "anim Layer, int32 onOff") \
    X(ILayerGetInheritVisibility, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerSetPrimaryVisibility, "ILayer", "result", "anim Layer, int32 onOff") \
    X(ILayerGetPrimaryVisibility, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerSetSecondaryVisibility, "ILayer", "result", "anim Layer, int32 onOff") \
    X(ILayerGetSecondaryVisibility, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerSetCastShadows, "ILayer", "result", "anim Layer, int32 onOff") \
    X(ILayerCastShadows, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerSetRcvShadows, "ILayer", "result", "anim Layer, int32 onOff") \
    X(ILayerRcvShadows, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerSetApplyAtmospherics, "ILayer", "result", "anim Layer, int32 onOff") \
    X(ILayerApplyAtmospherics, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerSetRenderOccluded, "ILayer", "result", "anim Layer, int32 onOff") \
    X(ILayerGetRenderOccluded, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerGetMotBlurOnOff, "ILayer", "result", "anim Layer, int32 t, ptr:int32 OutValue") \
    X(ILayerSetMotBlurOnOff, "ILayer", "result", "anim Layer, int32 t, int32 onOff") \
    X(ILayerGetImageBlurMultiplier, "ILayer", "result", "anim Layer, int32 t, ptr:float OutValue") \
    X(ILayerSetImageBlurMultiplier, "ILayer", "result", "anim Layer, int32 t, float m") \
    X(ILayerSetMotBlur, "ILayer", "result", "anim Layer, int32 kind") \
    X(ILayerMotBlur, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerUsed, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerHasObjects, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerSelectObjects, "ILayer", "result", "anim Layer") \
    X(ILayerGetNumOfChildLayers, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerGetRenderFlags, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerSetRenderFlags, "ILayer", "result", "anim Layer, int32 flags") \
    X(ILayerGetDisplayFlags, "ILayer", "result", "anim Layer, ptr:int32 OutValue") \
    X(ILayerGetFlag, "ILayer", "result", "anim Layer, int32 mask, ptr:int32 OutValue") \
    X(ILayerGetFlag2, "ILayer", "result", "anim Layer, int32 mask, ptr:int32 OutValue") \
    X(ILayerUpdateSelectionSet, "ILayer", "result", "anim Layer") \
    X(ParticleExtSetEveryStepUpdateScriptLine, "Particle", "result", "anim Object, cstr script") \
    X(ParticleExtSetEveryStepUpdateScriptFile, "Particle", "result", "anim Object, cstr file") \
    X(ParticleExtSetFinalStepUpdateScriptLine, "Particle", "result", "anim Object, cstr script") \
    X(ParticleExtSetFinalStepUpdateScriptFile, "Particle", "result", "anim Object, cstr file") \
    X(ParticleExtExecuteEveryStepUpdateScript, "Particle", "result", "anim Object") \
    X(ParticleExtExecuteFinalStepUpdateScript, "Particle", "result", "anim Object") \
    X(ParticleExtGetUpdateTime, "Particle", "result", "anim Object, ptr:int32 OutValue") \
    X(ParticleExtNumParticles, "Particle", "result", "anim Object, ptr:int32 OutValue") \
    X(ParticleExtNumParticlesGenerated, "Particle", "result", "anim Object, ptr:int32 OutValue") \
    X(ParticleExtAddParticle, "Particle", "result", "anim Object, ptr:int32 OutValue") \
    X(ParticleExtAddParticles, "Particle", "result", "anim Object, int32 num, ptr:int32 OutValue") \
    X(ParticleExtDeleteParticle, "Particle", "result", "anim Object, int32 index, ptr:int32 OutValue") \
    X(ParticleExtGetCurrentParticleIndex, "Particle", "result", "anim Object, ptr:int32 OutValue") \
    X(ParticleExtGetCurrentParticleBornIndex, "Particle", "result", "anim Object, ptr:int32 OutValue") \
    X(ParticleExtSetCurrentParticleIndex, "Particle", "result", "anim Object, int32 index") \
    X(ParticleExtSetCurrentParticleBornIndex, "Particle", "result", "anim Object, int32 bornIndex") \
    X(ParticleExtSetParticleAgeByIndex, "Particle", "result", "anim Object, int32 index, int32 age") \
    X(ParticleExtSetParticleAgeByBornIndex, "Particle", "result", "anim Object, int32 id, int32 age") \
    X(ParticleExtGetParticleAge, "Particle", "result", "anim Object, ptr:int32 OutValue") \
    X(ParticleExtSetParticleAge, "Particle", "result", "anim Object, int32 age") \
    X(ParticleExtSetParticleLifeSpanByIndex, "Particle", "result", "anim Object, int32 index, int32 LifeSpan") \
    X(ParticleExtSetParticleLifeSpanByBornIndex, "Particle", "result", "anim Object, int32 id, int32 LifeSpan") \
    X(ParticleExtGetParticleLifeSpan, "Particle", "result", "anim Object, ptr:int32 OutValue") \
    X(ParticleExtSetParticleLifeSpan, "Particle", "result", "anim Object, int32 lifespan") \
    X(ParticleExtSetParticleGroupTimeByIndex, "Particle", "result", "anim Object, int32 index, int32 time") \
    X(ParticleExtSetParticleGroupTimeByBornIndex, "Particle", "result", "anim Object, int32 id, int32 time") \
    X(ParticleExtGetParticleGroupTime, "Particle", "result", "anim Object, ptr:int32 OutValue") \
    X(ParticleExtSetParticleGroupTime, "Particle", "result", "anim Object, int32 time") \
    X(ParticleExtSetParticlePositionByIndex, "Particle", "result", "anim Object, int32 index, cptr:MaxMcpPoint3 pos") \
    X(ParticleExtSetParticlePositionByBornIndex, "Particle", "result", "anim Object, int32 id, cptr:MaxMcpPoint3 pos") \
    X(ParticleExtSetParticlePosition, "Particle", "result", "anim Object, cptr:MaxMcpPoint3 pos") \
    X(ParticleExtSetParticleSpeedByIndex, "Particle", "result", "anim Object, int32 index, cptr:MaxMcpPoint3 speed") \
    X(ParticleExtSetParticleSpeedByBornIndex, "Particle", "result", "anim Object, int32 id, cptr:MaxMcpPoint3 speed") \
    X(ParticleExtSetParticleSpeed, "Particle", "result", "anim Object, cptr:MaxMcpPoint3 speed") \
    X(ParticleExtSetParticleOrientationByIndex, "Particle", "result", "anim Object, int32 index, cptr:MaxMcpPoint3 orient") \
    X(ParticleExtSetParticleOrientationByBornIndex, "Particle", "result", "anim Object, int32 id, cptr:MaxMcpPoint3 orient") \
    X(ParticleExtSetParticleOrientation, "Particle", "result", "anim Object, cptr:MaxMcpPoint3 orient") \
    X(ParticleExtSetParticleSpinByIndex, "Particle", "result", "anim Object, int32 index, cptr:MaxMcpAngAxis spin") \
    X(ParticleExtSetParticleSpinByBornIndex, "Particle", "result", "anim Object, int32 id, cptr:MaxMcpAngAxis spin") \
    X(ParticleExtSetParticleSpin, "Particle", "result", "anim Object, cptr:MaxMcpAngAxis spin") \
    X(ParticleExtSetParticleScaleByIndex, "Particle", "result", "anim Object, int32 index, float scale") \
    X(ParticleExtSetParticleScaleByBornIndex, "Particle", "result", "anim Object, int32 id, float scale") \
    X(ParticleExtGetParticleScale, "Particle", "result", "anim Object, ptr:float OutValue") \
    X(ParticleExtSetParticleScale, "Particle", "result", "anim Object, float scale") \
    X(ParticleExtSetParticleScaleXYZByIndex, "Particle", "result", "anim Object, int32 index, cptr:MaxMcpPoint3 scale") \
    X(ParticleExtSetParticleScaleXYZByBornIndex, "Particle", "result", "anim Object, int32 id, cptr:MaxMcpPoint3 scale") \
    X(ParticleExtSetParticleScaleXYZ, "Particle", "result", "anim Object, cptr:MaxMcpPoint3 scale") \
    X(ParticleExtSetParticleTMByIndex, "Particle", "result", "anim Object, int32 index, cptr:MaxMcpMatrix3 tm") \
    X(ParticleExtSetParticleTMByBornIndex, "Particle", "result", "anim Object, int32 id, cptr:MaxMcpMatrix3 tm") \
    X(ParticleExtSetParticleTM, "Particle", "result", "anim Object, cptr:MaxMcpMatrix3 tm") \
    X(ParticleExtSetParticleSelectedByIndex, "Particle", "result", "anim Object, int32 index, int32 selected") \
    X(ParticleExtSetParticleSelectedByBornIndex, "Particle", "result", "anim Object, int32 id, int32 selected") \
    X(ParticleExtGetParticleSelected, "Particle", "result", "anim Object, ptr:int32 OutValue") \
    X(ParticleExtSetParticleSelected, "Particle", "result", "anim Object, int32 selected") \
    X(Scene8GetRendCamNode, "Scene8", "result", "ptr:node OutValue") \
    X(Scene8GetRendUseImgSeq, "Scene8", "result", "ptr:int32 OutValue") \
    X(Scene8SetRendUseImgSeq, "Scene8", "result", "int32 onOff") \
    X(Scene8GetRendImgSeqType, "Scene8", "result", "ptr:int32 OutValue") \
    X(Scene8SetRendImgSeqType, "Scene8", "result", "int32 type") \
    X(Scene8GetUsePreRendScript, "Scene8", "result", "ptr:int32 OutValue") \
    X(Scene8SetUsePreRendScript, "Scene8", "result", "int32 onOff") \
    X(Scene8GetLocalPreRendScript, "Scene8", "result", "ptr:int32 OutValue") \
    X(Scene8SetLocalPreRendScript, "Scene8", "result", "int32 onOff") \
    X(Scene8GetUsePostRendScript, "Scene8", "result", "ptr:int32 OutValue") \
    X(Scene8SetUsePostRendScript, "Scene8", "result", "int32 onOff") \
    X(Scene8GetControllerOverrideRangeDefault, "Scene8", "result", "ptr:int32 OutValue") \
    X(Scene8SetControllerOverrideRangeDefault, "Scene8", "result", "int32 override") \
    X(Scene8SetDefaultTangentType, "Scene8", "result", "int32 dfltInTangentType, int32 dfltOutTangentType, int32 writeInCfgFile") \
    X(Scene8GetSpringQuickEditMode, "Scene8", "result", "ptr:int32 OutValue") \
    X(Scene8SetSpringQuickEditMode, "Scene8", "result", "int32 in_quickEdit") \
    X(Scene8SetSpringRollingStart, "Scene8", "result", "int32 in_start") \
    X(Scene8GetSpringRollingStart, "Scene8", "result", "ptr:int32 OutValue") \
    X(Scene8ColorById, "Scene8", "result", "uint32 id, ptr:MaxMcpColor c") \
    X(Scene8RegisterModelessRenderWindow, "Scene8", "result", "hwnd hWnd") \
    X(Scene8UnRegisterModelessRenderWindow, "Scene8", "result", "hwnd hWnd") \
    X(Scene8IsRegisteredModelessRenderWindow, "Scene8", "result", "hwnd hWnd, ptr:int32 OutValue") \
    X(Scene8IsSavingToFile, "Scene8", "result", "ptr:int32 OutValue") \
    X(Scene10GetTrajectoryMode, "Scene10", "result", "ptr:int32 OutValue") \
    X(Scene10SetTrajectoryMode, "Scene10", "result", "int32 flag") \
    X(Scene10GetTrajectoryKeySubMode, "Scene10", "result", "ptr:int32 OutValue") \
    X(Scene10SetTrajectoryKeySubMode, "Scene10", "result", "int32 flag") \
    X(Scene10GetTrajectoryAddKeyMode, "Scene10", "result", "ptr:int32 OutValue") \
    X(Scene10SetTrajectoryAddKeyMode, "Scene10", "result", "int32 flag") \
    X(Scene10DeleteSelectedTrajectoryKey, "Scene10", "result", "") \
    X(Scene10GetAutoKeyDefaultKeyOn, "Scene10", "result", "ptr:int32 OutValue") \
    X(Scene10SetAutoKeyDefaultKeyOn, "Scene10", "result", "int32 setKey") \
    X(Scene10GetAutoKeyDefaultKeyTime, "Scene10", "result", "ptr:int32 OutValue") \
    X(Scene10SetAutoKeyDefaultKeyTime, "Scene10", "result", "int32 t") \
    X(Scene10GetPrompt, "Scene10", "result", "ptr:MaxMcpStrOut OutValue") \
    X(Scene10FormatRenderTime, "Scene10", "result", "uint32 msec, ptr:MaxMcpStrOut str, int32 hundredths") \
    X(Scene11GetRendUseActiveView, "Scene11", "result", "ptr:int32 OutValue") \
    X(Scene11SetRendUseActiveView, "Scene11", "result", "int32 useActiveView") \
    X(Scene11GetRenderPresetMRUListCount, "Scene11", "result", "ptr:int32 OutValue") \
    X(Scene11GetRenderPresetMRUListDisplayName, "Scene11", "result", "int32 i, ptr:MaxMcpStrOut OutValue") \
    X(Scene11GetRenderPresetMRUListFileName, "Scene11", "result", "int32 i, ptr:MaxMcpStrOut OutValue") \
    X(Scene11GetTransformGizmoTM, "Scene11", "result", "ptr:MaxMcpMatrix3 OutValue") \
    X(Scene11DisplayViewportConfigDialogPage, "Scene11", "result", "int32 i") \
    X(Scene13GetRendUseIterative, "Scene13", "result", "ptr:int32 OutValue") \
    X(Scene13SetRendUseIterative, "Scene13", "result", "int32 b") \
    X(Scene13SaveSceneAsVersion, "Scene13", "result", "cstr fname, int32 clearNeedSaveFlag, int32 useNewFile, uint32 saveAsVersion, ptr:int32 OutValue") \
    X(Scene13SaveSelectedNodesAsVersion, "Scene13", "result", "cstr fname, uint32 saveAsVersion, ptr:int32 OutValue") \
    X(Scene13GetSceneFileCompressOnSave, "Scene13", "result", "ptr:int32 OutValue") \
    X(Scene13SetSceneFileCompressOnSave, "Scene13", "result", "int32 compress, int32 persist") \
    X(Scene13GetMtlDlgMode, "Scene13", "result", "ptr:int32 OutValue") \
    X(Scene13SetMtlDlgMode, "Scene13", "result", "int32 mode") \
    X(Scene13SetNameSuffixLength, "Scene13", "result", "uint32 suffixLength") \
    X(Scene13GetNameSuffixLength, "Scene13", "result", "ptr:uint32 OutValue") \
    X(Scene14GetRendViewID, "Scene14", "result", "ptr:int32 OutValue") \
    X(Scene14SetRendViewID, "Scene14", "result", "int32 id") \
    X(Scene14SetPlayPreviewWhenDone, "Scene14", "result", "int32 play") \
    X(Scene14GetPlayPreviewWhenDone, "Scene14", "result", "ptr:int32 OutValue") \
    X(Scene14OverrideLanguageSpecifiedInSceneFile, "Scene14", "result", "ptr:int32 OutValue") \
    X(Scene14SetOverrideLanguageSpecifiedInSceneFile, "Scene14", "result", "int32 overrideFileLangID") \
    X(Scene14UseCodePageSpecifiedInSceneFile, "Scene14", "result", "ptr:int32 OutValue") \
    X(Scene14SetUseCodePageSpecifiedInSceneFile, "Scene14", "result", "int32 useFileCodePage") \
    X(Scene14LegacyFilesCanBeStoredUsingUTF8, "Scene14", "result", "ptr:int32 OutValue") \
    X(Scene14SetLegacyFilesCanBeStoredUsingUTF8, "Scene14", "result", "int32 allowUTF8") \
    X(Scene14DefaultTextLoadCodePage, "Scene14", "result", "ptr:uint32 OutValue") \
    X(Scene14DefaultTextSaveCodePage, "Scene14", "result", "int32 allow_utf8, ptr:uint32 OutValue") \
    X(Scene15GetMainThreadID, "Scene15", "result", "ptr:uint32 OutValue") \
    X(Scene16SetShowWorldAxis, "Scene16", "result", "int32 state") \
    X(Scene16GetShowWorldAxis, "Scene16", "result", "ptr:int32 OutValue") \
    X(Scene16GetOverrideRenderSettingMtl, "Scene16", "result", "ptr:anim OutValue") \
    X(Scene17SetEnableTMCache, "Scene17", "result", "int32 value, int32 commitToInit") \
    X(Scene17GetEnableTMCache, "Scene17", "result", "ptr:int32 OutValue") \
    X(Scene17InNonInteractiveMode, "Scene17", "result", "int32 checkTestMode, ptr:int32 OutValue") \
    X(Scene17SetInNonInteractiveTestMode, "Scene17", "result", "") \
    X(Scene17SetInSecureMode, "Scene17", "result", "") \
    X(Scene17InSecureMode, "Scene17", "result", "ptr:int32 OutValue") \
    X(Scene17IsRibbonSupportEnabled, "Scene17", "result", "ptr:int32 OutValue") \
    X(Scene17BreakSelectedKeyTangent, "Scene17", "result", "") \
    X(Scene17UnifySelectedKeyTangent, "Scene17", "result", "") \
    X(Scene17SetSelectedKeyTangentType, "Scene17", "result", "int32 type") \
    X(Scene17GetTrajectoryPathGradation, "Scene17", "result", "ptr:int32 OutValue") \
    X(Scene17GetUnselTrajectoryDrawFrameTicks, "Scene17", "result", "ptr:int32 OutValue") \
    X(Scene17SetUnselTrajectoryDrawFrameTicks, "Scene17", "result", "int32 draw") \
    X(Scene17GetUnselTrajectoryDrawKeys, "Scene17", "result", "ptr:int32 OutValue") \
    X(Scene17SetUnselTrajectoryDrawKeys, "Scene17", "result", "int32 draw") \
    X(Scene17TrimTrajectories, "Scene17", "result", "ptr:int32 OutValue") \
    X(Scene17SetTrimTrajectories, "Scene17", "result", "int32 trim") \
    X(Scene17IsFixedTrimRange, "Scene17", "result", "ptr:int32 OutValue") \
    X(Scene17SetFixedTrimRange, "Scene17", "result", "int32 fixedRange") \
    X(Scene17TrimTrajectoriesOffset, "Scene17", "result", "ptr:int32 OutValue") \
    X(Scene17SetTrimTrajectoriesOffset, "Scene17", "result", "int32 range") \
    X(Scene17GetTrimStart, "Scene17", "result", "ptr:int32 OutValue") \
    X(Scene17SetTrimStart, "Scene17", "result", "int32 startFrame") \
    X(Scene17GetTrimEnd, "Scene17", "result", "ptr:int32 OutValue") \
    X(Scene17SetTrimEnd, "Scene17", "result", "int32 endFrame") \
    X(Scene17GetSelTrajectoryDrawAllTangents, "Scene17", "result", "ptr:int32 OutValue") \
    X(Scene17SetSelTrajectoryDrawAllTangents, "Scene17", "result", "int32 draw") \
    X(Scene17GetSelTrajectoryDrawFrameTicks, "Scene17", "result", "ptr:int32 OutValue") \
    X(Scene17SetSelTrajectoryDrawFrameTicks, "Scene17", "result", "int32 draw") \
    X(Scene17GetSelTrajectoryDrawGradientTicks, "Scene17", "result", "ptr:int32 OutValue") \
    X(Scene17SetSelTrajectoryDrawGradientTicks, "Scene17", "result", "int32 draw") \
    X(Scene17GetTrajectoryDrawKeyTimes, "Scene17", "result", "ptr:int32 OutValue") \
    X(Scene17SetTrajectoryDrawKeyTimes, "Scene17", "result", "int32 draw") \
    X(Scene17GetSelTrajectoryDrawKeys, "Scene17", "result", "ptr:int32 OutValue") \
    X(Scene17SetSelTrajectoryDrawKeys, "Scene17", "result", "int32 draw") \
    X(Scene17UpdateSceneMaterialLib, "Scene17", "result", "") \
    X(Scene17SetRendFormatToCustom, "Scene17", "result", "") \
    X(Scene17IsValidSaveAsVersion, "Scene17", "result", "int32 saveAsVersion, ptr:int32 OutValue") \
    X(Scene17EnableViewportStatisticsRefresh, "Scene17", "result", "int32 enable") \
    X(Scene17RefreshViewportStatistics, "Scene17", "result", "") \
    X(Scene17EnableViewportStatistics, "Scene17", "result", "int32 enable") \
    X(Scene17GlobalScaleTime, "Scene17", "result", "cptr:MaxMcpInterval oldSegment, cptr:MaxMcpInterval newSegment, int32 modifyTimeline, int32 scaleToWholeFrames") \
    X(Scene17UpdateOsnapDlg, "Scene17", "result", "") \
    X(Scene17SetASnapStatus, "Scene17", "result", "int32 enable") \
    X(Scene17SetPSnapStatus, "Scene17", "result", "int32 enable") \
    X(Scene17GetSceneFileUserName, "Scene17", "result", "ptr:MaxMcpStrOut OutValue") \
    X(Scene17SetSceneFileUserName, "Scene17", "result", "cstr name, int32 persist") \
    X(Scene17GetSceneFileComputerName, "Scene17", "result", "ptr:MaxMcpStrOut OutValue") \
    X(Scene17SetSceneFileComputerName, "Scene17", "result", "cstr name, int32 persist") \
    X(BaseObjectGetObjectDisplayRequirement, "Base", "result", "anim Object, ptr:uint32 OutValue") \
    X(BaseObjectSetExtendedDisplay, "Base", "result", "anim Object, int32 flags") \
    X(BaseObjectGetObjectName, "Base", "result", "anim Object, int32 localized, ptr:MaxMcpStrOut OutValue") \
    X(BaseObjectOKToChangeTopology, "Base", "result", "anim Object, ptr:MaxMcpStrOut modName, ptr:int32 OutValue") \
    X(BaseObjectChangeTopology, "Base", "result", "anim Object, ptr:int32 OutValue") \
    X(BaseObjectForceNotify, "Base", "result", "anim Object, ptr:MaxMcpInterval i") \
    X(BaseObjectMove, "Base", "result", "anim Object, int32 t, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, ptr:MaxMcpPoint3 val, int32 localOrigin") \
    X(BaseObjectRotate, "Base", "result", "anim Object, int32 t, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, ptr:MaxMcpQuat val, int32 localOrigin") \
    X(BaseObjectScale, "Base", "result", "anim Object, int32 t, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, ptr:MaxMcpPoint3 val, int32 localOrigin") \
    X(BaseObjectTransformStart, "Base", "result", "anim Object, int32 t") \
    X(BaseObjectTransformHoldingStart, "Base", "result", "anim Object, int32 t") \
    X(BaseObjectTransformHoldingFinish, "Base", "result", "anim Object, int32 t") \
    X(BaseObjectTransformFinish, "Base", "result", "anim Object, int32 t") \
    X(BaseObjectTransformCancel, "Base", "result", "anim Object, int32 t") \
    X(BaseObjectCloneSelSubComponents, "Base", "result", "anim Object, int32 t") \
    X(BaseObjectAcceptCloneSelSubComponents, "Base", "result", "anim Object, int32 t") \
    X(BaseObjectClearSelection, "Base", "result", "anim Object, int32 selLevel") \
    X(BaseObjectSelectAll, "Base", "result", "anim Object, int32 selLevel") \
    X(BaseObjectInvertSelection, "Base", "result", "anim Object, int32 selLevel") \
    X(BaseObjectActivateSubSelSet, "Base", "result", "anim Object, ptr:MaxMcpStrOut setName") \
    X(BaseObjectNewSetFromCurSel, "Base", "result", "anim Object, ptr:MaxMcpStrOut setName") \
    X(BaseObjectRemoveSubSelSet, "Base", "result", "anim Object, ptr:MaxMcpStrOut setName") \
    X(BaseObjectSetupNamedSelDropDown, "Base", "result", "anim Object") \
    X(BaseObjectNumNamedSelSets, "Base", "result", "anim Object, ptr:int32 OutValue") \
    X(BaseObjectGetNamedSelSetName, "Base", "result", "anim Object, int32 i, ptr:MaxMcpStrOut OutValue") \
    X(BaseObjectSetNamedSelSetName, "Base", "result", "anim Object, int32 i, ptr:MaxMcpStrOut newName") \
    X(BaseObjectNumSubObjTypes, "Base", "result", "anim Object, ptr:int32 OutValue") \
    X(BaseObjectGetSubObjectLevel, "Base", "result", "anim Object, ptr:int32 OutValue") \
    X(BaseObjectHasUVW, "Base", "result", "anim Object, ptr:int32 OutValue") \
    X(BaseObjectSetGenUVW, "Base", "result", "anim Object, int32 sw") \
    X(BaseObjectShowEndResultChanged, "Base", "result", "anim Object, int32 showEndResult") \
    X(BaseObjectHasViewDependentBoundingBox, "Base", "result", "anim Object, ptr:int32 OutValue") \
    X(GenLightType, "Gen", "result", "anim Object, ptr:int32 OutValue") \
    X(GenLightSetType, "Gen", "result", "anim Object, int32 tp") \
    X(GenLightIsSpot, "Gen", "result", "anim Object, ptr:int32 OutValue") \
    X(GenLightIsDir, "Gen", "result", "anim Object, ptr:int32 OutValue") \
    X(GenLightSetSpotShape, "Gen", "result", "anim Object, int32 s") \
    X(GenLightGetSpotShape, "Gen", "result", "anim Object, ptr:int32 OutValue") \
    X(GenLightSetHSVColor, "Gen", "result", "anim Object, int32 t, ptr:MaxMcpPoint3 hsv") \
    X(GenLightGetHSVColor, "Gen", "result", "anim Object, int32 t, ptr:MaxMcpInterval valid, ptr:MaxMcpPoint3 OutValue") \
    X(GenLightSetContrast, "Gen", "result", "anim Object, int32 time, float f") \
    X(GenLightGetContrast, "Gen", "result", "anim Object, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(GenLightSetUseAttenNear, "Gen", "result", "anim Object, int32 s") \
    X(GenLightGetUseAttenNear, "Gen", "result", "anim Object, ptr:int32 OutValue") \
    X(GenLightSetAttenNearDisplay, "Gen", "result", "anim Object, int32 s") \
    X(GenLightGetAttenNearDisplay, "Gen", "result", "anim Object, ptr:int32 OutValue") \
    X(GenLightSetAtmosShadows, "Gen", "result", "anim Object, int32 t, int32 onOff") \
    X(GenLightGetAtmosShadows, "Gen", "result", "anim Object, int32 t, ptr:int32 OutValue") \
    X(GenLightSetAtmosOpacity, "Gen", "result", "anim Object, int32 t, float f") \
    X(GenLightGetAtmosOpacity, "Gen", "result", "anim Object, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(GenLightSetAtmosColAmt, "Gen", "result", "anim Object, int32 t, float f") \
    X(GenLightGetAtmosColAmt, "Gen", "result", "anim Object, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(GenLightSetUseShadowColorMap, "Gen", "result", "anim Object, int32 t, int32 onOff") \
    X(GenLightGetHotSpotControl, "Gen", "result", "anim Object, ptr:anim OutValue") \
    X(GenLightGetFalloffControl, "Gen", "result", "anim Object, ptr:anim OutValue") \
    X(GenLightGetColorControl, "Gen", "result", "anim Object, ptr:anim OutValue") \
    X(GenLightSetAffectDiffuse, "Gen", "result", "anim Object, int32 onOff") \
    X(GenLightGetAffectDiffuse, "Gen", "result", "anim Object, ptr:int32 OutValue") \
    X(GenLightSetAffectSpecular, "Gen", "result", "anim Object, int32 onOff") \
    X(GenLightGetAffectSpecular, "Gen", "result", "anim Object, ptr:int32 OutValue") \
    X(GenLightSetDecayType, "Gen", "result", "anim Object, int32 onOff") \
    X(GenLightGetDecayType, "Gen", "result", "anim Object, ptr:int32 OutValue") \
    X(GenLightSetDecayRadius, "Gen", "result", "anim Object, int32 time, float f") \
    X(GenLightGetDecayRadius, "Gen", "result", "anim Object, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(GenLightSetDiffuseSoft, "Gen", "result", "anim Object, int32 time, float f") \
    X(GenLightGetDiffuseSoft, "Gen", "result", "anim Object, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(GenLightSetShadColor, "Gen", "result", "anim Object, int32 t, cptr:MaxMcpPoint3 rgb") \
    X(GenLightGetShadColor, "Gen", "result", "anim Object, int32 t, ptr:MaxMcpInterval valid, ptr:MaxMcpPoint3 OutValue") \
    X(GenLightGetLightAffectsShadow, "Gen", "result", "anim Object, ptr:int32 OutValue") \
    X(GenLightSetLightAffectsShadow, "Gen", "result", "anim Object, int32 b") \
    X(GenLightSetShadMult, "Gen", "result", "anim Object, int32 t, float m") \
    X(GenLightGetShadMult, "Gen", "result", "anim Object, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(GenLightGetShadowProjMap, "Gen", "result", "anim Object, ptr:anim OutValue") \
    X(GenLightSetAmbientOnly, "Gen", "result", "anim Object, int32 onOff") \
    X(GenLightGetAmbientOnly, "Gen", "result", "anim Object, ptr:int32 OutValue") \
    X(LightObjSetUseLight, "Light", "result", "anim Object, int32 onOff") \
    X(LightObjGetUseLight, "Light", "result", "anim Object, ptr:int32 OutValue") \
    X(LightObjSetHotspot, "Light", "result", "anim Object, int32 time, float f") \
    X(LightObjGetHotspot, "Light", "result", "anim Object, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(LightObjSetFallsize, "Light", "result", "anim Object, int32 time, float f") \
    X(LightObjGetFallsize, "Light", "result", "anim Object, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(LightObjSetAtten, "Light", "result", "anim Object, int32 time, int32 which, float f") \
    X(LightObjGetAtten, "Light", "result", "anim Object, int32 t, int32 which, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(LightObjSetConeDisplay, "Light", "result", "anim Object, int32 s, int32 notify") \
    X(LightObjGetConeDisplay, "Light", "result", "anim Object, ptr:int32 OutValue") \
    X(LightObjGetShadowMethod, "Light", "result", "anim Object, ptr:int32 OutValue") \
    X(LightObjSetRGBColor, "Light", "result", "anim Object, int32 t, cptr:MaxMcpPoint3 rgb") \
    X(LightObjGetRGBColor, "Light", "result", "anim Object, int32 t, ptr:MaxMcpInterval valid, ptr:MaxMcpPoint3 OutValue") \
    X(LightObjSetIntensity, "Light", "result", "anim Object, int32 time, float f") \
    X(LightObjGetIntensity, "Light", "result", "anim Object, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(LightObjSetAspect, "Light", "result", "anim Object, int32 t, float f") \
    X(LightObjGetAspect, "Light", "result", "anim Object, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(LightObjSetUseAtten, "Light", "result", "anim Object, int32 s") \
    X(LightObjGetUseAtten, "Light", "result", "anim Object, ptr:int32 OutValue") \
    X(LightObjSetAttenDisplay, "Light", "result", "anim Object, int32 s") \
    X(LightObjGetAttenDisplay, "Light", "result", "anim Object, ptr:int32 OutValue") \
    X(LightObjEnable, "Light", "result", "anim Object, int32 enab") \
    X(LightObjSetMapBias, "Light", "result", "anim Object, int32 t, float f") \
    X(LightObjGetMapBias, "Light", "result", "anim Object, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(LightObjSetMapRange, "Light", "result", "anim Object, int32 t, float f") \
    X(LightObjGetMapRange, "Light", "result", "anim Object, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(LightObjSetMapSize, "Light", "result", "anim Object, int32 t, int32 f") \
    X(LightObjGetMapSize, "Light", "result", "anim Object, int32 t, ptr:MaxMcpInterval valid, ptr:int32 OutValue") \
    X(LightObjSetRayBias, "Light", "result", "anim Object, int32 t, float f") \
    X(LightObjGetRayBias, "Light", "result", "anim Object, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(LightObjGetUseGlobal, "Light", "result", "anim Object, ptr:int32 OutValue") \
    X(LightObjSetUseGlobal, "Light", "result", "anim Object, int32 a") \
    X(LightObjGetShadow, "Light", "result", "anim Object, ptr:int32 OutValue") \
    X(LightObjSetShadow, "Light", "result", "anim Object, int32 a") \
    X(LightObjGetShadowType, "Light", "result", "anim Object, ptr:int32 OutValue") \
    X(LightObjSetShadowType, "Light", "result", "anim Object, int32 a") \
    X(LightObjGetAbsMapBias, "Light", "result", "anim Object, ptr:int32 OutValue") \
    X(LightObjSetAbsMapBias, "Light", "result", "anim Object, int32 a") \
    X(LightObjGetOvershoot, "Light", "result", "anim Object, ptr:int32 OutValue") \
    X(LightObjSetOvershoot, "Light", "result", "anim Object, int32 a") \
    X(LightObjGetProjector, "Light", "result", "anim Object, ptr:int32 OutValue") \
    X(LightObjSetProjector, "Light", "result", "anim Object, int32 a") \
    X(LightObjInclude, "Light", "result", "anim Object, ptr:int32 OutValue") \
    X(LightObjGetProjMap, "Light", "result", "anim Object, ptr:anim OutValue") \
    X(StdMatSetSoften, "Std", "result", "anim Object, int32 onoff") \
    X(StdMatSetFaceMap, "Std", "result", "anim Object, int32 onoff") \
    X(StdMatSetTwoSided, "Std", "result", "anim Object, int32 onoff") \
    X(StdMatSetWire, "Std", "result", "anim Object, int32 onoff") \
    X(StdMatSetWireUnits, "Std", "result", "anim Object, int32 onOff") \
    X(StdMatSetFalloffOut, "Std", "result", "anim Object, int32 onOff") \
    X(StdMatSetTransparencyType, "Std", "result", "anim Object, int32 type") \
    X(StdMatSetAmbient, "Std", "result", "anim Object, cptr:MaxMcpColor c, int32 t") \
    X(StdMatSetDiffuse, "Std", "result", "anim Object, cptr:MaxMcpColor c, int32 t") \
    X(StdMatSetSpecular, "Std", "result", "anim Object, cptr:MaxMcpColor c, int32 t") \
    X(StdMatSetFilter, "Std", "result", "anim Object, cptr:MaxMcpColor c, int32 t") \
    X(StdMatSetShininess, "Std", "result", "anim Object, float v, int32 t") \
    X(StdMatSetShinStr, "Std", "result", "anim Object, float v, int32 t") \
    X(StdMatSetSelfIllum, "Std", "result", "anim Object, float v, int32 t") \
    X(StdMatSetOpacity, "Std", "result", "anim Object, float v, int32 t") \
    X(StdMatSetOpacFalloff, "Std", "result", "anim Object, float v, int32 t") \
    X(StdMatSetWireSize, "Std", "result", "anim Object, float s, int32 t") \
    X(StdMatSetIOR, "Std", "result", "anim Object, float v, int32 t") \
    X(StdMatLockAmbDiffTex, "Std", "result", "anim Object, int32 onOff") \
    X(StdMatSetSamplingOn, "Std", "result", "anim Object, int32 on") \
    X(StdMatSetShading, "Std", "result", "anim Object, int32 s") \
    X(StdMatGetSamplingOn, "Std", "result", "anim Object, ptr:int32 OutValue") \
    X(StdMatGetShading, "Std", "result", "anim Object, ptr:int32 OutValue") \
    X(StdMatEnableMap, "Std", "result", "anim Object, int32 id, int32 onoff") \
    X(StdMatMapEnabled, "Std", "result", "anim Object, int32 id, ptr:int32 OutValue") \
    X(StdMatSetTexmapAmt, "Std", "result", "anim Object, int32 id, float amt, int32 t") \
    X(StdMatGetTexmapAmt, "Std", "result", "anim Object, int32 id, int32 t, ptr:float OutValue") \
    X(StdMatGetSoften, "Std", "result", "anim Object, ptr:int32 OutValue") \
    X(StdMatGetFaceMap, "Std", "result", "anim Object, ptr:int32 OutValue") \
    X(StdMatGetTwoSided, "Std", "result", "anim Object, ptr:int32 OutValue") \
    X(StdMatGetWire, "Std", "result", "anim Object, ptr:int32 OutValue") \
    X(StdMatGetWireUnits, "Std", "result", "anim Object, ptr:int32 OutValue") \
    X(StdMatGetFalloffOut, "Std", "result", "anim Object, ptr:int32 OutValue") \
    X(StdMatGetTransparencyType, "Std", "result", "anim Object, ptr:int32 OutValue") \
    X(StdMatGetAmbient, "Std", "result", "anim Object, int32 t, ptr:MaxMcpColor OutValue") \
    X(StdMatGetDiffuse, "Std", "result", "anim Object, int32 t, ptr:MaxMcpColor OutValue") \
    X(StdMatGetSpecular, "Std", "result", "anim Object, int32 t, ptr:MaxMcpColor OutValue") \
    X(StdMatGetFilter, "Std", "result", "anim Object, int32 t, ptr:MaxMcpColor OutValue") \
    X(StdMatGetShininess, "Std", "result", "anim Object, int32 t, ptr:float OutValue") \
    X(StdMatGetShinStr, "Std", "result", "anim Object, int32 t, ptr:float OutValue") \
    X(StdMatGetSelfIllum, "Std", "result", "anim Object, int32 t, ptr:float OutValue") \
    X(StdMatGetOpacity, "Std", "result", "anim Object, int32 t, ptr:float OutValue") \
    X(StdMatGetOpacFalloff, "Std", "result", "anim Object, int32 t, ptr:float OutValue") \
    X(StdMatGetWireSize, "Std", "result", "anim Object, int32 t, ptr:float OutValue") \
    X(StdMatGetIOR, "Std", "result", "anim Object, int32 t, ptr:float OutValue") \
    X(StdMatGetAmbDiffTexLock, "Std", "result", "anim Object, ptr:int32 OutValue") \
    X(ViewExpGetViewID, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExpIsAlive, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExpGetPointOnCP, "View", "result", "hwnd Win, cptr:MaxMcpIPoint2 ps, ptr:MaxMcpPoint3 OutValue") \
    X(ViewExpSnapLength, "View", "result", "hwnd Win, float in, ptr:float OutValue") \
    X(ViewExpGetCPDisp, "View", "result", "hwnd Win, cptr:MaxMcpPoint3 base, cptr:MaxMcpPoint3 dir, cptr:MaxMcpIPoint2 sp1, cptr:MaxMcpIPoint2 sp2, int32 snap, ptr:float OutValue") \
    X(ViewExpIsWire, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExpMapViewToScreen, "View", "result", "hwnd Win, cptr:MaxMcpPoint3 p, ptr:MaxMcpPoint2 OutValue") \
    X(ViewExpMapScreenToView, "View", "result", "hwnd Win, cptr:MaxMcpIPoint2 sp, float depth, ptr:MaxMcpPoint3 OutValue") \
    X(ViewExpSetAffineTM, "View", "result", "hwnd Win, cptr:MaxMcpMatrix3 m, ptr:int32 OutValue") \
    X(ViewExpGetAffineTM, "View", "result", "hwnd Win, ptr:MaxMcpMatrix3 tm") \
    X(ViewExpGetViewType, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExpIsPerspView, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExpIsCanvasNavigationMode, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExpGetFOV, "View", "result", "hwnd Win, ptr:float OutValue") \
    X(ViewExpGetFocalDist, "View", "result", "hwnd Win, ptr:float OutValue") \
    X(ViewExpSetFocalDist, "View", "result", "hwnd Win, float fd") \
    X(ViewExpGetFPS, "View", "result", "hwnd Win, ptr:float OutValue") \
    X(ViewExpGetScreenScaleFactor, "View", "result", "hwnd Win, cptr:MaxMcpPoint3 worldPoint, ptr:float OutValue") \
    X(ViewExpGetVPWorldWidth, "View", "result", "hwnd Win, cptr:MaxMcpPoint3 wPoint, ptr:float OutValue") \
    X(ViewExpNonScalingObjectSize, "View", "result", "hwnd Win, ptr:float OutValue") \
    X(ViewExpGetConstructionTM, "View", "result", "hwnd Win, ptr:MaxMcpMatrix3 tm") \
    X(ViewExpSetGridSize, "View", "result", "hwnd Win, float size") \
    X(ViewExpGetGridSize, "View", "result", "hwnd Win, ptr:float OutValue") \
    X(ViewExpIsGridVisible, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExpSetGridVisibility, "View", "result", "hwnd Win, int32 bVisible") \
    X(ViewExpGetGridType, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExpGetViewCamera, "View", "result", "hwnd Win, ptr:node OutValue") \
    X(ViewExpSetViewUser, "View", "result", "hwnd Win, int32 persp") \
    X(ViewExpGetViewSpot, "View", "result", "hwnd Win, ptr:node OutValue") \
    X(ViewExpClearHitList, "View", "result", "hwnd Win") \
    X(ViewExpGetClosestHit, "View", "result", "hwnd Win, ptr:node OutValue") \
    X(ViewExpGetHit, "View", "result", "hwnd Win, int32 i, ptr:node OutValue") \
    X(ViewExpHitCount, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExpClearSubObjHitList, "View", "result", "hwnd Win") \
    X(ViewExpNumSubObjHits, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExpClearCtrlHitList, "View", "result", "hwnd Win") \
    X(ViewExpSetBkgImageDsp, "View", "result", "hwnd Win, int32 onOff, ptr:int32 OutValue") \
    X(ViewExpGetBkgImageDsp, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExpSetSFDisplay, "View", "result", "hwnd Win, int32 onOff") \
    X(ViewExpGetSFDisplay, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExpGetHWnd, "View", "result", "hwnd Win, ptr:hwnd OutValue") \
    X(ViewExpIsActive, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExpIsEnabled, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExpSetSolidBackgroundColorMode, "View", "result", "hwnd Win, int32 bSolidColor") \
    X(ViewExpIsSolidBackgroundColorMode, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExpResetBackgroundColorMode, "View", "result", "hwnd Win") \
    X(ViewExpReleaseImplicitGrid, "View", "result", "hwnd Win") \
    X(ViewExp10Pan, "View", "result", "hwnd Win, cptr:MaxMcpPoint2 screenDelta") \
    X(ViewExp10Zoom, "View", "result", "hwnd Win, float zoomFactor") \
    X(ViewExp10Rotate, "View", "result", "hwnd Win, cptr:MaxMcpQuat rotData, cptr:MaxMcpPoint3 center") \
    X(ViewExp10SetFocalDistance, "View", "result", "hwnd Win, float dist") \
    X(ViewExp10Invalidate, "View", "result", "hwnd Win, int32 bForegroundOnly") \
    X(ViewExp10IsValid, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExp10SetFOV, "View", "result", "hwnd Win, float fov, ptr:int32 OutValue") \
    X(ViewExp10GetViewportFPS, "View", "result", "hwnd Win, ptr:float OutValue") \
    X(ViewExp10GetViewportClipScale, "View", "result", "hwnd Win, ptr:float OutValue") \
    X(ViewExp10SetViewportClipScale, "View", "result", "hwnd Win, float fScale") \
    X(ViewExp10GetAdaptiveDegGoalFPS, "View", "result", "hwnd Win, ptr:float OutValue") \
    X(ViewExp10SetAdaptiveDegGoalFPS, "View", "result", "hwnd Win, float fFPS") \
    X(ViewExp10GetAdaptiveDegDisplayModeCurrent, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExp10SetAdaptiveDegDisplayModeCurrent, "View", "result", "hwnd Win, int32 bMode") \
    X(ViewExp10GetAdaptiveDegDisplayModeFastShaded, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExp10SetAdaptiveDegDisplayModeFastShaded, "View", "result", "hwnd Win, int32 bMode") \
    X(ViewExp10GetAdaptiveDegDisplayModeWire, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExp10SetAdaptiveDegDisplayModeWire, "View", "result", "hwnd Win, int32 bMode") \
    X(ViewExp10GetAdaptiveDegDisplayModeBox, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExp10SetAdaptiveDegDisplayModeBox, "View", "result", "hwnd Win, int32 bMode") \
    X(ViewExp10GetAdaptiveDegDisplayModePoint, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExp10SetAdaptiveDegDisplayModePoint, "View", "result", "hwnd Win, int32 bMode") \
    X(ViewExp10GetAdaptiveDegDisplayModeHide, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExp10SetAdaptiveDegDisplayModeHide, "View", "result", "hwnd Win, int32 bMode") \
    X(ViewExp10GetAdaptiveDegDrawBackface, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExp10SetAdaptiveDegDrawBackface, "View", "result", "hwnd Win, int32 bDraw") \
    X(ViewExp10GetAdaptiveDegNeverDegradeSelected, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExp10SetAdaptiveDegNeverDegradeSelected, "View", "result", "hwnd Win, int32 bNeverDegrade") \
    X(ViewExp10GetAdaptiveDegDegradeLight, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExp10SetAdaptiveDegDegradeLight, "View", "result", "hwnd Win, int32 bDegradeLight") \
    X(ViewExp10GetAdaptiveDegNeverRedrawAfterDegrade, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExp10SetAdaptiveDegNeverRedrawAfterDegrade, "View", "result", "hwnd Win, int32 bNeverRedraw") \
    X(ViewExp10GetAdaptiveDegCameraDistancePriority, "View", "result", "hwnd Win, ptr:float OutValue") \
    X(ViewExp10SetAdaptiveDegCameraDistancePriority, "View", "result", "hwnd Win, float fPriority") \
    X(ViewExp10GetAdaptiveDegScreenSizePriority, "View", "result", "hwnd Win, ptr:float OutValue") \
    X(ViewExp10SetAdaptiveDegScreenSizePriority, "View", "result", "hwnd Win, float fPriority") \
    X(ViewExp10GetAdaptiveDegMinSize, "View", "result", "hwnd Win, ptr:int32 OutValue") \
    X(ViewExp10SetAdaptiveDegMinSize, "View", "result", "hwnd Win, int32 iMinSize") \
    X(ITrackBarSetVisible, "ITrack", "result", "int32 bVisible") \
    X(ITrackBarIsVisible, "ITrack", "result", "ptr:int32 OutValue") \
    X(ITrackBarSetFilter, "ITrack", "result", "uint32 nFilter") \
    X(ITrackBarGetFilter, "ITrack", "result", "ptr:uint32 OutValue") \
    X(ITrackBarGetNextKey, "ITrack", "result", "int32 tStart, int32 bForward, ptr:int32 OutValue") \
    X(ITrackBarRedrawTrackBar, "ITrack", "result", "int32 bForce") \
    X(ITrackBarSetShowFrames, "ITrack", "result", "int32 b") \
    X(ITrackBarGetShowFrames, "ITrack", "result", "ptr:int32 OutValue") \
    X(ITrackBarSetShowAudio, "ITrack", "result", "int32 b") \
    X(ITrackBarGetShowAudio, "ITrack", "result", "ptr:int32 OutValue") \
    X(ITrackBarSetShowSelectionRange, "ITrack", "result", "int32 b") \
    X(ITrackBarGetShowSelectionRange, "ITrack", "result", "ptr:int32 OutValue") \
    X(ITrackBarSetSnapToFrames, "ITrack", "result", "int32 b") \
    X(ITrackBarGetSnapToFrames, "ITrack", "result", "ptr:int32 OutValue") \
    X(ITrackBarSetKeyTransparency, "ITrack", "result", "int32 xp") \
    X(ITrackBarGetKeyTransparency, "ITrack", "result", "ptr:int32 OutValue") \
    X(ITrackBarSetSelKeyTransparency, "ITrack", "result", "int32 xp") \
    X(ITrackBarGetSelKeyTransparency, "ITrack", "result", "ptr:int32 OutValue") \
    X(ITrackBarSetCursorTransparency, "ITrack", "result", "int32 xp") \
    X(ITrackBarGetCursorTransparency, "ITrack", "result", "ptr:int32 OutValue") \
    X(EPolyModGetEPolySelLevel, "EPoly", "result", "anim Mod, ptr:int32 OutValue") \
    X(EPolyModGetMNSelLevel, "EPoly", "result", "anim Mod, ptr:int32 OutValue") \
    X(EPolyModSetEPolySelLevel, "EPoly", "result", "anim Mod, int32 sl") \
    X(EPolyModEpModConvertSelection, "EPoly", "result", "anim Mod, int32 epSelLevelFrom, int32 epSelLevelTo, int32 requireAll, ptr:int32 OutValue") \
    X(EPolyModGetPolyOperationID, "EPoly", "result", "anim Mod, ptr:int32 OutValue") \
    X(EPolyModEpModSetPreserveMap, "EPoly", "result", "anim Mod, int32 mapChannel, int32 preserve") \
    X(EPolyModEpModGetPreserveMap, "EPoly", "result", "anim Mod, int32 mapChannel, ptr:int32 OutValue") \
    X(EPolyModInvalidateDistanceCache, "EPoly", "result", "anim Mod") \
    X(EPolyModInvalidateSoftSelectionCache, "EPoly", "result", "anim Mod") \
    X(EPolyModEpModSetOperation, "EPoly", "result", "anim Mod, int32 opcode") \
    X(EPolyModEpModPopupDialog, "EPoly", "result", "anim Mod, int32 opcode") \
    X(EPolyModEpModButtonOp, "EPoly", "result", "anim Mod, int32 opcode") \
    X(EPolyModEpModRefreshScreen, "EPoly", "result", "anim Mod") \
    X(EPolyModEpModCommitUnlessAnimating, "EPoly", "result", "anim Mod, int32 t") \
    X(EPolyModEpModCommit, "EPoly", "result", "anim Mod, int32 t") \
    X(EPolyModEpModCommitAndRepeat, "EPoly", "result", "anim Mod, int32 t") \
    X(EPolyModEpModCancel, "EPoly", "result", "anim Mod") \
    X(EPolyModEpModToggleCommandMode, "EPoly", "result", "anim Mod, int32 mode") \
    X(EPolyModEpModEnterCommandMode, "EPoly", "result", "anim Mod, int32 mode") \
    X(EPolyModEpModEnterPickMode, "EPoly", "result", "anim Mod, int32 mode") \
    X(EPolyModEpModGetCommandMode, "EPoly", "result", "anim Mod, ptr:int32 OutValue") \
    X(EPolyModEpModGetPickMode, "EPoly", "result", "anim Mod, ptr:int32 OutValue") \
    X(EPolyModSetHitLevelOverride, "EPoly", "result", "anim Mod, uint32 hlo") \
    X(EPolyModClearHitLevelOverride, "EPoly", "result", "anim Mod") \
    X(EPolyModGetHitLevelOverride, "EPoly", "result", "anim Mod, ptr:uint32 OutValue") \
    X(EPolyModSetHitTestResult, "EPoly", "result", "anim Mod, int32 ignoreNew") \
    X(EPolyModClearHitTestResult, "EPoly", "result", "anim Mod") \
    X(EPolyModSetDisplayLevelOverride, "EPoly", "result", "anim Mod, uint32 dlo") \
    X(EPolyModClearDisplayLevelOverride, "EPoly", "result", "anim Mod") \
    X(EPolyModGetDisplayLevelOverride, "EPoly", "result", "anim Mod, ptr:uint32 OutValue") \
    X(EPolyModForceIgnoreBackfacing, "EPoly", "result", "anim Mod, int32 force") \
    X(EPolyModGetForceIgnoreBackfacing, "EPoly", "result", "anim Mod, ptr:int32 OutValue") \
    X(EPolyModEpModMoveSelection, "EPoly", "result", "anim Mod, ptr:MaxMcpPoint3 val, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, int32 localOrigin, int32 t") \
    X(EPolyModEpModRotateSelection, "EPoly", "result", "anim Mod, ptr:MaxMcpQuat val, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, int32 localOrigin, int32 t") \
    X(EPolyModEpModScaleSelection, "EPoly", "result", "anim Mod, ptr:MaxMcpPoint3 val, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, int32 localOrigin, int32 t") \
    X(EPolyModEpModMoveSlicePlane, "EPoly", "result", "anim Mod, ptr:MaxMcpPoint3 val, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, int32 t") \
    X(EPolyModEpModRotateSlicePlane, "EPoly", "result", "anim Mod, ptr:MaxMcpQuat val, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, int32 localOrigin, int32 t") \
    X(EPolyModEpModScaleSlicePlane, "EPoly", "result", "anim Mod, ptr:MaxMcpPoint3 val, ptr:MaxMcpMatrix3 partm, ptr:MaxMcpMatrix3 tmAxis, int32 localOrigin, int32 t") \
    X(EPolyModEpResetSlicePlane, "EPoly", "result", "anim Mod") \
    X(EPolyModEpGetSlicePlaneTM, "EPoly", "result", "anim Mod, int32 t, ptr:MaxMcpMatrix3 OutValue") \
    X(EPolyModEpGetSlicePlane, "EPoly", "result", "anim Mod, ptr:MaxMcpPoint3 planeNormal, ptr:MaxMcpPoint3 planeCenter, int32 t") \
    X(EPolyModEpSetSlicePlane, "EPoly", "result", "anim Mod, ptr:MaxMcpPoint3 planeNormal, ptr:MaxMcpPoint3 planeCenter, int32 t") \
    X(EPolyModEpInSliceMode, "EPoly", "result", "anim Mod, ptr:int32 OutValue") \
    X(EPolyModEpInSlice, "EPoly", "result", "anim Mod, ptr:int32 OutValue") \
    X(EPolyModGetModifier, "EPoly", "result", "anim Mod, ptr:anim OutValue") \
    X(EPolyModUpdateAlignParameters, "EPoly", "result", "anim Mod, int32 t") \
    X(EPolyModUpdateCache, "EPoly", "result", "anim Mod, int32 t") \
    X(EPolyModEpModShowOperationDialog, "EPoly", "result", "anim Mod, ptr:int32 OutValue") \
    X(EPolyModEpModShowingOperationDialog, "EPoly", "result", "anim Mod, ptr:int32 OutValue") \
    X(EPolyModEpModCloseOperationDialog, "EPoly", "result", "anim Mod") \
    X(EPolyModEpModRepeatLast, "EPoly", "result", "anim Mod") \
    X(EPolyModEpModGetLastCutEnd, "EPoly", "result", "anim Mod, ptr:int32 OutValue") \
    X(EPolyModEpModClearLastCutEnd, "EPoly", "result", "anim Mod") \
    X(EPolyModEpModDetachToObject, "EPoly", "result", "anim Mod, ptr:MaxMcpStrOut newObjectName, int32 t") \
    X(EPolyModEpModCreateShape, "EPoly", "result", "anim Mod, ptr:MaxMcpStrOut shapeObjectName, int32 t") \
    X(EPolyModEpModSetRingShift, "EPoly", "result", "anim Mod, int32 in_newPos, int32 in_moveOnly, int32 in_add") \
    X(EPolyModEpModSetLoopShift, "EPoly", "result", "anim Mod, int32 in_newPos, int32 in_moveOnly, int32 in_add") \
    X(EPolyModEpModConvertSelectionToBorder, "EPoly", "result", "anim Mod, int32 in_epSelLevelFrom, int32 in_epSelLevelTo, ptr:int32 OutValue") \
    X(EPolyModEpModPaintDeformCommit, "EPoly", "result", "anim Mod") \
    X(EPolyModEpModPaintDeformCancel, "EPoly", "result", "anim Mod") \
    X(EPolyModSmGrpFloater, "EPoly", "result", "anim Mod") \
    X(EPolyModMatIDFloater, "EPoly", "result", "anim Mod") \
    X(EPolyModMatIDFloaterVisible, "EPoly", "result", "anim Mod, ptr:int32 OutValue") \
    X(EPolyModSmGrpFloaterVisible, "EPoly", "result", "anim Mod, ptr:int32 OutValue") \
    X(EPolyModCloseSmGrpFloater, "EPoly", "result", "anim Mod") \
    X(EPolyModCloseMatIDFloater, "EPoly", "result", "anim Mod") \
    X(EPolyModMatIDFloaterHWND, "EPoly", "result", "anim Mod, ptr:hwnd OutValue") \
    X(EPolyModSmGrpFloaterHWND, "EPoly", "result", "anim Mod, ptr:hwnd OutValue") \
    X(EPolyModListDeltaOps, "EPoly", "result", "anim Mod") \
    X(EPolyModEpModGetLast, "EPoly", "result", "anim Mod, ptr:int32 OutValue") \
    X(IBipDriverSetTrackSelection, "IBip", "result", "anim Anim, int32 track") \
    X(IBipDriverGetTrackSelection, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSaveBipFileDlg, "IBip", "result", "anim Anim") \
    X(IBipDriverLoadBipFileDlg, "IBip", "result", "anim Anim") \
    X(IBipDriverBeginModes, "IBip", "result", "anim Anim, uint32 modes, int32 redraw") \
    X(IBipDriverEndModes, "IBip", "result", "anim Anim, uint32 modes, int32 redraw") \
    X(IBipDriverConvertToFreeForm, "IBip", "result", "anim Anim, int32 keyPerFrame") \
    X(IBipDriverConvertToFootSteps, "IBip", "result", "anim Anim, int32 keyPerFrame, int32 flattenToZ") \
    X(IBipDriverGetDisplaySettings, "IBip", "result", "anim Anim, ptr:uint32 OutValue") \
    X(IBipDriverSetDisplaySettings, "IBip", "result", "anim Anim, uint32 disp") \
    X(IBipDriverGetBodyType, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetBodyType, "IBip", "result", "anim Anim, int32 bodytype") \
    X(IBipDriverGetDynamicsType, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetDynamicsType, "IBip", "result", "anim Anim, int32 dyn") \
    X(IBipDriverGetGravAccel, "IBip", "result", "anim Anim, ptr:float OutValue") \
    X(IBipDriverSetGravAccel, "IBip", "result", "anim Anim, float grav") \
    X(IBipDriverGetRootName, "IBip", "result", "anim Anim, ptr:MaxMcpStrOut OutValue") \
    X(IBipDriverSetRootName, "IBip", "result", "anim Anim, cstr rootname, int32 incAll") \
    X(IBipDriverSetAdaptLocks, "IBip", "result", "anim Anim, int32 id, int32 onOff") \
    X(IBipDriverSeparateTracks, "IBip", "result", "anim Anim, int32 id, int32 separate") \
    X(IBipDriverSetBodySpaceNeckRotation, "IBip", "result", "anim Anim, int32 val") \
    X(IBipDriverGetBodySpaceNeckRotation, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverGetHasArms, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetHasArms, "IBip", "result", "anim Anim, int32 arms") \
    X(IBipDriverSetNumLinks, "IBip", "result", "anim Anim, int32 keytrack, int32 n") \
    X(IBipDriverGetNumFingers, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetNumFingers, "IBip", "result", "anim Anim, int32 n") \
    X(IBipDriverGetNumToes, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetNumToes, "IBip", "result", "anim Anim, int32 n") \
    X(IBipDriverGetAnkleAttach, "IBip", "result", "anim Anim, ptr:float OutValue") \
    X(IBipDriverSetAnkleAttach, "IBip", "result", "anim Anim, float aa") \
    X(IBipDriverGetHeight, "IBip", "result", "anim Anim, ptr:float OutValue") \
    X(IBipDriverSetHeight, "IBip", "result", "anim Anim, float h, int32 KeepFeetOnGround") \
    X(IBipDriverGetTrianglePelvis, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetTrianglePelvis, "IBip", "result", "anim Anim, int32 tri") \
    X(IBipDriverGetProp1Exists, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetProp1Exists, "IBip", "result", "anim Anim, int32 prop") \
    X(IBipDriverGetProp2Exists, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetProp2Exists, "IBip", "result", "anim Anim, int32 prop") \
    X(IBipDriverGetProp3Exists, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetProp3Exists, "IBip", "result", "anim Anim, int32 prop") \
    X(IBipDriverGetDispBuffer, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetDispBuffer, "IBip", "result", "anim Anim, int32 onOff") \
    X(IBipDriverGetDispBufferTraj, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetDispBufferTraj, "IBip", "result", "anim Anim, int32 onOff") \
    X(IBipDriverGetTalentFigMode, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetTalentFigMode, "IBip", "result", "anim Anim, int32 onOff") \
    X(IBipDriverAdjustTalentPose, "IBip", "result", "anim Anim") \
    X(IBipDriverSaveTalentFigFile, "IBip", "result", "anim Anim, cstr fname") \
    X(IBipDriverSaveTalentPoseFile, "IBip", "result", "anim Anim, cstr fname") \
    X(IBipDriverGetFSAppendState, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetFSAppendState, "IBip", "result", "anim Anim, int32 onOff") \
    X(IBipDriverGetFSInsertState, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetFSInsertState, "IBip", "result", "anim Anim, int32 onOff") \
    X(IBipDriverGetGaitMode, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetGaitMode, "IBip", "result", "anim Anim, int32 mode") \
    X(IBipDriverGetGroundDur, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetGroundDur, "IBip", "result", "anim Anim, int32 val") \
    X(IBipDriverGetAirDur, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetAirDur, "IBip", "result", "anim Anim, int32 val") \
    X(IBipDriverDoMultipleFSDlg, "IBip", "result", "anim Anim") \
    X(IBipDriverNewFprintKeys, "IBip", "result", "anim Anim") \
    X(IBipDriverBendFootprints, "IBip", "result", "anim Anim, float angle") \
    X(IBipDriverScaleFootprints, "IBip", "result", "anim Anim, float scale") \
    X(IBipDriverUnifyMotion, "IBip", "result", "anim Anim") \
    X(IBipDriverGetAttachNode, "IBip", "result", "anim Anim, ptr:node OutValue") \
    X(IBipDriverGetHeadTarget, "IBip", "result", "anim Anim, ptr:node OutValue") \
    X(IBipDriverSetMultipleKeys, "IBip", "result", "anim Anim") \
    X(IBipDriverDoSetMultipleKeysDlg, "IBip", "result", "anim Anim") \
    X(IBipDriverResetAllLimbKeys, "IBip", "result", "anim Anim") \
    X(IBipDriverCollapseMoveAllMode, "IBip", "result", "anim Anim, int32 msg") \
    X(IBipDriverCreateLayer, "IBip", "result", "anim Anim, int32 index, cstr name") \
    X(IBipDriverDeleteLayer, "IBip", "result", "anim Anim, int32 index") \
    X(IBipDriverSetLayerActive, "IBip", "result", "anim Anim, int32 index, int32 onOff") \
    X(IBipDriverSetLayerName, "IBip", "result", "anim Anim, int32 index, cstr name") \
    X(IBipDriverGetCurrentLayer, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetCurrentLayer, "IBip", "result", "anim Anim, int32 index") \
    X(IBipDriverUpdateLayers, "IBip", "result", "anim Anim") \
    X(IBipDriverGetVisibleBefore, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetVisibleBefore, "IBip", "result", "anim Anim, int32 val") \
    X(IBipDriverGetVisibleAfter, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetVisibleAfter, "IBip", "result", "anim Anim, int32 val") \
    X(IBipDriverGetKeyHighlight, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetKeyHighlight, "IBip", "result", "anim Anim, int32 onOff") \
    X(IBipDriverClearPreferredClips, "IBip", "result", "anim Anim") \
    X(IBipDriverGetEnableSubAnims, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetEnableSubAnims, "IBip", "result", "anim Anim, int32 onOff") \
    X(IBipDriverGetManipSubAnims, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetManipSubAnims, "IBip", "result", "anim Anim, int32 onOff") \
    X(IBipDriverGetShowAllTracksInTV, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetShowAllTracksInTV, "IBip", "result", "anim Anim, int32 onOff") \
    X(IBipDriverGetShowBipedInTrackBar, "IBip", "result", "anim Anim, ptr:int32 OutValue") \
    X(IBipDriverSetShowBipedInTrackBar, "IBip", "result", "anim Anim, int32 onOff") \
    X(IBipDriverMirror, "IBip", "result", "anim Anim") \
    X(IBipDriverClearAllAnimation, "IBip", "result", "anim Anim") \
    X(IBipDriverClearSelectedAnimation, "IBip", "result", "anim Anim") \
    X(IBipDriverCollapseAllPosSubAnims, "IBip", "result", "anim Anim, int32 perFrame, int32 keep") \
    X(IBipDriverCollapseAllRotSubAnims, "IBip", "result", "anim Anim, int32 perFrame, int32 keep") \
    X(IBipDriverCopyPosture, "IBip", "result", "anim Anim, int32 copyType, int32 copyHor, int32 copyVer, int32 copyTurn, ptr:MaxMcpStrOut OutValue") \
    X(IBipDriverDeleteAllCopies, "IBip", "result", "anim Anim, int32 copyType, int32 holdIt") \
    X(IBipDriverDeleteCopy, "IBip", "result", "anim Anim, int32 copyType, cstr name") \
    X(IBipDriverSetCopyName, "IBip", "result", "anim Anim, int32 copyType, int32 index, cstr newName") \
    X(LightscapeLightSetType, "Lightscape", "result", "anim Anim, int32 type") \
    X(LightscapeLightType, "Lightscape", "result", "anim Anim, ptr:int32 OutValue") \
    X(LightscapeLightTypeName, "Lightscape", "result", "anim Anim, ptr:MaxMcpStrOut OutValue") \
    X(LightscapeLightGetDistribution, "Lightscape", "result", "anim Anim, ptr:int32 OutValue") \
    X(LightscapeLightSetIntensityAt, "Lightscape", "result", "anim Anim, float f") \
    X(LightscapeLightGetIntensityAt, "Lightscape", "result", "anim Anim, ptr:float OutValue") \
    X(LightscapeLightGetIntensityType, "Lightscape", "result", "anim Anim, ptr:int32 OutValue") \
    X(LightscapeLightSetFlux, "Lightscape", "result", "anim Anim, int32 t, float flux") \
    X(LightscapeLightGetFlux, "Lightscape", "result", "anim Anim, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(LightscapeLightSetRGBFilter, "Lightscape", "result", "anim Anim, int32 t, cptr:MaxMcpPoint3 rgb") \
    X(LightscapeLightGetRGBFilter, "Lightscape", "result", "anim Anim, int32 t, ptr:MaxMcpInterval valid, ptr:MaxMcpPoint3 OutValue") \
    X(LightscapeLightSetHSVFilter, "Lightscape", "result", "anim Anim, int32 t, ptr:MaxMcpPoint3 hsv") \
    X(LightscapeLightGetHSVFilter, "Lightscape", "result", "anim Anim, int32 t, ptr:MaxMcpInterval valid, ptr:MaxMcpPoint3 OutValue") \
    X(LightscapeLightGetShadowGeneratorName, "Lightscape", "result", "anim Anim, ptr:MaxMcpStrOut OutValue") \
    X(LightscapeLightSetShadowGenerator, "Lightscape", "result", "anim Anim, cstr name") \
    X(LightscapeLightSetInclude, "Lightscape", "result", "anim Anim, int32 onOff") \
    X(LightscapeLightGetKelvinControl, "Lightscape", "result", "anim Anim, ptr:anim OutValue") \
    X(LightscapeLightGetFilterControl, "Lightscape", "result", "anim Anim, ptr:anim OutValue") \
    X(LightscapeLightGetKelvin, "Lightscape", "result", "anim Anim, int32 t, ptr:MaxMcpInterval v, ptr:float OutValue") \
    X(LightscapeLightSetKelvin, "Lightscape", "result", "anim Anim, int32 t, float kelvin") \
    X(LightscapeLightGetUseKelvin, "Lightscape", "result", "anim Anim, ptr:int32 OutValue") \
    X(LightscapeLightSetUseKelvin, "Lightscape", "result", "anim Anim, int32 useKelvin") \
    X(LightscapeLightGetFullWebFileName, "Lightscape", "result", "anim Anim, ptr:MaxMcpStrOut OutValue") \
    X(LightscapeLightGetWebRotateX, "Lightscape", "result", "anim Anim, ptr:float OutValue") \
    X(LightscapeLightSetWebRotateX, "Lightscape", "result", "anim Anim, float degrees") \
    X(LightscapeLightGetWebRotateY, "Lightscape", "result", "anim Anim, ptr:float OutValue") \
    X(LightscapeLightSetWebRotateY, "Lightscape", "result", "anim Anim, float degrees") \
    X(LightscapeLightGetWebRotateZ, "Lightscape", "result", "anim Anim, ptr:float OutValue") \
    X(LightscapeLightSetWebRotateZ, "Lightscape", "result", "anim Anim, float degrees") \
    X(LightscapeLightGetDimmerValue, "Lightscape", "result", "anim Anim, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(LightscapeLightSetDimmerValue, "Lightscape", "result", "anim Anim, int32 t, float dimmer") \
    X(LightscapeLightGetUseMultiplier, "Lightscape", "result", "anim Anim, ptr:int32 OutValue") \
    X(LightscapeLightSetUseMultiplier, "Lightscape", "result", "anim Anim, int32 on") \
    X(LightscapeLightIsColorShiftEnabled, "Lightscape", "result", "anim Anim, ptr:int32 OutValue") \
    X(LightscapeLightEnableColorShift, "Lightscape", "result", "anim Anim, int32 on") \
    X(LightscapeLightGetResultingIntensity, "Lightscape", "result", "anim Anim, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(LightscapeLightGetResultingFlux, "Lightscape", "result", "anim Anim, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(LightscapeLightGetCenter, "Lightscape", "result", "anim Anim, ptr:MaxMcpPoint3 OutValue") \
    X(LightscapeLightGetRadius, "Lightscape", "result", "anim Anim, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(LightscapeLightSetRadius, "Lightscape", "result", "anim Anim, int32 t, float radius") \
    X(LightscapeLightGetLength, "Lightscape", "result", "anim Anim, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(LightscapeLightSetLength, "Lightscape", "result", "anim Anim, int32 t, float length") \
    X(LightscapeLightGetWidth, "Lightscape", "result", "anim Anim, int32 t, ptr:MaxMcpInterval valid, ptr:float OutValue") \
    X(LightscapeLightSetWidth, "Lightscape", "result", "anim Anim, int32 t, float width") \
    X(LightscapeLightGetOriginalFlux, "Lightscape", "result", "anim Anim, ptr:float OutValue") \
    X(LightscapeLightSetOriginalFlux, "Lightscape", "result", "anim Anim, float flux") \
    X(LightscapeLightGetOriginalIntensity, "Lightscape", "result", "anim Anim, ptr:float OutValue") \
    X(LightscapeLightSetOriginalIntensity, "Lightscape", "result", "anim Anim, float candelas") \
    X(LightscapeLightGetColorPreset, "Lightscape", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterInPaintMode, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterClearStroke, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterAddToStroke, "Painter", "result", "anim Anim, cptr:MaxMcpIPoint2 mousePos, int32 rebuildPointGatherData, int32 updateViewport, ptr:int32 OutValue") \
    X(PainterGetStrokeCount, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterGetStrFromPoint, "Painter", "result", "anim Anim, cptr:MaxMcpPoint3 point, ptr:float OutValue") \
    X(PainterGetBuildNormalData, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterSetBuildNormalData, "Painter", "result", "anim Anim, int32 enable") \
    X(PainterGetEnablePointGather, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterSetEnablePointGather, "Painter", "result", "anim Anim, int32 enable") \
    X(PainterGetMirrorEnable, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterSetMirrorEnable, "Painter", "result", "anim Anim, int32 enable") \
    X(PainterGetMirrorPlaneCenter, "Painter", "result", "anim Anim, ptr:MaxMcpPoint3 OutValue") \
    X(PainterGetMirrorAxis, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterSetMirrorAxis, "Painter", "result", "anim Anim, int32 dir") \
    X(PainterGetMirrorOffset, "Painter", "result", "anim Anim, ptr:float OutValue") \
    X(PainterSetMirrorOffset, "Painter", "result", "anim Anim, float offset") \
    X(PainterGetTreeDepth, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterSetTreeDepth, "Painter", "result", "anim Anim, int32 depth") \
    X(PainterGetUpdateOnMouseUp, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterSetUpdateOnMouseUp, "Painter", "result", "anim Anim, int32 update") \
    X(PainterGetLagRate, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterSetLagRate, "Painter", "result", "anim Anim, int32 lagRate") \
    X(PainterGetMinStr, "Painter", "result", "anim Anim, ptr:float OutValue") \
    X(PainterSetMinStr, "Painter", "result", "anim Anim, float str") \
    X(PainterGetMaxStr, "Painter", "result", "anim Anim, ptr:float OutValue") \
    X(PainterSetMaxStr, "Painter", "result", "anim Anim, float str") \
    X(PainterGetMinSize, "Painter", "result", "anim Anim, ptr:float OutValue") \
    X(PainterSetMinSize, "Painter", "result", "anim Anim, float str") \
    X(PainterGetMaxSize, "Painter", "result", "anim Anim, ptr:float OutValue") \
    X(PainterSetMaxSize, "Painter", "result", "anim Anim, float str") \
    X(PainterGetAdditiveMode, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterSetAdditiveMode, "Painter", "result", "anim Anim, int32 enable") \
    X(PainterGetDrawRing, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterSetDrawRing, "Painter", "result", "anim Anim, int32 draw") \
    X(PainterGetDrawNormal, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterSetDrawNormal, "Painter", "result", "anim Anim, int32 draw") \
    X(PainterGetDrawTrace, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterSetDrawTrace, "Painter", "result", "anim Anim, int32 draw") \
    X(PainterGetPressureEnable, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterSetPressureEnable, "Painter", "result", "anim Anim, int32 enable") \
    X(PainterGetPressureAffects, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterSetPressureAffects, "Painter", "result", "anim Anim, int32 affect") \
    X(PainterGetPredefinedStrEnable, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterSetPredefinedStrEnable, "Painter", "result", "anim Anim, int32 enable") \
    X(PainterGetPredefinedSizeEnable, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterSetPredefinedSizeEnable, "Painter", "result", "anim Anim, int32 enable") \
    X(PainterGetNormalScale, "Painter", "result", "anim Anim, ptr:float OutValue") \
    X(PainterSetNormalScale, "Painter", "result", "anim Anim, float scale") \
    X(PainterGetMarkerEnable, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterSetMarkerEnable, "Painter", "result", "anim Anim, int32 on") \
    X(PainterGetMarker, "Painter", "result", "anim Anim, ptr:float OutValue") \
    X(PainterSetMarker, "Painter", "result", "anim Anim, float pos") \
    X(PainterGetOffMeshHitType, "Painter", "result", "anim Anim, ptr:int32 OutValue") \
    X(PainterSetOffMeshHitType, "Painter", "result", "anim Anim, int32 type") \
    X(PainterGetOffMeshHitZDepth, "Painter", "result", "anim Anim, ptr:float OutValue") \
    X(PainterSetOffMeshHitZDepth, "Painter", "result", "anim Anim, float depth") \
    X(PainterGetOffMeshHitPos, "Painter", "result", "anim Anim, ptr:MaxMcpPoint3 OutValue") \
    X(PainterSetOffMeshHitPos, "Painter", "result", "anim Anim, cptr:MaxMcpPoint3 pos") \
    X(AtsGetVisible, "Ats", "result", "ptr:int32 OutValue") \
    X(AtsSetVisible, "Ats", "result", "int32 bVisible") \
    X(AtsNumFilesSelected, "Ats", "result", "ptr:int32 OutValue") \
    X(AtsGetFileSystemStatus, "Ats", "result", "cstr szFilename, ptr:uint32 OutValue") \
    X(AtsNumFiles, "Ats", "result", "ptr:int32 OutValue") \
    X(AtsIsInputFile, "Ats", "result", "cstr szFile, ptr:int32 OutValue") \
    X(AtsClearSelection, "Ats", "result", "") \
    X(AtsRefresh, "Ats", "result", "") \
    X(AtsGetDisabled, "Ats", "result", "ptr:int32 OutValue") \
    X(AtsSetDisabled, "Ats", "result", "int32 bDisabled") \
    X(AtsGetSilent, "Ats", "result", "ptr:int32 OutValue") \
    X(AtsSetSilent, "Ats", "result", "int32 bSilent") \
    X(AtsGetAutoLogin, "Ats", "result", "ptr:int32 OutValue") \
    X(AtsSetAutoLogin, "Ats", "result", "int32 bAutoLogin") \
    X(AtsGetTreeView, "Ats", "result", "ptr:int32 OutValue") \
    X(AtsSetTreeView, "Ats", "result", "int32 bTreeView") \
    X(AtsGetTableView, "Ats", "result", "ptr:int32 OutValue") \
    X(AtsSetTableView, "Ats", "result", "int32 bTableView") \
    X(AtsGetCheckNetworkPaths, "Ats", "result", "ptr:int32 OutValue") \
    X(AtsSetCheckNetworkPaths, "Ats", "result", "int32 bCheckPaths") \
    X(AtsGetDisplayExcluded, "Ats", "result", "ptr:int32 OutValue") \
    X(AtsSetDisplayExcluded, "Ats", "result", "int32 bDisplay") \
    X(AtsGetExcludeOutputFiles, "Ats", "result", "ptr:int32 OutValue") \
    X(AtsSetExcludeOutputFiles, "Ats", "result", "int32 bExclude") \
    X(AtsShowPromptsDialog, "Ats", "result", "") \
    X(AtsShowWorkingCommentDialog, "Ats", "result", "") \
    X(AtsShowStatusLogDialog, "Ats", "result", "") \
    X(AtsNumProviders, "Ats", "result", "ptr:int32 OutValue") \
    X(AtsGetProviderName, "Ats", "result", "int32 iProviderIndex, ptr:MaxMcpStrOut OutValue") \
    X(AtsGetActiveProvider, "Ats", "result", "ptr:int32 OutValue") \
    X(AtsSetActiveProvider, "Ats", "result", "int32 iProviderIndex") \
    X(AtsLoginProvider, "Ats", "result", "int32 iProviderIndex, ptr:int32 OutValue") \
    X(AtsLogoutProvider, "Ats", "result", "int32 iProviderIndex, ptr:int32 OutValue") \
    X(AtsIsFileExcluded, "Ats", "result", "int32 iProviderIndex, cstr szFile, ptr:int32 OutValue") \
    X(AtsIsFileShareLocked, "Ats", "result", "int32 iProviderIndex, cstr szFile, ptr:int32 OutValue") \
    X(AtsCheckForDependentFiles, "Ats", "result", "int32 iProviderIndex, cstr szFilename") \
    X(AtsCheckForCheckedOutFiles, "Ats", "result", "int32 iProviderIndex") \
    X(AtsCheckForUnControlledFiles, "Ats", "result", "int32 iProviderIndex") \
    X(AtsCheckForOutDatedFiles, "Ats", "result", "int32 iProviderIndex") \
    X(AtsCheckForSceneFileCheckOut, "Ats", "result", "int32 iProviderIndex") \
    X(AtsSetWorkingComment, "Ats", "result", "cstr szComment") \
    X(AtsGetWorkingComment, "Ats", "result", "ptr:MaxMcpStrOut OutValue") \
    X(AtsAppendStatusLog, "Ats", "result", "cstr szStatus") \
    X(AtsClearStatusLog, "Ats", "result", "") \
    X(AtsGetStatusLog, "Ats", "result", "ptr:MaxMcpStrOut OutValue") \
    X(AtsSetPath, "Ats", "result", "cstr aNewPath, int32 aCreateOutputFolder, ptr:int32 OutValue") \
    X(AtsSetPathOnSelection, "Ats", "result", "cstr aNewPath, int32 aCreateOutputFolder, ptr:int32 OutValue") \
    X(AtsResolveSelectionToUNC, "Ats", "result", "ptr:int32 OutValue") \
    X(AtsResolveSelectionRelativeToProjectFolder, "Ats", "result", "ptr:int32 OutValue") \
    X(AtsResolveSelectionToAbsolute, "Ats", "result", "ptr:int32 OutValue") \
    X(GfxWinShutdown, "Gfx", "result", "hwnd Win") \
    X(GfxWinGetVersion, "Gfx", "result", "hwnd Win, ptr:int32 OutValue") \
    X(GfxWinConfig, "Gfx", "result", "hwnd Win, hwnd hWnd") \
    X(GfxWinQuerySupport, "Gfx", "result", "hwnd Win, int32 what, ptr:int32 OutValue") \
    X(GfxWinGetHWnd, "Gfx", "result", "hwnd Win, ptr:hwnd OutValue") \
    X(GfxWinSetPos, "Gfx", "result", "hwnd Win, int32 x, int32 y, int32 w, int32 h") \
    X(GfxWinSetDisplayState, "Gfx", "result", "hwnd Win, int32 s") \
    X(GfxWinGetDisplayState, "Gfx", "result", "hwnd Win, ptr:int32 OutValue") \
    X(GfxWinGetWinDepth, "Gfx", "result", "hwnd Win, ptr:uint32 OutValue") \
    X(GfxWinGetHitherCoord, "Gfx", "result", "hwnd Win, ptr:uint32 OutValue") \
    X(GfxWinGetYonCoord, "Gfx", "result", "hwnd Win, ptr:uint32 OutValue") \
    X(GfxWinSetFlags, "Gfx", "result", "hwnd Win, uint32 f") \
    X(GfxWinGetMaxStripLength, "Gfx", "result", "hwnd Win, ptr:int32 OutValue") \
    X(GfxWinResetUpdateRect, "Gfx", "result", "hwnd Win") \
    X(GfxWinGetBufAccess, "Gfx", "result", "hwnd Win, int32 which, ptr:int32 OutValue") \
    X(GfxWinSetBackgroundOffset, "Gfx", "result", "hwnd Win, int32 x, int32 y") \
    X(GfxWinGetTextureSize, "Gfx", "result", "hwnd Win, int32 bkg, ptr:int32 OutValue") \
    X(GfxWinSetTextureColorOp, "Gfx", "result", "hwnd Win, int32 texStage, int32 texOp, int32 texAlphaSource, int32 texScale") \
    X(GfxWinSetTextureAlphaOp, "Gfx", "result", "hwnd Win, int32 texStage, int32 texOp, int32 texAlphaSource, int32 texScale") \
    X(GfxWinSetTextureTiling, "Gfx", "result", "hwnd Win, int32 u, int32 v, int32 w, int32 texStage, ptr:int32 OutValue") \
    X(GfxWinGetTextureTiling, "Gfx", "result", "hwnd Win, int32 which, int32 texStage, ptr:int32 OutValue") \
    X(GfxWinSetTexTransform, "Gfx", "result", "hwnd Win, cptr:MaxMcpMatrix3 m, int32 texStage") \
    X(GfxWinBeginFrame, "Gfx", "result", "hwnd Win") \
    X(GfxWinEndFrame, "Gfx", "result", "hwnd Win") \
    X(GfxWinSetViewport, "Gfx", "result", "hwnd Win, int32 x, int32 y, int32 w, int32 h") \
    X(GfxWinSetVirtualViewportParams, "Gfx", "result", "hwnd Win, float zoom, float xOffset, float yOffset") \
    X(GfxWinSetUseVirtualViewport, "Gfx", "result", "hwnd Win, int32 onOff") \
    X(GfxWinSetTransform, "Gfx", "result", "hwnd Win, cptr:MaxMcpMatrix3 m") \
    X(GfxWinGetFlipped, "Gfx", "result", "hwnd Win, ptr:int32 OutValue") \
    X(GfxWinGetTransform, "Gfx", "result", "hwnd Win, ptr:MaxMcpMatrix3 OutValue") \
    X(GfxWinMultiplePass, "Gfx", "result", "hwnd Win, int32 pass, int32 onOff, float scaleFact") \
    X(GfxWinSetSkipCount, "Gfx", "result", "hwnd Win, int32 c") \
    X(GfxWinGetSkipCount, "Gfx", "result", "hwnd Win, ptr:int32 OutValue") \
    X(GfxWinSetRndLimits, "Gfx", "result", "hwnd Win, uint32 l") \
    X(GfxWinGetRndLimits, "Gfx", "result", "hwnd Win, ptr:uint32 OutValue") \
    X(GfxWinGetRndMode, "Gfx", "result", "hwnd Win, ptr:uint32 OutValue") \
    X(GfxWinSetViewportLimits, "Gfx", "result", "hwnd Win, uint32 l") \
    X(GfxWinGetMaxLights, "Gfx", "result", "hwnd Win, ptr:int32 OutValue") \
    X(GfxWinSetLightExclusion, "Gfx", "result", "hwnd Win, uint32 exclVec") \
    X(GfxWinSetTransparency, "Gfx", "result", "hwnd Win, uint32 settings") \
    X(GfxWinHTransPoint, "Gfx", "result", "hwnd Win, cptr:MaxMcpPoint3 in, ptr:MaxMcpPoint3 out, ptr:uint32 OutValue") \
    X(GfxWinUpdateScreen, "Gfx", "result", "hwnd Win") \
    X(GfxWinLightVertex, "Gfx", "result", "hwnd Win, cptr:MaxMcpPoint3 pos, cptr:MaxMcpPoint3 nor, ptr:MaxMcpPoint3 rgb") \
    X(GfxWinGetTextPointSize, "Gfx", "result", "hwnd Win, ptr:float OutValue") \
    X(GfxWinSetTextPointSize, "Gfx", "result", "hwnd Win, float Arg0") \
    X(GfxWinGetTextWidthFactor, "Gfx", "result", "hwnd Win, ptr:float OutValue") \
    X(GfxWinSetTextWidthFactor, "Gfx", "result", "hwnd Win, float Arg0") \
    X(GfxWinStartMarkers, "Gfx", "result", "hwnd Win") \
    X(GfxWinEndMarkers, "Gfx", "result", "hwnd Win") \
    X(GfxWinStartSegments, "Gfx", "result", "hwnd Win") \
    X(GfxWinEndSegments, "Gfx", "result", "hwnd Win") \
    X(GfxWinStartTriangles, "Gfx", "result", "hwnd Win") \
    X(GfxWinEndTriangles, "Gfx", "result", "hwnd Win") \
    X(GfxWinClearHitCode, "Gfx", "result", "hwnd Win") \
    X(GfxWinCheckHitCode, "Gfx", "result", "hwnd Win, ptr:int32 OutValue") \
    X(GfxWinSetHitCode, "Gfx", "result", "hwnd Win, int32 h") \
    X(GfxWinGetHitDistance, "Gfx", "result", "hwnd Win, ptr:uint32 OutValue") \
    X(GfxWinSetHitDistance, "Gfx", "result", "hwnd Win, uint32 d") \
    X(GfxWinIsPerspectiveView, "Gfx", "result", "hwnd Win, ptr:int32 OutValue") \
    X(GfxWinMarkerBufferUnLock, "Gfx", "result", "hwnd Win") \
    X(GfxWinMarkerBufferDraw, "Gfx", "result", "hwnd Win, int32 numberOfMarkers") \
    X(GfxWinLineBufferUnLock, "Gfx", "result", "hwnd Win") \
    X(GfxWinLineBufferDraw, "Gfx", "result", "hwnd Win, int32 numberOfSegments") \
    X(TrackViewGetNumTracks, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewNumSelTracks, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewGetAnim, "Track", "result", "int32 Index, int32 index, ptr:anim OutValue") \
    X(TrackViewGetClient, "Track", "result", "int32 Index, int32 index, ptr:anim OutValue") \
    X(TrackViewCanAssignController, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewDoAssignController, "Track", "result", "int32 Index, int32 clearMot") \
    X(TrackViewShowControllerType, "Track", "result", "int32 Index, int32 show") \
    X(TrackViewGetTVName, "Track", "result", "int32 Index, ptr:MaxMcpStrOut OutValue") \
    X(TrackViewSetTVName, "Track", "result", "int32 Index, cstr Arg0") \
    X(TrackViewCloseTreeView, "Track", "result", "int32 Index") \
    X(TrackViewSetFilter, "Track", "result", "int32 Index, uint32 mask, int32 which, int32 redraw") \
    X(TrackViewClearFilter, "Track", "result", "int32 Index, uint32 mask, int32 which, int32 redraw") \
    X(TrackViewZoomSelected, "Track", "result", "int32 Index") \
    X(TrackViewExpandTracks, "Track", "result", "int32 Index") \
    X(TrackViewSelectTrackByIndex, "Track", "result", "int32 Index, int32 index, int32 clearSelection") \
    X(TrackViewSetEditMode, "Track", "result", "int32 Index, int32 mode") \
    X(TrackViewGetEditMode, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewIsCurrent, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewSetCurrent, "Track", "result", "int32 Index") \
    X(TrackViewSetAutoZoomOnSelChange, "Track", "result", "int32 Index, int32 autoZoom") \
    X(TrackViewAutoZoomOnSelChange, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewFpSelectTrackByIndex, "Track", "result", "int32 Index, int32 index, int32 clearSelection") \
    X(TrackViewModifySubTree, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewModifyChildren, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewLaunchUtility, "Track", "result", "int32 Index, cstr name") \
    X(TrackViewLaunchUtilityDialog, "Track", "result", "int32 Index") \
    X(TrackViewCloseUtility, "Track", "result", "int32 Index, cstr name") \
    X(TrackViewInteractiveUpdate, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewSyncTime, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewFreezeSelKeys, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewFreezeNonSelCurves, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewShowNonSelCurves, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewShowTangents, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewShowFrozenKeys, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewIsolateCurve, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewUseSoftSelect, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewSoftSelectRange, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewSoftSelectFalloff, "Track", "result", "int32 Index, ptr:float OutValue") \
    X(TrackViewSetTangentType, "Track", "result", "int32 Index, int32 type, int32 effect") \
    X(TrackViewSetInTangentType, "Track", "result", "int32 Index, int32 type, int32 effect") \
    X(TrackViewSetOutTangentType, "Track", "result", "int32 Index, int32 type, int32 effect") \
    X(TrackViewEffectSelectedObjectsOnly, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewManualNavigation, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewAutoExpandChildren, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewAutoExpandTransforms, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewAutoExpandObjects, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewAutoExpandModifiers, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewAutoExpandMaterials, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewAutoExpandXYZ, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewAutoSelectAnimated, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewAutoSelectPosition, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewAutoSelectRotation, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewAutoSelectScale, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewAutoSelectXYZ, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewAutoZoomToRoot, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewAutoZoomToSelected, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewAutoZoomToEdited, "Track", "result", "int32 Index, ptr:int32 OutValue") \
    X(TrackViewGetRootTrack, "Track", "result", "int32 Index, ptr:anim OutValue") \
    X(TrackViewRestoreDefaultRootTrack, "Track", "result", "int32 Index") \
    X(TrackViewScaleValuesOrigin, "Track", "result", "int32 Index, ptr:float OutValue") \
    X(TrackViewUpdateList, "Track", "result", "int32 Index") \
    X(TrackViewReduceKeys, "Track", "result", "int32 Index, float in_threshold") \
    X(TrackViewSplitKey, "Track", "result", "int32 Index") \
    X(TrackViewStepPreviousKeySelection, "Track", "result", "int32 Index") \
    X(TrackViewStepNextKeySelection, "Track", "result", "int32 Index") \
    X(TrackViewShrinkKeySelection, "Track", "result", "int32 Index") \
    X(TrackViewGrowKeySelection, "Track", "result", "int32 Index") \
    X(TrackViewEaseToPreviousKey, "Track", "result", "int32 Index") \
    X(TrackViewEaseToNextKey, "Track", "result", "int32 Index") \
    X(TrackViewMirrorKeyTangents, "Track", "result", "int32 Index") \
    X(TrackViewNudgeKey, "Track", "result", "int32 Index, int32 toLeft") \
    X(TrackViewScaleTangentsDown, "Track", "result", "int32 Index, int32 onlyInnerHandle") \
    X(TrackViewScaleTangentsUp, "Track", "result", "int32 Index, int32 onlyInnerHandle") \
    X(TrackViewLoopKey, "Track", "result", "int32 Index, int32 toLastKey") \
    X(TrackViewSnapScaleOriginsToFirstSelectedKey, "Track", "result", "int32 Index") \
    X(TrackViewSpaceKeyEvenly, "Track", "result", "int32 Index, int32 inValue") \
    X(TrackViewRelaxKeys, "Track", "result", "int32 Index, int32 toLin") \
    X(TrackViewFlattenKeys, "Track", "result", "int32 Index, int32 toLeft") \
    X(TrackViewAverageKeys, "Track", "result", "int32 Index, int32 weld") \
    X(StdUVGenSetCoordMapping, "Std", "result", "anim Anim, int32 Arg0") \
    X(StdUVGenSetUOffs, "Std", "result", "anim Anim, float f, int32 t") \
    X(StdUVGenSetVOffs, "Std", "result", "anim Anim, float f, int32 t") \
    X(StdUVGenSetUScl, "Std", "result", "anim Anim, float f, int32 t") \
    X(StdUVGenSetVScl, "Std", "result", "anim Anim, float f, int32 t") \
    X(StdUVGenSetAng, "Std", "result", "anim Anim, float f, int32 t") \
    X(StdUVGenSetUAng, "Std", "result", "anim Anim, float f, int32 t") \
    X(StdUVGenSetVAng, "Std", "result", "anim Anim, float f, int32 t") \
    X(StdUVGenSetWAng, "Std", "result", "anim Anim, float f, int32 t") \
    X(StdUVGenSetBlur, "Std", "result", "anim Anim, float f, int32 t") \
    X(StdUVGenSetBlurOffs, "Std", "result", "anim Anim, float f, int32 t") \
    X(StdUVGenSetNoiseAmt, "Std", "result", "anim Anim, float f, int32 t") \
    X(StdUVGenSetNoiseSize, "Std", "result", "anim Anim, float f, int32 t") \
    X(StdUVGenSetNoiseLev, "Std", "result", "anim Anim, int32 i, int32 t") \
    X(StdUVGenSetNoisePhs, "Std", "result", "anim Anim, float f, int32 t") \
    X(StdUVGenSetTextureTiling, "Std", "result", "anim Anim, int32 tiling") \
    X(StdUVGenSetMapChannel, "Std", "result", "anim Anim, int32 i") \
    X(StdUVGenSetFlag, "Std", "result", "anim Anim, uint32 f, uint32 val") \
    X(StdUVGenSetHideMapBackFlag, "Std", "result", "anim Anim, int32 b") \
    X(StdUVGenSetUseRealWorldScale, "Std", "result", "anim Anim, int32 useRWS") \
    X(StdUVGenGetCoordMapping, "Std", "result", "anim Anim, int32 Arg0, ptr:int32 OutValue") \
    X(StdUVGenGetUOffs, "Std", "result", "anim Anim, int32 t, ptr:float OutValue") \
    X(StdUVGenGetVOffs, "Std", "result", "anim Anim, int32 t, ptr:float OutValue") \
    X(StdUVGenGetUScl, "Std", "result", "anim Anim, int32 t, ptr:float OutValue") \
    X(StdUVGenGetVScl, "Std", "result", "anim Anim, int32 t, ptr:float OutValue") \
    X(StdUVGenGetAng, "Std", "result", "anim Anim, int32 t, ptr:float OutValue") \
    X(StdUVGenGetUAng, "Std", "result", "anim Anim, int32 t, ptr:float OutValue") \
    X(StdUVGenGetVAng, "Std", "result", "anim Anim, int32 t, ptr:float OutValue") \
    X(StdUVGenGetWAng, "Std", "result", "anim Anim, int32 t, ptr:float OutValue") \
    X(StdUVGenGetBlur, "Std", "result", "anim Anim, int32 t, ptr:float OutValue") \
    X(StdUVGenGetBlurOffs, "Std", "result", "anim Anim, int32 t, ptr:float OutValue") \
    X(StdUVGenGetNoiseAmt, "Std", "result", "anim Anim, int32 t, ptr:float OutValue") \
    X(StdUVGenGetNoiseSize, "Std", "result", "anim Anim, int32 t, ptr:float OutValue") \
    X(StdUVGenGetNoiseLev, "Std", "result", "anim Anim, int32 t, ptr:int32 OutValue") \
    X(StdUVGenGetNoisePhs, "Std", "result", "anim Anim, int32 t, ptr:float OutValue") \
    X(StdUVGenGetTextureTiling, "Std", "result", "anim Anim, ptr:int32 OutValue") \
    X(StdUVGenGetMapChannel, "Std", "result", "anim Anim, ptr:int32 OutValue") \
    X(StdUVGenGetFlag, "Std", "result", "anim Anim, uint32 f, ptr:int32 OutValue") \
    X(StdUVGenGetHideMapBackFlag, "Std", "result", "anim Anim, ptr:int32 OutValue") \
    X(StdUVGenGetUseRealWorldScale, "Std", "result", "anim Anim, ptr:int32 OutValue") \
    X(NodeBakeGetBakeEnabled, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeSetBakeEnabled, "Node", "result", "node Node, int32 isEnabled") \
    X(NodeBakeGetBakeMapChannel, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeSetBakeMapChannel, "Node", "result", "node Node, int32 mapChannel") \
    X(NodeBakeGetNDilations, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeSetNDilations, "Node", "result", "node Node, int32 nDilations") \
    X(NodeBakeGetSurfaceArea, "Node", "result", "node Node, ptr:float OutValue") \
    X(NodeBakeSetSurfaceArea, "Node", "result", "node Node, float area") \
    X(NodeBakeGetAreaScale, "Node", "result", "node Node, ptr:float OutValue") \
    X(NodeBakeSetAreaScale, "Node", "result", "node Node, float scale") \
    X(NodeBakeGetNBakeElements, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeRemoveBakeElementByName, "Node", "result", "node Node, cstr name, ptr:int32 OutValue") \
    X(NodeBakeRemoveBakeElementByIndex, "Node", "result", "node Node, int32 index, ptr:int32 OutValue") \
    X(NodeBakeRemoveAllBakeElements, "Node", "result", "node Node") \
    X(NodeBakeResetBakeProps, "Node", "result", "node Node") \
    X(NodeBakeGetEffectiveEnable, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeGetRenderSize, "Node", "result", "node Node, ptr:MaxMcpIPoint2 OutValue") \
    X(NodeBakeGetActiveTile, "Node", "result", "node Node, ptr:MaxMcpIPoint2 OutValue") \
    X(NodeBakeSetActiveTile, "Node", "result", "node Node, cptr:MaxMcpIPoint2 tile") \
    X(NodeBakeProjGetEnabled, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeProjSetEnabled, "Node", "result", "node Node, int32 b") \
    X(NodeBakeProjGetProjMod, "Node", "result", "node Node, ptr:anim OutValue") \
    X(NodeBakeProjGetProjModTarg, "Node", "result", "node Node, ptr:MaxMcpStrOut OutValue") \
    X(NodeBakeProjSetProjModTarg, "Node", "result", "node Node, cstr s") \
    X(NodeBakeProjGetCropAlpha, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeProjSetCropAlpha, "Node", "result", "node Node, int32 b") \
    X(NodeBakeProjGetProjSpace, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeProjSetProjSpace, "Node", "result", "node Node, int32 enum_val") \
    X(NodeBakeProjGetNormalSpace, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeProjSetNormalSpace, "Node", "result", "node Node, int32 enum_val") \
    X(NodeBakeProjGetTangentYDir, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeProjSetTangentYDir, "Node", "result", "node Node, int32 enum_val") \
    X(NodeBakeProjGetTangentXDir, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeProjSetTangentXDir, "Node", "result", "node Node, int32 enum_val") \
    X(NodeBakeProjGetUseCage, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeProjSetUseCage, "Node", "result", "node Node, int32 b") \
    X(NodeBakeProjGetRayOffset, "Node", "result", "node Node, ptr:float OutValue") \
    X(NodeBakeProjSetRayOffset, "Node", "result", "node Node, float f") \
    X(NodeBakeProjGetHitResolveMode, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeProjSetHitResolveMode, "Node", "result", "node Node, int32 enum_val") \
    X(NodeBakeProjGetHitMatchMtlID, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeProjSetHitMatchMtlID, "Node", "result", "node Node, int32 b") \
    X(NodeBakeProjGetHitWorkingModel, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeProjSetHitWorkingModel, "Node", "result", "node Node, int32 b") \
    X(NodeBakeProjGetWarnRayMiss, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeProjSetWarnRayMiss, "Node", "result", "node Node, int32 b") \
    X(NodeBakeProjGetHeightMapMin, "Node", "result", "node Node, ptr:float OutValue") \
    X(NodeBakeProjSetHeightMapMin, "Node", "result", "node Node, float f") \
    X(NodeBakeProjGetHeightMapMax, "Node", "result", "node Node, ptr:float OutValue") \
    X(NodeBakeProjSetHeightMapMax, "Node", "result", "node Node, float f") \
    X(NodeBakeProjGetHeightBufMin, "Node", "result", "node Node, ptr:float OutValue") \
    X(NodeBakeProjSetHeightBufMin, "Node", "result", "node Node, float f") \
    X(NodeBakeProjGetHeightBufMax, "Node", "result", "node Node, ptr:float OutValue") \
    X(NodeBakeProjSetHeightBufMax, "Node", "result", "node Node, float f") \
    X(NodeBakeProjGetProportionalOutput, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeProjSetProportionalOutput, "Node", "result", "node Node, int32 b") \
    X(NodeBakeProjGetBakeMapChannel_SO, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeProjSetBakeMapChannel_SO, "Node", "result", "node Node, int32 mapChannel") \
    X(NodeBakeProjGetBakeObjLevel, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeProjSetBakeObjLevel, "Node", "result", "node Node, int32 b") \
    X(NodeBakeProjGetBakeSubObjLevels, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeProjSetBakeSubObjLevels, "Node", "result", "node Node, int32 b") \
    X(NodeBakeProjGetObjBakeToMtl, "Node", "result", "node Node, ptr:int32 OutValue") \
    X(NodeBakeProjSetObjBakeToMtl, "Node", "result", "node Node, int32 b") \
    X(IGameNodeReleaseIGameObject, "IGame", "result", "node Node") \
    X(IGameNodeGetName, "IGame", "result", "node Node, ptr:MaxMcpStrOut OutValue") \
    X(IGameNodeGetNodeID, "IGame", "result", "node Node, ptr:int32 OutValue") \
    X(IGameNodeGetMaxNode, "IGame", "result", "node Node, ptr:node OutValue") \
    X(IGameNodeGetChildCount, "IGame", "result", "node Node, ptr:int32 OutValue") \
    X(IGameNodeGetMaterialIndex, "IGame", "result", "node Node, ptr:int32 OutValue") \
    X(IGameNodeGetWireframeColor, "IGame", "result", "node Node, ptr:MaxMcpIPoint3 OutValue") \
    X(IGameNodeIsTarget, "IGame", "result", "node Node, ptr:int32 OutValue") \
    X(IGameNodeIsGroupOwner, "IGame", "result", "node Node, ptr:int32 OutValue") \
    X(IGameNodeIsNodeHidden, "IGame", "result", "node Node, ptr:int32 OutValue") \
    X(IGameMeshInitializeBinormalData, "IGame", "result", "node Node, ptr:int32 OutValue") \
    X(IGameMeshGetNumberOfVerts, "IGame", "result", "node Node, ptr:int32 OutValue") \
    X(IGameMeshGetNumberOfTexVerts, "IGame", "result", "node Node, ptr:int32 OutValue") \
    X(IGameMeshGetVertex, "IGame", "result", "node Node, int32 index, int32 ObjectSpace, ptr:MaxMcpPoint3 OutValue") \
    X(IGameMeshGetTexVertex, "IGame", "result", "node Node, int32 index, ptr:MaxMcpPoint2 OutValue") \
    X(IGameMeshSetUseWeightedNormals, "IGame", "result", "node Node") \
    X(IGameMeshGetNumberOfNormals, "IGame", "result", "node Node, ptr:int32 OutValue") \
    X(IGameMeshGetNormalVertexIndex, "IGame", "result", "node Node, int32 index, ptr:int32 OutValue") \
    X(IGameMeshGetNormal, "IGame", "result", "node Node, int32 index, int32 ObjectSpace, ptr:MaxMcpPoint3 OutValue") \
    X(IGameMeshGetNumberOfIllumVerts, "IGame", "result", "node Node, ptr:int32 OutValue") \
    X(IGameMeshGetNumberOfAlphaVerts, "IGame", "result", "node Node, ptr:int32 OutValue") \
    X(IGameMeshGetNumberOfColorVerts, "IGame", "result", "node Node, ptr:int32 OutValue") \
    X(IGameMeshGetColorVertex, "IGame", "result", "node Node, int32 index, ptr:MaxMcpPoint3 OutValue") \
    X(IGameMeshGetAlphaVertex, "IGame", "result", "node Node, int32 index, ptr:float OutValue") \
    X(IGameMeshGetIllumVertex, "IGame", "result", "node Node, int32 index, ptr:float OutValue") \
    X(IGameMeshGetNumberOfFaces, "IGame", "result", "node Node, ptr:int32 OutValue") \
    X(IGameMeshGetNumberOfMapVerts, "IGame", "result", "node Node, int32 ch, ptr:int32 OutValue") \
    X(IGameMeshGetMapVertex, "IGame", "result", "node Node, int32 ch, int32 index, ptr:MaxMcpPoint3 OutValue") \
    X(IGameMeshGetNumberOfBinormals, "IGame", "result", "node Node, int32 mapChannel, ptr:int32 OutValue") \
    X(IGameMeshGetBinormal, "IGame", "result", "node Node, int32 index, int32 mapChannel, ptr:MaxMcpPoint3 OutValue") \
    X(IGameMeshGetNumberOfTangents, "IGame", "result", "node Node, int32 mapChannel, ptr:int32 OutValue") \
    X(IGameMeshGetTangent, "IGame", "result", "node Node, int32 index, int32 mapChannel, ptr:MaxMcpPoint3 OutValue") \
    X(IGameMeshGetActiveMapChannelNum, "IGame", "result", "node Node, ptr:MaxMcpSpan OutValue") \
    X(IGameMeshGetActiveSmgrps, "IGame", "result", "node Node, ptr:MaxMcpSpan OutValue") \
    X(IGameMeshGetActiveMatIDs, "IGame", "result", "node Node, ptr:MaxMcpSpan OutValue") \
    X(IGameMeshGetFaceIndexFromSmgrp, "IGame", "result", "node Node, uint32 smgrp, ptr:MaxMcpSpan OutValue") \
    X(IGameMeshGetFaceVertex, "IGame", "result", "node Node, int32 faceIndex, int32 corner, ptr:int32 OutValue") \
    X(IGameMeshGetFaceTextureVertex, "IGame", "result", "node Node, int32 faceIndex, int32 corner, int32 mapChannel, ptr:int32 OutValue") \
    X(IGameMeshGetFaceVertexNormal, "IGame", "result", "node Node, int32 faceIndex, int32 corner, ptr:int32 OutValue") \
    X(IGameMeshGetFaceVertexTangentBinormal, "IGame", "result", "node Node, int32 faceIndex, int32 corner, int32 mapChannel, ptr:int32 OutValue") \
    X(IGameMeshGetFaceSmoothingGroup, "IGame", "result", "node Node, int32 faceIndex, ptr:uint32 OutValue") \
    X(IGameMeshGetFaceMaterialID, "IGame", "result", "node Node, int32 faceIndex, ptr:int32 OutValue") \
    X(IGameMeshGetFaceEdgeVisibility, "IGame", "result", "node Node, int32 faceIndex, int32 edge, ptr:int32 OutValue") \
    X(IGameMeshSetCreateOptimizedNormalList, "IGame", "result", "node Node") \
    X(IGameMeshGetNumberOfPolygons, "IGame", "result", "node Node, ptr:int32 OutValue") \
    X(IGameMeshGetNumberOfPolygonNormals, "IGame", "result", "node Node, ptr:int32 OutValue") \
    X(IGameMeshGetNumberOfPolygonCorners, "IGame", "result", "node Node, int32 PolyIndex, ptr:int32 OutValue") \
    X(IGameMeshGetPolygonNormalsArray, "IGame", "result", "node Node, int32 PolyIndex, ptr:MaxMcpSpan OutValue") \
    X(IGameMeshGetPolygonSmoothingGroup, "IGame", "result", "node Node, int32 PolyIndex, ptr:uint32 OutValue") \
    X(IGameMeshGetPolygonMaterialID, "IGame", "result", "node Node, int32 PolyIndex, ptr:int32 OutValue") \
    X(MenuSettingsResetDefaults, "Menu", "result", "") \
    X(MenuSettingsSetBorderSz, "Menu", "result", "int32 borderSz") \
    X(MenuSettingsGetBorderSz, "Menu", "result", "ptr:int32 OutValue") \
    X(MenuSettingsSetHorizontalMarginInPoints, "Menu", "result", "int32 horizontalMarginInPoints") \
    X(MenuSettingsGetHorizontalMarginInPoints, "Menu", "result", "ptr:int32 OutValue") \
    X(MenuSettingsSetVerticalMarginInPoints, "Menu", "result", "int32 verticalMarginInPoints") \
    X(MenuSettingsGetVerticalMarginInPoints, "Menu", "result", "ptr:int32 OutValue") \
    X(MenuSettingsSetItemFontFace, "Menu", "result", "cstr szItemFontFace") \
    X(MenuSettingsGetItemFontFace, "Menu", "result", "ptr:MaxMcpStrOut OutValue") \
    X(MenuSettingsSetTitleFontFace, "Menu", "result", "cstr szTitleFontFace") \
    X(MenuSettingsGetTitleFontFace, "Menu", "result", "ptr:MaxMcpStrOut OutValue") \
    X(MenuSettingsSetItemFontSize, "Menu", "result", "int32 itemFontSize") \
    X(MenuSettingsGetItemFontSize, "Menu", "result", "ptr:int32 OutValue") \
    X(MenuSettingsSetTitleFontSize, "Menu", "result", "int32 titleFontSize") \
    X(MenuSettingsGetTitleFontSize, "Menu", "result", "ptr:int32 OutValue") \
    X(MenuSettingsSetUseUniformItemHeight, "Menu", "result", "int32 useUniformItemHeight") \
    X(MenuSettingsGetUseUniformItemHeight, "Menu", "result", "ptr:int32 OutValue") \
    X(MenuSettingsSetUseUniformItemHeightBOOL, "Menu", "result", "int32 useUniformItemHeight") \
    X(MenuSettingsGetUseUniformItemHeightBOOL, "Menu", "result", "ptr:int32 OutValue") \
    X(MenuSettingsSetOpacity, "Menu", "result", "float opacity") \
    X(MenuSettingsGetOpacity, "Menu", "result", "ptr:float OutValue") \
    X(MenuSettingsSetDisplayMethod, "Menu", "result", "int32 displayMethod") \
    X(MenuSettingsGetDisplayMethod, "Menu", "result", "ptr:int32 OutValue") \
    X(MenuSettingsSetAnimatedSteps, "Menu", "result", "uint32 steps") \
    X(MenuSettingsGetAnimatedSteps, "Menu", "result", "ptr:uint32 OutValue") \
    X(MenuSettingsSetAnimatedStepTime, "Menu", "result", "uint32 ms") \
    X(MenuSettingsGetAnimatedStepTime, "Menu", "result", "ptr:uint32 OutValue") \
    X(MenuSettingsSetSubMenuPauseTime, "Menu", "result", "uint32 ms") \
    X(MenuSettingsGetSubMenuPauseTime, "Menu", "result", "ptr:uint32 OutValue") \
    X(MenuSettingsSetUseLastExecutedItem, "Menu", "result", "int32 useLastExecutedItem") \
    X(MenuSettingsGetUseLastExecutedItem, "Menu", "result", "ptr:int32 OutValue") \
    X(MenuSettingsSetUseLastExecutedItemBOOL, "Menu", "result", "int32 useLastExecutedItem") \
    X(MenuSettingsGetUseLastExecutedItemBOOL, "Menu", "result", "ptr:int32 OutValue") \
    X(MenuSettingsSetRepositionWhenClipped, "Menu", "result", "int32 repositionWhenClipped") \
    X(MenuSettingsGetRepositionWhenClipped, "Menu", "result", "ptr:int32 OutValue") \
    X(MenuSettingsSetRepositionWhenClippedBOOL, "Menu", "result", "int32 repositionWhenClipped") \
    X(MenuSettingsGetRepositionWhenClippedBOOL, "Menu", "result", "ptr:int32 OutValue") \
    X(MenuSettingsSetRemoveRedundantSeparators, "Menu", "result", "int32 removeRedundantSeparators") \
    X(MenuSettingsGetRemoveRedundantSeparators, "Menu", "result", "ptr:int32 OutValue") \
    X(MenuSettingsSetRemoveRedundantSeparatorsBOOL, "Menu", "result", "int32 removeRedundantSeparators") \
    X(MenuSettingsGetRemoveRedundantSeparatorsBOOL, "Menu", "result", "ptr:int32 OutValue") \
    X(QuadMenuSetFirstQuadDisplayed, "Quad", "result", "int32 firstQuadDisplayed") \
    X(QuadMenuGetFirstQuadDisplayed, "Quad", "result", "ptr:int32 OutValue") \
    X(QuadMenuSetUseUniformQuadWidth, "Quad", "result", "int32 useUniformQuadWidth") \
    X(QuadMenuGetUseUniformQuadWidth, "Quad", "result", "ptr:int32 OutValue") \
    X(QuadMenuSetUseUniformQuadWidthBOOL, "Quad", "result", "int32 useUniformQuadWidth") \
    X(QuadMenuGetUseUniformQuadWidthBOOL, "Quad", "result", "ptr:int32 OutValue") \
    X(QuadMenuSetMoveCursorOnReposition, "Quad", "result", "int32 moveCursorOnReposition") \
    X(QuadMenuGetMoveCursorOnReposition, "Quad", "result", "ptr:int32 OutValue") \
    X(QuadMenuSetMoveCursorOnRepositionBOOL, "Quad", "result", "int32 moveCursorOnReposition") \
    X(QuadMenuGetMoveCursorOnRepositionBOOL, "Quad", "result", "ptr:int32 OutValue") \
    X(QuadMenuSetReturnCursorAfterReposition, "Quad", "result", "int32 returnCursorAfterReposition") \
    X(QuadMenuGetReturnCursorAfterReposition, "Quad", "result", "ptr:int32 OutValue") \
    X(QuadMenuSetReturnCursorAfterRepositionBOOL, "Quad", "result", "int32 returnCursorAfterReposition") \
    X(QuadMenuGetReturnCursorAfterRepositionBOOL, "Quad", "result", "ptr:int32 OutValue") \
    X(QuadMenuSetCursorLocInBox_0to1, "Quad", "result", "float x, float y") \
    X(QuadMenuGetCursorLocXInBox_0to1, "Quad", "result", "ptr:float OutValue") \
    X(QuadMenuGetCursorLocYInBox_0to1, "Quad", "result", "ptr:float OutValue") \
    X(QuadMenuSetTitleBarBackgroundColor, "Quad", "result", "int32 quadNum, cptr:MaxMcpColor color") \
    X(QuadMenuGetTitleBarBackgroundColor, "Quad", "result", "int32 quadNum, ptr:MaxMcpColor OutValue") \
    X(QuadMenuSetTitleBarTextColor, "Quad", "result", "int32 quadNum, cptr:MaxMcpColor color") \
    X(QuadMenuGetTitleBarTextColor, "Quad", "result", "int32 quadNum, ptr:MaxMcpColor OutValue") \
    X(QuadMenuSetItemBackgroundColor, "Quad", "result", "int32 quadNum, cptr:MaxMcpColor color") \
    X(QuadMenuGetItemBackgroundColor, "Quad", "result", "int32 quadNum, ptr:MaxMcpColor OutValue") \
    X(QuadMenuSetItemTextColor, "Quad", "result", "int32 quadNum, cptr:MaxMcpColor color") \
    X(QuadMenuGetItemTextColor, "Quad", "result", "int32 quadNum, ptr:MaxMcpColor OutValue") \
    X(QuadMenuSetLastExecutedItemTextColor, "Quad", "result", "int32 quadNum, cptr:MaxMcpColor color") \
    X(QuadMenuGetLastExecutedItemTextColor, "Quad", "result", "int32 quadNum, ptr:MaxMcpColor OutValue") \
    X(QuadMenuSetHighlightedItemBackgroundColor, "Quad", "result", "int32 quadNum, cptr:MaxMcpColor color") \
    X(QuadMenuGetHighlightedItemBackgroundColor, "Quad", "result", "int32 quadNum, ptr:MaxMcpColor OutValue") \
    X(QuadMenuSetHighlightedItemTextColor, "Quad", "result", "int32 quadNum, cptr:MaxMcpColor color") \
    X(QuadMenuGetHighlightedItemTextColor, "Quad", "result", "int32 quadNum, ptr:MaxMcpColor OutValue") \
    X(QuadMenuSetBorderColor, "Quad", "result", "int32 quadNum, cptr:MaxMcpColor color") \
    X(QuadMenuGetBorderColor, "Quad", "result", "int32 quadNum, ptr:MaxMcpColor OutValue") \
    X(QuadMenuSetDisabledShadowColor, "Quad", "result", "int32 quadNum, cptr:MaxMcpColor color") \
    X(QuadMenuGetDisabledShadowColor, "Quad", "result", "int32 quadNum, ptr:MaxMcpColor OutValue") \
    X(QuadMenuSetDisabledHighlightColor, "Quad", "result", "int32 quadNum, cptr:MaxMcpColor color") \
    X(QuadMenuGetDisabledHighlightColor, "Quad", "result", "int32 quadNum, ptr:MaxMcpColor OutValue") \
    X(GenCameraSetConeState, "Gen", "result", "anim Anim, int32 s") \
    X(GenCameraGetConeState, "Gen", "result", "anim Anim, ptr:int32 OutValue") \
    X(GenCameraSetHorzLineState, "Gen", "result", "anim Anim, int32 s") \
    X(GenCameraGetHorzLineState, "Gen", "result", "anim Anim, ptr:int32 OutValue") \
    X(GenCameraEnable, "Gen", "result", "anim Anim, int32 enab") \
    X(GenCameraSetFOVType, "Gen", "result", "anim Anim, int32 ft") \
    X(GenCameraGetFOVType, "Gen", "result", "anim Anim, ptr:int32 OutValue") \
    X(GenCameraGetFOVControl, "Gen", "result", "anim Anim, ptr:anim OutValue") \
    X(GenCameraType, "Gen", "result", "anim Anim, ptr:int32 OutValue") \
    X(GenCameraSetType, "Gen", "result", "anim Anim, int32 tp") \
    X(GenCameraSetDOFEnable, "Gen", "result", "anim Anim, int32 t, int32 onOff") \
    X(GenCameraSetDOFFStop, "Gen", "result", "anim Anim, int32 t, float fs") \
    X(KeyControlGetNumKeys, "Key", "result", "anim Anim, ptr:int32 OutValue") \
    X(KeyControlSetNumKeys, "Key", "result", "anim Anim, int32 n") \
    X(KeyControlSortKeys, "Key", "result", "anim Anim") \
    X(KeyControlGetKeySize, "Key", "result", "anim Anim, ptr:int32 OutValue") \
    X(HoldIsSuspended, "Hold", "result", "ptr:int32 OutValue") \
    X(HoldHolding, "Hold", "result", "ptr:int32 OutValue") \
    X(HoldRedoing, "Hold", "result", "ptr:int32 OutValue") \
    X(HoldRestoreOrRedoing, "Hold", "result", "ptr:int32 OutValue") \
    X(HoldDisableUndo, "Hold", "result", "") \
    X(HoldEnableUndo, "Hold", "result", "") \
    X(HoldGetBeginDepth, "Hold", "result", "ptr:int32 OutValue") \
    X(HoldRelease, "Hold", "result", "") \
    X(HoldEnd, "Hold", "result", "") \
    X(HoldGetSuperBeginDepth, "Hold", "result", "ptr:int32 OutValue") \
    X(HoldGetGlobalPutCount, "Hold", "result", "ptr:int32 OutValue") \
    X(ParamBlock2GetVersion, "Param", "result", "anim Anim, ptr:uint32 OutValue") \
    X(ParamBlock2NumParams, "Param", "result", "anim Anim, ptr:int32 OutValue") \
    X(ParamBlock2GetLocalName, "Param", "result", "anim Anim, ptr:MaxMcpStrOut OutValue") \
    X(ParamBlock2GetOwner, "Param", "result", "anim Anim, ptr:anim OutValue") \
    X(ParamBlock2ReleaseDesc, "Param", "result", "anim Anim") \
    X(ParamBlock2KeyFrameAtTimeByIndex, "Param", "result", "anim Anim, int32 i, int32 t, int32 tabIndex, ptr:int32 OutValue") \
    X(ParamBlock2RemoveControllerByIndex, "Param", "result", "anim Anim, int32 i, int32 tabIndex") \
    X(ParamBlock2SwapControllers, "Param", "result", "anim Anim, int32 i1, int32 tabIndex1, int32 i2, int32 tabIndex2") \
    X(ParamBlock2GetRefNum, "Param", "result", "anim Anim, int32 i, int32 tabIndex, ptr:int32 OutValue") \
    X(ParamBlock2GetControllerRefNum, "Param", "result", "anim Anim, int32 i, int32 tabIndex, ptr:int32 OutValue") \
    X(ParamBlock2RescaleParam, "Param", "result", "anim Anim, int32 paramNum, int32 tabIndex, float f") \
    X(ParamBlock2EnableNotifications, "Param", "result", "anim Anim, int32 onOff") \
    X(ParamBlock2IsNotificationEnabled, "Param", "result", "anim Anim, ptr:int32 OutValue") \
    X(ParamBlock2InitMSParameters, "Param", "result", "anim Anim") \
    X(ParamBlock2ClearParamAliases, "Param", "result", "anim Anim") \
    X(ParamBlock2ParamAliasCount, "Param", "result", "anim Anim, ptr:int32 OutValue") \
    X(ParamBlock2ClearSubAnimMap, "Param", "result", "anim Anim") \
    X(ParamBlock2ResetAll, "Param", "result", "anim Anim, int32 updateUI, int32 callSetHandlers") \
    X(ParamBlock2CallSets, "Param", "result", "anim Anim") \
    X(ParamBlock2CallGets, "Param", "result", "anim Anim") \
    X(ParamBlock2GetValidity, "Param", "result", "anim Anim, int32 t, ptr:MaxMcpInterval valid") \
    X(NodeSetImageBlurMultController, "Node", "result", "node Node, anim cont") \
    X(NodeSetMotBlurOnOffController, "Node", "result", "node Node, anim cont") \
    X(NodeSetVisController, "Node", "result", "node Node, anim cont") \
    X(NodeSetMtl, "Node", "result", "node Node, anim matl") \
    X(NodeSetXRefParent, "Node", "result", "node Node, int32 i, node par, int32 autoOffset") \
    X(EPolyModEpModSetSelection, "EPoly", "result", "anim Mod, int32 meshSelectionLevel, ptr:MaxMcpSpan selection, node pNode, ptr:int32 OutValue") \
    X(EPolyModEpModSetPrimaryNode, "EPoly", "result", "anim Mod, node node") \
    X(EPolyModEpModGetNodeTM, "EPoly", "result", "anim Mod, int32 t, node node, ptr:MaxMcpMatrix3 OutValue") \
    X(EPolyModEpModCreateVertex, "EPoly", "result", "anim Mod, cptr:MaxMcpPoint3 p, node pNode, ptr:int32 OutValue") \
    X(EPolyModEpModSetDiagonal, "EPoly", "result", "anim Mod, int32 v1, int32 v2, node pNode") \
    X(EPolyModEpModCut, "EPoly", "result", "anim Mod, int32 startLevel, int32 startIndex, cptr:MaxMcpPoint3 startPoint, cptr:MaxMcpPoint3 normal, node pNode") \
    X(EPolyModEpModSetCutEnd, "EPoly", "result", "anim Mod, cptr:MaxMcpPoint3 endPoint, node pNode") \
    X(EPolyModEpModCutCancel, "EPoly", "result", "anim Mod, node pNode") \
    X(EPolyModEpModDivideEdge, "EPoly", "result", "anim Mod, int32 edge, float prop, node pNode") \
    X(EPolyModEpModWeldVerts, "EPoly", "result", "anim Mod, int32 v1, int32 v2, node pNode") \
    X(EPolyModEpModWeldEdges, "EPoly", "result", "anim Mod, int32 e1, int32 e2, node pNode") \
    X(EPolyModEpModAttach, "EPoly", "result", "anim Mod, node node, node pNode, int32 t") \
    X(EPolyModEpModSetHingeEdge, "EPoly", "result", "anim Mod, int32 edge, cptr:MaxMcpMatrix3 modContextTM, node pNode") \
    X(EPolyModEpModGetHingeEdge, "EPoly", "result", "anim Mod, node pNode, ptr:int32 OutValue") \
    X(EPolyModEpModBridgeBorders, "EPoly", "result", "anim Mod, int32 edge1, int32 edge2, node pNode") \
    X(EPolyModEpModBridgePolygons, "EPoly", "result", "anim Mod, int32 face1, int32 face2, node pNode") \
    X(EPolyModEpModSetBridgeNode, "EPoly", "result", "anim Mod, node pNode") \
    X(EPolyModEpModTurnDiagonal, "EPoly", "result", "anim Mod, int32 faceIndex, int32 diagonal, node pNode") \
    X(EPolyModEpModListOperations, "EPoly", "result", "anim Mod, node pNode") \
    X(EPolyModEpMeshGetNumVertices, "EPoly", "result", "anim Mod, node pNode, ptr:int32 OutValue") \
    X(EPolyModEpMeshGetNumEdges, "EPoly", "result", "anim Mod, node pNode, ptr:int32 OutValue") \
    X(EPolyModEpMeshGetNumFaces, "EPoly", "result", "anim Mod, node pNode, ptr:int32 OutValue") \
    X(EPolyModEpMeshGetFaceDiagonal, "EPoly", "result", "anim Mod, int32 faceIndex, int32 diagonal, int32 end, node pNode, ptr:int32 OutValue") \
    X(EPolyModEpModBridgeEdges, "EPoly", "result", "anim Mod, int32 in_edge1, int32 in_edge2, node in_pNode") \
    X(EPolyModEpModUpdateRingEdgeSelection, "EPoly", "result", "anim Mod, int32 in_val, node in_pNode") \
    X(EPolyModEpModUpdateLoopEdgeSelection, "EPoly", "result", "anim Mod, int32 in_val, node in_pNode") \
    X(EPolyModEPMeshGetFaceNormal, "EPoly", "result", "anim Mod, int32 in_faceIndex, node in_pNode, ptr:MaxMcpPoint3 OutValue") \
    X(EPolyModEPMeshGetFaceCenter, "EPoly", "result", "anim Mod, int32 in_faceIndex, node in_pNode, ptr:MaxMcpPoint3 OutValue") \
    X(EPolyModEPMeshGetFaceArea, "EPoly", "result", "anim Mod, int32 in_faceIndex, node in_pNode, ptr:float OutValue") \
    X(EPolyModEPMeshGetVertsByFlag, "EPoly", "result", "anim Mod, ptr:MaxMcpSpan out_vset, uint32 in_flags, uint32 in_fmask, node in_pNode, ptr:int32 OutValue") \
    X(EPolyModEPMeshGetEdgesByFlag, "EPoly", "result", "anim Mod, ptr:MaxMcpSpan out_eset, uint32 in_flags, uint32 in_fmask, node in_pNode, ptr:int32 OutValue") \
    X(EPolyModEPMeshGetFacesByFlag, "EPoly", "result", "anim Mod, ptr:MaxMcpSpan out_fset, uint32 in_flags, uint32 in_fmask, node in_pNode, ptr:int32 OutValue") \
    X(EPolyModEPMeshSetVertexFlags, "EPoly", "result", "anim Mod, ptr:MaxMcpSpan in_vset, uint32 in_flags, uint32 in_fmask, int32 in_undoable, node in_pNode") \
    X(EPolyModEPMeshSetEdgeFlags, "EPoly", "result", "anim Mod, ptr:MaxMcpSpan in_eset, uint32 in_flags, uint32 in_fmask, int32 in_undoable, node in_pNode") \
    X(EPolyModEPMeshSetFaceFlags, "EPoly", "result", "anim Mod, ptr:MaxMcpSpan in_fset, uint32 in_flags, uint32 in_fmask, int32 in_undoable, node in_pNode") \
    X(EPolyModEPMeshGetVertexFlags, "EPoly", "result", "anim Mod, int32 in_vertexIndex, node in_pNode, ptr:int32 OutValue") \
    X(EPolyModEPMeshGetEdgeFlags, "EPoly", "result", "anim Mod, int32 in_edgeIndex, node in_pNode, ptr:int32 OutValue") \
    X(EPolyModEPMeshGetFaceFlags, "EPoly", "result", "anim Mod, int32 in_faceIndex, node in_pNode, ptr:int32 OutValue") \
    X(EPolyModEPMeshGetVertsUsingEdge, "EPoly", "result", "anim Mod, ptr:MaxMcpSpan out_vset, cptr:MaxMcpSpan in_eset, node in_pNode") \
    X(EPolyModEPMeshSetVert, "EPoly", "result", "anim Mod, cptr:MaxMcpSpan in_vset, cptr:MaxMcpPoint3 in_point, node in_pNode") \
    X(SceneDisplayFilterIsNodeHidden, "Scene", "result", "int32 index, int32 sid, cptr:MaxMcpClassID cid, node node, ptr:int32 OutValue") \
    X(SceneGetTransformAxis, "Scene", "result", "node node, int32 subIndex, ptr:int32 local, ptr:MaxMcpMatrix3 OutValue") \
    X(SceneCreateObjectNode, "Scene", "result", "anim obj, ptr:node OutValue") \
    X(SceneBindToTarget, "Scene", "result", "node laNode, node targNode, ptr:int32 OutValue") \
    X(SceneDeleteNode, "Scene", "result", "node node, int32 redraw, int32 overrideDriven, ptr:uint32 OutValue") \
    X(SceneSetNodeTMRelConstPlane, "Scene", "result", "node node, cptr:MaxMcpMatrix3 mat") \
    X(SceneSelectNode, "Scene", "result", "node node, int32 clearSel") \
    X(SceneDeSelectNode, "Scene", "result", "node node") \
    X(SceneAddLightToScene, "Scene", "result", "node node") \
    X(SceneAddGridToScene, "Scene", "result", "node node") \
    X(SceneSetActiveGrid, "Scene", "result", "node node") \
    X(ScenePutMtlToMtlEditor, "Scene", "result", "anim mb, int32 slot") \
    X(SceneOkMtlForScene, "Scene", "result", "anim m, ptr:int32 OutValue") \
    X(SceneSetLightTintController, "Scene", "result", "anim c") \
    X(SceneSetLightLevelController, "Scene", "result", "anim c") \
    X(SceneSetBackGroundController, "Scene", "result", "anim c") \
    X(SceneDeActivateTexture, "Scene", "result", "anim tx, anim mtl, int32 subNum") \
    X(SceneActivateTexture, "Scene", "result", "anim tx, anim mtl, int32 subNum") \
    X(SceneAssignNewName, "Scene", "result", "anim m") \
    X(SceneIsSceneXRefNode, "Scene", "result", "node node, ptr:int32 OutValue") \
    X(SceneCollapseNode, "Scene", "result", "node node, int32 noWarning") \
    X(IBipDriverSetAttachNode, "IBip", "result", "anim Anim, node node") \
    X(IBipDriverSetHeadTarget, "IBip", "result", "anim Anim, node node") \
    X(IBipDriverSetBipedKey, "IBip", "result", "anim Anim, int32 t, node node, int32 setHor, int32 setVer, int32 setTurn") \
    X(IBipDriverSetPlantedKey, "IBip", "result", "anim Anim, int32 t, node node") \
    X(IBipDriverSetSlidingKey, "IBip", "result", "anim Anim, int32 t, node node") \
    X(IBipDriverSetFreeKey, "IBip", "result", "anim Anim, int32 t, node node") \
    X(IBipDriverSetBipedPos, "IBip", "result", "anim Anim, cptr:MaxMcpPoint3 p, int32 t, node node, int32 setKey") \
    X(IBipDriverSetBipedRot, "IBip", "result", "anim Anim, cptr:MaxMcpQuat q, int32 t, node node, int32 setKey") \
    X(IBipDriverSetSnapKey, "IBip", "result", "anim Anim, int32 t, node node") \
    X(IBipDriverCreatePosSubAnims, "IBip", "result", "anim Anim, anim controlToClone, int32 checkIfOneExists") \
    X(IBipDriverCreateRotSubAnims, "IBip", "result", "anim Anim, anim controlToClone, int32 checkIfOneExists") \
    X(IBipDriverCreateScaleSubAnims, "IBip", "result", "anim Anim, anim controlToClone, int32 checkIfOneExists") \
    X(IBipDriverSetPosSubAnim, "IBip", "result", "anim Anim, cptr:MaxMcpPoint3 p, int32 t, node node, int32 absolute") \
    X(IBipDriverSetRotSubAnim, "IBip", "result", "anim Anim, cptr:MaxMcpQuat q, int32 t, node node, int32 absolute") \
    X(IBipDriverCollapseRotSubAnims, "IBip", "result", "anim Anim, int32 perFrame, int32 keep, node node") \
    X(IBipDriverCollapsePosSubAnims, "IBip", "result", "anim Anim, int32 perFrame, int32 keep, node node") \
    X(ILayerSetDisplayByLayer, "ILayer", "result", "anim Layer, int32 onOff, node node") \
    X(ILayerSetRenderByLayer, "ILayer", "result", "anim Layer, int32 onOff, node node") \
    X(ILayerSetMotionByLayer, "ILayer", "result", "anim Layer, int32 onOff, node node") \
    X(ILayerGetDisplayByLayer, "ILayer", "result", "anim Layer, node node, ptr:int32 OutValue") \
    X(ILayerGetRenderByLayer, "ILayer", "result", "anim Layer, node node, ptr:int32 OutValue") \
    X(ILayerGetMotionByLayer, "ILayer", "result", "anim Layer, node node, ptr:int32 OutValue") \
    X(ILayerAddToLayer, "ILayer", "result", "anim Layer, node node, ptr:int32 OutValue") \
    X(ILayerDeleteFromLayer, "ILayer", "result", "anim Layer, node rtarg, ptr:int32 OutValue") \
    X(ControllerCopy, "Controller", "result", "anim Controller, anim from") \
    X(ControllerSetPositionController, "Controller", "result", "anim Controller, anim c, ptr:int32 OutValue") \
    X(ControllerSetRotationController, "Controller", "result", "anim Controller, anim c, ptr:int32 OutValue") \
    X(ControllerSetScaleController, "Controller", "result", "anim Controller, anim c, ptr:int32 OutValue") \
    X(ControllerSetRollController, "Controller", "result", "anim Controller, anim c, ptr:int32 OutValue") \
    X(ControllerOKToBindToNode, "Controller", "result", "anim Controller, node node, ptr:int32 OutValue") \
    X(Scene7AddRefCoordNode, "Scene7", "result", "node node") \
    X(Scene7AddModToSelection, "Scene7", "result", "anim mod") \
    X(Scene7InvalidateObCache, "Scene7", "result", "node node") \
    X(Scene7FindNodeFromBaseObject, "Scene7", "result", "anim obj, int32 allowXRefNodes, int32 allowNonSceneNodes, int32 allowScriptedPlugins, int32 allowXrefObjects, int32 handleBranching, int32 preferSelected, ptr:node OutValue") \
    X(Scene7SetMtlSlot, "Scene7", "result", "int32 i, anim m") \
    X(Scene7SetNodeAttribute, "Scene7", "result", "node node, int32 whatAttrib, int32 onOff") \
    X(GenLightSetHotSpotControl, "Gen", "result", "anim Object, anim c, ptr:int32 OutValue") \
    X(GenLightSetFalloffControl, "Gen", "result", "anim Object, anim c, ptr:int32 OutValue") \
    X(GenLightSetColorControl, "Gen", "result", "anim Object, anim c, ptr:int32 OutValue") \
    X(GenLightSetShadowProjMap, "Gen", "result", "anim Object, anim pmap") \
    X(TrackViewZoomOn, "Track", "result", "int32 Index, anim owner, int32 subnum") \
    X(TrackViewGetIndex, "Track", "result", "int32 Index, anim anim, ptr:int32 OutValue") \
    X(TrackViewSelectTrack, "Track", "result", "int32 Index, anim anim, int32 clearSelection") \
    X(TrackViewSetRootTrack, "Track", "result", "int32 Index, anim root") \
    X(LightscapeLightUpdateTargDistance, "Lightscape", "result", "anim Anim, int32 t, node inode") \
    X(LightscapeLightSetKelvinControl, "Lightscape", "result", "anim Anim, anim kelvin, ptr:int32 OutValue") \
    X(LightscapeLightSetFilterControl, "Lightscape", "result", "anim Anim, anim filter, ptr:int32 OutValue") \
    X(EPolyEpfnDetachToObject, "EPoly", "result", "anim Object, cstr name, int32 msl, uint32 flag, int32 keepOriginal, node myNode, int32 t, ptr:int32 OutValue") \
    X(EPolyEpfnCreateShape, "EPoly", "result", "anim Object, cstr name, int32 smooth, node myNode, uint32 edgeFlag, ptr:int32 OutValue") \
    X(PatchSetVertCont, "Patch", "result", "anim Object, int32 i, anim c") \
    X(PatchSetVecCont, "Patch", "result", "anim Object, int32 i, anim c") \
    X(ViewExpSetViewCamera, "View", "result", "hwnd Win, node camNode") \
    X(ViewExpSetViewSpot, "View", "result", "hwnd Win, node spotNode") \
    X(GenCameraSetFOVControl, "Gen", "result", "anim Anim, anim c, ptr:int32 OutValue") \
    X(LightObjSetProjMap, "Light", "result", "anim Object, anim pmap") \
    X(NodeBakeProjSetProjMod, "Node", "result", "node Node, anim refTarg") \
    X(ParamBlock2SetControllerByIndex, "Param", "result", "anim Anim, int32 i, int32 tabIndex, anim c, int32 preserveFrame0Value") \
    X(ParticleExtUpdateParticles, "Particle", "result", "anim Object, node node, int32 t") \
    X(Scene16SetOverrideRenderSettingMtl, "Scene16", "result", "anim pOverrideRenderSettingMtl") \
    X(Scene17IsSceneNode, "Scene17", "result", "node node, ptr:int32 OutValue") \
    X(Scene8SetRendCamNode, "Scene8", "result", "node camNode") \
    X(SplineSetPtCont, "Spline", "result", "node Node, int32 i, anim c") \
    X(ParamBlock2IDtoIndex, "Param", "result", "anim Anim, int32 id, ptr:int32 OutValue") \
    X(ParamBlock2IndextoID, "Param", "result", "anim Anim, int32 i, ptr:int32 OutValue") \
    X(ParamBlock2SetValue, "Param", "result", "anim Anim, int32 id, int32 t, float v, int32 tabIndex, ptr:int32 OutValue") \
    X(ParamBlock2GetValue, "Param", "result", "anim Anim, int32 id, int32 t, ptr:MaxMcpPoint2 v, ptr:MaxMcpInterval ivalid, int32 tabIndex, ptr:int32 OutValue") \
    X(ParamBlock2GetColor, "Param", "result", "anim Anim, int32 id, int32 t, int32 tabIndex, ptr:MaxMcpColor OutValue") \
    X(ParamBlock2GetAColor, "Param", "result", "anim Anim, int32 id, int32 t, int32 tabIndex, ptr:MaxMcpAColor OutValue") \
    X(ParamBlock2GetPoint2, "Param", "result", "anim Anim, int32 id, int32 t, int32 tabIndex, ptr:MaxMcpPoint2 OutValue") \
    X(ParamBlock2GetPoint3, "Param", "result", "anim Anim, int32 id, int32 t, int32 tabIndex, ptr:MaxMcpPoint3 OutValue") \
    X(ParamBlock2GetPoint4, "Param", "result", "anim Anim, int32 id, int32 t, int32 tabIndex, ptr:MaxMcpPoint4 OutValue") \
    X(ParamBlock2GetInt, "Param", "result", "anim Anim, int32 id, int32 t, int32 tabIndex, ptr:int32 OutValue") \
    X(ParamBlock2GetFloat, "Param", "result", "anim Anim, int32 id, int32 t, int32 tabIndex, ptr:float OutValue") \
    X(ParamBlock2GetTimeValue, "Param", "result", "anim Anim, int32 id, int32 t, int32 tabIndex, ptr:int32 OutValue") \
    X(ParamBlock2GetStr, "Param", "result", "anim Anim, int32 id, int32 t, int32 tabIndex, ptr:MaxMcpStrOut OutValue") \
    X(ParamBlock2GetMtl, "Param", "result", "anim Anim, int32 id, int32 t, int32 tabIndex, ptr:anim OutValue") \
    X(ParamBlock2GetTexmap, "Param", "result", "anim Anim, int32 id, int32 t, int32 tabIndex, ptr:anim OutValue") \
    X(ParamBlock2GetINode, "Param", "result", "anim Anim, int32 id, int32 t, int32 tabIndex, ptr:node OutValue") \
    X(ParamBlock2GetReferenceTarget, "Param", "result", "anim Anim, int32 id, int32 t, int32 tabIndex, ptr:anim OutValue") \
    X(ParamBlock2GetMatrix3, "Param", "result", "anim Anim, int32 id, int32 t, int32 tabIndex, ptr:MaxMcpMatrix3 OutValue") \
    X(ParamBlock2Count, "Param", "result", "anim Anim, int32 id, ptr:int32 OutValue") \
    X(ParamBlock2ZeroCount, "Param", "result", "anim Anim, int32 id") \
    X(ParamBlock2SetCount, "Param", "result", "anim Anim, int32 id, int32 n") \
    X(ParamBlock2Delete, "Param", "result", "anim Anim, int32 id, int32 start, int32 num, ptr:int32 OutValue") \
    X(ParamBlock2Resize, "Param", "result", "anim Anim, int32 id, int32 num, ptr:int32 OutValue") \
    X(ParamBlock2Shrink, "Param", "result", "anim Anim, int32 id") \
    X(ParamBlock2KeyFrameAtTimeByID, "Param", "result", "anim Anim, int32 id, int32 t, int32 tabIndex, ptr:int32 OutValue") \
    X(ParamBlock2SetControllerByID, "Param", "result", "anim Anim, int32 id, int32 tabIndex, anim c, int32 preserveFrame0Value") \
    X(ParamBlock2GetAnimNum, "Param", "result", "anim Anim, int32 id, int32 tabIndex, ptr:int32 OutValue") \
    X(ParamBlock2RefDeleted, "Param", "result", "anim Anim, int32 id, int32 tabIndex") \
    X(ParamBlock2DefineParamAlias, "Param", "result", "anim Anim, cstr alias_name, int32 id, int32 tabIndex") \
    X(ParamBlock2FindParamAlias, "Param", "result", "anim Anim, int32 id, int32 tabIndex, ptr:MaxMcpStrOut OutValue") \
    X(ParamBlock2SetSubAnimNum, "Param", "result", "anim Anim, int32 id, int32 subAnimNum, int32 tabIndex") \
    X(ParamBlock2Reset, "Param", "result", "anim Anim, int32 id, int32 tabIndex, int32 updateUI, int32 callSetHandlers") \
    X(ParamBlock2CallSet, "Param", "result", "anim Anim, int32 id, int32 tabIndex") \
    X(ParamBlock2CallGet, "Param", "result", "anim Anim, int32 id, int32 tabIndex") \
    X(RefMakerDeleteMe, "Ref", "result", "anim Anim") \
    X(RefMakerDeleteAllRefsFromMe, "Ref", "result", "anim Anim, ptr:int32 OutValue") \
    X(RefMakerDeleteAllRefsToMe, "Ref", "result", "anim Anim, ptr:int32 OutValue") \
    X(RefMakerDeleteAllRefs, "Ref", "result", "anim Anim, ptr:int32 OutValue") \
    X(RefMakerDeleteReference, "Ref", "result", "anim Anim, int32 i, ptr:int32 OutValue") \
    X(RefMakerCanTransferReference, "Ref", "result", "anim Anim, int32 i, ptr:int32 OutValue") \
    X(RefMakerGetReference, "Ref", "result", "anim Anim, int32 i, ptr:anim OutValue") \
    X(RefMakerRescaleWorldUnits, "Ref", "result", "anim Anim, float f") \
    X(RefMakerFindRef, "Ref", "result", "anim Anim, anim rtarg, ptr:int32 OutValue") \
    X(RefMakerIsRefTarget, "Ref", "result", "anim Anim, ptr:int32 OutValue") \
    X(RefMakerIsRealDependency, "Ref", "result", "anim Anim, anim rtarg, ptr:int32 OutValue") \
    X(SplineInvalidateChannels, "Spline", "result", "node Node, uint32 channels") \
    X(SplineFreeChannels, "Spline", "result", "node Node, uint32 chan") \
    X(SplineShallowCopy, "Spline", "result", "node Node, anim fromOb, uint32 channels") \
    X(SplineNewAndCopyChannels, "Spline", "result", "node Node, uint32 channels") \
    X(SplineMultiAttachObject, "Spline", "result", "node Node, cptr:MaxMcpSpan nodeTab") \
    X(SceneSelectNodeTab, "Scene", "result", "cptr:MaxMcpSpan nodes, int32 sel, int32 redraw") \
    X(SceneFileSaveNodes, "Scene", "result", "cptr:MaxMcpSpan nodes, cstr fname") \
    X(SceneUngroupNodes, "Scene", "result", "cptr:MaxMcpSpan nodes") \
    X(SceneExplodeNodes, "Scene", "result", "cptr:MaxMcpSpan nodes") \
    X(SceneOpenGroup, "Scene", "result", "cptr:MaxMcpSpan nodes, int32 clearSel") \
    X(SceneCloseGroup, "Scene", "result", "cptr:MaxMcpSpan nodes, int32 selGroup") \
    X(SceneDetachNodesFromGroup, "Scene", "result", "cptr:MaxMcpSpan nodes, ptr:int32 OutValue") \
    X(SceneFlashNodes, "Scene", "result", "cptr:MaxMcpSpan nodes") \
    X(ObjectCopyChannelLocks, "Object", "result", "anim Anim, anim obj, uint32 needChannels") \
    X(ObjectReadyChannelsForMod, "Object", "result", "anim Anim, uint32 channels") \
    X(ObjectMakeShallowCopy, "Object", "result", "anim Anim, uint32 channels, ptr:anim OutValue") \
    X(ObjectShallowCopy, "Object", "result", "anim Anim, anim fromOb, uint32 channels") \
    X(ObjectFreeChannels, "Object", "result", "anim Anim, uint32 channels") \
    X(ObjectNewAndCopyChannels, "Object", "result", "anim Anim, uint32 channels") \
    X(PatchInvalidateChannels, "Patch", "result", "anim Object, uint32 channels") \
    X(PatchFreeChannels, "Patch", "result", "anim Object, uint32 chan") \
    X(PatchShallowCopy, "Patch", "result", "anim Object, anim fromOb, uint32 channels") \
    X(PatchNewAndCopyChannels, "Patch", "result", "anim Object, uint32 channels") \
    X(Scene7PutMaterial, "Scene7", "result", "anim mtl, anim oldMtl, int32 delOld, anim skipThis") \
    X(PolyNewAndCopyChannels, "Poly", "result", "anim Object, uint32 channels") \
    X(PolyFreeChannels, "Poly", "result", "anim Object, uint32 channels, int32 zeroOthers") \
    X(MeshNewAndCopyChannels, "Mesh", "result", "anim Object, uint32 channels") \
    X(MeshFreeChannels, "Mesh", "result", "anim Object, uint32 channels, int32 zeroOthers") \
    X(PatchMeshNewAndCopyChannels, "Patch", "result", "anim Object, uint32 channels") \
    X(PatchMeshFreeChannels, "Patch", "result", "anim Object, uint32 channels, int32 zeroOthers") \
    X(EPolyLocalDataChanged, "EPoly", "result", "anim Object, uint32 channels") \
    X(EPolyEpfnMultiAttach, "EPoly", "result", "anim Object, cptr:MaxMcpSpan nodeTab, node myNode, int32 t") \
    X(BezierShapeNewAndCopyChannels, "Bezier", "result", "node Node, uint32 channels") \
    X(BezierShapeFreeChannels, "Bezier", "result", "node Node, uint32 channels, int32 zeroOthers") \
    X(Scene13SaveNodesAsVersion, "Scene13", "result", "cstr fname, cptr:MaxMcpSpan nodes, uint32 saveAsVersion, ptr:int32 OutValue") \
    X(EPolyModEpModLocalDataChanged, "EPoly", "result", "anim Mod, uint32 channels") \
    X(ModifierGetName, "Modifier", "result", "anim Anim, int32 localized, ptr:MaxMcpStrOut OutValue") \
    X(ModifierDisableModApps, "Modifier", "result", "anim Anim") \
    X(ModifierEnableModApps, "Modifier", "result", "anim Anim") \
    X(ModifierDisableMod, "Modifier", "result", "anim Anim") \
    X(ModifierEnableMod, "Modifier", "result", "anim Anim") \
    X(ModifierIsEnabled, "Modifier", "result", "anim Anim, ptr:int32 OutValue") \
    X(ModifierDisableModInViews, "Modifier", "result", "anim Anim") \
    X(ModifierEnableModInViews, "Modifier", "result", "anim Anim") \
    X(ModifierIsEnabledInViews, "Modifier", "result", "anim Anim, ptr:int32 OutValue") \
    X(ModifierDisableModInRender, "Modifier", "result", "anim Anim") \
    X(ModifierEnableModInRender, "Modifier", "result", "anim Anim") \
    X(ModifierIsEnabledInRender, "Modifier", "result", "anim Anim, ptr:int32 OutValue") \
    X(ModifierLocalValidity, "Modifier", "result", "anim Anim, int32 t, ptr:MaxMcpInterval OutValue") \
    X(ModifierChangesSelType, "Modifier", "result", "anim Anim, ptr:int32 OutValue") \
    X(ModifierTotalChannelsUsed, "Modifier", "result", "anim Anim, ptr:uint32 OutValue") \
    X(ModifierTotalChannelsChanged, "Modifier", "result", "anim Anim, ptr:uint32 OutValue") \
    X(ModifierAnyObjectFilter, "Modifier", "result", "anim Anim, anim object, ptr:int32 OutValue") \
    X(ModifierShouldCollapseOnSave, "Modifier", "result", "anim Anim, ptr:int32 OutValue") \
    X(ModifierCopyAdditionalChannels, "Modifier", "result", "anim Anim, anim fromObj, anim toObj") \
    X(MtlGetActiveTexmap, "Mtl", "result", "anim Anim, ptr:anim OutValue") \
    X(MtlSetActiveTexmap, "Mtl", "result", "anim Anim, anim txm") \
    X(MtlRefDeleted, "Mtl", "result", "anim Anim, anim rm") \
    X(MtlRefAdded, "Mtl", "result", "anim Anim, anim rm") \
    X(MtlGetAmbient, "Mtl", "result", "anim Anim, int32 mtlNum, int32 backFace, ptr:MaxMcpColor OutValue") \
    X(MtlGetDiffuse, "Mtl", "result", "anim Anim, int32 mtlNum, int32 backFace, ptr:MaxMcpColor OutValue") \
    X(MtlGetSpecular, "Mtl", "result", "anim Anim, int32 mtlNum, int32 backFace, ptr:MaxMcpColor OutValue") \
    X(MtlGetShininess, "Mtl", "result", "anim Anim, int32 mtlNum, int32 backFace, ptr:float OutValue") \
    X(MtlGetShinStr, "Mtl", "result", "anim Anim, int32 mtlNum, int32 backFace, ptr:float OutValue") \
    X(MtlGetXParency, "Mtl", "result", "anim Anim, int32 mtlNum, int32 backFace, ptr:float OutValue") \
    X(MtlGetSelfIllumColorOn, "Mtl", "result", "anim Anim, int32 mtlNum, int32 backFace, ptr:int32 OutValue") \
    X(MtlGetSelfIllum, "Mtl", "result", "anim Anim, int32 mtlNum, int32 backFace, ptr:float OutValue") \
    X(MtlGetSelfIllumColor, "Mtl", "result", "anim Anim, int32 mtlNum, int32 backFace, ptr:MaxMcpColor OutValue") \
    X(MtlWireSize, "Mtl", "result", "anim Anim, int32 mtlNum, int32 backFace, ptr:float OutValue") \
    X(MtlSetAmbient, "Mtl", "result", "anim Anim, cptr:MaxMcpColor c, int32 t") \
    X(MtlSetDiffuse, "Mtl", "result", "anim Anim, cptr:MaxMcpColor c, int32 t") \
    X(MtlSetSpecular, "Mtl", "result", "anim Anim, cptr:MaxMcpColor c, int32 t") \
    X(MtlSetShininess, "Mtl", "result", "anim Anim, float v, int32 t") \
    X(MtlSupportsShaders, "Mtl", "result", "anim Anim, ptr:int32 OutValue") \
    X(MtlSupportsRenderElements, "Mtl", "result", "anim Anim, ptr:int32 OutValue") \
    X(MtlNumSubMtls, "Mtl", "result", "anim Anim, ptr:int32 OutValue") \
    X(MtlGetSubMtl, "Mtl", "result", "anim Anim, int32 i, ptr:anim OutValue") \
    X(MtlSetSubMtl, "Mtl", "result", "anim Anim, int32 i, anim m") \
    X(MtlVPDisplaySubMtl, "Mtl", "result", "anim Anim, ptr:int32 OutValue") \
    X(MtlGetSubMtlSlotName, "Mtl", "result", "anim Anim, int32 i, int32 localized, ptr:MaxMcpStrOut OutValue") \
    X(MtlGetSubMtlTVName, "Mtl", "result", "anim Anim, int32 i, int32 localized, ptr:MaxMcpStrOut OutValue") \
    X(MtlCopySubMtl, "Mtl", "result", "anim Anim, hwnd hwnd, int32 ifrom, int32 ito") \
    X(MtlDontKeepOldMtl, "Mtl", "result", "anim Anim, ptr:int32 OutValue") \
    X(MtlResolveWrapperMaterials, "Mtl", "result", "anim Anim, int32 forUseInViewport, ptr:anim OutValue") \
    X(MorphByBoneFnAddBone, "Morph", "result", "anim Anim, node node") \
    X(MorphByBoneFnRemoveBone, "Morph", "result", "anim Anim, node node") \
    X(MorphByBoneFnSelectBone, "Morph", "result", "anim Anim, node node, cstr morphName") \
    X(MorphByBoneFnGetSelectedBone, "Morph", "result", "anim Anim, ptr:node OutValue") \
    X(MorphByBoneFnGetSelectedMorph, "Morph", "result", "anim Anim, ptr:MaxMcpStrOut OutValue") \
    X(MorphByBoneFnResetGraph, "Morph", "result", "anim Anim") \
    X(MorphByBoneFnShrink, "Morph", "result", "anim Anim") \
    X(MorphByBoneFnGrow, "Morph", "result", "anim Anim") \
    X(MorphByBoneFnRing, "Morph", "result", "anim Anim") \
    X(MorphByBoneFnLoop, "Morph", "result", "anim Anim") \
    X(MorphByBoneFnCreateMorph, "Morph", "result", "anim Anim, node node") \
    X(MorphByBoneFnRemoveMorph, "Morph", "result", "anim Anim, node node, cstr name") \
    X(MorphByBoneFnEdit, "Morph", "result", "anim Anim, int32 edit") \
    X(MorphByBoneFnClearSelectedVertices, "Morph", "result", "anim Anim") \
    X(MorphByBoneFnDeleteSelectedVertices, "Morph", "result", "anim Anim") \
    X(MorphByBoneFnResetOrientation, "Morph", "result", "anim Anim, node node, cstr name") \
    X(MorphByBoneFnReloadTarget, "Morph", "result", "anim Anim, node node, cstr name") \
    X(MorphByBoneFnMirrorPaste, "Morph", "result", "anim Anim, node node") \
    X(MorphByBoneFnEditFalloffGraph, "Morph", "result", "anim Anim, node node, cstr name") \
    X(MorphByBoneFnSetExternalNode, "Morph", "result", "anim Anim, node node, cstr name, node exnode") \
    X(MorphByBoneFnMoveVerts, "Morph", "result", "anim Anim, cptr:MaxMcpPoint3 vec") \
    X(MorphByBoneFnTransFormVerts, "Morph", "result", "anim Anim, cptr:MaxMcpMatrix3 a, cptr:MaxMcpMatrix3 b") \
    X(MorphByBoneFnBoneSetInitialNodeTM, "Morph", "result", "anim Anim, node node, cptr:MaxMcpMatrix3 tm") \
    X(MorphByBoneFnBoneSetInitialObjectTM, "Morph", "result", "anim Anim, node node, cptr:MaxMcpMatrix3 tm") \
    X(MorphByBoneFnBoneSetInitialParentTM, "Morph", "result", "anim Anim, node node, cptr:MaxMcpMatrix3 tm") \
    X(MorphByBoneFnBoneGetNumberOfMorphs, "Morph", "result", "anim Anim, node node, ptr:int32 OutValue") \
    X(MorphByBoneFnBoneSetMorphName, "Morph", "result", "anim Anim, node node, int32 morphIndex, cstr name") \
    X(MorphByBoneFnBoneSetMorphAngle, "Morph", "result", "anim Anim, node node, int32 morphIndex, float angle") \
    X(MorphByBoneFnBoneSetMorphTM, "Morph", "result", "anim Anim, node node, int32 morphIndex, cptr:MaxMcpMatrix3 tm") \
    X(MorphByBoneFnBoneSetMorphParentTM, "Morph", "result", "anim Anim, node node, int32 morphIndex, cptr:MaxMcpMatrix3 tm") \
    X(MorphByBoneFnBoneSetMorphSetDead, "Morph", "result", "anim Anim, node node, int32 morphIndex, int32 dead") \
    X(MorphByBoneFnBoneSetMorphNumPoints, "Morph", "result", "anim Anim, node node, int32 morphIndex, int32 numberPoints") \
    X(MorphByBoneFnBoneSetMorphVertID, "Morph", "result", "anim Anim, node node, int32 morphIndex, int32 ithIndex, int32 vertIndex") \
    X(MorphByBoneFnBoneSetMorphVec, "Morph", "result", "anim Anim, node node, int32 morphIndex, int32 ithIndex, cptr:MaxMcpPoint3 vec") \
    X(MorphByBoneFnBoneSetMorphPVec, "Morph", "result", "anim Anim, node node, int32 morphIndex, int32 ithIndex, cptr:MaxMcpPoint3 vec") \
    X(MorphByBoneFnBoneSetMorphOP, "Morph", "result", "anim Anim, node node, int32 morphIndex, int32 ithIndex, cptr:MaxMcpPoint3 vec") \
    X(MorphByBoneFnBoneGetMorphOwner, "Morph", "result", "anim Anim, node node, int32 morphIndex, int32 ithIndex, ptr:node OutValue") \
    X(MorphByBoneFnBoneSetMorphOwner, "Morph", "result", "anim Anim, node node, int32 morphIndex, int32 ithIndex, node onode") \
    X(MorphByBoneFnBoneSetMorphFalloff, "Morph", "result", "anim Anim, node node, int32 morphIndex, int32 falloff") \
    X(MorphByBoneFnBoneSetJointType, "Morph", "result", "anim Anim, node node, int32 jointType") \
    X(MorphByBoneFnUpdate, "Morph", "result", "anim Anim") \
    X(MorphByBoneFnGetWeight, "Morph", "result", "anim Anim, node node, cstr name, ptr:float OutValue") \
    X(MorphByBoneFnBoneSetMorphEnabled, "Morph", "result", "anim Anim, node node, int32 morphIndex, int32 enabled") \
    X(ProjectionModNumObjects, "Projection", "result", "anim Anim, ptr:int32 OutValue") \
    X(ProjectionModGetObjectSelLevel, "Projection", "result", "anim Anim, int32 iIndex, ptr:int32 OutValue") \
    X(ProjectionModDeleteObjectNode, "Projection", "result", "anim Anim, int32 iIndex") \
    X(ProjectionModNumGeomSels, "Projection", "result", "anim Anim, ptr:int32 OutValue") \
    X(ProjectionModGetGeomSelSelLevel, "Projection", "result", "anim Anim, int32 iSelIndex, ptr:int32 OutValue") \
    X(ProjectionModNumGeomSelNodes, "Projection", "result", "anim Anim, int32 iSelIndex, ptr:int32 OutValue") \
    X(ProjectionModSetGeomSelMapProportion, "Projection", "result", "anim Anim, int32 iSelIndex, float fProportion") \
    X(ProjectionModGetGeomSelMapProportion, "Projection", "result", "anim Anim, int32 iSelIndex, ptr:float OutValue") \
    X(ProjectionModDeleteGeomSel, "Projection", "result", "anim Anim, int32 iSelIndex") \
    X(ProjectionModDeleteGeomSelNode, "Projection", "result", "anim Anim, int32 iSelIndex, int32 iNodeIndex") \
    X(ProjectionModIsValidObject, "Projection", "result", "anim Anim, node pNode, ptr:int32 OutValue") \
    X(ProjectionModAddObjectNode, "Projection", "result", "anim Anim, node pNode, ptr:int32 OutValue") \
    X(ProjectionModDeleteAll, "Projection", "result", "anim Anim") \
    X(ProjectionModSetGeomSelNodesVisibility, "Projection", "result", "anim Anim, int32 bVisible") \
    X(ProjectionModGetGeomSelNodesVisibility, "Projection", "result", "anim Anim, ptr:int32 OutValue") \
    X(ProjectionModUpdateProjectionTypeList, "Projection", "result", "anim Anim") \
    X(ProjectionModAutoWrapCage, "Projection", "result", "anim Anim") \
    X(ProjectionModResetCage, "Projection", "result", "anim Anim") \
    X(ProjectionModPushCage, "Projection", "result", "anim Anim, float fAmount") \
    X(ProjectionModFpGetGeomSelFaceArea, "Projection", "result", "anim Anim, node pNode, int32 iSelIndex, ptr:float OutValue") \
    X(ProjectionModFpCheckDuplicateMatIDs, "Projection", "result", "anim Anim, node pNode, ptr:MaxMcpSpan bitFaceDups, ptr:int32 OutValue") \
    X(ProjectionModFpCheckDuplicateSels, "Projection", "result", "anim Anim, node pNode, ptr:MaxMcpSpan bitFaceDups, ptr:int32 OutValue") \
    X(ProjectionModFpSelectByMtlID, "Projection", "result", "anim Anim, int32 iMtlID") \
    X(ProjectionModFpSelectBySG, "Projection", "result", "anim Anim, int32 iSG") \
    X(ProjectionModFpGetNumProjectionTypes, "Projection", "result", "anim Anim, ptr:int32 OutValue") \
    X(ProjectionModFpGetProjectionType, "Projection", "result", "anim Anim, int32 iIndex, ptr:anim OutValue") \
    X(ProjectionModFpRemoveProjectionType, "Projection", "result", "anim Anim, int32 iIndex") \
    X(ProjectionModFpProject, "Projection", "result", "anim Anim, int32 iIndex") \
    X(ProjectionModFpProjectAll, "Projection", "result", "anim Anim") \
    X(ProjectionModFpGetNumRegisteredProjectionTypes, "Projection", "result", "anim Anim, ptr:int32 OutValue") \
    X(ProjectionModFpAddRegisteredProjectionType, "Projection", "result", "anim Anim, int32 iIndex") \
    X(ProjectionModFpShowAlignment, "Projection", "result", "anim Anim") \
    X(ProjectionModFpClearAlignment, "Projection", "result", "anim Anim") \
    X(EditNormalsModEnfnSetSelLevel, "Edit", "result", "anim Anim, int32 selLevel") \
    X(EditNormalsModEnfnMove, "Edit", "result", "anim Anim, ptr:MaxMcpPoint3 offset, int32 t, ptr:int32 OutValue") \
    X(EditNormalsModEnfnRotate, "Edit", "result", "anim Anim, ptr:MaxMcpQuat rotation, int32 t, ptr:int32 OutValue") \
    X(EditNormalsModEnfnCopyNormal, "Edit", "result", "anim Anim, int32 normalID, node pNode, ptr:int32 OutValue") \
    X(EditNormalsModEnfnAverageGlobalNormals, "Edit", "result", "anim Anim, int32 useThresh, float threshold, ptr:int32 OutValue") \
    X(EditNormalsModEnfnAverageTwoNormals, "Edit", "result", "anim Anim, node pNode1, int32 normID1, node pNode2, int32 normID2, ptr:int32 OutValue") \
    X(EditNormalsModEnfnSetSelection, "Edit", "result", "anim Anim, ptr:MaxMcpSpan selection, node pNode, ptr:int32 OutValue") \
    X(EditNormalsModEnfnSelect, "Edit", "result", "anim Anim, ptr:MaxMcpSpan selection, int32 invert, int32 select, node pNode, ptr:int32 OutValue") \
    X(EditNormalsModEnfnGetNumNormals, "Edit", "result", "anim Anim, node pNode, ptr:int32 OutValue") \
    X(EditNormalsModEnfnSetNormal, "Edit", "result", "anim Anim, int32 normalID, ptr:MaxMcpPoint3 direction, node pNode, int32 t") \
    X(EditNormalsModEnfnSetNormalExplicit, "Edit", "result", "anim Anim, int32 normID, int32 value, node pNode") \
    X(EditNormalsModEnfnGetNumFaces, "Edit", "result", "anim Anim, node pNode, ptr:int32 OutValue") \
    X(EditNormalsModEnfnGetFaceDegree, "Edit", "result", "anim Anim, int32 face, node pNode, ptr:int32 OutValue") \
    X(EditNormalsModEnfnGetNormalID, "Edit", "result", "anim Anim, int32 face, int32 corner, node pNode, ptr:int32 OutValue") \
    X(EditNormalsModEnfnSetNormalID, "Edit", "result", "anim Anim, int32 face, int32 corner, int32 normalID, node pNode") \
    X(EditNormalsModEnfnGetFaceNormalSpecified, "Edit", "result", "anim Anim, int32 face, int32 corner, node pNode, ptr:int32 OutValue") \
    X(EditNormalsModEnfnSetFaceNormalSpecified, "Edit", "result", "anim Anim, int32 face, int32 corner, int32 specified, node pNode") \
    X(EditNormalsModEnfnGetNumVertices, "Edit", "result", "anim Anim, node pNode, ptr:int32 OutValue") \
    X(EditNormalsModEnfnGetVertexID, "Edit", "result", "anim Anim, int32 face, int32 corner, node pNode, ptr:int32 OutValue") \
    X(EditNormalsModEnfnGetVertex, "Edit", "result", "anim Anim, int32 vertexID, node pNode, int32 t, ptr:MaxMcpPoint3 OutValue") \
    X(EditNormalsModEnfnGetNumEdges, "Edit", "result", "anim Anim, node pNode, ptr:int32 OutValue") \
    X(EditNormalsModEnfnGetEdgeID, "Edit", "result", "anim Anim, int32 faceIndex, int32 sideIndex, node pNode, ptr:int32 OutValue") \
    X(EditNormalsModEnfnGetFaceEdgeSide, "Edit", "result", "anim Anim, int32 faceIndex, int32 edgeIndex, node pNode, ptr:int32 OutValue") \
    X(EditNormalsModEnfnGetEdgeVertex, "Edit", "result", "anim Anim, int32 edgeIndex, int32 end, node pNode, ptr:int32 OutValue") \
    X(EditNormalsModEnfnGetEdgeFace, "Edit", "result", "anim Anim, int32 edgeIndex, int32 side, node pNode, ptr:int32 OutValue") \
    X(EditNormalsModEnfnGetEdgeNormal, "Edit", "result", "anim Anim, int32 edgeIndex, int32 end, int32 side, node pNode, ptr:int32 OutValue") \
    X(EditNormalsModEnfnRebuildNormals, "Edit", "result", "anim Anim, node pNode") \
    X(EditNormalsModEnfnRecomputeNormals, "Edit", "result", "anim Anim, node pNode") \
    X(SplineHandleGet, "Spline", "spline", "node Node, int32 Index") \
    X(SplineCurveNewSpline, "Spline", "result", "spline Spline") \
    X(SplineCurveSegments, "Spline", "result", "spline Spline, ptr:int32 OutValue") \
    X(SplineCurveDeleteKnot, "Spline", "result", "spline Spline, int32 where, ptr:int32 OutValue") \
    X(SplineCurveGetParam, "Spline", "result", "spline Spline, int32 index, ptr:float OutValue") \
    X(SplineCurveSetKnotType, "Spline", "result", "spline Spline, int32 index, int32 type, ptr:int32 OutValue") \
    X(SplineCurveSetLineType, "Spline", "result", "spline Spline, int32 index, int32 type, ptr:int32 OutValue") \
    X(SplineCurveCustomParams, "Spline", "result", "spline Spline") \
    X(SplineCurveCompParams, "Spline", "result", "spline Spline") \
    X(SplineCurveComputeBezPoints, "Spline", "result", "spline Spline") \
    X(SplineCurveRefineCurve, "Spline", "result", "spline Spline, float u, int32 ptype") \
    X(SplineCurveRefineSegment, "Spline", "result", "spline Spline, int32 segment, float t, int32 ptype") \
    X(SplineCurveInterpBezier3D, "Spline", "result", "spline Spline, int32 segment, float t, int32 ptype, ptr:MaxMcpPoint3 OutValue") \
    X(SplineCurveInterpCurve3D, "Spline", "result", "spline Spline, float u, int32 ptype, ptr:MaxMcpPoint3 OutValue") \
    X(SplineCurveTangentBezier3D, "Spline", "result", "spline Spline, int32 segment, float t, int32 ptype, ptr:MaxMcpPoint3 OutValue") \
    X(SplineCurveTangentCurve3D, "Spline", "result", "spline Spline, float u, int32 ptype, ptr:MaxMcpPoint3 OutValue") \
    X(SplineCurveIsAuto, "Spline", "result", "spline Spline, int32 i, ptr:int32 OutValue") \
    X(SplineCurveIsBezierPt, "Spline", "result", "spline Spline, int32 i, ptr:int32 OutValue") \
    X(SplineCurveIsCorner, "Spline", "result", "spline Spline, int32 i, ptr:int32 OutValue") \
    X(SplineCurveDrawPhase, "Spline", "result", "spline Spline, ptr:int32 OutValue") \
    X(SplineCurveGetiCur, "Spline", "result", "spline Spline, ptr:int32 OutValue") \
    X(SplineCurveGetBBox, "Spline", "result", "spline Spline, int32 t, ptr:MaxMcpMatrix3 tm, ptr:MaxMcpBox3 box") \
    X(SplineCurveSetClosed, "Spline", "result", "spline Spline, int32 flag, ptr:int32 OutValue") \
    X(SplineCurveSetOpen, "Spline", "result", "spline Spline, ptr:int32 OutValue") \
    X(SplineCurveDump, "Spline", "result", "spline Spline, int32 where") \
    X(SplineCurveGetInVec, "Spline", "result", "spline Spline, int32 i, ptr:MaxMcpPoint3 OutValue") \
    X(SplineCurveSetInVec, "Spline", "result", "spline Spline, int32 i, cptr:MaxMcpPoint3 p") \
    X(SplineCurveGetRelInVec, "Spline", "result", "spline Spline, int32 i, ptr:MaxMcpPoint3 OutValue") \
    X(SplineCurveSetRelInVec, "Spline", "result", "spline Spline, int32 i, cptr:MaxMcpPoint3 p") \
    X(SplineCurveGetKnotPoint, "Spline", "result", "spline Spline, int32 i, ptr:MaxMcpPoint3 OutValue") \
    X(SplineCurveSetKnotPoint, "Spline", "result", "spline Spline, int32 i, cptr:MaxMcpPoint3 p") \
    X(SplineCurveGetOutVec, "Spline", "result", "spline Spline, int32 i, ptr:MaxMcpPoint3 OutValue") \
    X(SplineCurveSetOutVec, "Spline", "result", "spline Spline, int32 i, cptr:MaxMcpPoint3 p") \
    X(SplineCurveGetRelOutVec, "Spline", "result", "spline Spline, int32 i, ptr:MaxMcpPoint3 OutValue") \
    X(SplineCurveSetRelOutVec, "Spline", "result", "spline Spline, int32 i, cptr:MaxMcpPoint3 p") \
    X(SplineCurveGetKnotUserFlag, "Spline", "result", "spline Spline, int32 i, uint32 fl, ptr:int32 OutValue") \
    X(SplineCurveSetKnotUserFlag, "Spline", "result", "spline Spline, int32 i, uint32 fl, int32 val") \
    X(SplineCurveClearKnotUserFlag, "Spline", "result", "spline Spline, int32 i, uint32 fl") \
    X(SplineCurveGetAux, "Spline", "result", "spline Spline, int32 knot, ptr:int32 OutValue") \
    X(SplineCurveSetAux, "Spline", "result", "spline Spline, int32 knot, int32 value") \
    X(SplineCurveGetAux2, "Spline", "result", "spline Spline, int32 knot, ptr:int32 OutValue") \
    X(SplineCurveSetAux2, "Spline", "result", "spline Spline, int32 knot, int32 value") \
    X(SplineCurveGetAux3, "Spline", "result", "spline Spline, int32 knot, ptr:int32 OutValue") \
    X(SplineCurveSetAux3, "Spline", "result", "spline Spline, int32 knot, int32 value") \
    X(SplineCurveGetKnotAux, "Spline", "result", "spline Spline, int32 knot, int32 which, ptr:int32 OutValue") \
    X(SplineCurveSetKnotAux, "Spline", "result", "spline Spline, int32 knot, int32 which, int32 value") \
    X(SplineCurveGetInAux, "Spline", "result", "spline Spline, int32 knot, int32 which, ptr:int32 OutValue") \
    X(SplineCurveSetInAux, "Spline", "result", "spline Spline, int32 knot, int32 which, int32 value") \
    X(SplineCurveGetOutAux, "Spline", "result", "spline Spline, int32 knot, int32 which, ptr:int32 OutValue") \
    X(SplineCurveSetOutAux, "Spline", "result", "spline Spline, int32 knot, int32 which, int32 value") \
    X(SplineCurveGetVertAux, "Spline", "result", "spline Spline, int32 i, int32 which, ptr:int32 OutValue") \
    X(SplineCurveSetVertAux, "Spline", "result", "spline Spline, int32 i, int32 which, int32 value") \
    X(SplineCurveGetMatID, "Spline", "result", "spline Spline, int32 seg, ptr:uint32 OutValue") \
    X(SplineCurveSetMatID, "Spline", "result", "spline Spline, int32 seg, uint32 id") \
    X(SplineCurveSplineLength, "Spline", "result", "spline Spline, ptr:float OutValue") \
    X(SplineCurveSegmentLength, "Spline", "result", "spline Spline, int32 seg, ptr:float OutValue") \
    X(SplineCurveReverse, "Spline", "result", "spline Spline, int32 keepZero") \
    X(SplineCurveIsClockWise, "Spline", "result", "spline Spline, ptr:int32 OutValue") \
    X(SplineCurveSelfIntersects, "Spline", "result", "spline Spline, ptr:int32 OutValue") \
    X(SplineCurveSurroundsPoint, "Spline", "result", "spline Spline, cptr:MaxMcpPoint2 p, ptr:int32 OutValue") \
    X(SplineCurveInvalidateGeomCache, "Spline", "result", "spline Spline") \
    X(MeshMapHandleGet, "Mesh", "meshmap", "node Node, int32 Channel") \
    X(MeshMapVAlloc, "Mesh", "result", "meshmap Map, int32 num, int32 keep") \
    X(MeshMapFAlloc, "Mesh", "result", "meshmap Map, int32 num, int32 keep") \
    X(MeshMapNewTri, "Mesh", "result", "meshmap Map, int32 a, int32 b, int32 c, ptr:int32 OutValue") \
    X(MeshMapNewQuad, "Mesh", "result", "meshmap Map, int32 a, int32 b, int32 c, int32 d, ptr:int32 OutValue") \
    X(MeshMapSetNumFaces, "Mesh", "result", "meshmap Map, int32 nfnum") \
    X(MeshMapSetNumVerts, "Mesh", "result", "meshmap Map, int32 nvnum") \
    X(MeshMapClearAndFree, "Mesh", "result", "meshmap Map") \
    X(MeshMapTransform, "Mesh", "result", "meshmap Map, ptr:MaxMcpMatrix3 xfm") \
    X(MeshMapNewAndCopy, "Mesh", "result", "meshmap Map") \
    X(MNNormalInitialize, "MN", "result", "node Node") \
    X(MNNormalNAlloc, "MN", "result", "node Node, int32 num, int32 keep, ptr:int32 OutValue") \
    X(MNNormalNShrink, "MN", "result", "node Node") \
    X(MNNormalFAlloc, "MN", "result", "node Node, int32 num, int32 keep, ptr:int32 OutValue") \
    X(MNNormalFShrink, "MN", "result", "node Node") \
    X(MNNormalClearAndFree, "MN", "result", "node Node") \
    X(MNNormalSetNumFaces, "MN", "result", "node Node, int32 numFaces, ptr:int32 OutValue") \
    X(MNNormalSetNumNormals, "MN", "result", "node Node, int32 numNormals, ptr:int32 OutValue") \
    X(MNNormalGetNormal, "MN", "result", "node Node, int32 face, int32 corner, ptr:MaxMcpPoint3 OutValue") \
    X(MNNormalSetNormal, "MN", "result", "node Node, int32 face, int32 corner, ptr:MaxMcpPoint3 normal") \
    X(MNNormalGetNormalIndex, "MN", "result", "node Node, int32 face, int32 corner, ptr:int32 OutValue") \
    X(MNNormalSetNormalIndex, "MN", "result", "node Node, int32 face, int32 corner, int32 normalIndex") \
    X(MNNormalNewNormal, "MN", "result", "node Node, ptr:MaxMcpPoint3 normal, int32 explic, ptr:int32 OutValue") \
    X(MNNormalCollapseDeadFaces, "MN", "result", "node Node") \
    X(MNNormalClearNormals, "MN", "result", "node Node") \
    X(MNNormalBuildNormals, "MN", "result", "node Node") \
    X(MNNormalComputeNormals, "MN", "result", "node Node") \
    X(MNNormalCheckNormals, "MN", "result", "node Node") \
    X(MNNormalAdjustToParent, "MN", "result", "node Node, int32 doCheckDegree") \
    X(MNNormalCheckAllData, "MN", "result", "node Node, int32 numParentFaces, ptr:int32 OutValue") \
    X(MNNormalNewAndCopyChannels, "MN", "result", "node Node, uint32 channels") \
    X(MNNormalFreeChannels, "MN", "result", "node Node, uint32 channels, int32 zeroOthers") \
    X(MNNormalZeroChannels, "MN", "result", "node Node, uint32 channels") \
    X(ControllerSetInheritanceFlags, "Controller", "result", "anim Controller, uint32 f, int32 keepPos, ptr:int32 OutValue") \
    X(BitmapLoad, "Bitmap", "result", "cstr Path, ptr:held OutHeld") \
    X(BitmapWidth, "Bitmap", "result", "held Bm, ptr:int32 OutValue") \
    X(BitmapHeight, "Bitmap", "result", "held Bm, ptr:int32 OutValue") \
    X(BitmapGetFiltered, "Bitmap", "result", "held Bm, float U, float V, ptr:MaxMcpAColor OutValue") \
    X(BitmapGetPixels, "Bitmap", "result", "held Bm, int32 X, int32 Y, int32 Count, ptr:MaxMcpSpan OutValue") \
    X(MeshDeltaExtrudeFaces, "Mesh", "result", "anim Object, cptr:MaxMcpSpan Fset") \
    X(MeshDeltaExtrudeEdges, "Mesh", "result", "anim Object, cptr:MaxMcpSpan Eset") \
    X(MeshDeltaDivideFaces, "Mesh", "result", "anim Object, cptr:MaxMcpSpan Fset") \
    X(MeshDeltaExplodeFaces, "Mesh", "result", "anim Object, float Thresh, int32 UseFaceSel") \
    X(MeshDeltaWeldByThreshold, "Mesh", "result", "anim Object, cptr:MaxMcpSpan Vset, float Thresh, ptr:int32 OutValue") \
    X(MeshDeltaSlice, "Mesh", "result", "anim Object, cptr:MaxMcpPoint3 N, float Off, int32 Sep, int32 Remove, ptr:int32 OutValue") \
    X(FaceClustersCreate, "Face", "result", "anim Object, uint32 ClusterFlags, ptr:held OutHeld") \
    X(FaceClustersCount, "Face", "result", "held Clusters, ptr:int32 OutValue") \
    X(PolyExtrudeFaceClusters, "Poly", "result", "anim Object, held Clusters, ptr:int32 OutValue") \
    X(PolyExtrudeFaceCluster, "Poly", "result", "anim Object, held Clusters, int32 Cl, ptr:int32 OutValue") \
    X(LinkChainLinkCount, "Link", "result", "held Chain, ptr:int32 OutValue") \
    X(LinkChainPreBone, "Link", "result", "held Chain, int32 Index, ptr:int32 OutValue") \
    X(LinkChainBone, "Link", "result", "held Chain, int32 Index, ptr:int32 OutValue") \
    X(LinkChainParentMatrix, "Link", "result", "held Chain, ptr:MaxMcpMatrix3 OutValue") \
    X(LinkChainRootRotation, "Link", "result", "held Chain, ptr:MaxMcpPoint3 OutValue") \
    X(LinkChainLinkDofAxis, "Link", "result", "held Chain, int32 Index, ptr:int32 OutValue") \
    X(LinkChainLinkDofValue, "Link", "result", "held Chain, int32 Index, ptr:float OutValue") \
    X(LinkChainLinkLimits, "Link", "result", "held Chain, int32 Index, ptr:MaxMcpPoint2 OutValue") \
    X(LinkChainLinkMatrix, "Link", "result", "held Chain, int32 Index, int32 IncludeDof, ptr:MaxMcpMatrix3 OutValue") \
    X(LinkChainSetLinkDofValue, "Link", "result", "held Chain, int32 Index, float Value") \
    X(LinkChainSetRootRotation, "Link", "result", "held Chain, cptr:MaxMcpPoint3 Value") \
    X(ShadeContextRaw, "Shade", "result", "ptr:opaque OutRaw") \
    X(GpuDeviceRaw, "Gpu", "result", "ptr:opaque OutRaw") \
    X(MocapStreamRaw, "Mocap", "result", "ptr:opaque OutRaw") \
    X(MeshIntersectRay, "Mesh", "result", "anim Object, cptr:MaxMcpPoint3 Origin, cptr:MaxMcpPoint3 Dir, ptr:int32 OutHit, ptr:float OutAt, ptr:MaxMcpPoint3 OutNorm") \
    X(MeshFindVertexAngles, "Mesh", "result", "anim Object, cptr:uint32 SelectionBits, int32 BitCount, ptr:float OutAngles, size Capacity, ptr:int32 OutWritten") \
    X(ObjectGetDeformBBox, "Object", "result", "anim Anim, int32 Time, ptr:MaxMcpBox3 OutBox, cptr:MaxMcpMatrix3 Tm, int32 UseSel") \
    X(ObjectLockObject, "Object", "result", "anim Anim") \
    X(ObjectUnlockObject, "Object", "result", "anim Anim") \
    X(ObjectIsObjectLocked, "Object", "result", "anim Anim, ptr:int32 OutValue") \
    X(ObjectLockChannels, "Object", "result", "anim Anim, uint32 Channels") \
    X(ObjectUnlockChannels, "Object", "result", "anim Anim, uint32 Channels") \
    X(ObjectHasWeights, "Object", "result", "anim Anim, ptr:int32 OutValue") \
    X(ObjectMergeAdditionalChannels, "Object", "result", "anim Anim, anim From, int32 BranchID") \
    X(PolyEliminateBadVerts, "Poly", "result", "anim Object, uint32 Flag, int32 DoNullEdgeCheck, ptr:int32 OutValue") \
    X(PolyCollapseEdges, "Poly", "result", "anim Object, uint32 EdgeFlag, ptr:int32 OutValue") \
    X(PolyAddTri, "Poly", "result", "anim Object, anim Source") \
    X(PolyPropegateComponentFlags, "Poly", "result", "anim Object, int32 SlTo, uint32 FlTo, int32 SlFrom, uint32 FlFrom, int32 Ampersand, int32 Set, ptr:int32 OutValue") \
    X(PolyGetNewSmGroup, "Poly", "result", "anim Object, int32 TargOnly, ptr:uint32 OutValue") \
    X(MNChamferDataCreate, "MN", "result", "anim Object, ptr:held OutHeld") \
    X(PolyExtrudeVertices, "Poly", "result", "anim Object, uint32 VertexFlag, held ChamferData, cptr:MaxMcpPoint3 Directions, int32 DirCount, int32 TriangulationType, ptr:int32 OutValue") \
    X(MeshDeltaAttachMesh, "Mesh", "result", "anim Object, anim Attach, cptr:MaxMcpMatrix3 RelativeTransform, int32 MatOffset") \
    X(MeshDeltaDetach, "Mesh", "result", "anim Object, anim Out, cptr:uint32 Bits, int32 BitCount, int32 Faces, int32 Del, int32 Elem") \
    X(MeshDeltaCollapseEdges, "Mesh", "result", "anim Object, cptr:uint32 Bits, int32 BitCount, held AdjEdges") \
    X(MeshDeltaWeldVertSet, "Mesh", "result", "anim Object, cptr:uint32 Bits, int32 BitCount, int32 HasWeldPoint, cptr:MaxMcpPoint3 WeldPoint") \
    X(MeshDeltaCut, "Mesh", "result", "anim Object, uint32 Ed1, float Prop1, uint32 Ed2, float Prop2, cptr:MaxMcpPoint3 Norm, int32 FixNeighbors, int32 Split, ptr:uint32 OutValue") \
    X(MeshDeltaBevel, "Mesh", "result", "anim Object, cptr:uint32 Bits, int32 BitCount, float Outline, cptr:MaxMcpPoint3 ODir, int32 ODirCount, float Height, cptr:MaxMcpPoint3 HDir, int32 HDirCount") \
    X(ConvertMeshToPatch, "Convert", "result", "anim Dest, anim Source, uint32 Flags") \
    X(ConvertPatchToMesh, "Convert", "result", "anim Dest, anim Source, uint32 Flags") \
    X(ConvertPolyToPatch, "Convert", "result", "anim Dest, anim Source, uint32 Flags") \
    X(ConvertPatchToPoly, "Convert", "result", "anim Dest, anim Source, uint32 Flags") \
    X(BitmapPutPixels, "Bitmap", "result", "held Bm, int32 X, int32 Y, int32 Count, cptr:MaxMcpSpan Pixels") \
    X(BitmapGet16Gray, "Bitmap", "result", "held Bm, int32 X, int32 Y, int32 Count, ptr:MaxMcpSpan OutValue") \
    X(BitmapCreate, "Bitmap", "result", "int32 Width, int32 Height, int32 Type, ptr:held OutHeld") \
    X(BitmapOpenOutput, "Bitmap", "result", "held Bm, cstr Path, ptr:held OutHeld") \
    X(BitmapSave, "Bitmap", "result", "held Io, int32 Frame") \
    X(BitmapClose, "Bitmap", "result", "held Io, int32 Flag") \
    X(BitmapChannelsPresent, "Bitmap", "result", "held Bm, ptr:uint32 OutValue") \
    X(BitmapCreateChannels, "Bitmap", "result", "held Bm, uint32 ChannelIds, ptr:uint32 OutValue") \
    X(BitmapGetChannel, "Bitmap", "result", "held Bm, uint32 ChannelId, ptr:uint32 OutChanType, ptr:MaxMcpSpan OutValue") \
    X(BitmapAspect, "Bitmap", "result", "held Bm, ptr:float OutValue") \
    X(BitmapGetRenderInfo, "Bitmap", "result", "held Bm, ptr:MaxMcpRenderInfo OutValue") \
    X(PatchVertSelRead, "Patch", "result", "anim Object, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(PatchEdgeSelRead, "Patch", "result", "anim Object, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(PatchPatchSelRead, "Patch", "result", "anim Object, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(PatchVecSelRead, "Patch", "result", "anim Object, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(PatchVertSelWrite, "Patch", "result", "anim Object, int32 Time, cptr:uint32 Bits, int32 BitCount") \
    X(PatchEdgeSelWrite, "Patch", "result", "anim Object, int32 Time, cptr:uint32 Bits, int32 BitCount") \
    X(PatchPatchSelWrite, "Patch", "result", "anim Object, int32 Time, cptr:uint32 Bits, int32 BitCount") \
    X(PatchVecSelWrite, "Patch", "result", "anim Object, int32 Time, cptr:uint32 Bits, int32 BitCount") \
    X(PatchMeshVertexTempSelRead, "Patch", "result", "anim Object, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(PatchMeshVertexWeightRead, "Patch", "result", "anim Object, int32 i, ptr:float OutValue") \
    X(PatchMeshWeldByThreshold, "Patch", "result", "anim Object, float thresh, int32 weldIdentical, int32 startVert, ptr:int32 OutValue") \
    X(SplineCurveGetKnotType, "Spline", "result", "spline Spline, int32 index, ptr:int32 OutValue") \
    X(BezierShapeVertexTempSel, "Bezier", "result", "node Node, int32 poly, int32 level, ptr:uint32 OutBits, int32 BitCapacity, ptr:int32 OutBitCount") \
    X(PolySelLevelRead, "Poly", "result", "anim Object, ptr:int32 OutValue") \
    X(ShapeObjGetRectangular, "Shape", "result", "node Node, int32 t, ptr:int32 OutValue") \
    X(ShapeObjSetRectangular, "Shape", "result", "node Node, int32 t, int32 value") \
    X(ShapeObjGetWidth, "Shape", "result", "node Node, int32 t, ptr:float OutValue") \
    X(ShapeObjSetWidth, "Shape", "result", "node Node, int32 t, float value") \
    X(ShapeObjGetLength, "Shape", "result", "node Node, int32 t, ptr:float OutValue") \
    X(ShapeObjSetLength, "Shape", "result", "node Node, int32 t, float value") \
    X(ShapeObjGetAngle2, "Shape", "result", "node Node, int32 t, ptr:float OutValue") \
    X(ShapeObjSetAngle2, "Shape", "result", "node Node, int32 t, float value") \
    X(ShapeObjGetAspectLock, "Shape", "result", "node Node, int32 t, ptr:int32 OutValue") \
    X(ShapeObjSetAspectLock, "Shape", "result", "node Node, int32 t, int32 value") \
    X(ShapeObjGetVPTRectangular, "Shape", "result", "node Node, int32 t, ptr:int32 OutValue") \
    X(ShapeObjSetVPTRectangular, "Shape", "result", "node Node, int32 t, int32 value") \
    X(ShapeObjGetVPTWidth, "Shape", "result", "node Node, int32 t, ptr:float OutValue") \
    X(ShapeObjSetVPTWidth, "Shape", "result", "node Node, int32 t, float value") \
    X(ShapeObjGetVPTLength, "Shape", "result", "node Node, int32 t, ptr:float OutValue") \
    X(ShapeObjSetVPTLength, "Shape", "result", "node Node, int32 t, float value") \
    X(ShapeObjGetVPTAngle2, "Shape", "result", "node Node, int32 t, ptr:float OutValue") \
    X(ShapeObjSetVPTAngle2, "Shape", "result", "node Node, int32 t, float value") \
    X(ShapeObjGetVPTAspectLock, "Shape", "result", "node Node, int32 t, ptr:int32 OutValue") \
    X(ShapeObjSetVPTAspectLock, "Shape", "result", "node Node, int32 t, int32 value") \
    X(ShapeObjGetAutosmooth, "Shape", "result", "node Node, int32 t, ptr:int32 OutValue") \
    X(ShapeObjSetAutosmooth, "Shape", "result", "node Node, int32 t, int32 value") \
    X(ShapeObjGetAutosmoothThreshold, "Shape", "result", "node Node, int32 t, ptr:float OutValue") \
    X(ShapeObjSetAutosmoothThreshold, "Shape", "result", "node Node, int32 t, float value") \
    X(TriDispApproxRead, "Tri", "result", "anim Object, ptr:MaxMcpTessApprox OutTess") \
    X(TriDispApproxWrite, "Tri", "result", "anim Object, cptr:MaxMcpTessApprox Tess") \
    X(PolyDispApproxRead, "Poly", "result", "anim Object, ptr:MaxMcpTessApprox OutTess") \
    X(PolyDispApproxWrite, "Poly", "result", "anim Object, cptr:MaxMcpTessApprox Tess") \
    X(TriDisableDisplacementRead, "Tri", "result", "anim Object, ptr:int32 OutValue") \
    X(TriDisableDisplacementWrite, "Tri", "result", "anim Object, int32 value") \
    X(PolyDisableDisplacementRead, "Poly", "result", "anim Object, ptr:int32 OutValue") \
    X(PolyDisableDisplacementWrite, "Poly", "result", "anim Object, int32 value") \
    X(TriSplitMeshRead, "Tri", "result", "anim Object, ptr:int32 OutValue") \
    X(TriSplitMeshWrite, "Tri", "result", "anim Object, int32 value") \
    X(PolySplitMeshRead, "Poly", "result", "anim Object, ptr:int32 OutValue") \
    X(PolySplitMeshWrite, "Poly", "result", "anim Object, int32 value") \
    X(TriSubDivideDisplacementRead, "Tri", "result", "anim Object, ptr:int32 OutValue") \
    X(TriSubDivideDisplacementWrite, "Tri", "result", "anim Object, int32 value") \
    X(PolySubDivideDisplacementRead, "Poly", "result", "anim Object, ptr:int32 OutValue") \
    X(PolySubDivideDisplacementWrite, "Poly", "result", "anim Object, int32 value") \
    X(SceneMtlCount, "Scene", "int32", "") \
    X(SceneMtlGet, "Scene", "anim", "int32 Index") \
    X(MtlLibCount, "Mtl", "int32", "") \
    X(MtlLibGet, "Mtl", "anim", "int32 Index") \
    X(DllDirCount, "Dll", "int32", "") \
    X(DllDescFileName, "Dll", "result", "int32 Index, mutstr OutName, size Capacity") \
    X(DllDescIsLoaded, "Dll", "int32", "int32 Index") \
    X(ScenePropertyCount, "Scene", "int32", "int32 PropertySet") \
    X(ScenePropertyName, "Scene", "result", "int32 PropertySet, int32 Index, ptr:int32 OutKind, ptr:int32 OutPropId, mutstr OutName, size Capacity") \
    X(ScenePropertyValue, "Scene", "result", "int32 PropertySet, int32 Index, ptr:MaxMcpPropertyValue OutValue, mutstr OutName, size Capacity") \
    X(NodeEnumAuxFiles, "Node", "result", "node Node, int32 Flags, mutstr OutBuffer, size Capacity, ptr:int32 OutCount, ptr:int32 OutWritten") \
    X(SceneImportFromFile, "Scene", "result", "cstr name, int32 suppressPrompts, ptr:int32 OutValue") \
    X(SceneNewFile, "Scene", "result", "int32 NoPrompt") \
    X(SceneRenderFrame, "Scene", "result", "node CameraNode, int32 Width, int32 Height, ptr:held OutHeld") \
    X(ToneOperatorGetPhysicalUnit, "Tone", "result", "int32 Time, ptr:float OutValue, ptr:int32 OutStart, ptr:int32 OutEnd") \
    X(ParamDimensionConvert, "Param", "result", "anim Anim, int32 SubNum, float Value, ptr:float OutValue") \
    X(ParamDimensionUnConvert, "Param", "result", "anim Anim, int32 SubNum, float Value, ptr:float OutValue") \
    X(ForceFieldCreate, "Force", "result", "node Node, ptr:held OutHeld") \
    X(ForceFieldForce, "Force", "result", "held Field, int32 Time, cptr:MaxMcpPoint3 Pos, cptr:MaxMcpPoint3 Vel, int32 Index, ptr:MaxMcpPoint3 OutForce") \
    X(ForceFieldForceN, "Force", "result", "held Field, int32 Time, cptr:MaxMcpPoint3 Pos, cptr:MaxMcpPoint3 Vel, int32 BaseIndex, ptr:MaxMcpPoint3 OutForces, size Capacity, ptr:int32 OutWritten") \
    X(CollisionObjectCreate, "Collision", "result", "node Node, ptr:held OutHeld") \
    X(CollisionObjectCheck, "Collision", "result", "held Deflector, int32 Time, ptr:MaxMcpPoint3 Pos, ptr:MaxMcpPoint3 Vel, float Dt, int32 Index, int32 UpdatePastCollide, ptr:int32 OutHit, ptr:float OutCollideTime") \
    X(CurveCtlNumCurves, "Curve", "result", "anim CurveCtl, ptr:int32 OutValue") \
    X(CurveCtlGetValue, "Curve", "result", "anim CurveCtl, int32 CurveIndex, int32 Time, float X, ptr:float OutY") \
    X(CurveCtlGetValueN, "Curve", "result", "anim CurveCtl, int32 CurveIndex, int32 Time, cptr:float Xs, ptr:float OutYs, size Capacity, ptr:int32 OutWritten") \
    X(BitmapTexAssetCreate, "Bitmap", "result", "anim BitmapTex, ptr:held OutHeld") \
    X(AssetUserFileName, "Asset", "result", "held Asset, ptr:MaxMcpStrOut OutValue") \
    X(AssetUserFullFilePath, "Asset", "result", "held Asset, ptr:MaxMcpStrOut OutValue") \
    X(AssetUserId, "Asset", "result", "held Asset, ptr:MaxMcpStrOut OutValue") \
    X(AssetUserType, "Asset", "result", "held Asset, ptr:int32 OutValue") \
    X(FaceDataChanCount, "Face", "result", "anim Object, ptr:int32 OutValue") \
    X(FaceDataChanList, "Face", "result", "anim Object, ptr:MaxMcpFaceDataChan OutChans, size Capacity, ptr:int32 OutWritten") \
    X(FaceDataChanObjectCount, "Face", "result", "anim Object, uint32 ClassA, uint32 ClassB, ptr:uint32 OutValue") \
    X(PolyShapeCreate, "Poly", "result", "node Node, int32 Time, int32 Steps, int32 Optimize, ptr:held OutHeld") \
    X(MeshCapInfoCreate, "Mesh", "result", "held PolyShape, int32 Time, int32 CapType, ptr:held OutHeld") \
    X(MeshCapperCreate, "Mesh", "result", "held PolyShape, ptr:held OutHeld") \
    X(MeshCapInfoFaceCount, "Mesh", "result", "held CapInfo, ptr:int32 OutValue") \
    X(MeshCapInfoVertCount, "Mesh", "result", "held CapInfo, ptr:int32 OutValue") \
    X(MeshCapperCapMesh, "Mesh", "result", "held Capper, anim Mesh, held CapInfo, int32 Flip, uint32 Smooth, int32 MtlId, ptr:int32 OutValue") \
    X(NodeEvalWorldMeshRead, "Node", "result", "node Node, int32 Time, ptr:float OutVerts, size VertCapacity, ptr:MaxMcpFace OutFaces, size FaceCapacity, ptr:int32 OutVertCount, ptr:int32 OutFaceCount") \
    X(NodeEvalWorldStateTM, "Node", "result", "node Node, int32 Time, ptr:int32 OutHasTM, ptr:MaxMcpMatrix3 OutValue") \
    X(LinkChainGoalInfo, "Link", "result", "held Chain, ptr:MaxMcpLinkChainGoal OutValue") \
    X(LinkChainGoalMatrix, "Link", "result", "held Chain, ptr:MaxMcpMatrix3 OutValue") \
    X(LinkChainGoalSwivelAngle, "Link", "result", "held Chain, ptr:float OutValue") \
    X(LinkChainGoalChainNormal, "Link", "result", "held Chain, ptr:MaxMcpPoint3 OutValue") \
    X(LinkChainGoalVHTarget, "Link", "result", "held Chain, ptr:MaxMcpPoint3 OutValue") \
    X(LinkChainJointsRead, "Link", "result", "held Chain, ptr:MaxMcpSpan OutValue") \
    X(LinkChainEndEffectorMatrix, "Link", "result", "held Chain, ptr:MaxMcpMatrix3 OutValue") \
    X(LinkChainRootInitRotation, "Link", "result", "held Chain, ptr:MaxMcpPoint3 OutValue") \
    X(LinkChainRootLimits, "Link", "result", "held Chain, ptr:MaxMcpPoint3 OutLower, ptr:MaxMcpPoint3 OutUpper") \
    X(LinkChainRootDof, "Link", "result", "held Chain, ptr:MaxMcpLinkChainRootDof OutValue") \
    X(LinkChainRootRigidExtend, "Link", "result", "held Chain, ptr:MaxMcpMatrix3 OutValue") \
    X(LinkChainRootLinkMatrix, "Link", "result", "held Chain, int32 IncludeRot, ptr:MaxMcpMatrix3 OutValue") \
    X(LinkChainLinkInitValue, "Link", "result", "held Chain, int32 Index, ptr:float OutValue") \
    X(LinkChainLinkFlags, "Link", "result", "held Chain, int32 Index, ptr:MaxMcpLinkChainLinkFlags OutValue") \
    X(LinkChainLinkDofMatrix, "Link", "result", "held Chain, int32 Index, ptr:MaxMcpMatrix3 OutValue") \
    X(SubObjectAxes, "Sub", "result", "node Node, int32 Time, int32 CenterType, ptr:MaxMcpSpan OutValue") \
    X(ViewMapScreenToWorldRay, "View", "result", "hwnd Win, cptr:MaxMcpIPoint2 Screen, ptr:MaxMcpPoint3 OutOrigin, ptr:MaxMcpPoint3 OutDir") \
    X(ViewPickNode, "View", "node", "hwnd Win, cptr:MaxMcpIPoint2 Screen") \
    X(ObjectIntersectRay, "Object", "result", "node Node, int32 Time, cptr:MaxMcpPoint3 Origin, cptr:MaxMcpPoint3 Dir, ptr:int32 OutHit, ptr:float OutAt, ptr:MaxMcpPoint3 OutNorm") \
    X(ManipCurrentEvent, "Manip", "result", "ptr:int32 OutKind, ptr:int32 OutScreenX, ptr:int32 OutScreenY, ptr:uint32 OutFlags, ptr:held OutView") \
    X(ViewBorrowedRay, "View", "result", "held View, int32 ScreenX, int32 ScreenY, ptr:MaxMcpPoint3 OutOrigin, ptr:MaxMcpPoint3 OutDir") \
    X(OsnapCurrentEvent, "Osnap", "result", "ptr:int32 OutActive, ptr:int32 OutScreenX, ptr:int32 OutScreenY, ptr:int32 OutTime, ptr:held OutManager") \
    X(OsnapRecordHit, "Osnap", "result", "held Manager, cptr:MaxMcpPoint3 WorldPoint, int32 Sub") \
    X(ParticleContainerCurrent, "Particle", "result", "ptr:int32 OutActive, ptr:held OutContainer") \
    X(ParticleChannelCount, "Particle", "result", "held Container, ptr:int32 OutValue") \
    X(ParticlePositionGet, "Particle", "result", "held Container, int32 Index, ptr:MaxMcpPoint3 OutValue") \
    X(ParticlePositionSet, "Particle", "result", "held Container, int32 Index, cptr:MaxMcpPoint3 Value") \
    X(ParticleSpeedGet, "Particle", "result", "held Container, int32 Index, ptr:MaxMcpPoint3 OutValue") \
    X(ParticleSpeedSet, "Particle", "result", "held Container, int32 Index, cptr:MaxMcpPoint3 Value") \
    X(ParticleAccelerationGet, "Particle", "result", "held Container, int32 Index, ptr:MaxMcpPoint3 OutValue") \
    X(ParticleAccelerationSet, "Particle", "result", "held Container, int32 Index, cptr:MaxMcpPoint3 Value") \
    X(ParticleScaleGet, "Particle", "result", "held Container, int32 Index, ptr:MaxMcpPoint3 OutValue") \
    X(ParticleScaleSet, "Particle", "result", "held Container, int32 Index, cptr:MaxMcpPoint3 Value") \
    X(ParticleOrientationGet, "Particle", "result", "held Container, int32 Index, ptr:MaxMcpQuat OutValue") \
    X(ParticleOrientationSet, "Particle", "result", "held Container, int32 Index, cptr:MaxMcpQuat Value") \
    X(ParticleSpinGet, "Particle", "result", "held Container, int32 Index, ptr:MaxMcpAngAxis OutValue") \
    X(ParticleSpinSet, "Particle", "result", "held Container, int32 Index, cptr:MaxMcpAngAxis Value") \
    X(ParticleSelectionGet, "Particle", "result", "held Container, int32 Index, ptr:int32 OutValue") \
    X(ParticleSelectionSet, "Particle", "result", "held Container, int32 Index, int32 Value") \
    X(ParticleMaterialIndexGet, "Particle", "result", "held Container, int32 Index, ptr:int32 OutValue") \
    X(ParticleMaterialIndexSet, "Particle", "result", "held Container, int32 Index, int32 Value") \
    X(ParticleTimeGet, "Particle", "result", "held Container, int32 Index, ptr:MaxMcpPreciseTimeValue OutValue") \
    X(ParticleTimeSet, "Particle", "result", "held Container, int32 Index, cptr:MaxMcpPreciseTimeValue Value") \
    X(ParticleBirthTimeGet, "Particle", "result", "held Container, int32 Index, ptr:MaxMcpPreciseTimeValue OutValue") \
    X(ParticleBirthTimeSet, "Particle", "result", "held Container, int32 Index, cptr:MaxMcpPreciseTimeValue Value") \
    X(ParticleDeathTimeGet, "Particle", "result", "held Container, int32 Index, ptr:MaxMcpPreciseTimeValue OutValue") \
    X(ParticleDeathTimeSet, "Particle", "result", "held Container, int32 Index, cptr:MaxMcpPreciseTimeValue Value") \
    X(ParticleLifespanGet, "Particle", "result", "held Container, int32 Index, ptr:MaxMcpPreciseTimeValue OutValue") \
    X(ParticleLifespanSet, "Particle", "result", "held Container, int32 Index, cptr:MaxMcpPreciseTimeValue Value") \
    X(ParticleEventStartGet, "Particle", "result", "held Container, int32 Index, ptr:MaxMcpPreciseTimeValue OutValue") \
    X(ParticleEventStartSet, "Particle", "result", "held Container, int32 Index, cptr:MaxMcpPreciseTimeValue Value") \
    X(ParticleIsNew, "Particle", "result", "held Container, int32 Index, ptr:int32 OutValue") \
    X(ParticleIsAllNew, "Particle", "result", "held Container, ptr:int32 OutValue") \
    X(ParticleIsAllOld, "Particle", "result", "held Container, ptr:int32 OutValue") \
    X(ParticleSetNew, "Particle", "result", "held Container, int32 Index") \
    X(ParticleSetOld, "Particle", "result", "held Container, int32 Index") \
    X(ParticleSetAllNew, "Particle", "result", "held Container") \
    X(ParticleSetAllOld, "Particle", "result", "held Container") \
    X(ParticleGetIndex, "Particle", "result", "held Container, int32 Index, ptr:int32 OutValue") \
    X(ParticleGetBorn, "Particle", "result", "held Container, int32 Index, ptr:int32 OutValue") \
    X(ParticleSetID, "Particle", "result", "held Container, int32 Index, int32 ParticleIndex, int32 ParticleBorn") \
    X(ParticlePositionEnsure, "Particle", "result", "held Container, ptr:int32 OutCreated") \
    X(ParticleSpeedEnsure, "Particle", "result", "held Container, ptr:int32 OutCreated") \
    X(ParticleAccelerationEnsure, "Particle", "result", "held Container, ptr:int32 OutCreated") \
    X(ParticleScaleEnsure, "Particle", "result", "held Container, ptr:int32 OutCreated") \
    X(ParticleOrientationEnsure, "Particle", "result", "held Container, ptr:int32 OutCreated") \
    X(ParticleSpinEnsure, "Particle", "result", "held Container, ptr:int32 OutCreated") \
    X(ParticleSelectionEnsure, "Particle", "result", "held Container, ptr:int32 OutCreated") \
    X(ParticleMaterialIndexEnsure, "Particle", "result", "held Container, ptr:int32 OutCreated") \
    X(ParticleTimeEnsure, "Particle", "result", "held Container, ptr:int32 OutCreated") \
    X(ParticleBirthTimeEnsure, "Particle", "result", "held Container, ptr:int32 OutCreated") \
    X(ParticleDeathTimeEnsure, "Particle", "result", "held Container, ptr:int32 OutCreated") \
    X(ParticleLifespanEnsure, "Particle", "result", "held Container, ptr:int32 OutCreated") \
    X(ParticleEventStartEnsure, "Particle", "result", "held Container, ptr:int32 OutCreated") \
    X(ParticleShapeIsShared, "Particle", "result", "held Container, ptr:int32 OutValue") \
    X(ParticleShapeValueCount, "Particle", "result", "held Container, ptr:int32 OutValue") \
    X(ParticleShapeValueIndex, "Particle", "result", "held Container, int32 Index, ptr:int32 OutValue") \
    X(ParticleShapeSetFromNode, "Particle", "result", "held Container, int32 Index, anim SourceObject, ptr:int32 OutOk") \
    X(ParticleShapeSetGlobalFromNode, "Particle", "result", "held Container, anim SourceObject, ptr:int32 OutOk") \
    X(ParticleShapeCopyValue, "Particle", "result", "held Container, int32 FromIndex, int32 ToIndex, ptr:int32 OutOk") \
    X(ParticleShapeCopyValueToAll, "Particle", "result", "held Container, int32 FromIndex, ptr:int32 OutOk") \
    X(ParticleShapeNodeGet, "Particle", "result", "held Container, int32 Index, ptr:node OutNode") \
    X(ParticleShapeNodeSet, "Particle", "result", "held Container, int32 Index, node SourceNode, ptr:int32 OutOk") \
    X(ParticleShapeTextureNumMaps, "Particle", "result", "held Container, ptr:int32 OutValue") \
    X(ParticleShapeTextureMapSupport, "Particle", "result", "held Container, int32 MapChannel, ptr:int32 OutValue") \
    X(ParticleShapeTextureSetNumMaps, "Particle", "result", "held Container, int32 Count, int32 Keep") \
    X(ParticleShapeTextureSetMapSupport, "Particle", "result", "held Container, int32 MapChannel, int32 Support") \
    X(ParticleMXSFloatGet, "Particle", "result", "held Container, int32 Index, ptr:float OutValue") \
    X(ParticleMXSFloatSet, "Particle", "result", "held Container, int32 Index, float Value") \
    X(ParticleMXSIntegerGet, "Particle", "result", "held Container, int32 Index, ptr:int32 OutValue") \
    X(ParticleMXSIntegerSet, "Particle", "result", "held Container, int32 Index, int32 Value") \
    X(ParticleMXSVectorGet, "Particle", "result", "held Container, int32 Index, ptr:MaxMcpPoint3 OutValue") \
    X(ParticleMXSVectorSet, "Particle", "result", "held Container, int32 Index, cptr:MaxMcpPoint3 Value") \
    X(ParticleMXSMatrixGet, "Particle", "result", "held Container, int32 Index, ptr:MaxMcpMatrix3 OutValue") \
    X(ParticleMXSMatrixSet, "Particle", "result", "held Container, int32 Index, cptr:MaxMcpMatrix3 Value") \
    X(ParticleShapeTextureIsUVVertShared, "Particle", "result", "held Container, int32 MapChannel, ptr:int32 OutValue") \
    X(ParticleShapeTextureUVVertCount, "Particle", "result", "held Container, int32 MapChannel, ptr:int32 OutValue") \
    X(ParticleShapeTextureUVVertIndex, "Particle", "result", "held Container, int32 MapChannel, int32 Index, ptr:int32 OutValue") \
    X(ParticleShapeTextureUVVertRead, "Particle", "result", "held Container, int32 MapChannel, int32 Index, ptr:MaxMcpPoint3 OutVerts, size Capacity, ptr:int32 OutWritten") \
    X(ParticleShapeTextureUVVertSet, "Particle", "result", "held Container, int32 MapChannel, int32 Index, cptr:MaxMcpPoint3 Verts, size Count, ptr:int32 OutOk") \
    X(ParticleShapeTextureUVVertSetPlanar, "Particle", "result", "held Container, int32 MapChannel, int32 Index, cptr:MaxMcpPoint3 Value, ptr:int32 OutOk") \
    X(ParticleShapeTextureUVVertCopy, "Particle", "result", "held Container, int32 MapChannel, int32 FromIndex, int32 ToIndex, ptr:int32 OutOk") \
    X(ParticleShapeTextureUVVertCopyToAll, "Particle", "result", "held Container, int32 MapChannel, int32 FromIndex, ptr:int32 OutOk") \
    X(ParticleShapeTextureIsTVFaceShared, "Particle", "result", "held Container, int32 MapChannel, ptr:int32 OutValue") \
    X(ParticleShapeTextureTVFaceCount, "Particle", "result", "held Container, int32 MapChannel, ptr:int32 OutValue") \
    X(ParticleShapeTextureTVFaceIndex, "Particle", "result", "held Container, int32 MapChannel, int32 Index, ptr:int32 OutValue") \
    X(ParticleShapeTextureTVFaceRead, "Particle", "result", "held Container, int32 MapChannel, int32 Index, ptr:MaxMcpIPoint3 OutFaces, size Capacity, ptr:int32 OutWritten") \
    X(ParticleShapeTextureTVFaceSet, "Particle", "result", "held Container, int32 MapChannel, int32 Index, cptr:MaxMcpIPoint3 Faces, size Count, ptr:int32 OutOk") \
    X(ParticleShapeTextureTVFaceCopy, "Particle", "result", "held Container, int32 MapChannel, int32 FromIndex, int32 ToIndex, ptr:int32 OutOk") \
    X(ParticleShapeTextureTVFaceCopyToAll, "Particle", "result", "held Container, int32 MapChannel, int32 FromIndex, ptr:int32 OutOk") \
    X(ParticleShapeSetManyFromNode, "Particle", "result", "held Container, cptr:MaxMcpSpan Indices, anim SourceObject, ptr:int32 OutOk") \
    X(ParticleShapeCopyValueToMany, "Particle", "result", "held Container, int32 FromIndex, cptr:MaxMcpSpan ToIndices, ptr:int32 OutOk") \
    X(ParticleShapeNodeSetMany, "Particle", "result", "held Container, cptr:MaxMcpSpan Indices, node SourceNode, ptr:int32 OutOk") \
    X(ParticleShapeNodeCopyValueToMany, "Particle", "result", "held Container, int32 FromIndex, cptr:MaxMcpSpan ToIndices, ptr:int32 OutOk") \
    X(ParticleShapeTextureUVVertSetPlanarMany, "Particle", "result", "held Container, int32 MapChannel, cptr:MaxMcpSpan Indices, cptr:MaxMcpPoint3 Value, ptr:int32 OutOk") \
    X(ParticleShapeTextureUVVertCopyToMany, "Particle", "result", "held Container, int32 MapChannel, int32 FromIndex, cptr:MaxMcpSpan ToIndices, ptr:int32 OutOk") \
    X(ParticleShapeTextureTVFaceCopyToMany, "Particle", "result", "held Container, int32 MapChannel, int32 FromIndex, cptr:MaxMcpSpan ToIndices, ptr:int32 OutOk") \
    X(MxsPrimitiveCurrentCall, "Mxs", "result", "ptr:int32 OutActive, ptr:int32 OutArgCount") \
    X(MxsPrimitiveArg, "Mxs", "result", "int32 Index, ptr:int32 OutKind, ptr:int32 OutInt, ptr:double OutFloat, ptr:MaxMcpStrOut OutStr") \
    X(MxsPrimitiveSetResult, "Mxs", "result", "int32 Kind, int32 IntVal, double FloatVal, cstr Str") \
    X(ColorPipeGetLastErrorFunction, "Color", "result", "ptr:MaxMcpStrOut OutValue") \
    X(ColorPipeGetLastErrorText, "Color", "result", "ptr:MaxMcpStrOut OutValue") \
    X(ColorPipeClearLastError, "Color", "result", "") \
    X(ColorPipeSetDisplayGamma, "Color", "result", "float Value, ptr:int32 OutValue") \
    X(ColorPipeGetDisplayGamma, "Color", "result", "ptr:float OutValue") \
    X(ColorPipeSetDefaultFileInGamma, "Color", "result", "float Value, ptr:int32 OutValue") \
    X(ColorPipeGetDefaultFileInGamma, "Color", "result", "ptr:float OutValue") \
    X(ColorPipeSetDefaultFileOutGamma, "Color", "result", "float Value, ptr:int32 OutValue") \
    X(ColorPipeGetDefaultFileOutGamma, "Color", "result", "ptr:float OutValue") \
    X(ColorPipeGetBlackbodyColor, "Color", "result", "float TempKelvin, ptr:MaxMcpColor OutValue") \
    X(ColorPipeGetCIEDaylightColor, "Color", "result", "float TempKelvin, ptr:MaxMcpColor OutValue") \
    X(ColorPipeSaveSystemDefaults, "Color", "result", "ptr:int32 OutValue") \
    X(ColorPipeLoadSystemDefaults, "Color", "result", "ptr:int32 OutValue") \
    X(ColorPipeGetColorPipelineMode, "Color", "result", "ptr:int32 OutValue") \
    X(ColorPipeSetColorPipelineMode, "Color", "result", "int32 Mode, ptr:int32 OutValue") \
    X(NurbsSetOfNode, "Nurbs", "result", "node Node, int32 Time, ptr:held OutHeld") \
    X(NurbsSetObjectCount, "Nurbs", "result", "held Set, ptr:int32 OutValue") \
    X(NurbsObjectType, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsObjectId, "Nurbs", "result", "held Set, int32 Index, ptr:uint64 OutValue") \
    X(NurbsObjectName, "Nurbs", "result", "held Set, int32 Index, ptr:MaxMcpStrOut OutValue") \
    X(NurbsCVSurfaceSize, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutUOrder, ptr:int32 OutVOrder, ptr:int32 OutNumUCVs, ptr:int32 OutNumVCVs, ptr:int32 OutNumUKnots, ptr:int32 OutNumVKnots") \
    X(NurbsCVSurfaceGetCV, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 U, int32 V, ptr:MaxMcpNurbsCV OutCV") \
    X(NurbsCVSurfaceGetKnot, "Nurbs", "result", "held Set, int32 Index, int32 Axis, int32 KnotIndex, ptr:double OutValue") \
    X(NurbsCVSurfaceSetCV, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 U, int32 V, cptr:MaxMcpNurbsCV CV") \
    X(NurbsSurfaceEvaluate, "Nurbs", "result", "held Set, int32 Index, int32 Time, double U, double V, ptr:MaxMcpPoint3 OutPt") \
    X(NurbsCVCurveSize, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutOrder, ptr:int32 OutNumCVs, ptr:int32 OutNumKnots, ptr:int32 OutClosed") \
    X(NurbsCVCurveGetCV, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 I, ptr:MaxMcpNurbsCV OutCV") \
    X(NurbsCurveEvaluate, "Nurbs", "result", "held Set, int32 Index, int32 Time, double U, ptr:MaxMcpPoint3 OutPt, ptr:MaxMcpPoint3 OutTangent") \
    X(NurbsPointGetPosition, "Nurbs", "result", "held Set, int32 Index, int32 Time, ptr:MaxMcpPoint3 OutPt") \
    X(NurbsSetCreate, "Nurbs", "result", "ptr:held OutHeld") \
    X(NurbsSetAppendSphere, "Nurbs", "result", "held Set, float Radius, ptr:int32 OutIndex") \
    X(MtlBaseSetName, "Mtl", "result", "anim Base, cstr s") \
    X(MtlBaseGetFullName, "Mtl", "result", "anim Base, int32 localized, ptr:MaxMcpStrOut OutValue") \
    X(MtlBaseSetMtlFlag, "Mtl", "result", "anim Base, int32 mask, int32 val") \
    X(MtlBaseClearMtlFlag, "Mtl", "result", "anim Base, int32 mask") \
    X(MtlBaseTestMtlFlag, "Mtl", "result", "anim Base, int32 mask, ptr:int32 OutValue") \
    X(MtlBaseAnyMulti, "Mtl", "result", "anim Base, ptr:int32 OutValue") \
    X(MtlBaseRequirements, "Mtl", "result", "anim Base, int32 subMtlNum, ptr:uint32 OutValue") \
    X(MtlBaseLocalRequirements, "Mtl", "result", "anim Base, int32 subMtlNum, ptr:uint32 OutValue") \
    X(MtlBaseIsMultiMtl, "Mtl", "result", "anim Base, ptr:int32 OutValue") \
    X(MtlBaseDeactivateMapsInTree, "Mtl", "result", "anim Base") \
    X(MtlBaseUpdate, "Mtl", "result", "anim Base, int32 t, ptr:MaxMcpInterval valid") \
    X(MtlBaseReset, "Mtl", "result", "anim Base") \
    X(MtlBaseDiscardPStamp, "Mtl", "result", "anim Base, int32 sz") \
    X(MtlBaseSupportTexDisplay, "Mtl", "result", "anim Base, ptr:int32 OutValue") \
    X(MtlBaseIncrActive, "Mtl", "result", "anim Base") \
    X(MtlBaseDecrActive, "Mtl", "result", "anim Base") \
    X(MtlBaseActivateTexDisplay, "Mtl", "result", "anim Base, int32 onoff") \
    X(MtlBaseGetActiveMB, "Mtl", "result", "anim Base, ptr:anim OutValue") \
    X(MtlBaseSetActiveMB, "Mtl", "result", "anim Base, anim activeMB") \
    X(MtlBaseSupportsMultiMapsInViewport, "Mtl", "result", "anim Base, ptr:int32 OutValue") \
    X(MtlBaseGetRefTarget, "Mtl", "result", "anim Base, ptr:anim OutValue") \
    X(MtlBaseGetTransparencyHint, "Mtl", "result", "anim Base, int32 t, ptr:MaxMcpInterval valid, ptr:int32 OutValue") \
    X(ControllerCreateDefaultFloat, "Controller", "anim", "") \
    X(ControllerCreateDefaultPoint3, "Controller", "anim", "") \
    X(ControllerCreateDefaultMatrix3, "Controller", "anim", "") \
    X(ControllerCreateDefaultPosition, "Controller", "anim", "") \
    X(ControllerCreateDefaultRotation, "Controller", "anim", "") \
    X(ControllerCreateDefaultScale, "Controller", "anim", "") \
    X(ControllerCreateDefaultBool, "Controller", "anim", "") \
    X(ControllerCreateDefaultColor, "Controller", "anim", "") \
    X(ControllerCreateDefaultPoint4, "Controller", "anim", "") \
    X(ControllerCreateDefaultFRGBA, "Controller", "anim", "") \
    X(ControllerCreateDefaultPoint2, "Controller", "anim", "") \
    X(ControllerCreateInterpFloat, "Controller", "anim", "") \
    X(ControllerCreateInterpPosition, "Controller", "anim", "") \
    X(ControllerCreateInterpPoint3, "Controller", "anim", "") \
    X(ControllerCreateInterpRotation, "Controller", "anim", "") \
    X(ControllerCreateInterpScale, "Controller", "anim", "") \
    X(ControllerCreatePRS, "Controller", "anim", "") \
    X(ControllerCreateLookat, "Controller", "anim", "") \
    X(ControllerCreateInterpPoint4, "Controller", "anim", "") \
    X(ControllerCreateInterpPoint2, "Controller", "anim", "") \
    X(CurveCtlSetNumCurves, "Curve", "result", "anim CurveCtl, int32 Num, int32 DoUndo") \
    X(CurveCtlDeleteAllCurves, "Curve", "result", "anim CurveCtl") \
    X(CurveCtlDeleteCurve, "Curve", "result", "anim CurveCtl, int32 Index") \
    X(CurveCtlSetXRange, "Curve", "result", "anim CurveCtl, float Min, float Max, int32 RescaleKeys") \
    X(CurveCtlSetYRange, "Curve", "result", "anim CurveCtl, float Min, float Max") \
    X(CurveCtlSetCCFlags, "Curve", "result", "anim CurveCtl, int32 Flags") \
    X(CurveCtlSetNumPts, "Curve", "result", "anim CurveCtl, int32 CurveIndex, int32 Count") \
    X(CurveCtlSetPoint, "Curve", "result", "anim CurveCtl, int32 CurveIndex, int32 Time, int32 PtIndex, cptr:MaxMcpCurvePoint Point, int32 CheckConstraints, int32 Notify") \
    X(CurveCtlInsertPoint, "Curve", "result", "anim CurveCtl, int32 CurveIndex, int32 Where, cptr:MaxMcpCurvePoint Point, ptr:int32 OutInserted") \
    X(CurveCtlDeletePoint, "Curve", "result", "anim CurveCtl, int32 CurveIndex, int32 PtIndex") \
    X(CurveCtlSetOutOfRangeType, "Curve", "result", "anim CurveCtl, int32 CurveIndex, int32 Type") \
    X(CurveCtlSetPenProperty, "Curve", "result", "anim CurveCtl, int32 CurveIndex, int32 Color, int32 Width, int32 Style") \
    X(LinkChainInitJointAngles, "Link", "result", "held Chain") \
    X(LinkChainSetJointAngles, "Link", "result", "held Chain, cptr:MaxMcpPoint3 Angles, size Count") \
    X(LinkChainSetLinkInitValue, "Link", "result", "held Chain, int32 Index, float Value") \
    X(LinkChainSetLinkLimits, "Link", "result", "held Chain, int32 Index, cptr:MaxMcpPoint2 Value") \
    X(LinkChainSetLinkLimited, "Link", "result", "held Chain, int32 Index, int32 Lower, int32 Upper") \
    X(LinkChainSetLinkRigidExtend, "Link", "result", "held Chain, int32 Index, cptr:MaxMcpMatrix3 Value") \
    X(LinkChainSetRootInitRotation, "Link", "result", "held Chain, cptr:MaxMcpPoint3 Value") \
    X(LinkChainSetRootLimits, "Link", "result", "held Chain, cptr:MaxMcpPoint3 Lower, cptr:MaxMcpPoint3 Upper") \
    X(LinkChainSetRootRigidExtend, "Link", "result", "held Chain, cptr:MaxMcpMatrix3 Value") \
    X(LinkChainSetRootDof, "Link", "result", "held Chain, cptr:MaxMcpLinkChainRootDof Value") \
    X(LinkChainLinkApplyLinkMatrix, "Link", "result", "held Chain, int32 Index, int32 IncludeDof, ptr:MaxMcpMatrix3 Matrix") \
    X(LinkChainRootApplyLinkMatrix, "Link", "result", "held Chain, int32 IncludeRot, ptr:MaxMcpMatrix3 Matrix") \
    X(LinkChainRootRotateByAxis, "Link", "result", "held Chain, int32 Axis, ptr:MaxMcpMatrix3 Matrix") \
    X(LinkChainSplineGoalInfo, "Link", "result", "held Chain, ptr:MaxMcpLinkChainSplineGoal OutValue") \
    X(LinkChainSplineGoalPosAt, "Link", "result", "held Chain, float U, int32 WorldSpace, int32 Rebuild, ptr:MaxMcpPoint3 OutValue") \
    X(LinkChainGoalZeroPlaneMap, "Link", "result", "held Chain, cptr:MaxMcpPoint3 EEAxis, ptr:MaxMcpPoint3 OutValue") \
    X(PolyCut, "Poly", "result", "anim Object, int32 StartVert, cptr:MaxMcpPoint3 End, cptr:MaxMcpPoint3 ViewZ, int32 Split, int32 TriangulationType, ptr:int32 OutValue") \
    X(PolyCutVersioned, "Poly", "result", "anim Object, int32 StartVert, cptr:MaxMcpPoint3 End, cptr:MaxMcpPoint3 ViewZ, int32 Split, uint32 Ver, int32 TriangulationType, ptr:int32 OutValue") \
    X(PolyAutoSmoothIsland, "Poly", "result", "anim Object, float Threshold, uint32 FaceFlag, ptr:int32 OutValue") \
    X(PolyExtrudeOpenEdges, "Poly", "result", "anim Object, uint32 EdgeFlag, int32 ClearFlagOnOldEdges, int32 UseTracking, ptr:int32 OutValue") \
    X(PolyBridgeBorders, "Poly", "result", "anim Object, int32 Edge1, int32 Twist1, int32 Edge2, int32 Twist2, float SmoothThresh, int32 Segments, float Taper, float Bias, ptr:int32 OutValue") \
    X(PolyBridgePolygons, "Poly", "result", "anim Object, int32 Face1, int32 Twist1, int32 Face2, int32 Twist2, float SmoothThresh, int32 Segments, float Taper, float Bias, ptr:int32 OutValue") \
    X(PolyBridgePolygonClusters, "Poly", "result", "anim Object, uint32 PolyFlag, float SmoothThresh, int32 Segments, float Taper, float Bias, int32 Twist1, int32 Twist2, ptr:int32 OutValue") \
    X(PolyBridgeSelectedBorders, "Poly", "result", "anim Object, uint32 EdgeFlag, float SmoothThresh, int32 Segments, float Taper, float Bias, int32 Twist1, int32 Twist2, ptr:int32 OutValue") \
    X(PolyTurnDiagonal, "Poly", "result", "anim Object, int32 Face, int32 Diagonal, ptr:int32 OutValue") \
    X(PolyCutPrepare, "Poly", "result", "anim Object") \
    X(PolyCutCleanup, "Poly", "result", "anim Object") \
    X(PolyBridgeTwoEdges, "Poly", "result", "anim Object, int32 Edge1, int32 Edge2, int32 Segments, uint32 SmoothingGroup, uint32 MaterialId, int32 TriangulationType, ptr:int32 OutValue") \
    X(PolyBridgeSelectedEdges, "Poly", "result", "anim Object, uint32 EdgeFlag, float SmoothThresh, int32 Segments, float AdjacentAngle, int32 ReverseTriangle, int32 TriangulationType, ptr:int32 OutValue") \
    X(PolyChamferEdges, "Poly", "result", "anim Object, uint32 Flag, held ChamferData, int32 Open, ptr:int32 OutValue") \
    X(PolyChamferVertices, "Poly", "result", "anim Object, uint32 Flag, held ChamferData, int32 Open, ptr:int32 OutValue") \
    X(PolyInvalidateVertexCache, "Poly", "result", "anim Object, int32 Vertex") \
    X(ColorPipeGetPipeline, "Color", "result", "cstr FromSpace, cstr ToSpace, ptr:held OutHeld") \
    X(ColorPipeGetGammaPipeline, "Color", "result", "float Gamma, ptr:held OutHeld") \
    X(ColorPipeGetDefaultViewingPipeline, "Color", "result", "int32 Target, int32 Inverse, ptr:held OutHeld") \
    X(ColorPipeGetViewingPipeline, "Color", "result", "cstr FromSpace, cstr Display, cstr View, int32 Inverse, ptr:held OutHeld") \
    X(ColorPipeGetAdvancedViewingPipeline, "Color", "result", "cstr FromSpace, cstr Display, cstr View, int32 Inverse, ptr:held OutHeld") \
    X(ColorPipeGetPipelineParamToRendering, "Color", "result", "ptr:held OutHeld") \
    X(ColorPipeGetPipelineRenderingToParam, "Color", "result", "ptr:held OutHeld") \
    X(ColorPipeGetPipelineLinSRGBToRendering, "Color", "result", "ptr:held OutHeld") \
    X(ColorPipeGetPipelineRenderingToLinSRGB, "Color", "result", "ptr:held OutHeld") \
    X(ColorPipeParamCount, "Color", "result", "held Pipe, ptr:int32 OutValue") \
    X(ColorPipeGetDiagnosticString, "Color", "result", "held Pipe, ptr:MaxMcpStrOut OutValue") \
    X(ColorPipeParamName, "Color", "result", "held Pipe, int32 Index, ptr:MaxMcpStrOut OutValue") \
    X(ColorPipeParamGetValue, "Color", "result", "held Pipe, int32 Index, ptr:float OutValue") \
    X(ColorPipeParamSetValue, "Color", "result", "held Pipe, int32 Index, float Value, ptr:int32 OutValue") \
    X(ColorPipeSettingsMode, "Color", "result", "ptr:int32 OutValue") \
    X(ColorPipeSettingsIsActive, "Color", "result", "ptr:int32 OutValue") \
    X(ColorPipeSettingsIsOCIOBased, "Color", "result", "ptr:int32 OutValue") \
    X(ColorPipeSettingsGetStatus, "Color", "result", "ptr:int32 OutValue") \
    X(ColorPipeSettingsGetLocked, "Color", "result", "ptr:int32 OutValue") \
    X(ColorPipeSettingsSetLocked, "Color", "result", "int32 Lock, ptr:int32 OutOk") \
    X(ColorPipeSettingsGetModeDescription, "Color", "result", "ptr:MaxMcpStrOut OutValue") \
    X(ColorPipeSettingsGetColorSpaceDescription, "Color", "result", "cstr ColorSpace, ptr:MaxMcpStrOut OutValue") \
    X(ColorPipeSettingsGetDisplayViewDescription, "Color", "result", "cstr Display, cstr View, ptr:MaxMcpStrOut OutValue") \
    X(ColorPipeSettingsGetColorSpaceFlags, "Color", "result", "cstr ColorSpace, ptr:int32 OutValue") \
    X(ColorPipeSettingsReInitialize, "Color", "result", "ptr:int32 OutOk") \
    X(ColorPipeSettingsGetOCIOConfigFilePath, "Color", "result", "ptr:MaxMcpStrOut OutValue") \
    X(ColorPipeSettingsSetOCIOConfigFilePath, "Color", "result", "cstr PathToConfig, ptr:int32 OutOk") \
    X(ColorPipeSettingsGetOCIOConfigFileSource, "Color", "result", "ptr:int32 OutValue") \
    X(AssetGet, "Asset", "result", "cstr FileName, int32 Type, int32 AutoAcquire, ptr:held OutHeld") \
    X(AssetGetById, "Asset", "result", "cstr GuidString, ptr:held OutHeld") \
    X(AssetAddReference, "Asset", "result", "cstr GuidString, ptr:int32 OutFound") \
    X(AssetReleaseReference, "Asset", "result", "cstr GuidString, ptr:int32 OutFound") \
    X(AssetUserSetUsedInFileSave, "Asset", "result", "held Asset") \
    X(PathConfigGetAssetDirCount, "Path", "result", "int32 Type, ptr:int32 OutCount") \
    X(PathConfigGetAssetDir, "Path", "result", "int32 Index, int32 Type, ptr:MaxMcpStrOut OutValue") \
    X(PathConfigAddAssetDir, "Path", "result", "cstr Dir, int32 Type, int32 Update, ptr:int32 OutOk") \
    X(PathConfigDeleteAssetDir, "Path", "result", "int32 Index, int32 Type, int32 Update, ptr:int32 OutOk") \
    X(PathConfigGetCurAssetDirCount, "Path", "result", "int32 Type, ptr:int32 OutCount") \
    X(PathConfigGetCurAssetDir, "Path", "result", "int32 Index, int32 Type, ptr:MaxMcpStrOut OutValue") \
    X(PathConfigAddSessionAssetDir, "Path", "result", "cstr Dir, int32 Type, int32 Update, ptr:int32 OutOk") \
    X(PathConfigUpdateAssetSection, "Path", "result", "int32 Type") \
    X(PathConfigGetDir, "Path", "result", "int32 Which, ptr:MaxMcpStrOut OutValue") \
    X(PathConfigSetDir, "Path", "result", "int32 Which, cstr Dir, ptr:int32 OutOk") \
    X(PathConfigLoad, "Path", "result", "cstr FileName, ptr:int32 OutOk") \
    X(PathConfigMerge, "Path", "result", "cstr FileName, ptr:int32 OutOk") \
    X(PathConfigSave, "Path", "result", "cstr FileName, ptr:int32 OutOk") \
    X(PathConfigAppendSlash, "Path", "result", "cstr Path, ptr:MaxMcpStrOut OutValue") \
    X(PathConfigRemoveSlash, "Path", "result", "cstr Path, ptr:MaxMcpStrOut OutValue") \
    X(DxMaterialEffectBitmapCount, "DxMaterial", "result", "anim Material, ptr:int32 OutCount") \
    X(DxMaterialGetEffectFile, "DxMaterial", "result", "anim Material, ptr:held OutHeld") \
    X(DxMaterialSetEffectFile, "DxMaterial", "result", "anim Material, held Asset") \
    X(AssetAccessorCurrent, "Asset", "result", "ptr:held OutHeld") \
    X(AssetAccessorSetCurrent, "Asset", "result", "held Asset, int32 Type") \
    X(OsnapGetNode, "Osnap", "result", "held Manager, ptr:node OutNode") \
    X(OsnapOKForRelativeSnap, "Osnap", "result", "held Manager, ptr:int32 OutValue") \
    X(OsnapRefPointWasSnapped, "Osnap", "result", "held Manager, ptr:int32 OutValue") \
    X(OsnapGetRefPoint, "Osnap", "result", "held Manager, int32 Top, ptr:MaxMcpPoint3 OutValue") \
    X(OsnapGetObjectTM, "Osnap", "result", "held Manager, ptr:MaxMcpMatrix3 OutValue") \
    X(OsnapGetTime, "Osnap", "result", "held Manager, ptr:int32 OutValue") \
    X(OsnapGetCurrentPoint, "Osnap", "result", "held Manager, ptr:MaxMcpPoint3 OutValue") \
    X(OsnapGetSnapStrength, "Osnap", "result", "held Manager, ptr:int32 OutValue") \
    X(OsnapWTranspoint, "Osnap", "result", "held Manager, cptr:MaxMcpPoint3 InPoint, ptr:int32 OutX, ptr:int32 OutY, ptr:int32 OutZ") \
    X(OsnapGetVpt, "Osnap", "result", "held Manager, ptr:held OutVpt") \
    X(OsnapGetSnapInfo, "Osnap", "result", "held Manager, ptr:MaxMcpSnapInfo OutValue") \
    X(OsnapGetSnapRadius, "Osnap", "result", "held Manager, ptr:int32 OutValue") \
    X(OsnapGetSnapPreviewRadius, "Osnap", "result", "held Manager, ptr:int32 OutValue") \
    X(ManipCurrentGizmoBuild, "Manip", "result", "ptr:int32 OutActive, ptr:held OutBuilder") \
    X(GizmoShapeStartNewLine, "Gizmo", "result", "held Builder") \
    X(GizmoShapeAppendPoint, "Gizmo", "result", "held Builder, cptr:MaxMcpPoint3 P") \
    X(GizmoShapeAppendPolyline, "Gizmo", "result", "held Builder, cptr:MaxMcpPoint3 Points, size Count, int32 Closed") \
    X(GizmoShapeMakeCircle, "Gizmo", "result", "held Builder, cptr:MaxMcpPoint3 Center, float Radius, int32 Segments") \
    X(GizmoShapeMakeRect, "Gizmo", "result", "held Builder, cptr:MaxMcpPoint3 Center, float Width, float Height, int32 Plane") \
    X(GizmoBuildSetAppearance, "Gizmo", "result", "held Builder, cptr:MaxMcpPoint3 UnselColor, int32 Flags") \
    X(RenderContextCurrent, "Render", "result", "ptr:int32 OutKind, ptr:int32 OutTime, ptr:held OutGlobalContext, ptr:held OutCheckAbort, ptr:held OutViewParams, ptr:held OutRendParams, ptr:held OutProgress, ptr:held OutDefaultLights, ptr:int32 OutNumDefLights") \
    X(RenderGlobalContextInfo, "Render", "result", "held GlobalContext, ptr:MaxMcpRenderGlobalContext OutValue") \
    X(RenderGlobalContextCamToWorld, "Render", "result", "held GlobalContext, ptr:MaxMcpMatrix3 OutValue") \
    X(RenderGlobalContextWorldToCam, "Render", "result", "held GlobalContext, ptr:MaxMcpMatrix3 OutValue") \
    X(RenderGlobalContextMapToScreen, "Render", "result", "held GlobalContext, cptr:MaxMcpPoint3 WorldPt, ptr:MaxMcpPoint2 OutValue") \
    X(RenderGlobalContextRenderer, "Render", "result", "held GlobalContext, ptr:anim OutValue") \
    X(RenderGlobalContextEnvMap, "Render", "result", "held GlobalContext, ptr:anim OutValue") \
    X(RenderGlobalContextAtmos, "Render", "result", "held GlobalContext, ptr:anim OutValue") \
    X(RenderGlobalContextToneOp, "Render", "result", "held GlobalContext, ptr:anim OutValue") \
    X(RenderGlobalContextNumRenderInstances, "Render", "result", "held GlobalContext, ptr:int32 OutValue") \
    X(CheckAbortCheck, "Check", "result", "held CheckAbort, ptr:int32 OutValue") \
    X(CheckAbortProgress, "Check", "result", "held CheckAbort, int32 Done, int32 Total, ptr:int32 OutValue") \
    X(ViewParamsInfo, "View", "result", "held ViewParams, ptr:MaxMcpViewParams OutValue") \
    X(ViewParamsAffineTM, "View", "result", "held ViewParams, ptr:MaxMcpMatrix3 OutValue") \
    X(ViewParamsPrevAffineTM, "View", "result", "held ViewParams, ptr:MaxMcpMatrix3 OutValue") \
    X(RendParamsInfo, "Rend", "result", "held RendParams, ptr:MaxMcpRendParams OutValue") \
    X(RendParamsEnvMap, "Rend", "result", "held RendParams, ptr:anim OutValue") \
    X(RendParamsAtmos, "Rend", "result", "held RendParams, ptr:anim OutValue") \
    X(RendParamsEffect, "Rend", "result", "held RendParams, ptr:anim OutValue") \
    X(RendParamsToneOp, "Rend", "result", "held RendParams, ptr:anim OutValue") \
    X(RendProgressProgress, "Rend", "result", "held Progress, int32 Done, int32 Total, ptr:int32 OutValue") \
    X(RendProgressSetTitle, "Rend", "result", "held Progress, cstr Title") \
    X(RendProgressSetCurField, "Rend", "result", "held Progress, int32 Which") \
    X(RendProgressSetStep, "Rend", "result", "held Progress, int32 Current, int32 Total") \
    X(RendProgressSetSceneStats, "Rend", "result", "held Progress, int32 NLights, int32 NRayTraced, int32 NShadowed, int32 NObj, int32 NFaces") \
    X(DefaultLightTM, "Default", "result", "held DefaultLights, int32 Index, ptr:MaxMcpMatrix3 OutValue") \
    X(DefaultLightState, "Default", "result", "held DefaultLights, int32 Index, ptr:MaxMcpLightState OutValue") \
    X(LinkChainCurrent, "Link", "result", "ptr:int32 OutActive, ptr:held OutChain") \
    X(NurbsCVSurfaceAppend, "Nurbs", "result", "held Set, ptr:int32 OutIndex") \
    X(NurbsCVSurfaceSetNumCVs, "Nurbs", "result", "held Set, int32 Index, int32 NumU, int32 NumV") \
    X(NurbsCVSurfaceSetOrders, "Nurbs", "result", "held Set, int32 Index, int32 UOrder, int32 VOrder") \
    X(NurbsCVSurfaceSetNumKnots, "Nurbs", "result", "held Set, int32 Index, int32 NumU, int32 NumV") \
    X(NurbsCVSurfaceSetCVAt, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 U, int32 V, cptr:MaxMcpNurbsCV CV") \
    X(NurbsCVSurfaceSetKnot, "Nurbs", "result", "held Set, int32 Index, int32 Axis, int32 KnotIndex, double Value") \
    X(NurbsCVCurveAppend, "Nurbs", "result", "held Set, ptr:int32 OutIndex") \
    X(NurbsCVCurveSetNumCVs, "Nurbs", "result", "held Set, int32 Index, int32 Num") \
    X(NurbsCVCurveSetOrder, "Nurbs", "result", "held Set, int32 Index, int32 Order") \
    X(NurbsCVCurveSetNumKnots, "Nurbs", "result", "held Set, int32 Index, int32 Num") \
    X(NurbsCVCurveSetCVAt, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 I, cptr:MaxMcpNurbsCV CV") \
    X(NurbsCVCurveSetKnot, "Nurbs", "result", "held Set, int32 Index, int32 KnotIndex, double Value") \
    X(NurbsCVCurveClose, "Nurbs", "result", "held Set, int32 Index") \
    X(NurbsObjectSetName, "Nurbs", "result", "held Set, int32 Index, cstr Name") \
    X(NurbsCreateObject, "Nurbs", "result", "held Set, cptr:MaxMcpMatrix3 Tm, cstr Name, ptr:node OutNode") \
    X(ShapeSplineCountOfInput, "Shape", "result", "anim Object, ptr:int32 OutCount") \
    X(ShapeSplinePointsReadOfInput, "Shape", "result", "anim Object, int32 Index, ptr:MaxMcpShapePoint OutPoints, size Capacity, ptr:int32 OutWritten, ptr:int32 OutClosed") \
    X(ShapeKnotCountOfInput, "Shape", "result", "anim Object, int32 Spline, ptr:int32 OutCount") \
    X(ShapeKnotReadOfInput, "Shape", "result", "anim Object, int32 Spline, int32 Knot, ptr:MaxMcpKnot OutKnot") \
    X(ShapeSplineClosedOfInput, "Shape", "result", "anim Object, int32 Spline, ptr:int32 OutClosed") \
    X(ShapeSegCountOfInput, "Shape", "result", "anim Object, int32 Spline, ptr:int32 OutCount") \
    X(ShapeSegMatIdOfInput, "Shape", "result", "anim Object, int32 Spline, int32 Segment, ptr:uint32 OutMaterial") \
    X(ShapeLineCountOfInput, "Shape", "int32", "anim Object, int32 Time") \
    X(ShapeLineReadOfInput, "Shape", "result", "anim Object, int32 Time, int32 Index, ptr:MaxMcpShapeLine OutLine") \
    X(ShapePointsReadObjectOfInput, "Shape", "result", "anim Object, int32 Time, int32 Index, ptr:MaxMcpShapePoint OutPoints, size Capacity, ptr:int32 OutWritten") \
    X(ShapeBezierSplineCountOfInput, "Shape", "result", "anim Object, int32 Time, ptr:int32 OutCount") \
    X(ShapeBezierKnotCountOfInput, "Shape", "result", "anim Object, int32 Time, int32 Spline, ptr:int32 OutCount") \
    X(ShapeBezierKnotReadOfInput, "Shape", "result", "anim Object, int32 Time, int32 Spline, int32 Knot, ptr:MaxMcpKnot OutKnot") \
    X(ShapeBezierSplineClosedOfInput, "Shape", "result", "anim Object, int32 Time, int32 Spline, ptr:int32 OutClosed") \
    X(ShapeCurveCountOfInput, "Shape", "result", "anim Object, int32 Time, ptr:int32 OutCount") \
    X(ShapeCurveClosedOfInput, "Shape", "result", "anim Object, int32 Time, int32 Curve, ptr:int32 OutClosed") \
    X(ShapeCurveInterpOfInput, "Shape", "result", "anim Object, int32 Time, int32 Curve, float Param, int32 ParamType, ptr:float OutPoint") \
    X(ShapeCurveTangentOfInput, "Shape", "result", "anim Object, int32 Time, int32 Curve, float Param, int32 ParamType, ptr:float OutTangent") \
    X(ShapeCurveLengthOfInput, "Shape", "result", "anim Object, int32 Time, int32 Curve, ptr:float OutLength") \
    X(ShapePieceCountOfInput, "Shape", "result", "anim Object, int32 Time, int32 Curve, ptr:int32 OutCount") \
    X(ShapePieceInterpOfInput, "Shape", "result", "anim Object, int32 Time, int32 Curve, int32 Piece, float Param, int32 ParamType, ptr:float OutPoint") \
    X(ShapePieceTangentOfInput, "Shape", "result", "anim Object, int32 Time, int32 Curve, int32 Piece, float Param, int32 ParamType, ptr:float OutTangent") \
    X(ShapePieceMatIdOfInput, "Shape", "result", "anim Object, int32 Time, int32 Curve, int32 Piece, ptr:uint32 OutMaterial") \
    X(ShapeCanMakeBezierOfInput, "Shape", "result", "anim Object, int32 Time, ptr:int32 OutCan") \
    X(ShapeRenderReadOfInput, "Shape", "result", "anim Object, int32 Time, ptr:MaxMcpShapeRender OutRender") \
    X(NurbsGenSphere, "Nurbs", "result", "held Set, float Radius, float StartAngleU, float EndAngleU, float StartAngleV, float EndAngleV, int32 Open, cptr:MaxMcpMatrix3 Tm, ptr:int32 OutIndex") \
    X(NurbsGenCylinder, "Nurbs", "result", "held Set, float Radius, float Height, float StartAngle, float EndAngle, int32 Open, cptr:MaxMcpMatrix3 Tm, ptr:int32 OutIndex") \
    X(NurbsGenCone, "Nurbs", "result", "held Set, float Radius1, float Radius2, float Height, float StartAngle, float EndAngle, int32 Open, cptr:MaxMcpMatrix3 Tm, ptr:int32 OutIndex") \
    X(NurbsGenTorus, "Nurbs", "result", "held Set, float MajorRadius, float MinorRadius, float StartAngleU, float EndAngleU, float StartAngleV, float EndAngleV, int32 Open, cptr:MaxMcpMatrix3 Tm, ptr:int32 OutIndex") \
    X(NurbsGenLathe, "Nurbs", "result", "held Set, int32 CurveIndex, float StartAngle, float EndAngle, cptr:MaxMcpMatrix3 Tm, ptr:int32 OutIndex") \
    X(NurbsSetAppendCylinder, "Nurbs", "result", "held Set, float Radius, float Height, ptr:int32 OutIndex") \
    X(NurbsSetAppendCone, "Nurbs", "result", "held Set, float Radius1, float Radius2, float Height, ptr:int32 OutIndex") \
    X(NurbsSetAppendTorus, "Nurbs", "result", "held Set, float MajorRadius, float MinorRadius, ptr:int32 OutIndex") \
    X(NurbsSetAppendLathe, "Nurbs", "result", "held Set, int32 CurveIndex, ptr:int32 OutIndex") \
    X(NurbsBlendSurfaceAppend, "Nurbs", "result", "held Set, ptr:int32 OutIndex") \
    X(NurbsBlendSurfaceSetParent, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 ParentIndex") \
    X(NurbsBlendSurfaceSetEdge, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 Edge") \
    X(NurbsBlendSurfaceSetTension, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 Pnum, double Tension") \
    X(NurbsBlendSurfaceSetFlip, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 Flip") \
    X(NurbsBlendSurfaceSetCurveStartPoint, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 Pnum, double StartPoint") \
    X(NurbsBlendSurfaceGetTension, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 Pnum, ptr:double OutValue") \
    X(NurbsOffsetSurfaceAppend, "Nurbs", "result", "held Set, ptr:int32 OutIndex") \
    X(NurbsOffsetSurfaceSetParent, "Nurbs", "result", "held Set, int32 Index, int32 ParentIndex") \
    X(NurbsOffsetSurfaceSetDistance, "Nurbs", "result", "held Set, int32 Index, int32 Time, double Distance") \
    X(NurbsOffsetSurfaceGetDistance, "Nurbs", "result", "held Set, int32 Index, int32 Time, ptr:double OutValue") \
    X(NurbsOffsetSurfaceGetParent, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsExtrudeSurfaceAppend, "Nurbs", "result", "held Set, ptr:int32 OutIndex") \
    X(NurbsExtrudeSurfaceSetParent, "Nurbs", "result", "held Set, int32 Index, int32 ParentIndex") \
    X(NurbsExtrudeSurfaceSetDistance, "Nurbs", "result", "held Set, int32 Index, int32 Time, double Distance") \
    X(NurbsExtrudeSurfaceSetAxis, "Nurbs", "result", "held Set, int32 Index, int32 Time, cptr:MaxMcpMatrix3 Ray") \
    X(NurbsExtrudeSurfaceSetCurveStartPoint, "Nurbs", "result", "held Set, int32 Index, int32 Time, double StartPoint") \
    X(NurbsExtrudeSurfaceGetDistance, "Nurbs", "result", "held Set, int32 Index, int32 Time, ptr:double OutValue") \
    X(NurbsLatheSurfaceAppend, "Nurbs", "result", "held Set, ptr:int32 OutIndex") \
    X(NurbsLatheSurfaceSetParent, "Nurbs", "result", "held Set, int32 Index, int32 ParentIndex") \
    X(NurbsLatheSurfaceSetAxis, "Nurbs", "result", "held Set, int32 Index, int32 Time, cptr:MaxMcpMatrix3 Ray") \
    X(NurbsLatheSurfaceSetRotation, "Nurbs", "result", "held Set, int32 Index, int32 Time, double Degrees") \
    X(NurbsLatheSurfaceSetCurveStartPoint, "Nurbs", "result", "held Set, int32 Index, int32 Time, double StartPoint") \
    X(NurbsLatheSurfaceGetRotation, "Nurbs", "result", "held Set, int32 Index, int32 Time, ptr:double OutValue") \
    X(NurbsRuledSurfaceAppend, "Nurbs", "result", "held Set, ptr:int32 OutIndex") \
    X(NurbsRuledSurfaceSetParent, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 ParentIndex") \
    X(NurbsRuledSurfaceSetFlip, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 Flip") \
    X(NurbsRuledSurfaceSetCurveStartPoint, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 Pnum, double StartPoint") \
    X(NurbsRuledSurfaceGetParent, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, ptr:int32 OutValue") \
    X(NurbsULoftSurfaceAppend, "Nurbs", "result", "held Set, ptr:int32 OutIndex") \
    X(NurbsULoftSurfaceSetNumCurves, "Nurbs", "result", "held Set, int32 Index, int32 Num") \
    X(NurbsULoftSurfaceAppendCurve, "Nurbs", "result", "held Set, int32 Index, int32 CurveIndex, int32 Flip, double StartPoint, double Tension, int32 UseTangent, int32 FlipTangent, ptr:int32 OutCount") \
    X(NurbsULoftSurfaceSetCloseLoft, "Nurbs", "result", "held Set, int32 Index, int32 Close") \
    X(NurbsULoftSurfaceSetAutoAlign, "Nurbs", "result", "held Set, int32 Index, int32 AutoAlign") \
    X(NurbsULoftSurfaceGetNumCurves, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsUVLoftSurfaceAppend, "Nurbs", "result", "held Set, ptr:int32 OutIndex") \
    X(NurbsUVLoftSurfaceSetNumUCurves, "Nurbs", "result", "held Set, int32 Index, int32 Num") \
    X(NurbsUVLoftSurfaceSetNumVCurves, "Nurbs", "result", "held Set, int32 Index, int32 Num") \
    X(NurbsUVLoftSurfaceAppendUCurve, "Nurbs", "result", "held Set, int32 Index, int32 CurveIndex, ptr:int32 OutCount") \
    X(NurbsUVLoftSurfaceAppendVCurve, "Nurbs", "result", "held Set, int32 Index, int32 CurveIndex, ptr:int32 OutCount") \
    X(NurbsUVLoftSurfaceGetNumUCurves, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsUVLoftSurfaceGetNumVCurves, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsCapSurfaceAppend, "Nurbs", "result", "held Set, ptr:int32 OutIndex") \
    X(NurbsCapSurfaceSetParent, "Nurbs", "result", "held Set, int32 Index, int32 ParentIndex") \
    X(NurbsCapSurfaceSetEdge, "Nurbs", "result", "held Set, int32 Index, int32 Edge") \
    X(NurbsCapSurfaceSetCurveStartPoint, "Nurbs", "result", "held Set, int32 Index, int32 Time, double StartPoint") \
    X(NurbsCapSurfaceGetEdge, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsFilletSurfaceAppend, "Nurbs", "result", "held Set, ptr:int32 OutIndex") \
    X(NurbsFilletSurfaceSetParent, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 ParentIndex") \
    X(NurbsFilletSurfaceSetRadius, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 Rnum, float Radius") \
    X(NurbsFilletSurfaceSetCubic, "Nurbs", "result", "held Set, int32 Index, int32 Cubic") \
    X(NurbsFilletSurfaceSetSeed, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, double U, double V") \
    X(NurbsFilletSurfaceSetTrimSurface, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 Trim") \
    X(NurbsFilletSurfaceGetRadius, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 Rnum, ptr:float OutValue") \
    X(NurbsMirrorSurfaceAppend, "Nurbs", "result", "held Set, ptr:int32 OutIndex") \
    X(NurbsMirrorSurfaceSetParent, "Nurbs", "result", "held Set, int32 Index, int32 ParentIndex") \
    X(NurbsMirrorSurfaceSetAxis, "Nurbs", "result", "held Set, int32 Index, int32 Axis") \
    X(NurbsMirrorSurfaceSetDistance, "Nurbs", "result", "held Set, int32 Index, int32 Time, double Distance") \
    X(NurbsMirrorSurfaceSetXForm, "Nurbs", "result", "held Set, int32 Index, int32 Time, cptr:MaxMcpMatrix3 Mat") \
    X(NurbsMirrorSurfaceGetAxis, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsNBlendSurfaceAppend, "Nurbs", "result", "held Set, ptr:int32 OutIndex") \
    X(NurbsNBlendSurfaceSetParent, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 ParentIndex") \
    X(NurbsNBlendSurfaceSetEdge, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 Edge") \
    X(NurbsNBlendSurfaceGetParent, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, ptr:int32 OutValue") \
    X(Nurbs1RailSweepSurfaceAppend, "Nurbs1", "result", "held Set, ptr:int32 OutIndex") \
    X(Nurbs1RailSweepSurfaceSetParentRail, "Nurbs1", "result", "held Set, int32 Index, int32 RailIndex") \
    X(Nurbs1RailSweepSurfaceSetNumCurves, "Nurbs1", "result", "held Set, int32 Index, int32 Num") \
    X(Nurbs1RailSweepSurfaceAppendCurve, "Nurbs1", "result", "held Set, int32 Index, int32 CurveIndex, int32 Flip, double StartPoint, ptr:int32 OutCount") \
    X(Nurbs1RailSweepSurfaceSetParallel, "Nurbs1", "result", "held Set, int32 Index, int32 Parallel") \
    X(Nurbs1RailSweepSurfaceSetRoadlike, "Nurbs1", "result", "held Set, int32 Index, int32 Roadlike") \
    X(Nurbs1RailSweepSurfaceSetSnapCS, "Nurbs1", "result", "held Set, int32 Index, int32 SnapCS") \
    X(Nurbs1RailSweepSurfaceSetAxis, "Nurbs1", "result", "held Set, int32 Index, int32 Time, cptr:MaxMcpMatrix3 Ray") \
    X(Nurbs2RailSweepSurfaceAppend, "Nurbs2", "result", "held Set, ptr:int32 OutIndex") \
    X(Nurbs2RailSweepSurfaceSetNumCurves, "Nurbs2", "result", "held Set, int32 Index, int32 Num") \
    X(Nurbs2RailSweepSurfaceAppendCurve, "Nurbs2", "result", "held Set, int32 Index, int32 CurveIndex, int32 Flip, double StartPoint, ptr:int32 OutCount") \
    X(Nurbs2RailSweepSurfaceSetRailParent, "Nurbs2", "result", "held Set, int32 Index, int32 Pnum, int32 RailIndex") \
    X(Nurbs2RailSweepSurfaceSetParallel, "Nurbs2", "result", "held Set, int32 Index, int32 Parallel") \
    X(Nurbs2RailSweepSurfaceSetScale, "Nurbs2", "result", "held Set, int32 Index, int32 Scale") \
    X(Nurbs2RailSweepSurfaceSetSnapCS, "Nurbs2", "result", "held Set, int32 Index, int32 SnapCS") \
    X(NurbsMultiCurveTrimSurfaceAppend, "Nurbs", "result", "held Set, ptr:int32 OutIndex") \
    X(NurbsMultiCurveTrimSurfaceSetNumCurves, "Nurbs", "result", "held Set, int32 Index, int32 Num") \
    X(NurbsMultiCurveTrimSurfaceAppendCurve, "Nurbs", "result", "held Set, int32 Index, int32 CurveIndex, ptr:int32 OutCount") \
    X(NurbsMultiCurveTrimSurfaceSetSurfaceParent, "Nurbs", "result", "held Set, int32 Index, int32 SurfaceIndex") \
    X(NurbsMultiCurveTrimSurfaceSetFlipTrim, "Nurbs", "result", "held Set, int32 Index, int32 Flip") \
    X(NurbsMultiCurveTrimSurfaceGetFlipTrim, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsXFormSurfaceAppend, "Nurbs", "result", "held Set, ptr:int32 OutIndex") \
    X(NurbsXFormSurfaceSetParent, "Nurbs", "result", "held Set, int32 Index, int32 ParentIndex") \
    X(NurbsXFormSurfaceSetXForm, "Nurbs", "result", "held Set, int32 Index, int32 Time, cptr:MaxMcpMatrix3 Mat") \
    X(NurbsXFormSurfaceGetParent, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsPointSurfaceAppend, "Nurbs", "result", "held Set, ptr:int32 OutIndex") \
    X(NurbsPointSurfaceSetNumPts, "Nurbs", "result", "held Set, int32 Index, int32 NumU, int32 NumV") \
    X(NurbsPointSurfaceSetPointAt, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 U, int32 V, double X, double Y, double Z") \
    X(NurbsPointSurfaceCloseInU, "Nurbs", "result", "held Set, int32 Index") \
    X(NurbsPointSurfaceCloseInV, "Nurbs", "result", "held Set, int32 Index") \
    X(NurbsPointSurfaceGetNumPts, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutNumU, ptr:int32 OutNumV") \
    X(NurbsPointCurveAppend, "Nurbs", "result", "held Set, ptr:int32 OutIndex") \
    X(NurbsPointCurveSetNumPts, "Nurbs", "result", "held Set, int32 Index, int32 Num") \
    X(NurbsPointCurveGetNumPts, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutNum") \
    X(NurbsPointCurveSetPoint, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 PtIndex, cptr:MaxMcpPoint3 Pt") \
    X(NurbsPointCurveGetPoint, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 PtIndex, ptr:MaxMcpPoint3 OutPt") \
    X(NurbsPointCurveClose, "Nurbs", "result", "held Set, int32 Index") \
    X(NurbsBlendCurveAppend, "Nurbs", "result", "held Set, int32 Parent0, int32 Parent1, ptr:int32 OutIndex") \
    X(NurbsBlendCurveSetParent, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 ParentIndex") \
    X(NurbsBlendCurveSetEnd, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 End") \
    X(NurbsBlendCurveSetTension, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 Pnum, double Tension") \
    X(NurbsBlendCurveGetTension, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 Pnum, ptr:double OutValue") \
    X(NurbsOffsetCurveAppend, "Nurbs", "result", "held Set, int32 Parent, ptr:int32 OutIndex") \
    X(NurbsOffsetCurveSetDistance, "Nurbs", "result", "held Set, int32 Index, int32 Time, double Distance") \
    X(NurbsOffsetCurveGetDistance, "Nurbs", "result", "held Set, int32 Index, int32 Time, ptr:double OutValue") \
    X(NurbsXFormCurveAppend, "Nurbs", "result", "held Set, int32 Parent, ptr:int32 OutIndex") \
    X(NurbsXFormCurveSetXForm, "Nurbs", "result", "held Set, int32 Index, int32 Time, cptr:MaxMcpMatrix3 Tm") \
    X(NurbsXFormCurveGetXForm, "Nurbs", "result", "held Set, int32 Index, int32 Time, ptr:MaxMcpMatrix3 OutTm") \
    X(NurbsMirrorCurveAppend, "Nurbs", "result", "held Set, int32 Parent, ptr:int32 OutIndex") \
    X(NurbsMirrorCurveSetAxis, "Nurbs", "result", "held Set, int32 Index, int32 Axis") \
    X(NurbsMirrorCurveGetAxis, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsMirrorCurveSetDistance, "Nurbs", "result", "held Set, int32 Index, int32 Time, double Distance") \
    X(NurbsMirrorCurveGetDistance, "Nurbs", "result", "held Set, int32 Index, int32 Time, ptr:double OutValue") \
    X(NurbsMirrorCurveSetXForm, "Nurbs", "result", "held Set, int32 Index, int32 Time, cptr:MaxMcpMatrix3 Tm") \
    X(NurbsFilletCurveAppend, "Nurbs", "result", "held Set, int32 Parent0, int32 Parent1, ptr:int32 OutIndex") \
    X(NurbsFilletCurveSetRadius, "Nurbs", "result", "held Set, int32 Index, int32 Time, double Radius") \
    X(NurbsFilletCurveGetRadius, "Nurbs", "result", "held Set, int32 Index, int32 Time, ptr:double OutValue") \
    X(NurbsFilletCurveSetEnd, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 End") \
    X(NurbsFilletCurveSetTrimCurve, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 Trim") \
    X(NurbsFilletCurveSetFlipTrim, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 Flip") \
    X(NurbsChamferCurveAppend, "Nurbs", "result", "held Set, int32 Parent0, int32 Parent1, ptr:int32 OutIndex") \
    X(NurbsChamferCurveSetLength, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 Pnum, double Length") \
    X(NurbsChamferCurveGetLength, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 Pnum, ptr:double OutValue") \
    X(NurbsChamferCurveSetEnd, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 End") \
    X(NurbsChamferCurveSetTrimCurve, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 Trim") \
    X(NurbsChamferCurveSetFlipTrim, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 Flip") \
    X(NurbsIsoCurveAppend, "Nurbs", "result", "held Set, int32 Parent, ptr:int32 OutIndex") \
    X(NurbsIsoCurveSetDirection, "Nurbs", "result", "held Set, int32 Index, int32 IsU") \
    X(NurbsIsoCurveSetParam, "Nurbs", "result", "held Set, int32 Index, int32 Time, double Param") \
    X(NurbsIsoCurveGetParam, "Nurbs", "result", "held Set, int32 Index, int32 Time, ptr:double OutValue") \
    X(NurbsIsoCurveSetTrim, "Nurbs", "result", "held Set, int32 Index, int32 Trim") \
    X(NurbsIsoCurveSetSeed, "Nurbs", "result", "held Set, int32 Index, double SeedU, double SeedV") \
    X(NurbsSurfaceEdgeCurveAppend, "Nurbs", "result", "held Set, int32 Parent, ptr:int32 OutIndex") \
    X(NurbsSurfaceEdgeCurveSetSeed, "Nurbs", "result", "held Set, int32 Index, double SeedU, double SeedV") \
    X(NurbsSurfaceNormalCurveAppend, "Nurbs", "result", "held Set, int32 Parent, ptr:int32 OutIndex") \
    X(NurbsSurfaceNormalCurveSetDistance, "Nurbs", "result", "held Set, int32 Index, int32 Time, double Distance") \
    X(NurbsSurfaceNormalCurveGetDistance, "Nurbs", "result", "held Set, int32 Index, int32 Time, ptr:double OutValue") \
    X(NurbsProjectNormalCurveAppend, "Nurbs", "result", "held Set, int32 SurfParent, int32 CurveParent, ptr:int32 OutIndex") \
    X(NurbsProjectNormalCurveSetTrim, "Nurbs", "result", "held Set, int32 Index, int32 Trim") \
    X(NurbsProjectNormalCurveSetFlipTrim, "Nurbs", "result", "held Set, int32 Index, int32 Flip") \
    X(NurbsProjectNormalCurveSetSeed, "Nurbs", "result", "held Set, int32 Index, double SeedU, double SeedV") \
    X(NurbsProjectVectorCurveAppend, "Nurbs", "result", "held Set, int32 SurfParent, int32 CurveParent, ptr:int32 OutIndex") \
    X(NurbsProjectVectorCurveSetTrim, "Nurbs", "result", "held Set, int32 Index, int32 Trim") \
    X(NurbsProjectVectorCurveSetFlipTrim, "Nurbs", "result", "held Set, int32 Index, int32 Flip") \
    X(NurbsProjectVectorCurveSetSeed, "Nurbs", "result", "held Set, int32 Index, double SeedU, double SeedV") \
    X(NurbsProjectVectorCurveSetPVec, "Nurbs", "result", "held Set, int32 Index, int32 Time, cptr:MaxMcpPoint3 Vec") \
    X(NurbsSurfSurfIntersectionCurveAppend, "Nurbs", "result", "held Set, int32 Parent0, int32 Parent1, ptr:int32 OutIndex") \
    X(NurbsSurfSurfIntersectionCurveSetTrim, "Nurbs", "result", "held Set, int32 Index, int32 Tnum, int32 Trim") \
    X(NurbsSurfSurfIntersectionCurveSetFlipTrim, "Nurbs", "result", "held Set, int32 Index, int32 Tnum, int32 Flip") \
    X(NurbsSurfSurfIntersectionCurveSetSeed, "Nurbs", "result", "held Set, int32 Index, double SeedU, double SeedV") \
    X(NurbsCurveOnSurfaceAppend, "Nurbs", "result", "held Set, int32 SurfParent, ptr:int32 OutIndex") \
    X(NurbsCurveOnSurfaceSetTrim, "Nurbs", "result", "held Set, int32 Index, int32 Trim") \
    X(NurbsCurveOnSurfaceSetFlipTrim, "Nurbs", "result", "held Set, int32 Index, int32 Flip") \
    X(NurbsCurveOnSurfaceSetNumCVs, "Nurbs", "result", "held Set, int32 Index, int32 Num") \
    X(NurbsCurveOnSurfaceSetOrder, "Nurbs", "result", "held Set, int32 Index, int32 Order") \
    X(NurbsCurveOnSurfaceSetNumKnots, "Nurbs", "result", "held Set, int32 Index, int32 Num") \
    X(NurbsCurveOnSurfaceSetCVAt, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 I, cptr:MaxMcpNurbsCV CV") \
    X(NurbsCurveOnSurfaceSetKnot, "Nurbs", "result", "held Set, int32 Index, int32 KnotIndex, double Value") \
    X(NurbsPointCurveOnSurfaceAppend, "Nurbs", "result", "held Set, int32 SurfParent, ptr:int32 OutIndex") \
    X(NurbsPointCurveOnSurfaceSetTrim, "Nurbs", "result", "held Set, int32 Index, int32 Trim") \
    X(NurbsPointCurveOnSurfaceSetFlipTrim, "Nurbs", "result", "held Set, int32 Index, int32 Flip") \
    X(NurbsPointCurveOnSurfaceSetNumPts, "Nurbs", "result", "held Set, int32 Index, int32 Num") \
    X(NurbsPointCurveOnSurfaceSetPoint, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 PtIndex, cptr:MaxMcpPoint3 Pt") \
    X(NurbsPointCurveOnSurfaceClose, "Nurbs", "result", "held Set, int32 Index") \
    X(NurbsIndependentPointAppend, "Nurbs", "result", "held Set, ptr:int32 OutIndex") \
    X(NurbsIndependentPointSetPosition, "Nurbs", "result", "held Set, int32 Index, int32 Time, cptr:MaxMcpPoint3 Pt") \
    X(NurbsPointConstPointAppend, "Nurbs", "result", "held Set, int32 Parent, ptr:int32 OutIndex") \
    X(NurbsPointConstPointSetPointType, "Nurbs", "result", "held Set, int32 Index, int32 Type") \
    X(NurbsPointConstPointSetOffset, "Nurbs", "result", "held Set, int32 Index, int32 Time, cptr:MaxMcpPoint3 Offset") \
    X(NurbsPointConstPointGetOffset, "Nurbs", "result", "held Set, int32 Index, int32 Time, ptr:MaxMcpPoint3 OutOffset") \
    X(NurbsCurveConstPointAppend, "Nurbs", "result", "held Set, int32 Parent, ptr:int32 OutIndex") \
    X(NurbsCurveConstPointSetPointType, "Nurbs", "result", "held Set, int32 Index, int32 Type") \
    X(NurbsCurveConstPointSetUParam, "Nurbs", "result", "held Set, int32 Index, int32 Time, double Param") \
    X(NurbsCurveConstPointGetUParam, "Nurbs", "result", "held Set, int32 Index, int32 Time, ptr:double OutValue") \
    X(NurbsCurveConstPointSetOffset, "Nurbs", "result", "held Set, int32 Index, int32 Time, cptr:MaxMcpPoint3 Offset") \
    X(NurbsCurveConstPointSetNormal, "Nurbs", "result", "held Set, int32 Index, int32 Time, float Dist") \
    X(NurbsSurfConstPointAppend, "Nurbs", "result", "held Set, int32 Parent, ptr:int32 OutIndex") \
    X(NurbsSurfConstPointSetPointType, "Nurbs", "result", "held Set, int32 Index, int32 Type") \
    X(NurbsSurfConstPointSetUParam, "Nurbs", "result", "held Set, int32 Index, int32 Time, double Param") \
    X(NurbsSurfConstPointSetVParam, "Nurbs", "result", "held Set, int32 Index, int32 Time, double Param") \
    X(NurbsSurfConstPointSetOffset, "Nurbs", "result", "held Set, int32 Index, int32 Time, cptr:MaxMcpPoint3 Offset") \
    X(NurbsSurfConstPointSetNormal, "Nurbs", "result", "held Set, int32 Index, int32 Time, float Dist") \
    X(NurbsCurveCurveIntersectionPointAppend, "Nurbs", "result", "held Set, int32 Parent0, int32 Parent1, ptr:int32 OutIndex") \
    X(NurbsCurveCurveIntersectionPointSetCurveParam, "Nurbs", "result", "held Set, int32 Index, int32 CurveNum, double Param") \
    X(NurbsCurveCurveIntersectionPointGetCurveParam, "Nurbs", "result", "held Set, int32 Index, int32 CurveNum, ptr:double OutValue") \
    X(NurbsCurveCurveIntersectionPointSetTrimCurve, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 Trim") \
    X(NurbsCurveCurveIntersectionPointSetFlipTrim, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 Flip") \
    X(NurbsCurveSurfaceIntersectionPointAppend, "Nurbs", "result", "held Set, int32 SurfParent, int32 CurveParent, ptr:int32 OutIndex") \
    X(NurbsCurveSurfaceIntersectionPointSetSeed, "Nurbs", "result", "held Set, int32 Index, double Seed") \
    X(NurbsCurveSurfaceIntersectionPointGetSeed, "Nurbs", "result", "held Set, int32 Index, ptr:double OutValue") \
    X(NurbsCurveSurfaceIntersectionPointSetTrimCurve, "Nurbs", "result", "held Set, int32 Index, int32 Trim") \
    X(NurbsCurveSurfaceIntersectionPointSetFlipTrim, "Nurbs", "result", "held Set, int32 Index, int32 Flip") \
    X(NurbsCurveTrimPointCount, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutCount") \
    X(NurbsCurveGetTrimPoint, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 I, ptr:double OutParameter, ptr:int32 OutDirection") \
    X(NurbsSetClean, "Nurbs", "result", "held Set") \
    X(NurbsSetRemoveObject, "Nurbs", "result", "held Set, int32 Index") \
    X(NurbsSetGetTessMerge, "Nurbs", "result", "held Set, ptr:float OutValue") \
    X(NurbsSetSetTessMerge, "Nurbs", "result", "held Set, float Merge") \
    X(NurbsSetAddToNode, "Nurbs", "result", "held Set, node Node, int32 Time, ptr:int32 OutCount") \
    X(NurbsObjectGetIndex, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsObjectIsSelected, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsObjectSetSelected, "Nurbs", "result", "held Set, int32 Index, int32 Selected") \
    X(NurbsCVSurfaceGetTransform, "Nurbs", "result", "held Set, int32 Index, int32 Time, ptr:MaxMcpMatrix3 OutTm") \
    X(NurbsCVSurfaceSetTransform, "Nurbs", "result", "held Set, int32 Index, int32 Time, cptr:MaxMcpMatrix3 Tm") \
    X(NurbsCVCurveGetTransform, "Nurbs", "result", "held Set, int32 Index, int32 Time, ptr:MaxMcpMatrix3 OutTm") \
    X(NurbsCVCurveSetTransform, "Nurbs", "result", "held Set, int32 Index, int32 Time, cptr:MaxMcpMatrix3 Tm") \
    X(NurbsSurfaceGetMatID, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsSurfaceSetMatID, "Nurbs", "result", "held Set, int32 Index, int32 MatId") \
    X(NurbsCurveGetMatID, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsCurveSetMatID, "Nurbs", "result", "held Set, int32 Index, int32 MatId") \
    X(NurbsSurfaceGetRenderable, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsSurfaceSetRenderable, "Nurbs", "result", "held Set, int32 Index, int32 State") \
    X(NurbsSurfaceGetFlipNormals, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsSurfaceSetFlipNormals, "Nurbs", "result", "held Set, int32 Index, int32 State") \
    X(NurbsSurfaceGetGenerateUVs, "Nurbs", "result", "held Set, int32 Index, int32 Channel, ptr:int32 OutValue") \
    X(NurbsSurfaceSetGenerateUVs, "Nurbs", "result", "held Set, int32 Index, int32 Channel, int32 State") \
    X(NurbsSurfaceIsClosed, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutClosedU, ptr:int32 OutClosedV") \
    X(NurbsTrimSurfaceAppend, "Nurbs", "result", "held Set, ptr:int32 OutIndex") \
    X(NurbsTrimSurfaceSetNumCurves, "Nurbs", "result", "held Set, int32 Index, int32 Num") \
    X(NurbsTrimSurfaceGetNumCurves, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsTrimSurfaceAppendCurve, "Nurbs", "result", "held Set, int32 Index, int32 CurveIndex, ptr:int32 OutCount") \
    X(NurbsTrimSurfaceSetParent, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, int32 CurveIndex") \
    X(NurbsTrimSurfaceGetParent, "Nurbs", "result", "held Set, int32 Index, int32 Pnum, ptr:int32 OutValue") \
    X(NurbsTrimSurfaceSetSurfaceParent, "Nurbs", "result", "held Set, int32 Index, int32 SurfaceIndex") \
    X(NurbsTrimSurfaceGetSurfaceParent, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsTrimSurfaceSetFlipTrim, "Nurbs", "result", "held Set, int32 Index, int32 Flip") \
    X(NurbsTrimSurfaceGetFlipTrim, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsSurfaceNumChannels, "Nurbs", "result", "held Set, int32 Index, ptr:int32 OutValue") \
    X(NurbsSurfaceGetChannelFromIndex, "Nurbs", "result", "held Set, int32 Index, int32 ChannelIndex, ptr:int32 OutValue") \
    X(NurbsSurfaceGetTextureUV, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 Corner, int32 Channel, ptr:float OutU, ptr:float OutV") \
    X(NurbsSurfaceSetTextureUV, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 Corner, int32 Channel, float U, float V") \
    X(NurbsSurfaceGetTileOffset, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 Channel, ptr:float OutUTile, ptr:float OutVTile, ptr:float OutUOffset, ptr:float OutVOffset, ptr:float OutAngle") \
    X(NurbsSurfaceSetTileOffset, "Nurbs", "result", "held Set, int32 Index, int32 Time, int32 Channel, float UTile, float VTile, float UOffset, float VOffset, float Angle") \
    X(NurbsTextureSurfaceGetMapperType, "Nurbs", "result", "held Set, int32 Index, int32 Channel, ptr:int32 OutValue") \
    X(NurbsTextureSurfaceSetMapperType, "Nurbs", "result", "held Set, int32 Index, int32 Channel, int32 Type") \
    X(NurbsTextureSurfaceGetNumPoints, "Nurbs", "result", "held Set, int32 Index, int32 Channel, ptr:int32 OutU, ptr:int32 OutV") \
    X(NurbsTextureSurfaceSetNumPoints, "Nurbs", "result", "held Set, int32 Index, int32 Channel, int32 NumU, int32 NumV") \
    X(NurbsTextureSurfaceGetParent, "Nurbs", "result", "held Set, int32 Index, int32 Channel, ptr:int32 OutValue") \
    X(NurbsTextureSurfaceSetParent, "Nurbs", "result", "held Set, int32 Index, int32 Channel, int32 ParentIndex") \
    X(NurbsTextureSurfaceGetPoint, "Nurbs", "result", "held Set, int32 Index, int32 Channel, int32 Time, int32 U, int32 V, ptr:double OutX, ptr:double OutY") \
    X(NurbsTextureSurfaceSetPoint, "Nurbs", "result", "held Set, int32 Index, int32 Channel, int32 Time, int32 U, int32 V, double X, double Y") \
    X(NurbsFuseSurfaceCV, "Nurbs", "result", "held Set, int32 Surf1, int32 Surf2, int32 Row1, int32 Col1, int32 Row2, int32 Col2, ptr:int32 OutCount") \
    X(NurbsFuseCurveCV, "Nurbs", "result", "held Set, int32 Curve1, int32 Curve2, int32 CV1, int32 CV2, ptr:int32 OutCount") \
    X(NurbsSetSurfFuseCount, "Nurbs", "result", "held Set, ptr:int32 OutValue") \
    X(NurbsSetCurveFuseCount, "Nurbs", "result", "held Set, ptr:int32 OutValue") \
    X(NurbsSetGetSurfFuse, "Nurbs", "result", "held Set, int32 I, ptr:int32 OutSurf1, ptr:int32 OutSurf2, ptr:int32 OutRow1, ptr:int32 OutCol1, ptr:int32 OutRow2, ptr:int32 OutCol2") \
    X(NurbsSetGetCurveFuse, "Nurbs", "result", "held Set, int32 I, ptr:int32 OutCurve1, ptr:int32 OutCurve2, ptr:int32 OutCV1, ptr:int32 OutCV2") \
    X(NurbsSetClearSurfFuse, "Nurbs", "result", "held Set") \
    X(NurbsSetClearCurveFuse, "Nurbs", "result", "held Set") \
    X(PatchSetUIParam, "Patch", "result", "anim Object, int32 UICode, float Val") \
    X(SplineStartCommandMode, "Spline", "result", "node Node, int32 Mode") \
    X(SplineButtonOp, "Spline", "result", "node Node, int32 Opcode") \
    X(SplineSetUIParam, "Spline", "result", "node Node, int32 UICode, int32 Val") \
    X(ObjectSetXTCObjectBranchID, "Object", "result", "anim Object, int32 Index, int32 BranchID") \
    X(ObjectBranchDeleted, "Object", "result", "anim Object, int32 BranchID, int32 ReorderChannels") \
    X(ObjectDeleteAllAdditionalChannels, "Object", "result", "anim Object")

// One define per entry, so a name can be tested as well as read.
#define MAXMCP_FACADE_HAS_SceneRoot 1
#define MAXMCP_FACADE_HAS_NodeChildCount 1
#define MAXMCP_FACADE_HAS_NodeChild 1
#define MAXMCP_FACADE_HAS_NodeName 1
#define MAXMCP_FACADE_HAS_NodeSelected 1
#define MAXMCP_FACADE_HAS_NodeFaceCounts 1
#define MAXMCP_FACADE_HAS_CurrentTime 1
#define MAXMCP_FACADE_HAS_LightCreate 1
#define MAXMCP_FACADE_HAS_LightRead 1
#define MAXMCP_FACADE_HAS_LightWrite 1
#define MAXMCP_FACADE_HAS_LightExcludedName 1
#define MAXMCP_FACADE_HAS_NodeDelete 1
#define MAXMCP_FACADE_HAS_NodeTransformRead 1
#define MAXMCP_FACADE_HAS_NodeTransformWrite 1
#define MAXMCP_FACADE_HAS_CameraCreate 1
#define MAXMCP_FACADE_HAS_CameraRead 1
#define MAXMCP_FACADE_HAS_CameraWrite 1
#define MAXMCP_FACADE_HAS_ShapeCreate 1
#define MAXMCP_FACADE_HAS_ShapeLineCount 1
#define MAXMCP_FACADE_HAS_ShapeLineRead 1
#define MAXMCP_FACADE_HAS_ShapePointsRead 1
#define MAXMCP_FACADE_HAS_ShapeClear 1
#define MAXMCP_FACADE_HAS_ShapeLineAppend 1
#define MAXMCP_FACADE_HAS_HelperCreate 1
#define MAXMCP_FACADE_HAS_HelperRead 1
#define MAXMCP_FACADE_HAS_HelperClassName 1
#define MAXMCP_FACADE_HAS_MeshColorCounts 1
#define MAXMCP_FACADE_HAS_MeshColorVertsRead 1
#define MAXMCP_FACADE_HAS_MeshColorFacesRead 1
#define MAXMCP_FACADE_HAS_MeshColorWrite 1
#define MAXMCP_FACADE_HAS_NodeMaterial 1
#define MAXMCP_FACADE_HAS_NodeWireColor 1
#define MAXMCP_FACADE_HAS_NodeSetMaterial 1
#define MAXMCP_FACADE_HAS_MaterialCreate 1
#define MAXMCP_FACADE_HAS_MaterialRead 1
#define MAXMCP_FACADE_HAS_MaterialWrite 1
#define MAXMCP_FACADE_HAS_MaterialName 1
#define MAXMCP_FACADE_HAS_MaterialSetName 1
#define MAXMCP_FACADE_HAS_MaterialClassName 1
#define MAXMCP_FACADE_HAS_MaterialSubMaterial 1
#define MAXMCP_FACADE_HAS_MaterialSetSubMaterial 1
#define MAXMCP_FACADE_HAS_MaterialSubTexmap 1
#define MAXMCP_FACADE_HAS_MaterialSetSubTexmap 1
#define MAXMCP_FACADE_HAS_MaterialMapEnabled 1
#define MAXMCP_FACADE_HAS_MaterialMapAmount 1
#define MAXMCP_FACADE_HAS_TexmapCreateBitmap 1
#define MAXMCP_FACADE_HAS_TexmapRead 1
#define MAXMCP_FACADE_HAS_TexmapWrite 1
#define MAXMCP_FACADE_HAS_TexmapName 1
#define MAXMCP_FACADE_HAS_TexmapSetName 1
#define MAXMCP_FACADE_HAS_TexmapClassName 1
#define MAXMCP_FACADE_HAS_TexmapBitmapName 1
#define MAXMCP_FACADE_HAS_TexmapSetBitmapName 1
#define MAXMCP_FACADE_HAS_TexmapSubTexmap 1
#define MAXMCP_FACADE_HAS_TexmapSetSubTexmap 1
#define MAXMCP_FACADE_HAS_TexmapUVGenRead 1
#define MAXMCP_FACADE_HAS_TexmapUVGenWrite 1
#define MAXMCP_FACADE_HAS_SceneEnvironmentMap 1
#define MAXMCP_FACADE_HAS_SceneSetEnvironmentMap 1
#define MAXMCP_FACADE_HAS_NodeTMController 1
#define MAXMCP_FACADE_HAS_ControllerSubController 1
#define MAXMCP_FACADE_HAS_NodeVisibilityController 1
#define MAXMCP_FACADE_HAS_SceneBackgroundController 1
#define MAXMCP_FACADE_HAS_SceneAmbientController 1
#define MAXMCP_FACADE_HAS_ControllerRead 1
#define MAXMCP_FACADE_HAS_ControllerKeyRead 1
#define MAXMCP_FACADE_HAS_ControllerKeyWrite 1
#define MAXMCP_FACADE_HAS_ControllerKeyAppend 1
#define MAXMCP_FACADE_HAS_ControllerKeyDelete 1
#define MAXMCP_FACADE_HAS_NodeSampleRead 1
#define MAXMCP_FACADE_HAS_ControllerClassName 1
#define MAXMCP_FACADE_HAS_ControllerTimeRange 1
#define MAXMCP_FACADE_HAS_ControllerValueFloat 1
#define MAXMCP_FACADE_HAS_ControllerValuePoint3 1
#define MAXMCP_FACADE_HAS_SceneAnimRange 1
#define MAXMCP_FACADE_HAS_CameraValidity 1
#define MAXMCP_FACADE_HAS_LightValidity 1
#define MAXMCP_FACADE_HAS_NodeObjectValidity 1
#define MAXMCP_FACADE_HAS_MaterialHasMapControls 1
#define MAXMCP_FACADE_HAS_CameraTargetDistanceRaw 1
#define MAXMCP_FACADE_HAS_decomp_affine 1
#define MAXMCP_FACADE_HAS_comp_affine 1
#define MAXMCP_FACADE_HAS_invert_affine 1
#define MAXMCP_FACADE_HAS_SpectralDecomp 1
#define MAXMCP_FACADE_HAS_QFromAngAxis 1
#define MAXMCP_FACADE_HAS_AngAxisFromQ 1
#define MAXMCP_FACADE_HAS_QuatInverse 1
#define MAXMCP_FACADE_HAS_QuatConjugate 1
#define MAXMCP_FACADE_HAS_QuatLogN 1
#define MAXMCP_FACADE_HAS_QuatExp 1
#define MAXMCP_FACADE_HAS_QuatMultiply 1
#define MAXMCP_FACADE_HAS_QuatDivide 1
#define MAXMCP_FACADE_HAS_QuatNormalize 1
#define MAXMCP_FACADE_HAS_QuatIsIdentity 1
#define MAXMCP_FACADE_HAS_QuatMakeClosest 1
#define MAXMCP_FACADE_HAS_AngAxisGetNumRevs 1
#define MAXMCP_FACADE_HAS_AngAxisSetNumRevs 1
#define MAXMCP_FACADE_HAS_Slerp 1
#define MAXMCP_FACADE_HAS_QCompA 1
#define MAXMCP_FACADE_HAS_Squad 1
#define MAXMCP_FACADE_HAS_qorthog 1
#define MAXMCP_FACADE_HAS_squadrev 1
#define MAXMCP_FACADE_HAS_QangAxis 1
#define MAXMCP_FACADE_HAS_TransformQuat 1
#define MAXMCP_FACADE_HAS_QuatToEuler 1
#define MAXMCP_FACADE_HAS_EulerToQuat 1
#define MAXMCP_FACADE_HAS_MatrixToEuler 1
#define MAXMCP_FACADE_HAS_EulerToMatrix 1
#define MAXMCP_FACADE_HAS_ContinuousQuatToEuler 1
#define MAXMCP_FACADE_HAS_GetEulerQuatAngleRatio 1
#define MAXMCP_FACADE_HAS_GetEulerMatAngleRatio 1
#define MAXMCP_FACADE_HAS_RotateXMatrix 1
#define MAXMCP_FACADE_HAS_RotateYMatrix 1
#define MAXMCP_FACADE_HAS_RotateZMatrix 1
#define MAXMCP_FACADE_HAS_RotateYPRMatrix 1
#define MAXMCP_FACADE_HAS_RotAngleAxisMatrix 1
#define MAXMCP_FACADE_HAS_TransMatrix 1
#define MAXMCP_FACADE_HAS_ScaleMatrix 1
#define MAXMCP_FACADE_HAS_MatrixInverse 1
#define MAXMCP_FACADE_HAS_InverseHighPrecision 1
#define MAXMCP_FACADE_HAS_PseudoInverse 1
#define MAXMCP_FACADE_HAS_AffineTranspose 1
#define MAXMCP_FACADE_HAS_MatrixMultiply 1
#define MAXMCP_FACADE_HAS_XFormMat 1
#define MAXMCP_FACADE_HAS_MatrixTransformPoint 1
#define MAXMCP_FACADE_HAS_VectorTransform 1
#define MAXMCP_FACADE_HAS_RotateMatrix 1
#define MAXMCP_FACADE_HAS_PreRotateMatrix 1
#define MAXMCP_FACADE_HAS_MatrixHasNegativeParity 1
#define MAXMCP_FACADE_HAS_RGBtoHSV 1
#define MAXMCP_FACADE_HAS_HSVtoRGB 1
#define MAXMCP_FACADE_HAS_HSVtoRGBInt 1
#define MAXMCP_FACADE_HAS_GetTicksPerFrame 1
#define MAXMCP_FACADE_HAS_GetFrameRate 1
#define MAXMCP_FACADE_HAS_GetSystemUnitScale 1
#define MAXMCP_FACADE_HAS_GetRelativeScale 1
#define MAXMCP_FACADE_HAS_IsValidUnitCharacter 1
#define MAXMCP_FACADE_HAS_FormatUniverseValue 1
#define MAXMCP_FACADE_HAS_DecodeUniverseValue 1
#define MAXMCP_FACADE_HAS_TimeToString 1
#define MAXMCP_FACADE_HAS_StringToTime 1
#define MAXMCP_FACADE_HAS_NodeBaseObject 1
#define MAXMCP_FACADE_HAS_NodeEvaluatedObject 1
#define MAXMCP_FACADE_HAS_MeshVertexCount 1
#define MAXMCP_FACADE_HAS_MeshFaceCount 1
#define MAXMCP_FACADE_HAS_setNumVerts 1
#define MAXMCP_FACADE_HAS_setNumFaces 1
#define MAXMCP_FACADE_HAS_MeshVertsRead 1
#define MAXMCP_FACADE_HAS_MeshVertsWrite 1
#define MAXMCP_FACADE_HAS_MeshFacesRead 1
#define MAXMCP_FACADE_HAS_MeshFacesWrite 1
#define MAXMCP_FACADE_HAS_getMatID 1
#define MAXMCP_FACADE_HAS_setMatID 1
#define MAXMCP_FACADE_HAS_getEdgeVis 1
#define MAXMCP_FACADE_HAS_setEdgeVis 1
#define MAXMCP_FACADE_HAS_getNumMaps 1
#define MAXMCP_FACADE_HAS_setNumMaps 1
#define MAXMCP_FACADE_HAS_mapSupport 1
#define MAXMCP_FACADE_HAS_setMapSupport 1
#define MAXMCP_FACADE_HAS_getNumMapVerts 1
#define MAXMCP_FACADE_HAS_setNumMapVerts 1
#define MAXMCP_FACADE_HAS_getNumMapFaces 1
#define MAXMCP_FACADE_HAS_setNumMapFaces 1
#define MAXMCP_FACADE_HAS_MeshMapVertsRead 1
#define MAXMCP_FACADE_HAS_MeshMapVertsWrite 1
#define MAXMCP_FACADE_HAS_MeshMapFacesRead 1
#define MAXMCP_FACADE_HAS_MeshMapFacesWrite 1
#define MAXMCP_FACADE_HAS_buildNormals 1
#define MAXMCP_FACADE_HAS_checkNormals 1
#define MAXMCP_FACADE_HAS_FlipNormal 1
#define MAXMCP_FACADE_HAS_UnifyNormals 1
#define MAXMCP_FACADE_HAS_AutoSmooth 1
#define MAXMCP_FACADE_HAS_FaceNormal 1
#define MAXMCP_FACADE_HAS_FaceCenter 1
#define MAXMCP_FACADE_HAS_AngleBetweenFaces 1
#define MAXMCP_FACADE_HAS_DeleteVertSet 1
#define MAXMCP_FACADE_HAS_DeleteFaceSet 1
#define MAXMCP_FACADE_HAS_DeleteIsoVerts 1
#define MAXMCP_FACADE_HAS_DeleteFlaggedFaces 1
#define MAXMCP_FACADE_HAS_BreakVerts 1
#define MAXMCP_FACADE_HAS_CloneFaces 1
#define MAXMCP_FACADE_HAS_WeldCollinear 1
#define MAXMCP_FACADE_HAS_ExtrudeFaces 1
#define MAXMCP_FACADE_HAS_DivideEdge 1
#define MAXMCP_FACADE_HAS_DivideFace 1
#define MAXMCP_FACADE_HAS_TurnEdge 1
#define MAXMCP_FACADE_HAS_EdgeTessellate 1
#define MAXMCP_FACADE_HAS_FindOpenEdges 1
#define MAXMCP_FACADE_HAS_ElementFromFace 1
#define MAXMCP_FACADE_HAS_SliceMesh 1
#define MAXMCP_FACADE_HAS_Optimize 1
#define MAXMCP_FACADE_HAS_ApplyUVWMap 1
#define MAXMCP_FACADE_HAS_FreeAll 1
#define MAXMCP_FACADE_HAS_InvalidateGeomCache 1
#define MAXMCP_FACADE_HAS_InvalidateTopologyCache 1
#define MAXMCP_FACADE_HAS_CombineMeshes 1
#define MAXMCP_FACADE_HAS_DeepCopy 1
#define MAXMCP_FACADE_HAS_getBoundingBox 1
#define MAXMCP_FACADE_HAS_PointsWereChanged 1
#define MAXMCP_FACADE_HAS_EventSubscribe 1
#define MAXMCP_FACADE_HAS_EventUnsubscribe 1
#define MAXMCP_FACADE_HAS_EventPending 1
#define MAXMCP_FACADE_HAS_EventsRead 1
#define MAXMCP_FACADE_HAS_EventsDropped 1
#define MAXMCP_FACADE_HAS_NodeObjectClassId 1
#define MAXMCP_FACADE_HAS_AnimClassId 1
#define MAXMCP_FACADE_HAS_NodeCreateMesh 1
#define MAXMCP_FACADE_HAS_NodeSetName 1
#define MAXMCP_FACADE_HAS_NodeSetSelected 1
#define MAXMCP_FACADE_HAS_NodeParent 1
#define MAXMCP_FACADE_HAS_NodeAttachChild 1
#define MAXMCP_FACADE_HAS_NodeSetWireColor 1
#define MAXMCP_FACADE_HAS_NodeFlagsRead 1
#define MAXMCP_FACADE_HAS_NodeFlagsWrite 1
#define MAXMCP_FACADE_HAS_NodeUserPropBuffer 1
#define MAXMCP_FACADE_HAS_NodeSetUserPropBuffer 1
#define MAXMCP_FACADE_HAS_LightSetExcluded 1
#define MAXMCP_FACADE_HAS_ControllerCreate 1
#define MAXMCP_FACADE_HAS_NodeSetTMController 1
#define MAXMCP_FACADE_HAS_NodeSetVisibilityController 1
#define MAXMCP_FACADE_HAS_ControllerSetSubController 1
#define MAXMCP_FACADE_HAS_SceneAmbient 1
#define MAXMCP_FACADE_HAS_SceneSetAmbient 1
#define MAXMCP_FACADE_HAS_SceneBackground 1
#define MAXMCP_FACADE_HAS_SceneSetBackground 1
#define MAXMCP_FACADE_HAS_SceneSetAnimRange 1
#define MAXMCP_FACADE_HAS_SceneSetTime 1
#define MAXMCP_FACADE_HAS_MeshVertSelRead 1
#define MAXMCP_FACADE_HAS_MeshVertSelWrite 1
#define MAXMCP_FACADE_HAS_MeshFaceSelRead 1
#define MAXMCP_FACADE_HAS_MeshFaceSelWrite 1
#define MAXMCP_FACADE_HAS_MeshEdgeSelRead 1
#define MAXMCP_FACADE_HAS_MeshEdgeSelWrite 1
#define MAXMCP_FACADE_HAS_MeshSelLevelRead 1
#define MAXMCP_FACADE_HAS_MeshSelLevelWrite 1
#define MAXMCP_FACADE_HAS_MaterialCreateByClass 1
#define MAXMCP_FACADE_HAS_TexmapCreate 1
#define MAXMCP_FACADE_HAS_HoldBegin 1
#define MAXMCP_FACADE_HAS_HoldAccept 1
#define MAXMCP_FACADE_HAS_HoldCancel 1
#define MAXMCP_FACADE_HAS_HoldRestore 1
#define MAXMCP_FACADE_HAS_HoldSuspend 1
#define MAXMCP_FACADE_HAS_HoldResume 1
#define MAXMCP_FACADE_HAS_HoldSuperBegin 1
#define MAXMCP_FACADE_HAS_HoldSuperAccept 1
#define MAXMCP_FACADE_HAS_HoldSuperCancel 1
#define MAXMCP_FACADE_HAS_HoldStateRead 1
#define MAXMCP_FACADE_HAS_NodeIsGroupHead 1
#define MAXMCP_FACADE_HAS_NodeIkFlags 1
#define MAXMCP_FACADE_HAS_ControllerJointParams 1
#define MAXMCP_FACADE_HAS_ChamferDataCreate 1
#define MAXMCP_FACADE_HAS_AdjEdgeListCreate 1
#define MAXMCP_FACADE_HAS_MeshChamferVertices 1
#define MAXMCP_FACADE_HAS_MeshChamferEdges 1
#define MAXMCP_FACADE_HAS_MeshChamferMove 1
#define MAXMCP_FACADE_HAS_InstanceCreate 1
#define MAXMCP_FACADE_HAS_NodeCreateWithObject 1
#define MAXMCP_FACADE_HAS_HeldDispose 1
#define MAXMCP_FACADE_HAS_HeldCount 1
#define MAXMCP_FACADE_HAS_LightExcludeAdd 1
#define MAXMCP_FACADE_HAS_LightExcludedNode 1
#define MAXMCP_FACADE_HAS_LightExcludeSet 1
#define MAXMCP_FACADE_HAS_LightExcludeRemove 1
#define MAXMCP_FACADE_HAS_SceneSetAmbientController 1
#define MAXMCP_FACADE_HAS_SceneSetBackgroundController 1
#define MAXMCP_FACADE_HAS_NodeIkFlagsWrite 1
#define MAXMCP_FACADE_HAS_ControllerJointParamsWrite 1
#define MAXMCP_FACADE_HAS_HoldSuspendedRead 1
#define MAXMCP_FACADE_HAS_ShapeSplineCount 1
#define MAXMCP_FACADE_HAS_ShapeSplinePointsRead 1
#define MAXMCP_FACADE_HAS_ShapeSplineReplace 1
#define MAXMCP_FACADE_HAS_ShapeSplineDelete 1
#define MAXMCP_FACADE_HAS_ShapeSplineDeleteMany 1
#define MAXMCP_FACADE_HAS_EventSubscribedCodes 1
#define MAXMCP_FACADE_HAS_EventSubscriberCount 1
#define MAXMCP_FACADE_HAS_AnimRelease 1
#define MAXMCP_FACADE_HAS_AnimClassName 1
#define MAXMCP_FACADE_HAS_NodeObjectClassName 1
#define MAXMCP_FACADE_HAS_NodeObjectBBox 1
#define MAXMCP_FACADE_HAS_MtlBaseValidity 1
#define MAXMCP_FACADE_HAS_MtlDisplacementValidity 1
#define MAXMCP_FACADE_HAS_MaterialSetMapEnabled 1
#define MAXMCP_FACADE_HAS_MaterialSetMapAmount 1
#define MAXMCP_FACADE_HAS_MeshVertexNormal 1
#define MAXMCP_FACADE_HAS_MeshVertexNormalCount 1
#define MAXMCP_FACADE_HAS_MeshSetVertexNormal 1
#define MAXMCP_FACADE_HAS_MultiMaterialSetCount 1
#define MAXMCP_FACADE_HAS_MultiMaterialAdd 1
#define MAXMCP_FACADE_HAS_MultiMaterialRemove 1
#define MAXMCP_FACADE_HAS_MultiMaterialSetSubAndName 1
#define MAXMCP_FACADE_HAS_MultiMaterialSubName 1
#define MAXMCP_FACADE_HAS_MaterialSubMtlSlotName 1
#define MAXMCP_FACADE_HAS_MtlBaseSubTexmapSlotName 1
#define MAXMCP_FACADE_HAS_MtlBaseMapSlotType 1
#define MAXMCP_FACADE_HAS_CompositeTexmapSetCount 1
#define MAXMCP_FACADE_HAS_AnimInstanceCreate 1
#define MAXMCP_FACADE_HAS_NodeCreateForObject 1
#define MAXMCP_FACADE_HAS_NameMakeUnique 1
#define MAXMCP_FACADE_HAS_NodeSetObjectRef 1
#define MAXMCP_FACADE_HAS_NodeObjectOrWSMRef 1
#define MAXMCP_FACADE_HAS_AnimDeleteThis 1
#define MAXMCP_FACADE_HAS_SuperClassCount 1
#define MAXMCP_FACADE_HAS_SuperClassAt 1
#define MAXMCP_FACADE_HAS_ClassCount 1
#define MAXMCP_FACADE_HAS_ClassAt 1
#define MAXMCP_FACADE_HAS_ClassEntryName 1
#define MAXMCP_FACADE_HAS_ClassEntryNonLocalizedName 1
#define MAXMCP_FACADE_HAS_ClassCategory 1
#define MAXMCP_FACADE_HAS_ClassEntryIsLoaded 1
#define MAXMCP_FACADE_HAS_DefaultControllerRead 1
#define MAXMCP_FACADE_HAS_DefaultControllerWrite 1
#define MAXMCP_FACADE_HAS_AnimIsRefMaker 1
#define MAXMCP_FACADE_HAS_AnimIsRefTarget 1
#define MAXMCP_FACADE_HAS_NodeAsAnim 1
#define MAXMCP_FACADE_HAS_AnimAsNode 1
#define MAXMCP_FACADE_HAS_AnimSubCount 1
#define MAXMCP_FACADE_HAS_AnimSubAnim 1
#define MAXMCP_FACADE_HAS_AnimSubAnimName 1
#define MAXMCP_FACADE_HAS_AnimSubNumToRefNum 1
#define MAXMCP_FACADE_HAS_AnimRefCount 1
#define MAXMCP_FACADE_HAS_AnimReference 1
#define MAXMCP_FACADE_HAS_AnimFindRef 1
#define MAXMCP_FACADE_HAS_AnimDependents 1
#define MAXMCP_FACADE_HAS_AnimDirectDependents 1
#define MAXMCP_FACADE_HAS_ControllerSubCount 1
#define MAXMCP_FACADE_HAS_ControllerSubControllerAt 1
#define MAXMCP_FACADE_HAS_ControllerCreatePointContainer 1
#define MAXMCP_FACADE_HAS_ControllerAddSubController 1
#define MAXMCP_FACADE_HAS_AnimCanAssignController 1
#define MAXMCP_FACADE_HAS_AnimAssignController 1
#define MAXMCP_FACADE_HAS_AnimTestForLoop 1
#define MAXMCP_FACADE_HAS_AnimCanTransferReference 1
#define MAXMCP_FACADE_HAS_AnimReplaceReference 1
#define MAXMCP_FACADE_HAS_ControllerSetSubControllerAt 1
#define MAXMCP_FACADE_HAS_ControllerSetSubCount 1
#define MAXMCP_FACADE_HAS_AnimCanDeleteSubAnim 1
#define MAXMCP_FACADE_HAS_AnimDeleteSubAnim 1
#define MAXMCP_FACADE_HAS_AnimDeleteReference 1
#define MAXMCP_FACADE_HAS_ControllerDeleteSubControllers 1
#define MAXMCP_FACADE_HAS_AnimHasInterface 1
#define MAXMCP_FACADE_HAS_AnimInterfaceName 1
#define MAXMCP_FACADE_HAS_AnimHasLegacyInterface 1
#define MAXMCP_FACADE_HAS_ClassInterfaceCount 1
#define MAXMCP_FACADE_HAS_ClassInterfaceIdAt 1
#define MAXMCP_FACADE_HAS_ClassInterfaceNameAt 1
#define MAXMCP_FACADE_HAS_ClassHasInterface 1
#define MAXMCP_FACADE_HAS_AnimLimitEnableRead 1
#define MAXMCP_FACADE_HAS_AnimLimitEnableWrite 1
#define MAXMCP_FACADE_HAS_AnimLimitedControlRead 1
#define MAXMCP_FACADE_HAS_AnimLimitedControlWrite 1
#define MAXMCP_FACADE_HAS_AnimEulerOrderRead 1
#define MAXMCP_FACADE_HAS_AnimEulerOrderWrite 1
#define MAXMCP_FACADE_HAS_AnimRealWorldMapSizeRead 1
#define MAXMCP_FACADE_HAS_AnimRealWorldMapSizeTagRead 1
#define MAXMCP_FACADE_HAS_AnimRealWorldMapSizeWrite 1
#define MAXMCP_FACADE_HAS_AnimAppDataWrite 1
#define MAXMCP_FACADE_HAS_AnimAppDataRead 1
#define MAXMCP_FACADE_HAS_AnimAppDataDelete 1
#define MAXMCP_FACADE_HAS_AnimAppDataClearAll 1
#define MAXMCP_FACADE_HAS_AnimCustAttribContainer 1
#define MAXMCP_FACADE_HAS_AnimCustAttribContainerCreate 1
#define MAXMCP_FACADE_HAS_AnimCustAttribContainerDelete 1
#define MAXMCP_FACADE_HAS_CustAttribContainerOwner 1
#define MAXMCP_FACADE_HAS_AnimCustAttribCount 1
#define MAXMCP_FACADE_HAS_AnimCustAttribAt 1
#define MAXMCP_FACADE_HAS_CustAttribName 1
#define MAXMCP_FACADE_HAS_AnimCustAttribAppend 1
#define MAXMCP_FACADE_HAS_AnimCustAttribInsert 1
#define MAXMCP_FACADE_HAS_AnimCustAttribSet 1
#define MAXMCP_FACADE_HAS_AnimCustAttribRemove 1
#define MAXMCP_FACADE_HAS_AnimParamBlockCount 1
#define MAXMCP_FACADE_HAS_AnimParamBlock 1
#define MAXMCP_FACADE_HAS_AnimParamBlockById 1
#define MAXMCP_FACADE_HAS_ParamBlockId 1
#define MAXMCP_FACADE_HAS_ParamBlockVersion 1
#define MAXMCP_FACADE_HAS_ParamBlockName 1
#define MAXMCP_FACADE_HAS_ParamBlockOwner 1
#define MAXMCP_FACADE_HAS_ParamBlockValidity 1
#define MAXMCP_FACADE_HAS_ParamBlockParamCount 1
#define MAXMCP_FACADE_HAS_ParamBlockParamId 1
#define MAXMCP_FACADE_HAS_ParamBlockParamIndex 1
#define MAXMCP_FACADE_HAS_ParamBlockParamType 1
#define MAXMCP_FACADE_HAS_ParamBlockParamName 1
#define MAXMCP_FACADE_HAS_ParamBlockParamNonLocalizedName 1
#define MAXMCP_FACADE_HAS_ParamBlockParamLocalName 1
#define MAXMCP_FACADE_HAS_ParamBlockParamDef 1
#define MAXMCP_FACADE_HAS_ParamBlockParamControlType 1
#define MAXMCP_FACADE_HAS_ParamBlockParamAnimNum 1
#define MAXMCP_FACADE_HAS_ParamBlockAnimNumToParamIndex 1
#define MAXMCP_FACADE_HAS_ParamBlockParamRefNum 1
#define MAXMCP_FACADE_HAS_ParamBlockParamControllerRefNum 1
#define MAXMCP_FACADE_HAS_ParamBlockValueFloat 1
#define MAXMCP_FACADE_HAS_ParamBlockValueInt 1
#define MAXMCP_FACADE_HAS_ParamBlockValuePoint2 1
#define MAXMCP_FACADE_HAS_ParamBlockValuePoint3 1
#define MAXMCP_FACADE_HAS_ParamBlockValuePoint4 1
#define MAXMCP_FACADE_HAS_ParamBlockValueColor 1
#define MAXMCP_FACADE_HAS_ParamBlockValueAColor 1
#define MAXMCP_FACADE_HAS_ParamBlockValueString 1
#define MAXMCP_FACADE_HAS_ParamBlockValueMtl 1
#define MAXMCP_FACADE_HAS_ParamBlockValueTexmap 1
#define MAXMCP_FACADE_HAS_ParamBlockValueNode 1
#define MAXMCP_FACADE_HAS_ParamBlockValueRefTarget 1
#define MAXMCP_FACADE_HAS_ParamBlockValueBlock 1
#define MAXMCP_FACADE_HAS_ParamBlockValueMatrix3 1
#define MAXMCP_FACADE_HAS_ParamBlockSetFloat 1
#define MAXMCP_FACADE_HAS_ParamBlockSetInt 1
#define MAXMCP_FACADE_HAS_ParamBlockSetPoint2 1
#define MAXMCP_FACADE_HAS_ParamBlockSetPoint3 1
#define MAXMCP_FACADE_HAS_ParamBlockSetPoint4 1
#define MAXMCP_FACADE_HAS_ParamBlockSetColor 1
#define MAXMCP_FACADE_HAS_ParamBlockSetAColor 1
#define MAXMCP_FACADE_HAS_ParamBlockSetString 1
#define MAXMCP_FACADE_HAS_ParamBlockSetMtl 1
#define MAXMCP_FACADE_HAS_ParamBlockSetTexmap 1
#define MAXMCP_FACADE_HAS_ParamBlockSetNode 1
#define MAXMCP_FACADE_HAS_ParamBlockSetRefTarget 1
#define MAXMCP_FACADE_HAS_ParamBlockSetBlock 1
#define MAXMCP_FACADE_HAS_ParamBlockSetMatrix3 1
#define MAXMCP_FACADE_HAS_ParamBlockResetValue 1
#define MAXMCP_FACADE_HAS_ParamBlockController 1
#define MAXMCP_FACADE_HAS_ParamBlockKeyAtTime 1
#define MAXMCP_FACADE_HAS_ParamBlockSetController 1
#define MAXMCP_FACADE_HAS_ParamBlockRemoveController 1
#define MAXMCP_FACADE_HAS_ParamBlockTabCount 1
#define MAXMCP_FACADE_HAS_ParamBlockTabSetCount 1
#define MAXMCP_FACADE_HAS_ParamBlockTabZeroCount 1
#define MAXMCP_FACADE_HAS_ParamBlockTabResize 1
#define MAXMCP_FACADE_HAS_ParamBlockTabShrink 1
#define MAXMCP_FACADE_HAS_ParamBlockTabDelete 1
#define MAXMCP_FACADE_HAS_ParamBlockTabInsertFloat 1
#define MAXMCP_FACADE_HAS_ParamBlockTabInsertInt 1
#define MAXMCP_FACADE_HAS_ParamBlockTabInsertPoint2 1
#define MAXMCP_FACADE_HAS_ParamBlockTabInsertPoint3 1
#define MAXMCP_FACADE_HAS_ParamBlockTabInsertPoint4 1
#define MAXMCP_FACADE_HAS_ParamBlockTabInsertColor 1
#define MAXMCP_FACADE_HAS_ParamBlockTabInsertAColor 1
#define MAXMCP_FACADE_HAS_ParamBlockTabInsertString 1
#define MAXMCP_FACADE_HAS_ParamBlockTabInsertMtl 1
#define MAXMCP_FACADE_HAS_ParamBlockTabInsertTexmap 1
#define MAXMCP_FACADE_HAS_ParamBlockTabInsertNode 1
#define MAXMCP_FACADE_HAS_ParamBlockTabInsertRefTarget 1
#define MAXMCP_FACADE_HAS_ParamBlockTabInsertBlock 1
#define MAXMCP_FACADE_HAS_ParamBlockTabInsertMatrix3 1
#define MAXMCP_FACADE_HAS_ParamBlockTabAppendFloat 1
#define MAXMCP_FACADE_HAS_ParamBlockTabAppendInt 1
#define MAXMCP_FACADE_HAS_ParamBlockTabAppendPoint2 1
#define MAXMCP_FACADE_HAS_ParamBlockTabAppendPoint3 1
#define MAXMCP_FACADE_HAS_ParamBlockTabAppendPoint4 1
#define MAXMCP_FACADE_HAS_ParamBlockTabAppendColor 1
#define MAXMCP_FACADE_HAS_ParamBlockTabAppendAColor 1
#define MAXMCP_FACADE_HAS_ParamBlockTabAppendString 1
#define MAXMCP_FACADE_HAS_ParamBlockTabAppendMtl 1
#define MAXMCP_FACADE_HAS_ParamBlockTabAppendTexmap 1
#define MAXMCP_FACADE_HAS_ParamBlockTabAppendNode 1
#define MAXMCP_FACADE_HAS_ParamBlockTabAppendRefTarget 1
#define MAXMCP_FACADE_HAS_ParamBlockTabAppendBlock 1
#define MAXMCP_FACADE_HAS_ParamBlockTabAppendMatrix3 1
#define MAXMCP_FACADE_HAS_DefaultControllerForParamType 1
#define MAXMCP_FACADE_HAS_NodeDerivedObject 1
#define MAXMCP_FACADE_HAS_NodeWSMDerivedObject 1
#define MAXMCP_FACADE_HAS_NodeFindBaseObject 1
#define MAXMCP_FACADE_HAS_NodeReplaceableObjectRef 1
#define MAXMCP_FACADE_HAS_DerivedObjectCreate 1
#define MAXMCP_FACADE_HAS_WSDerivedObjectCreate 1
#define MAXMCP_FACADE_HAS_NodeCreateWSMDerivedObject 1
#define MAXMCP_FACADE_HAS_DerivedObjectReference 1
#define MAXMCP_FACADE_HAS_DerivedObjectSetReference 1
#define MAXMCP_FACADE_HAS_DerivedObjectModifierCount 1
#define MAXMCP_FACADE_HAS_DerivedObjectModifier 1
#define MAXMCP_FACADE_HAS_DerivedObjectAddModifier 1
#define MAXMCP_FACADE_HAS_DerivedObjectSetModifier 1
#define MAXMCP_FACADE_HAS_DerivedObjectDeleteModifier 1
#define MAXMCP_FACADE_HAS_NodeCanAddModifier 1
#define MAXMCP_FACADE_HAS_NodeAddModifier 1
#define MAXMCP_FACADE_HAS_NodeFindModifierAt 1
#define MAXMCP_FACADE_HAS_NodeFindModifier 1
#define MAXMCP_FACADE_HAS_NodeDeleteModifier 1
#define MAXMCP_FACADE_HAS_NodeDeleteModifierAt 1
#define MAXMCP_FACADE_HAS_ModifierName 1
#define MAXMCP_FACADE_HAS_ModifierSetName 1
#define MAXMCP_FACADE_HAS_ModifierEnabled 1
#define MAXMCP_FACADE_HAS_ModifierSetEnabled 1
#define MAXMCP_FACADE_HAS_ModifierEnabledInViews 1
#define MAXMCP_FACADE_HAS_ModifierSetEnabledInViews 1
#define MAXMCP_FACADE_HAS_ModifierEnabledInRender 1
#define MAXMCP_FACADE_HAS_ModifierSetEnabledInRender 1
#define MAXMCP_FACADE_HAS_ModifierValidity 1
#define MAXMCP_FACADE_HAS_ModifierChannelsUsed 1
#define MAXMCP_FACADE_HAS_ModifierChannelsChanged 1
#define MAXMCP_FACADE_HAS_ModifierInputType 1
#define MAXMCP_FACADE_HAS_WSMObjectCreateMod 1
#define MAXMCP_FACADE_HAS_ModContextTransform 1
#define MAXMCP_FACADE_HAS_ModContextSetTransform 1
#define MAXMCP_FACADE_HAS_ModContextBox 1
#define MAXMCP_FACADE_HAS_ModContextSetBox 1
#define MAXMCP_FACADE_HAS_NodeObjectTransform 1
#define MAXMCP_FACADE_HAS_NodeObjectTransformBeforeWSM 1
#define MAXMCP_FACADE_HAS_NodeObjectTransformAfterWSM 1
#define MAXMCP_FACADE_HAS_NodeTransformValidity 1
#define MAXMCP_FACADE_HAS_NodeHasWSM 1
#define MAXMCP_FACADE_HAS_NodeObjectOffset 1
#define MAXMCP_FACADE_HAS_NodeSetObjectOffset 1
#define MAXMCP_FACADE_HAS_NodeCenterPivot 1
#define MAXMCP_FACADE_HAS_NodeAlignPivot 1
#define MAXMCP_FACADE_HAS_NodeWorldAlignPivot 1
#define MAXMCP_FACADE_HAS_NodeAlignPivotToParent 1
#define MAXMCP_FACADE_HAS_NodeAlignPivotToWorld 1
#define MAXMCP_FACADE_HAS_NodeMayResetTransform 1
#define MAXMCP_FACADE_HAS_NodeResetTransform 1
#define MAXMCP_FACADE_HAS_NodeResetPivot 1
#define MAXMCP_FACADE_HAS_ObjectValidity 1
#define MAXMCP_FACADE_HAS_ObjectChannelValidity 1
#define MAXMCP_FACADE_HAS_ObjectSetChannelValidity 1
#define MAXMCP_FACADE_HAS_ObjectUpdateValidity 1
#define MAXMCP_FACADE_HAS_ObjectInvalidateChannels 1
#define MAXMCP_FACADE_HAS_NodeInvalidateTM 1
#define MAXMCP_FACADE_HAS_NodeInvalidateTreeTM 1
#define MAXMCP_FACADE_HAS_NodeInvalidateWS 1
#define MAXMCP_FACADE_HAS_NodeInvalidateObjectCache 1
#define MAXMCP_FACADE_HAS_AnimNotifyDependents 1
#define MAXMCP_FACADE_HAS_SceneRedrawViews 1
#define MAXMCP_FACADE_HAS_SceneSuspendEditing 1
#define MAXMCP_FACADE_HAS_SceneResumeEditing 1
#define MAXMCP_FACADE_HAS_ShapePointsReadObject 1
#define MAXMCP_FACADE_HAS_NodeCreatePoly 1
#define MAXMCP_FACADE_HAS_EditPolyObjClassId 1
#define MAXMCP_FACADE_HAS_PatchObjClassId 1
#define MAXMCP_FACADE_HAS_NodeCreatePatch 1
#define MAXMCP_FACADE_HAS_NodeCanConvertTo 1
#define MAXMCP_FACADE_HAS_PolySetNumVerts 1
#define MAXMCP_FACADE_HAS_PolySetNumFaces 1
#define MAXMCP_FACADE_HAS_PolyNewVert 1
#define MAXMCP_FACADE_HAS_PolyCreateFace 1
#define MAXMCP_FACADE_HAS_PolySetMapNum 1
#define MAXMCP_FACADE_HAS_PolyVertexCount 1
#define MAXMCP_FACADE_HAS_PolyVertsRead 1
#define MAXMCP_FACADE_HAS_PolyEdgeCount 1
#define MAXMCP_FACADE_HAS_PolyEdgesRead 1
#define MAXMCP_FACADE_HAS_PolyFaceCount 1
#define MAXMCP_FACADE_HAS_PolyFacesRead 1
#define MAXMCP_FACADE_HAS_PolyFaceVertsRead 1
#define MAXMCP_FACADE_HAS_PolyFaceEdgesRead 1
#define MAXMCP_FACADE_HAS_PolyMeshFlags 1
#define MAXMCP_FACADE_HAS_PolyPartValidity 1
#define MAXMCP_FACADE_HAS_PolyMapCount 1
#define MAXMCP_FACADE_HAS_PolyMapFlags 1
#define MAXMCP_FACADE_HAS_PolyMapVertCount 1
#define MAXMCP_FACADE_HAS_PolyMapFaceCount 1
#define MAXMCP_FACADE_HAS_PolyMapVertsRead 1
#define MAXMCP_FACADE_HAS_PolyMapFacesRead 1
#define MAXMCP_FACADE_HAS_PolyMapFaceVertsRead 1
#define MAXMCP_FACADE_HAS_PolyVertsWrite 1
#define MAXMCP_FACADE_HAS_PolyFaceMakePoly 1
#define MAXMCP_FACADE_HAS_PolyFaceSetSmGroup 1
#define MAXMCP_FACADE_HAS_PolyFaceSetMaterial 1
#define MAXMCP_FACADE_HAS_PolyInvalidateTopoCache 1
#define MAXMCP_FACADE_HAS_PolyInvalidateGeomCache 1
#define MAXMCP_FACADE_HAS_PolyFillInMesh 1
#define MAXMCP_FACADE_HAS_PolyMeshSetFlag 1
#define MAXMCP_FACADE_HAS_PolyMeshClearFlag 1
#define MAXMCP_FACADE_HAS_PolySetPartValidity 1
#define MAXMCP_FACADE_HAS_PolyInitMap 1
#define MAXMCP_FACADE_HAS_PolyMapSetNumVerts 1
#define MAXMCP_FACADE_HAS_PolyMapSetNumFaces 1
#define MAXMCP_FACADE_HAS_PolyMapNewVert 1
#define MAXMCP_FACADE_HAS_PolyMapNewFace 1
#define MAXMCP_FACADE_HAS_PolyMapVertsWrite 1
#define MAXMCP_FACADE_HAS_PolyMapFaceMakePoly 1
#define MAXMCP_FACADE_HAS_PolySetEdgeVis 1
#define MAXMCP_FACADE_HAS_PolySetEdgeSel 1
#define MAXMCP_FACADE_HAS_PolySetNumEdges 1
#define MAXMCP_FACADE_HAS_PolyAppendNewEdges 1
#define MAXMCP_FACADE_HAS_PolySimpleNewEdge 1
#define MAXMCP_FACADE_HAS_PolyNewEdge 1
#define MAXMCP_FACADE_HAS_PolyRegisterEdge 1
#define MAXMCP_FACADE_HAS_PolySetFlag 1
#define MAXMCP_FACADE_HAS_PolyClearFlag 1
#define MAXMCP_FACADE_HAS_PolyDeleteFlaggedFaces 1
#define MAXMCP_FACADE_HAS_PolyCollapseDeadVerts 1
#define MAXMCP_FACADE_HAS_PolyCollapseDeadEdges 1
#define MAXMCP_FACADE_HAS_PolyCollapseDeadFaces 1
#define MAXMCP_FACADE_HAS_PolyCollapseDeadStructs 1
#define MAXMCP_FACADE_HAS_PolyRemoveVertex 1
#define MAXMCP_FACADE_HAS_PolyRemoveVertices 1
#define MAXMCP_FACADE_HAS_PolyRemoveEdge 1
#define MAXMCP_FACADE_HAS_PolyRemoveSpur 1
#define MAXMCP_FACADE_HAS_PolyFreeVerts 1
#define MAXMCP_FACADE_HAS_PolyFreeEdges 1
#define MAXMCP_FACADE_HAS_PolyFreeFaces 1
#define MAXMCP_FACADE_HAS_PolyClear 1
#define MAXMCP_FACADE_HAS_PolyClearAndFree 1
#define MAXMCP_FACADE_HAS_PolyMapClear 1
#define MAXMCP_FACADE_HAS_PolyMapClearAndFree 1
#define MAXMCP_FACADE_HAS_PolyClearMap 1
#define MAXMCP_FACADE_HAS_PolyFreeMap 1
#define MAXMCP_FACADE_HAS_PolyFreeMaps 1
#define MAXMCP_FACADE_HAS_PolyMapCollapseDeadVerts 1
#define MAXMCP_FACADE_HAS_PolyMapCollapseDeadFaces 1
#define MAXMCP_FACADE_HAS_PolyBorderLoopCount 1
#define MAXMCP_FACADE_HAS_PolyBorderLoopRead 1
#define MAXMCP_FACADE_HAS_PolyExtrudeFaces 1
#define MAXMCP_FACADE_HAS_PolySlice 1
#define MAXMCP_FACADE_HAS_PolyMultiDivideEdge 1
#define MAXMCP_FACADE_HAS_PolySplitTriEdge 1
#define MAXMCP_FACADE_HAS_PolyDivideFace 1
#define MAXMCP_FACADE_HAS_PolyTessellateByEdges 1
#define MAXMCP_FACADE_HAS_PolyTessellateByCenters 1
#define MAXMCP_FACADE_HAS_PolyElementFromFace 1
#define MAXMCP_FACADE_HAS_PolyBorderFromEdge 1
#define MAXMCP_FACADE_HAS_PolyCloneFaces 1
#define MAXMCP_FACADE_HAS_PolyWeldVerts 1
#define MAXMCP_FACADE_HAS_PolyWeldEdge 1
#define MAXMCP_FACADE_HAS_PolyFlipNormal 1
#define MAXMCP_FACADE_HAS_PolyAutoSmooth 1
#define MAXMCP_FACADE_HAS_PolyVDataCount 1
#define MAXMCP_FACADE_HAS_PolyVDataSupported 1
#define MAXMCP_FACADE_HAS_PolySetVDataSupport 1
#define MAXMCP_FACADE_HAS_PolyVDataRead 1
#define MAXMCP_FACADE_HAS_PolyVDataWrite 1
#define MAXMCP_FACADE_HAS_PolyFreeVData 1
#define MAXMCP_FACADE_HAS_PolyFreeAllVData 1
#define MAXMCP_FACADE_HAS_PolyEDataCount 1
#define MAXMCP_FACADE_HAS_PolyEDataSupported 1
#define MAXMCP_FACADE_HAS_PolySetEDataSupport 1
#define MAXMCP_FACADE_HAS_PolyEDataRead 1
#define MAXMCP_FACADE_HAS_PolyEDataWrite 1
#define MAXMCP_FACADE_HAS_PolyFreeEData 1
#define MAXMCP_FACADE_HAS_PolyFreeAllEData 1
#define MAXMCP_FACADE_HAS_PatchSetNumVerts 1
#define MAXMCP_FACADE_HAS_PatchSetNumVecs 1
#define MAXMCP_FACADE_HAS_PatchSetNumPatches 1
#define MAXMCP_FACADE_HAS_PatchSetNumEdges 1
#define MAXMCP_FACADE_HAS_PatchMakeQuad 1
#define MAXMCP_FACADE_HAS_PatchMakeTri 1
#define MAXMCP_FACADE_HAS_PatchBuildLinkages 1
#define MAXMCP_FACADE_HAS_PatchComputeInteriors 1
#define MAXMCP_FACADE_HAS_PatchComputeAux 1
#define MAXMCP_FACADE_HAS_PatchVertexCount 1
#define MAXMCP_FACADE_HAS_PatchVecCount 1
#define MAXMCP_FACADE_HAS_PatchCount 1
#define MAXMCP_FACADE_HAS_PatchEdgeCount 1
#define MAXMCP_FACADE_HAS_PatchVertsRead 1
#define MAXMCP_FACADE_HAS_PatchVecsRead 1
#define MAXMCP_FACADE_HAS_PatchesRead 1
#define MAXMCP_FACADE_HAS_PatchesWrite 1
#define MAXMCP_FACADE_HAS_PatchEdgesRead 1
#define MAXMCP_FACADE_HAS_PatchVertVectorsRead 1
#define MAXMCP_FACADE_HAS_PatchVertPatchesRead 1
#define MAXMCP_FACADE_HAS_PatchVertEdgesRead 1
#define MAXMCP_FACADE_HAS_PatchVecPatchesRead 1
#define MAXMCP_FACADE_HAS_PatchEdgePatchesRead 1
#define MAXMCP_FACADE_HAS_PatchVertsWrite 1
#define MAXMCP_FACADE_HAS_PatchVecsWrite 1
#define MAXMCP_FACADE_HAS_PatchSetSmGroup 1
#define MAXMCP_FACADE_HAS_PatchSetFlags 1
#define MAXMCP_FACADE_HAS_PatchMatIdRead 1
#define MAXMCP_FACADE_HAS_PatchMatIdWrite 1
#define MAXMCP_FACADE_HAS_PatchViewTessRead 1
#define MAXMCP_FACADE_HAS_PatchViewTessWrite 1
#define MAXMCP_FACADE_HAS_PatchProdTessRead 1
#define MAXMCP_FACADE_HAS_PatchProdTessWrite 1
#define MAXMCP_FACADE_HAS_PatchDispTessRead 1
#define MAXMCP_FACADE_HAS_PatchDispTessWrite 1
#define MAXMCP_FACADE_HAS_PatchTessFlagsRead 1
#define MAXMCP_FACADE_HAS_PatchTessFlagsWrite 1
#define MAXMCP_FACADE_HAS_PatchSurfaceRead 1
#define MAXMCP_FACADE_HAS_PatchSurfaceWrite 1
#define MAXMCP_FACADE_HAS_PatchInvalidateGeomCache 1
#define MAXMCP_FACADE_HAS_PatchInvalidateMesh 1
#define MAXMCP_FACADE_HAS_PatchMapCount 1
#define MAXMCP_FACADE_HAS_PatchMapChannelCount 1
#define MAXMCP_FACADE_HAS_PatchSetNumMaps 1
#define MAXMCP_FACADE_HAS_PatchMapSupport 1
#define MAXMCP_FACADE_HAS_PatchSetMapSupport 1
#define MAXMCP_FACADE_HAS_PatchMapVertCount 1
#define MAXMCP_FACADE_HAS_PatchSetNumMapVerts 1
#define MAXMCP_FACADE_HAS_PatchSetNumMapPatches 1
#define MAXMCP_FACADE_HAS_PatchMapVertsRead 1
#define MAXMCP_FACADE_HAS_PatchMapVertsWrite 1
#define MAXMCP_FACADE_HAS_PatchMapPatchesRead 1
#define MAXMCP_FACADE_HAS_PatchMapPatchesWrite 1
#define MAXMCP_FACADE_HAS_PatchDeleteParts 1
#define MAXMCP_FACADE_HAS_ShapeKnotCount 1
#define MAXMCP_FACADE_HAS_ShapeKnotRead 1
#define MAXMCP_FACADE_HAS_ShapeSplineClosed 1
#define MAXMCP_FACADE_HAS_ShapeSegCount 1
#define MAXMCP_FACADE_HAS_ShapeSegMatId 1
#define MAXMCP_FACADE_HAS_ShapeBezierSplineCount 1
#define MAXMCP_FACADE_HAS_ShapeBezierKnotCount 1
#define MAXMCP_FACADE_HAS_ShapeBezierKnotRead 1
#define MAXMCP_FACADE_HAS_ShapeBezierSplineClosed 1
#define MAXMCP_FACADE_HAS_ShapeSplineAppend 1
#define MAXMCP_FACADE_HAS_ShapeSplineInsert 1
#define MAXMCP_FACADE_HAS_ShapeKnotAdd 1
#define MAXMCP_FACADE_HAS_ShapeKnotWrite 1
#define MAXMCP_FACADE_HAS_ShapeKnotFlagsWrite 1
#define MAXMCP_FACADE_HAS_ShapeSetKnotType 1
#define MAXMCP_FACADE_HAS_ShapeSetLineType 1
#define MAXMCP_FACADE_HAS_ShapeSplineInitialKnotType 1
#define MAXMCP_FACADE_HAS_ShapeSplineDragKnotType 1
#define MAXMCP_FACADE_HAS_ShapeSetSplineClosed 1
#define MAXMCP_FACADE_HAS_ShapeSetSegMatId 1
#define MAXMCP_FACADE_HAS_ShapeComputeBezPoints 1
#define MAXMCP_FACADE_HAS_ShapeKnotDelete 1
#define MAXMCP_FACADE_HAS_ShapeCurveCount 1
#define MAXMCP_FACADE_HAS_ShapeCurveClosed 1
#define MAXMCP_FACADE_HAS_ShapeCurveInterp 1
#define MAXMCP_FACADE_HAS_ShapeCurveTangent 1
#define MAXMCP_FACADE_HAS_ShapeCurveLength 1
#define MAXMCP_FACADE_HAS_ShapePieceCount 1
#define MAXMCP_FACADE_HAS_ShapePieceInterp 1
#define MAXMCP_FACADE_HAS_ShapePieceTangent 1
#define MAXMCP_FACADE_HAS_ShapePieceMatId 1
#define MAXMCP_FACADE_HAS_ShapeCanMakeBezier 1
#define MAXMCP_FACADE_HAS_ShapeRenderRead 1
#define MAXMCP_FACADE_HAS_ShapeRenderWrite 1
#define MAXMCP_FACADE_HAS_CombineMeshesTM 1
#define MAXMCP_FACADE_HAS_MeshSpecifyNormals 1
#define MAXMCP_FACADE_HAS_MeshSpecifiedNormalsPresent 1
#define MAXMCP_FACADE_HAS_MeshClearSpecifiedNormals 1
#define MAXMCP_FACADE_HAS_NormalSpecFaceCount 1
#define MAXMCP_FACADE_HAS_NormalSpecSetFaceCount 1
#define MAXMCP_FACADE_HAS_NormalSpecNormalCount 1
#define MAXMCP_FACADE_HAS_NormalSpecSetNormalCount 1
#define MAXMCP_FACADE_HAS_NormalSpecClear 1
#define MAXMCP_FACADE_HAS_NormalSpecClearAndFree 1
#define MAXMCP_FACADE_HAS_NormalSpecClearNormals 1
#define MAXMCP_FACADE_HAS_NormalSpecNewNormal 1
#define MAXMCP_FACADE_HAS_NormalSpecNormalsRead 1
#define MAXMCP_FACADE_HAS_NormalSpecNormalsWrite 1
#define MAXMCP_FACADE_HAS_NormalSpecNormalRead 1
#define MAXMCP_FACADE_HAS_NormalSpecNormalWrite 1
#define MAXMCP_FACADE_HAS_NormalSpecExplicitRead 1
#define MAXMCP_FACADE_HAS_NormalSpecExplicitWrite 1
#define MAXMCP_FACADE_HAS_NormalSpecAllExplicitWrite 1
#define MAXMCP_FACADE_HAS_NormalSpecAnyExplicit 1
#define MAXMCP_FACADE_HAS_NormalSpecMakeExplicit 1
#define MAXMCP_FACADE_HAS_NormalSpecFacesRead 1
#define MAXMCP_FACADE_HAS_NormalSpecFacesWrite 1
#define MAXMCP_FACADE_HAS_NormalSpecFaceNormalRead 1
#define MAXMCP_FACADE_HAS_NormalSpecFaceNormalWrite 1
#define MAXMCP_FACADE_HAS_NormalSpecFaceIndexRead 1
#define MAXMCP_FACADE_HAS_NormalSpecFaceIndexWrite 1
#define MAXMCP_FACADE_HAS_NormalSpecFaceCornerSpecifiedRead 1
#define MAXMCP_FACADE_HAS_NormalSpecFaceCornerSpecifiedWrite 1
#define MAXMCP_FACADE_HAS_NormalSpecFaceClear 1
#define MAXMCP_FACADE_HAS_NormalSpecSelectionRead 1
#define MAXMCP_FACADE_HAS_NormalSpecSelectionWrite 1
#define MAXMCP_FACADE_HAS_NormalSpecFlagRead 1
#define MAXMCP_FACADE_HAS_NormalSpecFlagWrite 1
#define MAXMCP_FACADE_HAS_NormalSpecDisplayLengthRead 1
#define MAXMCP_FACADE_HAS_NormalSpecDisplayLengthWrite 1
#define MAXMCP_FACADE_HAS_NormalSpecBuildNormals 1
#define MAXMCP_FACADE_HAS_NormalSpecComputeNormals 1
#define MAXMCP_FACADE_HAS_NormalSpecCheckNormals 1
#define MAXMCP_FACADE_HAS_MeshVDataChannelCount 1
#define MAXMCP_FACADE_HAS_MeshSetVDataChannelCount 1
#define MAXMCP_FACADE_HAS_MeshVDataSupported 1
#define MAXMCP_FACADE_HAS_MeshSetVDataSupport 1
#define MAXMCP_FACADE_HAS_MeshVDataType 1
#define MAXMCP_FACADE_HAS_VertexDataChannelType 1
#define MAXMCP_FACADE_HAS_MeshVDataElementCount 1
#define MAXMCP_FACADE_HAS_MeshSetVDataElementCount 1
#define MAXMCP_FACADE_HAS_MeshVDataRead 1
#define MAXMCP_FACADE_HAS_MeshVDataWrite 1
#define MAXMCP_FACADE_HAS_MeshFreeVData 1
#define MAXMCP_FACADE_HAS_MeshFreeAllVData 1
#define MAXMCP_FACADE_HAS_MeshVertHideRead 1
#define MAXMCP_FACADE_HAS_MeshVertHideWrite 1
#define MAXMCP_FACADE_HAS_ObjectSupportsNamedSubSels 1
#define MAXMCP_FACADE_HAS_ObjectNamedSelSetCount 1
#define MAXMCP_FACADE_HAS_ObjectNamedSelSetName 1
#define MAXMCP_FACADE_HAS_ObjectSetNamedSelSetName 1
#define MAXMCP_FACADE_HAS_ObjectNewSetFromCurSel 1
#define MAXMCP_FACADE_HAS_ObjectNewSetByOperator 1
#define MAXMCP_FACADE_HAS_ObjectActivateSubSelSet 1
#define MAXMCP_FACADE_HAS_ObjectRemoveSubSelSet 1
#define MAXMCP_FACADE_HAS_SceneNamedSelSetListChanged 1
#define MAXMCP_FACADE_HAS_ObjectSubObjTypeCount 1
#define MAXMCP_FACADE_HAS_ObjectSubObjTypeName 1
#define MAXMCP_FACADE_HAS_ObjectSubObjectLevel 1
#define MAXMCP_FACADE_HAS_PanelTaskMode 1
#define MAXMCP_FACADE_HAS_PanelSetTaskMode 1
#define MAXMCP_FACADE_HAS_PanelSubObjectLevel 1
#define MAXMCP_FACADE_HAS_PanelSubObjectLevelCount 1
#define MAXMCP_FACADE_HAS_PanelSetSubObjectLevel 1
#define MAXMCP_FACADE_HAS_MeshSelectModLevelRead 1
#define MAXMCP_FACADE_HAS_MeshSelectModLevelWrite 1
#define MAXMCP_FACADE_HAS_MeshSelectModDataChanged 1
#define MAXMCP_FACADE_HAS_MeshSelectVertSelRead 1
#define MAXMCP_FACADE_HAS_MeshSelectFaceSelRead 1
#define MAXMCP_FACADE_HAS_MeshSelectEdgeSelRead 1
#define MAXMCP_FACADE_HAS_MeshSelectVertSelWrite 1
#define MAXMCP_FACADE_HAS_MeshSelectFaceSelWrite 1
#define MAXMCP_FACADE_HAS_MeshSelectEdgeSelWrite 1
#define MAXMCP_FACADE_HAS_MeshSelectHasWeights 1
#define MAXMCP_FACADE_HAS_MeshSelectCanAssignWeights 1
#define MAXMCP_FACADE_HAS_MeshSelectWeightsRead 1
#define MAXMCP_FACADE_HAS_MeshSelectWeightsWrite 1
#define MAXMCP_FACADE_HAS_MeshSelectNamedSetCount 1
#define MAXMCP_FACADE_HAS_MeshSelectNamedSetName 1
#define MAXMCP_FACADE_HAS_MeshSelectNamedSetId 1
#define MAXMCP_FACADE_HAS_MeshSelectNamedSetBitsRead 1
#define MAXMCP_FACADE_HAS_MeshSelectNamedSetAppend 1
#define MAXMCP_FACADE_HAS_MeshSelectNamedSetBitsWrite 1
#define MAXMCP_FACADE_HAS_MeshSelectNamedSetRename 1
#define MAXMCP_FACADE_HAS_MeshSelectNamedSetDelete 1
#define MAXMCP_FACADE_HAS_MeshSelectNamedSetsResize 1
#define MAXMCP_FACADE_HAS_SplineSelectModLevelRead 1
#define MAXMCP_FACADE_HAS_SplineSelectModLevelWrite 1
#define MAXMCP_FACADE_HAS_SplineSelectModDataChanged 1
#define MAXMCP_FACADE_HAS_SplineSelectVertSelRead 1
#define MAXMCP_FACADE_HAS_SplineSelectSegmentSelRead 1
#define MAXMCP_FACADE_HAS_SplineSelectSplineSelRead 1
#define MAXMCP_FACADE_HAS_SplineSelectVertSelWrite 1
#define MAXMCP_FACADE_HAS_SplineSelectSegmentSelWrite 1
#define MAXMCP_FACADE_HAS_SplineSelectSplineSelWrite 1
#define MAXMCP_FACADE_HAS_SplineSelectNamedSetCount 1
#define MAXMCP_FACADE_HAS_SplineSelectNamedSetName 1
#define MAXMCP_FACADE_HAS_SplineSelectNamedSetId 1
#define MAXMCP_FACADE_HAS_SplineSelectNamedSetBitsRead 1
#define MAXMCP_FACADE_HAS_SplineSelectNamedSetAppend 1
#define MAXMCP_FACADE_HAS_SplineSelectNamedSetBitsWrite 1
#define MAXMCP_FACADE_HAS_SplineSelectNamedSetRename 1
#define MAXMCP_FACADE_HAS_SplineSelectNamedSetDelete 1
#define MAXMCP_FACADE_HAS_SplineSelectNamedSetsResize 1
#define MAXMCP_FACADE_HAS_NodeDisposeTemporary 1
#define MAXMCP_FACADE_HAS_NodeInvalidateRect 1
#define MAXMCP_FACADE_HAS_NodeDetach 1
#define MAXMCP_FACADE_HAS_NodeNumberOfChildren 1
#define MAXMCP_FACADE_HAS_NodeHide 1
#define MAXMCP_FACADE_HAS_NodeIsHidden 1
#define MAXMCP_FACADE_HAS_NodeIsNodeHidden 1
#define MAXMCP_FACADE_HAS_NodeIsFrozen 1
#define MAXMCP_FACADE_HAS_NodeFreeze 1
#define MAXMCP_FACADE_HAS_NodeSetShowFrozenWithMtl 1
#define MAXMCP_FACADE_HAS_NodeShowFrozenWithMtl 1
#define MAXMCP_FACADE_HAS_NodeXRayMtl 1
#define MAXMCP_FACADE_HAS_NodeHasXRayMtl 1
#define MAXMCP_FACADE_HAS_NodeBoxMode 1
#define MAXMCP_FACADE_HAS_NodeGetBoxMode 1
#define MAXMCP_FACADE_HAS_NodeAllEdges 1
#define MAXMCP_FACADE_HAS_NodeGetAllEdges 1
#define MAXMCP_FACADE_HAS_NodeVertTicks 1
#define MAXMCP_FACADE_HAS_NodeGetVertTicks 1
#define MAXMCP_FACADE_HAS_NodeBackCull 1
#define MAXMCP_FACADE_HAS_NodeGetBackCull 1
#define MAXMCP_FACADE_HAS_NodeUnhideObjectAndLayer 1
#define MAXMCP_FACADE_HAS_NodeIsObjectHidden 1
#define MAXMCP_FACADE_HAS_NodeUnfreezeObjectAndLayer 1
#define MAXMCP_FACADE_HAS_NodeIsObjectFrozen 1
#define MAXMCP_FACADE_HAS_NodeHasObjectXRayMtl 1
#define MAXMCP_FACADE_HAS_NodeIgnoreExtents 1
#define MAXMCP_FACADE_HAS_NodeGetIgnoreExtents 1
#define MAXMCP_FACADE_HAS_NodeSetCastShadows 1
#define MAXMCP_FACADE_HAS_NodeCastShadows 1
#define MAXMCP_FACADE_HAS_NodeSetRcvShadows 1
#define MAXMCP_FACADE_HAS_NodeRcvShadows 1
#define MAXMCP_FACADE_HAS_NodeSetMotBlur 1
#define MAXMCP_FACADE_HAS_NodeMotBlur 1
#define MAXMCP_FACADE_HAS_NodeGetImageBlurMultiplier 1
#define MAXMCP_FACADE_HAS_NodeSetImageBlurMultiplier 1
#define MAXMCP_FACADE_HAS_NodeGetMotBlurOnOff 1
#define MAXMCP_FACADE_HAS_NodeSetMotBlurOnOff 1
#define MAXMCP_FACADE_HAS_NodeSetRenderable 1
#define MAXMCP_FACADE_HAS_NodeRenderable 1
#define MAXMCP_FACADE_HAS_NodeSetApplyAtmospherics 1
#define MAXMCP_FACADE_HAS_NodeApplyAtmospherics 1
#define MAXMCP_FACADE_HAS_NodeSetPrimaryVisibility 1
#define MAXMCP_FACADE_HAS_NodeGetPrimaryVisibility 1
#define MAXMCP_FACADE_HAS_NodeSetSecondaryVisibility 1
#define MAXMCP_FACADE_HAS_NodeGetSecondaryVisibility 1
#define MAXMCP_FACADE_HAS_NodeSetGenerateCaustics 1
#define MAXMCP_FACADE_HAS_NodeGenerateCaustics 1
#define MAXMCP_FACADE_HAS_NodeSetRcvCaustics 1
#define MAXMCP_FACADE_HAS_NodeRcvCaustics 1
#define MAXMCP_FACADE_HAS_NodeSetGenerateGlobalIllum 1
#define MAXMCP_FACADE_HAS_NodeGenerateGlobalIllum 1
#define MAXMCP_FACADE_HAS_NodeSetRcvGlobalIllum 1
#define MAXMCP_FACADE_HAS_NodeRcvGlobalIllum 1
#define MAXMCP_FACADE_HAS_NodeSetCVertMode 1
#define MAXMCP_FACADE_HAS_NodeGetCVertMode 1
#define MAXMCP_FACADE_HAS_NodeSetShadeCVerts 1
#define MAXMCP_FACADE_HAS_NodeGetShadeCVerts 1
#define MAXMCP_FACADE_HAS_NodeGetVertexColorType 1
#define MAXMCP_FACADE_HAS_NodeSetVertexColorType 1
#define MAXMCP_FACADE_HAS_NodeGetVertexColorMapChannel 1
#define MAXMCP_FACADE_HAS_NodeSetVertexColorMapChannel 1
#define MAXMCP_FACADE_HAS_NodeGetTrajectoryON 1
#define MAXMCP_FACADE_HAS_NodeSetTrajectoryON 1
#define MAXMCP_FACADE_HAS_NodeShowBone 1
#define MAXMCP_FACADE_HAS_NodeBoneAsLine 1
#define MAXMCP_FACADE_HAS_NodeIsBoneShowing 1
#define MAXMCP_FACADE_HAS_NodeIsBoneOnly 1
#define MAXMCP_FACADE_HAS_NodeSetTargetNodePair 1
#define MAXMCP_FACADE_HAS_NodeGetTargetNodePair 1
#define MAXMCP_FACADE_HAS_NodeGetWireColor 1
#define MAXMCP_FACADE_HAS_NodeDependent 1
#define MAXMCP_FACADE_HAS_NodeIsRootNode 1
#define MAXMCP_FACADE_HAS_NodeGetTransformLock 1
#define MAXMCP_FACADE_HAS_NodeSetTransformLock 1
#define MAXMCP_FACADE_HAS_NodeIsTarget 1
#define MAXMCP_FACADE_HAS_NodeSetIsTarget 1
#define MAXMCP_FACADE_HAS_NodeSetVisibility 1
#define MAXMCP_FACADE_HAS_NodeGetInheritVisibility 1
#define MAXMCP_FACADE_HAS_NodeSetInheritVisibility 1
#define MAXMCP_FACADE_HAS_NodeSetRenderOccluded 1
#define MAXMCP_FACADE_HAS_NodeGetRenderOccluded 1
#define MAXMCP_FACADE_HAS_NodeNumMtls 1
#define MAXMCP_FACADE_HAS_NodeAlignToParent 1
#define MAXMCP_FACADE_HAS_NodeAlignToWorld 1
#define MAXMCP_FACADE_HAS_NodeFlagForeground 1
#define MAXMCP_FACADE_HAS_NodeIsActiveGrid 1
#define MAXMCP_FACADE_HAS_NodeGetGBufID 1
#define MAXMCP_FACADE_HAS_NodeSetGBufID 1
#define MAXMCP_FACADE_HAS_NodeGetRenderID 1
#define MAXMCP_FACADE_HAS_NodeSetRenderID 1
#define MAXMCP_FACADE_HAS_NodeGetHandle 1
#define MAXMCP_FACADE_HAS_NodeIsGroupMember 1
#define MAXMCP_FACADE_HAS_NodeIsOpenGroupMember 1
#define MAXMCP_FACADE_HAS_NodeIsOpenGroupHead 1
#define MAXMCP_FACADE_HAS_NodeSetGroupMember 1
#define MAXMCP_FACADE_HAS_NodeSetGroupHead 1
#define MAXMCP_FACADE_HAS_NodeSetGroupMemberOpen 1
#define MAXMCP_FACADE_HAS_NodeSetGroupHeadOpen 1
#define MAXMCP_FACADE_HAS_NodeGetPosTaskWeight 1
#define MAXMCP_FACADE_HAS_NodeGetRotTaskWeight 1
#define MAXMCP_FACADE_HAS_NodeSetPosTaskWeight 1
#define MAXMCP_FACADE_HAS_NodeSetRotTaskWeight 1
#define MAXMCP_FACADE_HAS_NodeGetTaskAxisState 1
#define MAXMCP_FACADE_HAS_NodeSetTaskAxisState 1
#define MAXMCP_FACADE_HAS_NodeGetTaskAxisStateBits 1
#define MAXMCP_FACADE_HAS_NodeGetXRefFileCount 1
#define MAXMCP_FACADE_HAS_NodeDeleteXRefFile 1
#define MAXMCP_FACADE_HAS_NodeBindXRefFile 1
#define MAXMCP_FACADE_HAS_NodeDeleteAllXRefs 1
#define MAXMCP_FACADE_HAS_NodeReloadXRef 1
#define MAXMCP_FACADE_HAS_NodeFlagXrefChanged 1
#define MAXMCP_FACADE_HAS_NodeUpdateChangedXRefs 1
#define MAXMCP_FACADE_HAS_NodeAttemptToResolveUnresolvedXRefs 1
#define MAXMCP_FACADE_HAS_NodeGetXRefFlags 1
#define MAXMCP_FACADE_HAS_NodeSetXRefFlags 1
#define MAXMCP_FACADE_HAS_NodeIsSceneXRefNode 1
#define MAXMCP_FACADE_HAS_NodeIsSceneNode 1
#define MAXMCP_FACADE_HAS_NodeSetBoneNodeOnOff 1
#define MAXMCP_FACADE_HAS_NodeSetBoneAutoAlign 1
#define MAXMCP_FACADE_HAS_NodeSetBoneFreezeLen 1
#define MAXMCP_FACADE_HAS_NodeSetBoneScaleType 1
#define MAXMCP_FACADE_HAS_NodeSetBoneAxis 1
#define MAXMCP_FACADE_HAS_NodeSetBoneAxisFlip 1
#define MAXMCP_FACADE_HAS_NodeGetBoneNodeOnOff 1
#define MAXMCP_FACADE_HAS_NodeGetBoneNodeOnOff_T 1
#define MAXMCP_FACADE_HAS_NodeGetBoneAutoAlign 1
#define MAXMCP_FACADE_HAS_NodeGetBoneFreezeLen 1
#define MAXMCP_FACADE_HAS_NodeGetBoneScaleType 1
#define MAXMCP_FACADE_HAS_NodeGetBoneAxis 1
#define MAXMCP_FACADE_HAS_NodeGetBoneAxisFlip 1
#define MAXMCP_FACADE_HAS_NodeRealignBoneToChild 1
#define MAXMCP_FACADE_HAS_NodeResetBoneStretch 1
#define MAXMCP_FACADE_HAS_NodeWasLoadedByLastMerge 1
#define MAXMCP_FACADE_HAS_ControllerNumKeys 1
#define MAXMCP_FACADE_HAS_ControllerKeyTime 1
#define MAXMCP_FACADE_HAS_ControllerKeyIndexAtTime 1
#define MAXMCP_FACADE_HAS_ControllerIsKeyAtTime 1
#define MAXMCP_FACADE_HAS_ControllerKeyTimes 1
#define MAXMCP_FACADE_HAS_ControllerKeySelState 1
#define MAXMCP_FACADE_HAS_ControllerKeySelected 1
#define MAXMCP_FACADE_HAS_ControllerNumSelKeys 1
#define MAXMCP_FACADE_HAS_ControllerFlaggedKeyIndex 1
#define MAXMCP_FACADE_HAS_ControllerSupportsTimeOperations 1
#define MAXMCP_FACADE_HAS_ControllerGetORT 1
#define MAXMCP_FACADE_HAS_ControllerORTsEnabled 1
#define MAXMCP_FACADE_HAS_AnimLocked 1
#define MAXMCP_FACADE_HAS_AnimLockIsComponent 1
#define MAXMCP_FACADE_HAS_AnimLockable 1
#define MAXMCP_FACADE_HAS_AnimSubAnimLocked 1
#define MAXMCP_FACADE_HAS_AnimSubAnimLockable 1
#define MAXMCP_FACADE_HAS_SceneUnlockOverride 1
#define MAXMCP_FACADE_HAS_AnimOverrideUnlocked 1
#define MAXMCP_FACADE_HAS_SceneUberUnlockDepth 1
#define MAXMCP_FACADE_HAS_SceneAnimateState 1
#define MAXMCP_FACADE_HAS_SceneAnimatingAt 1
#define MAXMCP_FACADE_HAS_SceneKeyingAt 1
#define MAXMCP_FACADE_HAS_SceneKeyModeState 1
#define MAXMCP_FACADE_HAS_SceneKeyModeSuspended 1
#define MAXMCP_FACADE_HAS_ControllerKeyAdd 1
#define MAXMCP_FACADE_HAS_ControllerInsertTime 1
#define MAXMCP_FACADE_HAS_ControllerKeyCopyFromTime 1
#define MAXMCP_FACADE_HAS_ControllerKeySelect 1
#define MAXMCP_FACADE_HAS_ControllerEditTimeRange 1
#define MAXMCP_FACADE_HAS_ControllerReverseTime 1
#define MAXMCP_FACADE_HAS_ControllerScaleTime 1
#define MAXMCP_FACADE_HAS_ControllerSetORT 1
#define MAXMCP_FACADE_HAS_ControllerEnableORTs 1
#define MAXMCP_FACADE_HAS_AnimSetLocked 1
#define MAXMCP_FACADE_HAS_AnimSubAnimSetLocked 1
#define MAXMCP_FACADE_HAS_SceneSetUnlockOverride 1
#define MAXMCP_FACADE_HAS_SceneUberUnlockPush 1
#define MAXMCP_FACADE_HAS_SceneUberUnlockPop 1
#define MAXMCP_FACADE_HAS_SceneAnimateOn 1
#define MAXMCP_FACADE_HAS_SceneAnimateOff 1
#define MAXMCP_FACADE_HAS_SceneAnimateSuspend 1
#define MAXMCP_FACADE_HAS_SceneAnimateResume 1
#define MAXMCP_FACADE_HAS_SceneSetKeyMode 1
#define MAXMCP_FACADE_HAS_SceneKeyModeSuspend 1
#define MAXMCP_FACADE_HAS_SceneKeyModeResume 1
#define MAXMCP_FACADE_HAS_ControllerKeyDeleteAtTime 1
#define MAXMCP_FACADE_HAS_ControllerKeyDeleteByIndex 1
#define MAXMCP_FACADE_HAS_ControllerKeysDelete 1
#define MAXMCP_FACADE_HAS_ControllerDeleteTime 1
#define MAXMCP_FACADE_HAS_ControllerValueQuat 1
#define MAXMCP_FACADE_HAS_ControllerValueScale 1
#define MAXMCP_FACADE_HAS_ControllerValuePoint4 1
#define MAXMCP_FACADE_HAS_ControllerValueMatrix3 1
#define MAXMCP_FACADE_HAS_ControllerSetValueFloat 1
#define MAXMCP_FACADE_HAS_ControllerSetValuePoint3 1
#define MAXMCP_FACADE_HAS_ControllerSetValuePoint4 1
#define MAXMCP_FACADE_HAS_ControllerSetValueQuat 1
#define MAXMCP_FACADE_HAS_ControllerSetValueAngAxis 1
#define MAXMCP_FACADE_HAS_ControllerSetValueScale 1
#define MAXMCP_FACADE_HAS_ControllerSetValueXForm 1
#define MAXMCP_FACADE_HAS_ControllerCommitValue 1
#define MAXMCP_FACADE_HAS_ControllerRestoreValue 1
#define MAXMCP_FACADE_HAS_ControllerNumMorphTargets 1
#define MAXMCP_FACADE_HAS_ControllerMorphTarget 1
#define MAXMCP_FACADE_HAS_ControllerMorphTargetName 1
#define MAXMCP_FACADE_HAS_ControllerMorphTargetTM 1
#define MAXMCP_FACADE_HAS_ControllerMorphTargetValid 1
#define MAXMCP_FACADE_HAS_ControllerMorphFlaggedTarget 1
#define MAXMCP_FACADE_HAS_ControllerMorphTargetAdd 1
#define MAXMCP_FACADE_HAS_ControllerSetMorphTargetName 1
#define MAXMCP_FACADE_HAS_ControllerMorphTargetDelete 1
#define MAXMCP_FACADE_HAS_SkinBoneCount 1
#define MAXMCP_FACADE_HAS_SkinBone 1
#define MAXMCP_FACADE_HAS_SkinBoneProperty 1
#define MAXMCP_FACADE_HAS_SkinBoneFlatCount 1
#define MAXMCP_FACADE_HAS_SkinBoneFlat 1
#define MAXMCP_FACADE_HAS_SkinBoneName 1
#define MAXMCP_FACADE_HAS_SkinSelectedBone 1
#define MAXMCP_FACADE_HAS_SkinBoneEndPoints 1
#define MAXMCP_FACADE_HAS_SkinBoneTm 1
#define MAXMCP_FACADE_HAS_SkinBoneInitTm 1
#define MAXMCP_FACADE_HAS_SkinInitTm 1
#define MAXMCP_FACADE_HAS_SkinRefFrame 1
#define MAXMCP_FACADE_HAS_SkinDQBlending 1
#define MAXMCP_FACADE_HAS_SkinSetDQBlending 1
#define MAXMCP_FACADE_HAS_SkinBoneStretchTm 1
#define MAXMCP_FACADE_HAS_SkinSetBoneStretchTm 1
#define MAXMCP_FACADE_HAS_SkinVertexSelectionRead 1
#define MAXMCP_FACADE_HAS_SkinVertexSelectionWrite 1
#define MAXMCP_FACADE_HAS_SkinPointCount 1
#define MAXMCP_FACADE_HAS_SkinVertexBoneCount 1
#define MAXMCP_FACADE_HAS_SkinVertexBones 1
#define MAXMCP_FACADE_HAS_SkinVertexWeights 1
#define MAXMCP_FACADE_HAS_SkinVertexSpline 1
#define MAXMCP_FACADE_HAS_SkinVertexDQBlendWeight 1
#define MAXMCP_FACADE_HAS_SkinSetVertexDQBlendWeight 1
#define MAXMCP_FACADE_HAS_SkinAddBone 1
#define MAXMCP_FACADE_HAS_SkinSetSkinTm 1
#define MAXMCP_FACADE_HAS_SkinSetBoneTm 1
#define MAXMCP_FACADE_HAS_SkinSetVertexWeights 1
#define MAXMCP_FACADE_HAS_MorphChannelCount 1
#define MAXMCP_FACADE_HAS_MorphSetChannelCount 1
#define MAXMCP_FACADE_HAS_MorphChannelActive 1
#define MAXMCP_FACADE_HAS_MorphChannelName 1
#define MAXMCP_FACADE_HAS_MorphSetChannelName 1
#define MAXMCP_FACADE_HAS_MorphChannelPointCount 1
#define MAXMCP_FACADE_HAS_MorphChannelConnection 1
#define MAXMCP_FACADE_HAS_MorphSetChannelConnection 1
#define MAXMCP_FACADE_HAS_MorphChannelTargetCount 1
#define MAXMCP_FACADE_HAS_MorphChannelProgressiveCount 1
#define MAXMCP_FACADE_HAS_MorphChannelProgressive 1
#define MAXMCP_FACADE_HAS_MorphChannelTargetAt 1
#define MAXMCP_FACADE_HAS_MorphChannelTargetPoint 1
#define MAXMCP_FACADE_HAS_MorphChannelTargetPercent 1
#define MAXMCP_FACADE_HAS_MorphSetChannelTargetPercent 1
#define MAXMCP_FACADE_HAS_MorphChannelInitPercent 1
#define MAXMCP_FACADE_HAS_MorphChannelPoint 1
#define MAXMCP_FACADE_HAS_MorphSetChannelPoint 1
#define MAXMCP_FACADE_HAS_MorphChannelPointDelta 1
#define MAXMCP_FACADE_HAS_MorphSetChannelPointDelta 1
#define MAXMCP_FACADE_HAS_MorphChannelPointWeight 1
#define MAXMCP_FACADE_HAS_MorphSetChannelPointWeight 1
#define MAXMCP_FACADE_HAS_MorphChannelBaseDeltas 1
#define MAXMCP_FACADE_HAS_MorphChannelProgressiveDeltas 1
#define MAXMCP_FACADE_HAS_MorphChannelWeightController 1
#define MAXMCP_FACADE_HAS_MorphChannelReset 1
#define MAXMCP_FACADE_HAS_MorphAddProgressiveTarget 1
#define MAXMCP_FACADE_HAS_MorphDeleteAllChannels 1
#define MAXMCP_FACADE_HAS_MorphRebuildCache 1
#define MAXMCP_FACADE_HAS_MorphDeleteCache 1
#define MAXMCP_FACADE_HAS_NodeBoneAttrsRead 1
#define MAXMCP_FACADE_HAS_NodeBoneAttrsWrite 1
#define MAXMCP_FACADE_HAS_NodeBoneNodeOnOffAt 1
#define MAXMCP_FACADE_HAS_NodeBoneDisplayRead 1
#define MAXMCP_FACADE_HAS_NodeStretchTm 1
#define MAXMCP_FACADE_HAS_SceneAtmosphericCount 1
#define MAXMCP_FACADE_HAS_SceneAtmospheric 1
#define MAXMCP_FACADE_HAS_SceneAddAtmospheric 1
#define MAXMCP_FACADE_HAS_SceneSetAtmospheric 1
#define MAXMCP_FACADE_HAS_SceneDeleteAtmospheric 1
#define MAXMCP_FACADE_HAS_SceneEffectCount 1
#define MAXMCP_FACADE_HAS_SceneEffect 1
#define MAXMCP_FACADE_HAS_SceneAddEffect 1
#define MAXMCP_FACADE_HAS_SceneSetEffect 1
#define MAXMCP_FACADE_HAS_SceneDeleteEffect 1
#define MAXMCP_FACADE_HAS_SpecialFxGizmoCount 1
#define MAXMCP_FACADE_HAS_SpecialFxGizmo 1
#define MAXMCP_FACADE_HAS_SpecialFxGizmoAppend 1
#define MAXMCP_FACADE_HAS_SpecialFxGizmoDelete 1
#define MAXMCP_FACADE_HAS_SpecialFxGizmoAccepts 1
#define MAXMCP_FACADE_HAS_SpecialFxName 1
#define MAXMCP_FACADE_HAS_SpecialFxStoredName 1
#define MAXMCP_FACADE_HAS_SpecialFxSetName 1
#define MAXMCP_FACADE_HAS_SpecialFxActive 1
#define MAXMCP_FACADE_HAS_SpecialFxDisabled 1
#define MAXMCP_FACADE_HAS_SpecialFxSetDisabled 1
#define MAXMCP_FACADE_HAS_SceneUseEnvironmentMap 1
#define MAXMCP_FACADE_HAS_SceneSetUseEnvironmentMap 1
#define MAXMCP_FACADE_HAS_LayerCreate 1
#define MAXMCP_FACADE_HAS_LayerCount 1
#define MAXMCP_FACADE_HAS_LayerByIndex 1
#define MAXMCP_FACADE_HAS_LayerByName 1
#define MAXMCP_FACADE_HAS_LayerCurrent 1
#define MAXMCP_FACADE_HAS_LayerRoot 1
#define MAXMCP_FACADE_HAS_LayerSetCurrent 1
#define MAXMCP_FACADE_HAS_LayerSetCurrentFromSelection 1
#define MAXMCP_FACADE_HAS_LayerPropagateToLayer 1
#define MAXMCP_FACADE_HAS_LayerSetPropagateToLayer 1
#define MAXMCP_FACADE_HAS_LayerName 1
#define MAXMCP_FACADE_HAS_LayerSetName 1
#define MAXMCP_FACADE_HAS_LayerFlagsRead 1
#define MAXMCP_FACADE_HAS_LayerFlagsWrite 1
#define MAXMCP_FACADE_HAS_LayerWireColor 1
#define MAXMCP_FACADE_HAS_LayerSetWireColor 1
#define MAXMCP_FACADE_HAS_LayerDisplayRead 1
#define MAXMCP_FACADE_HAS_LayerDisplayWrite 1
#define MAXMCP_FACADE_HAS_LayerRenderRead 1
#define MAXMCP_FACADE_HAS_LayerRenderWrite 1
#define MAXMCP_FACADE_HAS_LayerVisibility 1
#define MAXMCP_FACADE_HAS_LayerSetVisibility 1
#define MAXMCP_FACADE_HAS_LayerMotionBlurRead 1
#define MAXMCP_FACADE_HAS_LayerMotionBlurWrite 1
#define MAXMCP_FACADE_HAS_LayerGIExcluded 1
#define MAXMCP_FACADE_HAS_LayerSetGIExcluded 1
#define MAXMCP_FACADE_HAS_LayerNeverDegrade 1
#define MAXMCP_FACADE_HAS_LayerSetNeverDegrade 1
#define MAXMCP_FACADE_HAS_LayerOn 1
#define MAXMCP_FACADE_HAS_LayerSetOn 1
#define MAXMCP_FACADE_HAS_LayerLock 1
#define MAXMCP_FACADE_HAS_LayerSetLock 1
#define MAXMCP_FACADE_HAS_LayerParent 1
#define MAXMCP_FACADE_HAS_LayerChildCount 1
#define MAXMCP_FACADE_HAS_LayerChild 1
#define MAXMCP_FACADE_HAS_LayerSetParent 1
#define MAXMCP_FACADE_HAS_NodeLayer 1
#define MAXMCP_FACADE_HAS_LayerAddNode 1
#define MAXMCP_FACADE_HAS_LayerNodeCount 1
#define MAXMCP_FACADE_HAS_LayerNodes 1
#define MAXMCP_FACADE_HAS_NodeByLayerRead 1
#define MAXMCP_FACADE_HAS_NodeByLayerWrite 1
#define MAXMCP_FACADE_HAS_LayerUsed 1
#define MAXMCP_FACADE_HAS_LayerHasObjects 1
#define MAXMCP_FACADE_HAS_LayerHierarchyHasNodes 1
#define MAXMCP_FACADE_HAS_LayerHasSelectedNodesInHierarchy 1
#define MAXMCP_FACADE_HAS_LayerHasSceneXRefNodesInHierarchy 1
#define MAXMCP_FACADE_HAS_LayerMaxNodeHandle 1
#define MAXMCP_FACADE_HAS_LayerSelectObjects 1
#define MAXMCP_FACADE_HAS_LayerSelectObjectsFlag 1
#define MAXMCP_FACADE_HAS_LayerCanDelete 1
#define MAXMCP_FACADE_HAS_LayerDelete 1
#define MAXMCP_FACADE_HAS_LayerDeleteHierarchy 1
#define MAXMCP_FACADE_HAS_NodeGetActualINode 1
#define MAXMCP_FACADE_HAS_NodeGetName 1
#define MAXMCP_FACADE_HAS_NodeGetParentNode 1
#define MAXMCP_FACADE_HAS_NodeGetChildNode 1
#define MAXMCP_FACADE_HAS_NodeGetImageBlurMultController 1
#define MAXMCP_FACADE_HAS_NodeGetMotBlurOnOffController 1
#define MAXMCP_FACADE_HAS_NodeGetTarget 1
#define MAXMCP_FACADE_HAS_NodeGetLookatNode 1
#define MAXMCP_FACADE_HAS_NodeGetObjectRef 1
#define MAXMCP_FACADE_HAS_NodeGetObjOrWSMRef 1
#define MAXMCP_FACADE_HAS_NodeGetTMController 1
#define MAXMCP_FACADE_HAS_NodeGetVisController 1
#define MAXMCP_FACADE_HAS_NodeGetMtl 1
#define MAXMCP_FACADE_HAS_NodeGetXRefTree 1
#define MAXMCP_FACADE_HAS_NodeGetXRefParent 1
#define MAXMCP_FACADE_HAS_MeshGetMtlIndex 1
#define MAXMCP_FACADE_HAS_MeshInit 1
#define MAXMCP_FACADE_HAS_MeshSetNumTVerts 1
#define MAXMCP_FACADE_HAS_MeshSetNumTVFaces 1
#define MAXMCP_FACADE_HAS_MeshSetNumVertCol 1
#define MAXMCP_FACADE_HAS_MeshSetNumVCFaces 1
#define MAXMCP_FACADE_HAS_MeshSetNumMaps 1
#define MAXMCP_FACADE_HAS_MeshGetNumMaps 1
#define MAXMCP_FACADE_HAS_MeshMapSupport 1
#define MAXMCP_FACADE_HAS_MeshSetMapSupport 1
#define MAXMCP_FACADE_HAS_MeshSetNumMapVerts 1
#define MAXMCP_FACADE_HAS_MeshGetNumMapVerts 1
#define MAXMCP_FACADE_HAS_MeshSetNumMapFaces 1
#define MAXMCP_FACADE_HAS_MeshGetNumMapFaces 1
#define MAXMCP_FACADE_HAS_MeshMakeMapPlanar 1
#define MAXMCP_FACADE_HAS_MeshDeleteIsoMapVerts 1
#define MAXMCP_FACADE_HAS_MeshFreeMapVerts 1
#define MAXMCP_FACADE_HAS_MeshFreeMapFaces 1
#define MAXMCP_FACADE_HAS_MeshSetNumVData 1
#define MAXMCP_FACADE_HAS_MeshGetNumVData 1
#define MAXMCP_FACADE_HAS_MeshGetNumVDataSupported 1
#define MAXMCP_FACADE_HAS_MeshVDataSupport 1
#define MAXMCP_FACADE_HAS_MeshSetSmoothFlags 1
#define MAXMCP_FACADE_HAS_MeshGetSmoothFlags 1
#define MAXMCP_FACADE_HAS_MeshBuildNormals 1
#define MAXMCP_FACADE_HAS_MeshBuildRenderNormals 1
#define MAXMCP_FACADE_HAS_MeshCheckNormals 1
#define MAXMCP_FACADE_HAS_MeshGetFaceMtlIndex 1
#define MAXMCP_FACADE_HAS_MeshInvalidateGeomCache 1
#define MAXMCP_FACADE_HAS_MeshInvalidateTopologyCache 1
#define MAXMCP_FACADE_HAS_MeshFreeAll 1
#define MAXMCP_FACADE_HAS_MeshEnableEdgeList 1
#define MAXMCP_FACADE_HAS_MeshBuildVisEdgeList 1
#define MAXMCP_FACADE_HAS_MeshInvalidateEdgeList 1
#define MAXMCP_FACADE_HAS_MeshBuildBoundingBox 1
#define MAXMCP_FACADE_HAS_MeshBuildStrips 1
#define MAXMCP_FACADE_HAS_MeshInvalidateStrips 1
#define MAXMCP_FACADE_HAS_MeshBuildStripsAndEdges 1
#define MAXMCP_FACADE_HAS_MeshFlipNormal 1
#define MAXMCP_FACADE_HAS_MeshUnifyNormals 1
#define MAXMCP_FACADE_HAS_MeshAutoSmooth 1
#define MAXMCP_FACADE_HAS_MeshDeleteFlaggedFaces 1
#define MAXMCP_FACADE_HAS_MeshDeleteSelected 1
#define MAXMCP_FACADE_HAS_MeshDoesFaceExist 1
#define MAXMCP_FACADE_HAS_MeshRemoveDegenerateFaces 1
#define MAXMCP_FACADE_HAS_MeshRemoveIllegalFaces 1
#define MAXMCP_FACADE_HAS_MeshDivideEdge 1
#define MAXMCP_FACADE_HAS_MeshDivideFace 1
#define MAXMCP_FACADE_HAS_MeshExtrudeFaces 1
#define MAXMCP_FACADE_HAS_MeshIndentSelFaces 1
#define MAXMCP_FACADE_HAS_MeshDeleteIsoVerts 1
#define MAXMCP_FACADE_HAS_MeshIsFaceCacheInvalid 1
#define MAXMCP_FACADE_HAS_MeshInvalidateVertexCache 1
#define MAXMCP_FACADE_HAS_MeshSetStaticMesh 1
#define MAXMCP_FACADE_HAS_MeshReduceDisplayCaches 1
#define MAXMCP_FACADE_HAS_MeshIsAccelDataDirty 1
#define MAXMCP_FACADE_HAS_MeshDirtyAccelData 1
#define MAXMCP_FACADE_HAS_SceneForceCompleteRedraw 1
#define MAXMCP_FACADE_HAS_SceneDisplayActiveCameraViewWithMultiPassEffect 1
#define MAXMCP_FACADE_HAS_SceneSetActiveViewportTransparencyDisplay 1
#define MAXMCP_FACADE_HAS_SceneDisableSceneRedraw 1
#define MAXMCP_FACADE_HAS_SceneEnableSceneRedraw 1
#define MAXMCP_FACADE_HAS_SceneIsSceneRedrawDisabled 1
#define MAXMCP_FACADE_HAS_ScenePopCommandMode 1
#define MAXMCP_FACADE_HAS_SceneSetStdCommandMode 1
#define MAXMCP_FACADE_HAS_ScenePushStdCommandMode 1
#define MAXMCP_FACADE_HAS_ScenePopPrompt 1
#define MAXMCP_FACADE_HAS_SceneRemoveTempPrompt 1
#define MAXMCP_FACADE_HAS_SceneDisableStatusXYZ 1
#define MAXMCP_FACADE_HAS_SceneEnableStatusXYZ 1
#define MAXMCP_FACADE_HAS_SceneProgressEnd 1
#define MAXMCP_FACADE_HAS_SceneGetCancel 1
#define MAXMCP_FACADE_HAS_SceneSetCancel 1
#define MAXMCP_FACADE_HAS_SceneGetGridSpacing 1
#define MAXMCP_FACADE_HAS_SceneGetGridMajorLines 1
#define MAXMCP_FACADE_HAS_SceneSetExtendedDisplayMode 1
#define MAXMCP_FACADE_HAS_SceneGetExtendedDisplayMode 1
#define MAXMCP_FACADE_HAS_SceneSetFlyOffTime 1
#define MAXMCP_FACADE_HAS_SceneGetFlyOffTime 1
#define MAXMCP_FACADE_HAS_SceneSetCrossHairCur 1
#define MAXMCP_FACADE_HAS_SceneGetCrossHairCur 1
#define MAXMCP_FACADE_HAS_SceneRealizeParamPanel 1
#define MAXMCP_FACADE_HAS_SceneSnapPercent 1
#define MAXMCP_FACADE_HAS_SceneGetSnapState 1
#define MAXMCP_FACADE_HAS_SceneGetSnapMode 1
#define MAXMCP_FACADE_HAS_SceneSetSnapMode 1
#define MAXMCP_FACADE_HAS_SceneClearPickMode 1
#define MAXMCP_FACADE_HAS_SceneClearSubObjectNamedSelSets 1
#define MAXMCP_FACADE_HAS_SceneClearCurNamedSelSet 1
#define MAXMCP_FACADE_HAS_SceneGetSubObjectLevel 1
#define MAXMCP_FACADE_HAS_SceneSetSubObjectLevel 1
#define MAXMCP_FACADE_HAS_SceneGetNumSubObjectLevels 1
#define MAXMCP_FACADE_HAS_ScenePipeSelLevelChanged 1
#define MAXMCP_FACADE_HAS_SceneSelectionFrozen 1
#define MAXMCP_FACADE_HAS_SceneFreezeSelection 1
#define MAXMCP_FACADE_HAS_SceneThawSelection 1
#define MAXMCP_FACADE_HAS_SceneGetSelNode 1
#define MAXMCP_FACADE_HAS_SceneGetSelNodeCount 1
#define MAXMCP_FACADE_HAS_SceneEnableShowEndResult 1
#define MAXMCP_FACADE_HAS_SceneGetShowEndResult 1
#define MAXMCP_FACADE_HAS_SceneSetShowEndResult 1
#define MAXMCP_FACADE_HAS_SceneGetPreserveStackPosition 1
#define MAXMCP_FACADE_HAS_SceneSetPreserveStackPosition 1
#define MAXMCP_FACADE_HAS_SceneGetCrossing 1
#define MAXMCP_FACADE_HAS_SceneSetToolButtonState 1
#define MAXMCP_FACADE_HAS_SceneEnableToolButton 1
#define MAXMCP_FACADE_HAS_SceneEnableUndo 1
#define MAXMCP_FACADE_HAS_SceneGetCommandPanelTaskMode 1
#define MAXMCP_FACADE_HAS_SceneSetCommandPanelTaskMode 1
#define MAXMCP_FACADE_HAS_SceneEnableAnimateButton 1
#define MAXMCP_FACADE_HAS_SceneIsAnimateEnabled 1
#define MAXMCP_FACADE_HAS_SceneSetAnimateButtonState 1
#define MAXMCP_FACADE_HAS_SceneInProgressiveMode 1
#define MAXMCP_FACADE_HAS_SceneBeginProgressiveMode 1
#define MAXMCP_FACADE_HAS_SceneEndProgressiveMode 1
#define MAXMCP_FACADE_HAS_SceneGetAxisConstraints 1
#define MAXMCP_FACADE_HAS_SceneSetAxisConstraints 1
#define MAXMCP_FACADE_HAS_SceneEnableAxisConstraints 1
#define MAXMCP_FACADE_HAS_ScenePushAxisConstraints 1
#define MAXMCP_FACADE_HAS_ScenePopAxisConstraints 1
#define MAXMCP_FACADE_HAS_SceneGetCoordCenter 1
#define MAXMCP_FACADE_HAS_SceneSetCoordCenter 1
#define MAXMCP_FACADE_HAS_SceneEnableCoordCenter 1
#define MAXMCP_FACADE_HAS_SceneGetRefCoordSys 1
#define MAXMCP_FACADE_HAS_SceneSetRefCoordSys 1
#define MAXMCP_FACADE_HAS_SceneEnableRefCoordSys 1
#define MAXMCP_FACADE_HAS_SceneGetSelectFilter 1
#define MAXMCP_FACADE_HAS_SceneSetSelectFilter 1
#define MAXMCP_FACADE_HAS_SceneGetNumberSelectFilters 1
#define MAXMCP_FACADE_HAS_SceneGetSelectFilterName 1
#define MAXMCP_FACADE_HAS_SceneGetDisplayFilter 1
#define MAXMCP_FACADE_HAS_SceneSetDisplayFilter 1
#define MAXMCP_FACADE_HAS_SceneGetNumberDisplayFilters 1
#define MAXMCP_FACADE_HAS_SceneGetDisplayFilterName 1
#define MAXMCP_FACADE_HAS_SceneGetNumAxis 1
#define MAXMCP_FACADE_HAS_SceneLockAxisTripods 1
#define MAXMCP_FACADE_HAS_SceneAxisTripodLocked 1
#define MAXMCP_FACADE_HAS_SceneGetTime 1
#define MAXMCP_FACADE_HAS_SceneIsCPEdgeOnInView 1
#define MAXMCP_FACADE_HAS_SceneGetRootNode 1
#define MAXMCP_FACADE_HAS_SceneClearNodeSelection 1
#define MAXMCP_FACADE_HAS_SceneGetLightConeConstraint 1
#define MAXMCP_FACADE_HAS_SceneGetActiveGrid 1
#define MAXMCP_FACADE_HAS_SceneStopCreating 1
#define MAXMCP_FACADE_HAS_SceneGetDir 1
#define MAXMCP_FACADE_HAS_SceneGetPlugInEntryCount 1
#define MAXMCP_FACADE_HAS_SceneGetPlugInDesc 1
#define MAXMCP_FACADE_HAS_SceneGetPlugInDir 1
#define MAXMCP_FACADE_HAS_SceneGetMtlSlot 1
#define MAXMCP_FACADE_HAS_SceneGetMatLibFileName 1
#define MAXMCP_FACADE_HAS_SceneFileOpen 1
#define MAXMCP_FACADE_HAS_SceneFileSave 1
#define MAXMCP_FACADE_HAS_SceneFileSaveAs 1
#define MAXMCP_FACADE_HAS_SceneFileSaveSelected 1
#define MAXMCP_FACADE_HAS_SceneFileReset 1
#define MAXMCP_FACADE_HAS_SceneFileMerge 1
#define MAXMCP_FACADE_HAS_SceneFileHold 1
#define MAXMCP_FACADE_HAS_SceneFileFetch 1
#define MAXMCP_FACADE_HAS_SceneLoadDefaultMatLib 1
#define MAXMCP_FACADE_HAS_SceneFileImport 1
#define MAXMCP_FACADE_HAS_SceneFileExport 1
#define MAXMCP_FACADE_HAS_SceneSetBkgImageAspect 1
#define MAXMCP_FACADE_HAS_SceneGetBkgImageAspect 1
#define MAXMCP_FACADE_HAS_SceneSetBkgImageAnimate 1
#define MAXMCP_FACADE_HAS_SceneSetBkgFrameRange 1
#define MAXMCP_FACADE_HAS_SceneGetBkgFrameRangeVal 1
#define MAXMCP_FACADE_HAS_SceneSetBkgORType 1
#define MAXMCP_FACADE_HAS_SceneGetBkgORType 1
#define MAXMCP_FACADE_HAS_SceneSetBkgStartTime 1
#define MAXMCP_FACADE_HAS_SceneGetBkgStartTime 1
#define MAXMCP_FACADE_HAS_SceneSetBkgSyncFrame 1
#define MAXMCP_FACADE_HAS_SceneGetBkgSyncFrame 1
#define MAXMCP_FACADE_HAS_SceneGetBkgFrameNum 1
#define MAXMCP_FACADE_HAS_SceneGetRealTimePlayback 1
#define MAXMCP_FACADE_HAS_SceneSetRealTimePlayback 1
#define MAXMCP_FACADE_HAS_SceneGetPlayActiveOnly 1
#define MAXMCP_FACADE_HAS_SceneSetPlayActiveOnly 1
#define MAXMCP_FACADE_HAS_SceneStartAnimPlayback 1
#define MAXMCP_FACADE_HAS_SceneEndAnimPlayback 1
#define MAXMCP_FACADE_HAS_SceneIsAnimPlaying 1
#define MAXMCP_FACADE_HAS_SceneGetPlaybackSpeed 1
#define MAXMCP_FACADE_HAS_SceneSetPlaybackSpeed 1
#define MAXMCP_FACADE_HAS_SceneGetPlaybackLoop 1
#define MAXMCP_FACADE_HAS_SceneSetPlaybackLoop 1
#define MAXMCP_FACADE_HAS_SceneIncrementValidityToken 1
#define MAXMCP_FACADE_HAS_SceneCloseCurRenderer 1
#define MAXMCP_FACADE_HAS_SceneSetUseDraftRenderer 1
#define MAXMCP_FACADE_HAS_SceneGetUseDraftRenderer 1
#define MAXMCP_FACADE_HAS_SceneChangeRenderSetting 1
#define MAXMCP_FACADE_HAS_SceneGetCurrentRenderSetting 1
#define MAXMCP_FACADE_HAS_SceneGetMEditRendererLocked 1
#define MAXMCP_FACADE_HAS_SceneSetMEditRendererLocked 1
#define MAXMCP_FACADE_HAS_SceneGetMEditRendererLocked_DefaultValue 1
#define MAXMCP_FACADE_HAS_SceneSetMEditRendererLocked_DefaultValue 1
#define MAXMCP_FACADE_HAS_SceneCheckForRenderAbort 1
#define MAXMCP_FACADE_HAS_SceneAbortRender 1
#define MAXMCP_FACADE_HAS_SceneGetRendTimeType 1
#define MAXMCP_FACADE_HAS_SceneSetRendTimeType 1
#define MAXMCP_FACADE_HAS_SceneGetRendStart 1
#define MAXMCP_FACADE_HAS_SceneSetRendStart 1
#define MAXMCP_FACADE_HAS_SceneGetRendEnd 1
#define MAXMCP_FACADE_HAS_SceneSetRendEnd 1
#define MAXMCP_FACADE_HAS_SceneGetRendNThFrame 1
#define MAXMCP_FACADE_HAS_SceneSetRendNThFrame 1
#define MAXMCP_FACADE_HAS_SceneGetRendShowVFB 1
#define MAXMCP_FACADE_HAS_SceneSetRendShowVFB 1
#define MAXMCP_FACADE_HAS_SceneGetRendSaveFile 1
#define MAXMCP_FACADE_HAS_SceneSetRendSaveFile 1
#define MAXMCP_FACADE_HAS_SceneGetRendUseDevice 1
#define MAXMCP_FACADE_HAS_SceneSetRendUseDevice 1
#define MAXMCP_FACADE_HAS_SceneGetRendUseNet 1
#define MAXMCP_FACADE_HAS_SceneSetRendUseNet 1
#define MAXMCP_FACADE_HAS_SceneGetRendWidth 1
#define MAXMCP_FACADE_HAS_SceneSetRendWidth 1
#define MAXMCP_FACADE_HAS_SceneGetRendHeight 1
#define MAXMCP_FACADE_HAS_SceneSetRendHeight 1
#define MAXMCP_FACADE_HAS_SceneGetRendPixelAspect 1
#define MAXMCP_FACADE_HAS_SceneSetRendPixelAspect 1
#define MAXMCP_FACADE_HAS_SceneGetRendImageAspect 1
#define MAXMCP_FACADE_HAS_SceneGetRendApertureWidth 1
#define MAXMCP_FACADE_HAS_SceneSetRendApertureWidth 1
#define MAXMCP_FACADE_HAS_SceneGetRendFieldRender 1
#define MAXMCP_FACADE_HAS_SceneSetRendFieldRender 1
#define MAXMCP_FACADE_HAS_SceneGetRendColorCheck 1
#define MAXMCP_FACADE_HAS_SceneSetRendColorCheck 1
#define MAXMCP_FACADE_HAS_SceneGetRendSuperBlack 1
#define MAXMCP_FACADE_HAS_SceneSetRendSuperBlack 1
#define MAXMCP_FACADE_HAS_SceneGetRendHidden 1
#define MAXMCP_FACADE_HAS_SceneSetRendHidden 1
#define MAXMCP_FACADE_HAS_SceneGetRendForce2Side 1
#define MAXMCP_FACADE_HAS_SceneSetRendForce2Side 1
#define MAXMCP_FACADE_HAS_SceneGetRendAtmosphere 1
#define MAXMCP_FACADE_HAS_SceneSetRendAtmosphere 1
#define MAXMCP_FACADE_HAS_SceneGetRendEffects 1
#define MAXMCP_FACADE_HAS_SceneSetRendEffects 1
#define MAXMCP_FACADE_HAS_SceneGetRendDisplacement 1
#define MAXMCP_FACADE_HAS_SceneSetRendDisplacement 1
#define MAXMCP_FACADE_HAS_SceneGetRendDitherTrue 1
#define MAXMCP_FACADE_HAS_SceneSetRendDitherTrue 1
#define MAXMCP_FACADE_HAS_SceneGetRendDither256 1
#define MAXMCP_FACADE_HAS_SceneSetRendDither256 1
#define MAXMCP_FACADE_HAS_SceneGetRendMultiThread 1
#define MAXMCP_FACADE_HAS_SceneSetRendMultiThread 1
#define MAXMCP_FACADE_HAS_SceneGetRendNThSerial 1
#define MAXMCP_FACADE_HAS_SceneSetRendNThSerial 1
#define MAXMCP_FACADE_HAS_SceneGetRendVidCorrectMethod 1
#define MAXMCP_FACADE_HAS_SceneSetRendVidCorrectMethod 1
#define MAXMCP_FACADE_HAS_SceneGetRendFieldOrder 1
#define MAXMCP_FACADE_HAS_SceneSetRendFieldOrder 1
#define MAXMCP_FACADE_HAS_SceneGetRendNTSC_PAL 1
#define MAXMCP_FACADE_HAS_SceneSetRendNTSC_PAL 1
#define MAXMCP_FACADE_HAS_SceneGetRendSuperBlackThresh 1
#define MAXMCP_FACADE_HAS_SceneSetRendSuperBlackThresh 1
#define MAXMCP_FACADE_HAS_SceneGetRendFileNumberBase 1
#define MAXMCP_FACADE_HAS_SceneSetRendFileNumberBase 1
#define MAXMCP_FACADE_HAS_SceneGetSkipRenderedFrames 1
#define MAXMCP_FACADE_HAS_SceneSetSkipRenderedFrames 1
#define MAXMCP_FACADE_HAS_SceneGetRendSimplifyAreaLights 1
#define MAXMCP_FACADE_HAS_SceneSetRendSimplifyAreaLights 1
#define MAXMCP_FACADE_HAS_SceneGetHideByCategoryFlags 1
#define MAXMCP_FACADE_HAS_SceneSetHideByCategoryFlags 1
#define MAXMCP_FACADE_HAS_SceneGetViewportLayout 1
#define MAXMCP_FACADE_HAS_SceneSetViewportLayout 1
#define MAXMCP_FACADE_HAS_SceneIsViewportMaxed 1
#define MAXMCP_FACADE_HAS_SceneSetViewportMax 1
#define MAXMCP_FACADE_HAS_SceneViewportZoomExtents 1
#define MAXMCP_FACADE_HAS_SceneGetINodeByHandle 1
#define MAXMCP_FACADE_HAS_SceneGetINodeFromRenderID 1
#define MAXMCP_FACADE_HAS_SceneExecuteMAXCommand 1
#define MAXMCP_FACADE_HAS_SceneGetEnvironmentMap 1
#define MAXMCP_FACADE_HAS_SceneGetUseEnvironmentMap 1
#define MAXMCP_FACADE_HAS_SceneGetAmbientController 1
#define MAXMCP_FACADE_HAS_SceneGetLightTintController 1
#define MAXMCP_FACADE_HAS_SceneSetLightLevel 1
#define MAXMCP_FACADE_HAS_SceneGetLightLevelController 1
#define MAXMCP_FACADE_HAS_SceneNumAtmospheric 1
#define MAXMCP_FACADE_HAS_SceneDeleteAtmosphere 1
#define MAXMCP_FACADE_HAS_SceneGetBackGroundController 1
#define MAXMCP_FACADE_HAS_SceneNumEffects 1
#define MAXMCP_FACADE_HAS_SceneInvalidateOsnapdraw 1
#define MAXMCP_FACADE_HAS_SceneIsNetworkRenderServer 1
#define MAXMCP_FACADE_HAS_SceneGetScenePointer 1
#define MAXMCP_FACADE_HAS_SceneFreeSceneBitmaps 1
#define MAXMCP_FACADE_HAS_SceneGetKeyStepsSelOnly 1
#define MAXMCP_FACADE_HAS_SceneSetKeyStepsSelOnly 1
#define MAXMCP_FACADE_HAS_SceneGetKeyStepsUseTrans 1
#define MAXMCP_FACADE_HAS_SceneSetKeyStepsUseTrans 1
#define MAXMCP_FACADE_HAS_SceneGetKeyStepsPos 1
#define MAXMCP_FACADE_HAS_SceneSetKeyStepsPos 1
#define MAXMCP_FACADE_HAS_SceneGetKeyStepsRot 1
#define MAXMCP_FACADE_HAS_SceneSetKeyStepsRot 1
#define MAXMCP_FACADE_HAS_SceneGetKeyStepsScale 1
#define MAXMCP_FACADE_HAS_SceneSetKeyStepsScale 1
#define MAXMCP_FACADE_HAS_SceneGetKeyStepsUseTrackBar 1
#define MAXMCP_FACADE_HAS_SceneSetKeyStepsUseTrackBar 1
#define MAXMCP_FACADE_HAS_SceneGetUseTransformGizmo 1
#define MAXMCP_FACADE_HAS_SceneSetUseTransformGizmo 1
#define MAXMCP_FACADE_HAS_SceneSetTransformGizmoRestoreAxis 1
#define MAXMCP_FACADE_HAS_SceneGetTransformGizmoRestoreAxis 1
#define MAXMCP_FACADE_HAS_SceneGetConstantAxisRestriction 1
#define MAXMCP_FACADE_HAS_SceneSetConstantAxisRestriction 1
#define MAXMCP_FACADE_HAS_SceneDeactivateTransformGizmo 1
#define MAXMCP_FACADE_HAS_SceneConfigureBitmapPaths 1
#define MAXMCP_FACADE_HAS_SceneGetCommandStackSize 1
#define MAXMCP_FACADE_HAS_SceneAddSFXRollupPage 1
#define MAXMCP_FACADE_HAS_SceneDeleteSFXRollupPage 1
#define MAXMCP_FACADE_HAS_SceneRefreshSFXRollupPage 1
#define MAXMCP_FACADE_HAS_SceneGetNumProperties 1
#define MAXMCP_FACADE_HAS_SceneGetImportZoomExtents 1
#define MAXMCP_FACADE_HAS_SceneSetImportZoomExtents 1
#define MAXMCP_FACADE_HAS_SceneSetIncludeXRefsInHierarchy 1
#define MAXMCP_FACADE_HAS_SceneGetIncludeXRefsInHierarchy 1
#define MAXMCP_FACADE_HAS_SceneIsXRefAutoUpdateSuspended 1
#define MAXMCP_FACADE_HAS_SceneSetXRefAutoUpdateSuspended 1
#define MAXMCP_FACADE_HAS_SceneUpdateMtlEditorBrackets 1
#define MAXMCP_FACADE_HAS_SceneIsTrialLicense 1
#define MAXMCP_FACADE_HAS_SceneIsNetworkLicense 1
#define MAXMCP_FACADE_HAS_SceneCheckForSave 1
#define MAXMCP_FACADE_HAS_SceneFlushUndoBuffer 1
#define MAXMCP_FACADE_HAS_SceneDeferredPluginLoadingEnabled 1
#define MAXMCP_FACADE_HAS_SceneEnableDeferredPluginLoading 1
#define MAXMCP_FACADE_HAS_SceneGetImportCtxNode 1
#define MAXMCP_FACADE_HAS_SceneSetQuietMode 1
#define MAXMCP_FACADE_HAS_SceneGetQuietMode 1
#define MAXMCP_FACADE_HAS_SceneSetAutoGridEnable 1
#define MAXMCP_FACADE_HAS_SceneGetAutoGridEnable 1
#define MAXMCP_FACADE_HAS_SceneGetAutoGridState 1
#define MAXMCP_FACADE_HAS_SceneSetAutoGridState 1
#define MAXMCP_FACADE_HAS_PolyVShrink 1
#define MAXMCP_FACADE_HAS_PolyFreeVEdge 1
#define MAXMCP_FACADE_HAS_PolyVEdgeAlloc 1
#define MAXMCP_FACADE_HAS_PolyFreeVFace 1
#define MAXMCP_FACADE_HAS_PolyVFaceAlloc 1
#define MAXMCP_FACADE_HAS_PolyEAlloc 1
#define MAXMCP_FACADE_HAS_PolyEShrink 1
#define MAXMCP_FACADE_HAS_PolyFShrink 1
#define MAXMCP_FACADE_HAS_PolyMNum 1
#define MAXMCP_FACADE_HAS_PolyTriNum 1
#define MAXMCP_FACADE_HAS_PolyIsEdgeMapSeam 1
#define MAXMCP_FACADE_HAS_PolySetNumVData 1
#define MAXMCP_FACADE_HAS_PolyVDNum 1
#define MAXMCP_FACADE_HAS_PolyVDNumSupported 1
#define MAXMCP_FACADE_HAS_PolyVDataSupport 1
#define MAXMCP_FACADE_HAS_PolySetNumEData 1
#define MAXMCP_FACADE_HAS_PolyEDNum 1
#define MAXMCP_FACADE_HAS_PolyEDNumSupported 1
#define MAXMCP_FACADE_HAS_PolyEDataSupport 1
#define MAXMCP_FACADE_HAS_PolyVClear 1
#define MAXMCP_FACADE_HAS_PolyVInit 1
#define MAXMCP_FACADE_HAS_PolyVFaceIndex 1
#define MAXMCP_FACADE_HAS_PolyVEdgeIndex 1
#define MAXMCP_FACADE_HAS_PolyVDeleteEdge 1
#define MAXMCP_FACADE_HAS_PolyVDeleteFace 1
#define MAXMCP_FACADE_HAS_PolyVReplaceEdge 1
#define MAXMCP_FACADE_HAS_PolyVReplaceFace 1
#define MAXMCP_FACADE_HAS_PolyCopyVert 1
#define MAXMCP_FACADE_HAS_PolyMNVDebugPrint 1
#define MAXMCP_FACADE_HAS_PolyAppendNewFaces 1
#define MAXMCP_FACADE_HAS_PolyAppendNewVerts 1
#define MAXMCP_FACADE_HAS_PolyEliminateCollinearVerts 1
#define MAXMCP_FACADE_HAS_PolyEliminateCoincidentVerts 1
#define MAXMCP_FACADE_HAS_PolyPaintFaceFlag 1
#define MAXMCP_FACADE_HAS_PolyFillInFaceEdges 1
#define MAXMCP_FACADE_HAS_PolyFillInVertEdgesFaces 1
#define MAXMCP_FACADE_HAS_PolyOrderVerts 1
#define MAXMCP_FACADE_HAS_PolyOrderVert 1
#define MAXMCP_FACADE_HAS_PolyTriangulate 1
#define MAXMCP_FACADE_HAS_PolyTriangulateFace 1
#define MAXMCP_FACADE_HAS_PolyTargetVertsBySelection 1
#define MAXMCP_FACADE_HAS_PolyTargetEdgesBySelection 1
#define MAXMCP_FACADE_HAS_PolyTargetFacesBySelection 1
#define MAXMCP_FACADE_HAS_PolyDetargetVertsBySharpness 1
#define MAXMCP_FACADE_HAS_PolyRetriangulateFace 1
#define MAXMCP_FACADE_HAS_PolyMakePolyMesh 1
#define MAXMCP_FACADE_HAS_PolyMakePolyMeshRanged 1
#define MAXMCP_FACADE_HAS_PolyMakeConvexPolyMesh 1
#define MAXMCP_FACADE_HAS_PolyFindEdgeFromVertToVert 1
#define MAXMCP_FACADE_HAS_PolyCheckNormals 1
#define MAXMCP_FACADE_HAS_PolyBuildNormals 1
#define MAXMCP_FACADE_HAS_PolyBuildRenderNormals 1
#define MAXMCP_FACADE_HAS_PolyFlipElementNormals 1
#define MAXMCP_FACADE_HAS_PolyFlipFaceNormals 1
#define MAXMCP_FACADE_HAS_PolyResmooth 1
#define MAXMCP_FACADE_HAS_PolyCommonSmoothing 1
#define MAXMCP_FACADE_HAS_PolyGetOldSmGroup 1
#define MAXMCP_FACADE_HAS_PolyGetAllSmGroups 1
#define MAXMCP_FACADE_HAS_PolyFindReplacementSmGroup 1
#define MAXMCP_FACADE_HAS_PolyPaintNewSmGroup 1
#define MAXMCP_FACADE_HAS_PolySeparateSmGroups 1
#define MAXMCP_FACADE_HAS_PolyFindAvailableSmoothingGroups 1
#define MAXMCP_FACADE_HAS_PolyFenceMaterials 1
#define MAXMCP_FACADE_HAS_PolyFenceSmGroups 1
#define MAXMCP_FACADE_HAS_PolyFenceFaceSel 1
#define MAXMCP_FACADE_HAS_PolyFenceOneSidedEdges 1
#define MAXMCP_FACADE_HAS_PolyFenceNonPlanarEdges 1
#define MAXMCP_FACADE_HAS_PolySetMapSeamFlags 1
#define MAXMCP_FACADE_HAS_PolyFindOpenRegions 1
#define MAXMCP_FACADE_HAS_PolyEliminateDoubledMappingVerts 1
#define MAXMCP_FACADE_HAS_PolyEliminateIsoMapVerts 1
#define MAXMCP_FACADE_HAS_PolyMNDebugPrintVertexNeighborhood 1
#define MAXMCP_FACADE_HAS_PolySplitEdge 1
#define MAXMCP_FACADE_HAS_PolySplitFlaggedVertices 1
#define MAXMCP_FACADE_HAS_PolySplitFlaggedEdges 1
#define MAXMCP_FACADE_HAS_PolySplitFacesUsingBothSidesOfEdge 1
#define MAXMCP_FACADE_HAS_PolyMakeConvex 1
#define MAXMCP_FACADE_HAS_PolyMakeFaceConvex 1
#define MAXMCP_FACADE_HAS_PolyRestrictPolySize 1
#define MAXMCP_FACADE_HAS_PolyMakePlanar 1
#define MAXMCP_FACADE_HAS_PolyMakeFacePlanar 1
#define MAXMCP_FACADE_HAS_PolyWeldBorderEdges 1
#define MAXMCP_FACADE_HAS_PolyWeldBorderVerts 1
#define MAXMCP_FACADE_HAS_PolyWeldOpposingEdges 1
#define MAXMCP_FACADE_HAS_PolyPrepForBoolean 1
#define MAXMCP_FACADE_HAS_PolyConnectEdges 1
#define MAXMCP_FACADE_HAS_PolyConnectVertices 1
#define MAXMCP_FACADE_HAS_PolyCloneVerts 1
#define MAXMCP_FACADE_HAS_PolyDetachFaces 1
#define MAXMCP_FACADE_HAS_PolyQuadChamfer 1
#define MAXMCP_FACADE_HAS_PolyUpdateDisplayVertexColors 1
#define MAXMCP_FACADE_HAS_PolySetDisplayVertexColors 1
#define MAXMCP_FACADE_HAS_PolyPrepForPipeline 1
#define MAXMCP_FACADE_HAS_PolyAllocRVerts 1
#define MAXMCP_FACADE_HAS_PolyFreeRVerts 1
#define MAXMCP_FACADE_HAS_PolyReduceDisplayCaches 1
#define MAXMCP_FACADE_HAS_PolyInvalidateHardwareMesh 1
#define MAXMCP_FACADE_HAS_PolySetStaticMesh 1
#define MAXMCP_FACADE_HAS_PolyClearSpecifiedNormals 1
#define MAXMCP_FACADE_HAS_PolySpecifyNormals 1
#define MAXMCP_FACADE_HAS_PolyRelax 1
#define MAXMCP_FACADE_HAS_PolySmoothByCreases 1
#define MAXMCP_FACADE_HAS_PolyNumDeadEdges 1
#define MAXMCP_FACADE_HAS_PolyNumDeadVerts 1
#define MAXMCP_FACADE_HAS_PolyNumDeadFaces 1
#define MAXMCP_FACADE_HAS_PolyIsAccelDataDirty 1
#define MAXMCP_FACADE_HAS_PolyDirtyAccelData 1
#define MAXMCP_FACADE_HAS_PolyGetFlag 1
#define MAXMCP_FACADE_HAS_PolyClearAllFlags 1
#define MAXMCP_FACADE_HAS_PolyCopyFlags 1
#define MAXMCP_FACADE_HAS_PolyFlagMatch 1
#define MAXMCP_FACADE_HAS_PolyExportFlags 1
#define MAXMCP_FACADE_HAS_PolyImportFlags 1
#define MAXMCP_FACADE_HAS_ControllerGetTarget 1
#define MAXMCP_FACADE_HAS_ControllerGetPositionController 1
#define MAXMCP_FACADE_HAS_ControllerGetRotationController 1
#define MAXMCP_FACADE_HAS_ControllerGetScaleController 1
#define MAXMCP_FACADE_HAS_ControllerGetRollController 1
#define MAXMCP_FACADE_HAS_ControllerGetInheritanceFlags 1
#define MAXMCP_FACADE_HAS_ControllerIsColorController 1
#define MAXMCP_FACADE_HAS_ControllerIsLeaf 1
#define MAXMCP_FACADE_HAS_ControllerIsKeyable 1
#define MAXMCP_FACADE_HAS_ControllerIsReplaceable 1
#define MAXMCP_FACADE_HAS_ControllerMirrorIKConstraints 1
#define MAXMCP_FACADE_HAS_ControllerTerminateIK 1
#define MAXMCP_FACADE_HAS_ControllerNodeIKParamsChanged 1
#define MAXMCP_FACADE_HAS_ControllerTMInvalidated 1
#define MAXMCP_FACADE_HAS_ControllerCanCopyIKParams 1
#define MAXMCP_FACADE_HAS_ControllerCanApplyEaseMultCurves 1
#define MAXMCP_FACADE_HAS_ControllerPostCloneNode 1
#define MAXMCP_FACADE_HAS_ControllerPreventNodeDeletion 1
#define MAXMCP_FACADE_HAS_ControllerVisibleInViewports 1
#define MAXMCP_FACADE_HAS_ControllerCanInstanceController 1
#define MAXMCP_FACADE_HAS_ControllerClearSelection 1
#define MAXMCP_FACADE_HAS_ControllerSelectAll 1
#define MAXMCP_FACADE_HAS_ControllerInvertSelection 1
#define MAXMCP_FACADE_HAS_MeshSetMtlIndex 1
#define MAXMCP_FACADE_HAS_MeshGetNormal 1
#define MAXMCP_FACADE_HAS_MeshGetFaceNormal 1
#define MAXMCP_FACADE_HAS_MeshSetFaceMtlIndex 1
#define MAXMCP_FACADE_HAS_MeshFaceNormal 1
#define MAXMCP_FACADE_HAS_MeshFaceCenter 1
#define MAXMCP_FACADE_HAS_NodeSetObjOffsetPos 1
#define MAXMCP_FACADE_HAS_NodeGetObjOffsetPos 1
#define MAXMCP_FACADE_HAS_NodeSetObjOffsetRot 1
#define MAXMCP_FACADE_HAS_NodeGetObjOffsetRot 1
#define MAXMCP_FACADE_HAS_MeshSetNormal 1
#define MAXMCP_FACADE_HAS_MeshSetFaceNormal 1
#define MAXMCP_FACADE_HAS_MeshGetStripNormal 1
#define MAXMCP_FACADE_HAS_MeshBaryCoords 1
#define MAXMCP_FACADE_HAS_PolyFaceBBox 1
#define MAXMCP_FACADE_HAS_PolyBBox 1
#define MAXMCP_FACADE_HAS_PolyComputeCenter 1
#define MAXMCP_FACADE_HAS_PolyComputeSafeCenter 1
#define MAXMCP_FACADE_HAS_PolyGetVertexNormal 1
#define MAXMCP_FACADE_HAS_PolyGetEdgeNormal 1
#define MAXMCP_FACADE_HAS_PolyGetFaceNormal 1
#define MAXMCP_FACADE_HAS_ControllerClearIKParam 1
#define MAXMCP_FACADE_HAS_ControllerRescaleTime 1
#define MAXMCP_FACADE_HAS_SceneSetStatusXYZ 1
#define MAXMCP_FACADE_HAS_SceneGetAnimRange 1
#define MAXMCP_FACADE_HAS_SceneGetDefaultRendererClassID 1
#define MAXMCP_FACADE_HAS_SceneSetDefaultRendererClassID 1
#define MAXMCP_FACADE_HAS_SceneZoomToBounds 1
#define MAXMCP_FACADE_HAS_SceneGetSelectionWorldBox 1
#define MAXMCP_FACADE_HAS_SceneSetViewportBGColor 1
#define MAXMCP_FACADE_HAS_SceneGetViewportBGColor 1
#define MAXMCP_FACADE_HAS_SceneGetAmbient 1
#define MAXMCP_FACADE_HAS_SceneGetLightTint 1
#define MAXMCP_FACADE_HAS_SceneSetLightTint 1
#define MAXMCP_FACADE_HAS_SceneGetLightLevel 1
#define MAXMCP_FACADE_HAS_SceneGetBackGround 1
#define MAXMCP_FACADE_HAS_SceneSetBackGround 1
#define MAXMCP_FACADE_HAS_Scene7GetPivotMode 1
#define MAXMCP_FACADE_HAS_Scene7GetAffectChildren 1
#define MAXMCP_FACADE_HAS_Scene7SetAffectChildren 1
#define MAXMCP_FACADE_HAS_Scene7ShouldContinueRenderOnError 1
#define MAXMCP_FACADE_HAS_Scene7IncrRenderActive 1
#define MAXMCP_FACADE_HAS_Scene7DecrRenderActive 1
#define MAXMCP_FACADE_HAS_Scene7XRefRenderEnd 1
#define MAXMCP_FACADE_HAS_Scene7OpenRenderDialog 1
#define MAXMCP_FACADE_HAS_Scene7CancelRenderDialog 1
#define MAXMCP_FACADE_HAS_Scene7CloseRenderDialog 1
#define MAXMCP_FACADE_HAS_Scene7CommitRenderDialogParameters 1
#define MAXMCP_FACADE_HAS_Scene7UpdateRenderDialogParameters 1
#define MAXMCP_FACADE_HAS_Scene7FlushAllTrackViewWindows 1
#define MAXMCP_FACADE_HAS_Scene7UnFlushAllTrackViewWindows 1
#define MAXMCP_FACADE_HAS_Scene7CloseAllTrackViewWindows 1
#define MAXMCP_FACADE_HAS_Scene7SelectedHistoryChanged 1
#define MAXMCP_FACADE_HAS_Scene7CmdPanelOpen 1
#define MAXMCP_FACADE_HAS_Scene7SuspendEditing 1
#define MAXMCP_FACADE_HAS_Scene7ResumeEditing 1
#define MAXMCP_FACADE_HAS_Scene7SuspendMotionEditing 1
#define MAXMCP_FACADE_HAS_Scene7ResumeMotionEditing 1
#define MAXMCP_FACADE_HAS_Scene7ReBuildSuperList 1
#define MAXMCP_FACADE_HAS_Scene7IsEditing 1
#define MAXMCP_FACADE_HAS_Scene7ChangeHistory 1
#define MAXMCP_FACADE_HAS_Scene7UpdateLockCheckObjectCounts 1
#define MAXMCP_FACADE_HAS_Scene7GetMAXIniFile 1
#define MAXMCP_FACADE_HAS_Scene7CloseAllSchematicViewWindows 1
#define MAXMCP_FACADE_HAS_Scene7FlushAllSchematicViewWindows 1
#define MAXMCP_FACADE_HAS_Scene7UnFlushAllSchematicViewWindows 1
#define MAXMCP_FACADE_HAS_Scene7EnableDrawing 1
#define MAXMCP_FACADE_HAS_Scene7SetSceneDisplayFlag 1
#define MAXMCP_FACADE_HAS_Scene7GetActiveMtlSlot 1
#define MAXMCP_FACADE_HAS_Scene7SetActiveMtlSlot 1
#define MAXMCP_FACADE_HAS_Scene7FlushMtlDlg 1
#define MAXMCP_FACADE_HAS_Scene7UnFlushMtlDlg 1
#define MAXMCP_FACADE_HAS_Scene7IsMtlDlgShowing 1
#define MAXMCP_FACADE_HAS_Scene7OpenMtlDlg 1
#define MAXMCP_FACADE_HAS_Scene7CloseMtlDlg 1
#define MAXMCP_FACADE_HAS_Scene7ResetAllViews 1
#define MAXMCP_FACADE_HAS_Scene7GetLockImageAspRatio 1
#define MAXMCP_FACADE_HAS_Scene7SetLockImageAspRatio 1
#define MAXMCP_FACADE_HAS_Scene7GetImageAspRatio 1
#define MAXMCP_FACADE_HAS_Scene7SetImageAspRatio 1
#define MAXMCP_FACADE_HAS_Scene7GetLockPixelAspRatio 1
#define MAXMCP_FACADE_HAS_Scene7SetLockPixelAspRatio 1
#define MAXMCP_FACADE_HAS_Scene7GetPixelAspRatio 1
#define MAXMCP_FACADE_HAS_Scene7SetPixelAspRatio 1
#define MAXMCP_FACADE_HAS_Scene7SetViewportGridVisible 1
#define MAXMCP_FACADE_HAS_Scene7ViewportInvalidate 1
#define MAXMCP_FACADE_HAS_Scene7ViewportInvalidateBkgImage 1
#define MAXMCP_FACADE_HAS_Scene7InvalidateAllViewportRects 1
#define MAXMCP_FACADE_HAS_Scene7RedrawViewportsNow 1
#define MAXMCP_FACADE_HAS_Scene7RedrawViewportsLater 1
#define MAXMCP_FACADE_HAS_Scene7SetActiveViewportRenderLevel 1
#define MAXMCP_FACADE_HAS_Scene7GetActiveViewportRenderLevel 1
#define MAXMCP_FACADE_HAS_Scene7SetActiveViewportShowEdgeFaces 1
#define MAXMCP_FACADE_HAS_Scene7GetActiveViewportShowEdgeFaces 1
#define MAXMCP_FACADE_HAS_Scene7SetActiveViewportTransparencyLevel 1
#define MAXMCP_FACADE_HAS_Scene7GetActiveViewportTransparencyLevel 1
#define MAXMCP_FACADE_HAS_Scene7GetDualPlanes 1
#define MAXMCP_FACADE_HAS_Scene7SetDualPlanes 1
#define MAXMCP_FACADE_HAS_Scene7SetTestOnlyFrozen 1
#define MAXMCP_FACADE_HAS_Scene7SetScaleMode 1
#define MAXMCP_FACADE_HAS_Scene7SetCenterMode 1
#define MAXMCP_FACADE_HAS_Scene7StartManipulateMode 1
#define MAXMCP_FACADE_HAS_Scene7EndManipulateMode 1
#define MAXMCP_FACADE_HAS_Scene7XRefSceneSetIgnoreFlag 1
#define MAXMCP_FACADE_HAS_Scene7UpdateSceneXRefState 1
#define MAXMCP_FACADE_HAS_Scene7GetSnapActive 1
#define MAXMCP_FACADE_HAS_Scene7SetSnapActive 1
#define MAXMCP_FACADE_HAS_Scene7GetSnapType 1
#define MAXMCP_FACADE_HAS_Scene7SetSnapType 1
#define MAXMCP_FACADE_HAS_Scene7ToggleASnap 1
#define MAXMCP_FACADE_HAS_Scene7TogglePSnap 1
#define MAXMCP_FACADE_HAS_Scene7SetGridSpacing 1
#define MAXMCP_FACADE_HAS_Scene7SetGridMajorLines 1
#define MAXMCP_FACADE_HAS_Scene7GetSnapAngle 1
#define MAXMCP_FACADE_HAS_Scene7SetSnapAngle 1
#define MAXMCP_FACADE_HAS_Scene7GetSnapPercent 1
#define MAXMCP_FACADE_HAS_Scene7SetSnapPercent 1
#define MAXMCP_FACADE_HAS_Scene7SetExpertMode 1
#define MAXMCP_FACADE_HAS_Scene7GetExpertMode 1
#define MAXMCP_FACADE_HAS_Scene7WriteCUIConfig 1
#define MAXMCP_FACADE_HAS_Scene7SaveCUIAs 1
#define MAXMCP_FACADE_HAS_Scene7LoadCUI 1
#define MAXMCP_FACADE_HAS_Scene7RevertToBackupCUI 1
#define MAXMCP_FACADE_HAS_Scene7ResetToFactoryDefaultCUI 1
#define MAXMCP_FACADE_HAS_Scene7GetGridIntens 1
#define MAXMCP_FACADE_HAS_Scene7SetGridIntens 1
#define MAXMCP_FACADE_HAS_Scene7GetWhiteOrigin 1
#define MAXMCP_FACADE_HAS_Scene7SetWhiteOrigin 1
#define MAXMCP_FACADE_HAS_Scene7GetUseGridColor 1
#define MAXMCP_FACADE_HAS_Scene7SetUseGridColor 1
#define MAXMCP_FACADE_HAS_Scene7UpdateColors 1
#define MAXMCP_FACADE_HAS_Scene7RepaintTimeSlider 1
#define MAXMCP_FACADE_HAS_Scene7StartAnimPlayback2 1
#define MAXMCP_FACADE_HAS_Scene7OpenEnvEffectsDialog 1
#define MAXMCP_FACADE_HAS_Scene7CloseEnvEffectsDialog 1
#define MAXMCP_FACADE_HAS_AnimClassID 1
#define MAXMCP_FACADE_HAS_AnimTestFlagBit 1
#define MAXMCP_FACADE_HAS_AnimSetFlagBit 1
#define MAXMCP_FACADE_HAS_AnimClearFlagBit 1
#define MAXMCP_FACADE_HAS_AnimFreeCaches 1
#define MAXMCP_FACADE_HAS_AnimNumSubs 1
#define MAXMCP_FACADE_HAS_AnimBypassTreeView 1
#define MAXMCP_FACADE_HAS_AnimBypassTrackBar 1
#define MAXMCP_FACADE_HAS_AnimBypassPropertyLevel 1
#define MAXMCP_FACADE_HAS_AnimInvisibleProperty 1
#define MAXMCP_FACADE_HAS_AnimGetSubAnimCurveColor 1
#define MAXMCP_FACADE_HAS_AnimCanCopyAnim 1
#define MAXMCP_FACADE_HAS_AnimCanMakeUnique 1
#define MAXMCP_FACADE_HAS_AnimHasSubElements 1
#define MAXMCP_FACADE_HAS_AnimRenderEnd 1
#define MAXMCP_FACADE_HAS_AnimEditTrack 1
#define MAXMCP_FACADE_HAS_AnimNumKeys 1
#define MAXMCP_FACADE_HAS_AnimGetKeyTime 1
#define MAXMCP_FACADE_HAS_AnimGetKeyIndex 1
#define MAXMCP_FACADE_HAS_AnimCopyKeysFromTime 1
#define MAXMCP_FACADE_HAS_AnimDeleteKeyAtTime 1
#define MAXMCP_FACADE_HAS_AnimIsKeyAtTime 1
#define MAXMCP_FACADE_HAS_AnimOpenTreeEntry 1
#define MAXMCP_FACADE_HAS_AnimCloseTreeEntry 1
#define MAXMCP_FACADE_HAS_AnimIsTreeEntryOpen 1
#define MAXMCP_FACADE_HAS_AnimSetSelInTrackView 1
#define MAXMCP_FACADE_HAS_AnimSetTrackViewSelSet 1
#define MAXMCP_FACADE_HAS_AnimGetTimeRange 1
#define MAXMCP_FACADE_HAS_AnimEditTimeRange 1
#define MAXMCP_FACADE_HAS_AnimDeleteTime 1
#define MAXMCP_FACADE_HAS_AnimReverseTime 1
#define MAXMCP_FACADE_HAS_AnimScaleTime 1
#define MAXMCP_FACADE_HAS_AnimInsertTime 1
#define MAXMCP_FACADE_HAS_AnimSupportTimeOperations 1
#define MAXMCP_FACADE_HAS_AnimDeleteKeys 1
#define MAXMCP_FACADE_HAS_AnimDeleteKeyByIndex 1
#define MAXMCP_FACADE_HAS_AnimSelectSubCurve 1
#define MAXMCP_FACADE_HAS_AnimSelectKeyByIndex 1
#define MAXMCP_FACADE_HAS_AnimIsKeySelected 1
#define MAXMCP_FACADE_HAS_AnimGetFlagKeyIndex 1
#define MAXMCP_FACADE_HAS_AnimNumSelKeys 1
#define MAXMCP_FACADE_HAS_AnimCloneSelectedKeys 1
#define MAXMCP_FACADE_HAS_AnimAddNewKey 1
#define MAXMCP_FACADE_HAS_AnimSelectCurve 1
#define MAXMCP_FACADE_HAS_AnimIsCurveSelected 1
#define MAXMCP_FACADE_HAS_AnimIsSubCurveSelected 1
#define MAXMCP_FACADE_HAS_AnimSetSelKeyCoords 1
#define MAXMCP_FACADE_HAS_AnimSubAnimSetKeyBufferPresent 1
#define MAXMCP_FACADE_HAS_AnimSetKeyBufferPresent 1
#define MAXMCP_FACADE_HAS_AnimSubAnimCommitSetKeyBuffer 1
#define MAXMCP_FACADE_HAS_AnimCommitSetKeyBuffer 1
#define MAXMCP_FACADE_HAS_AnimSubAnimRevertSetKeyBuffer 1
#define MAXMCP_FACADE_HAS_AnimRevertSetKeyBuffer 1
#define MAXMCP_FACADE_HAS_AnimIsAnimated 1
#define MAXMCP_FACADE_HAS_AnimCanCopySubTrack 1
#define MAXMCP_FACADE_HAS_AnimGetTrackVSpace 1
#define MAXMCP_FACADE_HAS_AnimTrackParamsType 1
#define MAXMCP_FACADE_HAS_AnimHasNoteTracks 1
#define MAXMCP_FACADE_HAS_AnimNumNoteTracks 1
#define MAXMCP_FACADE_HAS_AnimDeleteAllNoteTracks 1
#define MAXMCP_FACADE_HAS_AnimFreeAllBitmaps 1
#define MAXMCP_FACADE_HAS_AnimIsSubClassOf 1
#define MAXMCP_FACADE_HAS_AnimClearAllAppData 1
#define MAXMCP_FACADE_HAS_AnimMouseCycleCompleted 1
#define MAXMCP_FACADE_HAS_AnimMouseCycleStarted 1
#define MAXMCP_FACADE_HAS_AnimNumParamBlocks 1
#define MAXMCP_FACADE_HAS_AnimSvSetRefIndex 1
#define MAXMCP_FACADE_HAS_AnimAllocCustAttribContainer 1
#define MAXMCP_FACADE_HAS_AnimDeleteCustAttribContainer 1
#define MAXMCP_FACADE_HAS_ObjectIsRenderable 1
#define MAXMCP_FACADE_HAS_ObjectUsesWireColor 1
#define MAXMCP_FACADE_HAS_ObjectDoOwnSelectHilite 1
#define MAXMCP_FACADE_HAS_ObjectNormalAlignVector 1
#define MAXMCP_FACADE_HAS_ObjectCanCacheObject 1
#define MAXMCP_FACADE_HAS_ObjectWSStateInvalidate 1
#define MAXMCP_FACADE_HAS_ObjectIsWorldSpaceObject 1
#define MAXMCP_FACADE_HAS_ObjectGetWorldSpaceObjectNode 1
#define MAXMCP_FACADE_HAS_ObjectIsParticleSystem 1
#define MAXMCP_FACADE_HAS_ObjectTopologyChanged 1
#define MAXMCP_FACADE_HAS_ObjectIsDeformable 1
#define MAXMCP_FACADE_HAS_ObjectNumPoints 1
#define MAXMCP_FACADE_HAS_ObjectGetPoint 1
#define MAXMCP_FACADE_HAS_ObjectSetPoint 1
#define MAXMCP_FACADE_HAS_ObjectIsPointSelected 1
#define MAXMCP_FACADE_HAS_ObjectPointSelection 1
#define MAXMCP_FACADE_HAS_ObjectGetWeight 1
#define MAXMCP_FACADE_HAS_ObjectSetWeight 1
#define MAXMCP_FACADE_HAS_ObjectPointsWereChanged 1
#define MAXMCP_FACADE_HAS_ObjectNumMapsUsed 1
#define MAXMCP_FACADE_HAS_ObjectConvertToType 1
#define MAXMCP_FACADE_HAS_ObjectPreferredCollapseType 1
#define MAXMCP_FACADE_HAS_ObjectCollapseObject 1
#define MAXMCP_FACADE_HAS_ObjectGetSubselState 1
#define MAXMCP_FACADE_HAS_ObjectSetSubSelState 1
#define MAXMCP_FACADE_HAS_ObjectObjectValidity 1
#define MAXMCP_FACADE_HAS_ObjectIsBaseClassOwnedChannel 1
#define MAXMCP_FACADE_HAS_ObjectReduceCaches 1
#define MAXMCP_FACADE_HAS_ObjectIsConstObject 1
#define MAXMCP_FACADE_HAS_ObjectNumPipeBranches 1
#define MAXMCP_FACADE_HAS_ObjectGetPipeBranch 1
#define MAXMCP_FACADE_HAS_ObjectNumberOfContainedShapes 1
#define MAXMCP_FACADE_HAS_ObjectIsShapeObject 1
#define MAXMCP_FACADE_HAS_ObjectCheckObjectIntegrity 1
#define MAXMCP_FACADE_HAS_ObjectFindBaseObject 1
#define MAXMCP_FACADE_HAS_ObjectIsParamSurface 1
#define MAXMCP_FACADE_HAS_ObjectNumSurfaces 1
#define MAXMCP_FACADE_HAS_ObjectGetSurfacePoint 1
#define MAXMCP_FACADE_HAS_ObjectUseSelectionBrackets 1
#define MAXMCP_FACADE_HAS_ObjectIsManipulator 1
#define MAXMCP_FACADE_HAS_ObjectReduceDisplayCaches 1
#define MAXMCP_FACADE_HAS_ObjectStartStackEval 1
#define MAXMCP_FACADE_HAS_ObjectEndStackEval 1
#define MAXMCP_FACADE_HAS_PatchPatchObjectInit 1
#define MAXMCP_FACADE_HAS_PatchGetObjectDisplayRequirement 1
#define MAXMCP_FACADE_HAS_PatchSetChannelValidity 1
#define MAXMCP_FACADE_HAS_PatchTopologyChanged 1
#define MAXMCP_FACADE_HAS_PatchConvertValidity 1
#define MAXMCP_FACADE_HAS_PatchSetPoint 1
#define MAXMCP_FACADE_HAS_PatchPointsWereChanged 1
#define MAXMCP_FACADE_HAS_PatchDeleteThis 1
#define MAXMCP_FACADE_HAS_PatchFreeCaches 1
#define MAXMCP_FACADE_HAS_PatchRescaleWorldUnits 1
#define MAXMCP_FACADE_HAS_PatchPlugControllersSel 1
#define MAXMCP_FACADE_HAS_PatchAllocVertContArray 1
#define MAXMCP_FACADE_HAS_PatchAllocVecContArray 1
#define MAXMCP_FACADE_HAS_PatchAllocContArrays 1
#define MAXMCP_FACADE_HAS_PatchSetVertAnim 1
#define MAXMCP_FACADE_HAS_PatchSetVecAnim 1
#define MAXMCP_FACADE_HAS_PatchUpdatePatchMesh 1
#define MAXMCP_FACADE_HAS_PatchPrepareMesh 1
#define MAXMCP_FACADE_HAS_PatchShowLattice 1
#define MAXMCP_FACADE_HAS_PatchShowVerts 1
#define MAXMCP_FACADE_HAS_PatchSetShowLattice 1
#define MAXMCP_FACADE_HAS_PatchSetShowVerts 1
#define MAXMCP_FACADE_HAS_PatchSetMeshSteps 1
#define MAXMCP_FACADE_HAS_PatchGetMeshSteps 1
#define MAXMCP_FACADE_HAS_PatchSetMeshStepsRender 1
#define MAXMCP_FACADE_HAS_PatchGetMeshStepsRender 1
#define MAXMCP_FACADE_HAS_PatchSetRelax 1
#define MAXMCP_FACADE_HAS_PatchSetRelaxViewports 1
#define MAXMCP_FACADE_HAS_PatchSetRelaxValue 1
#define MAXMCP_FACADE_HAS_PatchSetRelaxIter 1
#define MAXMCP_FACADE_HAS_PatchSetRelaxBoundary 1
#define MAXMCP_FACADE_HAS_PatchSetRelaxSaddle 1
#define MAXMCP_FACADE_HAS_PatchSetShowInterior 1
#define MAXMCP_FACADE_HAS_PatchGetShowInterior 1
#define MAXMCP_FACADE_HAS_PatchSetUsePatchNormals 1
#define MAXMCP_FACADE_HAS_PatchGetUsePatchNormals 1
#define MAXMCP_FACADE_HAS_PatchSetAdaptive 1
#define MAXMCP_FACADE_HAS_PatchGetAdaptive 1
#define MAXMCP_FACADE_HAS_PatchGetViewTessNormals 1
#define MAXMCP_FACADE_HAS_PatchSetViewTessNormals 1
#define MAXMCP_FACADE_HAS_PatchGetProdTessNormals 1
#define MAXMCP_FACADE_HAS_PatchSetProdTessNormals 1
#define MAXMCP_FACADE_HAS_PatchGetViewTessWeld 1
#define MAXMCP_FACADE_HAS_PatchSetViewTessWeld 1
#define MAXMCP_FACADE_HAS_PatchGetProdTessWeld 1
#define MAXMCP_FACADE_HAS_PatchSetProdTessWeld 1
#define MAXMCP_FACADE_HAS_PatchInvalidateRelaxedMesh 1
#define MAXMCP_FACADE_HAS_PatchGetSubobjectLevel 1
#define MAXMCP_FACADE_HAS_PatchGetSubobjectType 1
#define MAXMCP_FACADE_HAS_PatchSetSubobjectLevel 1
#define MAXMCP_FACADE_HAS_PatchShowEndResultChanged 1
#define MAXMCP_FACADE_HAS_PatchClearSelection 1
#define MAXMCP_FACADE_HAS_PatchSelectAll 1
#define MAXMCP_FACADE_HAS_PatchInvertSelection 1
#define MAXMCP_FACADE_HAS_PatchPatchSelChanged 1
#define MAXMCP_FACADE_HAS_PatchInvalidateSurfaceUI 1
#define MAXMCP_FACADE_HAS_PatchInvalidateOpsUI 1
#define MAXMCP_FACADE_HAS_PatchChangeRememberedPatch 1
#define MAXMCP_FACADE_HAS_PatchChangeSelPatches 1
#define MAXMCP_FACADE_HAS_PatchSetRememberedPatchType 1
#define MAXMCP_FACADE_HAS_PatchChangeRememberedVert 1
#define MAXMCP_FACADE_HAS_PatchChangeSelVerts 1
#define MAXMCP_FACADE_HAS_PatchSetRememberedVertType 1
#define MAXMCP_FACADE_HAS_PatchTransformStart 1
#define MAXMCP_FACADE_HAS_PatchTransformFinish 1
#define MAXMCP_FACADE_HAS_PatchTransformCancel 1
#define MAXMCP_FACADE_HAS_PatchSetupNamedSelDropDown 1
#define MAXMCP_FACADE_HAS_PatchNSCopy 1
#define MAXMCP_FACADE_HAS_PatchNSPaste 1
#define MAXMCP_FACADE_HAS_PatchRefreshSelType 1
#define MAXMCP_FACADE_HAS_PatchSetNumSelLabel 1
#define MAXMCP_FACADE_HAS_PatchSetSelDlgEnables 1
#define MAXMCP_FACADE_HAS_PatchSetOpsDlgEnables 1
#define MAXMCP_FACADE_HAS_PatchSetSurfDlgEnables 1
#define MAXMCP_FACADE_HAS_PatchGetAttachMat 1
#define MAXMCP_FACADE_HAS_PatchSetAttachMat 1
#define MAXMCP_FACADE_HAS_PatchGetCondenseMat 1
#define MAXMCP_FACADE_HAS_PatchSetCondenseMat 1
#define MAXMCP_FACADE_HAS_PatchDoDeleteSelected 1
#define MAXMCP_FACADE_HAS_PatchDoBreak 1
#define MAXMCP_FACADE_HAS_PatchResolveTopoChanges 1
#define MAXMCP_FACADE_HAS_PatchCreateContArrays 1
#define MAXMCP_FACADE_HAS_PatchSynchContArrays 1
#define MAXMCP_FACADE_HAS_PatchGetSelMatIndex 1
#define MAXMCP_FACADE_HAS_PatchSetSelMatIndex 1
#define MAXMCP_FACADE_HAS_PatchSelectByMat 1
#define MAXMCP_FACADE_HAS_PatchSelectBySmoothGroup 1
#define MAXMCP_FACADE_HAS_PatchSetSelSmoothBits 1
#define MAXMCP_FACADE_HAS_PatchSetPropagate 1
#define MAXMCP_FACADE_HAS_PatchGetPropagate 1
#define MAXMCP_FACADE_HAS_PatchDoPatchAdd 1
#define MAXMCP_FACADE_HAS_PatchDoSubdivide 1
#define MAXMCP_FACADE_HAS_PatchDoPatchDetach 1
#define MAXMCP_FACADE_HAS_PatchDoVertWeld 1
#define MAXMCP_FACADE_HAS_PatchDoEdgeWeld 1
#define MAXMCP_FACADE_HAS_PatchStartCopyTangentMode 1
#define MAXMCP_FACADE_HAS_PatchStartPasteTangentMode 1
#define MAXMCP_FACADE_HAS_PatchStartPasteTangent 1
#define MAXMCP_FACADE_HAS_PatchEndPasteTangent 1
#define MAXMCP_FACADE_HAS_PatchDoHide 1
#define MAXMCP_FACADE_HAS_PatchDoUnHide 1
#define MAXMCP_FACADE_HAS_PatchDoPatchHide 1
#define MAXMCP_FACADE_HAS_PatchDoVertHide 1
#define MAXMCP_FACADE_HAS_PatchDoEdgeHide 1
#define MAXMCP_FACADE_HAS_PatchDoAddHook 1
#define MAXMCP_FACADE_HAS_PatchDoRemoveHook 1
#define MAXMCP_FACADE_HAS_PatchDoExtrude 1
#define MAXMCP_FACADE_HAS_PatchBeginExtrude 1
#define MAXMCP_FACADE_HAS_PatchEndExtrude 1
#define MAXMCP_FACADE_HAS_PatchExtrude 1
#define MAXMCP_FACADE_HAS_PatchDoFlipNormals 1
#define MAXMCP_FACADE_HAS_PatchDoUnifyNormals 1
#define MAXMCP_FACADE_HAS_PatchDoBevel 1
#define MAXMCP_FACADE_HAS_PatchBeginBevel 1
#define MAXMCP_FACADE_HAS_PatchEndBevel 1
#define MAXMCP_FACADE_HAS_PatchBevel 1
#define MAXMCP_FACADE_HAS_PatchDoPatchSmooth 1
#define MAXMCP_FACADE_HAS_PatchCreatePatch 1
#define MAXMCP_FACADE_HAS_PatchGetSelLevel 1
#define MAXMCP_FACADE_HAS_PatchSetSelLevel 1
#define MAXMCP_FACADE_HAS_PatchLocalDataChanged 1
#define MAXMCP_FACADE_HAS_PatchSetVertColor 1
#define MAXMCP_FACADE_HAS_PatchSetPatchColor 1
#define MAXMCP_FACADE_HAS_PatchChangeMappingTypeLinear 1
#define MAXMCP_FACADE_HAS_PatchShrinkSelection 1
#define MAXMCP_FACADE_HAS_PatchGrowSelection 1
#define MAXMCP_FACADE_HAS_PatchSelectEdgeRing 1
#define MAXMCP_FACADE_HAS_PatchSelectEdgeLoop 1
#define MAXMCP_FACADE_HAS_PatchSelectOpenEdges 1
#define MAXMCP_FACADE_HAS_PatchDoCreateShape 1
#define MAXMCP_FACADE_HAS_PatchUseEdgeDists 1
#define MAXMCP_FACADE_HAS_PatchSetUseEdgeDists 1
#define MAXMCP_FACADE_HAS_PatchUseSoftSelections 1
#define MAXMCP_FACADE_HAS_PatchSetUseSoftSelections 1
#define MAXMCP_FACADE_HAS_PatchInvalidateVertexWeights 1
#define MAXMCP_FACADE_HAS_PatchToggleShadedFaces 1
#define MAXMCP_FACADE_HAS_PatchUpdateVertexDists 1
#define MAXMCP_FACADE_HAS_PatchUpdateEdgeDists 1
#define MAXMCP_FACADE_HAS_PatchUpdateVertexWeights 1
#define MAXMCP_FACADE_HAS_SplineSplineShapeInit 1
#define MAXMCP_FACADE_HAS_SplineTransformStart 1
#define MAXMCP_FACADE_HAS_SplineTransformFinish 1
#define MAXMCP_FACADE_HAS_SplineTransformCancel 1
#define MAXMCP_FACADE_HAS_SplineSetupNamedSelDropDown 1
#define MAXMCP_FACADE_HAS_SplineNSCopy 1
#define MAXMCP_FACADE_HAS_SplineNSPaste 1
#define MAXMCP_FACADE_HAS_SplineSetChannelValidity 1
#define MAXMCP_FACADE_HAS_SplineSetPoint 1
#define MAXMCP_FACADE_HAS_SplinePointsWereChanged 1
#define MAXMCP_FACADE_HAS_SplineDeleteThis 1
#define MAXMCP_FACADE_HAS_SplineRescaleWorldUnits 1
#define MAXMCP_FACADE_HAS_SplineCreateContArray 1
#define MAXMCP_FACADE_HAS_SplineSynchContArray 1
#define MAXMCP_FACADE_HAS_SplineAllocContArray 1
#define MAXMCP_FACADE_HAS_SplineInsertPointConts 1
#define MAXMCP_FACADE_HAS_SplineReversePointConts 1
#define MAXMCP_FACADE_HAS_SplineNullPointConts 1
#define MAXMCP_FACADE_HAS_SplineNullPolyPointConts 1
#define MAXMCP_FACADE_HAS_SplinePlugControllersSel 1
#define MAXMCP_FACADE_HAS_SplineSetPointAnim 1
#define MAXMCP_FACADE_HAS_SplineGetSubobjectLevel 1
#define MAXMCP_FACADE_HAS_SplineSetSubobjectLevel 1
#define MAXMCP_FACADE_HAS_SplineClearSelection 1
#define MAXMCP_FACADE_HAS_SplineSelectAll 1
#define MAXMCP_FACADE_HAS_SplineInvertSelection 1
#define MAXMCP_FACADE_HAS_SplineShowEndResultChanged 1
#define MAXMCP_FACADE_HAS_SplineBeginOutlineMove 1
#define MAXMCP_FACADE_HAS_SplineBeginFilletMove 1
#define MAXMCP_FACADE_HAS_SplineBeginChamferMove 1
#define MAXMCP_FACADE_HAS_SplineOutlineMove 1
#define MAXMCP_FACADE_HAS_SplineFilletMove 1
#define MAXMCP_FACADE_HAS_SplineChamferMove 1
#define MAXMCP_FACADE_HAS_SplineEndMoveModes 1
#define MAXMCP_FACADE_HAS_SplineEndOutlineMove 1
#define MAXMCP_FACADE_HAS_SplineEndFilletMove 1
#define MAXMCP_FACADE_HAS_SplineEndChamferMove 1
#define MAXMCP_FACADE_HAS_SplineStartOutlineMode 1
#define MAXMCP_FACADE_HAS_SplineStartFilletMode 1
#define MAXMCP_FACADE_HAS_SplineStartChamferMode 1
#define MAXMCP_FACADE_HAS_SplineStartSegBreakMode 1
#define MAXMCP_FACADE_HAS_SplineStartSegRefineMode 1
#define MAXMCP_FACADE_HAS_SplineStartCrossInsertMode 1
#define MAXMCP_FACADE_HAS_SplineStartVertConnectMode 1
#define MAXMCP_FACADE_HAS_SplineStartVertInsertMode 1
#define MAXMCP_FACADE_HAS_SplineEndVertInsert 1
#define MAXMCP_FACADE_HAS_SplineStartCreateLineMode 1
#define MAXMCP_FACADE_HAS_SplineEndCreateLine 1
#define MAXMCP_FACADE_HAS_SplineStartCrossSectionMode 1
#define MAXMCP_FACADE_HAS_SplineStartCrossSection 1
#define MAXMCP_FACADE_HAS_SplineEndCrossSection 1
#define MAXMCP_FACADE_HAS_SplineStartBooleanMode 1
#define MAXMCP_FACADE_HAS_SplineDoBoolean 1
#define MAXMCP_FACADE_HAS_SplineStartTrimMode 1
#define MAXMCP_FACADE_HAS_SplineStartExtendMode 1
#define MAXMCP_FACADE_HAS_SplineGetAttachMat 1
#define MAXMCP_FACADE_HAS_SplineSetAttachMat 1
#define MAXMCP_FACADE_HAS_SplineGetCondenseMat 1
#define MAXMCP_FACADE_HAS_SplineSetCondenseMat 1
#define MAXMCP_FACADE_HAS_SplineDoVertBreak 1
#define MAXMCP_FACADE_HAS_SplineDoVertWeld 1
#define MAXMCP_FACADE_HAS_SplineDoMakeFirst 1
#define MAXMCP_FACADE_HAS_SplineDoVertDelete 1
#define MAXMCP_FACADE_HAS_SplineDoSegDelete 1
#define MAXMCP_FACADE_HAS_SplineDoSegDetach 1
#define MAXMCP_FACADE_HAS_SplineDoSegDivide 1
#define MAXMCP_FACADE_HAS_SplineDoPolyClose 1
#define MAXMCP_FACADE_HAS_SplineDoPolyDetach 1
#define MAXMCP_FACADE_HAS_SplineDoPolyMirror 1
#define MAXMCP_FACADE_HAS_SplineDoPolyDelete 1
#define MAXMCP_FACADE_HAS_SplineDoPolyReverse 1
#define MAXMCP_FACADE_HAS_SplineDoPolyExplode 1
#define MAXMCP_FACADE_HAS_SplineDoExplodeToObjects 1
#define MAXMCP_FACADE_HAS_SplineSetBoolOperation 1
#define MAXMCP_FACADE_HAS_SplineSetMirrorOperation 1
#define MAXMCP_FACADE_HAS_SplineGetBoolOperation 1
#define MAXMCP_FACADE_HAS_SplineGetMirrorOperation 1
#define MAXMCP_FACADE_HAS_SplineSetBooleanButton 1
#define MAXMCP_FACADE_HAS_SplineSetMirrorButton 1
#define MAXMCP_FACADE_HAS_SplineChangeSelVerts 1
#define MAXMCP_FACADE_HAS_SplineChangeRememberedVert 1
#define MAXMCP_FACADE_HAS_SplineSetRememberedVertType 1
#define MAXMCP_FACADE_HAS_SplineChangeSelSegs 1
#define MAXMCP_FACADE_HAS_SplineChangeRememberedSeg 1
#define MAXMCP_FACADE_HAS_SplineSetRememberedSegType 1
#define MAXMCP_FACADE_HAS_SplineChangeSelPolys 1
#define MAXMCP_FACADE_HAS_SplineChangeRememberedPoly 1
#define MAXMCP_FACADE_HAS_SplineSetRememberedPolyType 1
#define MAXMCP_FACADE_HAS_SplineDeleteSpline 1
#define MAXMCP_FACADE_HAS_SplineReverse 1
#define MAXMCP_FACADE_HAS_SplineDeleteKnot 1
#define MAXMCP_FACADE_HAS_SplineMakeFirst 1
#define MAXMCP_FACADE_HAS_SplineSetOptimize 1
#define MAXMCP_FACADE_HAS_SplineSetAdaptive 1
#define MAXMCP_FACADE_HAS_SplineSetSteps 1
#define MAXMCP_FACADE_HAS_SplineRecordTopologyTags 1
#define MAXMCP_FACADE_HAS_SplineRecordTopology 1
#define MAXMCP_FACADE_HAS_SplineRefreshSelType 1
#define MAXMCP_FACADE_HAS_SplineUpdateSelectDisplay 1
#define MAXMCP_FACADE_HAS_SplineSetSelDlgEnables 1
#define MAXMCP_FACADE_HAS_SplineSetOpsDlgEnables 1
#define MAXMCP_FACADE_HAS_SplineSetSurfDlgEnables 1
#define MAXMCP_FACADE_HAS_SplineSelectionChanged 1
#define MAXMCP_FACADE_HAS_SplineSetFCLimit 1
#define MAXMCP_FACADE_HAS_SplineGetSelMatIndex 1
#define MAXMCP_FACADE_HAS_SplineSetSelMatIndex 1
#define MAXMCP_FACADE_HAS_SplineSelectByMat 1
#define MAXMCP_FACADE_HAS_SplineInvalidateSurfaceUI 1
#define MAXMCP_FACADE_HAS_SplineStartBindMode 1
#define MAXMCP_FACADE_HAS_SplineDoBind 1
#define MAXMCP_FACADE_HAS_SplineDoUnBind 1
#define MAXMCP_FACADE_HAS_SplineDoHide 1
#define MAXMCP_FACADE_HAS_SplineDoUnhide 1
#define MAXMCP_FACADE_HAS_SplineDoCycleVerts 1
#define MAXMCP_FACADE_HAS_SplineStartRefineConnectMode 1
#define MAXMCP_FACADE_HAS_SplineEndRefineConnectMode 1
#define MAXMCP_FACADE_HAS_SplineDoVertFuse 1
#define MAXMCP_FACADE_HAS_SplineStartCopyTangentMode 1
#define MAXMCP_FACADE_HAS_SplineStartPasteTangentMode 1
#define MAXMCP_FACADE_HAS_SplineStartPasteTangent 1
#define MAXMCP_FACADE_HAS_SplineEndPasteTangent 1
#define MAXMCP_FACADE_HAS_SplineGetSelLevel 1
#define MAXMCP_FACADE_HAS_SplineSetSelLevel 1
#define MAXMCP_FACADE_HAS_SplineLocalDataChanged 1
#define MAXMCP_FACADE_HAS_SplineSelectBySegment 1
#define MAXMCP_FACADE_HAS_SplineSelectBySpline 1
#define MAXMCP_FACADE_HAS_SplineInvalidateGeomCache 1
#define MAXMCP_FACADE_HAS_SplineUseEdgeDists 1
#define MAXMCP_FACADE_HAS_SplineSetUseEdgeDists 1
#define MAXMCP_FACADE_HAS_SplineUseSoftSelections 1
#define MAXMCP_FACADE_HAS_SplineSetUseSoftSelections 1
#define MAXMCP_FACADE_HAS_SplineInvalidateVertexWeights 1
#define MAXMCP_FACADE_HAS_SplineUpdateVertexDists 1
#define MAXMCP_FACADE_HAS_SplineUpdateEdgeDists 1
#define MAXMCP_FACADE_HAS_SplineUpdateVertexWeights 1
#define MAXMCP_FACADE_HAS_PatchMeshSetNumVerts 1
#define MAXMCP_FACADE_HAS_PatchMeshSetNumVecs 1
#define MAXMCP_FACADE_HAS_PatchMeshSetNumPatches 1
#define MAXMCP_FACADE_HAS_PatchMeshSetNumEdges 1
#define MAXMCP_FACADE_HAS_PatchMeshGetNumMapVerts 1
#define MAXMCP_FACADE_HAS_PatchMeshSetPatchMtlIndex 1
#define MAXMCP_FACADE_HAS_PatchMeshBuildLinkages 1
#define MAXMCP_FACADE_HAS_PatchMeshComputeInteriors 1
#define MAXMCP_FACADE_HAS_PatchMeshComputeAux 1
#define MAXMCP_FACADE_HAS_PatchMeshBuildBoundingBox 1
#define MAXMCP_FACADE_HAS_PatchMeshInvalidateGeomCache 1
#define MAXMCP_FACADE_HAS_PatchMeshInvalidateMesh 1
#define MAXMCP_FACADE_HAS_PatchMeshInvalidateRelaxedMesh 1
#define MAXMCP_FACADE_HAS_PatchMeshFreeAll 1
#define MAXMCP_FACADE_HAS_PatchMeshApplyConstraints 1
#define MAXMCP_FACADE_HAS_PatchMeshSetMeshSteps 1
#define MAXMCP_FACADE_HAS_PatchMeshGetMeshSteps 1
#define MAXMCP_FACADE_HAS_PatchMeshSetMeshStepsRender 1
#define MAXMCP_FACADE_HAS_PatchMeshGetMeshStepsRender 1
#define MAXMCP_FACADE_HAS_PatchMeshSetShowInterior 1
#define MAXMCP_FACADE_HAS_PatchMeshGetShowInterior 1
#define MAXMCP_FACADE_HAS_PatchMeshSetUsePatchNormals 1
#define MAXMCP_FACADE_HAS_PatchMeshGetUsePatchNormals 1
#define MAXMCP_FACADE_HAS_PatchMeshSetAdaptive 1
#define MAXMCP_FACADE_HAS_PatchMeshGetAdaptive 1
#define MAXMCP_FACADE_HAS_PatchMeshGetViewTessNormals 1
#define MAXMCP_FACADE_HAS_PatchMeshSetViewTessNormals 1
#define MAXMCP_FACADE_HAS_PatchMeshGetProdTessNormals 1
#define MAXMCP_FACADE_HAS_PatchMeshSetProdTessNormals 1
#define MAXMCP_FACADE_HAS_PatchMeshGetViewTessWeld 1
#define MAXMCP_FACADE_HAS_PatchMeshSetViewTessWeld 1
#define MAXMCP_FACADE_HAS_PatchMeshGetProdTessWeld 1
#define MAXMCP_FACADE_HAS_PatchMeshSetProdTessWeld 1
#define MAXMCP_FACADE_HAS_PatchMeshGetEdge 1
#define MAXMCP_FACADE_HAS_PatchMeshGetPatches 1
#define MAXMCP_FACADE_HAS_PatchMeshGetEdges 1
#define MAXMCP_FACADE_HAS_PatchMeshGetVectors 1
#define MAXMCP_FACADE_HAS_PatchMeshSetNumMaps 1
#define MAXMCP_FACADE_HAS_PatchMeshSetMapSupport 1
#define MAXMCP_FACADE_HAS_PatchMeshRecordTopologyTags 1
#define MAXMCP_FACADE_HAS_PatchMeshWeld 1
#define MAXMCP_FACADE_HAS_PatchMeshSubdivide 1
#define MAXMCP_FACADE_HAS_PatchMeshWeldEdges 1
#define MAXMCP_FACADE_HAS_PatchMeshCreateExtrusion 1
#define MAXMCP_FACADE_HAS_PatchMeshBuildPatchNormals 1
#define MAXMCP_FACADE_HAS_PatchMeshInvalidatePatchNormals 1
#define MAXMCP_FACADE_HAS_PatchMeshMoveNormal 1
#define MAXMCP_FACADE_HAS_PatchMeshFlipPatchNormal 1
#define MAXMCP_FACADE_HAS_PatchMeshUnifyNormals 1
#define MAXMCP_FACADE_HAS_PatchMeshCreateBevel 1
#define MAXMCP_FACADE_HAS_PatchMeshBevel 1
#define MAXMCP_FACADE_HAS_PatchMeshChangePatchInterior 1
#define MAXMCP_FACADE_HAS_PatchMeshChangeVertType 1
#define MAXMCP_FACADE_HAS_PatchMeshShrinkSelection 1
#define MAXMCP_FACADE_HAS_PatchMeshGrowSelection 1
#define MAXMCP_FACADE_HAS_PatchMeshPrepareMesh 1
#define MAXMCP_FACADE_HAS_PatchMeshPrepareUnrelaxedMesh 1
#define MAXMCP_FACADE_HAS_PatchMeshAutoSmooth 1
#define MAXMCP_FACADE_HAS_PatchMeshChangePatchToLinearMapping 1
#define MAXMCP_FACADE_HAS_PatchMeshChangePatchToCurvedMapping 1
#define MAXMCP_FACADE_HAS_PatchMeshArePatchesLinearMapped 1
#define MAXMCP_FACADE_HAS_PatchMeshArePatchesCurvedMapped 1
#define MAXMCP_FACADE_HAS_PatchMeshSingleEdgesOnly 1
#define MAXMCP_FACADE_HAS_PatchMeshSetVertexWeightCount 1
#define MAXMCP_FACADE_HAS_PatchMeshSetVertexWeight 1
#define MAXMCP_FACADE_HAS_PatchMeshSupportVSelectionWeights 1
#define MAXMCP_FACADE_HAS_PatchMeshVertexWeightSelectLevel 1
#define MAXMCP_FACADE_HAS_PatchMeshUseEdgeDists 1
#define MAXMCP_FACADE_HAS_PatchMeshSetUseEdgeDists 1
#define MAXMCP_FACADE_HAS_PatchMeshEdgeDist 1
#define MAXMCP_FACADE_HAS_PatchMeshSetEdgeDist 1
#define MAXMCP_FACADE_HAS_PatchMeshUseSoftSelections 1
#define MAXMCP_FACADE_HAS_PatchMeshSetUseSoftSelections 1
#define MAXMCP_FACADE_HAS_PatchMeshAffectBackface 1
#define MAXMCP_FACADE_HAS_PatchMeshSetAffectBackface 1
#define MAXMCP_FACADE_HAS_PatchMeshFalloff 1
#define MAXMCP_FACADE_HAS_PatchMeshSetFalloff 1
#define MAXMCP_FACADE_HAS_PatchMeshPinch 1
#define MAXMCP_FACADE_HAS_PatchMeshSetPinch 1
#define MAXMCP_FACADE_HAS_PatchMeshBubble 1
#define MAXMCP_FACADE_HAS_PatchMeshSetBubble 1
#define MAXMCP_FACADE_HAS_PatchMeshInvalidateVertexWeights 1
#define MAXMCP_FACADE_HAS_PatchMeshUpdateVertexDists 1
#define MAXMCP_FACADE_HAS_PatchMeshUpdateEdgeDists 1
#define MAXMCP_FACADE_HAS_PatchMeshUpdateVertexWeights 1
#define MAXMCP_FACADE_HAS_MeshDeleteVertSet 1
#define MAXMCP_FACADE_HAS_MeshBreakVerts 1
#define MAXMCP_FACADE_HAS_MeshCloneFaces 1
#define MAXMCP_FACADE_HAS_PolyVertexSelect 1
#define MAXMCP_FACADE_HAS_PolyEdgeSelect 1
#define MAXMCP_FACADE_HAS_PolyFaceSelect 1
#define MAXMCP_FACADE_HAS_PolyOptimizeSmoothingGroups 1
#define MAXMCP_FACADE_HAS_NodeSetUserPropString 1
#define MAXMCP_FACADE_HAS_NodeSetUserPropInt 1
#define MAXMCP_FACADE_HAS_NodeSetUserPropFloat 1
#define MAXMCP_FACADE_HAS_NodeSetUserPropBool 1
#define MAXMCP_FACADE_HAS_NodeUserPropExists 1
#define MAXMCP_FACADE_HAS_ScenePushPrompt 1
#define MAXMCP_FACADE_HAS_SceneReplacePrompt 1
#define MAXMCP_FACADE_HAS_SceneDisplayTempPrompt 1
#define MAXMCP_FACADE_HAS_SceneProgressUpdate 1
#define MAXMCP_FACADE_HAS_SceneAppendSubObjectNamedSelSet 1
#define MAXMCP_FACADE_HAS_SceneSetCurNamedSelSet 1
#define MAXMCP_FACADE_HAS_SceneLoadFromFile 1
#define MAXMCP_FACADE_HAS_SceneSaveToFile 1
#define MAXMCP_FACADE_HAS_SceneGetINodeByName 1
#define MAXMCP_FACADE_HAS_SceneCanImportFile 1
#define MAXMCP_FACADE_HAS_SceneIsMaxFile 1
#define MAXMCP_FACADE_HAS_SceneIsInternetCachedFile 1
#define MAXMCP_FACADE_HAS_SceneCanImportBitmap 1
#define MAXMCP_FACADE_HAS_Scene7BringTrackViewWindowToTop 1
#define MAXMCP_FACADE_HAS_Scene7AppendToCurFilePath 1
#define MAXMCP_FACADE_HAS_Scene7LoadCUIConfig 1
#define MAXMCP_FACADE_HAS_SplineDeletePointConts 1
#define MAXMCP_FACADE_HAS_MeshWeldCollinear 1
#define MAXMCP_FACADE_HAS_MeshFindOpenEdges 1
#define MAXMCP_FACADE_HAS_PolySelectEdgeLoop 1
#define MAXMCP_FACADE_HAS_PolySelectEdgeRing 1
#define MAXMCP_FACADE_HAS_PolyGetVerticesByFlag 1
#define MAXMCP_FACADE_HAS_PolyGetEdgesByFlag 1
#define MAXMCP_FACADE_HAS_PolyGetFacesByFlag 1
#define MAXMCP_FACADE_HAS_NodeGetUserPropBuffer 1
#define MAXMCP_FACADE_HAS_NodeGetUserPropString 1
#define MAXMCP_FACADE_HAS_SceneMakeNameUnique 1
#define MAXMCP_FACADE_HAS_Scene7GetCurRefCoordSysName 1
#define MAXMCP_FACADE_HAS_AnimGetClassName 1
#define MAXMCP_FACADE_HAS_AnimGetKeySelState 1
#define MAXMCP_FACADE_HAS_ObjectInitNodeName 1
#define MAXMCP_FACADE_HAS_PatchActivateSubSelSet 1
#define MAXMCP_FACADE_HAS_PatchNewSetFromCurSel 1
#define MAXMCP_FACADE_HAS_PatchRemoveSubSelSet 1
#define MAXMCP_FACADE_HAS_PatchSetNamedSelSetName 1
#define MAXMCP_FACADE_HAS_SplineInitNodeName 1
#define MAXMCP_FACADE_HAS_SplineActivateSubSelSet 1
#define MAXMCP_FACADE_HAS_SplineNewSetFromCurSel 1
#define MAXMCP_FACADE_HAS_SplineRemoveSubSelSet 1
#define MAXMCP_FACADE_HAS_SplineSetNamedSelSetName 1
#define MAXMCP_FACADE_HAS_PatchMeshSelectEdgeRing 1
#define MAXMCP_FACADE_HAS_PatchMeshSelectEdgeLoop 1
#define MAXMCP_FACADE_HAS_SceneSetActiveViewport 1
#define MAXMCP_FACADE_HAS_SceneGetMAXHWnd 1
#define MAXMCP_FACADE_HAS_SceneMakeExtendedViewportActive 1
#define MAXMCP_FACADE_HAS_SceneRegisterDlgWnd 1
#define MAXMCP_FACADE_HAS_SceneUnRegisterDlgWnd 1
#define MAXMCP_FACADE_HAS_SceneDeleteRollupPage 1
#define MAXMCP_FACADE_HAS_SceneFileOpenMatLib 1
#define MAXMCP_FACADE_HAS_SceneFileSaveMatLib 1
#define MAXMCP_FACADE_HAS_SceneFileSaveAsMatLib 1
#define MAXMCP_FACADE_HAS_SceneRAMPlayer 1
#define MAXMCP_FACADE_HAS_Scene7GetStatusPanelHWnd 1
#define MAXMCP_FACADE_HAS_Scene7SetListenerMiniHWnd 1
#define MAXMCP_FACADE_HAS_Scene7GetListenerMiniHWnd 1
#define MAXMCP_FACADE_HAS_Scene7GetViewPanelHWnd 1
#define MAXMCP_FACADE_HAS_NodeGetVisibility 1
#define MAXMCP_FACADE_HAS_NodeGetLocalVisibility 1
#define MAXMCP_FACADE_HAS_PatchGetVertColor 1
#define MAXMCP_FACADE_HAS_PatchGetPatchColor 1
#define MAXMCP_FACADE_HAS_MeshBuildTransformedBoundingBox 1
#define MAXMCP_FACADE_HAS_MeshApplyUVWMap 1
#define MAXMCP_FACADE_HAS_PolyGetVertexSpace 1
#define MAXMCP_FACADE_HAS_NodeGetNodeTM 1
#define MAXMCP_FACADE_HAS_NodeSetNodeTM 1
#define MAXMCP_FACADE_HAS_NodeGetObjectTM 1
#define MAXMCP_FACADE_HAS_NodeGetObjTMBeforeWSM 1
#define MAXMCP_FACADE_HAS_NodeGetObjTMAfterWSM 1
#define MAXMCP_FACADE_HAS_NodeGetParentTM 1
#define MAXMCP_FACADE_HAS_NodeGetTargetTM 1
#define MAXMCP_FACADE_HAS_NodeMove 1
#define MAXMCP_FACADE_HAS_NodeRotate 1
#define MAXMCP_FACADE_HAS_NodeScale 1
#define MAXMCP_FACADE_HAS_NodeGetStretchTM 1
#define MAXMCP_FACADE_HAS_ControllerSubMove 1
#define MAXMCP_FACADE_HAS_ControllerSubRotate 1
#define MAXMCP_FACADE_HAS_ControllerSubScale 1
#define MAXMCP_FACADE_HAS_SceneNonMouseCreate 1
#define MAXMCP_FACADE_HAS_SceneNonMouseCreateFinish 1
#define MAXMCP_FACADE_HAS_ObjectApplyUVWMap 1
#define MAXMCP_FACADE_HAS_ObjectGetContainedShapeMatrix 1
#define MAXMCP_FACADE_HAS_PatchApplyUVWMap 1
#define MAXMCP_FACADE_HAS_PatchMove 1
#define MAXMCP_FACADE_HAS_PatchRotate 1
#define MAXMCP_FACADE_HAS_PatchScale 1
#define MAXMCP_FACADE_HAS_SplineMove 1
#define MAXMCP_FACADE_HAS_SplineRotate 1
#define MAXMCP_FACADE_HAS_SplineScale 1
#define MAXMCP_FACADE_HAS_PatchMeshApplyUVWMap 1
#define MAXMCP_FACADE_HAS_PatchMeshTransform 1
#define MAXMCP_FACADE_HAS_EPolyInvalidateSoftSelectionCache 1
#define MAXMCP_FACADE_HAS_EPolyInvalidateDistanceCache 1
#define MAXMCP_FACADE_HAS_EPolyRefreshScreen 1
#define MAXMCP_FACADE_HAS_EPolyEditing 1
#define MAXMCP_FACADE_HAS_EPolyGetEPolySelLevel 1
#define MAXMCP_FACADE_HAS_EPolyGetMNSelLevel 1
#define MAXMCP_FACADE_HAS_EPolySetEPolySelLevel 1
#define MAXMCP_FACADE_HAS_EPolyEpGetVerticesByFlag 1
#define MAXMCP_FACADE_HAS_EPolyEpGetEdgesByFlag 1
#define MAXMCP_FACADE_HAS_EPolyEpGetFacesByFlag 1
#define MAXMCP_FACADE_HAS_EPolyEpSetVertexFlags 1
#define MAXMCP_FACADE_HAS_EPolyEpSetEdgeFlags 1
#define MAXMCP_FACADE_HAS_EPolyEpSetFaceFlags 1
#define MAXMCP_FACADE_HAS_EPolyEpActionButtonOp 1
#define MAXMCP_FACADE_HAS_EPolyEpActionToggleCommandMode 1
#define MAXMCP_FACADE_HAS_EPolyEpActionEnterPickMode 1
#define MAXMCP_FACADE_HAS_EPolyEpActionExitCommandModes 1
#define MAXMCP_FACADE_HAS_EPolyEpActionGetCommandMode 1
#define MAXMCP_FACADE_HAS_EPolyEpActionGetPickMode 1
#define MAXMCP_FACADE_HAS_EPolyMoveSelection 1
#define MAXMCP_FACADE_HAS_EPolyRotateSelection 1
#define MAXMCP_FACADE_HAS_EPolyScaleSelection 1
#define MAXMCP_FACADE_HAS_EPolyEpResetSlicePlane 1
#define MAXMCP_FACADE_HAS_EPolyEpSetSlicePlane 1
#define MAXMCP_FACADE_HAS_EPolySetVertexColor 1
#define MAXMCP_FACADE_HAS_EPolySetFaceColor 1
#define MAXMCP_FACADE_HAS_EPolySetVertexDataValue 1
#define MAXMCP_FACADE_HAS_EPolySetEdgeDataValue 1
#define MAXMCP_FACADE_HAS_EPolyResetVertexData 1
#define MAXMCP_FACADE_HAS_EPolyResetEdgeData 1
#define MAXMCP_FACADE_HAS_EPolyBeginPerDataModify 1
#define MAXMCP_FACADE_HAS_EPolyInPerDataModify 1
#define MAXMCP_FACADE_HAS_EPolyEndPerDataModify 1
#define MAXMCP_FACADE_HAS_EPolyBeginVertexColorModify 1
#define MAXMCP_FACADE_HAS_EPolyInVertexColorModify 1
#define MAXMCP_FACADE_HAS_EPolyEndVertexColorModify 1
#define MAXMCP_FACADE_HAS_EPolySetMatIndex 1
#define MAXMCP_FACADE_HAS_EPolySetSmoothBits 1
#define MAXMCP_FACADE_HAS_EPolySetDisplacementParams 1
#define MAXMCP_FACADE_HAS_EPolyUpdateDisplacementParams 1
#define MAXMCP_FACADE_HAS_EPolyUseDisplacementPreset 1
#define MAXMCP_FACADE_HAS_EPolyEpfnBeginExtrude 1
#define MAXMCP_FACADE_HAS_EPolyEpfnEndExtrude 1
#define MAXMCP_FACADE_HAS_EPolyEpfnDragExtrude 1
#define MAXMCP_FACADE_HAS_EPolyEpfnBeginBevel 1
#define MAXMCP_FACADE_HAS_EPolyEpfnEndBevel 1
#define MAXMCP_FACADE_HAS_EPolyEpfnDragBevel 1
#define MAXMCP_FACADE_HAS_EPolyEpfnBeginChamfer 1
#define MAXMCP_FACADE_HAS_EPolyEpfnEndChamfer 1
#define MAXMCP_FACADE_HAS_EPolyEpfnDragChamfer 1
#define MAXMCP_FACADE_HAS_EPolyEpfnHide 1
#define MAXMCP_FACADE_HAS_EPolyEpfnUnhideAll 1
#define MAXMCP_FACADE_HAS_EPolyEpfnNamedSelectionCopy 1
#define MAXMCP_FACADE_HAS_EPolyEpfnNamedSelectionPaste 1
#define MAXMCP_FACADE_HAS_EPolyEpfnCreateVertex 1
#define MAXMCP_FACADE_HAS_EPolyEpfnCreateEdge 1
#define MAXMCP_FACADE_HAS_EPolyEpfnCapHoles 1
#define MAXMCP_FACADE_HAS_EPolyEpfnDelete 1
#define MAXMCP_FACADE_HAS_EPolyEpfnDetachToElement 1
#define MAXMCP_FACADE_HAS_EPolyEpfnSplitEdges 1
#define MAXMCP_FACADE_HAS_EPolyEpfnBreakVerts 1
#define MAXMCP_FACADE_HAS_EPolyEpfnCollapse 1
#define MAXMCP_FACADE_HAS_EPolyEpfnExtrudeFaces 1
#define MAXMCP_FACADE_HAS_EPolyEpfnBevelFaces 1
#define MAXMCP_FACADE_HAS_EPolyEpfnChamferVertices 1
#define MAXMCP_FACADE_HAS_EPolyEpfnChamferEdges 1
#define MAXMCP_FACADE_HAS_EPolyEpfnInSlicePlaneMode 1
#define MAXMCP_FACADE_HAS_EPolyEpfnWeldVerts 1
#define MAXMCP_FACADE_HAS_EPolyEpfnWeldEdges 1
#define MAXMCP_FACADE_HAS_EPolyEpfnWeldFlaggedVerts 1
#define MAXMCP_FACADE_HAS_EPolyEpfnWeldFlaggedEdges 1
#define MAXMCP_FACADE_HAS_EPolyEpfnMakePlanar 1
#define MAXMCP_FACADE_HAS_EPolyEpfnMoveToPlane 1
#define MAXMCP_FACADE_HAS_EPolyEpfnDeleteIsoVerts 1
#define MAXMCP_FACADE_HAS_EPolyEpfnForceSubdivision 1
#define MAXMCP_FACADE_HAS_EPolyEpfnSelectVertByColor 1
#define MAXMCP_FACADE_HAS_EPolyEpfnSetDiagonal 1
#define MAXMCP_FACADE_HAS_EPolyEpfnRetriangulate 1
#define MAXMCP_FACADE_HAS_EPolyEpfnFlipNormals 1
#define MAXMCP_FACADE_HAS_EPolyEpfnSelectByMat 1
#define MAXMCP_FACADE_HAS_EPolyEpfnSelectBySmoothGroup 1
#define MAXMCP_FACADE_HAS_EPolyEpfnAutoSmooth 1
#define MAXMCP_FACADE_HAS_EPolyCollapseDeadStructs 1
#define MAXMCP_FACADE_HAS_EPolyEpfnChamferVerticesOpen 1
#define MAXMCP_FACADE_HAS_EPolyEpfnChamferEdgesOpen 1
#define MAXMCP_FACADE_HAS_EPolyEpfnSetRingShift 1
#define MAXMCP_FACADE_HAS_EPolyEpfnSetLoopShift 1
#define MAXMCP_FACADE_HAS_EPolyEpfnConvertSelectionToBorder 1
#define MAXMCP_FACADE_HAS_EPolyEpfnPaintDeformCommit 1
#define MAXMCP_FACADE_HAS_EPolyEpfnPaintDeformCancel 1
#define MAXMCP_FACADE_HAS_EPolyCloseSmGrpFloater 1
#define MAXMCP_FACADE_HAS_EPolyCloseMatIDFloater 1
#define MAXMCP_FACADE_HAS_EPolyMatIDFloaterHWND 1
#define MAXMCP_FACADE_HAS_EPolySmGrpFloaterHWND 1
#define MAXMCP_FACADE_HAS_EPolySmGrpFloater 1
#define MAXMCP_FACADE_HAS_EPolyMatIDFloater 1
#define MAXMCP_FACADE_HAS_EPolyMatIDFloaterVisible 1
#define MAXMCP_FACADE_HAS_EPolySmGrpFloaterVisible 1
#define MAXMCP_FACADE_HAS_UnwrapFnPlanarMap 1
#define MAXMCP_FACADE_HAS_UnwrapFnSave 1
#define MAXMCP_FACADE_HAS_UnwrapFnLoad 1
#define MAXMCP_FACADE_HAS_UnwrapFnReset 1
#define MAXMCP_FACADE_HAS_UnwrapFnEdit 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetMapChannel 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetMapChannel 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetProjectionType 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetProjectionType 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetVC 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetVC 1
#define MAXMCP_FACADE_HAS_UnwrapFnMove 1
#define MAXMCP_FACADE_HAS_UnwrapFnMoveH 1
#define MAXMCP_FACADE_HAS_UnwrapFnMoveV 1
#define MAXMCP_FACADE_HAS_UnwrapFnRotate 1
#define MAXMCP_FACADE_HAS_UnwrapFnScale 1
#define MAXMCP_FACADE_HAS_UnwrapFnScaleH 1
#define MAXMCP_FACADE_HAS_UnwrapFnScaleV 1
#define MAXMCP_FACADE_HAS_UnwrapFnMirrorH 1
#define MAXMCP_FACADE_HAS_UnwrapFnMirrorV 1
#define MAXMCP_FACADE_HAS_UnwrapFnExpandSelection 1
#define MAXMCP_FACADE_HAS_UnwrapFnContractSelection 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetFalloffType 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetFalloffType 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetFalloffSpace 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetFalloffSpace 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetFalloffDist 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetFalloffDist 1
#define MAXMCP_FACADE_HAS_UnwrapFnBreakSelected 1
#define MAXMCP_FACADE_HAS_UnwrapFnWeld 1
#define MAXMCP_FACADE_HAS_UnwrapFnWeldSelected 1
#define MAXMCP_FACADE_HAS_UnwrapFnUpdatemap 1
#define MAXMCP_FACADE_HAS_UnwrapFnDisplaymap 1
#define MAXMCP_FACADE_HAS_UnwrapFnIsMapDisplayed 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetUVSpace 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetUVSpace 1
#define MAXMCP_FACADE_HAS_UnwrapFnOptions 1
#define MAXMCP_FACADE_HAS_UnwrapFnLock 1
#define MAXMCP_FACADE_HAS_UnwrapFnHide 1
#define MAXMCP_FACADE_HAS_UnwrapFnUnhide 1
#define MAXMCP_FACADE_HAS_UnwrapFnFreeze 1
#define MAXMCP_FACADE_HAS_UnwrapFnThaw 1
#define MAXMCP_FACADE_HAS_UnwrapFnFilterSelected 1
#define MAXMCP_FACADE_HAS_UnwrapFnPan 1
#define MAXMCP_FACADE_HAS_UnwrapFnZoom 1
#define MAXMCP_FACADE_HAS_UnwrapFnZoomRegion 1
#define MAXMCP_FACADE_HAS_UnwrapFnFit 1
#define MAXMCP_FACADE_HAS_UnwrapFnFitSelected 1
#define MAXMCP_FACADE_HAS_UnwrapFnSnapToggle 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetCurrentMap 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetCurrentMap 1
#define MAXMCP_FACADE_HAS_UnwrapFnNumberMaps 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetLineColor 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetSelColor 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetRenderWidth 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetRenderWidth 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetRenderHeight 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetRenderHeight 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetWeldThreshold 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetWeldThresold 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetUseBitmapRes 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetUseBitmapRes 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetConstantUpdate 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetConstantUpdate 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetShowSelectedVertices 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetShowSelectedVertices 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetPixelCenterSnape 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetPixelCenterSnape 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetMatID 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetMatID 1
#define MAXMCP_FACADE_HAS_UnwrapFnNumberMatIDs 1
#define MAXMCP_FACADE_HAS_UnwrapFnIsVertexSelected 1
#define MAXMCP_FACADE_HAS_UnwrapFnMoveSelectedVertices 1
#define MAXMCP_FACADE_HAS_UnwrapFnRotateSelectedVertices 1
#define MAXMCP_FACADE_HAS_UnwrapFnScaleSelectedVertices 1
#define MAXMCP_FACADE_HAS_UnwrapFnNumberVertices 1
#define MAXMCP_FACADE_HAS_UnwrapFnMoveX 1
#define MAXMCP_FACADE_HAS_UnwrapFnMoveY 1
#define MAXMCP_FACADE_HAS_UnwrapFnMoveZ 1
#define MAXMCP_FACADE_HAS_UnwrapFnIsPolygonSelected 1
#define MAXMCP_FACADE_HAS_UnwrapFnNumberPolygons 1
#define MAXMCP_FACADE_HAS_UnwrapFnDetachEdgeVerts 1
#define MAXMCP_FACADE_HAS_UnwrapFnFlipH 1
#define MAXMCP_FACADE_HAS_UnwrapFnFlipV 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetLockAspect 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetLockAspect 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetMapScale 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetMapScale 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetSelectionFromFace 1
#define MAXMCP_FACADE_HAS_UnwrapFnForceUpdate 1
#define MAXMCP_FACADE_HAS_UnwrapFnZoomToGizmo 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetVertexPosition 1
#define MAXMCP_FACADE_HAS_UnwrapFnMarkAsDead 1
#define MAXMCP_FACADE_HAS_UnwrapFnNumberPointsInFace 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetVertexIndexFromFace 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetHandleIndexFromFace 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetInteriorIndexFromFace 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetVertexGIndexFromFace 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetHandleGIndexFromFace 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetInteriorGIndexFromFace 1
#define MAXMCP_FACADE_HAS_UnwrapFnAddPoint 1
#define MAXMCP_FACADE_HAS_UnwrapFnAddHandle 1
#define MAXMCP_FACADE_HAS_UnwrapFnAddInterior 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetFaceVertexIndex 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetFaceHandleIndex 1
#define MAXMCP_FACADE_HAS_UnwrapFnSetFaceInteriorIndex 1
#define MAXMCP_FACADE_HAS_UnwrapFnUpdateViews 1
#define MAXMCP_FACADE_HAS_UnwrapFnGetFaceSelFromStack 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSelectFacesByNormal 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSelectClusterByNormal 1
#define MAXMCP_FACADE_HAS_Unwrap2FnNormalMapNoParams 1
#define MAXMCP_FACADE_HAS_Unwrap2FnNormalMapDialog 1
#define MAXMCP_FACADE_HAS_Unwrap2FnUnfoldSelectedPolygons 1
#define MAXMCP_FACADE_HAS_Unwrap2FnUnfoldSelectedPolygonsDialog 1
#define MAXMCP_FACADE_HAS_Unwrap2FnUnfoldSelectedPolygonsNoParams 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetSeedFace 1
#define MAXMCP_FACADE_HAS_Unwrap2FnShowVertexConnectionList 1
#define MAXMCP_FACADE_HAS_Unwrap2FnCopy 1
#define MAXMCP_FACADE_HAS_Unwrap2FnPaste 1
#define MAXMCP_FACADE_HAS_Unwrap2FnPasteInstance 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetDebugLevel 1
#define MAXMCP_FACADE_HAS_Unwrap2FnStitchVerts 1
#define MAXMCP_FACADE_HAS_Unwrap2FnStitchVertsNoParams 1
#define MAXMCP_FACADE_HAS_Unwrap2FnStitchVertsDialog 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSelectElement 1
#define MAXMCP_FACADE_HAS_Unwrap2FnFlattenMapDialog 1
#define MAXMCP_FACADE_HAS_Unwrap2FnFlattenMapNoParams 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetTile 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetTileLimit 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetTileContrast 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetShowMap 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetLimitSoftSel 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetLimitSoftSelRange 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetVertexWeight 1
#define MAXMCP_FACADE_HAS_Unwrap2FnModifyWeight 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetGeomElemMode 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetGeomPlanarMode 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetGeomPlanarModeThreshold 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetBackFaceCull 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetOldSelMethod 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetSelectionMatID 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSelectByMatID 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSelectBySG 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetTVElementMode 1
#define MAXMCP_FACADE_HAS_Unwrap2FnGeomExpandFaceSel 1
#define MAXMCP_FACADE_HAS_Unwrap2FnGeomContractFaceSel 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetAlwaysEdit 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetShowConnection 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetFilteredSelected 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetPixelCornerSnap 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetLock 1
#define MAXMCP_FACADE_HAS_Unwrap2FnPackNoParams 1
#define MAXMCP_FACADE_HAS_Unwrap2FnPackDialog 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetTVSubMode 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetFillMode 1
#define MAXMCP_FACADE_HAS_Unwrap2FnMoveSelected 1
#define MAXMCP_FACADE_HAS_Unwrap2FnRotateSelected 1
#define MAXMCP_FACADE_HAS_Unwrap2FnScaleSelected 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetDisplayOpenEdges 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetOpenEdgeColor 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetUVEdgeMode 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetOpenEdgeMode 1
#define MAXMCP_FACADE_HAS_Unwrap2FnUVEdgeSelect 1
#define MAXMCP_FACADE_HAS_Unwrap2FnOpenEdgeSelect 1
#define MAXMCP_FACADE_HAS_Unwrap2FnVertToEdgeSelect 1
#define MAXMCP_FACADE_HAS_Unwrap2FnVertToFaceSelect 1
#define MAXMCP_FACADE_HAS_Unwrap2FnEdgeToVertSelect 1
#define MAXMCP_FACADE_HAS_Unwrap2FnEdgeToFaceSelect 1
#define MAXMCP_FACADE_HAS_Unwrap2FnFaceToVertSelect 1
#define MAXMCP_FACADE_HAS_Unwrap2FnFaceToEdgeSelect 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetDisplayHiddenEdges 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetHandleColor 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetFreeFormMode 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetFreeFormColor 1
#define MAXMCP_FACADE_HAS_Unwrap2FnScaleSelectedXY 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSnapPivot 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetPivotOffset 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSketchNoParams 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSketchDialog 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSketchReverse 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetHitSize 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetResetPivotOnSel 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetPolyMode 1
#define MAXMCP_FACADE_HAS_Unwrap2FnPolySelect 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetAllowSelectionInsideGizmo 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetAsDefaults 1
#define MAXMCP_FACADE_HAS_Unwrap2FnLoadDefaults 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetSharedColor 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetShowShared 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetSyncSelectionMode 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSyncTVSelection 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSyncGeomSelection 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetBackgroundColor 1
#define MAXMCP_FACADE_HAS_Unwrap2FnUpdateMenuBar 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetBrightCenterTile 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetBlendToBack 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetPaintMode 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetPaintSize 1
#define MAXMCP_FACADE_HAS_Unwrap2FnIncPaintSize 1
#define MAXMCP_FACADE_HAS_Unwrap2FnDecPaintSize 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetTickSize 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetGridSize 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetSnapToggle 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetGridVisible 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetGridColor 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetSnapStrength 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetAutoMap 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetFlattenAngle 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetFlattenSpacing 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetFlattenNormalize 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetFlattenRotate 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetFlattenFillHoles 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetPreventFlattening 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetEnableSoftSelection 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetApplyToWholeObject 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetVertexPosition2 1
#define MAXMCP_FACADE_HAS_Unwrap2FnRelax 1
#define MAXMCP_FACADE_HAS_Unwrap2FnGetCheckerTiling 1
#define MAXMCP_FACADE_HAS_Unwrap2FnSetCheckerTiling 1
#define MAXMCP_FACADE_HAS_ShapeObjGetThickness 1
#define MAXMCP_FACADE_HAS_ShapeObjGetSides 1
#define MAXMCP_FACADE_HAS_ShapeObjGetAngle 1
#define MAXMCP_FACADE_HAS_ShapeObjGetViewportThickness 1
#define MAXMCP_FACADE_HAS_ShapeObjGetViewportSides 1
#define MAXMCP_FACADE_HAS_ShapeObjGetViewportAngle 1
#define MAXMCP_FACADE_HAS_ShapeObjGetGenUVs 1
#define MAXMCP_FACADE_HAS_ShapeObjGetDispRenderMesh 1
#define MAXMCP_FACADE_HAS_ShapeObjGetUseViewport 1
#define MAXMCP_FACADE_HAS_ShapeObjGetViewportOrRenderer 1
#define MAXMCP_FACADE_HAS_ShapeObjSetThickness 1
#define MAXMCP_FACADE_HAS_ShapeObjSetSides 1
#define MAXMCP_FACADE_HAS_ShapeObjSetAngle 1
#define MAXMCP_FACADE_HAS_ShapeObjSetViewportThickness 1
#define MAXMCP_FACADE_HAS_ShapeObjSetViewportSides 1
#define MAXMCP_FACADE_HAS_ShapeObjSetViewportAngle 1
#define MAXMCP_FACADE_HAS_ShapeObjSetRenderable 1
#define MAXMCP_FACADE_HAS_ShapeObjSetGenUVs 1
#define MAXMCP_FACADE_HAS_ShapeObjSetDispRenderMesh 1
#define MAXMCP_FACADE_HAS_ShapeObjSetUseViewport 1
#define MAXMCP_FACADE_HAS_ShapeObjSetViewportOrRenderer 1
#define MAXMCP_FACADE_HAS_ShapeObjNumberOfVertices 1
#define MAXMCP_FACADE_HAS_ShapeObjNumberOfCurves 1
#define MAXMCP_FACADE_HAS_ShapeObjCurveClosed 1
#define MAXMCP_FACADE_HAS_ShapeObjInterpCurve3D 1
#define MAXMCP_FACADE_HAS_ShapeObjTangentCurve3D 1
#define MAXMCP_FACADE_HAS_ShapeObjNumberOfPieces 1
#define MAXMCP_FACADE_HAS_ShapeObjInterpPiece3D 1
#define MAXMCP_FACADE_HAS_ShapeObjTangentPiece3D 1
#define MAXMCP_FACADE_HAS_ShapeObjGetMatID 1
#define MAXMCP_FACADE_HAS_ShapeObjCanMakeBezier 1
#define MAXMCP_FACADE_HAS_ShapeObjGetParameterName 1
#define MAXMCP_FACADE_HAS_ShapeObjInvalidateGeomCache 1
#define MAXMCP_FACADE_HAS_ShapeObjGetUsePhysicalScaleUVs 1
#define MAXMCP_FACADE_HAS_ShapeObjSetUsePhysicalScaleUVs 1
#define MAXMCP_FACADE_HAS_ShapeObjGetTwistCorrect 1
#define MAXMCP_FACADE_HAS_ShapeObjSetTwistCorrect 1
#define MAXMCP_FACADE_HAS_ShapeObjGetCap 1
#define MAXMCP_FACADE_HAS_ShapeObjSetCap 1
#define MAXMCP_FACADE_HAS_ShapeObjGetQuadCap 1
#define MAXMCP_FACADE_HAS_ShapeObjSetQuadCap 1
#define MAXMCP_FACADE_HAS_ShapeObjGetCapSegments 1
#define MAXMCP_FACADE_HAS_ShapeObjSetCapSegments 1
#define MAXMCP_FACADE_HAS_ShapeObjGetSphereCap 1
#define MAXMCP_FACADE_HAS_ShapeObjSetSphereCap 1
#define MAXMCP_FACADE_HAS_MXSParticleGetParticleSystem 1
#define MAXMCP_FACADE_HAS_MXSParticleGetParticleSystemNode 1
#define MAXMCP_FACADE_HAS_MXSParticleGetTimeStart 1
#define MAXMCP_FACADE_HAS_MXSParticleGetTimeEnd 1
#define MAXMCP_FACADE_HAS_MXSParticleSetTimeEnd 1
#define MAXMCP_FACADE_HAS_MXSParticleGetActionNode 1
#define MAXMCP_FACADE_HAS_MXSParticleGetUseTime 1
#define MAXMCP_FACADE_HAS_MXSParticleSetUseTime 1
#define MAXMCP_FACADE_HAS_MXSParticleGetUseAge 1
#define MAXMCP_FACADE_HAS_MXSParticleSetUseAge 1
#define MAXMCP_FACADE_HAS_MXSParticleGetUseLifespan 1
#define MAXMCP_FACADE_HAS_MXSParticleSetUseLifespan 1
#define MAXMCP_FACADE_HAS_MXSParticleGetUseEventTime 1
#define MAXMCP_FACADE_HAS_MXSParticleSetUseEventTime 1
#define MAXMCP_FACADE_HAS_MXSParticleGetUsePosition 1
#define MAXMCP_FACADE_HAS_MXSParticleSetUsePosition 1
#define MAXMCP_FACADE_HAS_MXSParticleGetUseSpeed 1
#define MAXMCP_FACADE_HAS_MXSParticleSetUseSpeed 1
#define MAXMCP_FACADE_HAS_MXSParticleGetUseAcceleration 1
#define MAXMCP_FACADE_HAS_MXSParticleSetUseAcceleration 1
#define MAXMCP_FACADE_HAS_MXSParticleGetUseOrientation 1
#define MAXMCP_FACADE_HAS_MXSParticleSetUseOrientation 1
#define MAXMCP_FACADE_HAS_MXSParticleGetUseSpin 1
#define MAXMCP_FACADE_HAS_MXSParticleSetUseSpin 1
#define MAXMCP_FACADE_HAS_MXSParticleGetUseScale 1
#define MAXMCP_FACADE_HAS_MXSParticleSetUseScale 1
#define MAXMCP_FACADE_HAS_MXSParticleGetUseTM 1
#define MAXMCP_FACADE_HAS_MXSParticleSetUseTM 1
#define MAXMCP_FACADE_HAS_MXSParticleGetUseSelected 1
#define MAXMCP_FACADE_HAS_MXSParticleSetUseSelected 1
#define MAXMCP_FACADE_HAS_MXSParticleGetUseShape 1
#define MAXMCP_FACADE_HAS_MXSParticleSetUseShape 1
#define MAXMCP_FACADE_HAS_MXSParticleGetUseMtlIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetUseMtlIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleGetUseMapping 1
#define MAXMCP_FACADE_HAS_MXSParticleSetUseMapping 1
#define MAXMCP_FACADE_HAS_MXSParticleGetUseInt 1
#define MAXMCP_FACADE_HAS_MXSParticleSetUseInt 1
#define MAXMCP_FACADE_HAS_MXSParticleGetUseFloat 1
#define MAXMCP_FACADE_HAS_MXSParticleSetUseFloat 1
#define MAXMCP_FACADE_HAS_MXSParticleGetUseVector 1
#define MAXMCP_FACADE_HAS_MXSParticleSetUseVector 1
#define MAXMCP_FACADE_HAS_MXSParticleGetUseMatrix 1
#define MAXMCP_FACADE_HAS_MXSParticleSetUseMatrix 1
#define MAXMCP_FACADE_HAS_MXSParticleGetCurrentParticleIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleGetCurrentParticleBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetCurrentParticleIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetCurrentParticleBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleTimeByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleTimeByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleGetParticleTime 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleTime 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleAgeByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleAgeByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleGetParticleAge 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleAge 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleLifespanByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleLifespanByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleGetParticleLifespan 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleLifespan 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleEventTimeByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleEventTimeByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleGetParticleEventTime 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleEventTime 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticlePositionByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticlePositionByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticlePosition 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleSpeedByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleSpeedByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleSpeed 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleAccelerationByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleAccelerationByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleAcceleration 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleOrientationByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleOrientationByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleOrientation 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleSpinByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleSpinByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleSpin 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleScaleByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleScaleByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleGetParticleScale 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleScale 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleScaleXYZByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleScaleXYZByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleScaleXYZ 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleTMByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleTMByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleTM 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleSelectedByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleSelectedByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleGetParticleSelected 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleSelected 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleMtlIndexByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleMtlIndexByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleMtlIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleIntByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleIntByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleGetParticleInt 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleInt 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleFloatByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleFloatByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleGetParticleFloat 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleFloat 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleVectorByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleVectorByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleVector 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleMatrixByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleMatrixByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleMatrix 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleTestStatusByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleTestStatusByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleGetParticleTestStatus 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleTestStatus 1
#define MAXMCP_FACADE_HAS_MXSParticleSetGlobalTestStatus 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleTestTimeByIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleTestTimeByBornIndex 1
#define MAXMCP_FACADE_HAS_MXSParticleGetParticleTestTime 1
#define MAXMCP_FACADE_HAS_MXSParticleSetParticleTestTime 1
#define MAXMCP_FACADE_HAS_MXSParticleSetGlobalTestTime 1
#define MAXMCP_FACADE_HAS_BezierShapeInit 1
#define MAXMCP_FACADE_HAS_BezierShapeGetVert 1
#define MAXMCP_FACADE_HAS_BezierShapeBuildBoundingBox 1
#define MAXMCP_FACADE_HAS_BezierShapeInvalidateGeomCache 1
#define MAXMCP_FACADE_HAS_BezierShapeInvalidateCapCache 1
#define MAXMCP_FACADE_HAS_BezierShapeSetDispFlag 1
#define MAXMCP_FACADE_HAS_BezierShapeGetDispFlag 1
#define MAXMCP_FACADE_HAS_BezierShapeClearDispFlag 1
#define MAXMCP_FACADE_HAS_BezierShapeDeleteSpline 1
#define MAXMCP_FACADE_HAS_BezierShapeNewShape 1
#define MAXMCP_FACADE_HAS_BezierShapeGetNumVerts 1
#define MAXMCP_FACADE_HAS_BezierShapeGetNumSegs 1
#define MAXMCP_FACADE_HAS_BezierShapeUpdateSels 1
#define MAXMCP_FACADE_HAS_BezierShapeGetClosures 1
#define MAXMCP_FACADE_HAS_BezierShapeSetClosures 1
#define MAXMCP_FACADE_HAS_BezierShapeReverse 1
#define MAXMCP_FACADE_HAS_BezierShapeMakeFirst 1
#define MAXMCP_FACADE_HAS_BezierShapeTransform 1
#define MAXMCP_FACADE_HAS_BezierShapeReadyCachedPolyShape 1
#define MAXMCP_FACADE_HAS_BezierShapePrepVertBaseIndex 1
#define MAXMCP_FACADE_HAS_BezierShapeGetVertIndex 1
#define MAXMCP_FACADE_HAS_BezierShapeGetTotalVerts 1
#define MAXMCP_FACADE_HAS_BezierShapeSetVert 1
#define MAXMCP_FACADE_HAS_BezierShapePrepKnotBaseIndex 1
#define MAXMCP_FACADE_HAS_BezierShapeGetKnotIndex 1
#define MAXMCP_FACADE_HAS_BezierShapeGetTotalKnots 1
#define MAXMCP_FACADE_HAS_BezierShapeDeleteSelVerts 1
#define MAXMCP_FACADE_HAS_BezierShapeDeleteSelSegs 1
#define MAXMCP_FACADE_HAS_BezierShapeDeleteSelectedVerts 1
#define MAXMCP_FACADE_HAS_BezierShapeDeleteSelectedSegs 1
#define MAXMCP_FACADE_HAS_BezierShapeDeleteSelectedPolys 1
#define MAXMCP_FACADE_HAS_BezierShapeCloneSelectedParts 1
#define MAXMCP_FACADE_HAS_BezierShapeRecordTopologyTags 1
#define MAXMCP_FACADE_HAS_BezierShapeInterpCurve3D 1
#define MAXMCP_FACADE_HAS_BezierShapeTangentCurve3D 1
#define MAXMCP_FACADE_HAS_BezierShapeInterpPiece3D 1
#define MAXMCP_FACADE_HAS_BezierShapeTangentPiece3D 1
#define MAXMCP_FACADE_HAS_BezierShapeGetMatID 1
#define MAXMCP_FACADE_HAS_BezierShapeLengthOfCurve 1
#define MAXMCP_FACADE_HAS_BezierShapeBindKnot 1
#define MAXMCP_FACADE_HAS_BezierShapeUnbindKnot 1
#define MAXMCP_FACADE_HAS_BezierShapeUpdateBindList 1
#define MAXMCP_FACADE_HAS_BezierShapeHideSelectedSegs 1
#define MAXMCP_FACADE_HAS_BezierShapeHideSelectedVerts 1
#define MAXMCP_FACADE_HAS_BezierShapeHideSelectedSplines 1
#define MAXMCP_FACADE_HAS_BezierShapeUnhideSegs 1
#define MAXMCP_FACADE_HAS_BezierShapeSetVertexWeightCount 1
#define MAXMCP_FACADE_HAS_BezierShapeSetVertexWeight 1
#define MAXMCP_FACADE_HAS_BezierShapeSupportVSelectionWeights 1
#define MAXMCP_FACADE_HAS_BezierShapeUseEdgeDists 1
#define MAXMCP_FACADE_HAS_BezierShapeSetUseEdgeDists 1
#define MAXMCP_FACADE_HAS_BezierShapeEdgeDist 1
#define MAXMCP_FACADE_HAS_BezierShapeSetEdgeDist 1
#define MAXMCP_FACADE_HAS_BezierShapeUseSoftSelections 1
#define MAXMCP_FACADE_HAS_BezierShapeSetUseSoftSelections 1
#define MAXMCP_FACADE_HAS_BezierShapeAffectBackface 1
#define MAXMCP_FACADE_HAS_BezierShapeSetAffectBackface 1
#define MAXMCP_FACADE_HAS_BezierShapeFalloff 1
#define MAXMCP_FACADE_HAS_BezierShapeSetFalloff 1
#define MAXMCP_FACADE_HAS_BezierShapePinch 1
#define MAXMCP_FACADE_HAS_BezierShapeSetPinch 1
#define MAXMCP_FACADE_HAS_BezierShapeBubble 1
#define MAXMCP_FACADE_HAS_BezierShapeSetBubble 1
#define MAXMCP_FACADE_HAS_BezierShapeInvalidateVertexWeights 1
#define MAXMCP_FACADE_HAS_BezierShapeUpdateVertexDists 1
#define MAXMCP_FACADE_HAS_BezierShapeUpdateEdgeDists 1
#define MAXMCP_FACADE_HAS_BezierShapeUpdateVertexWeights 1
#define MAXMCP_FACADE_HAS_ILayerSetName 1
#define MAXMCP_FACADE_HAS_ILayerGetName 1
#define MAXMCP_FACADE_HAS_ILayerSetWireColor 1
#define MAXMCP_FACADE_HAS_ILayerGetWireColor 1
#define MAXMCP_FACADE_HAS_ILayerHide 1
#define MAXMCP_FACADE_HAS_ILayerIsHidden 1
#define MAXMCP_FACADE_HAS_ILayerFreeze 1
#define MAXMCP_FACADE_HAS_ILayerIsFrozen 1
#define MAXMCP_FACADE_HAS_ILayerXRayMtl 1
#define MAXMCP_FACADE_HAS_ILayerHasXRayMtl 1
#define MAXMCP_FACADE_HAS_ILayerBoxMode 1
#define MAXMCP_FACADE_HAS_ILayerGetBoxMode 1
#define MAXMCP_FACADE_HAS_ILayerBackCull 1
#define MAXMCP_FACADE_HAS_ILayerGetBackCull 1
#define MAXMCP_FACADE_HAS_ILayerAllEdges 1
#define MAXMCP_FACADE_HAS_ILayerGetAllEdges 1
#define MAXMCP_FACADE_HAS_ILayerVertTicks 1
#define MAXMCP_FACADE_HAS_ILayerGetVertTicks 1
#define MAXMCP_FACADE_HAS_ILayerTrajectory 1
#define MAXMCP_FACADE_HAS_ILayerGetTrajectory 1
#define MAXMCP_FACADE_HAS_ILayerIgnoreExtents 1
#define MAXMCP_FACADE_HAS_ILayerGetIgnoreExtents 1
#define MAXMCP_FACADE_HAS_ILayerSetShowFrozenWithMtl 1
#define MAXMCP_FACADE_HAS_ILayerShowFrozenWithMtl 1
#define MAXMCP_FACADE_HAS_ILayerSetCVertMode 1
#define MAXMCP_FACADE_HAS_ILayerGetCVertMode 1
#define MAXMCP_FACADE_HAS_ILayerSetShadeCVerts 1
#define MAXMCP_FACADE_HAS_ILayerGetShadeCVerts 1
#define MAXMCP_FACADE_HAS_ILayerSetVisibility 1
#define MAXMCP_FACADE_HAS_ILayerGetVisibility 1
#define MAXMCP_FACADE_HAS_ILayerIsHiddenByVisControl 1
#define MAXMCP_FACADE_HAS_ILayerSetRenderable 1
#define MAXMCP_FACADE_HAS_ILayerRenderable 1
#define MAXMCP_FACADE_HAS_ILayerSetInheritVisibility 1
#define MAXMCP_FACADE_HAS_ILayerGetInheritVisibility 1
#define MAXMCP_FACADE_HAS_ILayerSetPrimaryVisibility 1
#define MAXMCP_FACADE_HAS_ILayerGetPrimaryVisibility 1
#define MAXMCP_FACADE_HAS_ILayerSetSecondaryVisibility 1
#define MAXMCP_FACADE_HAS_ILayerGetSecondaryVisibility 1
#define MAXMCP_FACADE_HAS_ILayerSetCastShadows 1
#define MAXMCP_FACADE_HAS_ILayerCastShadows 1
#define MAXMCP_FACADE_HAS_ILayerSetRcvShadows 1
#define MAXMCP_FACADE_HAS_ILayerRcvShadows 1
#define MAXMCP_FACADE_HAS_ILayerSetApplyAtmospherics 1
#define MAXMCP_FACADE_HAS_ILayerApplyAtmospherics 1
#define MAXMCP_FACADE_HAS_ILayerSetRenderOccluded 1
#define MAXMCP_FACADE_HAS_ILayerGetRenderOccluded 1
#define MAXMCP_FACADE_HAS_ILayerGetMotBlurOnOff 1
#define MAXMCP_FACADE_HAS_ILayerSetMotBlurOnOff 1
#define MAXMCP_FACADE_HAS_ILayerGetImageBlurMultiplier 1
#define MAXMCP_FACADE_HAS_ILayerSetImageBlurMultiplier 1
#define MAXMCP_FACADE_HAS_ILayerSetMotBlur 1
#define MAXMCP_FACADE_HAS_ILayerMotBlur 1
#define MAXMCP_FACADE_HAS_ILayerUsed 1
#define MAXMCP_FACADE_HAS_ILayerHasObjects 1
#define MAXMCP_FACADE_HAS_ILayerSelectObjects 1
#define MAXMCP_FACADE_HAS_ILayerGetNumOfChildLayers 1
#define MAXMCP_FACADE_HAS_ILayerGetRenderFlags 1
#define MAXMCP_FACADE_HAS_ILayerSetRenderFlags 1
#define MAXMCP_FACADE_HAS_ILayerGetDisplayFlags 1
#define MAXMCP_FACADE_HAS_ILayerGetFlag 1
#define MAXMCP_FACADE_HAS_ILayerGetFlag2 1
#define MAXMCP_FACADE_HAS_ILayerUpdateSelectionSet 1
#define MAXMCP_FACADE_HAS_ParticleExtSetEveryStepUpdateScriptLine 1
#define MAXMCP_FACADE_HAS_ParticleExtSetEveryStepUpdateScriptFile 1
#define MAXMCP_FACADE_HAS_ParticleExtSetFinalStepUpdateScriptLine 1
#define MAXMCP_FACADE_HAS_ParticleExtSetFinalStepUpdateScriptFile 1
#define MAXMCP_FACADE_HAS_ParticleExtExecuteEveryStepUpdateScript 1
#define MAXMCP_FACADE_HAS_ParticleExtExecuteFinalStepUpdateScript 1
#define MAXMCP_FACADE_HAS_ParticleExtGetUpdateTime 1
#define MAXMCP_FACADE_HAS_ParticleExtNumParticles 1
#define MAXMCP_FACADE_HAS_ParticleExtNumParticlesGenerated 1
#define MAXMCP_FACADE_HAS_ParticleExtAddParticle 1
#define MAXMCP_FACADE_HAS_ParticleExtAddParticles 1
#define MAXMCP_FACADE_HAS_ParticleExtDeleteParticle 1
#define MAXMCP_FACADE_HAS_ParticleExtGetCurrentParticleIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtGetCurrentParticleBornIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetCurrentParticleIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetCurrentParticleBornIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleAgeByIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleAgeByBornIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtGetParticleAge 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleAge 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleLifeSpanByIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleLifeSpanByBornIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtGetParticleLifeSpan 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleLifeSpan 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleGroupTimeByIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleGroupTimeByBornIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtGetParticleGroupTime 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleGroupTime 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticlePositionByIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticlePositionByBornIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticlePosition 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleSpeedByIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleSpeedByBornIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleSpeed 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleOrientationByIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleOrientationByBornIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleOrientation 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleSpinByIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleSpinByBornIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleSpin 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleScaleByIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleScaleByBornIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtGetParticleScale 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleScale 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleScaleXYZByIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleScaleXYZByBornIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleScaleXYZ 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleTMByIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleTMByBornIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleTM 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleSelectedByIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleSelectedByBornIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtGetParticleSelected 1
#define MAXMCP_FACADE_HAS_ParticleExtSetParticleSelected 1
#define MAXMCP_FACADE_HAS_Scene8GetRendCamNode 1
#define MAXMCP_FACADE_HAS_Scene8GetRendUseImgSeq 1
#define MAXMCP_FACADE_HAS_Scene8SetRendUseImgSeq 1
#define MAXMCP_FACADE_HAS_Scene8GetRendImgSeqType 1
#define MAXMCP_FACADE_HAS_Scene8SetRendImgSeqType 1
#define MAXMCP_FACADE_HAS_Scene8GetUsePreRendScript 1
#define MAXMCP_FACADE_HAS_Scene8SetUsePreRendScript 1
#define MAXMCP_FACADE_HAS_Scene8GetLocalPreRendScript 1
#define MAXMCP_FACADE_HAS_Scene8SetLocalPreRendScript 1
#define MAXMCP_FACADE_HAS_Scene8GetUsePostRendScript 1
#define MAXMCP_FACADE_HAS_Scene8SetUsePostRendScript 1
#define MAXMCP_FACADE_HAS_Scene8GetControllerOverrideRangeDefault 1
#define MAXMCP_FACADE_HAS_Scene8SetControllerOverrideRangeDefault 1
#define MAXMCP_FACADE_HAS_Scene8SetDefaultTangentType 1
#define MAXMCP_FACADE_HAS_Scene8GetSpringQuickEditMode 1
#define MAXMCP_FACADE_HAS_Scene8SetSpringQuickEditMode 1
#define MAXMCP_FACADE_HAS_Scene8SetSpringRollingStart 1
#define MAXMCP_FACADE_HAS_Scene8GetSpringRollingStart 1
#define MAXMCP_FACADE_HAS_Scene8ColorById 1
#define MAXMCP_FACADE_HAS_Scene8RegisterModelessRenderWindow 1
#define MAXMCP_FACADE_HAS_Scene8UnRegisterModelessRenderWindow 1
#define MAXMCP_FACADE_HAS_Scene8IsRegisteredModelessRenderWindow 1
#define MAXMCP_FACADE_HAS_Scene8IsSavingToFile 1
#define MAXMCP_FACADE_HAS_Scene10GetTrajectoryMode 1
#define MAXMCP_FACADE_HAS_Scene10SetTrajectoryMode 1
#define MAXMCP_FACADE_HAS_Scene10GetTrajectoryKeySubMode 1
#define MAXMCP_FACADE_HAS_Scene10SetTrajectoryKeySubMode 1
#define MAXMCP_FACADE_HAS_Scene10GetTrajectoryAddKeyMode 1
#define MAXMCP_FACADE_HAS_Scene10SetTrajectoryAddKeyMode 1
#define MAXMCP_FACADE_HAS_Scene10DeleteSelectedTrajectoryKey 1
#define MAXMCP_FACADE_HAS_Scene10GetAutoKeyDefaultKeyOn 1
#define MAXMCP_FACADE_HAS_Scene10SetAutoKeyDefaultKeyOn 1
#define MAXMCP_FACADE_HAS_Scene10GetAutoKeyDefaultKeyTime 1
#define MAXMCP_FACADE_HAS_Scene10SetAutoKeyDefaultKeyTime 1
#define MAXMCP_FACADE_HAS_Scene10GetPrompt 1
#define MAXMCP_FACADE_HAS_Scene10FormatRenderTime 1
#define MAXMCP_FACADE_HAS_Scene11GetRendUseActiveView 1
#define MAXMCP_FACADE_HAS_Scene11SetRendUseActiveView 1
#define MAXMCP_FACADE_HAS_Scene11GetRenderPresetMRUListCount 1
#define MAXMCP_FACADE_HAS_Scene11GetRenderPresetMRUListDisplayName 1
#define MAXMCP_FACADE_HAS_Scene11GetRenderPresetMRUListFileName 1
#define MAXMCP_FACADE_HAS_Scene11GetTransformGizmoTM 1
#define MAXMCP_FACADE_HAS_Scene11DisplayViewportConfigDialogPage 1
#define MAXMCP_FACADE_HAS_Scene13GetRendUseIterative 1
#define MAXMCP_FACADE_HAS_Scene13SetRendUseIterative 1
#define MAXMCP_FACADE_HAS_Scene13SaveSceneAsVersion 1
#define MAXMCP_FACADE_HAS_Scene13SaveSelectedNodesAsVersion 1
#define MAXMCP_FACADE_HAS_Scene13GetSceneFileCompressOnSave 1
#define MAXMCP_FACADE_HAS_Scene13SetSceneFileCompressOnSave 1
#define MAXMCP_FACADE_HAS_Scene13GetMtlDlgMode 1
#define MAXMCP_FACADE_HAS_Scene13SetMtlDlgMode 1
#define MAXMCP_FACADE_HAS_Scene13SetNameSuffixLength 1
#define MAXMCP_FACADE_HAS_Scene13GetNameSuffixLength 1
#define MAXMCP_FACADE_HAS_Scene14GetRendViewID 1
#define MAXMCP_FACADE_HAS_Scene14SetRendViewID 1
#define MAXMCP_FACADE_HAS_Scene14SetPlayPreviewWhenDone 1
#define MAXMCP_FACADE_HAS_Scene14GetPlayPreviewWhenDone 1
#define MAXMCP_FACADE_HAS_Scene14OverrideLanguageSpecifiedInSceneFile 1
#define MAXMCP_FACADE_HAS_Scene14SetOverrideLanguageSpecifiedInSceneFile 1
#define MAXMCP_FACADE_HAS_Scene14UseCodePageSpecifiedInSceneFile 1
#define MAXMCP_FACADE_HAS_Scene14SetUseCodePageSpecifiedInSceneFile 1
#define MAXMCP_FACADE_HAS_Scene14LegacyFilesCanBeStoredUsingUTF8 1
#define MAXMCP_FACADE_HAS_Scene14SetLegacyFilesCanBeStoredUsingUTF8 1
#define MAXMCP_FACADE_HAS_Scene14DefaultTextLoadCodePage 1
#define MAXMCP_FACADE_HAS_Scene14DefaultTextSaveCodePage 1
#define MAXMCP_FACADE_HAS_Scene15GetMainThreadID 1
#define MAXMCP_FACADE_HAS_Scene16SetShowWorldAxis 1
#define MAXMCP_FACADE_HAS_Scene16GetShowWorldAxis 1
#define MAXMCP_FACADE_HAS_Scene16GetOverrideRenderSettingMtl 1
#define MAXMCP_FACADE_HAS_Scene17SetEnableTMCache 1
#define MAXMCP_FACADE_HAS_Scene17GetEnableTMCache 1
#define MAXMCP_FACADE_HAS_Scene17InNonInteractiveMode 1
#define MAXMCP_FACADE_HAS_Scene17SetInNonInteractiveTestMode 1
#define MAXMCP_FACADE_HAS_Scene17SetInSecureMode 1
#define MAXMCP_FACADE_HAS_Scene17InSecureMode 1
#define MAXMCP_FACADE_HAS_Scene17IsRibbonSupportEnabled 1
#define MAXMCP_FACADE_HAS_Scene17BreakSelectedKeyTangent 1
#define MAXMCP_FACADE_HAS_Scene17UnifySelectedKeyTangent 1
#define MAXMCP_FACADE_HAS_Scene17SetSelectedKeyTangentType 1
#define MAXMCP_FACADE_HAS_Scene17GetTrajectoryPathGradation 1
#define MAXMCP_FACADE_HAS_Scene17GetUnselTrajectoryDrawFrameTicks 1
#define MAXMCP_FACADE_HAS_Scene17SetUnselTrajectoryDrawFrameTicks 1
#define MAXMCP_FACADE_HAS_Scene17GetUnselTrajectoryDrawKeys 1
#define MAXMCP_FACADE_HAS_Scene17SetUnselTrajectoryDrawKeys 1
#define MAXMCP_FACADE_HAS_Scene17TrimTrajectories 1
#define MAXMCP_FACADE_HAS_Scene17SetTrimTrajectories 1
#define MAXMCP_FACADE_HAS_Scene17IsFixedTrimRange 1
#define MAXMCP_FACADE_HAS_Scene17SetFixedTrimRange 1
#define MAXMCP_FACADE_HAS_Scene17TrimTrajectoriesOffset 1
#define MAXMCP_FACADE_HAS_Scene17SetTrimTrajectoriesOffset 1
#define MAXMCP_FACADE_HAS_Scene17GetTrimStart 1
#define MAXMCP_FACADE_HAS_Scene17SetTrimStart 1
#define MAXMCP_FACADE_HAS_Scene17GetTrimEnd 1
#define MAXMCP_FACADE_HAS_Scene17SetTrimEnd 1
#define MAXMCP_FACADE_HAS_Scene17GetSelTrajectoryDrawAllTangents 1
#define MAXMCP_FACADE_HAS_Scene17SetSelTrajectoryDrawAllTangents 1
#define MAXMCP_FACADE_HAS_Scene17GetSelTrajectoryDrawFrameTicks 1
#define MAXMCP_FACADE_HAS_Scene17SetSelTrajectoryDrawFrameTicks 1
#define MAXMCP_FACADE_HAS_Scene17GetSelTrajectoryDrawGradientTicks 1
#define MAXMCP_FACADE_HAS_Scene17SetSelTrajectoryDrawGradientTicks 1
#define MAXMCP_FACADE_HAS_Scene17GetTrajectoryDrawKeyTimes 1
#define MAXMCP_FACADE_HAS_Scene17SetTrajectoryDrawKeyTimes 1
#define MAXMCP_FACADE_HAS_Scene17GetSelTrajectoryDrawKeys 1
#define MAXMCP_FACADE_HAS_Scene17SetSelTrajectoryDrawKeys 1
#define MAXMCP_FACADE_HAS_Scene17UpdateSceneMaterialLib 1
#define MAXMCP_FACADE_HAS_Scene17SetRendFormatToCustom 1
#define MAXMCP_FACADE_HAS_Scene17IsValidSaveAsVersion 1
#define MAXMCP_FACADE_HAS_Scene17EnableViewportStatisticsRefresh 1
#define MAXMCP_FACADE_HAS_Scene17RefreshViewportStatistics 1
#define MAXMCP_FACADE_HAS_Scene17EnableViewportStatistics 1
#define MAXMCP_FACADE_HAS_Scene17GlobalScaleTime 1
#define MAXMCP_FACADE_HAS_Scene17UpdateOsnapDlg 1
#define MAXMCP_FACADE_HAS_Scene17SetASnapStatus 1
#define MAXMCP_FACADE_HAS_Scene17SetPSnapStatus 1
#define MAXMCP_FACADE_HAS_Scene17GetSceneFileUserName 1
#define MAXMCP_FACADE_HAS_Scene17SetSceneFileUserName 1
#define MAXMCP_FACADE_HAS_Scene17GetSceneFileComputerName 1
#define MAXMCP_FACADE_HAS_Scene17SetSceneFileComputerName 1
#define MAXMCP_FACADE_HAS_BaseObjectGetObjectDisplayRequirement 1
#define MAXMCP_FACADE_HAS_BaseObjectSetExtendedDisplay 1
#define MAXMCP_FACADE_HAS_BaseObjectGetObjectName 1
#define MAXMCP_FACADE_HAS_BaseObjectOKToChangeTopology 1
#define MAXMCP_FACADE_HAS_BaseObjectChangeTopology 1
#define MAXMCP_FACADE_HAS_BaseObjectForceNotify 1
#define MAXMCP_FACADE_HAS_BaseObjectMove 1
#define MAXMCP_FACADE_HAS_BaseObjectRotate 1
#define MAXMCP_FACADE_HAS_BaseObjectScale 1
#define MAXMCP_FACADE_HAS_BaseObjectTransformStart 1
#define MAXMCP_FACADE_HAS_BaseObjectTransformHoldingStart 1
#define MAXMCP_FACADE_HAS_BaseObjectTransformHoldingFinish 1
#define MAXMCP_FACADE_HAS_BaseObjectTransformFinish 1
#define MAXMCP_FACADE_HAS_BaseObjectTransformCancel 1
#define MAXMCP_FACADE_HAS_BaseObjectCloneSelSubComponents 1
#define MAXMCP_FACADE_HAS_BaseObjectAcceptCloneSelSubComponents 1
#define MAXMCP_FACADE_HAS_BaseObjectClearSelection 1
#define MAXMCP_FACADE_HAS_BaseObjectSelectAll 1
#define MAXMCP_FACADE_HAS_BaseObjectInvertSelection 1
#define MAXMCP_FACADE_HAS_BaseObjectActivateSubSelSet 1
#define MAXMCP_FACADE_HAS_BaseObjectNewSetFromCurSel 1
#define MAXMCP_FACADE_HAS_BaseObjectRemoveSubSelSet 1
#define MAXMCP_FACADE_HAS_BaseObjectSetupNamedSelDropDown 1
#define MAXMCP_FACADE_HAS_BaseObjectNumNamedSelSets 1
#define MAXMCP_FACADE_HAS_BaseObjectGetNamedSelSetName 1
#define MAXMCP_FACADE_HAS_BaseObjectSetNamedSelSetName 1
#define MAXMCP_FACADE_HAS_BaseObjectNumSubObjTypes 1
#define MAXMCP_FACADE_HAS_BaseObjectGetSubObjectLevel 1
#define MAXMCP_FACADE_HAS_BaseObjectHasUVW 1
#define MAXMCP_FACADE_HAS_BaseObjectSetGenUVW 1
#define MAXMCP_FACADE_HAS_BaseObjectShowEndResultChanged 1
#define MAXMCP_FACADE_HAS_BaseObjectHasViewDependentBoundingBox 1
#define MAXMCP_FACADE_HAS_GenLightType 1
#define MAXMCP_FACADE_HAS_GenLightSetType 1
#define MAXMCP_FACADE_HAS_GenLightIsSpot 1
#define MAXMCP_FACADE_HAS_GenLightIsDir 1
#define MAXMCP_FACADE_HAS_GenLightSetSpotShape 1
#define MAXMCP_FACADE_HAS_GenLightGetSpotShape 1
#define MAXMCP_FACADE_HAS_GenLightSetHSVColor 1
#define MAXMCP_FACADE_HAS_GenLightGetHSVColor 1
#define MAXMCP_FACADE_HAS_GenLightSetContrast 1
#define MAXMCP_FACADE_HAS_GenLightGetContrast 1
#define MAXMCP_FACADE_HAS_GenLightSetUseAttenNear 1
#define MAXMCP_FACADE_HAS_GenLightGetUseAttenNear 1
#define MAXMCP_FACADE_HAS_GenLightSetAttenNearDisplay 1
#define MAXMCP_FACADE_HAS_GenLightGetAttenNearDisplay 1
#define MAXMCP_FACADE_HAS_GenLightSetAtmosShadows 1
#define MAXMCP_FACADE_HAS_GenLightGetAtmosShadows 1
#define MAXMCP_FACADE_HAS_GenLightSetAtmosOpacity 1
#define MAXMCP_FACADE_HAS_GenLightGetAtmosOpacity 1
#define MAXMCP_FACADE_HAS_GenLightSetAtmosColAmt 1
#define MAXMCP_FACADE_HAS_GenLightGetAtmosColAmt 1
#define MAXMCP_FACADE_HAS_GenLightSetUseShadowColorMap 1
#define MAXMCP_FACADE_HAS_GenLightGetHotSpotControl 1
#define MAXMCP_FACADE_HAS_GenLightGetFalloffControl 1
#define MAXMCP_FACADE_HAS_GenLightGetColorControl 1
#define MAXMCP_FACADE_HAS_GenLightSetAffectDiffuse 1
#define MAXMCP_FACADE_HAS_GenLightGetAffectDiffuse 1
#define MAXMCP_FACADE_HAS_GenLightSetAffectSpecular 1
#define MAXMCP_FACADE_HAS_GenLightGetAffectSpecular 1
#define MAXMCP_FACADE_HAS_GenLightSetDecayType 1
#define MAXMCP_FACADE_HAS_GenLightGetDecayType 1
#define MAXMCP_FACADE_HAS_GenLightSetDecayRadius 1
#define MAXMCP_FACADE_HAS_GenLightGetDecayRadius 1
#define MAXMCP_FACADE_HAS_GenLightSetDiffuseSoft 1
#define MAXMCP_FACADE_HAS_GenLightGetDiffuseSoft 1
#define MAXMCP_FACADE_HAS_GenLightSetShadColor 1
#define MAXMCP_FACADE_HAS_GenLightGetShadColor 1
#define MAXMCP_FACADE_HAS_GenLightGetLightAffectsShadow 1
#define MAXMCP_FACADE_HAS_GenLightSetLightAffectsShadow 1
#define MAXMCP_FACADE_HAS_GenLightSetShadMult 1
#define MAXMCP_FACADE_HAS_GenLightGetShadMult 1
#define MAXMCP_FACADE_HAS_GenLightGetShadowProjMap 1
#define MAXMCP_FACADE_HAS_GenLightSetAmbientOnly 1
#define MAXMCP_FACADE_HAS_GenLightGetAmbientOnly 1
#define MAXMCP_FACADE_HAS_LightObjSetUseLight 1
#define MAXMCP_FACADE_HAS_LightObjGetUseLight 1
#define MAXMCP_FACADE_HAS_LightObjSetHotspot 1
#define MAXMCP_FACADE_HAS_LightObjGetHotspot 1
#define MAXMCP_FACADE_HAS_LightObjSetFallsize 1
#define MAXMCP_FACADE_HAS_LightObjGetFallsize 1
#define MAXMCP_FACADE_HAS_LightObjSetAtten 1
#define MAXMCP_FACADE_HAS_LightObjGetAtten 1
#define MAXMCP_FACADE_HAS_LightObjSetConeDisplay 1
#define MAXMCP_FACADE_HAS_LightObjGetConeDisplay 1
#define MAXMCP_FACADE_HAS_LightObjGetShadowMethod 1
#define MAXMCP_FACADE_HAS_LightObjSetRGBColor 1
#define MAXMCP_FACADE_HAS_LightObjGetRGBColor 1
#define MAXMCP_FACADE_HAS_LightObjSetIntensity 1
#define MAXMCP_FACADE_HAS_LightObjGetIntensity 1
#define MAXMCP_FACADE_HAS_LightObjSetAspect 1
#define MAXMCP_FACADE_HAS_LightObjGetAspect 1
#define MAXMCP_FACADE_HAS_LightObjSetUseAtten 1
#define MAXMCP_FACADE_HAS_LightObjGetUseAtten 1
#define MAXMCP_FACADE_HAS_LightObjSetAttenDisplay 1
#define MAXMCP_FACADE_HAS_LightObjGetAttenDisplay 1
#define MAXMCP_FACADE_HAS_LightObjEnable 1
#define MAXMCP_FACADE_HAS_LightObjSetMapBias 1
#define MAXMCP_FACADE_HAS_LightObjGetMapBias 1
#define MAXMCP_FACADE_HAS_LightObjSetMapRange 1
#define MAXMCP_FACADE_HAS_LightObjGetMapRange 1
#define MAXMCP_FACADE_HAS_LightObjSetMapSize 1
#define MAXMCP_FACADE_HAS_LightObjGetMapSize 1
#define MAXMCP_FACADE_HAS_LightObjSetRayBias 1
#define MAXMCP_FACADE_HAS_LightObjGetRayBias 1
#define MAXMCP_FACADE_HAS_LightObjGetUseGlobal 1
#define MAXMCP_FACADE_HAS_LightObjSetUseGlobal 1
#define MAXMCP_FACADE_HAS_LightObjGetShadow 1
#define MAXMCP_FACADE_HAS_LightObjSetShadow 1
#define MAXMCP_FACADE_HAS_LightObjGetShadowType 1
#define MAXMCP_FACADE_HAS_LightObjSetShadowType 1
#define MAXMCP_FACADE_HAS_LightObjGetAbsMapBias 1
#define MAXMCP_FACADE_HAS_LightObjSetAbsMapBias 1
#define MAXMCP_FACADE_HAS_LightObjGetOvershoot 1
#define MAXMCP_FACADE_HAS_LightObjSetOvershoot 1
#define MAXMCP_FACADE_HAS_LightObjGetProjector 1
#define MAXMCP_FACADE_HAS_LightObjSetProjector 1
#define MAXMCP_FACADE_HAS_LightObjInclude 1
#define MAXMCP_FACADE_HAS_LightObjGetProjMap 1
#define MAXMCP_FACADE_HAS_StdMatSetSoften 1
#define MAXMCP_FACADE_HAS_StdMatSetFaceMap 1
#define MAXMCP_FACADE_HAS_StdMatSetTwoSided 1
#define MAXMCP_FACADE_HAS_StdMatSetWire 1
#define MAXMCP_FACADE_HAS_StdMatSetWireUnits 1
#define MAXMCP_FACADE_HAS_StdMatSetFalloffOut 1
#define MAXMCP_FACADE_HAS_StdMatSetTransparencyType 1
#define MAXMCP_FACADE_HAS_StdMatSetAmbient 1
#define MAXMCP_FACADE_HAS_StdMatSetDiffuse 1
#define MAXMCP_FACADE_HAS_StdMatSetSpecular 1
#define MAXMCP_FACADE_HAS_StdMatSetFilter 1
#define MAXMCP_FACADE_HAS_StdMatSetShininess 1
#define MAXMCP_FACADE_HAS_StdMatSetShinStr 1
#define MAXMCP_FACADE_HAS_StdMatSetSelfIllum 1
#define MAXMCP_FACADE_HAS_StdMatSetOpacity 1
#define MAXMCP_FACADE_HAS_StdMatSetOpacFalloff 1
#define MAXMCP_FACADE_HAS_StdMatSetWireSize 1
#define MAXMCP_FACADE_HAS_StdMatSetIOR 1
#define MAXMCP_FACADE_HAS_StdMatLockAmbDiffTex 1
#define MAXMCP_FACADE_HAS_StdMatSetSamplingOn 1
#define MAXMCP_FACADE_HAS_StdMatSetShading 1
#define MAXMCP_FACADE_HAS_StdMatGetSamplingOn 1
#define MAXMCP_FACADE_HAS_StdMatGetShading 1
#define MAXMCP_FACADE_HAS_StdMatEnableMap 1
#define MAXMCP_FACADE_HAS_StdMatMapEnabled 1
#define MAXMCP_FACADE_HAS_StdMatSetTexmapAmt 1
#define MAXMCP_FACADE_HAS_StdMatGetTexmapAmt 1
#define MAXMCP_FACADE_HAS_StdMatGetSoften 1
#define MAXMCP_FACADE_HAS_StdMatGetFaceMap 1
#define MAXMCP_FACADE_HAS_StdMatGetTwoSided 1
#define MAXMCP_FACADE_HAS_StdMatGetWire 1
#define MAXMCP_FACADE_HAS_StdMatGetWireUnits 1
#define MAXMCP_FACADE_HAS_StdMatGetFalloffOut 1
#define MAXMCP_FACADE_HAS_StdMatGetTransparencyType 1
#define MAXMCP_FACADE_HAS_StdMatGetAmbient 1
#define MAXMCP_FACADE_HAS_StdMatGetDiffuse 1
#define MAXMCP_FACADE_HAS_StdMatGetSpecular 1
#define MAXMCP_FACADE_HAS_StdMatGetFilter 1
#define MAXMCP_FACADE_HAS_StdMatGetShininess 1
#define MAXMCP_FACADE_HAS_StdMatGetShinStr 1
#define MAXMCP_FACADE_HAS_StdMatGetSelfIllum 1
#define MAXMCP_FACADE_HAS_StdMatGetOpacity 1
#define MAXMCP_FACADE_HAS_StdMatGetOpacFalloff 1
#define MAXMCP_FACADE_HAS_StdMatGetWireSize 1
#define MAXMCP_FACADE_HAS_StdMatGetIOR 1
#define MAXMCP_FACADE_HAS_StdMatGetAmbDiffTexLock 1
#define MAXMCP_FACADE_HAS_ViewExpGetViewID 1
#define MAXMCP_FACADE_HAS_ViewExpIsAlive 1
#define MAXMCP_FACADE_HAS_ViewExpGetPointOnCP 1
#define MAXMCP_FACADE_HAS_ViewExpSnapLength 1
#define MAXMCP_FACADE_HAS_ViewExpGetCPDisp 1
#define MAXMCP_FACADE_HAS_ViewExpIsWire 1
#define MAXMCP_FACADE_HAS_ViewExpMapViewToScreen 1
#define MAXMCP_FACADE_HAS_ViewExpMapScreenToView 1
#define MAXMCP_FACADE_HAS_ViewExpSetAffineTM 1
#define MAXMCP_FACADE_HAS_ViewExpGetAffineTM 1
#define MAXMCP_FACADE_HAS_ViewExpGetViewType 1
#define MAXMCP_FACADE_HAS_ViewExpIsPerspView 1
#define MAXMCP_FACADE_HAS_ViewExpIsCanvasNavigationMode 1
#define MAXMCP_FACADE_HAS_ViewExpGetFOV 1
#define MAXMCP_FACADE_HAS_ViewExpGetFocalDist 1
#define MAXMCP_FACADE_HAS_ViewExpSetFocalDist 1
#define MAXMCP_FACADE_HAS_ViewExpGetFPS 1
#define MAXMCP_FACADE_HAS_ViewExpGetScreenScaleFactor 1
#define MAXMCP_FACADE_HAS_ViewExpGetVPWorldWidth 1
#define MAXMCP_FACADE_HAS_ViewExpNonScalingObjectSize 1
#define MAXMCP_FACADE_HAS_ViewExpGetConstructionTM 1
#define MAXMCP_FACADE_HAS_ViewExpSetGridSize 1
#define MAXMCP_FACADE_HAS_ViewExpGetGridSize 1
#define MAXMCP_FACADE_HAS_ViewExpIsGridVisible 1
#define MAXMCP_FACADE_HAS_ViewExpSetGridVisibility 1
#define MAXMCP_FACADE_HAS_ViewExpGetGridType 1
#define MAXMCP_FACADE_HAS_ViewExpGetViewCamera 1
#define MAXMCP_FACADE_HAS_ViewExpSetViewUser 1
#define MAXMCP_FACADE_HAS_ViewExpGetViewSpot 1
#define MAXMCP_FACADE_HAS_ViewExpClearHitList 1
#define MAXMCP_FACADE_HAS_ViewExpGetClosestHit 1
#define MAXMCP_FACADE_HAS_ViewExpGetHit 1
#define MAXMCP_FACADE_HAS_ViewExpHitCount 1
#define MAXMCP_FACADE_HAS_ViewExpClearSubObjHitList 1
#define MAXMCP_FACADE_HAS_ViewExpNumSubObjHits 1
#define MAXMCP_FACADE_HAS_ViewExpClearCtrlHitList 1
#define MAXMCP_FACADE_HAS_ViewExpSetBkgImageDsp 1
#define MAXMCP_FACADE_HAS_ViewExpGetBkgImageDsp 1
#define MAXMCP_FACADE_HAS_ViewExpSetSFDisplay 1
#define MAXMCP_FACADE_HAS_ViewExpGetSFDisplay 1
#define MAXMCP_FACADE_HAS_ViewExpGetHWnd 1
#define MAXMCP_FACADE_HAS_ViewExpIsActive 1
#define MAXMCP_FACADE_HAS_ViewExpIsEnabled 1
#define MAXMCP_FACADE_HAS_ViewExpSetSolidBackgroundColorMode 1
#define MAXMCP_FACADE_HAS_ViewExpIsSolidBackgroundColorMode 1
#define MAXMCP_FACADE_HAS_ViewExpResetBackgroundColorMode 1
#define MAXMCP_FACADE_HAS_ViewExpReleaseImplicitGrid 1
#define MAXMCP_FACADE_HAS_ViewExp10Pan 1
#define MAXMCP_FACADE_HAS_ViewExp10Zoom 1
#define MAXMCP_FACADE_HAS_ViewExp10Rotate 1
#define MAXMCP_FACADE_HAS_ViewExp10SetFocalDistance 1
#define MAXMCP_FACADE_HAS_ViewExp10Invalidate 1
#define MAXMCP_FACADE_HAS_ViewExp10IsValid 1
#define MAXMCP_FACADE_HAS_ViewExp10SetFOV 1
#define MAXMCP_FACADE_HAS_ViewExp10GetViewportFPS 1
#define MAXMCP_FACADE_HAS_ViewExp10GetViewportClipScale 1
#define MAXMCP_FACADE_HAS_ViewExp10SetViewportClipScale 1
#define MAXMCP_FACADE_HAS_ViewExp10GetAdaptiveDegGoalFPS 1
#define MAXMCP_FACADE_HAS_ViewExp10SetAdaptiveDegGoalFPS 1
#define MAXMCP_FACADE_HAS_ViewExp10GetAdaptiveDegDisplayModeCurrent 1
#define MAXMCP_FACADE_HAS_ViewExp10SetAdaptiveDegDisplayModeCurrent 1
#define MAXMCP_FACADE_HAS_ViewExp10GetAdaptiveDegDisplayModeFastShaded 1
#define MAXMCP_FACADE_HAS_ViewExp10SetAdaptiveDegDisplayModeFastShaded 1
#define MAXMCP_FACADE_HAS_ViewExp10GetAdaptiveDegDisplayModeWire 1
#define MAXMCP_FACADE_HAS_ViewExp10SetAdaptiveDegDisplayModeWire 1
#define MAXMCP_FACADE_HAS_ViewExp10GetAdaptiveDegDisplayModeBox 1
#define MAXMCP_FACADE_HAS_ViewExp10SetAdaptiveDegDisplayModeBox 1
#define MAXMCP_FACADE_HAS_ViewExp10GetAdaptiveDegDisplayModePoint 1
#define MAXMCP_FACADE_HAS_ViewExp10SetAdaptiveDegDisplayModePoint 1
#define MAXMCP_FACADE_HAS_ViewExp10GetAdaptiveDegDisplayModeHide 1
#define MAXMCP_FACADE_HAS_ViewExp10SetAdaptiveDegDisplayModeHide 1
#define MAXMCP_FACADE_HAS_ViewExp10GetAdaptiveDegDrawBackface 1
#define MAXMCP_FACADE_HAS_ViewExp10SetAdaptiveDegDrawBackface 1
#define MAXMCP_FACADE_HAS_ViewExp10GetAdaptiveDegNeverDegradeSelected 1
#define MAXMCP_FACADE_HAS_ViewExp10SetAdaptiveDegNeverDegradeSelected 1
#define MAXMCP_FACADE_HAS_ViewExp10GetAdaptiveDegDegradeLight 1
#define MAXMCP_FACADE_HAS_ViewExp10SetAdaptiveDegDegradeLight 1
#define MAXMCP_FACADE_HAS_ViewExp10GetAdaptiveDegNeverRedrawAfterDegrade 1
#define MAXMCP_FACADE_HAS_ViewExp10SetAdaptiveDegNeverRedrawAfterDegrade 1
#define MAXMCP_FACADE_HAS_ViewExp10GetAdaptiveDegCameraDistancePriority 1
#define MAXMCP_FACADE_HAS_ViewExp10SetAdaptiveDegCameraDistancePriority 1
#define MAXMCP_FACADE_HAS_ViewExp10GetAdaptiveDegScreenSizePriority 1
#define MAXMCP_FACADE_HAS_ViewExp10SetAdaptiveDegScreenSizePriority 1
#define MAXMCP_FACADE_HAS_ViewExp10GetAdaptiveDegMinSize 1
#define MAXMCP_FACADE_HAS_ViewExp10SetAdaptiveDegMinSize 1
#define MAXMCP_FACADE_HAS_ITrackBarSetVisible 1
#define MAXMCP_FACADE_HAS_ITrackBarIsVisible 1
#define MAXMCP_FACADE_HAS_ITrackBarSetFilter 1
#define MAXMCP_FACADE_HAS_ITrackBarGetFilter 1
#define MAXMCP_FACADE_HAS_ITrackBarGetNextKey 1
#define MAXMCP_FACADE_HAS_ITrackBarRedrawTrackBar 1
#define MAXMCP_FACADE_HAS_ITrackBarSetShowFrames 1
#define MAXMCP_FACADE_HAS_ITrackBarGetShowFrames 1
#define MAXMCP_FACADE_HAS_ITrackBarSetShowAudio 1
#define MAXMCP_FACADE_HAS_ITrackBarGetShowAudio 1
#define MAXMCP_FACADE_HAS_ITrackBarSetShowSelectionRange 1
#define MAXMCP_FACADE_HAS_ITrackBarGetShowSelectionRange 1
#define MAXMCP_FACADE_HAS_ITrackBarSetSnapToFrames 1
#define MAXMCP_FACADE_HAS_ITrackBarGetSnapToFrames 1
#define MAXMCP_FACADE_HAS_ITrackBarSetKeyTransparency 1
#define MAXMCP_FACADE_HAS_ITrackBarGetKeyTransparency 1
#define MAXMCP_FACADE_HAS_ITrackBarSetSelKeyTransparency 1
#define MAXMCP_FACADE_HAS_ITrackBarGetSelKeyTransparency 1
#define MAXMCP_FACADE_HAS_ITrackBarSetCursorTransparency 1
#define MAXMCP_FACADE_HAS_ITrackBarGetCursorTransparency 1
#define MAXMCP_FACADE_HAS_EPolyModGetEPolySelLevel 1
#define MAXMCP_FACADE_HAS_EPolyModGetMNSelLevel 1
#define MAXMCP_FACADE_HAS_EPolyModSetEPolySelLevel 1
#define MAXMCP_FACADE_HAS_EPolyModEpModConvertSelection 1
#define MAXMCP_FACADE_HAS_EPolyModGetPolyOperationID 1
#define MAXMCP_FACADE_HAS_EPolyModEpModSetPreserveMap 1
#define MAXMCP_FACADE_HAS_EPolyModEpModGetPreserveMap 1
#define MAXMCP_FACADE_HAS_EPolyModInvalidateDistanceCache 1
#define MAXMCP_FACADE_HAS_EPolyModInvalidateSoftSelectionCache 1
#define MAXMCP_FACADE_HAS_EPolyModEpModSetOperation 1
#define MAXMCP_FACADE_HAS_EPolyModEpModPopupDialog 1
#define MAXMCP_FACADE_HAS_EPolyModEpModButtonOp 1
#define MAXMCP_FACADE_HAS_EPolyModEpModRefreshScreen 1
#define MAXMCP_FACADE_HAS_EPolyModEpModCommitUnlessAnimating 1
#define MAXMCP_FACADE_HAS_EPolyModEpModCommit 1
#define MAXMCP_FACADE_HAS_EPolyModEpModCommitAndRepeat 1
#define MAXMCP_FACADE_HAS_EPolyModEpModCancel 1
#define MAXMCP_FACADE_HAS_EPolyModEpModToggleCommandMode 1
#define MAXMCP_FACADE_HAS_EPolyModEpModEnterCommandMode 1
#define MAXMCP_FACADE_HAS_EPolyModEpModEnterPickMode 1
#define MAXMCP_FACADE_HAS_EPolyModEpModGetCommandMode 1
#define MAXMCP_FACADE_HAS_EPolyModEpModGetPickMode 1
#define MAXMCP_FACADE_HAS_EPolyModSetHitLevelOverride 1
#define MAXMCP_FACADE_HAS_EPolyModClearHitLevelOverride 1
#define MAXMCP_FACADE_HAS_EPolyModGetHitLevelOverride 1
#define MAXMCP_FACADE_HAS_EPolyModSetHitTestResult 1
#define MAXMCP_FACADE_HAS_EPolyModClearHitTestResult 1
#define MAXMCP_FACADE_HAS_EPolyModSetDisplayLevelOverride 1
#define MAXMCP_FACADE_HAS_EPolyModClearDisplayLevelOverride 1
#define MAXMCP_FACADE_HAS_EPolyModGetDisplayLevelOverride 1
#define MAXMCP_FACADE_HAS_EPolyModForceIgnoreBackfacing 1
#define MAXMCP_FACADE_HAS_EPolyModGetForceIgnoreBackfacing 1
#define MAXMCP_FACADE_HAS_EPolyModEpModMoveSelection 1
#define MAXMCP_FACADE_HAS_EPolyModEpModRotateSelection 1
#define MAXMCP_FACADE_HAS_EPolyModEpModScaleSelection 1
#define MAXMCP_FACADE_HAS_EPolyModEpModMoveSlicePlane 1
#define MAXMCP_FACADE_HAS_EPolyModEpModRotateSlicePlane 1
#define MAXMCP_FACADE_HAS_EPolyModEpModScaleSlicePlane 1
#define MAXMCP_FACADE_HAS_EPolyModEpResetSlicePlane 1
#define MAXMCP_FACADE_HAS_EPolyModEpGetSlicePlaneTM 1
#define MAXMCP_FACADE_HAS_EPolyModEpGetSlicePlane 1
#define MAXMCP_FACADE_HAS_EPolyModEpSetSlicePlane 1
#define MAXMCP_FACADE_HAS_EPolyModEpInSliceMode 1
#define MAXMCP_FACADE_HAS_EPolyModEpInSlice 1
#define MAXMCP_FACADE_HAS_EPolyModGetModifier 1
#define MAXMCP_FACADE_HAS_EPolyModUpdateAlignParameters 1
#define MAXMCP_FACADE_HAS_EPolyModUpdateCache 1
#define MAXMCP_FACADE_HAS_EPolyModEpModShowOperationDialog 1
#define MAXMCP_FACADE_HAS_EPolyModEpModShowingOperationDialog 1
#define MAXMCP_FACADE_HAS_EPolyModEpModCloseOperationDialog 1
#define MAXMCP_FACADE_HAS_EPolyModEpModRepeatLast 1
#define MAXMCP_FACADE_HAS_EPolyModEpModGetLastCutEnd 1
#define MAXMCP_FACADE_HAS_EPolyModEpModClearLastCutEnd 1
#define MAXMCP_FACADE_HAS_EPolyModEpModDetachToObject 1
#define MAXMCP_FACADE_HAS_EPolyModEpModCreateShape 1
#define MAXMCP_FACADE_HAS_EPolyModEpModSetRingShift 1
#define MAXMCP_FACADE_HAS_EPolyModEpModSetLoopShift 1
#define MAXMCP_FACADE_HAS_EPolyModEpModConvertSelectionToBorder 1
#define MAXMCP_FACADE_HAS_EPolyModEpModPaintDeformCommit 1
#define MAXMCP_FACADE_HAS_EPolyModEpModPaintDeformCancel 1
#define MAXMCP_FACADE_HAS_EPolyModSmGrpFloater 1
#define MAXMCP_FACADE_HAS_EPolyModMatIDFloater 1
#define MAXMCP_FACADE_HAS_EPolyModMatIDFloaterVisible 1
#define MAXMCP_FACADE_HAS_EPolyModSmGrpFloaterVisible 1
#define MAXMCP_FACADE_HAS_EPolyModCloseSmGrpFloater 1
#define MAXMCP_FACADE_HAS_EPolyModCloseMatIDFloater 1
#define MAXMCP_FACADE_HAS_EPolyModMatIDFloaterHWND 1
#define MAXMCP_FACADE_HAS_EPolyModSmGrpFloaterHWND 1
#define MAXMCP_FACADE_HAS_EPolyModListDeltaOps 1
#define MAXMCP_FACADE_HAS_EPolyModEpModGetLast 1
#define MAXMCP_FACADE_HAS_IBipDriverSetTrackSelection 1
#define MAXMCP_FACADE_HAS_IBipDriverGetTrackSelection 1
#define MAXMCP_FACADE_HAS_IBipDriverSaveBipFileDlg 1
#define MAXMCP_FACADE_HAS_IBipDriverLoadBipFileDlg 1
#define MAXMCP_FACADE_HAS_IBipDriverBeginModes 1
#define MAXMCP_FACADE_HAS_IBipDriverEndModes 1
#define MAXMCP_FACADE_HAS_IBipDriverConvertToFreeForm 1
#define MAXMCP_FACADE_HAS_IBipDriverConvertToFootSteps 1
#define MAXMCP_FACADE_HAS_IBipDriverGetDisplaySettings 1
#define MAXMCP_FACADE_HAS_IBipDriverSetDisplaySettings 1
#define MAXMCP_FACADE_HAS_IBipDriverGetBodyType 1
#define MAXMCP_FACADE_HAS_IBipDriverSetBodyType 1
#define MAXMCP_FACADE_HAS_IBipDriverGetDynamicsType 1
#define MAXMCP_FACADE_HAS_IBipDriverSetDynamicsType 1
#define MAXMCP_FACADE_HAS_IBipDriverGetGravAccel 1
#define MAXMCP_FACADE_HAS_IBipDriverSetGravAccel 1
#define MAXMCP_FACADE_HAS_IBipDriverGetRootName 1
#define MAXMCP_FACADE_HAS_IBipDriverSetRootName 1
#define MAXMCP_FACADE_HAS_IBipDriverSetAdaptLocks 1
#define MAXMCP_FACADE_HAS_IBipDriverSeparateTracks 1
#define MAXMCP_FACADE_HAS_IBipDriverSetBodySpaceNeckRotation 1
#define MAXMCP_FACADE_HAS_IBipDriverGetBodySpaceNeckRotation 1
#define MAXMCP_FACADE_HAS_IBipDriverGetHasArms 1
#define MAXMCP_FACADE_HAS_IBipDriverSetHasArms 1
#define MAXMCP_FACADE_HAS_IBipDriverSetNumLinks 1
#define MAXMCP_FACADE_HAS_IBipDriverGetNumFingers 1
#define MAXMCP_FACADE_HAS_IBipDriverSetNumFingers 1
#define MAXMCP_FACADE_HAS_IBipDriverGetNumToes 1
#define MAXMCP_FACADE_HAS_IBipDriverSetNumToes 1
#define MAXMCP_FACADE_HAS_IBipDriverGetAnkleAttach 1
#define MAXMCP_FACADE_HAS_IBipDriverSetAnkleAttach 1
#define MAXMCP_FACADE_HAS_IBipDriverGetHeight 1
#define MAXMCP_FACADE_HAS_IBipDriverSetHeight 1
#define MAXMCP_FACADE_HAS_IBipDriverGetTrianglePelvis 1
#define MAXMCP_FACADE_HAS_IBipDriverSetTrianglePelvis 1
#define MAXMCP_FACADE_HAS_IBipDriverGetProp1Exists 1
#define MAXMCP_FACADE_HAS_IBipDriverSetProp1Exists 1
#define MAXMCP_FACADE_HAS_IBipDriverGetProp2Exists 1
#define MAXMCP_FACADE_HAS_IBipDriverSetProp2Exists 1
#define MAXMCP_FACADE_HAS_IBipDriverGetProp3Exists 1
#define MAXMCP_FACADE_HAS_IBipDriverSetProp3Exists 1
#define MAXMCP_FACADE_HAS_IBipDriverGetDispBuffer 1
#define MAXMCP_FACADE_HAS_IBipDriverSetDispBuffer 1
#define MAXMCP_FACADE_HAS_IBipDriverGetDispBufferTraj 1
#define MAXMCP_FACADE_HAS_IBipDriverSetDispBufferTraj 1
#define MAXMCP_FACADE_HAS_IBipDriverGetTalentFigMode 1
#define MAXMCP_FACADE_HAS_IBipDriverSetTalentFigMode 1
#define MAXMCP_FACADE_HAS_IBipDriverAdjustTalentPose 1
#define MAXMCP_FACADE_HAS_IBipDriverSaveTalentFigFile 1
#define MAXMCP_FACADE_HAS_IBipDriverSaveTalentPoseFile 1
#define MAXMCP_FACADE_HAS_IBipDriverGetFSAppendState 1
#define MAXMCP_FACADE_HAS_IBipDriverSetFSAppendState 1
#define MAXMCP_FACADE_HAS_IBipDriverGetFSInsertState 1
#define MAXMCP_FACADE_HAS_IBipDriverSetFSInsertState 1
#define MAXMCP_FACADE_HAS_IBipDriverGetGaitMode 1
#define MAXMCP_FACADE_HAS_IBipDriverSetGaitMode 1
#define MAXMCP_FACADE_HAS_IBipDriverGetGroundDur 1
#define MAXMCP_FACADE_HAS_IBipDriverSetGroundDur 1
#define MAXMCP_FACADE_HAS_IBipDriverGetAirDur 1
#define MAXMCP_FACADE_HAS_IBipDriverSetAirDur 1
#define MAXMCP_FACADE_HAS_IBipDriverDoMultipleFSDlg 1
#define MAXMCP_FACADE_HAS_IBipDriverNewFprintKeys 1
#define MAXMCP_FACADE_HAS_IBipDriverBendFootprints 1
#define MAXMCP_FACADE_HAS_IBipDriverScaleFootprints 1
#define MAXMCP_FACADE_HAS_IBipDriverUnifyMotion 1
#define MAXMCP_FACADE_HAS_IBipDriverGetAttachNode 1
#define MAXMCP_FACADE_HAS_IBipDriverGetHeadTarget 1
#define MAXMCP_FACADE_HAS_IBipDriverSetMultipleKeys 1
#define MAXMCP_FACADE_HAS_IBipDriverDoSetMultipleKeysDlg 1
#define MAXMCP_FACADE_HAS_IBipDriverResetAllLimbKeys 1
#define MAXMCP_FACADE_HAS_IBipDriverCollapseMoveAllMode 1
#define MAXMCP_FACADE_HAS_IBipDriverCreateLayer 1
#define MAXMCP_FACADE_HAS_IBipDriverDeleteLayer 1
#define MAXMCP_FACADE_HAS_IBipDriverSetLayerActive 1
#define MAXMCP_FACADE_HAS_IBipDriverSetLayerName 1
#define MAXMCP_FACADE_HAS_IBipDriverGetCurrentLayer 1
#define MAXMCP_FACADE_HAS_IBipDriverSetCurrentLayer 1
#define MAXMCP_FACADE_HAS_IBipDriverUpdateLayers 1
#define MAXMCP_FACADE_HAS_IBipDriverGetVisibleBefore 1
#define MAXMCP_FACADE_HAS_IBipDriverSetVisibleBefore 1
#define MAXMCP_FACADE_HAS_IBipDriverGetVisibleAfter 1
#define MAXMCP_FACADE_HAS_IBipDriverSetVisibleAfter 1
#define MAXMCP_FACADE_HAS_IBipDriverGetKeyHighlight 1
#define MAXMCP_FACADE_HAS_IBipDriverSetKeyHighlight 1
#define MAXMCP_FACADE_HAS_IBipDriverClearPreferredClips 1
#define MAXMCP_FACADE_HAS_IBipDriverGetEnableSubAnims 1
#define MAXMCP_FACADE_HAS_IBipDriverSetEnableSubAnims 1
#define MAXMCP_FACADE_HAS_IBipDriverGetManipSubAnims 1
#define MAXMCP_FACADE_HAS_IBipDriverSetManipSubAnims 1
#define MAXMCP_FACADE_HAS_IBipDriverGetShowAllTracksInTV 1
#define MAXMCP_FACADE_HAS_IBipDriverSetShowAllTracksInTV 1
#define MAXMCP_FACADE_HAS_IBipDriverGetShowBipedInTrackBar 1
#define MAXMCP_FACADE_HAS_IBipDriverSetShowBipedInTrackBar 1
#define MAXMCP_FACADE_HAS_IBipDriverMirror 1
#define MAXMCP_FACADE_HAS_IBipDriverClearAllAnimation 1
#define MAXMCP_FACADE_HAS_IBipDriverClearSelectedAnimation 1
#define MAXMCP_FACADE_HAS_IBipDriverCollapseAllPosSubAnims 1
#define MAXMCP_FACADE_HAS_IBipDriverCollapseAllRotSubAnims 1
#define MAXMCP_FACADE_HAS_IBipDriverCopyPosture 1
#define MAXMCP_FACADE_HAS_IBipDriverDeleteAllCopies 1
#define MAXMCP_FACADE_HAS_IBipDriverDeleteCopy 1
#define MAXMCP_FACADE_HAS_IBipDriverSetCopyName 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetType 1
#define MAXMCP_FACADE_HAS_LightscapeLightType 1
#define MAXMCP_FACADE_HAS_LightscapeLightTypeName 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetDistribution 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetIntensityAt 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetIntensityAt 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetIntensityType 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetFlux 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetFlux 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetRGBFilter 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetRGBFilter 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetHSVFilter 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetHSVFilter 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetShadowGeneratorName 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetShadowGenerator 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetInclude 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetKelvinControl 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetFilterControl 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetKelvin 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetKelvin 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetUseKelvin 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetUseKelvin 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetFullWebFileName 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetWebRotateX 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetWebRotateX 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetWebRotateY 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetWebRotateY 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetWebRotateZ 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetWebRotateZ 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetDimmerValue 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetDimmerValue 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetUseMultiplier 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetUseMultiplier 1
#define MAXMCP_FACADE_HAS_LightscapeLightIsColorShiftEnabled 1
#define MAXMCP_FACADE_HAS_LightscapeLightEnableColorShift 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetResultingIntensity 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetResultingFlux 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetCenter 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetRadius 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetRadius 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetLength 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetLength 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetWidth 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetWidth 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetOriginalFlux 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetOriginalFlux 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetOriginalIntensity 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetOriginalIntensity 1
#define MAXMCP_FACADE_HAS_LightscapeLightGetColorPreset 1
#define MAXMCP_FACADE_HAS_PainterInPaintMode 1
#define MAXMCP_FACADE_HAS_PainterClearStroke 1
#define MAXMCP_FACADE_HAS_PainterAddToStroke 1
#define MAXMCP_FACADE_HAS_PainterGetStrokeCount 1
#define MAXMCP_FACADE_HAS_PainterGetStrFromPoint 1
#define MAXMCP_FACADE_HAS_PainterGetBuildNormalData 1
#define MAXMCP_FACADE_HAS_PainterSetBuildNormalData 1
#define MAXMCP_FACADE_HAS_PainterGetEnablePointGather 1
#define MAXMCP_FACADE_HAS_PainterSetEnablePointGather 1
#define MAXMCP_FACADE_HAS_PainterGetMirrorEnable 1
#define MAXMCP_FACADE_HAS_PainterSetMirrorEnable 1
#define MAXMCP_FACADE_HAS_PainterGetMirrorPlaneCenter 1
#define MAXMCP_FACADE_HAS_PainterGetMirrorAxis 1
#define MAXMCP_FACADE_HAS_PainterSetMirrorAxis 1
#define MAXMCP_FACADE_HAS_PainterGetMirrorOffset 1
#define MAXMCP_FACADE_HAS_PainterSetMirrorOffset 1
#define MAXMCP_FACADE_HAS_PainterGetTreeDepth 1
#define MAXMCP_FACADE_HAS_PainterSetTreeDepth 1
#define MAXMCP_FACADE_HAS_PainterGetUpdateOnMouseUp 1
#define MAXMCP_FACADE_HAS_PainterSetUpdateOnMouseUp 1
#define MAXMCP_FACADE_HAS_PainterGetLagRate 1
#define MAXMCP_FACADE_HAS_PainterSetLagRate 1
#define MAXMCP_FACADE_HAS_PainterGetMinStr 1
#define MAXMCP_FACADE_HAS_PainterSetMinStr 1
#define MAXMCP_FACADE_HAS_PainterGetMaxStr 1
#define MAXMCP_FACADE_HAS_PainterSetMaxStr 1
#define MAXMCP_FACADE_HAS_PainterGetMinSize 1
#define MAXMCP_FACADE_HAS_PainterSetMinSize 1
#define MAXMCP_FACADE_HAS_PainterGetMaxSize 1
#define MAXMCP_FACADE_HAS_PainterSetMaxSize 1
#define MAXMCP_FACADE_HAS_PainterGetAdditiveMode 1
#define MAXMCP_FACADE_HAS_PainterSetAdditiveMode 1
#define MAXMCP_FACADE_HAS_PainterGetDrawRing 1
#define MAXMCP_FACADE_HAS_PainterSetDrawRing 1
#define MAXMCP_FACADE_HAS_PainterGetDrawNormal 1
#define MAXMCP_FACADE_HAS_PainterSetDrawNormal 1
#define MAXMCP_FACADE_HAS_PainterGetDrawTrace 1
#define MAXMCP_FACADE_HAS_PainterSetDrawTrace 1
#define MAXMCP_FACADE_HAS_PainterGetPressureEnable 1
#define MAXMCP_FACADE_HAS_PainterSetPressureEnable 1
#define MAXMCP_FACADE_HAS_PainterGetPressureAffects 1
#define MAXMCP_FACADE_HAS_PainterSetPressureAffects 1
#define MAXMCP_FACADE_HAS_PainterGetPredefinedStrEnable 1
#define MAXMCP_FACADE_HAS_PainterSetPredefinedStrEnable 1
#define MAXMCP_FACADE_HAS_PainterGetPredefinedSizeEnable 1
#define MAXMCP_FACADE_HAS_PainterSetPredefinedSizeEnable 1
#define MAXMCP_FACADE_HAS_PainterGetNormalScale 1
#define MAXMCP_FACADE_HAS_PainterSetNormalScale 1
#define MAXMCP_FACADE_HAS_PainterGetMarkerEnable 1
#define MAXMCP_FACADE_HAS_PainterSetMarkerEnable 1
#define MAXMCP_FACADE_HAS_PainterGetMarker 1
#define MAXMCP_FACADE_HAS_PainterSetMarker 1
#define MAXMCP_FACADE_HAS_PainterGetOffMeshHitType 1
#define MAXMCP_FACADE_HAS_PainterSetOffMeshHitType 1
#define MAXMCP_FACADE_HAS_PainterGetOffMeshHitZDepth 1
#define MAXMCP_FACADE_HAS_PainterSetOffMeshHitZDepth 1
#define MAXMCP_FACADE_HAS_PainterGetOffMeshHitPos 1
#define MAXMCP_FACADE_HAS_PainterSetOffMeshHitPos 1
#define MAXMCP_FACADE_HAS_AtsGetVisible 1
#define MAXMCP_FACADE_HAS_AtsSetVisible 1
#define MAXMCP_FACADE_HAS_AtsNumFilesSelected 1
#define MAXMCP_FACADE_HAS_AtsGetFileSystemStatus 1
#define MAXMCP_FACADE_HAS_AtsNumFiles 1
#define MAXMCP_FACADE_HAS_AtsIsInputFile 1
#define MAXMCP_FACADE_HAS_AtsClearSelection 1
#define MAXMCP_FACADE_HAS_AtsRefresh 1
#define MAXMCP_FACADE_HAS_AtsGetDisabled 1
#define MAXMCP_FACADE_HAS_AtsSetDisabled 1
#define MAXMCP_FACADE_HAS_AtsGetSilent 1
#define MAXMCP_FACADE_HAS_AtsSetSilent 1
#define MAXMCP_FACADE_HAS_AtsGetAutoLogin 1
#define MAXMCP_FACADE_HAS_AtsSetAutoLogin 1
#define MAXMCP_FACADE_HAS_AtsGetTreeView 1
#define MAXMCP_FACADE_HAS_AtsSetTreeView 1
#define MAXMCP_FACADE_HAS_AtsGetTableView 1
#define MAXMCP_FACADE_HAS_AtsSetTableView 1
#define MAXMCP_FACADE_HAS_AtsGetCheckNetworkPaths 1
#define MAXMCP_FACADE_HAS_AtsSetCheckNetworkPaths 1
#define MAXMCP_FACADE_HAS_AtsGetDisplayExcluded 1
#define MAXMCP_FACADE_HAS_AtsSetDisplayExcluded 1
#define MAXMCP_FACADE_HAS_AtsGetExcludeOutputFiles 1
#define MAXMCP_FACADE_HAS_AtsSetExcludeOutputFiles 1
#define MAXMCP_FACADE_HAS_AtsShowPromptsDialog 1
#define MAXMCP_FACADE_HAS_AtsShowWorkingCommentDialog 1
#define MAXMCP_FACADE_HAS_AtsShowStatusLogDialog 1
#define MAXMCP_FACADE_HAS_AtsNumProviders 1
#define MAXMCP_FACADE_HAS_AtsGetProviderName 1
#define MAXMCP_FACADE_HAS_AtsGetActiveProvider 1
#define MAXMCP_FACADE_HAS_AtsSetActiveProvider 1
#define MAXMCP_FACADE_HAS_AtsLoginProvider 1
#define MAXMCP_FACADE_HAS_AtsLogoutProvider 1
#define MAXMCP_FACADE_HAS_AtsIsFileExcluded 1
#define MAXMCP_FACADE_HAS_AtsIsFileShareLocked 1
#define MAXMCP_FACADE_HAS_AtsCheckForDependentFiles 1
#define MAXMCP_FACADE_HAS_AtsCheckForCheckedOutFiles 1
#define MAXMCP_FACADE_HAS_AtsCheckForUnControlledFiles 1
#define MAXMCP_FACADE_HAS_AtsCheckForOutDatedFiles 1
#define MAXMCP_FACADE_HAS_AtsCheckForSceneFileCheckOut 1
#define MAXMCP_FACADE_HAS_AtsSetWorkingComment 1
#define MAXMCP_FACADE_HAS_AtsGetWorkingComment 1
#define MAXMCP_FACADE_HAS_AtsAppendStatusLog 1
#define MAXMCP_FACADE_HAS_AtsClearStatusLog 1
#define MAXMCP_FACADE_HAS_AtsGetStatusLog 1
#define MAXMCP_FACADE_HAS_AtsSetPath 1
#define MAXMCP_FACADE_HAS_AtsSetPathOnSelection 1
#define MAXMCP_FACADE_HAS_AtsResolveSelectionToUNC 1
#define MAXMCP_FACADE_HAS_AtsResolveSelectionRelativeToProjectFolder 1
#define MAXMCP_FACADE_HAS_AtsResolveSelectionToAbsolute 1
#define MAXMCP_FACADE_HAS_GfxWinShutdown 1
#define MAXMCP_FACADE_HAS_GfxWinGetVersion 1
#define MAXMCP_FACADE_HAS_GfxWinConfig 1
#define MAXMCP_FACADE_HAS_GfxWinQuerySupport 1
#define MAXMCP_FACADE_HAS_GfxWinGetHWnd 1
#define MAXMCP_FACADE_HAS_GfxWinSetPos 1
#define MAXMCP_FACADE_HAS_GfxWinSetDisplayState 1
#define MAXMCP_FACADE_HAS_GfxWinGetDisplayState 1
#define MAXMCP_FACADE_HAS_GfxWinGetWinDepth 1
#define MAXMCP_FACADE_HAS_GfxWinGetHitherCoord 1
#define MAXMCP_FACADE_HAS_GfxWinGetYonCoord 1
#define MAXMCP_FACADE_HAS_GfxWinSetFlags 1
#define MAXMCP_FACADE_HAS_GfxWinGetMaxStripLength 1
#define MAXMCP_FACADE_HAS_GfxWinResetUpdateRect 1
#define MAXMCP_FACADE_HAS_GfxWinGetBufAccess 1
#define MAXMCP_FACADE_HAS_GfxWinSetBackgroundOffset 1
#define MAXMCP_FACADE_HAS_GfxWinGetTextureSize 1
#define MAXMCP_FACADE_HAS_GfxWinSetTextureColorOp 1
#define MAXMCP_FACADE_HAS_GfxWinSetTextureAlphaOp 1
#define MAXMCP_FACADE_HAS_GfxWinSetTextureTiling 1
#define MAXMCP_FACADE_HAS_GfxWinGetTextureTiling 1
#define MAXMCP_FACADE_HAS_GfxWinSetTexTransform 1
#define MAXMCP_FACADE_HAS_GfxWinBeginFrame 1
#define MAXMCP_FACADE_HAS_GfxWinEndFrame 1
#define MAXMCP_FACADE_HAS_GfxWinSetViewport 1
#define MAXMCP_FACADE_HAS_GfxWinSetVirtualViewportParams 1
#define MAXMCP_FACADE_HAS_GfxWinSetUseVirtualViewport 1
#define MAXMCP_FACADE_HAS_GfxWinSetTransform 1
#define MAXMCP_FACADE_HAS_GfxWinGetFlipped 1
#define MAXMCP_FACADE_HAS_GfxWinGetTransform 1
#define MAXMCP_FACADE_HAS_GfxWinMultiplePass 1
#define MAXMCP_FACADE_HAS_GfxWinSetSkipCount 1
#define MAXMCP_FACADE_HAS_GfxWinGetSkipCount 1
#define MAXMCP_FACADE_HAS_GfxWinSetRndLimits 1
#define MAXMCP_FACADE_HAS_GfxWinGetRndLimits 1
#define MAXMCP_FACADE_HAS_GfxWinGetRndMode 1
#define MAXMCP_FACADE_HAS_GfxWinSetViewportLimits 1
#define MAXMCP_FACADE_HAS_GfxWinGetMaxLights 1
#define MAXMCP_FACADE_HAS_GfxWinSetLightExclusion 1
#define MAXMCP_FACADE_HAS_GfxWinSetTransparency 1
#define MAXMCP_FACADE_HAS_GfxWinHTransPoint 1
#define MAXMCP_FACADE_HAS_GfxWinUpdateScreen 1
#define MAXMCP_FACADE_HAS_GfxWinLightVertex 1
#define MAXMCP_FACADE_HAS_GfxWinGetTextPointSize 1
#define MAXMCP_FACADE_HAS_GfxWinSetTextPointSize 1
#define MAXMCP_FACADE_HAS_GfxWinGetTextWidthFactor 1
#define MAXMCP_FACADE_HAS_GfxWinSetTextWidthFactor 1
#define MAXMCP_FACADE_HAS_GfxWinStartMarkers 1
#define MAXMCP_FACADE_HAS_GfxWinEndMarkers 1
#define MAXMCP_FACADE_HAS_GfxWinStartSegments 1
#define MAXMCP_FACADE_HAS_GfxWinEndSegments 1
#define MAXMCP_FACADE_HAS_GfxWinStartTriangles 1
#define MAXMCP_FACADE_HAS_GfxWinEndTriangles 1
#define MAXMCP_FACADE_HAS_GfxWinClearHitCode 1
#define MAXMCP_FACADE_HAS_GfxWinCheckHitCode 1
#define MAXMCP_FACADE_HAS_GfxWinSetHitCode 1
#define MAXMCP_FACADE_HAS_GfxWinGetHitDistance 1
#define MAXMCP_FACADE_HAS_GfxWinSetHitDistance 1
#define MAXMCP_FACADE_HAS_GfxWinIsPerspectiveView 1
#define MAXMCP_FACADE_HAS_GfxWinMarkerBufferUnLock 1
#define MAXMCP_FACADE_HAS_GfxWinMarkerBufferDraw 1
#define MAXMCP_FACADE_HAS_GfxWinLineBufferUnLock 1
#define MAXMCP_FACADE_HAS_GfxWinLineBufferDraw 1
#define MAXMCP_FACADE_HAS_TrackViewGetNumTracks 1
#define MAXMCP_FACADE_HAS_TrackViewNumSelTracks 1
#define MAXMCP_FACADE_HAS_TrackViewGetAnim 1
#define MAXMCP_FACADE_HAS_TrackViewGetClient 1
#define MAXMCP_FACADE_HAS_TrackViewCanAssignController 1
#define MAXMCP_FACADE_HAS_TrackViewDoAssignController 1
#define MAXMCP_FACADE_HAS_TrackViewShowControllerType 1
#define MAXMCP_FACADE_HAS_TrackViewGetTVName 1
#define MAXMCP_FACADE_HAS_TrackViewSetTVName 1
#define MAXMCP_FACADE_HAS_TrackViewCloseTreeView 1
#define MAXMCP_FACADE_HAS_TrackViewSetFilter 1
#define MAXMCP_FACADE_HAS_TrackViewClearFilter 1
#define MAXMCP_FACADE_HAS_TrackViewZoomSelected 1
#define MAXMCP_FACADE_HAS_TrackViewExpandTracks 1
#define MAXMCP_FACADE_HAS_TrackViewSelectTrackByIndex 1
#define MAXMCP_FACADE_HAS_TrackViewSetEditMode 1
#define MAXMCP_FACADE_HAS_TrackViewGetEditMode 1
#define MAXMCP_FACADE_HAS_TrackViewIsCurrent 1
#define MAXMCP_FACADE_HAS_TrackViewSetCurrent 1
#define MAXMCP_FACADE_HAS_TrackViewSetAutoZoomOnSelChange 1
#define MAXMCP_FACADE_HAS_TrackViewAutoZoomOnSelChange 1
#define MAXMCP_FACADE_HAS_TrackViewFpSelectTrackByIndex 1
#define MAXMCP_FACADE_HAS_TrackViewModifySubTree 1
#define MAXMCP_FACADE_HAS_TrackViewModifyChildren 1
#define MAXMCP_FACADE_HAS_TrackViewLaunchUtility 1
#define MAXMCP_FACADE_HAS_TrackViewLaunchUtilityDialog 1
#define MAXMCP_FACADE_HAS_TrackViewCloseUtility 1
#define MAXMCP_FACADE_HAS_TrackViewInteractiveUpdate 1
#define MAXMCP_FACADE_HAS_TrackViewSyncTime 1
#define MAXMCP_FACADE_HAS_TrackViewFreezeSelKeys 1
#define MAXMCP_FACADE_HAS_TrackViewFreezeNonSelCurves 1
#define MAXMCP_FACADE_HAS_TrackViewShowNonSelCurves 1
#define MAXMCP_FACADE_HAS_TrackViewShowTangents 1
#define MAXMCP_FACADE_HAS_TrackViewShowFrozenKeys 1
#define MAXMCP_FACADE_HAS_TrackViewIsolateCurve 1
#define MAXMCP_FACADE_HAS_TrackViewUseSoftSelect 1
#define MAXMCP_FACADE_HAS_TrackViewSoftSelectRange 1
#define MAXMCP_FACADE_HAS_TrackViewSoftSelectFalloff 1
#define MAXMCP_FACADE_HAS_TrackViewSetTangentType 1
#define MAXMCP_FACADE_HAS_TrackViewSetInTangentType 1
#define MAXMCP_FACADE_HAS_TrackViewSetOutTangentType 1
#define MAXMCP_FACADE_HAS_TrackViewEffectSelectedObjectsOnly 1
#define MAXMCP_FACADE_HAS_TrackViewManualNavigation 1
#define MAXMCP_FACADE_HAS_TrackViewAutoExpandChildren 1
#define MAXMCP_FACADE_HAS_TrackViewAutoExpandTransforms 1
#define MAXMCP_FACADE_HAS_TrackViewAutoExpandObjects 1
#define MAXMCP_FACADE_HAS_TrackViewAutoExpandModifiers 1
#define MAXMCP_FACADE_HAS_TrackViewAutoExpandMaterials 1
#define MAXMCP_FACADE_HAS_TrackViewAutoExpandXYZ 1
#define MAXMCP_FACADE_HAS_TrackViewAutoSelectAnimated 1
#define MAXMCP_FACADE_HAS_TrackViewAutoSelectPosition 1
#define MAXMCP_FACADE_HAS_TrackViewAutoSelectRotation 1
#define MAXMCP_FACADE_HAS_TrackViewAutoSelectScale 1
#define MAXMCP_FACADE_HAS_TrackViewAutoSelectXYZ 1
#define MAXMCP_FACADE_HAS_TrackViewAutoZoomToRoot 1
#define MAXMCP_FACADE_HAS_TrackViewAutoZoomToSelected 1
#define MAXMCP_FACADE_HAS_TrackViewAutoZoomToEdited 1
#define MAXMCP_FACADE_HAS_TrackViewGetRootTrack 1
#define MAXMCP_FACADE_HAS_TrackViewRestoreDefaultRootTrack 1
#define MAXMCP_FACADE_HAS_TrackViewScaleValuesOrigin 1
#define MAXMCP_FACADE_HAS_TrackViewUpdateList 1
#define MAXMCP_FACADE_HAS_TrackViewReduceKeys 1
#define MAXMCP_FACADE_HAS_TrackViewSplitKey 1
#define MAXMCP_FACADE_HAS_TrackViewStepPreviousKeySelection 1
#define MAXMCP_FACADE_HAS_TrackViewStepNextKeySelection 1
#define MAXMCP_FACADE_HAS_TrackViewShrinkKeySelection 1
#define MAXMCP_FACADE_HAS_TrackViewGrowKeySelection 1
#define MAXMCP_FACADE_HAS_TrackViewEaseToPreviousKey 1
#define MAXMCP_FACADE_HAS_TrackViewEaseToNextKey 1
#define MAXMCP_FACADE_HAS_TrackViewMirrorKeyTangents 1
#define MAXMCP_FACADE_HAS_TrackViewNudgeKey 1
#define MAXMCP_FACADE_HAS_TrackViewScaleTangentsDown 1
#define MAXMCP_FACADE_HAS_TrackViewScaleTangentsUp 1
#define MAXMCP_FACADE_HAS_TrackViewLoopKey 1
#define MAXMCP_FACADE_HAS_TrackViewSnapScaleOriginsToFirstSelectedKey 1
#define MAXMCP_FACADE_HAS_TrackViewSpaceKeyEvenly 1
#define MAXMCP_FACADE_HAS_TrackViewRelaxKeys 1
#define MAXMCP_FACADE_HAS_TrackViewFlattenKeys 1
#define MAXMCP_FACADE_HAS_TrackViewAverageKeys 1
#define MAXMCP_FACADE_HAS_StdUVGenSetCoordMapping 1
#define MAXMCP_FACADE_HAS_StdUVGenSetUOffs 1
#define MAXMCP_FACADE_HAS_StdUVGenSetVOffs 1
#define MAXMCP_FACADE_HAS_StdUVGenSetUScl 1
#define MAXMCP_FACADE_HAS_StdUVGenSetVScl 1
#define MAXMCP_FACADE_HAS_StdUVGenSetAng 1
#define MAXMCP_FACADE_HAS_StdUVGenSetUAng 1
#define MAXMCP_FACADE_HAS_StdUVGenSetVAng 1
#define MAXMCP_FACADE_HAS_StdUVGenSetWAng 1
#define MAXMCP_FACADE_HAS_StdUVGenSetBlur 1
#define MAXMCP_FACADE_HAS_StdUVGenSetBlurOffs 1
#define MAXMCP_FACADE_HAS_StdUVGenSetNoiseAmt 1
#define MAXMCP_FACADE_HAS_StdUVGenSetNoiseSize 1
#define MAXMCP_FACADE_HAS_StdUVGenSetNoiseLev 1
#define MAXMCP_FACADE_HAS_StdUVGenSetNoisePhs 1
#define MAXMCP_FACADE_HAS_StdUVGenSetTextureTiling 1
#define MAXMCP_FACADE_HAS_StdUVGenSetMapChannel 1
#define MAXMCP_FACADE_HAS_StdUVGenSetFlag 1
#define MAXMCP_FACADE_HAS_StdUVGenSetHideMapBackFlag 1
#define MAXMCP_FACADE_HAS_StdUVGenSetUseRealWorldScale 1
#define MAXMCP_FACADE_HAS_StdUVGenGetCoordMapping 1
#define MAXMCP_FACADE_HAS_StdUVGenGetUOffs 1
#define MAXMCP_FACADE_HAS_StdUVGenGetVOffs 1
#define MAXMCP_FACADE_HAS_StdUVGenGetUScl 1
#define MAXMCP_FACADE_HAS_StdUVGenGetVScl 1
#define MAXMCP_FACADE_HAS_StdUVGenGetAng 1
#define MAXMCP_FACADE_HAS_StdUVGenGetUAng 1
#define MAXMCP_FACADE_HAS_StdUVGenGetVAng 1
#define MAXMCP_FACADE_HAS_StdUVGenGetWAng 1
#define MAXMCP_FACADE_HAS_StdUVGenGetBlur 1
#define MAXMCP_FACADE_HAS_StdUVGenGetBlurOffs 1
#define MAXMCP_FACADE_HAS_StdUVGenGetNoiseAmt 1
#define MAXMCP_FACADE_HAS_StdUVGenGetNoiseSize 1
#define MAXMCP_FACADE_HAS_StdUVGenGetNoiseLev 1
#define MAXMCP_FACADE_HAS_StdUVGenGetNoisePhs 1
#define MAXMCP_FACADE_HAS_StdUVGenGetTextureTiling 1
#define MAXMCP_FACADE_HAS_StdUVGenGetMapChannel 1
#define MAXMCP_FACADE_HAS_StdUVGenGetFlag 1
#define MAXMCP_FACADE_HAS_StdUVGenGetHideMapBackFlag 1
#define MAXMCP_FACADE_HAS_StdUVGenGetUseRealWorldScale 1
#define MAXMCP_FACADE_HAS_NodeBakeGetBakeEnabled 1
#define MAXMCP_FACADE_HAS_NodeBakeSetBakeEnabled 1
#define MAXMCP_FACADE_HAS_NodeBakeGetBakeMapChannel 1
#define MAXMCP_FACADE_HAS_NodeBakeSetBakeMapChannel 1
#define MAXMCP_FACADE_HAS_NodeBakeGetNDilations 1
#define MAXMCP_FACADE_HAS_NodeBakeSetNDilations 1
#define MAXMCP_FACADE_HAS_NodeBakeGetSurfaceArea 1
#define MAXMCP_FACADE_HAS_NodeBakeSetSurfaceArea 1
#define MAXMCP_FACADE_HAS_NodeBakeGetAreaScale 1
#define MAXMCP_FACADE_HAS_NodeBakeSetAreaScale 1
#define MAXMCP_FACADE_HAS_NodeBakeGetNBakeElements 1
#define MAXMCP_FACADE_HAS_NodeBakeRemoveBakeElementByName 1
#define MAXMCP_FACADE_HAS_NodeBakeRemoveBakeElementByIndex 1
#define MAXMCP_FACADE_HAS_NodeBakeRemoveAllBakeElements 1
#define MAXMCP_FACADE_HAS_NodeBakeResetBakeProps 1
#define MAXMCP_FACADE_HAS_NodeBakeGetEffectiveEnable 1
#define MAXMCP_FACADE_HAS_NodeBakeGetRenderSize 1
#define MAXMCP_FACADE_HAS_NodeBakeGetActiveTile 1
#define MAXMCP_FACADE_HAS_NodeBakeSetActiveTile 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetEnabled 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetEnabled 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetProjMod 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetProjModTarg 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetProjModTarg 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetCropAlpha 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetCropAlpha 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetProjSpace 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetProjSpace 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetNormalSpace 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetNormalSpace 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetTangentYDir 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetTangentYDir 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetTangentXDir 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetTangentXDir 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetUseCage 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetUseCage 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetRayOffset 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetRayOffset 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetHitResolveMode 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetHitResolveMode 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetHitMatchMtlID 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetHitMatchMtlID 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetHitWorkingModel 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetHitWorkingModel 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetWarnRayMiss 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetWarnRayMiss 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetHeightMapMin 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetHeightMapMin 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetHeightMapMax 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetHeightMapMax 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetHeightBufMin 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetHeightBufMin 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetHeightBufMax 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetHeightBufMax 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetProportionalOutput 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetProportionalOutput 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetBakeMapChannel_SO 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetBakeMapChannel_SO 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetBakeObjLevel 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetBakeObjLevel 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetBakeSubObjLevels 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetBakeSubObjLevels 1
#define MAXMCP_FACADE_HAS_NodeBakeProjGetObjBakeToMtl 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetObjBakeToMtl 1
#define MAXMCP_FACADE_HAS_IGameNodeReleaseIGameObject 1
#define MAXMCP_FACADE_HAS_IGameNodeGetName 1
#define MAXMCP_FACADE_HAS_IGameNodeGetNodeID 1
#define MAXMCP_FACADE_HAS_IGameNodeGetMaxNode 1
#define MAXMCP_FACADE_HAS_IGameNodeGetChildCount 1
#define MAXMCP_FACADE_HAS_IGameNodeGetMaterialIndex 1
#define MAXMCP_FACADE_HAS_IGameNodeGetWireframeColor 1
#define MAXMCP_FACADE_HAS_IGameNodeIsTarget 1
#define MAXMCP_FACADE_HAS_IGameNodeIsGroupOwner 1
#define MAXMCP_FACADE_HAS_IGameNodeIsNodeHidden 1
#define MAXMCP_FACADE_HAS_IGameMeshInitializeBinormalData 1
#define MAXMCP_FACADE_HAS_IGameMeshGetNumberOfVerts 1
#define MAXMCP_FACADE_HAS_IGameMeshGetNumberOfTexVerts 1
#define MAXMCP_FACADE_HAS_IGameMeshGetVertex 1
#define MAXMCP_FACADE_HAS_IGameMeshGetTexVertex 1
#define MAXMCP_FACADE_HAS_IGameMeshSetUseWeightedNormals 1
#define MAXMCP_FACADE_HAS_IGameMeshGetNumberOfNormals 1
#define MAXMCP_FACADE_HAS_IGameMeshGetNormalVertexIndex 1
#define MAXMCP_FACADE_HAS_IGameMeshGetNormal 1
#define MAXMCP_FACADE_HAS_IGameMeshGetNumberOfIllumVerts 1
#define MAXMCP_FACADE_HAS_IGameMeshGetNumberOfAlphaVerts 1
#define MAXMCP_FACADE_HAS_IGameMeshGetNumberOfColorVerts 1
#define MAXMCP_FACADE_HAS_IGameMeshGetColorVertex 1
#define MAXMCP_FACADE_HAS_IGameMeshGetAlphaVertex 1
#define MAXMCP_FACADE_HAS_IGameMeshGetIllumVertex 1
#define MAXMCP_FACADE_HAS_IGameMeshGetNumberOfFaces 1
#define MAXMCP_FACADE_HAS_IGameMeshGetNumberOfMapVerts 1
#define MAXMCP_FACADE_HAS_IGameMeshGetMapVertex 1
#define MAXMCP_FACADE_HAS_IGameMeshGetNumberOfBinormals 1
#define MAXMCP_FACADE_HAS_IGameMeshGetBinormal 1
#define MAXMCP_FACADE_HAS_IGameMeshGetNumberOfTangents 1
#define MAXMCP_FACADE_HAS_IGameMeshGetTangent 1
#define MAXMCP_FACADE_HAS_IGameMeshGetActiveMapChannelNum 1
#define MAXMCP_FACADE_HAS_IGameMeshGetActiveSmgrps 1
#define MAXMCP_FACADE_HAS_IGameMeshGetActiveMatIDs 1
#define MAXMCP_FACADE_HAS_IGameMeshGetFaceIndexFromSmgrp 1
#define MAXMCP_FACADE_HAS_IGameMeshGetFaceVertex 1
#define MAXMCP_FACADE_HAS_IGameMeshGetFaceTextureVertex 1
#define MAXMCP_FACADE_HAS_IGameMeshGetFaceVertexNormal 1
#define MAXMCP_FACADE_HAS_IGameMeshGetFaceVertexTangentBinormal 1
#define MAXMCP_FACADE_HAS_IGameMeshGetFaceSmoothingGroup 1
#define MAXMCP_FACADE_HAS_IGameMeshGetFaceMaterialID 1
#define MAXMCP_FACADE_HAS_IGameMeshGetFaceEdgeVisibility 1
#define MAXMCP_FACADE_HAS_IGameMeshSetCreateOptimizedNormalList 1
#define MAXMCP_FACADE_HAS_IGameMeshGetNumberOfPolygons 1
#define MAXMCP_FACADE_HAS_IGameMeshGetNumberOfPolygonNormals 1
#define MAXMCP_FACADE_HAS_IGameMeshGetNumberOfPolygonCorners 1
#define MAXMCP_FACADE_HAS_IGameMeshGetPolygonNormalsArray 1
#define MAXMCP_FACADE_HAS_IGameMeshGetPolygonSmoothingGroup 1
#define MAXMCP_FACADE_HAS_IGameMeshGetPolygonMaterialID 1
#define MAXMCP_FACADE_HAS_MenuSettingsResetDefaults 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetBorderSz 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetBorderSz 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetHorizontalMarginInPoints 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetHorizontalMarginInPoints 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetVerticalMarginInPoints 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetVerticalMarginInPoints 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetItemFontFace 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetItemFontFace 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetTitleFontFace 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetTitleFontFace 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetItemFontSize 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetItemFontSize 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetTitleFontSize 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetTitleFontSize 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetUseUniformItemHeight 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetUseUniformItemHeight 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetUseUniformItemHeightBOOL 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetUseUniformItemHeightBOOL 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetOpacity 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetOpacity 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetDisplayMethod 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetDisplayMethod 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetAnimatedSteps 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetAnimatedSteps 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetAnimatedStepTime 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetAnimatedStepTime 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetSubMenuPauseTime 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetSubMenuPauseTime 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetUseLastExecutedItem 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetUseLastExecutedItem 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetUseLastExecutedItemBOOL 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetUseLastExecutedItemBOOL 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetRepositionWhenClipped 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetRepositionWhenClipped 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetRepositionWhenClippedBOOL 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetRepositionWhenClippedBOOL 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetRemoveRedundantSeparators 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetRemoveRedundantSeparators 1
#define MAXMCP_FACADE_HAS_MenuSettingsSetRemoveRedundantSeparatorsBOOL 1
#define MAXMCP_FACADE_HAS_MenuSettingsGetRemoveRedundantSeparatorsBOOL 1
#define MAXMCP_FACADE_HAS_QuadMenuSetFirstQuadDisplayed 1
#define MAXMCP_FACADE_HAS_QuadMenuGetFirstQuadDisplayed 1
#define MAXMCP_FACADE_HAS_QuadMenuSetUseUniformQuadWidth 1
#define MAXMCP_FACADE_HAS_QuadMenuGetUseUniformQuadWidth 1
#define MAXMCP_FACADE_HAS_QuadMenuSetUseUniformQuadWidthBOOL 1
#define MAXMCP_FACADE_HAS_QuadMenuGetUseUniformQuadWidthBOOL 1
#define MAXMCP_FACADE_HAS_QuadMenuSetMoveCursorOnReposition 1
#define MAXMCP_FACADE_HAS_QuadMenuGetMoveCursorOnReposition 1
#define MAXMCP_FACADE_HAS_QuadMenuSetMoveCursorOnRepositionBOOL 1
#define MAXMCP_FACADE_HAS_QuadMenuGetMoveCursorOnRepositionBOOL 1
#define MAXMCP_FACADE_HAS_QuadMenuSetReturnCursorAfterReposition 1
#define MAXMCP_FACADE_HAS_QuadMenuGetReturnCursorAfterReposition 1
#define MAXMCP_FACADE_HAS_QuadMenuSetReturnCursorAfterRepositionBOOL 1
#define MAXMCP_FACADE_HAS_QuadMenuGetReturnCursorAfterRepositionBOOL 1
#define MAXMCP_FACADE_HAS_QuadMenuSetCursorLocInBox_0to1 1
#define MAXMCP_FACADE_HAS_QuadMenuGetCursorLocXInBox_0to1 1
#define MAXMCP_FACADE_HAS_QuadMenuGetCursorLocYInBox_0to1 1
#define MAXMCP_FACADE_HAS_QuadMenuSetTitleBarBackgroundColor 1
#define MAXMCP_FACADE_HAS_QuadMenuGetTitleBarBackgroundColor 1
#define MAXMCP_FACADE_HAS_QuadMenuSetTitleBarTextColor 1
#define MAXMCP_FACADE_HAS_QuadMenuGetTitleBarTextColor 1
#define MAXMCP_FACADE_HAS_QuadMenuSetItemBackgroundColor 1
#define MAXMCP_FACADE_HAS_QuadMenuGetItemBackgroundColor 1
#define MAXMCP_FACADE_HAS_QuadMenuSetItemTextColor 1
#define MAXMCP_FACADE_HAS_QuadMenuGetItemTextColor 1
#define MAXMCP_FACADE_HAS_QuadMenuSetLastExecutedItemTextColor 1
#define MAXMCP_FACADE_HAS_QuadMenuGetLastExecutedItemTextColor 1
#define MAXMCP_FACADE_HAS_QuadMenuSetHighlightedItemBackgroundColor 1
#define MAXMCP_FACADE_HAS_QuadMenuGetHighlightedItemBackgroundColor 1
#define MAXMCP_FACADE_HAS_QuadMenuSetHighlightedItemTextColor 1
#define MAXMCP_FACADE_HAS_QuadMenuGetHighlightedItemTextColor 1
#define MAXMCP_FACADE_HAS_QuadMenuSetBorderColor 1
#define MAXMCP_FACADE_HAS_QuadMenuGetBorderColor 1
#define MAXMCP_FACADE_HAS_QuadMenuSetDisabledShadowColor 1
#define MAXMCP_FACADE_HAS_QuadMenuGetDisabledShadowColor 1
#define MAXMCP_FACADE_HAS_QuadMenuSetDisabledHighlightColor 1
#define MAXMCP_FACADE_HAS_QuadMenuGetDisabledHighlightColor 1
#define MAXMCP_FACADE_HAS_GenCameraSetConeState 1
#define MAXMCP_FACADE_HAS_GenCameraGetConeState 1
#define MAXMCP_FACADE_HAS_GenCameraSetHorzLineState 1
#define MAXMCP_FACADE_HAS_GenCameraGetHorzLineState 1
#define MAXMCP_FACADE_HAS_GenCameraEnable 1
#define MAXMCP_FACADE_HAS_GenCameraSetFOVType 1
#define MAXMCP_FACADE_HAS_GenCameraGetFOVType 1
#define MAXMCP_FACADE_HAS_GenCameraGetFOVControl 1
#define MAXMCP_FACADE_HAS_GenCameraType 1
#define MAXMCP_FACADE_HAS_GenCameraSetType 1
#define MAXMCP_FACADE_HAS_GenCameraSetDOFEnable 1
#define MAXMCP_FACADE_HAS_GenCameraSetDOFFStop 1
#define MAXMCP_FACADE_HAS_KeyControlGetNumKeys 1
#define MAXMCP_FACADE_HAS_KeyControlSetNumKeys 1
#define MAXMCP_FACADE_HAS_KeyControlSortKeys 1
#define MAXMCP_FACADE_HAS_KeyControlGetKeySize 1
#define MAXMCP_FACADE_HAS_HoldIsSuspended 1
#define MAXMCP_FACADE_HAS_HoldHolding 1
#define MAXMCP_FACADE_HAS_HoldRedoing 1
#define MAXMCP_FACADE_HAS_HoldRestoreOrRedoing 1
#define MAXMCP_FACADE_HAS_HoldDisableUndo 1
#define MAXMCP_FACADE_HAS_HoldEnableUndo 1
#define MAXMCP_FACADE_HAS_HoldGetBeginDepth 1
#define MAXMCP_FACADE_HAS_HoldRelease 1
#define MAXMCP_FACADE_HAS_HoldEnd 1
#define MAXMCP_FACADE_HAS_HoldGetSuperBeginDepth 1
#define MAXMCP_FACADE_HAS_HoldGetGlobalPutCount 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetVersion 1
#define MAXMCP_FACADE_HAS_ParamBlock2NumParams 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetLocalName 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetOwner 1
#define MAXMCP_FACADE_HAS_ParamBlock2ReleaseDesc 1
#define MAXMCP_FACADE_HAS_ParamBlock2KeyFrameAtTimeByIndex 1
#define MAXMCP_FACADE_HAS_ParamBlock2RemoveControllerByIndex 1
#define MAXMCP_FACADE_HAS_ParamBlock2SwapControllers 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetRefNum 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetControllerRefNum 1
#define MAXMCP_FACADE_HAS_ParamBlock2RescaleParam 1
#define MAXMCP_FACADE_HAS_ParamBlock2EnableNotifications 1
#define MAXMCP_FACADE_HAS_ParamBlock2IsNotificationEnabled 1
#define MAXMCP_FACADE_HAS_ParamBlock2InitMSParameters 1
#define MAXMCP_FACADE_HAS_ParamBlock2ClearParamAliases 1
#define MAXMCP_FACADE_HAS_ParamBlock2ParamAliasCount 1
#define MAXMCP_FACADE_HAS_ParamBlock2ClearSubAnimMap 1
#define MAXMCP_FACADE_HAS_ParamBlock2ResetAll 1
#define MAXMCP_FACADE_HAS_ParamBlock2CallSets 1
#define MAXMCP_FACADE_HAS_ParamBlock2CallGets 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetValidity 1
#define MAXMCP_FACADE_HAS_NodeSetImageBlurMultController 1
#define MAXMCP_FACADE_HAS_NodeSetMotBlurOnOffController 1
#define MAXMCP_FACADE_HAS_NodeSetVisController 1
#define MAXMCP_FACADE_HAS_NodeSetMtl 1
#define MAXMCP_FACADE_HAS_NodeSetXRefParent 1
#define MAXMCP_FACADE_HAS_EPolyModEpModSetSelection 1
#define MAXMCP_FACADE_HAS_EPolyModEpModSetPrimaryNode 1
#define MAXMCP_FACADE_HAS_EPolyModEpModGetNodeTM 1
#define MAXMCP_FACADE_HAS_EPolyModEpModCreateVertex 1
#define MAXMCP_FACADE_HAS_EPolyModEpModSetDiagonal 1
#define MAXMCP_FACADE_HAS_EPolyModEpModCut 1
#define MAXMCP_FACADE_HAS_EPolyModEpModSetCutEnd 1
#define MAXMCP_FACADE_HAS_EPolyModEpModCutCancel 1
#define MAXMCP_FACADE_HAS_EPolyModEpModDivideEdge 1
#define MAXMCP_FACADE_HAS_EPolyModEpModWeldVerts 1
#define MAXMCP_FACADE_HAS_EPolyModEpModWeldEdges 1
#define MAXMCP_FACADE_HAS_EPolyModEpModAttach 1
#define MAXMCP_FACADE_HAS_EPolyModEpModSetHingeEdge 1
#define MAXMCP_FACADE_HAS_EPolyModEpModGetHingeEdge 1
#define MAXMCP_FACADE_HAS_EPolyModEpModBridgeBorders 1
#define MAXMCP_FACADE_HAS_EPolyModEpModBridgePolygons 1
#define MAXMCP_FACADE_HAS_EPolyModEpModSetBridgeNode 1
#define MAXMCP_FACADE_HAS_EPolyModEpModTurnDiagonal 1
#define MAXMCP_FACADE_HAS_EPolyModEpModListOperations 1
#define MAXMCP_FACADE_HAS_EPolyModEpMeshGetNumVertices 1
#define MAXMCP_FACADE_HAS_EPolyModEpMeshGetNumEdges 1
#define MAXMCP_FACADE_HAS_EPolyModEpMeshGetNumFaces 1
#define MAXMCP_FACADE_HAS_EPolyModEpMeshGetFaceDiagonal 1
#define MAXMCP_FACADE_HAS_EPolyModEpModBridgeEdges 1
#define MAXMCP_FACADE_HAS_EPolyModEpModUpdateRingEdgeSelection 1
#define MAXMCP_FACADE_HAS_EPolyModEpModUpdateLoopEdgeSelection 1
#define MAXMCP_FACADE_HAS_EPolyModEPMeshGetFaceNormal 1
#define MAXMCP_FACADE_HAS_EPolyModEPMeshGetFaceCenter 1
#define MAXMCP_FACADE_HAS_EPolyModEPMeshGetFaceArea 1
#define MAXMCP_FACADE_HAS_EPolyModEPMeshGetVertsByFlag 1
#define MAXMCP_FACADE_HAS_EPolyModEPMeshGetEdgesByFlag 1
#define MAXMCP_FACADE_HAS_EPolyModEPMeshGetFacesByFlag 1
#define MAXMCP_FACADE_HAS_EPolyModEPMeshSetVertexFlags 1
#define MAXMCP_FACADE_HAS_EPolyModEPMeshSetEdgeFlags 1
#define MAXMCP_FACADE_HAS_EPolyModEPMeshSetFaceFlags 1
#define MAXMCP_FACADE_HAS_EPolyModEPMeshGetVertexFlags 1
#define MAXMCP_FACADE_HAS_EPolyModEPMeshGetEdgeFlags 1
#define MAXMCP_FACADE_HAS_EPolyModEPMeshGetFaceFlags 1
#define MAXMCP_FACADE_HAS_EPolyModEPMeshGetVertsUsingEdge 1
#define MAXMCP_FACADE_HAS_EPolyModEPMeshSetVert 1
#define MAXMCP_FACADE_HAS_SceneDisplayFilterIsNodeHidden 1
#define MAXMCP_FACADE_HAS_SceneGetTransformAxis 1
#define MAXMCP_FACADE_HAS_SceneCreateObjectNode 1
#define MAXMCP_FACADE_HAS_SceneBindToTarget 1
#define MAXMCP_FACADE_HAS_SceneDeleteNode 1
#define MAXMCP_FACADE_HAS_SceneSetNodeTMRelConstPlane 1
#define MAXMCP_FACADE_HAS_SceneSelectNode 1
#define MAXMCP_FACADE_HAS_SceneDeSelectNode 1
#define MAXMCP_FACADE_HAS_SceneAddLightToScene 1
#define MAXMCP_FACADE_HAS_SceneAddGridToScene 1
#define MAXMCP_FACADE_HAS_SceneSetActiveGrid 1
#define MAXMCP_FACADE_HAS_ScenePutMtlToMtlEditor 1
#define MAXMCP_FACADE_HAS_SceneOkMtlForScene 1
#define MAXMCP_FACADE_HAS_SceneSetLightTintController 1
#define MAXMCP_FACADE_HAS_SceneSetLightLevelController 1
#define MAXMCP_FACADE_HAS_SceneSetBackGroundController 1
#define MAXMCP_FACADE_HAS_SceneDeActivateTexture 1
#define MAXMCP_FACADE_HAS_SceneActivateTexture 1
#define MAXMCP_FACADE_HAS_SceneAssignNewName 1
#define MAXMCP_FACADE_HAS_SceneIsSceneXRefNode 1
#define MAXMCP_FACADE_HAS_SceneCollapseNode 1
#define MAXMCP_FACADE_HAS_IBipDriverSetAttachNode 1
#define MAXMCP_FACADE_HAS_IBipDriverSetHeadTarget 1
#define MAXMCP_FACADE_HAS_IBipDriverSetBipedKey 1
#define MAXMCP_FACADE_HAS_IBipDriverSetPlantedKey 1
#define MAXMCP_FACADE_HAS_IBipDriverSetSlidingKey 1
#define MAXMCP_FACADE_HAS_IBipDriverSetFreeKey 1
#define MAXMCP_FACADE_HAS_IBipDriverSetBipedPos 1
#define MAXMCP_FACADE_HAS_IBipDriverSetBipedRot 1
#define MAXMCP_FACADE_HAS_IBipDriverSetSnapKey 1
#define MAXMCP_FACADE_HAS_IBipDriverCreatePosSubAnims 1
#define MAXMCP_FACADE_HAS_IBipDriverCreateRotSubAnims 1
#define MAXMCP_FACADE_HAS_IBipDriverCreateScaleSubAnims 1
#define MAXMCP_FACADE_HAS_IBipDriverSetPosSubAnim 1
#define MAXMCP_FACADE_HAS_IBipDriverSetRotSubAnim 1
#define MAXMCP_FACADE_HAS_IBipDriverCollapseRotSubAnims 1
#define MAXMCP_FACADE_HAS_IBipDriverCollapsePosSubAnims 1
#define MAXMCP_FACADE_HAS_ILayerSetDisplayByLayer 1
#define MAXMCP_FACADE_HAS_ILayerSetRenderByLayer 1
#define MAXMCP_FACADE_HAS_ILayerSetMotionByLayer 1
#define MAXMCP_FACADE_HAS_ILayerGetDisplayByLayer 1
#define MAXMCP_FACADE_HAS_ILayerGetRenderByLayer 1
#define MAXMCP_FACADE_HAS_ILayerGetMotionByLayer 1
#define MAXMCP_FACADE_HAS_ILayerAddToLayer 1
#define MAXMCP_FACADE_HAS_ILayerDeleteFromLayer 1
#define MAXMCP_FACADE_HAS_ControllerCopy 1
#define MAXMCP_FACADE_HAS_ControllerSetPositionController 1
#define MAXMCP_FACADE_HAS_ControllerSetRotationController 1
#define MAXMCP_FACADE_HAS_ControllerSetScaleController 1
#define MAXMCP_FACADE_HAS_ControllerSetRollController 1
#define MAXMCP_FACADE_HAS_ControllerOKToBindToNode 1
#define MAXMCP_FACADE_HAS_Scene7AddRefCoordNode 1
#define MAXMCP_FACADE_HAS_Scene7AddModToSelection 1
#define MAXMCP_FACADE_HAS_Scene7InvalidateObCache 1
#define MAXMCP_FACADE_HAS_Scene7FindNodeFromBaseObject 1
#define MAXMCP_FACADE_HAS_Scene7SetMtlSlot 1
#define MAXMCP_FACADE_HAS_Scene7SetNodeAttribute 1
#define MAXMCP_FACADE_HAS_GenLightSetHotSpotControl 1
#define MAXMCP_FACADE_HAS_GenLightSetFalloffControl 1
#define MAXMCP_FACADE_HAS_GenLightSetColorControl 1
#define MAXMCP_FACADE_HAS_GenLightSetShadowProjMap 1
#define MAXMCP_FACADE_HAS_TrackViewZoomOn 1
#define MAXMCP_FACADE_HAS_TrackViewGetIndex 1
#define MAXMCP_FACADE_HAS_TrackViewSelectTrack 1
#define MAXMCP_FACADE_HAS_TrackViewSetRootTrack 1
#define MAXMCP_FACADE_HAS_LightscapeLightUpdateTargDistance 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetKelvinControl 1
#define MAXMCP_FACADE_HAS_LightscapeLightSetFilterControl 1
#define MAXMCP_FACADE_HAS_EPolyEpfnDetachToObject 1
#define MAXMCP_FACADE_HAS_EPolyEpfnCreateShape 1
#define MAXMCP_FACADE_HAS_PatchSetVertCont 1
#define MAXMCP_FACADE_HAS_PatchSetVecCont 1
#define MAXMCP_FACADE_HAS_ViewExpSetViewCamera 1
#define MAXMCP_FACADE_HAS_ViewExpSetViewSpot 1
#define MAXMCP_FACADE_HAS_GenCameraSetFOVControl 1
#define MAXMCP_FACADE_HAS_LightObjSetProjMap 1
#define MAXMCP_FACADE_HAS_NodeBakeProjSetProjMod 1
#define MAXMCP_FACADE_HAS_ParamBlock2SetControllerByIndex 1
#define MAXMCP_FACADE_HAS_ParticleExtUpdateParticles 1
#define MAXMCP_FACADE_HAS_Scene16SetOverrideRenderSettingMtl 1
#define MAXMCP_FACADE_HAS_Scene17IsSceneNode 1
#define MAXMCP_FACADE_HAS_Scene8SetRendCamNode 1
#define MAXMCP_FACADE_HAS_SplineSetPtCont 1
#define MAXMCP_FACADE_HAS_ParamBlock2IDtoIndex 1
#define MAXMCP_FACADE_HAS_ParamBlock2IndextoID 1
#define MAXMCP_FACADE_HAS_ParamBlock2SetValue 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetValue 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetColor 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetAColor 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetPoint2 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetPoint3 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetPoint4 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetInt 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetFloat 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetTimeValue 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetStr 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetMtl 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetTexmap 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetINode 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetReferenceTarget 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetMatrix3 1
#define MAXMCP_FACADE_HAS_ParamBlock2Count 1
#define MAXMCP_FACADE_HAS_ParamBlock2ZeroCount 1
#define MAXMCP_FACADE_HAS_ParamBlock2SetCount 1
#define MAXMCP_FACADE_HAS_ParamBlock2Delete 1
#define MAXMCP_FACADE_HAS_ParamBlock2Resize 1
#define MAXMCP_FACADE_HAS_ParamBlock2Shrink 1
#define MAXMCP_FACADE_HAS_ParamBlock2KeyFrameAtTimeByID 1
#define MAXMCP_FACADE_HAS_ParamBlock2SetControllerByID 1
#define MAXMCP_FACADE_HAS_ParamBlock2GetAnimNum 1
#define MAXMCP_FACADE_HAS_ParamBlock2RefDeleted 1
#define MAXMCP_FACADE_HAS_ParamBlock2DefineParamAlias 1
#define MAXMCP_FACADE_HAS_ParamBlock2FindParamAlias 1
#define MAXMCP_FACADE_HAS_ParamBlock2SetSubAnimNum 1
#define MAXMCP_FACADE_HAS_ParamBlock2Reset 1
#define MAXMCP_FACADE_HAS_ParamBlock2CallSet 1
#define MAXMCP_FACADE_HAS_ParamBlock2CallGet 1
#define MAXMCP_FACADE_HAS_RefMakerDeleteMe 1
#define MAXMCP_FACADE_HAS_RefMakerDeleteAllRefsFromMe 1
#define MAXMCP_FACADE_HAS_RefMakerDeleteAllRefsToMe 1
#define MAXMCP_FACADE_HAS_RefMakerDeleteAllRefs 1
#define MAXMCP_FACADE_HAS_RefMakerDeleteReference 1
#define MAXMCP_FACADE_HAS_RefMakerCanTransferReference 1
#define MAXMCP_FACADE_HAS_RefMakerGetReference 1
#define MAXMCP_FACADE_HAS_RefMakerRescaleWorldUnits 1
#define MAXMCP_FACADE_HAS_RefMakerFindRef 1
#define MAXMCP_FACADE_HAS_RefMakerIsRefTarget 1
#define MAXMCP_FACADE_HAS_RefMakerIsRealDependency 1
#define MAXMCP_FACADE_HAS_SplineInvalidateChannels 1
#define MAXMCP_FACADE_HAS_SplineFreeChannels 1
#define MAXMCP_FACADE_HAS_SplineShallowCopy 1
#define MAXMCP_FACADE_HAS_SplineNewAndCopyChannels 1
#define MAXMCP_FACADE_HAS_SplineMultiAttachObject 1
#define MAXMCP_FACADE_HAS_SceneSelectNodeTab 1
#define MAXMCP_FACADE_HAS_SceneFileSaveNodes 1
#define MAXMCP_FACADE_HAS_SceneUngroupNodes 1
#define MAXMCP_FACADE_HAS_SceneExplodeNodes 1
#define MAXMCP_FACADE_HAS_SceneOpenGroup 1
#define MAXMCP_FACADE_HAS_SceneCloseGroup 1
#define MAXMCP_FACADE_HAS_SceneDetachNodesFromGroup 1
#define MAXMCP_FACADE_HAS_SceneFlashNodes 1
#define MAXMCP_FACADE_HAS_ObjectCopyChannelLocks 1
#define MAXMCP_FACADE_HAS_ObjectReadyChannelsForMod 1
#define MAXMCP_FACADE_HAS_ObjectMakeShallowCopy 1
#define MAXMCP_FACADE_HAS_ObjectShallowCopy 1
#define MAXMCP_FACADE_HAS_ObjectFreeChannels 1
#define MAXMCP_FACADE_HAS_ObjectNewAndCopyChannels 1
#define MAXMCP_FACADE_HAS_PatchInvalidateChannels 1
#define MAXMCP_FACADE_HAS_PatchFreeChannels 1
#define MAXMCP_FACADE_HAS_PatchShallowCopy 1
#define MAXMCP_FACADE_HAS_PatchNewAndCopyChannels 1
#define MAXMCP_FACADE_HAS_Scene7PutMaterial 1
#define MAXMCP_FACADE_HAS_PolyNewAndCopyChannels 1
#define MAXMCP_FACADE_HAS_PolyFreeChannels 1
#define MAXMCP_FACADE_HAS_MeshNewAndCopyChannels 1
#define MAXMCP_FACADE_HAS_MeshFreeChannels 1
#define MAXMCP_FACADE_HAS_PatchMeshNewAndCopyChannels 1
#define MAXMCP_FACADE_HAS_PatchMeshFreeChannels 1
#define MAXMCP_FACADE_HAS_EPolyLocalDataChanged 1
#define MAXMCP_FACADE_HAS_EPolyEpfnMultiAttach 1
#define MAXMCP_FACADE_HAS_BezierShapeNewAndCopyChannels 1
#define MAXMCP_FACADE_HAS_BezierShapeFreeChannels 1
#define MAXMCP_FACADE_HAS_Scene13SaveNodesAsVersion 1
#define MAXMCP_FACADE_HAS_EPolyModEpModLocalDataChanged 1
#define MAXMCP_FACADE_HAS_ModifierGetName 1
#define MAXMCP_FACADE_HAS_ModifierDisableModApps 1
#define MAXMCP_FACADE_HAS_ModifierEnableModApps 1
#define MAXMCP_FACADE_HAS_ModifierDisableMod 1
#define MAXMCP_FACADE_HAS_ModifierEnableMod 1
#define MAXMCP_FACADE_HAS_ModifierIsEnabled 1
#define MAXMCP_FACADE_HAS_ModifierDisableModInViews 1
#define MAXMCP_FACADE_HAS_ModifierEnableModInViews 1
#define MAXMCP_FACADE_HAS_ModifierIsEnabledInViews 1
#define MAXMCP_FACADE_HAS_ModifierDisableModInRender 1
#define MAXMCP_FACADE_HAS_ModifierEnableModInRender 1
#define MAXMCP_FACADE_HAS_ModifierIsEnabledInRender 1
#define MAXMCP_FACADE_HAS_ModifierLocalValidity 1
#define MAXMCP_FACADE_HAS_ModifierChangesSelType 1
#define MAXMCP_FACADE_HAS_ModifierTotalChannelsUsed 1
#define MAXMCP_FACADE_HAS_ModifierTotalChannelsChanged 1
#define MAXMCP_FACADE_HAS_ModifierAnyObjectFilter 1
#define MAXMCP_FACADE_HAS_ModifierShouldCollapseOnSave 1
#define MAXMCP_FACADE_HAS_ModifierCopyAdditionalChannels 1
#define MAXMCP_FACADE_HAS_MtlGetActiveTexmap 1
#define MAXMCP_FACADE_HAS_MtlSetActiveTexmap 1
#define MAXMCP_FACADE_HAS_MtlRefDeleted 1
#define MAXMCP_FACADE_HAS_MtlRefAdded 1
#define MAXMCP_FACADE_HAS_MtlGetAmbient 1
#define MAXMCP_FACADE_HAS_MtlGetDiffuse 1
#define MAXMCP_FACADE_HAS_MtlGetSpecular 1
#define MAXMCP_FACADE_HAS_MtlGetShininess 1
#define MAXMCP_FACADE_HAS_MtlGetShinStr 1
#define MAXMCP_FACADE_HAS_MtlGetXParency 1
#define MAXMCP_FACADE_HAS_MtlGetSelfIllumColorOn 1
#define MAXMCP_FACADE_HAS_MtlGetSelfIllum 1
#define MAXMCP_FACADE_HAS_MtlGetSelfIllumColor 1
#define MAXMCP_FACADE_HAS_MtlWireSize 1
#define MAXMCP_FACADE_HAS_MtlSetAmbient 1
#define MAXMCP_FACADE_HAS_MtlSetDiffuse 1
#define MAXMCP_FACADE_HAS_MtlSetSpecular 1
#define MAXMCP_FACADE_HAS_MtlSetShininess 1
#define MAXMCP_FACADE_HAS_MtlSupportsShaders 1
#define MAXMCP_FACADE_HAS_MtlSupportsRenderElements 1
#define MAXMCP_FACADE_HAS_MtlNumSubMtls 1
#define MAXMCP_FACADE_HAS_MtlGetSubMtl 1
#define MAXMCP_FACADE_HAS_MtlSetSubMtl 1
#define MAXMCP_FACADE_HAS_MtlVPDisplaySubMtl 1
#define MAXMCP_FACADE_HAS_MtlGetSubMtlSlotName 1
#define MAXMCP_FACADE_HAS_MtlGetSubMtlTVName 1
#define MAXMCP_FACADE_HAS_MtlCopySubMtl 1
#define MAXMCP_FACADE_HAS_MtlDontKeepOldMtl 1
#define MAXMCP_FACADE_HAS_MtlResolveWrapperMaterials 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnAddBone 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnRemoveBone 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnSelectBone 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnGetSelectedBone 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnGetSelectedMorph 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnResetGraph 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnShrink 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnGrow 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnRing 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnLoop 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnCreateMorph 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnRemoveMorph 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnEdit 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnClearSelectedVertices 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnDeleteSelectedVertices 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnResetOrientation 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnReloadTarget 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnMirrorPaste 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnEditFalloffGraph 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnSetExternalNode 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnMoveVerts 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnTransFormVerts 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnBoneSetInitialNodeTM 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnBoneSetInitialObjectTM 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnBoneSetInitialParentTM 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnBoneGetNumberOfMorphs 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnBoneSetMorphName 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnBoneSetMorphAngle 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnBoneSetMorphTM 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnBoneSetMorphParentTM 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnBoneSetMorphSetDead 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnBoneSetMorphNumPoints 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnBoneSetMorphVertID 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnBoneSetMorphVec 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnBoneSetMorphPVec 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnBoneSetMorphOP 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnBoneGetMorphOwner 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnBoneSetMorphOwner 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnBoneSetMorphFalloff 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnBoneSetJointType 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnUpdate 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnGetWeight 1
#define MAXMCP_FACADE_HAS_MorphByBoneFnBoneSetMorphEnabled 1
#define MAXMCP_FACADE_HAS_ProjectionModNumObjects 1
#define MAXMCP_FACADE_HAS_ProjectionModGetObjectSelLevel 1
#define MAXMCP_FACADE_HAS_ProjectionModDeleteObjectNode 1
#define MAXMCP_FACADE_HAS_ProjectionModNumGeomSels 1
#define MAXMCP_FACADE_HAS_ProjectionModGetGeomSelSelLevel 1
#define MAXMCP_FACADE_HAS_ProjectionModNumGeomSelNodes 1
#define MAXMCP_FACADE_HAS_ProjectionModSetGeomSelMapProportion 1
#define MAXMCP_FACADE_HAS_ProjectionModGetGeomSelMapProportion 1
#define MAXMCP_FACADE_HAS_ProjectionModDeleteGeomSel 1
#define MAXMCP_FACADE_HAS_ProjectionModDeleteGeomSelNode 1
#define MAXMCP_FACADE_HAS_ProjectionModIsValidObject 1
#define MAXMCP_FACADE_HAS_ProjectionModAddObjectNode 1
#define MAXMCP_FACADE_HAS_ProjectionModDeleteAll 1
#define MAXMCP_FACADE_HAS_ProjectionModSetGeomSelNodesVisibility 1
#define MAXMCP_FACADE_HAS_ProjectionModGetGeomSelNodesVisibility 1
#define MAXMCP_FACADE_HAS_ProjectionModUpdateProjectionTypeList 1
#define MAXMCP_FACADE_HAS_ProjectionModAutoWrapCage 1
#define MAXMCP_FACADE_HAS_ProjectionModResetCage 1
#define MAXMCP_FACADE_HAS_ProjectionModPushCage 1
#define MAXMCP_FACADE_HAS_ProjectionModFpGetGeomSelFaceArea 1
#define MAXMCP_FACADE_HAS_ProjectionModFpCheckDuplicateMatIDs 1
#define MAXMCP_FACADE_HAS_ProjectionModFpCheckDuplicateSels 1
#define MAXMCP_FACADE_HAS_ProjectionModFpSelectByMtlID 1
#define MAXMCP_FACADE_HAS_ProjectionModFpSelectBySG 1
#define MAXMCP_FACADE_HAS_ProjectionModFpGetNumProjectionTypes 1
#define MAXMCP_FACADE_HAS_ProjectionModFpGetProjectionType 1
#define MAXMCP_FACADE_HAS_ProjectionModFpRemoveProjectionType 1
#define MAXMCP_FACADE_HAS_ProjectionModFpProject 1
#define MAXMCP_FACADE_HAS_ProjectionModFpProjectAll 1
#define MAXMCP_FACADE_HAS_ProjectionModFpGetNumRegisteredProjectionTypes 1
#define MAXMCP_FACADE_HAS_ProjectionModFpAddRegisteredProjectionType 1
#define MAXMCP_FACADE_HAS_ProjectionModFpShowAlignment 1
#define MAXMCP_FACADE_HAS_ProjectionModFpClearAlignment 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnSetSelLevel 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnMove 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnRotate 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnCopyNormal 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnAverageGlobalNormals 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnAverageTwoNormals 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnSetSelection 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnSelect 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnGetNumNormals 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnSetNormal 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnSetNormalExplicit 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnGetNumFaces 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnGetFaceDegree 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnGetNormalID 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnSetNormalID 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnGetFaceNormalSpecified 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnSetFaceNormalSpecified 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnGetNumVertices 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnGetVertexID 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnGetVertex 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnGetNumEdges 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnGetEdgeID 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnGetFaceEdgeSide 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnGetEdgeVertex 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnGetEdgeFace 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnGetEdgeNormal 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnRebuildNormals 1
#define MAXMCP_FACADE_HAS_EditNormalsModEnfnRecomputeNormals 1
#define MAXMCP_FACADE_HAS_SplineHandleGet 1
#define MAXMCP_FACADE_HAS_SplineCurveNewSpline 1
#define MAXMCP_FACADE_HAS_SplineCurveSegments 1
#define MAXMCP_FACADE_HAS_SplineCurveDeleteKnot 1
#define MAXMCP_FACADE_HAS_SplineCurveGetParam 1
#define MAXMCP_FACADE_HAS_SplineCurveSetKnotType 1
#define MAXMCP_FACADE_HAS_SplineCurveSetLineType 1
#define MAXMCP_FACADE_HAS_SplineCurveCustomParams 1
#define MAXMCP_FACADE_HAS_SplineCurveCompParams 1
#define MAXMCP_FACADE_HAS_SplineCurveComputeBezPoints 1
#define MAXMCP_FACADE_HAS_SplineCurveRefineCurve 1
#define MAXMCP_FACADE_HAS_SplineCurveRefineSegment 1
#define MAXMCP_FACADE_HAS_SplineCurveInterpBezier3D 1
#define MAXMCP_FACADE_HAS_SplineCurveInterpCurve3D 1
#define MAXMCP_FACADE_HAS_SplineCurveTangentBezier3D 1
#define MAXMCP_FACADE_HAS_SplineCurveTangentCurve3D 1
#define MAXMCP_FACADE_HAS_SplineCurveIsAuto 1
#define MAXMCP_FACADE_HAS_SplineCurveIsBezierPt 1
#define MAXMCP_FACADE_HAS_SplineCurveIsCorner 1
#define MAXMCP_FACADE_HAS_SplineCurveDrawPhase 1
#define MAXMCP_FACADE_HAS_SplineCurveGetiCur 1
#define MAXMCP_FACADE_HAS_SplineCurveGetBBox 1
#define MAXMCP_FACADE_HAS_SplineCurveSetClosed 1
#define MAXMCP_FACADE_HAS_SplineCurveSetOpen 1
#define MAXMCP_FACADE_HAS_SplineCurveDump 1
#define MAXMCP_FACADE_HAS_SplineCurveGetInVec 1
#define MAXMCP_FACADE_HAS_SplineCurveSetInVec 1
#define MAXMCP_FACADE_HAS_SplineCurveGetRelInVec 1
#define MAXMCP_FACADE_HAS_SplineCurveSetRelInVec 1
#define MAXMCP_FACADE_HAS_SplineCurveGetKnotPoint 1
#define MAXMCP_FACADE_HAS_SplineCurveSetKnotPoint 1
#define MAXMCP_FACADE_HAS_SplineCurveGetOutVec 1
#define MAXMCP_FACADE_HAS_SplineCurveSetOutVec 1
#define MAXMCP_FACADE_HAS_SplineCurveGetRelOutVec 1
#define MAXMCP_FACADE_HAS_SplineCurveSetRelOutVec 1
#define MAXMCP_FACADE_HAS_SplineCurveGetKnotUserFlag 1
#define MAXMCP_FACADE_HAS_SplineCurveSetKnotUserFlag 1
#define MAXMCP_FACADE_HAS_SplineCurveClearKnotUserFlag 1
#define MAXMCP_FACADE_HAS_SplineCurveGetAux 1
#define MAXMCP_FACADE_HAS_SplineCurveSetAux 1
#define MAXMCP_FACADE_HAS_SplineCurveGetAux2 1
#define MAXMCP_FACADE_HAS_SplineCurveSetAux2 1
#define MAXMCP_FACADE_HAS_SplineCurveGetAux3 1
#define MAXMCP_FACADE_HAS_SplineCurveSetAux3 1
#define MAXMCP_FACADE_HAS_SplineCurveGetKnotAux 1
#define MAXMCP_FACADE_HAS_SplineCurveSetKnotAux 1
#define MAXMCP_FACADE_HAS_SplineCurveGetInAux 1
#define MAXMCP_FACADE_HAS_SplineCurveSetInAux 1
#define MAXMCP_FACADE_HAS_SplineCurveGetOutAux 1
#define MAXMCP_FACADE_HAS_SplineCurveSetOutAux 1
#define MAXMCP_FACADE_HAS_SplineCurveGetVertAux 1
#define MAXMCP_FACADE_HAS_SplineCurveSetVertAux 1
#define MAXMCP_FACADE_HAS_SplineCurveGetMatID 1
#define MAXMCP_FACADE_HAS_SplineCurveSetMatID 1
#define MAXMCP_FACADE_HAS_SplineCurveSplineLength 1
#define MAXMCP_FACADE_HAS_SplineCurveSegmentLength 1
#define MAXMCP_FACADE_HAS_SplineCurveReverse 1
#define MAXMCP_FACADE_HAS_SplineCurveIsClockWise 1
#define MAXMCP_FACADE_HAS_SplineCurveSelfIntersects 1
#define MAXMCP_FACADE_HAS_SplineCurveSurroundsPoint 1
#define MAXMCP_FACADE_HAS_SplineCurveInvalidateGeomCache 1
#define MAXMCP_FACADE_HAS_MeshMapHandleGet 1
#define MAXMCP_FACADE_HAS_MeshMapVAlloc 1
#define MAXMCP_FACADE_HAS_MeshMapFAlloc 1
#define MAXMCP_FACADE_HAS_MeshMapNewTri 1
#define MAXMCP_FACADE_HAS_MeshMapNewQuad 1
#define MAXMCP_FACADE_HAS_MeshMapSetNumFaces 1
#define MAXMCP_FACADE_HAS_MeshMapSetNumVerts 1
#define MAXMCP_FACADE_HAS_MeshMapClearAndFree 1
#define MAXMCP_FACADE_HAS_MeshMapTransform 1
#define MAXMCP_FACADE_HAS_MeshMapNewAndCopy 1
#define MAXMCP_FACADE_HAS_MNNormalInitialize 1
#define MAXMCP_FACADE_HAS_MNNormalNAlloc 1
#define MAXMCP_FACADE_HAS_MNNormalNShrink 1
#define MAXMCP_FACADE_HAS_MNNormalFAlloc 1
#define MAXMCP_FACADE_HAS_MNNormalFShrink 1
#define MAXMCP_FACADE_HAS_MNNormalClearAndFree 1
#define MAXMCP_FACADE_HAS_MNNormalSetNumFaces 1
#define MAXMCP_FACADE_HAS_MNNormalSetNumNormals 1
#define MAXMCP_FACADE_HAS_MNNormalGetNormal 1
#define MAXMCP_FACADE_HAS_MNNormalSetNormal 1
#define MAXMCP_FACADE_HAS_MNNormalGetNormalIndex 1
#define MAXMCP_FACADE_HAS_MNNormalSetNormalIndex 1
#define MAXMCP_FACADE_HAS_MNNormalNewNormal 1
#define MAXMCP_FACADE_HAS_MNNormalCollapseDeadFaces 1
#define MAXMCP_FACADE_HAS_MNNormalClearNormals 1
#define MAXMCP_FACADE_HAS_MNNormalBuildNormals 1
#define MAXMCP_FACADE_HAS_MNNormalComputeNormals 1
#define MAXMCP_FACADE_HAS_MNNormalCheckNormals 1
#define MAXMCP_FACADE_HAS_MNNormalAdjustToParent 1
#define MAXMCP_FACADE_HAS_MNNormalCheckAllData 1
#define MAXMCP_FACADE_HAS_MNNormalNewAndCopyChannels 1
#define MAXMCP_FACADE_HAS_MNNormalFreeChannels 1
#define MAXMCP_FACADE_HAS_MNNormalZeroChannels 1
#define MAXMCP_FACADE_HAS_ControllerSetInheritanceFlags 1
#define MAXMCP_FACADE_HAS_BitmapLoad 1
#define MAXMCP_FACADE_HAS_BitmapWidth 1
#define MAXMCP_FACADE_HAS_BitmapHeight 1
#define MAXMCP_FACADE_HAS_BitmapGetFiltered 1
#define MAXMCP_FACADE_HAS_BitmapGetPixels 1
#define MAXMCP_FACADE_HAS_MeshDeltaExtrudeFaces 1
#define MAXMCP_FACADE_HAS_MeshDeltaExtrudeEdges 1
#define MAXMCP_FACADE_HAS_MeshDeltaDivideFaces 1
#define MAXMCP_FACADE_HAS_MeshDeltaExplodeFaces 1
#define MAXMCP_FACADE_HAS_MeshDeltaWeldByThreshold 1
#define MAXMCP_FACADE_HAS_MeshDeltaSlice 1
#define MAXMCP_FACADE_HAS_FaceClustersCreate 1
#define MAXMCP_FACADE_HAS_FaceClustersCount 1
#define MAXMCP_FACADE_HAS_PolyExtrudeFaceClusters 1
#define MAXMCP_FACADE_HAS_PolyExtrudeFaceCluster 1
#define MAXMCP_FACADE_HAS_LinkChainLinkCount 1
#define MAXMCP_FACADE_HAS_LinkChainPreBone 1
#define MAXMCP_FACADE_HAS_LinkChainBone 1
#define MAXMCP_FACADE_HAS_LinkChainParentMatrix 1
#define MAXMCP_FACADE_HAS_LinkChainRootRotation 1
#define MAXMCP_FACADE_HAS_LinkChainLinkDofAxis 1
#define MAXMCP_FACADE_HAS_LinkChainLinkDofValue 1
#define MAXMCP_FACADE_HAS_LinkChainLinkLimits 1
#define MAXMCP_FACADE_HAS_LinkChainLinkMatrix 1
#define MAXMCP_FACADE_HAS_LinkChainSetLinkDofValue 1
#define MAXMCP_FACADE_HAS_LinkChainSetRootRotation 1
#define MAXMCP_FACADE_HAS_ShadeContextRaw 1
#define MAXMCP_FACADE_HAS_GpuDeviceRaw 1
#define MAXMCP_FACADE_HAS_MocapStreamRaw 1
#define MAXMCP_FACADE_HAS_MeshIntersectRay 1
#define MAXMCP_FACADE_HAS_MeshFindVertexAngles 1
#define MAXMCP_FACADE_HAS_ObjectGetDeformBBox 1
#define MAXMCP_FACADE_HAS_ObjectLockObject 1
#define MAXMCP_FACADE_HAS_ObjectUnlockObject 1
#define MAXMCP_FACADE_HAS_ObjectIsObjectLocked 1
#define MAXMCP_FACADE_HAS_ObjectLockChannels 1
#define MAXMCP_FACADE_HAS_ObjectUnlockChannels 1
#define MAXMCP_FACADE_HAS_ObjectHasWeights 1
#define MAXMCP_FACADE_HAS_ObjectMergeAdditionalChannels 1
#define MAXMCP_FACADE_HAS_PolyEliminateBadVerts 1
#define MAXMCP_FACADE_HAS_PolyCollapseEdges 1
#define MAXMCP_FACADE_HAS_PolyAddTri 1
#define MAXMCP_FACADE_HAS_PolyPropegateComponentFlags 1
#define MAXMCP_FACADE_HAS_PolyGetNewSmGroup 1
#define MAXMCP_FACADE_HAS_MNChamferDataCreate 1
#define MAXMCP_FACADE_HAS_PolyExtrudeVertices 1
#define MAXMCP_FACADE_HAS_MeshDeltaAttachMesh 1
#define MAXMCP_FACADE_HAS_MeshDeltaDetach 1
#define MAXMCP_FACADE_HAS_MeshDeltaCollapseEdges 1
#define MAXMCP_FACADE_HAS_MeshDeltaWeldVertSet 1
#define MAXMCP_FACADE_HAS_MeshDeltaCut 1
#define MAXMCP_FACADE_HAS_MeshDeltaBevel 1
#define MAXMCP_FACADE_HAS_ConvertMeshToPatch 1
#define MAXMCP_FACADE_HAS_ConvertPatchToMesh 1
#define MAXMCP_FACADE_HAS_ConvertPolyToPatch 1
#define MAXMCP_FACADE_HAS_ConvertPatchToPoly 1
#define MAXMCP_FACADE_HAS_BitmapPutPixels 1
#define MAXMCP_FACADE_HAS_BitmapGet16Gray 1
#define MAXMCP_FACADE_HAS_BitmapCreate 1
#define MAXMCP_FACADE_HAS_BitmapOpenOutput 1
#define MAXMCP_FACADE_HAS_BitmapSave 1
#define MAXMCP_FACADE_HAS_BitmapClose 1
#define MAXMCP_FACADE_HAS_BitmapChannelsPresent 1
#define MAXMCP_FACADE_HAS_BitmapCreateChannels 1
#define MAXMCP_FACADE_HAS_BitmapGetChannel 1
#define MAXMCP_FACADE_HAS_BitmapAspect 1
#define MAXMCP_FACADE_HAS_BitmapGetRenderInfo 1
#define MAXMCP_FACADE_HAS_PatchVertSelRead 1
#define MAXMCP_FACADE_HAS_PatchEdgeSelRead 1
#define MAXMCP_FACADE_HAS_PatchPatchSelRead 1
#define MAXMCP_FACADE_HAS_PatchVecSelRead 1
#define MAXMCP_FACADE_HAS_PatchVertSelWrite 1
#define MAXMCP_FACADE_HAS_PatchEdgeSelWrite 1
#define MAXMCP_FACADE_HAS_PatchPatchSelWrite 1
#define MAXMCP_FACADE_HAS_PatchVecSelWrite 1
#define MAXMCP_FACADE_HAS_PatchMeshVertexTempSelRead 1
#define MAXMCP_FACADE_HAS_PatchMeshVertexWeightRead 1
#define MAXMCP_FACADE_HAS_PatchMeshWeldByThreshold 1
#define MAXMCP_FACADE_HAS_SplineCurveGetKnotType 1
#define MAXMCP_FACADE_HAS_BezierShapeVertexTempSel 1
#define MAXMCP_FACADE_HAS_PolySelLevelRead 1
#define MAXMCP_FACADE_HAS_ShapeObjGetRectangular 1
#define MAXMCP_FACADE_HAS_ShapeObjSetRectangular 1
#define MAXMCP_FACADE_HAS_ShapeObjGetWidth 1
#define MAXMCP_FACADE_HAS_ShapeObjSetWidth 1
#define MAXMCP_FACADE_HAS_ShapeObjGetLength 1
#define MAXMCP_FACADE_HAS_ShapeObjSetLength 1
#define MAXMCP_FACADE_HAS_ShapeObjGetAngle2 1
#define MAXMCP_FACADE_HAS_ShapeObjSetAngle2 1
#define MAXMCP_FACADE_HAS_ShapeObjGetAspectLock 1
#define MAXMCP_FACADE_HAS_ShapeObjSetAspectLock 1
#define MAXMCP_FACADE_HAS_ShapeObjGetVPTRectangular 1
#define MAXMCP_FACADE_HAS_ShapeObjSetVPTRectangular 1
#define MAXMCP_FACADE_HAS_ShapeObjGetVPTWidth 1
#define MAXMCP_FACADE_HAS_ShapeObjSetVPTWidth 1
#define MAXMCP_FACADE_HAS_ShapeObjGetVPTLength 1
#define MAXMCP_FACADE_HAS_ShapeObjSetVPTLength 1
#define MAXMCP_FACADE_HAS_ShapeObjGetVPTAngle2 1
#define MAXMCP_FACADE_HAS_ShapeObjSetVPTAngle2 1
#define MAXMCP_FACADE_HAS_ShapeObjGetVPTAspectLock 1
#define MAXMCP_FACADE_HAS_ShapeObjSetVPTAspectLock 1
#define MAXMCP_FACADE_HAS_ShapeObjGetAutosmooth 1
#define MAXMCP_FACADE_HAS_ShapeObjSetAutosmooth 1
#define MAXMCP_FACADE_HAS_ShapeObjGetAutosmoothThreshold 1
#define MAXMCP_FACADE_HAS_ShapeObjSetAutosmoothThreshold 1
#define MAXMCP_FACADE_HAS_TriDispApproxRead 1
#define MAXMCP_FACADE_HAS_TriDispApproxWrite 1
#define MAXMCP_FACADE_HAS_PolyDispApproxRead 1
#define MAXMCP_FACADE_HAS_PolyDispApproxWrite 1
#define MAXMCP_FACADE_HAS_TriDisableDisplacementRead 1
#define MAXMCP_FACADE_HAS_TriDisableDisplacementWrite 1
#define MAXMCP_FACADE_HAS_PolyDisableDisplacementRead 1
#define MAXMCP_FACADE_HAS_PolyDisableDisplacementWrite 1
#define MAXMCP_FACADE_HAS_TriSplitMeshRead 1
#define MAXMCP_FACADE_HAS_TriSplitMeshWrite 1
#define MAXMCP_FACADE_HAS_PolySplitMeshRead 1
#define MAXMCP_FACADE_HAS_PolySplitMeshWrite 1
#define MAXMCP_FACADE_HAS_TriSubDivideDisplacementRead 1
#define MAXMCP_FACADE_HAS_TriSubDivideDisplacementWrite 1
#define MAXMCP_FACADE_HAS_PolySubDivideDisplacementRead 1
#define MAXMCP_FACADE_HAS_PolySubDivideDisplacementWrite 1
#define MAXMCP_FACADE_HAS_SceneMtlCount 1
#define MAXMCP_FACADE_HAS_SceneMtlGet 1
#define MAXMCP_FACADE_HAS_MtlLibCount 1
#define MAXMCP_FACADE_HAS_MtlLibGet 1
#define MAXMCP_FACADE_HAS_DllDirCount 1
#define MAXMCP_FACADE_HAS_DllDescFileName 1
#define MAXMCP_FACADE_HAS_DllDescIsLoaded 1
#define MAXMCP_FACADE_HAS_ScenePropertyCount 1
#define MAXMCP_FACADE_HAS_ScenePropertyName 1
#define MAXMCP_FACADE_HAS_ScenePropertyValue 1
#define MAXMCP_FACADE_HAS_NodeEnumAuxFiles 1
#define MAXMCP_FACADE_HAS_SceneImportFromFile 1
#define MAXMCP_FACADE_HAS_SceneNewFile 1
#define MAXMCP_FACADE_HAS_SceneRenderFrame 1
#define MAXMCP_FACADE_HAS_ToneOperatorGetPhysicalUnit 1
#define MAXMCP_FACADE_HAS_ParamDimensionConvert 1
#define MAXMCP_FACADE_HAS_ParamDimensionUnConvert 1
#define MAXMCP_FACADE_HAS_ForceFieldCreate 1
#define MAXMCP_FACADE_HAS_ForceFieldForce 1
#define MAXMCP_FACADE_HAS_ForceFieldForceN 1
#define MAXMCP_FACADE_HAS_CollisionObjectCreate 1
#define MAXMCP_FACADE_HAS_CollisionObjectCheck 1
#define MAXMCP_FACADE_HAS_CurveCtlNumCurves 1
#define MAXMCP_FACADE_HAS_CurveCtlGetValue 1
#define MAXMCP_FACADE_HAS_CurveCtlGetValueN 1
#define MAXMCP_FACADE_HAS_BitmapTexAssetCreate 1
#define MAXMCP_FACADE_HAS_AssetUserFileName 1
#define MAXMCP_FACADE_HAS_AssetUserFullFilePath 1
#define MAXMCP_FACADE_HAS_AssetUserId 1
#define MAXMCP_FACADE_HAS_AssetUserType 1
#define MAXMCP_FACADE_HAS_FaceDataChanCount 1
#define MAXMCP_FACADE_HAS_FaceDataChanList 1
#define MAXMCP_FACADE_HAS_FaceDataChanObjectCount 1
#define MAXMCP_FACADE_HAS_PolyShapeCreate 1
#define MAXMCP_FACADE_HAS_MeshCapInfoCreate 1
#define MAXMCP_FACADE_HAS_MeshCapperCreate 1
#define MAXMCP_FACADE_HAS_MeshCapInfoFaceCount 1
#define MAXMCP_FACADE_HAS_MeshCapInfoVertCount 1
#define MAXMCP_FACADE_HAS_MeshCapperCapMesh 1
#define MAXMCP_FACADE_HAS_NodeEvalWorldMeshRead 1
#define MAXMCP_FACADE_HAS_NodeEvalWorldStateTM 1
#define MAXMCP_FACADE_HAS_LinkChainGoalInfo 1
#define MAXMCP_FACADE_HAS_LinkChainGoalMatrix 1
#define MAXMCP_FACADE_HAS_LinkChainGoalSwivelAngle 1
#define MAXMCP_FACADE_HAS_LinkChainGoalChainNormal 1
#define MAXMCP_FACADE_HAS_LinkChainGoalVHTarget 1
#define MAXMCP_FACADE_HAS_LinkChainJointsRead 1
#define MAXMCP_FACADE_HAS_LinkChainEndEffectorMatrix 1
#define MAXMCP_FACADE_HAS_LinkChainRootInitRotation 1
#define MAXMCP_FACADE_HAS_LinkChainRootLimits 1
#define MAXMCP_FACADE_HAS_LinkChainRootDof 1
#define MAXMCP_FACADE_HAS_LinkChainRootRigidExtend 1
#define MAXMCP_FACADE_HAS_LinkChainRootLinkMatrix 1
#define MAXMCP_FACADE_HAS_LinkChainLinkInitValue 1
#define MAXMCP_FACADE_HAS_LinkChainLinkFlags 1
#define MAXMCP_FACADE_HAS_LinkChainLinkDofMatrix 1
#define MAXMCP_FACADE_HAS_SubObjectAxes 1
#define MAXMCP_FACADE_HAS_ViewMapScreenToWorldRay 1
#define MAXMCP_FACADE_HAS_ViewPickNode 1
#define MAXMCP_FACADE_HAS_ObjectIntersectRay 1
#define MAXMCP_FACADE_HAS_ManipCurrentEvent 1
#define MAXMCP_FACADE_HAS_ViewBorrowedRay 1
#define MAXMCP_FACADE_HAS_OsnapCurrentEvent 1
#define MAXMCP_FACADE_HAS_OsnapRecordHit 1
#define MAXMCP_FACADE_HAS_ParticleContainerCurrent 1
#define MAXMCP_FACADE_HAS_ParticleChannelCount 1
#define MAXMCP_FACADE_HAS_ParticlePositionGet 1
#define MAXMCP_FACADE_HAS_ParticlePositionSet 1
#define MAXMCP_FACADE_HAS_ParticleSpeedGet 1
#define MAXMCP_FACADE_HAS_ParticleSpeedSet 1
#define MAXMCP_FACADE_HAS_ParticleAccelerationGet 1
#define MAXMCP_FACADE_HAS_ParticleAccelerationSet 1
#define MAXMCP_FACADE_HAS_ParticleScaleGet 1
#define MAXMCP_FACADE_HAS_ParticleScaleSet 1
#define MAXMCP_FACADE_HAS_ParticleOrientationGet 1
#define MAXMCP_FACADE_HAS_ParticleOrientationSet 1
#define MAXMCP_FACADE_HAS_ParticleSpinGet 1
#define MAXMCP_FACADE_HAS_ParticleSpinSet 1
#define MAXMCP_FACADE_HAS_ParticleSelectionGet 1
#define MAXMCP_FACADE_HAS_ParticleSelectionSet 1
#define MAXMCP_FACADE_HAS_ParticleMaterialIndexGet 1
#define MAXMCP_FACADE_HAS_ParticleMaterialIndexSet 1
#define MAXMCP_FACADE_HAS_ParticleTimeGet 1
#define MAXMCP_FACADE_HAS_ParticleTimeSet 1
#define MAXMCP_FACADE_HAS_ParticleBirthTimeGet 1
#define MAXMCP_FACADE_HAS_ParticleBirthTimeSet 1
#define MAXMCP_FACADE_HAS_ParticleDeathTimeGet 1
#define MAXMCP_FACADE_HAS_ParticleDeathTimeSet 1
#define MAXMCP_FACADE_HAS_ParticleLifespanGet 1
#define MAXMCP_FACADE_HAS_ParticleLifespanSet 1
#define MAXMCP_FACADE_HAS_ParticleEventStartGet 1
#define MAXMCP_FACADE_HAS_ParticleEventStartSet 1
#define MAXMCP_FACADE_HAS_ParticleIsNew 1
#define MAXMCP_FACADE_HAS_ParticleIsAllNew 1
#define MAXMCP_FACADE_HAS_ParticleIsAllOld 1
#define MAXMCP_FACADE_HAS_ParticleSetNew 1
#define MAXMCP_FACADE_HAS_ParticleSetOld 1
#define MAXMCP_FACADE_HAS_ParticleSetAllNew 1
#define MAXMCP_FACADE_HAS_ParticleSetAllOld 1
#define MAXMCP_FACADE_HAS_ParticleGetIndex 1
#define MAXMCP_FACADE_HAS_ParticleGetBorn 1
#define MAXMCP_FACADE_HAS_ParticleSetID 1
#define MAXMCP_FACADE_HAS_ParticlePositionEnsure 1
#define MAXMCP_FACADE_HAS_ParticleSpeedEnsure 1
#define MAXMCP_FACADE_HAS_ParticleAccelerationEnsure 1
#define MAXMCP_FACADE_HAS_ParticleScaleEnsure 1
#define MAXMCP_FACADE_HAS_ParticleOrientationEnsure 1
#define MAXMCP_FACADE_HAS_ParticleSpinEnsure 1
#define MAXMCP_FACADE_HAS_ParticleSelectionEnsure 1
#define MAXMCP_FACADE_HAS_ParticleMaterialIndexEnsure 1
#define MAXMCP_FACADE_HAS_ParticleTimeEnsure 1
#define MAXMCP_FACADE_HAS_ParticleBirthTimeEnsure 1
#define MAXMCP_FACADE_HAS_ParticleDeathTimeEnsure 1
#define MAXMCP_FACADE_HAS_ParticleLifespanEnsure 1
#define MAXMCP_FACADE_HAS_ParticleEventStartEnsure 1
#define MAXMCP_FACADE_HAS_ParticleShapeIsShared 1
#define MAXMCP_FACADE_HAS_ParticleShapeValueCount 1
#define MAXMCP_FACADE_HAS_ParticleShapeValueIndex 1
#define MAXMCP_FACADE_HAS_ParticleShapeSetFromNode 1
#define MAXMCP_FACADE_HAS_ParticleShapeSetGlobalFromNode 1
#define MAXMCP_FACADE_HAS_ParticleShapeCopyValue 1
#define MAXMCP_FACADE_HAS_ParticleShapeCopyValueToAll 1
#define MAXMCP_FACADE_HAS_ParticleShapeNodeGet 1
#define MAXMCP_FACADE_HAS_ParticleShapeNodeSet 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureNumMaps 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureMapSupport 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureSetNumMaps 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureSetMapSupport 1
#define MAXMCP_FACADE_HAS_ParticleMXSFloatGet 1
#define MAXMCP_FACADE_HAS_ParticleMXSFloatSet 1
#define MAXMCP_FACADE_HAS_ParticleMXSIntegerGet 1
#define MAXMCP_FACADE_HAS_ParticleMXSIntegerSet 1
#define MAXMCP_FACADE_HAS_ParticleMXSVectorGet 1
#define MAXMCP_FACADE_HAS_ParticleMXSVectorSet 1
#define MAXMCP_FACADE_HAS_ParticleMXSMatrixGet 1
#define MAXMCP_FACADE_HAS_ParticleMXSMatrixSet 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureIsUVVertShared 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureUVVertCount 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureUVVertIndex 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureUVVertRead 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureUVVertSet 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureUVVertSetPlanar 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureUVVertCopy 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureUVVertCopyToAll 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureIsTVFaceShared 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureTVFaceCount 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureTVFaceIndex 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureTVFaceRead 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureTVFaceSet 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureTVFaceCopy 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureTVFaceCopyToAll 1
#define MAXMCP_FACADE_HAS_ParticleShapeSetManyFromNode 1
#define MAXMCP_FACADE_HAS_ParticleShapeCopyValueToMany 1
#define MAXMCP_FACADE_HAS_ParticleShapeNodeSetMany 1
#define MAXMCP_FACADE_HAS_ParticleShapeNodeCopyValueToMany 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureUVVertSetPlanarMany 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureUVVertCopyToMany 1
#define MAXMCP_FACADE_HAS_ParticleShapeTextureTVFaceCopyToMany 1
#define MAXMCP_FACADE_HAS_MxsPrimitiveCurrentCall 1
#define MAXMCP_FACADE_HAS_MxsPrimitiveArg 1
#define MAXMCP_FACADE_HAS_MxsPrimitiveSetResult 1
#define MAXMCP_FACADE_HAS_ColorPipeGetLastErrorFunction 1
#define MAXMCP_FACADE_HAS_ColorPipeGetLastErrorText 1
#define MAXMCP_FACADE_HAS_ColorPipeClearLastError 1
#define MAXMCP_FACADE_HAS_ColorPipeSetDisplayGamma 1
#define MAXMCP_FACADE_HAS_ColorPipeGetDisplayGamma 1
#define MAXMCP_FACADE_HAS_ColorPipeSetDefaultFileInGamma 1
#define MAXMCP_FACADE_HAS_ColorPipeGetDefaultFileInGamma 1
#define MAXMCP_FACADE_HAS_ColorPipeSetDefaultFileOutGamma 1
#define MAXMCP_FACADE_HAS_ColorPipeGetDefaultFileOutGamma 1
#define MAXMCP_FACADE_HAS_ColorPipeGetBlackbodyColor 1
#define MAXMCP_FACADE_HAS_ColorPipeGetCIEDaylightColor 1
#define MAXMCP_FACADE_HAS_ColorPipeSaveSystemDefaults 1
#define MAXMCP_FACADE_HAS_ColorPipeLoadSystemDefaults 1
#define MAXMCP_FACADE_HAS_ColorPipeGetColorPipelineMode 1
#define MAXMCP_FACADE_HAS_ColorPipeSetColorPipelineMode 1
#define MAXMCP_FACADE_HAS_NurbsSetOfNode 1
#define MAXMCP_FACADE_HAS_NurbsSetObjectCount 1
#define MAXMCP_FACADE_HAS_NurbsObjectType 1
#define MAXMCP_FACADE_HAS_NurbsObjectId 1
#define MAXMCP_FACADE_HAS_NurbsObjectName 1
#define MAXMCP_FACADE_HAS_NurbsCVSurfaceSize 1
#define MAXMCP_FACADE_HAS_NurbsCVSurfaceGetCV 1
#define MAXMCP_FACADE_HAS_NurbsCVSurfaceGetKnot 1
#define MAXMCP_FACADE_HAS_NurbsCVSurfaceSetCV 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceEvaluate 1
#define MAXMCP_FACADE_HAS_NurbsCVCurveSize 1
#define MAXMCP_FACADE_HAS_NurbsCVCurveGetCV 1
#define MAXMCP_FACADE_HAS_NurbsCurveEvaluate 1
#define MAXMCP_FACADE_HAS_NurbsPointGetPosition 1
#define MAXMCP_FACADE_HAS_NurbsSetCreate 1
#define MAXMCP_FACADE_HAS_NurbsSetAppendSphere 1
#define MAXMCP_FACADE_HAS_MtlBaseSetName 1
#define MAXMCP_FACADE_HAS_MtlBaseGetFullName 1
#define MAXMCP_FACADE_HAS_MtlBaseSetMtlFlag 1
#define MAXMCP_FACADE_HAS_MtlBaseClearMtlFlag 1
#define MAXMCP_FACADE_HAS_MtlBaseTestMtlFlag 1
#define MAXMCP_FACADE_HAS_MtlBaseAnyMulti 1
#define MAXMCP_FACADE_HAS_MtlBaseRequirements 1
#define MAXMCP_FACADE_HAS_MtlBaseLocalRequirements 1
#define MAXMCP_FACADE_HAS_MtlBaseIsMultiMtl 1
#define MAXMCP_FACADE_HAS_MtlBaseDeactivateMapsInTree 1
#define MAXMCP_FACADE_HAS_MtlBaseUpdate 1
#define MAXMCP_FACADE_HAS_MtlBaseReset 1
#define MAXMCP_FACADE_HAS_MtlBaseDiscardPStamp 1
#define MAXMCP_FACADE_HAS_MtlBaseSupportTexDisplay 1
#define MAXMCP_FACADE_HAS_MtlBaseIncrActive 1
#define MAXMCP_FACADE_HAS_MtlBaseDecrActive 1
#define MAXMCP_FACADE_HAS_MtlBaseActivateTexDisplay 1
#define MAXMCP_FACADE_HAS_MtlBaseGetActiveMB 1
#define MAXMCP_FACADE_HAS_MtlBaseSetActiveMB 1
#define MAXMCP_FACADE_HAS_MtlBaseSupportsMultiMapsInViewport 1
#define MAXMCP_FACADE_HAS_MtlBaseGetRefTarget 1
#define MAXMCP_FACADE_HAS_MtlBaseGetTransparencyHint 1
#define MAXMCP_FACADE_HAS_ControllerCreateDefaultFloat 1
#define MAXMCP_FACADE_HAS_ControllerCreateDefaultPoint3 1
#define MAXMCP_FACADE_HAS_ControllerCreateDefaultMatrix3 1
#define MAXMCP_FACADE_HAS_ControllerCreateDefaultPosition 1
#define MAXMCP_FACADE_HAS_ControllerCreateDefaultRotation 1
#define MAXMCP_FACADE_HAS_ControllerCreateDefaultScale 1
#define MAXMCP_FACADE_HAS_ControllerCreateDefaultBool 1
#define MAXMCP_FACADE_HAS_ControllerCreateDefaultColor 1
#define MAXMCP_FACADE_HAS_ControllerCreateDefaultPoint4 1
#define MAXMCP_FACADE_HAS_ControllerCreateDefaultFRGBA 1
#define MAXMCP_FACADE_HAS_ControllerCreateDefaultPoint2 1
#define MAXMCP_FACADE_HAS_ControllerCreateInterpFloat 1
#define MAXMCP_FACADE_HAS_ControllerCreateInterpPosition 1
#define MAXMCP_FACADE_HAS_ControllerCreateInterpPoint3 1
#define MAXMCP_FACADE_HAS_ControllerCreateInterpRotation 1
#define MAXMCP_FACADE_HAS_ControllerCreateInterpScale 1
#define MAXMCP_FACADE_HAS_ControllerCreatePRS 1
#define MAXMCP_FACADE_HAS_ControllerCreateLookat 1
#define MAXMCP_FACADE_HAS_ControllerCreateInterpPoint4 1
#define MAXMCP_FACADE_HAS_ControllerCreateInterpPoint2 1
#define MAXMCP_FACADE_HAS_CurveCtlSetNumCurves 1
#define MAXMCP_FACADE_HAS_CurveCtlDeleteAllCurves 1
#define MAXMCP_FACADE_HAS_CurveCtlDeleteCurve 1
#define MAXMCP_FACADE_HAS_CurveCtlSetXRange 1
#define MAXMCP_FACADE_HAS_CurveCtlSetYRange 1
#define MAXMCP_FACADE_HAS_CurveCtlSetCCFlags 1
#define MAXMCP_FACADE_HAS_CurveCtlSetNumPts 1
#define MAXMCP_FACADE_HAS_CurveCtlSetPoint 1
#define MAXMCP_FACADE_HAS_CurveCtlInsertPoint 1
#define MAXMCP_FACADE_HAS_CurveCtlDeletePoint 1
#define MAXMCP_FACADE_HAS_CurveCtlSetOutOfRangeType 1
#define MAXMCP_FACADE_HAS_CurveCtlSetPenProperty 1
#define MAXMCP_FACADE_HAS_LinkChainInitJointAngles 1
#define MAXMCP_FACADE_HAS_LinkChainSetJointAngles 1
#define MAXMCP_FACADE_HAS_LinkChainSetLinkInitValue 1
#define MAXMCP_FACADE_HAS_LinkChainSetLinkLimits 1
#define MAXMCP_FACADE_HAS_LinkChainSetLinkLimited 1
#define MAXMCP_FACADE_HAS_LinkChainSetLinkRigidExtend 1
#define MAXMCP_FACADE_HAS_LinkChainSetRootInitRotation 1
#define MAXMCP_FACADE_HAS_LinkChainSetRootLimits 1
#define MAXMCP_FACADE_HAS_LinkChainSetRootRigidExtend 1
#define MAXMCP_FACADE_HAS_LinkChainSetRootDof 1
#define MAXMCP_FACADE_HAS_LinkChainLinkApplyLinkMatrix 1
#define MAXMCP_FACADE_HAS_LinkChainRootApplyLinkMatrix 1
#define MAXMCP_FACADE_HAS_LinkChainRootRotateByAxis 1
#define MAXMCP_FACADE_HAS_LinkChainSplineGoalInfo 1
#define MAXMCP_FACADE_HAS_LinkChainSplineGoalPosAt 1
#define MAXMCP_FACADE_HAS_LinkChainGoalZeroPlaneMap 1
#define MAXMCP_FACADE_HAS_PolyCut 1
#define MAXMCP_FACADE_HAS_PolyCutVersioned 1
#define MAXMCP_FACADE_HAS_PolyAutoSmoothIsland 1
#define MAXMCP_FACADE_HAS_PolyExtrudeOpenEdges 1
#define MAXMCP_FACADE_HAS_PolyBridgeBorders 1
#define MAXMCP_FACADE_HAS_PolyBridgePolygons 1
#define MAXMCP_FACADE_HAS_PolyBridgePolygonClusters 1
#define MAXMCP_FACADE_HAS_PolyBridgeSelectedBorders 1
#define MAXMCP_FACADE_HAS_PolyTurnDiagonal 1
#define MAXMCP_FACADE_HAS_PolyCutPrepare 1
#define MAXMCP_FACADE_HAS_PolyCutCleanup 1
#define MAXMCP_FACADE_HAS_PolyBridgeTwoEdges 1
#define MAXMCP_FACADE_HAS_PolyBridgeSelectedEdges 1
#define MAXMCP_FACADE_HAS_PolyChamferEdges 1
#define MAXMCP_FACADE_HAS_PolyChamferVertices 1
#define MAXMCP_FACADE_HAS_PolyInvalidateVertexCache 1
#define MAXMCP_FACADE_HAS_ColorPipeGetPipeline 1
#define MAXMCP_FACADE_HAS_ColorPipeGetGammaPipeline 1
#define MAXMCP_FACADE_HAS_ColorPipeGetDefaultViewingPipeline 1
#define MAXMCP_FACADE_HAS_ColorPipeGetViewingPipeline 1
#define MAXMCP_FACADE_HAS_ColorPipeGetAdvancedViewingPipeline 1
#define MAXMCP_FACADE_HAS_ColorPipeGetPipelineParamToRendering 1
#define MAXMCP_FACADE_HAS_ColorPipeGetPipelineRenderingToParam 1
#define MAXMCP_FACADE_HAS_ColorPipeGetPipelineLinSRGBToRendering 1
#define MAXMCP_FACADE_HAS_ColorPipeGetPipelineRenderingToLinSRGB 1
#define MAXMCP_FACADE_HAS_ColorPipeParamCount 1
#define MAXMCP_FACADE_HAS_ColorPipeGetDiagnosticString 1
#define MAXMCP_FACADE_HAS_ColorPipeParamName 1
#define MAXMCP_FACADE_HAS_ColorPipeParamGetValue 1
#define MAXMCP_FACADE_HAS_ColorPipeParamSetValue 1
#define MAXMCP_FACADE_HAS_ColorPipeSettingsMode 1
#define MAXMCP_FACADE_HAS_ColorPipeSettingsIsActive 1
#define MAXMCP_FACADE_HAS_ColorPipeSettingsIsOCIOBased 1
#define MAXMCP_FACADE_HAS_ColorPipeSettingsGetStatus 1
#define MAXMCP_FACADE_HAS_ColorPipeSettingsGetLocked 1
#define MAXMCP_FACADE_HAS_ColorPipeSettingsSetLocked 1
#define MAXMCP_FACADE_HAS_ColorPipeSettingsGetModeDescription 1
#define MAXMCP_FACADE_HAS_ColorPipeSettingsGetColorSpaceDescription 1
#define MAXMCP_FACADE_HAS_ColorPipeSettingsGetDisplayViewDescription 1
#define MAXMCP_FACADE_HAS_ColorPipeSettingsGetColorSpaceFlags 1
#define MAXMCP_FACADE_HAS_ColorPipeSettingsReInitialize 1
#define MAXMCP_FACADE_HAS_ColorPipeSettingsGetOCIOConfigFilePath 1
#define MAXMCP_FACADE_HAS_ColorPipeSettingsSetOCIOConfigFilePath 1
#define MAXMCP_FACADE_HAS_ColorPipeSettingsGetOCIOConfigFileSource 1
#define MAXMCP_FACADE_HAS_AssetGet 1
#define MAXMCP_FACADE_HAS_AssetGetById 1
#define MAXMCP_FACADE_HAS_AssetAddReference 1
#define MAXMCP_FACADE_HAS_AssetReleaseReference 1
#define MAXMCP_FACADE_HAS_AssetUserSetUsedInFileSave 1
#define MAXMCP_FACADE_HAS_PathConfigGetAssetDirCount 1
#define MAXMCP_FACADE_HAS_PathConfigGetAssetDir 1
#define MAXMCP_FACADE_HAS_PathConfigAddAssetDir 1
#define MAXMCP_FACADE_HAS_PathConfigDeleteAssetDir 1
#define MAXMCP_FACADE_HAS_PathConfigGetCurAssetDirCount 1
#define MAXMCP_FACADE_HAS_PathConfigGetCurAssetDir 1
#define MAXMCP_FACADE_HAS_PathConfigAddSessionAssetDir 1
#define MAXMCP_FACADE_HAS_PathConfigUpdateAssetSection 1
#define MAXMCP_FACADE_HAS_PathConfigGetDir 1
#define MAXMCP_FACADE_HAS_PathConfigSetDir 1
#define MAXMCP_FACADE_HAS_PathConfigLoad 1
#define MAXMCP_FACADE_HAS_PathConfigMerge 1
#define MAXMCP_FACADE_HAS_PathConfigSave 1
#define MAXMCP_FACADE_HAS_PathConfigAppendSlash 1
#define MAXMCP_FACADE_HAS_PathConfigRemoveSlash 1
#define MAXMCP_FACADE_HAS_DxMaterialEffectBitmapCount 1
#define MAXMCP_FACADE_HAS_DxMaterialGetEffectFile 1
#define MAXMCP_FACADE_HAS_DxMaterialSetEffectFile 1
#define MAXMCP_FACADE_HAS_AssetAccessorCurrent 1
#define MAXMCP_FACADE_HAS_AssetAccessorSetCurrent 1
#define MAXMCP_FACADE_HAS_OsnapGetNode 1
#define MAXMCP_FACADE_HAS_OsnapOKForRelativeSnap 1
#define MAXMCP_FACADE_HAS_OsnapRefPointWasSnapped 1
#define MAXMCP_FACADE_HAS_OsnapGetRefPoint 1
#define MAXMCP_FACADE_HAS_OsnapGetObjectTM 1
#define MAXMCP_FACADE_HAS_OsnapGetTime 1
#define MAXMCP_FACADE_HAS_OsnapGetCurrentPoint 1
#define MAXMCP_FACADE_HAS_OsnapGetSnapStrength 1
#define MAXMCP_FACADE_HAS_OsnapWTranspoint 1
#define MAXMCP_FACADE_HAS_OsnapGetVpt 1
#define MAXMCP_FACADE_HAS_OsnapGetSnapInfo 1
#define MAXMCP_FACADE_HAS_OsnapGetSnapRadius 1
#define MAXMCP_FACADE_HAS_OsnapGetSnapPreviewRadius 1
#define MAXMCP_FACADE_HAS_ManipCurrentGizmoBuild 1
#define MAXMCP_FACADE_HAS_GizmoShapeStartNewLine 1
#define MAXMCP_FACADE_HAS_GizmoShapeAppendPoint 1
#define MAXMCP_FACADE_HAS_GizmoShapeAppendPolyline 1
#define MAXMCP_FACADE_HAS_GizmoShapeMakeCircle 1
#define MAXMCP_FACADE_HAS_GizmoShapeMakeRect 1
#define MAXMCP_FACADE_HAS_GizmoBuildSetAppearance 1
#define MAXMCP_FACADE_HAS_RenderContextCurrent 1
#define MAXMCP_FACADE_HAS_RenderGlobalContextInfo 1
#define MAXMCP_FACADE_HAS_RenderGlobalContextCamToWorld 1
#define MAXMCP_FACADE_HAS_RenderGlobalContextWorldToCam 1
#define MAXMCP_FACADE_HAS_RenderGlobalContextMapToScreen 1
#define MAXMCP_FACADE_HAS_RenderGlobalContextRenderer 1
#define MAXMCP_FACADE_HAS_RenderGlobalContextEnvMap 1
#define MAXMCP_FACADE_HAS_RenderGlobalContextAtmos 1
#define MAXMCP_FACADE_HAS_RenderGlobalContextToneOp 1
#define MAXMCP_FACADE_HAS_RenderGlobalContextNumRenderInstances 1
#define MAXMCP_FACADE_HAS_CheckAbortCheck 1
#define MAXMCP_FACADE_HAS_CheckAbortProgress 1
#define MAXMCP_FACADE_HAS_ViewParamsInfo 1
#define MAXMCP_FACADE_HAS_ViewParamsAffineTM 1
#define MAXMCP_FACADE_HAS_ViewParamsPrevAffineTM 1
#define MAXMCP_FACADE_HAS_RendParamsInfo 1
#define MAXMCP_FACADE_HAS_RendParamsEnvMap 1
#define MAXMCP_FACADE_HAS_RendParamsAtmos 1
#define MAXMCP_FACADE_HAS_RendParamsEffect 1
#define MAXMCP_FACADE_HAS_RendParamsToneOp 1
#define MAXMCP_FACADE_HAS_RendProgressProgress 1
#define MAXMCP_FACADE_HAS_RendProgressSetTitle 1
#define MAXMCP_FACADE_HAS_RendProgressSetCurField 1
#define MAXMCP_FACADE_HAS_RendProgressSetStep 1
#define MAXMCP_FACADE_HAS_RendProgressSetSceneStats 1
#define MAXMCP_FACADE_HAS_DefaultLightTM 1
#define MAXMCP_FACADE_HAS_DefaultLightState 1
#define MAXMCP_FACADE_HAS_LinkChainCurrent 1
#define MAXMCP_FACADE_HAS_NurbsCVSurfaceAppend 1
#define MAXMCP_FACADE_HAS_NurbsCVSurfaceSetNumCVs 1
#define MAXMCP_FACADE_HAS_NurbsCVSurfaceSetOrders 1
#define MAXMCP_FACADE_HAS_NurbsCVSurfaceSetNumKnots 1
#define MAXMCP_FACADE_HAS_NurbsCVSurfaceSetCVAt 1
#define MAXMCP_FACADE_HAS_NurbsCVSurfaceSetKnot 1
#define MAXMCP_FACADE_HAS_NurbsCVCurveAppend 1
#define MAXMCP_FACADE_HAS_NurbsCVCurveSetNumCVs 1
#define MAXMCP_FACADE_HAS_NurbsCVCurveSetOrder 1
#define MAXMCP_FACADE_HAS_NurbsCVCurveSetNumKnots 1
#define MAXMCP_FACADE_HAS_NurbsCVCurveSetCVAt 1
#define MAXMCP_FACADE_HAS_NurbsCVCurveSetKnot 1
#define MAXMCP_FACADE_HAS_NurbsCVCurveClose 1
#define MAXMCP_FACADE_HAS_NurbsObjectSetName 1
#define MAXMCP_FACADE_HAS_NurbsCreateObject 1
#define MAXMCP_FACADE_HAS_ShapeSplineCountOfInput 1
#define MAXMCP_FACADE_HAS_ShapeSplinePointsReadOfInput 1
#define MAXMCP_FACADE_HAS_ShapeKnotCountOfInput 1
#define MAXMCP_FACADE_HAS_ShapeKnotReadOfInput 1
#define MAXMCP_FACADE_HAS_ShapeSplineClosedOfInput 1
#define MAXMCP_FACADE_HAS_ShapeSegCountOfInput 1
#define MAXMCP_FACADE_HAS_ShapeSegMatIdOfInput 1
#define MAXMCP_FACADE_HAS_ShapeLineCountOfInput 1
#define MAXMCP_FACADE_HAS_ShapeLineReadOfInput 1
#define MAXMCP_FACADE_HAS_ShapePointsReadObjectOfInput 1
#define MAXMCP_FACADE_HAS_ShapeBezierSplineCountOfInput 1
#define MAXMCP_FACADE_HAS_ShapeBezierKnotCountOfInput 1
#define MAXMCP_FACADE_HAS_ShapeBezierKnotReadOfInput 1
#define MAXMCP_FACADE_HAS_ShapeBezierSplineClosedOfInput 1
#define MAXMCP_FACADE_HAS_ShapeCurveCountOfInput 1
#define MAXMCP_FACADE_HAS_ShapeCurveClosedOfInput 1
#define MAXMCP_FACADE_HAS_ShapeCurveInterpOfInput 1
#define MAXMCP_FACADE_HAS_ShapeCurveTangentOfInput 1
#define MAXMCP_FACADE_HAS_ShapeCurveLengthOfInput 1
#define MAXMCP_FACADE_HAS_ShapePieceCountOfInput 1
#define MAXMCP_FACADE_HAS_ShapePieceInterpOfInput 1
#define MAXMCP_FACADE_HAS_ShapePieceTangentOfInput 1
#define MAXMCP_FACADE_HAS_ShapePieceMatIdOfInput 1
#define MAXMCP_FACADE_HAS_ShapeCanMakeBezierOfInput 1
#define MAXMCP_FACADE_HAS_ShapeRenderReadOfInput 1
#define MAXMCP_FACADE_HAS_NurbsGenSphere 1
#define MAXMCP_FACADE_HAS_NurbsGenCylinder 1
#define MAXMCP_FACADE_HAS_NurbsGenCone 1
#define MAXMCP_FACADE_HAS_NurbsGenTorus 1
#define MAXMCP_FACADE_HAS_NurbsGenLathe 1
#define MAXMCP_FACADE_HAS_NurbsSetAppendCylinder 1
#define MAXMCP_FACADE_HAS_NurbsSetAppendCone 1
#define MAXMCP_FACADE_HAS_NurbsSetAppendTorus 1
#define MAXMCP_FACADE_HAS_NurbsSetAppendLathe 1
#define MAXMCP_FACADE_HAS_NurbsBlendSurfaceAppend 1
#define MAXMCP_FACADE_HAS_NurbsBlendSurfaceSetParent 1
#define MAXMCP_FACADE_HAS_NurbsBlendSurfaceSetEdge 1
#define MAXMCP_FACADE_HAS_NurbsBlendSurfaceSetTension 1
#define MAXMCP_FACADE_HAS_NurbsBlendSurfaceSetFlip 1
#define MAXMCP_FACADE_HAS_NurbsBlendSurfaceSetCurveStartPoint 1
#define MAXMCP_FACADE_HAS_NurbsBlendSurfaceGetTension 1
#define MAXMCP_FACADE_HAS_NurbsOffsetSurfaceAppend 1
#define MAXMCP_FACADE_HAS_NurbsOffsetSurfaceSetParent 1
#define MAXMCP_FACADE_HAS_NurbsOffsetSurfaceSetDistance 1
#define MAXMCP_FACADE_HAS_NurbsOffsetSurfaceGetDistance 1
#define MAXMCP_FACADE_HAS_NurbsOffsetSurfaceGetParent 1
#define MAXMCP_FACADE_HAS_NurbsExtrudeSurfaceAppend 1
#define MAXMCP_FACADE_HAS_NurbsExtrudeSurfaceSetParent 1
#define MAXMCP_FACADE_HAS_NurbsExtrudeSurfaceSetDistance 1
#define MAXMCP_FACADE_HAS_NurbsExtrudeSurfaceSetAxis 1
#define MAXMCP_FACADE_HAS_NurbsExtrudeSurfaceSetCurveStartPoint 1
#define MAXMCP_FACADE_HAS_NurbsExtrudeSurfaceGetDistance 1
#define MAXMCP_FACADE_HAS_NurbsLatheSurfaceAppend 1
#define MAXMCP_FACADE_HAS_NurbsLatheSurfaceSetParent 1
#define MAXMCP_FACADE_HAS_NurbsLatheSurfaceSetAxis 1
#define MAXMCP_FACADE_HAS_NurbsLatheSurfaceSetRotation 1
#define MAXMCP_FACADE_HAS_NurbsLatheSurfaceSetCurveStartPoint 1
#define MAXMCP_FACADE_HAS_NurbsLatheSurfaceGetRotation 1
#define MAXMCP_FACADE_HAS_NurbsRuledSurfaceAppend 1
#define MAXMCP_FACADE_HAS_NurbsRuledSurfaceSetParent 1
#define MAXMCP_FACADE_HAS_NurbsRuledSurfaceSetFlip 1
#define MAXMCP_FACADE_HAS_NurbsRuledSurfaceSetCurveStartPoint 1
#define MAXMCP_FACADE_HAS_NurbsRuledSurfaceGetParent 1
#define MAXMCP_FACADE_HAS_NurbsULoftSurfaceAppend 1
#define MAXMCP_FACADE_HAS_NurbsULoftSurfaceSetNumCurves 1
#define MAXMCP_FACADE_HAS_NurbsULoftSurfaceAppendCurve 1
#define MAXMCP_FACADE_HAS_NurbsULoftSurfaceSetCloseLoft 1
#define MAXMCP_FACADE_HAS_NurbsULoftSurfaceSetAutoAlign 1
#define MAXMCP_FACADE_HAS_NurbsULoftSurfaceGetNumCurves 1
#define MAXMCP_FACADE_HAS_NurbsUVLoftSurfaceAppend 1
#define MAXMCP_FACADE_HAS_NurbsUVLoftSurfaceSetNumUCurves 1
#define MAXMCP_FACADE_HAS_NurbsUVLoftSurfaceSetNumVCurves 1
#define MAXMCP_FACADE_HAS_NurbsUVLoftSurfaceAppendUCurve 1
#define MAXMCP_FACADE_HAS_NurbsUVLoftSurfaceAppendVCurve 1
#define MAXMCP_FACADE_HAS_NurbsUVLoftSurfaceGetNumUCurves 1
#define MAXMCP_FACADE_HAS_NurbsUVLoftSurfaceGetNumVCurves 1
#define MAXMCP_FACADE_HAS_NurbsCapSurfaceAppend 1
#define MAXMCP_FACADE_HAS_NurbsCapSurfaceSetParent 1
#define MAXMCP_FACADE_HAS_NurbsCapSurfaceSetEdge 1
#define MAXMCP_FACADE_HAS_NurbsCapSurfaceSetCurveStartPoint 1
#define MAXMCP_FACADE_HAS_NurbsCapSurfaceGetEdge 1
#define MAXMCP_FACADE_HAS_NurbsFilletSurfaceAppend 1
#define MAXMCP_FACADE_HAS_NurbsFilletSurfaceSetParent 1
#define MAXMCP_FACADE_HAS_NurbsFilletSurfaceSetRadius 1
#define MAXMCP_FACADE_HAS_NurbsFilletSurfaceSetCubic 1
#define MAXMCP_FACADE_HAS_NurbsFilletSurfaceSetSeed 1
#define MAXMCP_FACADE_HAS_NurbsFilletSurfaceSetTrimSurface 1
#define MAXMCP_FACADE_HAS_NurbsFilletSurfaceGetRadius 1
#define MAXMCP_FACADE_HAS_NurbsMirrorSurfaceAppend 1
#define MAXMCP_FACADE_HAS_NurbsMirrorSurfaceSetParent 1
#define MAXMCP_FACADE_HAS_NurbsMirrorSurfaceSetAxis 1
#define MAXMCP_FACADE_HAS_NurbsMirrorSurfaceSetDistance 1
#define MAXMCP_FACADE_HAS_NurbsMirrorSurfaceSetXForm 1
#define MAXMCP_FACADE_HAS_NurbsMirrorSurfaceGetAxis 1
#define MAXMCP_FACADE_HAS_NurbsNBlendSurfaceAppend 1
#define MAXMCP_FACADE_HAS_NurbsNBlendSurfaceSetParent 1
#define MAXMCP_FACADE_HAS_NurbsNBlendSurfaceSetEdge 1
#define MAXMCP_FACADE_HAS_NurbsNBlendSurfaceGetParent 1
#define MAXMCP_FACADE_HAS_Nurbs1RailSweepSurfaceAppend 1
#define MAXMCP_FACADE_HAS_Nurbs1RailSweepSurfaceSetParentRail 1
#define MAXMCP_FACADE_HAS_Nurbs1RailSweepSurfaceSetNumCurves 1
#define MAXMCP_FACADE_HAS_Nurbs1RailSweepSurfaceAppendCurve 1
#define MAXMCP_FACADE_HAS_Nurbs1RailSweepSurfaceSetParallel 1
#define MAXMCP_FACADE_HAS_Nurbs1RailSweepSurfaceSetRoadlike 1
#define MAXMCP_FACADE_HAS_Nurbs1RailSweepSurfaceSetSnapCS 1
#define MAXMCP_FACADE_HAS_Nurbs1RailSweepSurfaceSetAxis 1
#define MAXMCP_FACADE_HAS_Nurbs2RailSweepSurfaceAppend 1
#define MAXMCP_FACADE_HAS_Nurbs2RailSweepSurfaceSetNumCurves 1
#define MAXMCP_FACADE_HAS_Nurbs2RailSweepSurfaceAppendCurve 1
#define MAXMCP_FACADE_HAS_Nurbs2RailSweepSurfaceSetRailParent 1
#define MAXMCP_FACADE_HAS_Nurbs2RailSweepSurfaceSetParallel 1
#define MAXMCP_FACADE_HAS_Nurbs2RailSweepSurfaceSetScale 1
#define MAXMCP_FACADE_HAS_Nurbs2RailSweepSurfaceSetSnapCS 1
#define MAXMCP_FACADE_HAS_NurbsMultiCurveTrimSurfaceAppend 1
#define MAXMCP_FACADE_HAS_NurbsMultiCurveTrimSurfaceSetNumCurves 1
#define MAXMCP_FACADE_HAS_NurbsMultiCurveTrimSurfaceAppendCurve 1
#define MAXMCP_FACADE_HAS_NurbsMultiCurveTrimSurfaceSetSurfaceParent 1
#define MAXMCP_FACADE_HAS_NurbsMultiCurveTrimSurfaceSetFlipTrim 1
#define MAXMCP_FACADE_HAS_NurbsMultiCurveTrimSurfaceGetFlipTrim 1
#define MAXMCP_FACADE_HAS_NurbsXFormSurfaceAppend 1
#define MAXMCP_FACADE_HAS_NurbsXFormSurfaceSetParent 1
#define MAXMCP_FACADE_HAS_NurbsXFormSurfaceSetXForm 1
#define MAXMCP_FACADE_HAS_NurbsXFormSurfaceGetParent 1
#define MAXMCP_FACADE_HAS_NurbsPointSurfaceAppend 1
#define MAXMCP_FACADE_HAS_NurbsPointSurfaceSetNumPts 1
#define MAXMCP_FACADE_HAS_NurbsPointSurfaceSetPointAt 1
#define MAXMCP_FACADE_HAS_NurbsPointSurfaceCloseInU 1
#define MAXMCP_FACADE_HAS_NurbsPointSurfaceCloseInV 1
#define MAXMCP_FACADE_HAS_NurbsPointSurfaceGetNumPts 1
#define MAXMCP_FACADE_HAS_NurbsPointCurveAppend 1
#define MAXMCP_FACADE_HAS_NurbsPointCurveSetNumPts 1
#define MAXMCP_FACADE_HAS_NurbsPointCurveGetNumPts 1
#define MAXMCP_FACADE_HAS_NurbsPointCurveSetPoint 1
#define MAXMCP_FACADE_HAS_NurbsPointCurveGetPoint 1
#define MAXMCP_FACADE_HAS_NurbsPointCurveClose 1
#define MAXMCP_FACADE_HAS_NurbsBlendCurveAppend 1
#define MAXMCP_FACADE_HAS_NurbsBlendCurveSetParent 1
#define MAXMCP_FACADE_HAS_NurbsBlendCurveSetEnd 1
#define MAXMCP_FACADE_HAS_NurbsBlendCurveSetTension 1
#define MAXMCP_FACADE_HAS_NurbsBlendCurveGetTension 1
#define MAXMCP_FACADE_HAS_NurbsOffsetCurveAppend 1
#define MAXMCP_FACADE_HAS_NurbsOffsetCurveSetDistance 1
#define MAXMCP_FACADE_HAS_NurbsOffsetCurveGetDistance 1
#define MAXMCP_FACADE_HAS_NurbsXFormCurveAppend 1
#define MAXMCP_FACADE_HAS_NurbsXFormCurveSetXForm 1
#define MAXMCP_FACADE_HAS_NurbsXFormCurveGetXForm 1
#define MAXMCP_FACADE_HAS_NurbsMirrorCurveAppend 1
#define MAXMCP_FACADE_HAS_NurbsMirrorCurveSetAxis 1
#define MAXMCP_FACADE_HAS_NurbsMirrorCurveGetAxis 1
#define MAXMCP_FACADE_HAS_NurbsMirrorCurveSetDistance 1
#define MAXMCP_FACADE_HAS_NurbsMirrorCurveGetDistance 1
#define MAXMCP_FACADE_HAS_NurbsMirrorCurveSetXForm 1
#define MAXMCP_FACADE_HAS_NurbsFilletCurveAppend 1
#define MAXMCP_FACADE_HAS_NurbsFilletCurveSetRadius 1
#define MAXMCP_FACADE_HAS_NurbsFilletCurveGetRadius 1
#define MAXMCP_FACADE_HAS_NurbsFilletCurveSetEnd 1
#define MAXMCP_FACADE_HAS_NurbsFilletCurveSetTrimCurve 1
#define MAXMCP_FACADE_HAS_NurbsFilletCurveSetFlipTrim 1
#define MAXMCP_FACADE_HAS_NurbsChamferCurveAppend 1
#define MAXMCP_FACADE_HAS_NurbsChamferCurveSetLength 1
#define MAXMCP_FACADE_HAS_NurbsChamferCurveGetLength 1
#define MAXMCP_FACADE_HAS_NurbsChamferCurveSetEnd 1
#define MAXMCP_FACADE_HAS_NurbsChamferCurveSetTrimCurve 1
#define MAXMCP_FACADE_HAS_NurbsChamferCurveSetFlipTrim 1
#define MAXMCP_FACADE_HAS_NurbsIsoCurveAppend 1
#define MAXMCP_FACADE_HAS_NurbsIsoCurveSetDirection 1
#define MAXMCP_FACADE_HAS_NurbsIsoCurveSetParam 1
#define MAXMCP_FACADE_HAS_NurbsIsoCurveGetParam 1
#define MAXMCP_FACADE_HAS_NurbsIsoCurveSetTrim 1
#define MAXMCP_FACADE_HAS_NurbsIsoCurveSetSeed 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceEdgeCurveAppend 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceEdgeCurveSetSeed 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceNormalCurveAppend 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceNormalCurveSetDistance 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceNormalCurveGetDistance 1
#define MAXMCP_FACADE_HAS_NurbsProjectNormalCurveAppend 1
#define MAXMCP_FACADE_HAS_NurbsProjectNormalCurveSetTrim 1
#define MAXMCP_FACADE_HAS_NurbsProjectNormalCurveSetFlipTrim 1
#define MAXMCP_FACADE_HAS_NurbsProjectNormalCurveSetSeed 1
#define MAXMCP_FACADE_HAS_NurbsProjectVectorCurveAppend 1
#define MAXMCP_FACADE_HAS_NurbsProjectVectorCurveSetTrim 1
#define MAXMCP_FACADE_HAS_NurbsProjectVectorCurveSetFlipTrim 1
#define MAXMCP_FACADE_HAS_NurbsProjectVectorCurveSetSeed 1
#define MAXMCP_FACADE_HAS_NurbsProjectVectorCurveSetPVec 1
#define MAXMCP_FACADE_HAS_NurbsSurfSurfIntersectionCurveAppend 1
#define MAXMCP_FACADE_HAS_NurbsSurfSurfIntersectionCurveSetTrim 1
#define MAXMCP_FACADE_HAS_NurbsSurfSurfIntersectionCurveSetFlipTrim 1
#define MAXMCP_FACADE_HAS_NurbsSurfSurfIntersectionCurveSetSeed 1
#define MAXMCP_FACADE_HAS_NurbsCurveOnSurfaceAppend 1
#define MAXMCP_FACADE_HAS_NurbsCurveOnSurfaceSetTrim 1
#define MAXMCP_FACADE_HAS_NurbsCurveOnSurfaceSetFlipTrim 1
#define MAXMCP_FACADE_HAS_NurbsCurveOnSurfaceSetNumCVs 1
#define MAXMCP_FACADE_HAS_NurbsCurveOnSurfaceSetOrder 1
#define MAXMCP_FACADE_HAS_NurbsCurveOnSurfaceSetNumKnots 1
#define MAXMCP_FACADE_HAS_NurbsCurveOnSurfaceSetCVAt 1
#define MAXMCP_FACADE_HAS_NurbsCurveOnSurfaceSetKnot 1
#define MAXMCP_FACADE_HAS_NurbsPointCurveOnSurfaceAppend 1
#define MAXMCP_FACADE_HAS_NurbsPointCurveOnSurfaceSetTrim 1
#define MAXMCP_FACADE_HAS_NurbsPointCurveOnSurfaceSetFlipTrim 1
#define MAXMCP_FACADE_HAS_NurbsPointCurveOnSurfaceSetNumPts 1
#define MAXMCP_FACADE_HAS_NurbsPointCurveOnSurfaceSetPoint 1
#define MAXMCP_FACADE_HAS_NurbsPointCurveOnSurfaceClose 1
#define MAXMCP_FACADE_HAS_NurbsIndependentPointAppend 1
#define MAXMCP_FACADE_HAS_NurbsIndependentPointSetPosition 1
#define MAXMCP_FACADE_HAS_NurbsPointConstPointAppend 1
#define MAXMCP_FACADE_HAS_NurbsPointConstPointSetPointType 1
#define MAXMCP_FACADE_HAS_NurbsPointConstPointSetOffset 1
#define MAXMCP_FACADE_HAS_NurbsPointConstPointGetOffset 1
#define MAXMCP_FACADE_HAS_NurbsCurveConstPointAppend 1
#define MAXMCP_FACADE_HAS_NurbsCurveConstPointSetPointType 1
#define MAXMCP_FACADE_HAS_NurbsCurveConstPointSetUParam 1
#define MAXMCP_FACADE_HAS_NurbsCurveConstPointGetUParam 1
#define MAXMCP_FACADE_HAS_NurbsCurveConstPointSetOffset 1
#define MAXMCP_FACADE_HAS_NurbsCurveConstPointSetNormal 1
#define MAXMCP_FACADE_HAS_NurbsSurfConstPointAppend 1
#define MAXMCP_FACADE_HAS_NurbsSurfConstPointSetPointType 1
#define MAXMCP_FACADE_HAS_NurbsSurfConstPointSetUParam 1
#define MAXMCP_FACADE_HAS_NurbsSurfConstPointSetVParam 1
#define MAXMCP_FACADE_HAS_NurbsSurfConstPointSetOffset 1
#define MAXMCP_FACADE_HAS_NurbsSurfConstPointSetNormal 1
#define MAXMCP_FACADE_HAS_NurbsCurveCurveIntersectionPointAppend 1
#define MAXMCP_FACADE_HAS_NurbsCurveCurveIntersectionPointSetCurveParam 1
#define MAXMCP_FACADE_HAS_NurbsCurveCurveIntersectionPointGetCurveParam 1
#define MAXMCP_FACADE_HAS_NurbsCurveCurveIntersectionPointSetTrimCurve 1
#define MAXMCP_FACADE_HAS_NurbsCurveCurveIntersectionPointSetFlipTrim 1
#define MAXMCP_FACADE_HAS_NurbsCurveSurfaceIntersectionPointAppend 1
#define MAXMCP_FACADE_HAS_NurbsCurveSurfaceIntersectionPointSetSeed 1
#define MAXMCP_FACADE_HAS_NurbsCurveSurfaceIntersectionPointGetSeed 1
#define MAXMCP_FACADE_HAS_NurbsCurveSurfaceIntersectionPointSetTrimCurve 1
#define MAXMCP_FACADE_HAS_NurbsCurveSurfaceIntersectionPointSetFlipTrim 1
#define MAXMCP_FACADE_HAS_NurbsCurveTrimPointCount 1
#define MAXMCP_FACADE_HAS_NurbsCurveGetTrimPoint 1
#define MAXMCP_FACADE_HAS_NurbsSetClean 1
#define MAXMCP_FACADE_HAS_NurbsSetRemoveObject 1
#define MAXMCP_FACADE_HAS_NurbsSetGetTessMerge 1
#define MAXMCP_FACADE_HAS_NurbsSetSetTessMerge 1
#define MAXMCP_FACADE_HAS_NurbsSetAddToNode 1
#define MAXMCP_FACADE_HAS_NurbsObjectGetIndex 1
#define MAXMCP_FACADE_HAS_NurbsObjectIsSelected 1
#define MAXMCP_FACADE_HAS_NurbsObjectSetSelected 1
#define MAXMCP_FACADE_HAS_NurbsCVSurfaceGetTransform 1
#define MAXMCP_FACADE_HAS_NurbsCVSurfaceSetTransform 1
#define MAXMCP_FACADE_HAS_NurbsCVCurveGetTransform 1
#define MAXMCP_FACADE_HAS_NurbsCVCurveSetTransform 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceGetMatID 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceSetMatID 1
#define MAXMCP_FACADE_HAS_NurbsCurveGetMatID 1
#define MAXMCP_FACADE_HAS_NurbsCurveSetMatID 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceGetRenderable 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceSetRenderable 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceGetFlipNormals 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceSetFlipNormals 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceGetGenerateUVs 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceSetGenerateUVs 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceIsClosed 1
#define MAXMCP_FACADE_HAS_NurbsTrimSurfaceAppend 1
#define MAXMCP_FACADE_HAS_NurbsTrimSurfaceSetNumCurves 1
#define MAXMCP_FACADE_HAS_NurbsTrimSurfaceGetNumCurves 1
#define MAXMCP_FACADE_HAS_NurbsTrimSurfaceAppendCurve 1
#define MAXMCP_FACADE_HAS_NurbsTrimSurfaceSetParent 1
#define MAXMCP_FACADE_HAS_NurbsTrimSurfaceGetParent 1
#define MAXMCP_FACADE_HAS_NurbsTrimSurfaceSetSurfaceParent 1
#define MAXMCP_FACADE_HAS_NurbsTrimSurfaceGetSurfaceParent 1
#define MAXMCP_FACADE_HAS_NurbsTrimSurfaceSetFlipTrim 1
#define MAXMCP_FACADE_HAS_NurbsTrimSurfaceGetFlipTrim 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceNumChannels 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceGetChannelFromIndex 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceGetTextureUV 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceSetTextureUV 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceGetTileOffset 1
#define MAXMCP_FACADE_HAS_NurbsSurfaceSetTileOffset 1
#define MAXMCP_FACADE_HAS_NurbsTextureSurfaceGetMapperType 1
#define MAXMCP_FACADE_HAS_NurbsTextureSurfaceSetMapperType 1
#define MAXMCP_FACADE_HAS_NurbsTextureSurfaceGetNumPoints 1
#define MAXMCP_FACADE_HAS_NurbsTextureSurfaceSetNumPoints 1
#define MAXMCP_FACADE_HAS_NurbsTextureSurfaceGetParent 1
#define MAXMCP_FACADE_HAS_NurbsTextureSurfaceSetParent 1
#define MAXMCP_FACADE_HAS_NurbsTextureSurfaceGetPoint 1
#define MAXMCP_FACADE_HAS_NurbsTextureSurfaceSetPoint 1
#define MAXMCP_FACADE_HAS_NurbsFuseSurfaceCV 1
#define MAXMCP_FACADE_HAS_NurbsFuseCurveCV 1
#define MAXMCP_FACADE_HAS_NurbsSetSurfFuseCount 1
#define MAXMCP_FACADE_HAS_NurbsSetCurveFuseCount 1
#define MAXMCP_FACADE_HAS_NurbsSetGetSurfFuse 1
#define MAXMCP_FACADE_HAS_NurbsSetGetCurveFuse 1
#define MAXMCP_FACADE_HAS_NurbsSetClearSurfFuse 1
#define MAXMCP_FACADE_HAS_NurbsSetClearCurveFuse 1
#define MAXMCP_FACADE_HAS_PatchSetUIParam 1
#define MAXMCP_FACADE_HAS_SplineStartCommandMode 1
#define MAXMCP_FACADE_HAS_SplineButtonOp 1
#define MAXMCP_FACADE_HAS_SplineSetUIParam 1
#define MAXMCP_FACADE_HAS_ObjectSetXTCObjectBranchID 1
#define MAXMCP_FACADE_HAS_ObjectBranchDeleted 1
#define MAXMCP_FACADE_HAS_ObjectDeleteAllAdditionalChannels 1

// -- WHAT IS FACTUALLY MISSING, AND WHY ----------------------------------------
//
// trade   : may not cross the facade - a payload is swapped under a running host, so
//           it may never hold a raw pointer into the SDK. Not a gap.
// not-yet : genuinely absent and wanted. THIS is what a feature request is for.
// host    : 3ds Max does not offer it to a plugin at all.
//
// per-pixel shading  [trade]  (materials, shaders, samplers)
/
/
 
 
 
 
 
A
 
m
a
t
e
r
i
a
l
'
s
 
o
w
n
 
S
h
a
d
e
/
E
v
a
l
C
o
l
o
r
,
 
a
 
s
h
a
d
e
r
'
s
 
I
l
l
u
m
 
a
n
d
 
a
 
s
a
m
p
l
e
r
'
s
 
D
o
S
a
m
p
l
e
 
a
r
e


/
/
 
c
a
l
l
e
d
 
p
e
r
 
p
i
x
e
l
,
 
o
n
 
a
 
t
r
a
n
s
i
e
n
t
 
o
b
j
e
c
t
,
 
a
t
 
a
 
r
a
t
e
 
n
o
 
h
a
n
d
l
e
 
r
o
u
n
d
-
t
r
i
p
 
c
a
n
 
m
e
e
t
.


/
/
 
P
r
o
j
e
c
t
i
n
g
 
t
h
e
m
 
w
o
u
l
d
 
m
e
a
n
 
h
a
n
d
i
n
g
 
a
 
p
a
y
l
o
a
d
 
a
 
r
a
w
 
p
o
i
n
t
e
r
 
f
o
r
 
t
h
e
 
s
p
a
n
 
o
f
 
a
 
r
e
n
d
e
r
.
/
/
 
 
 
 
 
i
n
s
t
e
a
d
:
 
A
s
s
e
m
b
l
e
 
a
n
d
 
d
r
i
v
e
 
S
T
O
C
K
 
m
a
t
e
r
i
a
l
s
 
-
 
S
t
a
n
d
a
r
d
,
 
M
u
l
t
i
,
 
t
h
e
 
w
h
o
l
e
 
S
t
d
M
a
t


/
/
 
f
a
m
i
l
y
 
-
 
t
h
r
o
u
g
h
 
t
h
e
 
f
a
c
a
d
e
.
 
M
o
s
t
 
r
e
a
l
 
m
a
t
e
r
i
a
l
 
w
o
r
k
 
i
s
 
e
x
a
c
t
l
y
 
t
h
a
t
.
/
/
 
 
 
 
 
s
e
e
:
 
i
m
t
l
.
h
 
(
M
t
l
:
:
S
h
a
d
e
)
,
 
s
h
a
d
e
r
s
.
h
 
(
S
h
a
d
e
r
:
:
I
l
l
u
m
)
,
 
s
a
m
p
l
e
r
s
.
h
 
(
S
a
m
p
l
e
r
:
:
D
o
S
a
m
p
l
e
)
//
// live GPU device handle  [trade]  (viewport graphics)
/
/
 
 
 
 
 
T
h
e
r
e
 
i
s
 
n
o
 
s
a
f
e
,
 
p
o
r
t
a
b
l
e
 
p
r
o
j
e
c
t
i
o
n
 
o
f
 
a
 
r
a
w
 
g
r
a
p
h
i
c
s
-
d
e
v
i
c
e
 
p
o
i
n
t
e
r
 
a
c
r
o
s
s
 
a


/
/
 
b
o
u
n
d
a
r
y
 
a
 
p
a
y
l
o
a
d
 
c
a
n
 
b
e
 
s
w
a
p
p
e
d
 
o
v
e
r
.
/
/
 
 
 
 
 
i
n
s
t
e
a
d
:
 
V
i
e
w
p
o
r
t
 
G
E
O
M
E
T
R
Y
 
i
s
 
r
e
a
c
h
a
b
l
e
:
 
t
h
e
 
m
a
n
i
p
u
l
a
t
o
r
 
g
i
z
m
o
-
b
u
i
l
d
 
f
a
m
i
l
y
 
b
u
i
l
d
s


/
/
 
r
e
a
l
 
i
n
t
e
r
a
c
t
i
v
e
 
s
h
a
p
e
s
 
(
s
e
e
 
b
a
r
e
b
o
n
e
s
/
m
a
n
i
p
u
l
a
t
o
r
,
 
w
h
i
c
h
 
d
r
a
w
s
 
a
 
t
e
t
r
a
h
e
d
r
o
n
)
.
/
/
 
 
 
 
 
s
e
e
:
 
g
f
x
.
h
//
// raw hardware input streams  [trade]  (motion capture devices)
/
/
 
 
 
 
 
A
 
j
o
y
s
t
i
c
k
,
 
M
I
D
I
 
c
o
n
t
r
o
l
l
e
r
 
o
r
 
r
a
w
 
k
e
y
b
o
a
r
d
 
d
e
v
i
c
e
 
i
s
 
a
 
l
i
v
e
 
O
S
 
h
a
n
d
l
e
 
r
e
a
d
 
o
n
 
i
t
s


/
/
 
o
w
n
 
t
h
r
e
a
d
.
 
T
h
e
 
P
L
U
G
I
N
 
K
I
N
D
 
f
o
r
 
a
 
m
o
t
i
o
n
-
c
a
p
t
u
r
e
 
d
e
v
i
c
e
 
i
s
 
f
u
l
l
y
 
s
u
p
p
o
r
t
e
d
;
 
i
t
 
i
s


/
/
 
s
p
e
c
i
f
i
c
a
l
l
y
 
t
h
e
 
r
a
w
 
s
t
r
e
a
m
 
u
n
d
e
r
n
e
a
t
h
 
i
t
 
t
h
a
t
 
s
t
a
y
s
 
o
u
t
s
i
d
e
.
/
/
 
 
 
 
 
i
n
s
t
e
a
d
:
 
H
o
s
t
 
t
h
e
 
d
e
v
i
c
e
 
k
i
n
d
 
i
n
 
i
t
s
 
s
l
o
t
 
a
n
d
 
d
r
i
v
e
 
t
h
e
 
c
o
n
t
r
o
l
l
e
r
 
v
a
l
u
e
s
 
t
h
r
o
u
g
h
 
t
h
e


/
/
 
c
o
n
t
r
o
l
l
e
r
 
a
n
d
 
p
a
r
a
m
e
t
e
r
-
b
l
o
c
k
 
f
a
m
i
l
i
e
s
.
/
/
 
 
 
 
 
s
e
e
:
 
c
m
d
m
o
d
e
.
h
 
/
 
m
o
u
s
e
m
a
n
.
h
//
// painter / BVH internals  [trade]  (paint tools)
/
/
 
 
 
 
 
P
r
o
v
i
d
i
n
g
 
a
 
n
e
w
 
N
A
T
I
V
E
 
p
a
i
n
t
 
s
u
r
f
a
c
e
 
m
e
a
n
s
 
o
w
n
i
n
g
 
3
d
s
 
M
a
x
'
s
 
p
e
r
-
s
t
r
o
k
e
 
b
r
u
s
h
 
s
e
r
v
i
c
e
,


/
/
 
i
t
s
 
b
o
u
n
d
s
 
t
r
e
e
 
a
n
d
 
t
a
b
l
e
t
 
p
r
e
s
s
u
r
e
 
i
n
s
i
d
e
 
t
h
e
 
p
a
y
l
o
a
d
.
 
T
h
e
 
C
O
N
S
U
M
I
N
G
 
s
i
d
e
 
-
 
q
u
e
r
y
i
n
g
 
a
n


/
/
 
e
x
i
s
t
i
n
g
 
p
a
i
n
t
e
r
 
i
n
t
e
r
f
a
c
e
 
-
 
i
s
 
c
o
v
e
r
e
d
.
/
/
 
 
 
 
 
i
n
s
t
e
a
d
:
 
Q
u
e
r
y
 
t
h
e
 
e
x
i
s
t
i
n
g
 
p
a
i
n
t
e
r
 
i
n
t
e
r
f
a
c
e
 
a
n
d
 
e
d
i
t
 
t
h
e
 
m
e
s
h
 
t
h
r
o
u
g
h
 
t
h
e
 
m
e
s
h


/
/
 
f
a
m
i
l
y
.
/
/
 
 
 
 
 
s
e
e
:
 
I
P
a
i
n
t
e
r
I
n
t
e
r
f
a
c
e
.
h
//
// NURBS procedural-callback generators  [not-yet]  (NURBS)
/
/
 
 
 
 
 
T
h
e
 
N
U
R
B
S
 
f
a
m
i
l
y
 
c
o
v
e
r
s
 
C
V
 
s
u
r
f
a
c
e
s
 
a
n
d
 
c
u
r
v
e
s
,
 
t
h
e
 
d
e
p
e
n
d
e
n
t
 
t
y
p
e
s
,
 
t
r
i
m
,
 
t
e
x
t
u
r
e


/
/
 
a
n
d
 
s
e
t
 
o
p
e
r
a
t
i
o
n
s
.
 
W
h
a
t
 
i
s
 
n
o
t
 
p
r
o
j
e
c
t
e
d
 
i
s
 
a
 
s
u
r
f
a
c
e
 
o
r
 
c
u
r
v
e
 
w
h
o
s
e
 
p
o
i
n
t
s
 
a
r
e
 
p
r
o
d
u
c
e
d


/
/
 
b
y
 
t
h
e
 
P
A
Y
L
O
A
D
'
S
 
O
W
N
 
c
a
l
l
b
a
c
k
 
d
u
r
i
n
g
 
e
v
a
l
u
a
t
i
o
n
 
-
 
t
h
e
 
s
a
m
e
 
s
w
a
p
p
e
d
-
u
n
d
e
r
-
a
-
r
u
n
n
i
n
g
-
h
o
s
t


/
/
 
q
u
e
s
t
i
o
n
 
a
s
 
p
e
r
-
p
i
x
e
l
 
s
h
a
d
i
n
g
,
 
b
u
t
 
a
t
 
a
 
r
a
t
e
 
t
h
a
t
 
m
i
g
h
t
 
a
c
t
u
a
l
l
y
 
b
e
 
a
f
f
o
r
d
a
b
l
e
.


/
/
 
U
n
d
e
c
i
d
e
d
,
 
n
o
t
 
r
e
f
u
s
e
d
.
/
/
 
 
 
 
 
s
e
e
:
 
s
u
r
f
_
a
p
i
.
h
//
// GizmoShape tooltip  [not-yet]  (manipulators)
/
/
 
 
 
 
 
S
i
m
p
l
e
M
a
n
i
p
u
l
a
t
o
r
:
:
U
p
d
a
t
e
S
h
a
p
e
s
 
i
s
 
h
a
n
d
e
d
 
a
n
 
M
S
T
R
&
 
t
o
o
l
T
i
p
 
t
h
e
 
m
a
n
i
p
u
l
a
t
o
r
 
f
i
l
l
s
,
 
a
n
d


/
/
 
t
h
e
 
s
l
o
t
 
c
u
r
r
e
n
t
l
y
 
w
r
i
t
e
s
 
i
t
s
 
o
w
n
 
d
i
s
p
l
a
y
 
n
a
m
e
 
t
h
e
r
e
.
 
A
 
p
a
y
l
o
a
d
 
c
a
n
n
o
t
 
y
e
t
 
s
e
t
 
i
t
,
 
s
o
 
a


/
/
 
c
a
r
t
r
i
d
g
e
 
g
i
z
m
o
 
c
a
n
n
o
t
 
l
a
b
e
l
 
i
t
s
e
l
f
.
/
/
 
 
 
 
 
s
e
e
:
 
m
a
n
i
p
u
l
a
t
o
r
.
h
 
(
S
i
m
p
l
e
M
a
n
i
p
u
l
a
t
o
r
:
:
U
p
d
a
t
e
S
h
a
p
e
s
)
//
// GizmoShapeAppendMesh  [not-yet]  (manipulators)
/
/
 
 
 
 
 
T
h
e
 
g
i
z
m
o
-
b
u
i
l
d
 
f
a
m
i
l
y
 
a
p
p
e
n
d
s
 
p
o
l
y
l
i
n
e
s
,
 
p
o
i
n
t
s
,
 
c
i
r
c
l
e
s
 
a
n
d
 
r
e
c
t
a
n
g
l
e
s
.
 
A
p
p
e
n
d
i
n
g
 
a


/
/
 
w
h
o
l
e
 
M
E
S
H
 
a
s
 
g
i
z
m
o
 
g
e
o
m
e
t
r
y
 
-
 
t
h
e
 
S
D
K
'
s
 
o
w
n
 
m
e
s
h
-
s
h
a
p
e
d
 
g
i
z
m
o
 
-
 
h
a
s
 
n
o
 
e
n
t
r
y
,
 
s
o
 
a


/
/
 
c
a
r
t
r
i
d
g
e
 
g
i
z
m
o
 
i
s
 
w
i
r
e
f
r
a
m
e
-
o
n
l
y
 
t
o
d
a
y
.
/
/
 
 
 
 
 
s
e
e
:
 
m
a
n
i
p
u
l
a
t
o
r
.
h
 
(
G
i
z
m
o
S
h
a
p
e
)
//
// GizmoShapeAppendMarker  [not-yet]  (manipulators)
/
/
 
 
 
 
 
P
o
i
n
t
 
m
a
r
k
e
r
s
 
(
t
h
e
 
s
m
a
l
l
 
v
i
e
w
p
o
r
t
 
g
l
y
p
h
s
 
-
 
c
r
o
s
s
,
 
b
o
x
,
 
d
o
t
)
 
h
a
v
e
 
n
o
 
e
n
t
r
y
,
 
s
o
 
a


/
/
 
c
a
r
t
r
i
d
g
e
 
g
i
z
m
o
 
d
r
a
w
s
 
a
 
t
i
n
y
 
p
o
l
y
l
i
n
e
 
w
h
e
r
e
 
a
 
m
a
r
k
e
r
 
i
s
 
w
h
a
t
 
i
s
 
w
a
n
t
e
d
.
/
/
 
 
 
 
 
s
e
e
:
 
m
a
n
i
p
u
l
a
t
o
r
.
h
 
(
G
i
z
m
o
S
h
a
p
e
)
//
// Video Post from script  [host]  (Video Post)
/
/
 
 
 
 
 
3
d
s
 
M
a
x
 
d
o
e
s
 
n
o
t
 
e
x
p
o
s
e
 
V
i
d
e
o
 
P
o
s
t
 
t
o
 
p
y
m
x
s
 
o
r
 
M
A
X
S
c
r
i
p
t
 
a
t
 
a
l
l
,
 
s
o
 
a
 
V
i
d
e
o
 
P
o
s
t


/
/
 
f
i
l
t
e
r
 
c
a
r
t
r
i
d
g
e
 
c
a
n
n
o
t
 
b
e
 
d
r
i
v
e
n
 
h
e
a
d
l
e
s
s
l
y
 
-
 
i
t
 
i
s
 
v
e
r
i
f
i
e
d
 
b
y
 
a
 
p
e
r
s
o
n
 
p
e
r
f
o
r
m
i
n
g
 
A
d
d


/
/
 
I
m
a
g
e
 
F
i
l
t
e
r
 
E
v
e
n
t
.
 
T
h
i
s
 
i
s
 
a
 
h
o
s
t
 
l
i
m
i
t
 
a
n
d
 
n
o
 
f
a
c
a
d
e
 
e
n
t
r
y
 
c
a
n
 
l
i
f
t
 
i
t
.
/
/
 
 
 
 
 
s
e
e
:
 
n
o
 
m
a
x
s
c
r
i
p
t
 
e
x
p
o
s
u
r
e
;
 
s
e
e
 
d
o
c
s
/
P
L
U
G
I
N
_
T
Y
P
E
S
.
m
d
//
// the IK Solvers menu  [host]  (IK solvers)
/
/
 
 
 
 
 
A
n
i
m
a
t
i
o
n
 
>
 
I
K
 
S
o
l
v
e
r
s
 
i
s
 
a
 
S
T
A
T
I
C
 
m
e
n
u
:
 
i
t
 
l
i
s
t
s
 
s
o
l
v
e
r
s
 
3
d
s
 
M
a
x
 
s
h
i
p
s
 
a
n
d
 
w
i
l
l


/
/
 
n
e
v
e
r
 
l
i
s
t
 
a
 
t
h
i
r
d
-
p
a
r
t
y
 
o
n
e
,
 
e
v
e
n
 
o
n
e
 
t
h
e
 
I
K
 
s
y
s
t
e
m
 
e
n
u
m
e
r
a
t
e
s
.
 
A
 
s
o
l
v
e
r
 
c
a
r
t
r
i
d
g
e
 
i
s


/
/
 
a
s
s
i
g
n
e
d
 
f
r
o
m
 
t
h
e
 
M
o
t
i
o
n
 
p
a
n
e
l
 
o
r
 
b
y
 
I
K
S
y
s
.
i
k
C
h
a
i
n
(
s
t
a
r
t
,
 
e
n
d
,
 
"
<
I
n
t
e
r
n
a
l
N
a
m
e
>
"
)
.
/
/
 
 
 
 
 
i
n
s
t
e
a
d
:
 
I
K
S
y
s
.
i
k
C
h
a
i
n
(
s
t
a
r
t
,
 
e
n
d
,
 
"
C
a
r
t
r
i
d
g
e
_
I
K
_
S
o
l
v
e
r
"
)
 
-
 
t
h
e
 
I
N
T
E
R
N
A
L
 
n
a
m
e
,
 
n
o
t


/
/
 
t
h
e
 
U
I
 
n
a
m
e
.
/
/
 
 
 
 
 
s
e
e
:
 
i
k
s
o
l
v
e
r
.
h
;
 
o
b
s
e
r
v
e
d
 
a
g
a
i
n
s
t
 
a
 
l
i
v
e
 
h
o
s
t
//

#endif  // MAXMCP_FACADE_SURFACE_H
