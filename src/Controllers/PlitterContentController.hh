<?hh //strict

namespace Plitter\Controllers;


use Plenty\Plugin\Controller;
use Plenty\Plugin\Templates\Twig;
use Plenty\Modules\Category\Contracts\CategoryRepository;

class PlitterContentController extends Controller
{
    public function showBlog(Twig $twig, CategoryRepository $categories):string
    {
        $blogEntries = $categories->getByType('blog');

        $templateData = [
          'entries' => $blogEntries,
        ];

        return $twig->render('Plitter::blog', $templateData);
    }
}
