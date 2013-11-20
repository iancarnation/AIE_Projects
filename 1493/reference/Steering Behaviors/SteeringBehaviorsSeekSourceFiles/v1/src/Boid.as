package  
{
	import flash.display.MovieClip;
	import flash.geom.Vector3D;
	
	public class Boid extends MovieClip
	{
		public static const MAX_FORCE 		:Number = 0.4;
		public static const MAX_VELOCITY 	:Number = 3;
		
		public var position 	:Vector3D;
		public var velocity 	:Vector3D;
		public var target 		:Vector3D;
		public var mass			:Number;
		
		public function Boid(posX :Number, posY :Number, totalMass :Number = 20) {
			position = new Vector3D(posX, posY);
			velocity = new Vector3D(-1, -2);
			target	 = new Vector3D(0, 0);
			mass	 = totalMass;
			
			truncate(velocity, MAX_VELOCITY);
			
			x = position.x;
			y = position.y;
			
			graphics.beginFill(0xFF0000);
			graphics.drawRect(0, 0, 20, 20);
			graphics.endFill();
		}
		
		public function truncate(vector :Vector3D, max :Number) :void {
			var i :Number;

			i = max / vector.length;
			i = i < 1.0 ? 1.0 : i;
			
			vector.scaleBy(i);
		}
		
		public function update():void {
			target = Game.mouse;
			
			velocity = target.subtract(position);
			velocity.normalize();
			velocity.scaleBy(MAX_VELOCITY);
			velocity.scaleBy(1 / mass);
			
			truncate(velocity, MAX_VELOCITY);
			position = position.add(velocity);

			x = position.x;
			y = position.y;
		}
	}
}