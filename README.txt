---------
PROBLEMES
---------

- Refaire ft_str_to_tab_sep											// DONE

- En cas de minishell-ception :
		Corriger leaks												// DONE
		Corriger environnement en cas d'environnement vide			// DONE
				Si ./minishell : L'environnement est toujours ok
				Si env -i ./minishell puis ./minishell, certaines
				variables sont manquantes.
		Erreur au niveau des limbes									// DONE

- Segfault en cas d'espace											// DONE

- Norme																// DONE

- Gerer les appels directs d'executables							// DONE

- La fonction get_shlvl pue la merde								// DONE

- Erreur cd repertoire_inexistant : Message d'erreur inverse		// DONE

- En cas de unset de SHLVL, boucle infinie sur put_prompt			// DONE

- En cas de cd -, afficher le repertoire precedent avant de chdir	// DONE

- En cas de chmod 000  sur repertoire precedent ou courant :
		$> cd -      => OLDPATH vide								// DONE
		$> cd ..     => no such file or directory					// CHDIR ?

- Segfault en cas de modif de path sans l'avoir unset				// DONE

-----------
CRASH TESTS
-----------

$> ./minishell < /dev/urandom
			DONE SALEMENT

$> .
			DONE

$> env -i ./minishell
			DONE

$> ./minishell && mkdir test && cd test && rm -r ../test && cd .. && cd -
			DONE


