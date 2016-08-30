<?hh //strict

namespace Plitter\Providers;


use Plenty\Plugin\RouteServiceProvider;
use Plenty\Plugin\Routing\Router;

class PlitterRouteServiceProvider extends RouteServiceProvider
{
    public function map(Router $router):void
    {
      $router->get('blog', 'Plitter\Controllers\PlitterContentController@showBlog');
    }
}
