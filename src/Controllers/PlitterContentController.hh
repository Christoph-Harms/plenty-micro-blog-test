<?hh //strict

namespace Plitter\Controllers;


use Plenty\Plugin\Controller;
use Plenty\Plugin\Templates\Twig;
use Plenty\Plugin\Http\Request;
use Plitter\Models\User;
use Plitter\Models\Post;

class PlitterContentController extends Controller
{
    public function showBlog(Twig $twig):string
    {
      $users = User::all();

      $ret = '';

      foreach ($users as $user)
      {
        $name = '';
        $bday = '';
        if (is_array($user) && array_key_exists('name', $user) && array_key_exists('birthday', $user))
        {
          $name = $user['name'];
          $bday = $user['birthday'];
        }

        if (is_string($name) && is_string($bday))
        {
          $ret .= 'Name: ' . $name . "\n";
          $ret .= 'Birthday' . $bday  . "\n\n";
        }
      }

      return $ret;
    }

    public function newPost(Twig $twig):string
    {
      return $twig->render('Plitter::newPost');
    }

    public function storePost(Twig $twig, Request $request):string
    {
      $req = $request->all();

      $req = array_filter(array_flip($req), ($value) ==> {
          return $value != 'plentyMarkets';
        });

      $req = array_flip($req);


      return Post::store($req);
    }
}
