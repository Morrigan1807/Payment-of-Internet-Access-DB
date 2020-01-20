#pragma once
#include "ChangeLogItem.h"
namespace PaymentofInternetAccess {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Xml;

	/// <summary>
	/// Сводка для AddOperator
	/// </summary>
	public ref class AddOperator : public System::Windows::Forms::Form
	{
	public:
		AddOperator(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
			SqlConnection^ connect = gcnew SqlConnection(db);
			SqlCommand^ command = connect->CreateCommand();
			command->CommandText = "SELECT MAX(Operator_number) FROM Operators";
			command->Connection = connect;
			SqlDataReader^ dr;
			connect->Open();
			dr = command->ExecuteReader();
			dr->Read();
			if ((dr->HasRows))
			{
				Operator_number->Text = Convert::ToString(Convert::ToInt32(dr[0]) + 1);
			}
			else
			{
				Operator_number->Text = "1";
			}
			dr->Close();
			connect->Close();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddOperator()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  exit;
	protected:

	private: System::Windows::Forms::Button^  Add_row;
	protected:

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  Home_address;

	private: System::Windows::Forms::TextBox^  Operator_number;
	private: System::Windows::Forms::TextBox^  Full_name;
	private: System::Windows::Forms::TextBox^  Position;

	public: Form^ general;

	private: System::Windows::Forms::Label^  label5;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  O_login;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  O_password;

	private: System::Windows::Forms::MaskedTextBox^  Phone_number;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AddOperator::typeid));
			this->exit = (gcnew System::Windows::Forms::Button());
			this->Add_row = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Home_address = (gcnew System::Windows::Forms::TextBox());
			this->Operator_number = (gcnew System::Windows::Forms::TextBox());
			this->Full_name = (gcnew System::Windows::Forms::TextBox());
			this->Position = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->O_login = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->O_password = (gcnew System::Windows::Forms::TextBox());
			this->Phone_number = (gcnew System::Windows::Forms::MaskedTextBox());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->SuspendLayout();
			// 
			// exit
			// 
			this->exit->Location = System::Drawing::Point(207, 410);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(75, 23);
			this->exit->TabIndex = 21;
			this->exit->Text = L"Выйти";
			this->exit->UseVisualStyleBackColor = true;
			this->exit->Click += gcnew System::EventHandler(this, &AddOperator::exit_Click);
			// 
			// Add_row
			// 
			this->Add_row->Location = System::Drawing::Point(39, 410);
			this->Add_row->Name = L"Add_row";
			this->Add_row->Size = System::Drawing::Size(115, 23);
			this->Add_row->TabIndex = 20;
			this->Add_row->Text = L"Добавить строку";
			this->Add_row->UseVisualStyleBackColor = true;
			this->Add_row->Click += gcnew System::EventHandler(this, &AddOperator::Add_row_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Location = System::Drawing::Point(36, 182);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(159, 13);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Домашний адрес сотрудника:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Location = System::Drawing::Point(36, 130);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(129, 13);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Должность сотрудника:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(36, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(98, 13);
			this->label2->TabIndex = 15;
			this->label2->Text = L"ФИО сотрудника:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(36, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(105, 13);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Номер сотрудника:";
			this->toolTip1->SetToolTip(this->label1, L"Это поле заполняется автоматически.");
			// 
			// Home_address
			// 
			this->Home_address->Location = System::Drawing::Point(39, 198);
			this->Home_address->Name = L"Home_address";
			this->Home_address->Size = System::Drawing::Size(243, 20);
			this->Home_address->TabIndex = 13;
			// 
			// Operator_number
			// 
			this->Operator_number->Location = System::Drawing::Point(39, 47);
			this->Operator_number->Name = L"Operator_number";
			this->Operator_number->ReadOnly = true;
			this->Operator_number->Size = System::Drawing::Size(243, 20);
			this->Operator_number->TabIndex = 12;
			this->toolTip1->SetToolTip(this->Operator_number, L"Это поле заполняется автоматически.");
			// 
			// Full_name
			// 
			this->Full_name->Location = System::Drawing::Point(39, 97);
			this->Full_name->Name = L"Full_name";
			this->Full_name->Size = System::Drawing::Size(243, 20);
			this->Full_name->TabIndex = 22;
			// 
			// Position
			// 
			this->Position->Location = System::Drawing::Point(39, 146);
			this->Position->Name = L"Position";
			this->Position->Size = System::Drawing::Size(243, 20);
			this->Position->TabIndex = 23;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Location = System::Drawing::Point(36, 238);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(156, 13);
			this->label5->TabIndex = 25;
			this->label5->Text = L"Личный телефон сотрудника:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Location = System::Drawing::Point(36, 295);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(157, 13);
			this->label6->TabIndex = 27;
			this->label6->Text = L"Логин сотрудника в системе:";
			// 
			// O_login
			// 
			this->O_login->Location = System::Drawing::Point(39, 311);
			this->O_login->Name = L"O_login";
			this->O_login->Size = System::Drawing::Size(243, 20);
			this->O_login->TabIndex = 26;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Location = System::Drawing::Point(36, 347);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(164, 13);
			this->label7->TabIndex = 29;
			this->label7->Text = L"Пароль сотрудника в системе:";
			// 
			// O_password
			// 
			this->O_password->Location = System::Drawing::Point(39, 363);
			this->O_password->Name = L"O_password";
			this->O_password->Size = System::Drawing::Size(243, 20);
			this->O_password->TabIndex = 28;
			// 
			// Phone_number
			// 
			this->Phone_number->Location = System::Drawing::Point(39, 254);
			this->Phone_number->Mask = L"+000 (00) 000-00-00";
			this->Phone_number->Name = L"Phone_number";
			this->Phone_number->Size = System::Drawing::Size(243, 20);
			this->Phone_number->TabIndex = 30;
			this->Phone_number->TextMaskFormat = System::Windows::Forms::MaskFormat::ExcludePromptAndLiterals;
			// 
			// AddOperator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(327, 470);
			this->Controls->Add(this->Phone_number);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->O_password);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->O_login);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->Position);
			this->Controls->Add(this->Full_name);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->Add_row);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Home_address);
			this->Controls->Add(this->Operator_number);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddOperator";
			this->Text = L"Добавить сотрудника";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AddOperator::AddOperator_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AddOperator_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
	{
		general->Enabled = true;
	}
