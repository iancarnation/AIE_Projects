package 
{
	import flash.display.Sprite;
	import flash.events.*;
	
	[SWF(width = "600", height = "480")]
	
	public class Main extends Sprite 
	{
		private var game :Game = new Game();
		
		public function Main():void 
		{
			if (stage) init();
			else addEventListener(Event.ADDED_TO_STAGE, init);
		}
		
		private function init(e:Event = null):void 
		{
			removeEventListener(Event.ADDED_TO_STAGE, init);
			
			stage.addEventListener(Event.ENTER_FRAME, enterFrame);
			stage.addEventListener(MouseEvent.MOUSE_MOVE, mouseMove);
			stage.frameRate = 30;
			
			addChild(game);
		}
		
		private function mouseMove(e :MouseEvent) :void {
			Game.mouse.x = e.stageX;
			Game.mouse.y = e.stageY;
		}
		
		private function enterFrame(e :Event) :void {
			game.update();
		}
	}
}