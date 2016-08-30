<?hh //strict

namespace Plitter\Providers;


use Plenty\Plugin\ServiceProvider;

class PlitterServiceProvider extends ServiceProvider
{

    /**
     * Register the service provider.
     */

    public function register():void
    {
      $this->getApplication()->register(PlitterRouteServiceProvider::class);
    }
}