private: System::Void exit_Click(System::Object^  sender, System::EventArgs^  e) 
{
	general->Enabled = true;
	this->Close();
}
	private: System::Void Add_row_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (Full_name->Text != "" && Position->Text != "" && Home_address->Text != ""
			&& Phone_number->Text != "" && O_login->Text != "" && O_password->Text != "")
		{
			String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
			SqlConnection^ connect = gcnew SqlConnection(db);
			SqlCommand^ command = connect->CreateCommand();
			command->CommandText = "SELECT Telephone, U_login FROM Operators WHERE Telephone = \'" + this->Phone_number->Text
				+ "\' OR U_login = \'" + this->O_login->Text + "\'";
			command->Connection = connect;
			SqlDataReader^ dr;
			connect->Open();
			dr = command->ExecuteReader();
			dr->Read();
			if (!(dr->HasRows))
			{
				ChangeLogItem^ ch = gcnew ChangeLogItem("Operators", "INSERT");
				ch->fill_row_update("Full_name", "\'" + this->Full_name->Text + "\'");
				ch->fill_row_update("Position", "\'" + this->Position->Text + "\'");
				ch->fill_row_update("Adress", "\'" + this->Home_address->Text + "\'");
				ch->fill_row_update("Telephone", "\'" + this->Phone_number->Text + "\'");
				ch->fill_row_update("U_login", "\'" + this->O_login->Text + "\'");
				ch->fill_row_update("U_password", "\'" + this->O_password->Text + "\'");
				ch->applyChange();
				MessageBox::Show("Строка успешно добавлена!");
				Operator_number->Text = Convert::ToString(Convert::ToInt32(Operator_number->Text) + 1);
			}
			else
			{
				MessageBox::Show("Ошибка! Строка с таким телефоном или логином уже существует!");
			}
			dr->Close();
			connect->Close();

		}
		else
		{
			MessageBox::Show("Ошибка! Все поля должны быть заполнены!");
		}
	}
};
}
