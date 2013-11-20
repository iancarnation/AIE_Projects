package  
{
	import flash.display.MovieClip;
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.events.MouseEvent;
	import flash.geom.Vector3D;
	import flash.text.TextField;

	public class Game extends MovieClip
	{
		public static var mouse :Vector3D = new Vector3D(100, 100);
		
		public var boids :Vector.<Boid> = new Vector.<Boid>;
		public var forces :Sprite;
		
		public function Game() {
			addEventListener(Event.ADDED_TO_STAGE, init);
		}
		
		private function init(e :Event) :void {
			var i :int, boid :Boid;
			
			for (i = 0; i < 2; i++) {
				boid = new Boid(stage.stageWidth * Math.random(), stage.stageHeight * Math.random(), 20 +  Math.random() * 20);
	
				addChild(boid);
				boids.push(boid);
			}
			
			forces = new Sprite();
			addChild(forces);
		}
		
		public function update():void {
			var i :int;
			
			forces.graphics.clear();
			
			for (i = 0; i < boids.length; i++) { 
				boids[i].update();
				drawForces(boids[i]);
			}
		}
		
		private function drawForces(boid :Boid) :void {
			var velocity :Vector3D = boid.velocity.clone();
			
			velocity.normalize();
			
			// Force vectors
			drawForceVector(boid, velocity, 0x00FF00);
			
			// Target
			forces.graphics.lineStyle(1, 0x323232);
			forces.graphics.beginFill(0x323232);
			forces.graphics.drawCircle(mouse.x, mouse.y, 10);
			forces.graphics.endFill();
		}
		
		private function drawForceVector(boid :Boid, force :Vector3D, color :uint, scale :Number = 100) :void {
			forces.graphics.moveTo(boid.x + boid.width / 2, boid.y + boid.height / 2);
			forces.graphics.lineStyle(2, color);
			forces.graphics.lineTo(boid.x + force.x * scale, boid.y + force.y * scale);
		}
	}
}