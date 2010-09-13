<?php
/**
 * Provide QueryPath with additional XML tools.
 *
 * @package QueryPath
 * @subpackage Extension
 * @author M Butcher <matt@aleph-null.tv>
 * @license http://opensource.org/licenses/lgpl-2.1.php LGPL or MIT-like license.
 * @see QueryPathExtension
 * @see QueryPathExtensionRegistry::extend()
 * @see QPXML
 */
 
/**
 * Provide additional tools for working with XML content.
 */
class QPXML implements QueryPathExtension {
  
  protected $qp;
  
  public function __construct(QueryPath $qp) {
    $this->qp = $qp;
  }
  
  public function schema($file) {
    $doc = $this->qp->branch()->top()->get(0)->ownerDocument;
    
    if (!$doc->schemaValidate($file)) {
      throw new QueryPathException('Document did not validate against the schema.');
    }
  }
  
  /**
   * Get or set a CDATA section.
   *
   * If this is given text, it will create a CDATA section in each matched element, 
   * setting that item's value to $text.
   *
   * If no parameter is passed in, this will return the first CDATA section that it
   * finds in the matched elements.
   *
   * @param string $text
   *  The text data to insert into the current matches. If this is NULL, then the first
   *  CDATA will be returned.
   *
   * @return mixed
   *  If $text is not NULL, this will return a {@link QueryPath}. Otherwise, it will
   *  return a string. If no CDATA is found, this will return NULL.
   * @see comment()
   * @see QueryPath::text()
   * @see QueryPath::html()
   */
  public function cdata($text = NULL) {
    if (isset($text)) {
      // Add this text as CDATA in the current elements.
      foreach ($this->qp->get() as $element) {
        $cdata = $element->ownerDocument->createCDATASection($text);
        $element->appendChild($cdata);
      }
      return $this->qp;;
    }
    
    // Look for CDATA sections
    foreach ($this->qp->get() as $ele) {
      foreach ($ele->childNodes as $node) {
        if ($node->nodeType == XML_CDATA_SECTION_NODE) {
          // Return first match.
          return $node->textContent;
        }
      }
    }
    return NULL;
    // Nothing found
  }
  
  /**
   * Get or set a comment.
   *
   * This function is used to get or set comments in an XML or HTML document.
   * If a $text value is passed in (and is not NULL), then this will add a comment
   * (with the value $text) to every match in the set.
   *
   * If no text is passed in, this will return the first comment in the set of matches.
   * If no comments are found, NULL will be returned.
   *
   * @param string $text
   *  The text of the comment. If set, a new comment will be created in every item 
   *  wrapped by the current {@link QueryPath}.
   * @return mixed
   *  If $text is set, this will return a {@link QueryPath}. If no text is set, this
   *  will search for a comment and attempt to return the string value of the first
   *  comment it finds. If no comment is found, NULL will be returned.
   * @see cdata()
   */
  public function comment($text = NULL) {
    if (isset($text)) {
      foreach ($this->qp->get() as $element) {
        $comment = $element->ownerDocument->createComment($text);
        $element->appendChild($comment);
      }
      return $this->qp;
    }
    foreach ($this->qp->get() as $ele) {
      foreach ($ele->childNodes as $node) {
        if ($node->nodeType == XML_COMMENT_NODE) {
          // Return first match.
          return $node->textContent;
        }
      }
    }
  }
  
  /**
   * Get or set a processor instruction.
   */
  public function pi($prefix = NULL, $text = NULL) {
    if (isset($text)) {
      foreach ($this->qp->get() as $element) {
        $comment = $element->ownerDocument->createProcessingInstruction($prefix, $text);
        $element->appendChild($comment);
      }
      return $this->qp;
    }
    foreach ($this->qp->get() as $ele) {
      foreach ($ele->childNodes as $node) {
        if ($node->nodeType == XML_PI_NODE) {
          
          if (isset($prefix)) {
            if ($node->tagName == $prefix) {
              return $node->textContent;
            }
          }
          else {
            // Return first match.
            return $node->textContent;
          }
        }
      } // foreach
    } // foreach
  }
}
QueryPathExtensionRegistry::extend('QPXML');