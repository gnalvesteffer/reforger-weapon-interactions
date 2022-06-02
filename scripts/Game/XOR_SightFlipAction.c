class XOR_SightFlipAction : SCR_BaseWeaponAction
{
	private static const vector DEFAULT_ANGLE = Vector(0, 0, 0);
	private static const vector ADJUSTED_ANGLE = Vector(0, Math.PI / 2, 0);
	
	private TNodeId _sightBoneIndex;
	private bool _isAdjusted;
	
	override void Init(IEntity pOwnerEntity, GenericComponent pManagerComponent)
	{
		super.Init(pOwnerEntity, pManagerComponent);
		_sightBoneIndex = pOwnerEntity.GetBoneIndex("w_sight");
	}
	
	override bool CanBeShownScript(IEntity user)
	{
		return true;
	}
	
	override bool CanBePerformedScript(IEntity user)
	{
		return true;
	}
	
	override void PerformAction(IEntity pOwnerEntity, IEntity pUserEntity)
	{
		Print("SIGHT ADJUSTED");
		_isAdjusted = !_isAdjusted;
		vector angle = DEFAULT_ANGLE;
		if (_isAdjusted)
		{
			angle = ADJUSTED_ANGLE;
		}
		pOwnerEntity.SetBone(_sightBoneIndex, angle, vector.Zero, 1);
	}
}